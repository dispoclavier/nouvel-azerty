/*****************************************************************************\
* Module Name: kbfrFRs.C
*
* keyboard layout
*
* Copyright (c) 1985-2001, Microsoft Corporation
* Copyright (c) 2015-2025, Dispoclavier
*
* History:
* Debug dead key content sort order  5.3.0.12.01-Thu-2025-06-26T0819+0200
* Test KANA modifier on KanaLock key 5.3.0.12.00-Tue-2025-06-24T0450+0200
* Debug level-10 digit emoji         5.3.0.11.00-Sun-2025-06-22T0639+0200
* Append WJ to level-10 digit emoji  5.3.0.10.00-Sun-2025-06-22T0519+0200
* Replace cursive non-joiner with WJ  5.3.0.9.00-Sat-2025-06-21T0826+0200
* Debug level-10 letter emoji         5.3.0.8.00-Fri-2025-06-20T0934+0200
* Level-10 letter emoji, subdiv flags 5.3.0.7.00-Fri-2025-06-20T0717+0200
* Work around the column-02 bug       5.3.0.6.00-Thu-2025-06-19T0817+0200
* Debug level-10 tag characters       5.3.0.5.00-Thu-2025-06-19T0640+0200
* Level 10 for tag characters         5.3.0.4.00-Thu-2025-06-19T0504+0200
* Debug level-9 infrastructure        5.3.0.3.00-Wed-2025-06-18T0317+0200
* Complete level-9 infrastructure     5.3.0.2.00-Tue-2025-06-17T1656+0200
* Replicate row-E emoji on level 9    5.3.0.1.00-Mon-2025-06-16T2153+0200
* Support regional indicator letters  5.3.0.0.00-Mon-2025-06-16T1643+0200
* Debug circumflex in legacy code     5.2.0.5.00-Sun-2025-06-15T1248+0200
* Add U+1F642 emoji, debug cedilla    5.2.0.4.00-Fri-2025-06-13T0645+0200
* Change cedilla dead character       5.2.0.3.12-Thu-2025-06-12T2330+0200
* Extend DEADTRANS macro   Wed 2025-06-11T1239+0200
* Document SGCaps bug      Sun Jun 08 03:57 2025
* Debug key C11   v5.2.0.2 Sun Jun 08 03:02 2025
* Correct high surrogates  Sat Jun 07 00:42 2025
* Add 0xD83D               Fri Jun 06 08:45 2025
* Support high surrogates  Thu Jun 05 03:07 2025
* Simple deadkeys v5.2.0.0 Thu Jun 05 03:07 2025
* Update group char v5.2   Mon Jun 02 04:03 2025
* Sync key D07, v5.1       Mon Apr 28 09:20 2025
* Upgrade to v5.1          Fri Apr 18 02:32 2025
* Upgrade to v5 complete   Sun Apr 13 18:44 2025
* Upgrade to v5            Tue Apr 01 13:32 2025
* Work around SGCaps bug   Sat Dec 21 07:04 2024
* Debug layout             Fri Dec 20 23:55 2024
* Fix transpiled, extend   Fri Dec 20 20:01 2024
* KBDTOOL v3.40 - Created  Thu Dec 19 14:03:05 2024
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
* The keyboard has only three shifter keys:
*     SHIFT (L & R) affects alphabnumeric keys,
*     CTRL  (L & R) is used to generate control characters
*     ALT   (L & R) used for generating characters by number with numpad
\*****************************************************************************/
static ALLOC_SECTION_LDATA VK_TO_BIT aVkToBits[] = {
    { VK_SHIFT    ,   KBDSHIFT     },
    { VK_CONTROL  ,   KBDCTRL      },
    { VK_MENU     ,   KBDALT       },
    { VK_OEM_AX   ,   16           }, // AltGr key
    { VK_OEM_102  ,   32           }, // AltFr key
    { VK_CAPITAL  ,   64           }, // CapsLock key additionally a modifier
    { VK_KANA     ,   128          }, // KanaLock key additionally a modifier
    { 0           ,   0            }
};

/*****************************************************************************\
* aModification[]  - map character modifier bits to modification number
*
* See kbd.h for a full description.
*
\*****************************************************************************/

static ALLOC_SECTION_LDATA MODIFIERS CharModifiers = {
    &aVkToBits[0],
    249, // Decimal # of the last shift state in this array.
         // Any shift state beyond is ignored.
    {
    //  Modification# //            Keys Pressed Or KanaLock Toggle On
    //  ============= // =============================================
        0,            //   0  0x00
        1,            //   1  0x01  Shift
        8,            //   2  0x02  Control
        SHFT_INVALID, //   3  0x03  Shift + Control
        SHFT_INVALID, //   4  0x04  Menu
        SHFT_INVALID, //   5  0x05  Shift + Menu
        SHFT_INVALID, //   6  0x06  Control + Menu
        SHFT_INVALID, //   7  0x07  Shift + Control + Menu
        9,            //   8  0x08  KanaLock
        10,           //   9  0x09  KanaLock + Shift
        SHFT_INVALID, //  10  0x0a  KanaLock + Control
        SHFT_INVALID, //  11  0x0b  KanaLock + Shift + Control
        SHFT_INVALID, //  12  0x0c  KanaLock + Menu
        SHFT_INVALID, //  13  0x0d  KanaLock + Shift + Menu
        SHFT_INVALID, //  14  0x0e  KanaLock + Control + Menu
        SHFT_INVALID, //  15  0x0f  KanaLock + Shift + Control + Menu
        2,            //  16  0x10  OEM_AX
        3,            //  17  0x11  Shift + OEM_AX
        SHFT_INVALID, //  18  0x12  Control + OEM_AX
        SHFT_INVALID, //  19  0x13  Shift + Control + OEM_AX
        SHFT_INVALID, //  20  0x14  Menu + OEM_AX
        SHFT_INVALID, //  21  0x15  Shift + Menu + OEM_AX
        SHFT_INVALID, //  22  0x16  Control + Menu + OEM_AX
        SHFT_INVALID, //  23  0x17  Shift + Control + Menu + OEM_AX
        11,           //  24  0x18  KanaLock + OEM_AX
        12,           //  25  0x19  KanaLock + Shift + OEM_AX
        SHFT_INVALID, //  26  0x1a  KanaLock + Control + OEM_AX
        SHFT_INVALID, //  27  0x1b  KanaLock + Shift + Control + OEM_AX
        SHFT_INVALID, //  28  0x1c  KanaLock + Menu + OEM_AX
        SHFT_INVALID, //  29  0x1d  KanaLock + Shift + Menu + OEM_AX
        SHFT_INVALID, //  30  0x1e  KanaLock + Control + Menu + OEM_AX
        SHFT_INVALID, //  31  0x1f  KanaLock + Shift + Control + Menu + OEM_AX
        4,            //  32  0x20  OEM_102
        5,            //  33  0x21  Shift + OEM_102
        SHFT_INVALID, //  34  0x22  Control + OEM_102
        SHFT_INVALID, //  35  0x23  Shift + Control + OEM_102
        SHFT_INVALID, //  36  0x24  Menu + OEM_102
        SHFT_INVALID, //  37  0x25  Shift + Menu + OEM_102
        SHFT_INVALID, //  38  0x26  Control + Menu + OEM_102
        SHFT_INVALID, //  39  0x27  Shift + Control + Menu + OEM_102
        13,           //  40  0x28  KanaLock + OEM_102
        14,           //  41  0x29  KanaLock + Shift + OEM_102
        SHFT_INVALID, //  42  0x2a  KanaLock + Control + OEM_102
        SHFT_INVALID, //  43  0x2b  KanaLock + Shift + Control + OEM_102
        SHFT_INVALID, //  44  0x2c  KanaLock + Menu + OEM_102
        SHFT_INVALID, //  45  0x2d  KanaLock + Shift + Menu + OEM_102
        SHFT_INVALID, //  46  0x2e  KanaLock + Control + Menu + OEM_102
        SHFT_INVALID, //  47  0x2f  KanaLock + Shift + Control + Menu + OEM_102
        6,            //  48  0x30  OEM_AX + OEM_102
        7,            //  49  0x31  Shift + OEM_AX + OEM_102
        SHFT_INVALID, //  50  0x32  Control + OEM_AX + OEM_102
        SHFT_INVALID, //  51  0x33  Shift + Control + OEM_AX + OEM_102
        SHFT_INVALID, //  52  0x34  Menu + OEM_AX + OEM_102
        SHFT_INVALID, //  53  0x35  Shift + Menu + OEM_AX + OEM_102
        SHFT_INVALID, //  54  0x36  Control + Menu + OEM_AX + OEM_102
        SHFT_INVALID, //  55  0x37  Shift + Control + Menu + OEM_AX + OEM_102
        15,           //  56  0x38  KanaLock + OEM_AX + OEM_102
        16,           //  57  0x39  KanaLock + Shift + OEM_AX + OEM_102
        SHFT_INVALID, //  58  0x3a
        SHFT_INVALID, //  59  0x3b
        SHFT_INVALID, //  60  0x3c
        SHFT_INVALID, //  61  0x3d
        SHFT_INVALID, //  62  0x3e
        SHFT_INVALID, //  63  0x3f
        17,           //  64  0x40  CAPITAL
        18,           //  65  0x41  Shift + CAPITAL
        SHFT_INVALID, //  66  0x42
        SHFT_INVALID, //  67  0x43
        SHFT_INVALID, //  68  0x44
        SHFT_INVALID, //  69  0x45
        SHFT_INVALID, //  70  0x46
        SHFT_INVALID, //  71  0x47
        17,           //  72  0x48  KanaLock + CAPITAL
        18,           //  73  0x49  KanaLock + Shift + CAPITAL
        SHFT_INVALID, //  74  0x4a
        SHFT_INVALID, //  75  0x4b
        SHFT_INVALID, //  76  0x4c
        SHFT_INVALID, //  77  0x4d
        SHFT_INVALID, //  78  0x4e
        SHFT_INVALID, //  79  0x4f
        17,           //  80  0x50  OEM_AX + CAPITAL
        18,           //  81  0x51  Shift + OEM_AX + CAPITAL
        SHFT_INVALID, //  82  0x52
        SHFT_INVALID, //  83  0x53
        SHFT_INVALID, //  84  0x54
        SHFT_INVALID, //  85  0x55
        SHFT_INVALID, //  86  0x56
        SHFT_INVALID, //  87  0x57
        17,           //  88  0x58  KanaLock + OEM_AX + CAPITAL
        18,           //  89  0x59  KanaLock + Shift + OEM_AX + CAPITAL
        SHFT_INVALID, //  90  0x5a
        SHFT_INVALID, //  91  0x5b
        SHFT_INVALID, //  92  0x5c
        SHFT_INVALID, //  93  0x5d
        SHFT_INVALID, //  94  0x5e
        SHFT_INVALID, //  95  0x5f
        17,           //  96  0x60  OEM_102 + CAPITAL
        18,           //  97  0x61  Shift + OEM_102 + CAPITAL
        SHFT_INVALID, //  98  0x62
        SHFT_INVALID, //  99  0x63
        SHFT_INVALID, // 100  0x64
        SHFT_INVALID, // 101  0x65
        SHFT_INVALID, // 102  0x66
        SHFT_INVALID, // 103  0x67
        17,           // 104  0x68  KanaLock + OEM_102 + CAPITAL
        18,           // 105  0x69  KanaLock + Shift + OEM_102 + CAPITAL
        SHFT_INVALID, // 106  0x6a
        SHFT_INVALID, // 107  0x6b
        SHFT_INVALID, // 108  0x6c
        SHFT_INVALID, // 109  0x6d
        SHFT_INVALID, // 110  0x6e
        SHFT_INVALID, // 111  0x6f
        17,           // 112  0x70  OEM_AX + OEM_102 + CAPITAL
        18,           // 113  0x71  Shift + OEM_AX + OEM_102 + CAPITAL
        SHFT_INVALID, // 114  0x72
        SHFT_INVALID, // 115  0x73
        SHFT_INVALID, // 116  0x74
        SHFT_INVALID, // 117  0x75
        SHFT_INVALID, // 118  0x76
        SHFT_INVALID, // 119  0x77
        17,           // 120  0x78  KanaLock + OEM_AX + OEM_102 + CAPITAL
        18,           // 121  0x79  KanaLock + Shift + OEM_AX + OEM_102 + CAPITAL
        SHFT_INVALID, // 122  0x7a
        SHFT_INVALID, // 123  0x7b
        SHFT_INVALID, // 124  0x7c
        SHFT_INVALID, // 125  0x7d
        SHFT_INVALID, // 126  0x7e
        SHFT_INVALID, // 127  0x7f
        17,           // 128  0x80  KANA
        18,           // 129  0x81  Shift + KANA
        SHFT_INVALID, // 130  0x82
        SHFT_INVALID, // 131  0x83
        SHFT_INVALID, // 132  0x84
        SHFT_INVALID, // 133  0x85
        SHFT_INVALID, // 134  0x86
        SHFT_INVALID, // 135  0x87
        17,           // 136  0x88  KanaLock + KANA
        18,           // 137  0x89  KanaLock + Shift + KANA
        SHFT_INVALID, // 138  0x8a
        SHFT_INVALID, // 139  0x8b
        SHFT_INVALID, // 140  0x8c
        SHFT_INVALID, // 141  0x8d
        SHFT_INVALID, // 142  0x8e
        SHFT_INVALID, // 143  0x8f
        2,            // 144  0x90  OEM_AX + KANA
        3,            // 145  0x91  Shift + OEM_AX + KANA
        SHFT_INVALID, // 146  0x92
        SHFT_INVALID, // 147  0x93
        SHFT_INVALID, // 148  0x94
        SHFT_INVALID, // 149  0x95
        SHFT_INVALID, // 150  0x96
        SHFT_INVALID, // 151  0x97
        11,           // 152  0x98  KanaLock + OEM_AX + KANA
        12,           // 153  0x99  KanaLock + Shift + OEM_AX + KANA
        SHFT_INVALID, // 154  0x9a
        SHFT_INVALID, // 155  0x9b
        SHFT_INVALID, // 156  0x9c
        SHFT_INVALID, // 157  0x9d
        SHFT_INVALID, // 158  0x9e
        SHFT_INVALID, // 159  0x9f
        4,            // 160  0xa0  OEM_102 + KANA
        5,            // 161  0xa1  Shift + OEM_102 + KANA
        SHFT_INVALID, // 162  0xa2
        SHFT_INVALID, // 163  0xa3
        SHFT_INVALID, // 164  0xa4
        SHFT_INVALID, // 165  0xa5
        SHFT_INVALID, // 166  0xa6
        SHFT_INVALID, // 167  0xa7
        13,           // 168  0xa8  KanaLock + OEM_102 + KANA
        14,           // 169  0xa9  KanaLock + Shift + OEM_102 + KANA
        SHFT_INVALID, // 170  0xaa
        SHFT_INVALID, // 171  0xab
        SHFT_INVALID, // 172  0xac
        SHFT_INVALID, // 173  0xad
        SHFT_INVALID, // 174  0xae
        SHFT_INVALID, // 175  0xaf
        6,            // 176  0xb0  OEM_AX + OEM_102 + KANA
        7,            // 177  0xb1  Shift + OEM_AX + OEM_102 + KANA
        SHFT_INVALID, // 178  0xb2
        SHFT_INVALID, // 179  0xb3
        SHFT_INVALID, // 180  0xb4
        SHFT_INVALID, // 181  0xb5
        SHFT_INVALID, // 182  0xb6
        SHFT_INVALID, // 183  0xb7
        15,           // 184  0xb8  KanaLock + OEM_AX + OEM_102 + KANA
        16,           // 185  0xb9  KanaLock + Shift + OEM_AX + OEM_102 + KANA
        SHFT_INVALID, // 186  0xba
        SHFT_INVALID, // 187  0xbb
        SHFT_INVALID, // 188  0xbc
        SHFT_INVALID, // 189  0xbd
        SHFT_INVALID, // 190  0xbe
        SHFT_INVALID, // 191  0xbf
        17,           // 192  0xc0  CAPITAL + KANA
        18,           // 193  0xc1  Shift + CAPITAL + KANA
        SHFT_INVALID, // 194  0xc2
        SHFT_INVALID, // 195  0xc3
        SHFT_INVALID, // 196  0xc4
        SHFT_INVALID, // 197  0xc5
        SHFT_INVALID, // 198  0xc6
        SHFT_INVALID, // 199  0xc7
        17,           // 200  0xc8  KanaLock + CAPITAL + KANA
        18,           // 201  0xc9  KanaLock + Shift + CAPITAL + KANA
        SHFT_INVALID, // 202  0xca
        SHFT_INVALID, // 203  0xcb
        SHFT_INVALID, // 204  0xcc
        SHFT_INVALID, // 205  0xcd
        SHFT_INVALID, // 206  0xce
        SHFT_INVALID, // 207  0xcf
        17,           // 208  0xd0  OEM_AX + CAPITAL + KANA
        18,           // 209  0xd1  Shift + OEM_AX + CAPITAL + KANA
        SHFT_INVALID, // 210  0xd2
        SHFT_INVALID, // 211  0xd3
        SHFT_INVALID, // 212  0xd4
        SHFT_INVALID, // 213  0xd5
        SHFT_INVALID, // 214  0xd6
        SHFT_INVALID, // 215  0xd7
        17,           // 216  0xd8  KanaLock + OEM_AX + CAPITAL + KANA
        18,           // 217  0xd9  KanaLock + Shift + OEM_AX + CAPITAL + KANA
        SHFT_INVALID, // 218  0xda
        SHFT_INVALID, // 219  0xdb
        SHFT_INVALID, // 220  0xdc
        SHFT_INVALID, // 221  0xdd
        SHFT_INVALID, // 222  0xde
        SHFT_INVALID, // 223  0xdf
        17,           // 224  0xe0  OEM_102 + CAPITAL + KANA
        18,           // 225  0xe1  Shift + OEM_102 + CAPITAL + KANA
        SHFT_INVALID, // 226  0xe2
        SHFT_INVALID, // 227  0xe3
        SHFT_INVALID, // 228  0xe4
        SHFT_INVALID, // 229  0xe5
        SHFT_INVALID, // 230  0xe6
        SHFT_INVALID, // 231  0xe7
        17,           // 232  0xe8  KanaLock + OEM_102 + CAPITAL + KANA
        18,           // 233  0xe9  KanaLock + Shift + OEM_102 + CAPITAL + KANA
        SHFT_INVALID, // 234  0xea
        SHFT_INVALID, // 235  0xeb
        SHFT_INVALID, // 236  0xec
        SHFT_INVALID, // 237  0xed
        SHFT_INVALID, // 238  0xee
        SHFT_INVALID, // 239  0xef
        17,           // 240  0xf0  OEM_AX + OEM_102 + CAPITAL + KANA
        18,           // 241  0xf1  Shift + OEM_AX + OEM_102 + CAPITAL + KANA
        SHFT_INVALID, // 242  0xf2
        SHFT_INVALID, // 243  0xf3
        SHFT_INVALID, // 244  0xf4
        SHFT_INVALID, // 245  0xf5
        SHFT_INVALID, // 246  0xf6
        SHFT_INVALID, // 247  0xf7
        17,           // 248  0xf8  KanaLock + OEM_AX + OEM_102 + CAPITAL + KANA
        18,           // 249  0xf9  KanaLock + Shift + OEM_AX + OEM_102 + CAPITAL + KANA
     }
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
*     CAPLOK bit    - CAPS-LOCK affect this key like SHIFT
*
* Special values for wch[*] (column 3 & 4)
*     WCH_NONE      - No character
*     WCH_DEAD      - Dead Key (diaresis) or invalid (US keyboard has none)
*     WCH_LGTR      - Ligature (generates multiple characters)
*
\*****************************************************************************/

static ALLOC_SECTION_LDATA VK_TO_WCHARS2 aVkToWch2[] = {
//                      |         |  Shift  |
//                      |=========|=========|
  {VK_TAB       ,0      ,'\t'     ,'\t'     },
  {VK_ADD       ,0      ,'+'      ,'+'      },
  {VK_DIVIDE    ,0      ,'/'      ,'/'      },
  {VK_MULTIPLY  ,0      ,'*'      ,'*'      },
  {VK_SUBTRACT  ,0      ,'-'      ,'-'      },
  {VK_DECIMAL   ,CAPLOK ,'.'      ,','      },
  {0            ,0      ,0        ,0        }
};

/*****************************************************************************\
* Known bugs
*
* The level 7 (AltGr + AltFr i.e. VK_OEM_AX + VK_OEM_102) does not work when
* KANA is on, if the key is subject to KANA. To work around this issue, the
* level 7 with KANA should be redundant.
*
* The level 10 (Shift + CAPITAL, where CAPITAL is the modifier added on top
* of the Caps Lock toggle key) does not work on column 02, i.e. keys "2",
* "W", "S", "X" of the US-QWERTY. To work around this issue, mappings on
* these keys are replicated on unused keys as there are to the right.
\*****************************************************************************/                                                                                             // This column                  This does not
                                                                                                                                                                            // does not work.               work on keys
static ALLOC_SECTION_LDATA VK_TO_WCHARS19 aVkToWch19[] = {                                                                                                                  //|||||||||||                   (B..E)02. 
//                      |         |  Shift  |  AltGr  | S+AltGr |  AltFr  | S+AltFr |AltGr+Fr | S+Gr+Fr |  Ctrl   |  Kana   |Shft+Kana| AltGr+K |S+AltGr+K| AltFr+K |S+AltFr+K|AlGr+Fr+K|S+Gr+Fr+K| CAPITAL |S+CAPITAL|
//                      |=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|
  {VK_OEM_102   ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,SGCAPS ,0x00b2   ,0x00b3   ,'1'      ,'&'      ,'1'      ,0x00b9   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'1'      ,'1'      ,'1'      ,0x2081   ,'1'      ,0x00b9   ,0x2081   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {'1'          ,0      ,0x2082   ,0x2083   },
  {'2'          ,KBD    ,0x00e9   ,0x00c9   ,'2'      ,WCH_DEAD ,'2'      ,0x00b2   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'2'      ,'2'      ,'2'      ,0x2082   ,'2'      ,0x00b2   ,0x2082   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR }, // This does not work.
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'~'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,ALTGR  ,'\"'     ,0x2013   ,'3'      ,'#'      ,'3'      ,0x00b3   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'3'      ,'3'      ,'3'      ,0x2083   ,'3'      ,0x00b3   ,0x2083   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {'4'          ,ALTGR  ,0x2019   ,0x2014   ,'4'      ,'{'      ,'4'      ,0x2074   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'4'      ,'4'      ,'4'      ,0x2084   ,'4'      ,0x2074   ,0x2084   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {'5'          ,ALTGR  ,WCH_DEAD ,0x00ad   ,'5'      ,'['      ,'5'      ,0x2075   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'5'      ,'5'      ,'5'      ,0x2085   ,'5'      ,0x2075   ,0x2085   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,0x00eb   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,ALTGR  ,'-'      ,0x2011   ,'6'      ,'|'      ,'6'      ,0x2076   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'6'      ,'6'      ,'6'      ,0x2086   ,'6'      ,0x2076   ,0x2086   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {'7'          ,ALTGR  ,0x00e8   ,0x00c8   ,'7'      ,WCH_DEAD ,'7'      ,0x2077   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'7'      ,'7'      ,'7'      ,0x2087   ,'7'      ,0x2077   ,0x2087   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'`'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,KBD    ,'_'      ,0x2015   ,'8'      ,'\\'     ,'8'      ,0x2078   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'8'      ,'8'      ,'8'      ,0x2088   ,'8'      ,0x2078   ,0x2088   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {'9'          ,KBD    ,0x00e7   ,0x00c7   ,'9'      ,'('      ,'9'      ,0x2079   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'9'      ,'9'      ,'9'      ,0x2089   ,'9'      ,0x2079   ,0x2089   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {'0'          ,KBD    ,0x00e0   ,0x00c0   ,'0'      ,')'      ,'0'      ,0x2070   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'0'      ,'0'      ,'0'      ,0x2080   ,'0'      ,0x2070   ,0x2080   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {VK_OEM_MINUS ,ALTGR  ,'@'      ,0x00b0   ,0x1d49   ,']'      ,0x00b0   ,0x207b   ,'E'      ,WCH_LGTR ,WCH_NONE ,'@'      ,0x00b0   ,'-'      ,0x208b   ,'E'      ,0x207b   ,0x208b   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {VK_OEM_PLUS  ,ALTGR  ,'\''     ,'+'      ,WCH_DEAD ,'}'      ,'='      ,0x207a   ,'F'      ,WCH_LGTR ,WCH_NONE ,'='      ,'+'      ,WCH_DEAD ,0x208a   ,'F'      ,0x207a   ,0x208a   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,0x00a6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00a6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,CAPLOK ,'a'      ,'A'      ,'^'      ,WCH_DEAD ,'^'      ,0x1d43   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'^'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Z'          ,CAPLOK ,'z'      ,'Z'      ,'%'      ,WCH_DEAD ,'%'      ,0x1dbb   ,0x2032   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR }, // This does not work.
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0250   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,CAPLOK ,'e'      ,'E'      ,0x20ac   ,WCH_DEAD ,0x20ac   ,0x1d49   ,0x2033   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0151   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,CAPLOK ,'r'      ,'R'      ,'\\'     ,WCH_DEAD ,0x00a3   ,0x02b3   ,0x2236   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x019e   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,CAPLOK ,'t'      ,'T'      ,'~'      ,WCH_DEAD ,0x2212   ,0x1d57   ,0x00b1   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00f5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,CAPLOK ,'y'      ,'Y'      ,WCH_DEAD ,WCH_DEAD ,0x00b5   ,0x02b8   ,0x00a5   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,0x03b5   ,0x03b5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'U'          ,CAPLOK ,'u'      ,'U'      ,'\''     ,WCH_DEAD ,'4'      ,0x1d58   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00e1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,CAPLOK ,'i'      ,'I'      ,'{'      ,WCH_DEAD ,'5'      ,0x2071   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0192   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,CAPLOK ,'o'      ,'O'      ,'}'      ,WCH_DEAD ,'6'      ,0x1d52   ,0x03a9   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0273   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,CAPLOK ,'p'      ,'P'      ,'&'      ,WCH_DEAD ,'.'      ,0x1d56   ,0x00b6   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x1e57   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,ALTGR  ,WCH_DEAD ,WCH_LGTR ,WCH_DEAD ,'^'      ,0x2039   ,WCH_DEAD ,'C'      ,'['      ,WCH_NONE ,'"'      ,'{'      ,'^'      ,'_'      ,'C'      ,'^'      ,'_'      ,'['      ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,0x00ea   ,WCH_NONE ,0x00f5   ,WCH_NONE ,WCH_NONE ,0x00eb   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,ALTGR  ,WCH_DEAD ,WCH_LGTR ,WCH_DEAD ,'$'      ,0x203a   ,0x00a3   ,'D'      ,']'      ,WCH_NONE ,'_'      ,'}'      ,WCH_DEAD ,0x208c   ,'D'      ,0x207c   ,0x208c   ,']'      ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,0x00e1   ,WCH_NONE ,0x00f2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x2460   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,CAPLOK ,'q'      ,'Q'      ,'#'      ,WCH_DEAD ,'#'      ,WCH_LGTR ,0x200d   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x2460   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,CAPLOK ,'s'      ,'S'      ,'$'      ,WCH_DEAD ,'$'      ,0x02e2   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR }, // This does not work.
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00a4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,CAPLOK ,'d'      ,'D'      ,'('      ,WCH_DEAD ,'('      ,0x1d48   ,0x2300   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0213   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,CAPLOK ,'f'      ,'F'      ,')'      ,WCH_DEAD ,')'      ,0x1da0   ,0x2013   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0115   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,CAPLOK ,'g'      ,'G'      ,'-'      ,WCH_DEAD ,'-'      ,0x1d4d   ,0x2192   ,0x21d2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x024d   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,CAPLOK ,'h'      ,'H'      ,'+'      ,WCH_DEAD ,'+'      ,0x02b0   ,0x2064   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x01a1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,CAPLOK ,'j'      ,'J'      ,'_'      ,WCH_DEAD ,'1'      ,0x02b2   ,0x203e   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'_'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,CAPLOK ,'k'      ,'K'      ,'['      ,WCH_DEAD ,'2'      ,0x1d4f   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x01eb   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,CAPLOK ,'l'      ,'L'      ,']'      ,WCH_DEAD ,'3'      ,0x02e1   ,0x00a3   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x1ebb   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,CAPLOK ,'m'      ,'M'      ,'|'      ,WCH_DEAD ,','      ,0x1d50   ,0x00b5   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0101   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,SGCAPS ,0x00f9   ,WCH_LGTR ,0x2026   ,0x00a4   ,0x00ab   ,'%'      ,'A'      ,'\''     ,WCH_NONE ,'\''     ,'%'      ,'`'      ,0x208d   ,'A'      ,0x207d   ,0x208d   ,'\''     ,WCH_LGTR ,WCH_LGTR },
//{0xff         ,0      ,0x00d9   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {0xff         ,0      ,0x00d9   ,0x00ab   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
//{VK_OEM_3     ,0      ,0x00d9   ,WCH_LGTR }, // This does not work.
//{VK_OEM_3     ,0      ,0x00d9   ,0x00ab   }, // This works.
// This key is bugged, as neither the short form nor the long form works as designed. 2025-06-08T0338+0200
  {VK_OEM_5     ,ALTGR  ,WCH_DEAD ,WCH_LGTR ,WCH_DEAD ,'*'      ,0x00bb   ,0x00b5   ,'B'      ,';'      ,WCH_NONE ,'-'      ,'*'      ,WCH_DEAD ,0x208e   ,'B'      ,0x207e   ,0x208e   ,';'      ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,0x2460   ,WCH_NONE ,0x2460   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00a6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,CAPLOK ,'w'      ,'W'      ,'/'      ,WCH_DEAD ,'/'      ,0x02b7   ,0x200c   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00f8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,CAPLOK ,'x'      ,'X'      ,'*'      ,WCH_DEAD ,'*'      ,0x02e3   ,0x22c5   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR }, // This does not work.
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00e5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,CAPLOK ,'c'      ,'C'      ,'<'      ,WCH_DEAD ,0x00d7   ,0x1d9c   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00ea   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,CAPLOK ,'v'      ,'V'      ,'>'      ,WCH_DEAD ,0x00f7   ,0x1d5b   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x021f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,CAPLOK ,'b'      ,'B'      ,'='      ,WCH_DEAD ,WCH_LGTR ,0x1d47   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x2690   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,CAPLOK ,'n'      ,'N'      ,'`'      ,WCH_DEAD ,'0'      ,0x207f   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00f2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,ALTGR  ,','      ,WCH_LGTR ,'?'      ,WCH_DEAD ,'?'      ,'?'      ,0x2063   ,WCH_LGTR ,WCH_NONE ,','      ,'?'      ,'?'      ,WCH_DEAD ,'?'      ,WCH_LGTR ,0x2007   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00E7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00E7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,ALTGR  ,'.'      ,WCH_LGTR ,'!'      ,WCH_DEAD ,'!'      ,'!'      ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'.'      ,'!'      ,'!'      ,WCH_DEAD ,'!'      ,WCH_LGTR ,0x2008   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x1e05   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x1e05   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,ALTGR  ,'/'      ,WCH_LGTR ,':'      ,WCH_DEAD ,':'      ,':'      ,0x2044   ,WCH_LGTR ,WCH_NONE ,':'      ,'/'      ,':'      ,WCH_DEAD ,':'      ,0x2044   ,0x2044   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00eb   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00eb   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,ALTGR  ,'\\'     ,WCH_LGTR ,0x00a7   ,WCH_DEAD ,';'      ,';'      ,0x00a7   ,WCH_LGTR ,WCH_NONE ,';'      ,'\\'     ,';'      ,WCH_DEAD ,';'      ,0x00a7   ,0x00a7   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0219   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0219   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_SPACE     ,ALTGR  ,' '      ,' '      ,0x00a0   ,0x200b   ,0x202f   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,' '      ,' '      ,' '      ,' '      ,WCH_LGTR ,' '      ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,0x2060   ,' '      },
  {0            ,0      ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        }
};

static ALLOC_SECTION_LDATA VK_TO_WCHARS9 aVkToWch9[] = {
//                      |         |  Shift  |         |S+       |         |S+       |         |S+       |  Ctrl   |
//                      |=========|=========|=========|=========|=========|=========|=========|=========|=========|
  {VK_BACK      ,0      ,'\b'     ,'\b'     ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x007f   },
  {VK_ESCAPE    ,0      ,0x001b   ,0x001b   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x001b   },
  {VK_RETURN    ,0      ,'\r'     ,'\r'     ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'\n'     },
  {VK_CANCEL    ,0      ,0x0003   ,0x0003   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0003   },
  {0            ,0      ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        }
};

// Put this last so that VkKeyScan interprets number characters
// as coming from the main section of the kbd (aVkToWch19)
// before considering the numpad (aVkToWch1).

static ALLOC_SECTION_LDATA VK_TO_WCHARS1 aVkToWch1[] = {
    { VK_NUMPAD0   , 0      ,  '0'   },
    { VK_NUMPAD1   , 0      ,  '1'   },
    { VK_NUMPAD2   , 0      ,  '2'   },
    { VK_NUMPAD3   , 0      ,  '3'   },
    { VK_NUMPAD4   , 0      ,  '4'   },
    { VK_NUMPAD5   , 0      ,  '5'   },
    { VK_NUMPAD6   , 0      ,  '6'   },
    { VK_NUMPAD7   , 0      ,  '7'   },
    { VK_NUMPAD8   , 0      ,  '8'   },
    { VK_NUMPAD9   , 0      ,  '9'   },
    { 0            , 0      ,  '\0'  }
};

static ALLOC_SECTION_LDATA VK_TO_WCHAR_TABLE aVkToWcharTable[] = {
    {  (PVK_TO_WCHARS1)aVkToWch19, 19, sizeof(aVkToWch19[0]) },
    {  (PVK_TO_WCHARS1)aVkToWch9, 9, sizeof(aVkToWch9[0]) },
    {  (PVK_TO_WCHARS1)aVkToWch2, 2, sizeof(aVkToWch2[0]) },
    {  (PVK_TO_WCHARS1)aVkToWch1, 1, sizeof(aVkToWch1[0]) },
    {                       NULL, 0, 0                    },
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
    L"\x00eb"	L"MINUSCULE LATINE E TR�MA",
    L"\x00e1"	L"MINUSCULE LATINE A ACCENT AIGU",
    L"^"	L"ACCENT CIRCONFLEXE",
    L"^"	L"ACCENT CIRCONFLEXE",
    L"\x0250"	L"MINUSCULE LATINE A TOURN�",
    L"\x0151"	L"MINUSCULE LATINE O DOUBLE ACCENT AIGU",
    L"\x019e"	L"MINUSCULE LATINE N PROLONG� � DROITE",
    L"\x00f5"	L"MINUSCULE LATINE O TILDE",
    L"\x00a6"	L"DEUX-BARRETTES",
    L"\x03b5"	L"MINUSCULE GRECQUE EPSILON",
    L"\x00f2"	L"MINUSCULE LATINE O ACCENT GRAVE",
    L"\x00e1"	L"MINUSCULE LATINE A ACCENT AIGU",
    L"\x0192"	L"MINUSCULE LATINE F HAME�ON",
    L"\x0273"	L"MINUSCULE LATINE N HAME�ON R�TROFLEXE",
    L"\x0e57"	L"MINUSCULE LATINE P POINT EN CHEF",
    L"\x00ea"	L"MINUSCULE LATINE E ACCENT CIRCONFLEXE",
    L"\x00b2"	L"EXPOSANT CHIFFRE DEUX",
    L"\x00b2"	L"EXPOSANT CHIFFRE DEUX",
    L"\x00a4"	L"SYMBOLE MON�TAIRE G�N�RIQUE",
    L"\x0213"	L"MINUSCULE LATINE R BR�VE INVERS�E",
    L"\x0115"	L"MINUSCULE LATINE E BR�VE",
    L"\x024d"	L"MINUSCULE LATINE R RAY�",
    L"\x01a1"	L"MINUSCULE LATINE O CORNU",
    L"_"	L"TIRET BAS",
    L"\x01eb"	L"MINUSCULE LATINE O OGONEK",
    L"\x0ebb"	L"MINUSCULE LATINE E CROCHET EN CHEF",
    L"\x0101"	L"MINUSCULE LATINE A MACRON",
    L"\x00f8"	L"MINUSCULE LATINE O BARR�",
    L"\x00e5"	L"MINUSCULE LATINE A ROND EN CHEF",
    L"\x00ea"	L"MINUSCULE LATINE E ACCENT CIRCONFLEXE",
    L"\x021f"	L"MINUSCULE LATINE H HATCHEK",
    L"\x0690"	L"DRAPEAU NEUTRE",
    L"\x00f2"	L"MINUSCULE LATINE O ACCENT GRAVE",
    L"\x00E7"	L"MINUSCULE LATINE C C�DILLE",
    L"\x0e05"	L"MINUSCULE LATINE B POINT SOUSCRIT",
    L"\x00eb"	L"MINUSCULE LATINE E TR�MA",
    L"\x0219"	L"MINUSCULE LATINE S VIRGULE SOUSCRITE",
    NULL
};

static ALLOC_SECTION_LDATA DEADKEY aDeadKey[] = {

/*****************************************************************************\
# On Windows, the dead key output is restricted to the low surrogate. An input
# method for the high surrogates is provided separately at the root of related
# dead keys, with U+200B ZERO WIDTH SPACE as a base character, in synergy with
# most dead keys, on level 4 of the space bar in French mode.
#
# The number of required high surrogates amounts to seven:
#
#     D801, D807,
#     D835, D837, D83C, D83D, D83E.
#
# These can be dispatched among dead keys most straightforwardly as follows:
#
#     D801 dead_superscript (modifier letters)
#     D807 dead_turned [dead_turned] (U+11FB0 "𑾰" LISU LETTER YHA)
#     D835 dead_group (mathematical alphanumeric symbols)
#     D837 dead_bar, dead_breve, dead_hook, dead_retroflexhook, others (Latin)
#     D83C dead_flag, dead_greek (flag letters, squared letters)
#     D83D dead_doubleacute, dead_acute, others (ornamental quotation marks)
#     D83E dead_stroke, dead_group 11 and 12 as built-in (wide-headed arrows)
#
# The output is directly in C, where an array of DEADTRANS macro calls makes
# for a flat layout of dead key data, while in KLC format, the data is grouped
# under DEADKEY headers. Transpilation by KbdUTool produces C code without any
# of the comments placed in the KLC file. Anyway, KLC only supports end-of-line
# comments, while leading block comments (in addition to EOL comments) are best
# for human readability, and with long lists are more readable than the grouped
# layout. Given that furthermore, the KLC-to-C transpiler in KbdUTool is broken
# and unable to support the Kana Lock levels, using the KLC format is pointless
# and induces a significant amount of waste.
#
# As a result, any DEADTRANS macro call can be overridden by a similar call,
# with the same input and the same dead character, but another output, provided
# that the valid call precedes anyhow in the source code.
\*****************************************************************************/

/*<!dead_abovedot>*/      DEADTRANS( 0x200B ,0x1E57 ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_abovehook>*/     DEADTRANS( 0x200B ,0x1EBB ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_abovering>*/     DEADTRANS( 0x200B ,0x00E5 ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_acute>*/         DEADTRANS( 0x200B ,0x00E1 ,0xD83D ,0x0000 ), // High surrogate for ornamental quotation marks.
/*<!dead_bar>*/           DEADTRANS( 0x200B ,0x024D ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_belowcomma>*/    DEADTRANS( 0x200B ,0x0219 ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_belowdot>*/      DEADTRANS( 0x200B ,0x1E05 ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_breve>*/         DEADTRANS( 0x200B ,0x0115 ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_caron>*/         DEADTRANS( 0x200B ,0x021F ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_cedilla>*/       DEADTRANS( 0x200B ,0x00E7 ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_circumflex>*/    DEADTRANS( 0x200B ,0x00EA ,0xD83D ,0x0000 ), // High surrogate for ornamental quotation marks.
/*<!dead_currency>*/      DEADTRANS( 0x200B ,0x00A4 ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_diaeresis>*/     DEADTRANS( 0x200B ,0x00EB ,0xD83D ,0x0000 ), // High surrogate for ornamental quotation marks.
/*<!dead_doubleacute>*/   DEADTRANS( 0x200B ,0x0151 ,0xD83D ,0x0000 ), // High surrogate for ornamental quotation marks.
/*<!dead_flag>*/          DEADTRANS( 0x200B ,0x2690 ,0xD83C ,0x0000 ), // High surrogate for flag letters, squared letters.
/*<!dead_grave>*/         DEADTRANS( 0x200B ,0x00F2 ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_greek>*/         DEADTRANS( 0x200B ,0x03B5 ,0xD83C ,0x0000 ), // High surrogate for flag letters, squared letters.
/*<!dead_group>*/         DEADTRANS( 0x200B ,0x2460 ,0xD835 ,0x0000 ), // High surrogate for mathematical alphanumeric symbols.
/*<!dead_hook>*/          DEADTRANS( 0x200B ,0x0192 ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_horn>*/          DEADTRANS( 0x200B ,0x01A1 ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_invertedbreve>*/ DEADTRANS( 0x200B ,0x0213 ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_macron>*/        DEADTRANS( 0x200B ,0x0101 ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_ogonek>*/        DEADTRANS( 0x200B ,0x01EB ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_retroflexhook>*/ DEADTRANS( 0x200B ,0x0273 ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_reversed>*/      DEADTRANS( 0x200B ,0x019E ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_stroke>*/        DEADTRANS( 0x200B ,0x00F8 ,0xD83E ,0x0000 ), // High surrogate for wide-headed arrows.
/*<!dead_subscript>*/     DEADTRANS( 0x200B ,L'_'   ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_superscript>*/   DEADTRANS( 0x200B ,L'^'   ,0xD801 ,0x0000 ), // High surrogate for modifier letters.
/*<!dead_tilde>*/         DEADTRANS( 0x200B ,0x00F5 ,0xD837 ,0x0000 ), // High surrogate for Latin.
/*<!dead_turned>*/        DEADTRANS( 0x200B ,0x0250 ,0xD807 ,0x0000 ), // High surrogate for U+11FB0 "𑾰" LISU LETTER YHA.

/*****************************************************************************\
# On Windows, the dead key output is restricted to a single code unit, due to a
# bad design decision, based on a misconception of Unicode as a 16-bit charset,
# and on the ignorance of the Unicode encoding model using combining diacritics
# whenever possible, and the Unicode recommendation to support composed letters
# by dead keys. Since extending the DEADTRANS macro to support 5 of the missing
# code units would be pointless, due to Windows’ inability to look the array up
# for the additional code units, and append them to the output if non-null, the
# degradation of the user experience compared to Linux and macOS (and ChromeOS’
# precompiled Linux layouts) should be mitigated as far as possible.
#
# On Linux and macOS, the "Ê" key emulation supports uppercase, "êq" expands to
# "êqu", and "x" yields the "êch" trigraph. On Windows, lowercase works as
# intended due to default handling of the dead character, while uppercase would
# be mixed with lowercase "ê". To mitigate this UX disruption, unsupported
# letters output the start of the full sequence.
#
# A "Ç" key is also emulated, for Canadian French.
\*****************************************************************************/

/*<!dead_circumflex>*/	DEADTRANS(	L'K'	,0x00EA	,0x00CA	,0x0000	), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'L'	,0x00EA	,0x00CA	,0x0000	), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'M'	,0x00EA	,0x00CA	,0x0000	), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'N'	,0x00EA	,0x00CA	,0x0000	), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'P'	,0x00EA	,0x00CA	,0x0000	), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'Q'	,0x00EA	,0x00CA	,0x0000	), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'R'	,0x00EA	,0x00CA	,0x0000	), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'T'	,0x00EA	,0x00CA	,0x0000	), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'V'	,0x00EA	,0x00CA	,0x0000	), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'X'	,0x00EA	,0x00CA	,0x0000	), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'x'	,0x00EA	,0x00EA	,0x0000	), // "ê" LATIN SMALL LETTER E WITH CIRCUMFLEX
/*<!dead_cedilla>*/	DEADTRANS(	L'A'	,0x00E7	,0x00C7	,0x0000	), // "Ç" LATIN CAPITAL LETTER C WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'O'	,0x00E7	,0x00C7	,0x0000	), // "Ç" LATIN CAPITAL LETTER C WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'U'	,0x00E7	,0x00C7	,0x0000	), // "Ç" LATIN CAPITAL LETTER C WITH CEDILLA

/*****************************************************************************\
# Flag letters need to be adapted to Windows, where a single dead key press is
# to output the regional indicator symbol letter’s low surrogate right away, as
# the system is unable to output more than a single code unit (as opposed to
# Linux and macOS, where the single-press output fits the needs of writing in
# letter emoji, by appending a cursive non-joiner U200C ZWNJ).
\*****************************************************************************/

/*<!dead_flag>*/	DEADTRANS(	L'a'	,0x2690	,0xDDE6	,0x0000	), // High surrogate: D83C; Unicode: U+1F1E6 "🇦" REGIONAL INDICATOR SYMBOL LETTER A
/*<!dead_flag>*/	DEADTRANS(	L'A'	,0x2690	,0xDDE6	,0x0000	), // High surrogate: D83C; Unicode: U+1F1E6 "🇦" REGIONAL INDICATOR SYMBOL LETTER A
/*<!dead_flag>*/	DEADTRANS(	L'b'	,0x2690	,0xDDE7	,0x0000	), // High surrogate: D83C; Unicode: U+1F1E7 "🇧" REGIONAL INDICATOR SYMBOL LETTER B
/*<!dead_flag>*/	DEADTRANS(	L'B'	,0x2690	,0xDDE7	,0x0000	), // High surrogate: D83C; Unicode: U+1F1E7 "🇧" REGIONAL INDICATOR SYMBOL LETTER B
/*<!dead_flag>*/	DEADTRANS(	L'c'	,0x2690	,0xDDE8	,0x0000	), // High surrogate: D83C; Unicode: U+1F1E8 "🇨" REGIONAL INDICATOR SYMBOL LETTER C
/*<!dead_flag>*/	DEADTRANS(	L'C'	,0x2690	,0xDDE8	,0x0000	), // High surrogate: D83C; Unicode: U+1F1E8 "🇨" REGIONAL INDICATOR SYMBOL LETTER C
/*<!dead_flag>*/	DEADTRANS(	L'd'	,0x2690	,0xDDE9	,0x0000	), // High surrogate: D83C; Unicode: U+1F1E9 "🇩" REGIONAL INDICATOR SYMBOL LETTER D
/*<!dead_flag>*/	DEADTRANS(	L'D'	,0x2690	,0xDDE9	,0x0000	), // High surrogate: D83C; Unicode: U+1F1E9 "🇩" REGIONAL INDICATOR SYMBOL LETTER D
/*<!dead_flag>*/	DEADTRANS(	L'e'	,0x2690	,0xDDEA	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EA "🇪" REGIONAL INDICATOR SYMBOL LETTER E
/*<!dead_flag>*/	DEADTRANS(	L'E'	,0x2690	,0xDDEA	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EA "🇪" REGIONAL INDICATOR SYMBOL LETTER E
/*<!dead_flag>*/	DEADTRANS(	L'f'	,0x2690	,0xDDEB	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EB "🇫" REGIONAL INDICATOR SYMBOL LETTER F
/*<!dead_flag>*/	DEADTRANS(	L'F'	,0x2690	,0xDDEB	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EB "🇫" REGIONAL INDICATOR SYMBOL LETTER F
/*<!dead_flag>*/	DEADTRANS(	L'g'	,0x2690	,0xDDEC	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EC "🇬" REGIONAL INDICATOR SYMBOL LETTER G
/*<!dead_flag>*/	DEADTRANS(	L'G'	,0x2690	,0xDDEC	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EC "🇬" REGIONAL INDICATOR SYMBOL LETTER G
/*<!dead_flag>*/	DEADTRANS(	L'h'	,0x2690	,0xDDED	,0x0000	), // High surrogate: D83C; Unicode: U+1F1ED "🇭" REGIONAL INDICATOR SYMBOL LETTER H
/*<!dead_flag>*/	DEADTRANS(	L'H'	,0x2690	,0xDDED	,0x0000	), // High surrogate: D83C; Unicode: U+1F1ED "🇭" REGIONAL INDICATOR SYMBOL LETTER H
/*<!dead_flag>*/	DEADTRANS(	L'i'	,0x2690	,0xDDEE	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EE "🇮" REGIONAL INDICATOR SYMBOL LETTER I
/*<!dead_flag>*/	DEADTRANS(	L'I'	,0x2690	,0xDDEE	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EE "🇮" REGIONAL INDICATOR SYMBOL LETTER I
/*<!dead_flag>*/	DEADTRANS(	L'j'	,0x2690	,0xDDEF	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EF "🇯" REGIONAL INDICATOR SYMBOL LETTER J
/*<!dead_flag>*/	DEADTRANS(	L'J'	,0x2690	,0xDDEF	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EF "🇯" REGIONAL INDICATOR SYMBOL LETTER J
/*<!dead_flag>*/	DEADTRANS(	L'k'	,0x2690	,0xDDF0	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F0 "🇰" REGIONAL INDICATOR SYMBOL LETTER K
/*<!dead_flag>*/	DEADTRANS(	L'K'	,0x2690	,0xDDF0	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F0 "🇰" REGIONAL INDICATOR SYMBOL LETTER K
/*<!dead_flag>*/	DEADTRANS(	L'l'	,0x2690	,0xDDF1	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F1 "🇱" REGIONAL INDICATOR SYMBOL LETTER L
/*<!dead_flag>*/	DEADTRANS(	L'L'	,0x2690	,0xDDF1	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F1 "🇱" REGIONAL INDICATOR SYMBOL LETTER L
/*<!dead_flag>*/	DEADTRANS(	L'm'	,0x2690	,0xDDF2	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F2 "🇲" REGIONAL INDICATOR SYMBOL LETTER M
/*<!dead_flag>*/	DEADTRANS(	L'M'	,0x2690	,0xDDF2	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F2 "🇲" REGIONAL INDICATOR SYMBOL LETTER M
/*<!dead_flag>*/	DEADTRANS(	L'n'	,0x2690	,0xDDF3	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F3 "🇳" REGIONAL INDICATOR SYMBOL LETTER N
/*<!dead_flag>*/	DEADTRANS(	L'N'	,0x2690	,0xDDF3	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F3 "🇳" REGIONAL INDICATOR SYMBOL LETTER N
/*<!dead_flag>*/	DEADTRANS(	L'o'	,0x2690	,0xDDF4	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F4 "🇴" REGIONAL INDICATOR SYMBOL LETTER O
/*<!dead_flag>*/	DEADTRANS(	L'O'	,0x2690	,0xDDF4	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F4 "🇴" REGIONAL INDICATOR SYMBOL LETTER O
/*<!dead_flag>*/	DEADTRANS(	L'p'	,0x2690	,0xDDF5	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F5 "🇵" REGIONAL INDICATOR SYMBOL LETTER P
/*<!dead_flag>*/	DEADTRANS(	L'P'	,0x2690	,0xDDF5	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F5 "🇵" REGIONAL INDICATOR SYMBOL LETTER P
/*<!dead_flag>*/	DEADTRANS(	L'q'	,0x2690	,0xDDF6	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F6 "🇶" REGIONAL INDICATOR SYMBOL LETTER Q
/*<!dead_flag>*/	DEADTRANS(	L'Q'	,0x2690	,0xDDF6	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F6 "🇶" REGIONAL INDICATOR SYMBOL LETTER Q
/*<!dead_flag>*/	DEADTRANS(	L'r'	,0x2690	,0xDDF7	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F7 "🇷" REGIONAL INDICATOR SYMBOL LETTER R
/*<!dead_flag>*/	DEADTRANS(	L'R'	,0x2690	,0xDDF7	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F7 "🇷" REGIONAL INDICATOR SYMBOL LETTER R
/*<!dead_flag>*/	DEADTRANS(	L's'	,0x2690	,0xDDF8	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F8 "🇸" REGIONAL INDICATOR SYMBOL LETTER S
/*<!dead_flag>*/	DEADTRANS(	L'S'	,0x2690	,0xDDF8	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F8 "🇸" REGIONAL INDICATOR SYMBOL LETTER S
/*<!dead_flag>*/	DEADTRANS(	L't'	,0x2690	,0xDDF9	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F9 "🇹" REGIONAL INDICATOR SYMBOL LETTER T
/*<!dead_flag>*/	DEADTRANS(	L'T'	,0x2690	,0xDDF9	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F9 "🇹" REGIONAL INDICATOR SYMBOL LETTER T
/*<!dead_flag>*/	DEADTRANS(	L'u'	,0x2690	,0xDDFA	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FA "🇺" REGIONAL INDICATOR SYMBOL LETTER U
/*<!dead_flag>*/	DEADTRANS(	L'U'	,0x2690	,0xDDFA	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FA "🇺" REGIONAL INDICATOR SYMBOL LETTER U
/*<!dead_flag>*/	DEADTRANS(	L'v'	,0x2690	,0xDDFB	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FB "🇻" REGIONAL INDICATOR SYMBOL LETTER V
/*<!dead_flag>*/	DEADTRANS(	L'V'	,0x2690	,0xDDFB	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FB "🇻" REGIONAL INDICATOR SYMBOL LETTER V
/*<!dead_flag>*/	DEADTRANS(	L'w'	,0x2690	,0xDDFC	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FC "🇼" REGIONAL INDICATOR SYMBOL LETTER W
/*<!dead_flag>*/	DEADTRANS(	L'W'	,0x2690	,0xDDFC	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FC "🇼" REGIONAL INDICATOR SYMBOL LETTER W
/*<!dead_flag>*/	DEADTRANS(	L'x'	,0x2690	,0xDDFD	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FD "🇽" REGIONAL INDICATOR SYMBOL LETTER X
/*<!dead_flag>*/	DEADTRANS(	L'X'	,0x2690	,0xDDFD	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FD "🇽" REGIONAL INDICATOR SYMBOL LETTER X
/*<!dead_flag>*/	DEADTRANS(	L'y'	,0x2690	,0xDDFE	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FE "🇾" REGIONAL INDICATOR SYMBOL LETTER Y
/*<!dead_flag>*/	DEADTRANS(	L'Y'	,0x2690	,0xDDFE	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FE "🇾" REGIONAL INDICATOR SYMBOL LETTER Y
/*<!dead_flag>*/	DEADTRANS(	L'z'	,0x2690	,0xDDFF	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FF "🇿" REGIONAL INDICATOR SYMBOL LETTER Z
/*<!dead_flag>*/	DEADTRANS(	L'Z'	,0x2690	,0xDDFF	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FF "🇿" REGIONAL INDICATOR SYMBOL LETTER Z

/*****************************************************************************\
* Single-press dead key content is up-to-date and overrides the legacy code.
\*****************************************************************************/

/*<!dead_abovedot>*/	DEADTRANS(	L'\''	,0x1E57	,0x2AC3	,0x0000	), // "⫃" SUBSET OF OR EQUAL TO WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	0x2019	,0x1E57	,0x2AC3	,0x0000	), // "⫃" SUBSET OF OR EQUAL TO WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'~'	,0x1E57	,0x2A6A	,0x0000	), // "⩪" TILDE OPERATOR WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'|'	,0x1E57	,0xA717	,0x0000	), // "ꜗ" MODIFIER LETTER DOT VERTICAL BAR
/*<!dead_abovedot>*/	DEADTRANS(	L'{'	,0x1E57	,0x2AC4	,0x0000	), // "⫄" SUPERSET OF OR EQUAL TO WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'='	,0x1E57	,0x2250	,0x0000	), // "≐" APPROACHES THE LIMIT
/*<!dead_abovedot>*/	DEADTRANS(	L'`'	,0x1E57	,0x2A51	,0x0000	), // "⩑" LOGICAL AND WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'>'	,0x1E57	,0x2A82	,0x0000	), // "⪂" GREATER-THAN OR SLANTED EQUAL TO WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'<'	,0x1E57	,0x2A81	,0x0000	), // "⪁" LESS-THAN OR SLANTED EQUAL TO WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'-'	,0x1E57	,0x2238	,0x0000	), // "∸" DOT MINUS
/*<!dead_abovedot>*/	DEADTRANS(	L'%'	,0x1E57	,0x29CA	,0x0000	), // "⧊" TRIANGLE WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'+'	,0x1E57	,0x2214	,0x0000	), // "∔" DOT PLUS
/*<!dead_abovedot>*/	DEADTRANS(	L'?'	,0x1E57	,0x2A52	,0x0000	), // "⩒" LOGICAL OR WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'"'	,0x1E57	,0x22F5	,0x0000	), // "⋵" ELEMENT OF WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	0x20AC	,0x1E57	,0x22F5	,0x0000	), // "⋵" ELEMENT OF WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L';'	,0x1E57	,0x2A30	,0x0000	), // "⨰" MULTIPLICATION SIGN WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'/'	,0x1E57	,0xA718	,0x0000	), // "ꜘ" MODIFIER LETTER DOT SLASH
/*<!dead_abovedot>*/	DEADTRANS(	L'_'	,0x1E57	,0xA719	,0x0000	), // "ꜙ" MODIFIER LETTER DOT HORIZONTAL BAR
/*<!dead_abovedot>*/	DEADTRANS(	L'0'	,0x1E57	,0x267C	,0x0000	), // "♼" RECYCLED PAPER SYMBOL
/*<!dead_abovedot>*/	DEADTRANS(	L'1'	,0x1E57	,0x1DFA	,0x0000	), // "᷺" COMBINING DOT BELOW LEFT
/*<!dead_abovedot>*/	DEADTRANS(	L'2'	,0x1E57	,0x267D	,0x0000	), // "♽" PARTIALLY-RECYCLED PAPER SYMBOL
/*<!dead_abovedot>*/	DEADTRANS(	L'3'	,0x1E57	,0x1AB4	,0x0000	), // "᪴" COMBINING TRIPLE DOT
/*<!dead_abovedot>*/	DEADTRANS(	L'4'	,0x1E57	,0x267D	,0x0000	), // "♽" PARTIALLY-RECYCLED PAPER SYMBOL
/*<!dead_abovedot>*/	DEADTRANS(	L'5'	,0x1E57	,0x0352	,0x0000	), // "͒" COMBINING FERMATA
/*<!dead_abovedot>*/	DEADTRANS(	L'6'	,0x1E57	,0x267C	,0x0000	), // "♼" RECYCLED PAPER SYMBOL
/*<!dead_abovedot>*/	DEADTRANS(	L'7'	,0x1E57	,0x1DF8	,0x0000	), // "᷸" COMBINING DOT ABOVE LEFT
/*<!dead_abovedot>*/	DEADTRANS(	L'8'	,0x1E57	,0x267E	,0x0000	), // "♾" PERMANENT PAPER SIGN emoji
/*<!dead_abovedot>*/	DEADTRANS(	L'9'	,0x1E57	,0x0358	,0x0000	), // "͘" COMBINING DOT ABOVE RIGHT
/*<!dead_abovedot>*/	DEADTRANS(	L'A'	,0x1E57	,0x0226	,0x0000	), // "Ȧ" LATIN CAPITAL LETTER A WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'a'	,0x1E57	,0x0227	,0x0000	), // "ȧ" LATIN SMALL LETTER A WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'B'	,0x1E57	,0x1E02	,0x0000	), // "Ḃ" LATIN CAPITAL LETTER B WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'b'	,0x1E57	,0x1E03	,0x0000	), // "ḃ" LATIN SMALL LETTER B WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'C'	,0x1E57	,0x010A	,0x0000	), // "Ċ" LATIN CAPITAL LETTER C WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'c'	,0x1E57	,0x010B	,0x0000	), // "ċ" LATIN SMALL LETTER C WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'D'	,0x1E57	,0x1E0A	,0x0000	), // "Ḋ" LATIN CAPITAL LETTER D WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'd'	,0x1E57	,0x1E0B	,0x0000	), // "ḋ" LATIN SMALL LETTER D WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'E'	,0x1E57	,0x0116	,0x0000	), // "Ė" LATIN CAPITAL LETTER E WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'e'	,0x1E57	,0x0117	,0x0000	), // "ė" LATIN SMALL LETTER E WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'F'	,0x1E57	,0x1E1E	,0x0000	), // "Ḟ" LATIN CAPITAL LETTER F WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'f'	,0x1E57	,0x1E1F	,0x0000	), // "ḟ" LATIN SMALL LETTER F WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'G'	,0x1E57	,0x0120	,0x0000	), // "Ġ" LATIN CAPITAL LETTER G WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'g'	,0x1E57	,0x0121	,0x0000	), // "ġ" LATIN SMALL LETTER G WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'H'	,0x1E57	,0x1E22	,0x0000	), // "Ḣ" LATIN CAPITAL LETTER H WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'h'	,0x1E57	,0x1E23	,0x0000	), // "ḣ" LATIN SMALL LETTER H WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'I'	,0x1E57	,0x0130	,0x0000	), // "İ" LATIN CAPITAL LETTER I WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'i'	,0x1E57	,0x0131	,0x0000	), // "ı" LATIN SMALL LETTER DOTLESS I
/*<!dead_abovedot>*/	DEADTRANS(	L'J'	,0x1E57	,0x0237	,0x0000	), // "ȷ" LATIN SMALL LETTER DOTLESS J
/*<!dead_abovedot>*/	DEADTRANS(	L'j'	,0x1E57	,0x0237	,0x0000	), // "ȷ" LATIN SMALL LETTER DOTLESS J
/*<!dead_abovedot>*/	DEADTRANS(	L'L'	,0x1E57	,0x013F	,0x0000	), // "Ŀ" LATIN CAPITAL LETTER L WITH MIDDLE DOT
/*<!dead_abovedot>*/	DEADTRANS(	L'l'	,0x1E57	,0x0140	,0x0000	), // "ŀ" LATIN SMALL LETTER L WITH MIDDLE DOT
/*<!dead_abovedot>*/	DEADTRANS(	L'M'	,0x1E57	,0x1E40	,0x0000	), // "Ṁ" LATIN CAPITAL LETTER M WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'm'	,0x1E57	,0x1E41	,0x0000	), // "ṁ" LATIN SMALL LETTER M WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	0x00D7	,0x1E57	,0x2A30	,0x0000	), // "⨰" MULTIPLICATION SIGN WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'N'	,0x1E57	,0x1E44	,0x0000	), // "Ṅ" LATIN CAPITAL LETTER N WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'n'	,0x1E57	,0x1E45	,0x0000	), // "ṅ" LATIN SMALL LETTER N WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'O'	,0x1E57	,0x022E	,0x0000	), // "Ȯ" LATIN CAPITAL LETTER O WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'o'	,0x1E57	,0x022F	,0x0000	), // "ȯ" LATIN SMALL LETTER O WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'P'	,0x1E57	,0x1E56	,0x0000	), // "Ṗ" LATIN CAPITAL LETTER P WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'p'	,0x1E57	,0x1E57	,0x0000	), // "ṗ" LATIN SMALL LETTER P WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'R'	,0x1E57	,0x1E58	,0x0000	), // "Ṙ" LATIN CAPITAL LETTER R WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'r'	,0x1E57	,0x1E59	,0x0000	), // "ṙ" LATIN SMALL LETTER R WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'S'	,0x1E57	,0x1E60	,0x0000	), // "Ṡ" LATIN CAPITAL LETTER S WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L's'	,0x1E57	,0x1E61	,0x0000	), // "ṡ" LATIN SMALL LETTER S WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'T'	,0x1E57	,0x1E6A	,0x0000	), // "Ṫ" LATIN CAPITAL LETTER T WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L't'	,0x1E57	,0x1E6B	,0x0000	), // "ṫ" LATIN SMALL LETTER T WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'W'	,0x1E57	,0x1E86	,0x0000	), // "Ẇ" LATIN CAPITAL LETTER W WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'w'	,0x1E57	,0x1E87	,0x0000	), // "ẇ" LATIN SMALL LETTER W WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'X'	,0x1E57	,0x1E8A	,0x0000	), // "Ẋ" LATIN CAPITAL LETTER X WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'x'	,0x1E57	,0x1E8B	,0x0000	), // "ẋ" LATIN SMALL LETTER X WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'Y'	,0x1E57	,0x1E8E	,0x0000	), // "Ẏ" LATIN CAPITAL LETTER Y WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'y'	,0x1E57	,0x1E8F	,0x0000	), // "ẏ" LATIN SMALL LETTER Y WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'Z'	,0x1E57	,0x017B	,0x0000	), // "Ż" LATIN CAPITAL LETTER Z WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L'z'	,0x1E57	,0x017C	,0x0000	), // "ż" LATIN SMALL LETTER Z WITH DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	0x00A0	,0x1E57	,0x02D9	,0x0000	), // "˙" DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	0x202F	,0x1E57	,0x02D9	,0x0000	), // "˙" DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	L' '	,0x1E57	,0x0307	,0x0000	), // "̇" COMBINING DOT ABOVE
/*<!dead_abovedot>*/	DEADTRANS(	0x200B	,0x1E57	,0x0307	,0x0000	), // "̇" COMBINING DOT ABOVE
/*<!dead_abovehook>*/	DEADTRANS(	0x01EB	,0x1EBB	,0x20E3	,0x0000	), // "⃣" COMBINING ENCLOSING KEYCAP
/*<!dead_abovehook>*/	DEADTRANS(	L'0'	,0x1EBB	,0x2793	,0x0000	), // "➓" DINGBAT NEGATIVE CIRCLED SANS-SERIF NUMBER TEN
/*<!dead_abovehook>*/	DEADTRANS(	L'1'	,0x1EBB	,0x278A	,0x0000	), // "➊" DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*<!dead_abovehook>*/	DEADTRANS(	L'2'	,0x1EBB	,0x278B	,0x0000	), // "➋" DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT TWO
/*<!dead_abovehook>*/	DEADTRANS(	L'3'	,0x1EBB	,0x278C	,0x0000	), // "➌" DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT THREE
/*<!dead_abovehook>*/	DEADTRANS(	L'4'	,0x1EBB	,0x278D	,0x0000	), // "➍" DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT FOUR
/*<!dead_abovehook>*/	DEADTRANS(	L'5'	,0x1EBB	,0x278E	,0x0000	), // "➎" DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT FIVE
/*<!dead_abovehook>*/	DEADTRANS(	L'6'	,0x1EBB	,0x278F	,0x0000	), // "➏" DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT SIX
/*<!dead_abovehook>*/	DEADTRANS(	L'7'	,0x1EBB	,0x2790	,0x0000	), // "➐" DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT SEVEN
/*<!dead_abovehook>*/	DEADTRANS(	L'8'	,0x1EBB	,0x2791	,0x0000	), // "➑" DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT EIGHT
/*<!dead_abovehook>*/	DEADTRANS(	L'9'	,0x1EBB	,0x2792	,0x0000	), // "➒" DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT NINE
/*<!dead_abovehook>*/	DEADTRANS(	L'A'	,0x1EBB	,0x1EA2	,0x0000	), // "Ả" LATIN CAPITAL LETTER A WITH HOOK ABOVE
/*<!dead_abovehook>*/	DEADTRANS(	L'a'	,0x1EBB	,0x1EA3	,0x0000	), // "ả" LATIN SMALL LETTER A WITH HOOK ABOVE
/*<!dead_abovehook>*/	DEADTRANS(	L'E'	,0x1EBB	,0x1EBA	,0x0000	), // "Ẻ" LATIN CAPITAL LETTER E WITH HOOK ABOVE
/*<!dead_abovehook>*/	DEADTRANS(	L'e'	,0x1EBB	,0x1EBB	,0x0000	), // "ẻ" LATIN SMALL LETTER E WITH HOOK ABOVE
/*<!dead_abovehook>*/	DEADTRANS(	L'I'	,0x1EBB	,0x1EC8	,0x0000	), // "Ỉ" LATIN CAPITAL LETTER I WITH HOOK ABOVE
/*<!dead_abovehook>*/	DEADTRANS(	L'i'	,0x1EBB	,0x1EC9	,0x0000	), // "ỉ" LATIN SMALL LETTER I WITH HOOK ABOVE
/*<!dead_abovehook>*/	DEADTRANS(	L'O'	,0x1EBB	,0x1ECE	,0x0000	), // "Ỏ" LATIN CAPITAL LETTER O WITH HOOK ABOVE
/*<!dead_abovehook>*/	DEADTRANS(	L'o'	,0x1EBB	,0x1ECF	,0x0000	), // "ỏ" LATIN SMALL LETTER O WITH HOOK ABOVE
/*<!dead_abovehook>*/	DEADTRANS(	L'U'	,0x1EBB	,0x1EE6	,0x0000	), // "Ủ" LATIN CAPITAL LETTER U WITH HOOK ABOVE
/*<!dead_abovehook>*/	DEADTRANS(	L'u'	,0x1EBB	,0x1EE7	,0x0000	), // "ủ" LATIN SMALL LETTER U WITH HOOK ABOVE
/*<!dead_abovehook>*/	DEADTRANS(	L'Y'	,0x1EBB	,0x1EF6	,0x0000	), // "Ỷ" LATIN CAPITAL LETTER Y WITH HOOK ABOVE
/*<!dead_abovehook>*/	DEADTRANS(	L'y'	,0x1EBB	,0x1EF7	,0x0000	), // "ỷ" LATIN SMALL LETTER Y WITH HOOK ABOVE
/*<!dead_abovehook>*/	DEADTRANS(	0x00A0	,0x1EBB	,0x02BE	,0x0000	), // "ʾ" MODIFIER LETTER RIGHT HALF RING
/*<!dead_abovehook>*/	DEADTRANS(	0x202F	,0x1EBB	,0x02BF	,0x0000	), // "ʿ" MODIFIER LETTER LEFT HALF RING
/*<!dead_abovehook>*/	DEADTRANS(	L' '	,0x1EBB	,0x0309	,0x0000	), // "̉" COMBINING HOOK ABOVE
/*<!dead_abovehook>*/	DEADTRANS(	0x200B	,0x1EBB	,0x0309	,0x0000	), // "̉" COMBINING HOOK ABOVE
/*<!dead_abovering>*/	DEADTRANS(	L'|'	,0x00E5	,0x2AEF	,0x0000	), // "⫯" VERTICAL LINE WITH CIRCLE ABOVE
/*<!dead_abovering>*/	DEADTRANS(	L'}'	,0x00E5	,0x29B2	,0x0000	), // "⦲" EMPTY SET WITH SMALL CIRCLE ABOVE
/*<!dead_abovering>*/	DEADTRANS(	L'('	,0x00E5	,0x0351	,0x0000	), // "͑" COMBINING LEFT HALF RING ABOVE
/*<!dead_abovering>*/	DEADTRANS(	L')'	,0x00E5	,0x0357	,0x0000	), // "͗" COMBINING RIGHT HALF RING ABOVE
/*<!dead_abovering>*/	DEADTRANS(	L'.'	,0x00E5	,0x2E30	,0x0000	), // "⸰" RING POINT
/*<!dead_abovering>*/	DEADTRANS(	L'+'	,0x00E5	,0x2A22	,0x0000	), // "⨢" PLUS SIGN WITH SMALL CIRCLE ABOVE
/*<!dead_abovering>*/	DEADTRANS(	L'0'	,0x00E5	,0x00B0	,0x0000	), // "°" DEGREE SIGN
/*<!dead_abovering>*/	DEADTRANS(	L'1'	,0x00E5	,0x204E	,0x0000	), // "⁎" LOW ASTERISK
/*<!dead_abovering>*/	DEADTRANS(	L'2'	,0x00E5	,0x2051	,0x0000	), // "⁑" TWO ASTERISKS ALIGNED VERTICALLY
/*<!dead_abovering>*/	DEADTRANS(	L'3'	,0x00E5	,0x2042	,0x0000	), // "⁂" ASTERISM
/*<!dead_abovering>*/	DEADTRANS(	L'4'	,0x00E5	,0x02D3	,0x0000	), // "˓" MODIFIER LETTER CENTRED LEFT HALF RING
/*<!dead_abovering>*/	DEADTRANS(	L'5'	,0x00E5	,0x2217	,0x0000	), // "∗" ASTERISK OPERATOR
/*<!dead_abovering>*/	DEADTRANS(	L'6'	,0x00E5	,0x02D2	,0x0000	), // "˒" MODIFIER LETTER CENTRED RIGHT HALF RING
/*<!dead_abovering>*/	DEADTRANS(	L'7'	,0x00E5	,0x02BF	,0x0000	), // "ʿ" MODIFIER LETTER LEFT HALF RING
/*<!dead_abovering>*/	DEADTRANS(	L'8'	,0x00E5	,0x00B0	,0x0000	), // "°" DEGREE SIGN
/*<!dead_abovering>*/	DEADTRANS(	L'9'	,0x00E5	,0x02BE	,0x0000	), // "ʾ" MODIFIER LETTER RIGHT HALF RING
/*<!dead_abovering>*/	DEADTRANS(	L'A'	,0x00E5	,0x00C5	,0x0000	), // "Å" LATIN CAPITAL LETTER A WITH RING ABOVE
/*<!dead_abovering>*/	DEADTRANS(	L'a'	,0x00E5	,0x00E5	,0x0000	), // "å" LATIN SMALL LETTER A WITH RING ABOVE
/*<!dead_abovering>*/	DEADTRANS(	L'C'	,0x00E5	,0x2103	,0x0000	), // "℃" DEGREE CELSIUS
/*<!dead_abovering>*/	DEADTRANS(	L'c'	,0x00E5	,0x2103	,0x0000	), // "℃" DEGREE CELSIUS
/*<!dead_abovering>*/	DEADTRANS(	L'F'	,0x00E5	,0x2109	,0x0000	), // "℉" DEGREE FAHRENHEIT
/*<!dead_abovering>*/	DEADTRANS(	L'f'	,0x00E5	,0x2109	,0x0000	), // "℉" DEGREE FAHRENHEIT
/*<!dead_abovering>*/	DEADTRANS(	L'K'	,0x00E5	,0x212A	,0x0000	), // "K" KELVIN SIGN
/*<!dead_abovering>*/	DEADTRANS(	L'k'	,0x00E5	,0x212A	,0x0000	), // "K" KELVIN SIGN
/*<!dead_abovering>*/	DEADTRANS(	L'l'	,0x00E5	,0xAB39	,0x0000	), // "ꬹ" LATIN SMALL LETTER L WITH MIDDLE RING
/*<!dead_abovering>*/	DEADTRANS(	L'o'	,0x00E5	,0x2C7A	,0x0000	), // "ⱺ" LATIN SMALL LETTER O WITH LOW RING INSIDE
/*<!dead_abovering>*/	DEADTRANS(	L'q'	,0x00E5	,0xAB54	,0x0000	), // "ꭔ" LATIN SMALL LETTER CHI WITH LOW RIGHT RING
/*<!dead_abovering>*/	DEADTRANS(	L'r'	,0x00E5	,0xAB4C	,0x0000	), // "ꭌ" LATIN SMALL LETTER SCRIPT R WITH RING
/*<!dead_abovering>*/	DEADTRANS(	L'T'	,0x00E5	,0x27DF	,0x0000	), // "⟟" UP TACK WITH CIRCLE ABOVE
/*<!dead_abovering>*/	DEADTRANS(	L't'	,0x00E5	,0x27DF	,0x0000	), // "⟟" UP TACK WITH CIRCLE ABOVE
/*<!dead_abovering>*/	DEADTRANS(	L'U'	,0x00E5	,0x016E	,0x0000	), // "Ů" LATIN CAPITAL LETTER U WITH RING ABOVE
/*<!dead_abovering>*/	DEADTRANS(	L'u'	,0x00E5	,0x016F	,0x0000	), // "ů" LATIN SMALL LETTER U WITH RING ABOVE
/*<!dead_abovering>*/	DEADTRANS(	L'w'	,0x00E5	,0x1E98	,0x0000	), // "ẘ" LATIN SMALL LETTER W WITH RING ABOVE
/*<!dead_abovering>*/	DEADTRANS(	L'x'	,0x00E5	,0xAB56	,0x0000	), // "ꭖ" LATIN SMALL LETTER X WITH LOW RIGHT RING
/*<!dead_abovering>*/	DEADTRANS(	L'X'	,0x00E5	,0xAB58	,0x0000	), // "ꭘ" LATIN SMALL LETTER X WITH LONG LEFT LEG AND LOW RIGHT RING
/*<!dead_abovering>*/	DEADTRANS(	L'y'	,0x00E5	,0x1E99	,0x0000	), // "ẙ" LATIN SMALL LETTER Y WITH RING ABOVE
/*<!dead_abovering>*/	DEADTRANS(	0x00A0	,0x00E5	,0x02DA	,0x0000	), // "˚" RING ABOVE
/*<!dead_abovering>*/	DEADTRANS(	0x202F	,0x00E5	,0x02DA	,0x0000	), // "˚" RING ABOVE
/*<!dead_abovering>*/	DEADTRANS(	L' '	,0x00E5	,0x030A	,0x0000	), // "̊" COMBINING RING ABOVE
/*<!dead_abovering>*/	DEADTRANS(	0x200B	,0x00E5	,0x030A	,0x0000	), // "̊" COMBINING RING ABOVE
/*<!dead_acute>*/	DEADTRANS(	L'&'	,0x00E1	,0x0317	,0x0000	), // "̗" COMBINING ACUTE ACCENT BELOW
/*<!dead_acute>*/	DEADTRANS(	L'\''	,0x00E1	,0x2019	,0x0000	), // "’" RIGHT SINGLE QUOTATION MARK, single comma quotation mark
/*<!dead_acute>*/	DEADTRANS(	0x2019	,0x00E1	,0x2019	,0x0000	), // "’" RIGHT SINGLE QUOTATION MARK, single comma quotation mark
/*<!dead_acute>*/	DEADTRANS(	L'"'	,0x00E1	,0x201D	,0x0000	), // "”" RIGHT DOUBLE QUOTATION MARK, double comma quotation mark
/*<!dead_acute>*/	DEADTRANS(	0x20AC	,0x00E1	,0x201D	,0x0000	), // "”" RIGHT DOUBLE QUOTATION MARK, double comma quotation mark
/*<!dead_acute>*/	DEADTRANS(	L'_'	,0x00E1	,0x02CF	,0x0000	), // "ˏ" MODIFIER LETTER LOW ACUTE ACCENT
/*<!dead_acute>*/	DEADTRANS(	L'1'	,0x00E1	,0x2032	,0x0000	), // "′" PRIME
/*<!dead_acute>*/	DEADTRANS(	L'2'	,0x00E1	,0x2033	,0x0000	), // "″" DOUBLE PRIME
/*<!dead_acute>*/	DEADTRANS(	L'3'	,0x00E1	,0x2034	,0x0000	), // "‴" TRIPLE PRIME
/*<!dead_acute>*/	DEADTRANS(	L'4'	,0x00E1	,0x2057	,0x0000	), // "⁗" QUADRUPLE PRIME
/*<!dead_acute>*/	DEADTRANS(	L'A'	,0x00E1	,0x00C1	,0x0000	), // "Á" LATIN CAPITAL LETTER A WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'a'	,0x00E1	,0x00E1	,0x0000	), // "á" LATIN SMALL LETTER A WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	0x00C0	,0x00E1	,0x00D5	,0x0000	), // "Õ" LATIN CAPITAL LETTER O WITH TILDE
/*<!dead_acute>*/	DEADTRANS(	0x00E0	,0x00E1	,0x00F5	,0x0000	), // "õ" LATIN SMALL LETTER O WITH TILDE
/*<!dead_acute>*/	DEADTRANS(	L'C'	,0x00E1	,0x0106	,0x0000	), // "Ć" LATIN CAPITAL LETTER C WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'c'	,0x00E1	,0x0107	,0x0000	), // "ć" LATIN SMALL LETTER C WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	0x00C7	,0x00E1	,0x1E08	,0x0000	), // "Ḉ" LATIN CAPITAL LETTER C WITH CEDILLA AND ACUTE
/*<!dead_acute>*/	DEADTRANS(	0x00E7	,0x00E1	,0x1E09	,0x0000	), // "ḉ" LATIN SMALL LETTER C WITH CEDILLA AND ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'E'	,0x00E1	,0x00C9	,0x0000	), // "É" LATIN CAPITAL LETTER E WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'e'	,0x00E1	,0x00E9	,0x0000	), // "é" LATIN SMALL LETTER E WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	0x00C9	,0x00E1	,0x00C3	,0x0000	), // "Ã" LATIN CAPITAL LETTER A WITH TILDE
/*<!dead_acute>*/	DEADTRANS(	0x00E9	,0x00E1	,0x00E3	,0x0000	), // "ã" LATIN SMALL LETTER A WITH TILDE
/*<!dead_acute>*/	DEADTRANS(	L'G'	,0x00E1	,0x01F4	,0x0000	), // "Ǵ" LATIN CAPITAL LETTER G WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'g'	,0x00E1	,0x01F5	,0x0000	), // "ǵ" LATIN SMALL LETTER G WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'I'	,0x00E1	,0x00CD	,0x0000	), // "Í" LATIN CAPITAL LETTER I WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'i'	,0x00E1	,0x00ED	,0x0000	), // "í" LATIN SMALL LETTER I WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'K'	,0x00E1	,0x1E30	,0x0000	), // "Ḱ" LATIN CAPITAL LETTER K WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'k'	,0x00E1	,0x1E31	,0x0000	), // "ḱ" LATIN SMALL LETTER K WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'L'	,0x00E1	,0x0139	,0x0000	), // "Ĺ" LATIN CAPITAL LETTER L WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'l'	,0x00E1	,0x013A	,0x0000	), // "ĺ" LATIN SMALL LETTER L WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'M'	,0x00E1	,0x1E3E	,0x0000	), // "Ḿ" LATIN CAPITAL LETTER M WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'm'	,0x00E1	,0x1E3F	,0x0000	), // "ḿ" LATIN SMALL LETTER M WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'N'	,0x00E1	,0x0143	,0x0000	), // "Ń" LATIN CAPITAL LETTER N WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'n'	,0x00E1	,0x0144	,0x0000	), // "ń" LATIN SMALL LETTER N WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'O'	,0x00E1	,0x00D3	,0x0000	), // "Ó" LATIN CAPITAL LETTER O WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'o'	,0x00E1	,0x00F3	,0x0000	), // "ó" LATIN SMALL LETTER O WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'P'	,0x00E1	,0x1E54	,0x0000	), // "Ṕ" LATIN CAPITAL LETTER P WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'p'	,0x00E1	,0x1E55	,0x0000	), // "ṕ" LATIN SMALL LETTER P WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'R'	,0x00E1	,0x0154	,0x0000	), // "Ŕ" LATIN CAPITAL LETTER R WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'r'	,0x00E1	,0x0155	,0x0000	), // "ŕ" LATIN SMALL LETTER R WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'S'	,0x00E1	,0x015A	,0x0000	), // "Ś" LATIN CAPITAL LETTER S WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L's'	,0x00E1	,0x015B	,0x0000	), // "ś" LATIN SMALL LETTER S WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'U'	,0x00E1	,0x00DA	,0x0000	), // "Ú" LATIN CAPITAL LETTER U WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'u'	,0x00E1	,0x00FA	,0x0000	), // "ú" LATIN SMALL LETTER U WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'W'	,0x00E1	,0x1E82	,0x0000	), // "Ẃ" LATIN CAPITAL LETTER W WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'w'	,0x00E1	,0x1E83	,0x0000	), // "ẃ" LATIN SMALL LETTER W WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'Y'	,0x00E1	,0x00DD	,0x0000	), // "Ý" LATIN CAPITAL LETTER Y WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'y'	,0x00E1	,0x00FD	,0x0000	), // "ý" LATIN SMALL LETTER Y WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'Z'	,0x00E1	,0x0179	,0x0000	), // "Ź" LATIN CAPITAL LETTER Z WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	L'z'	,0x00E1	,0x017A	,0x0000	), // "ź" LATIN SMALL LETTER Z WITH ACUTE
/*<!dead_acute>*/	DEADTRANS(	0x00A0	,0x00E1	,0x00B4	,0x0000	), // "´" ACUTE ACCENT
/*<!dead_acute>*/	DEADTRANS(	0x202F	,0x00E1	,0x02CA	,0x0000	), // "ˊ" MODIFIER LETTER ACUTE ACCENT
/*<!dead_acute>*/	DEADTRANS(	L' '	,0x00E1	,0x0301	,0x0000	), // "́" COMBINING ACUTE ACCENT
/*<!dead_acute>*/	DEADTRANS(	0x200B	,0x00E1	,0x0301	,0x0000	), // "́" COMBINING ACUTE ACCENT
/*<!dead_bar>*/	DEADTRANS(	L'}'	,0x024D	,0x29B5	,0x0000	), // "⦵" CIRCLE WITH HORIZONTAL BAR
/*<!dead_bar>*/	DEADTRANS(	L'['	,0x024D	,0x2045	,0x0000	), // "⁅" LEFT SQUARE BRACKET WITH QUILL
/*<!dead_bar>*/	DEADTRANS(	L']'	,0x024D	,0x2046	,0x0000	), // "⁆" RIGHT SQUARE BRACKET WITH QUILL
/*<!dead_bar>*/	DEADTRANS(	L'2'	,0x024D	,0x01BB	,0x0000	), // "ƻ" LATIN LETTER TWO WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'7'	,0x024D	,0x02A1	,0x0000	), // "ʡ" LATIN LETTER GLOTTAL STOP WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'A'	,0x024D	,0xA73A	,0x0000	), // "Ꜻ" LATIN CAPITAL LETTER AV WITH HORIZONTAL BAR
/*<!dead_bar>*/	DEADTRANS(	L'a'	,0x024D	,0xA73B	,0x0000	), // "ꜻ" LATIN SMALL LETTER AV WITH HORIZONTAL BAR
/*<!dead_bar>*/	DEADTRANS(	L'b'	,0x024D	,0x0180	,0x0000	), // "ƀ" LATIN SMALL LETTER B WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'B'	,0x024D	,0x0243	,0x0000	), // "Ƀ" LATIN CAPITAL LETTER B WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'C'	,0x024D	,0xA792	,0x0000	), // "Ꞓ" LATIN CAPITAL LETTER C WITH BAR
/*<!dead_bar>*/	DEADTRANS(	L'c'	,0x024D	,0xA793	,0x0000	), // "ꞓ" LATIN SMALL LETTER C WITH BAR
/*<!dead_bar>*/	DEADTRANS(	L'D'	,0x024D	,0x0110	,0x0000	), // "Đ" LATIN CAPITAL LETTER D WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'd'	,0x024D	,0x0111	,0x0000	), // "đ" LATIN SMALL LETTER D WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'e'	,0x024D	,0xAB33	,0x0000	), // "ꬳ" LATIN SMALL LETTER BARRED E
/*<!dead_bar>*/	DEADTRANS(	L'F'	,0x024D	,0xA798	,0x0000	), // "Ꞙ" LATIN CAPITAL LETTER F WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'f'	,0x024D	,0xA799	,0x0000	), // "ꞙ" LATIN SMALL LETTER F WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'G'	,0x024D	,0x01E4	,0x0000	), // "Ǥ" LATIN CAPITAL LETTER G WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'g'	,0x024D	,0x01E5	,0x0000	), // "ǥ" LATIN SMALL LETTER G WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'H'	,0x024D	,0x0126	,0x0000	), // "Ħ" LATIN CAPITAL LETTER H WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'h'	,0x024D	,0x0127	,0x0000	), // "ħ" LATIN SMALL LETTER H WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'I'	,0x024D	,0x0197	,0x0000	), // "Ɨ" LATIN CAPITAL LETTER I WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'i'	,0x024D	,0x0268	,0x0000	), // "ɨ" LATIN SMALL LETTER I WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'J'	,0x024D	,0x0248	,0x0000	), // "Ɉ" LATIN CAPITAL LETTER J WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'j'	,0x024D	,0x0249	,0x0000	), // "ɉ" LATIN SMALL LETTER J WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'K'	,0x024D	,0xA740	,0x0000	), // "Ꝁ" LATIN CAPITAL LETTER K WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'k'	,0x024D	,0xA741	,0x0000	), // "ꝁ" LATIN SMALL LETTER K WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'l'	,0x024D	,0x019A	,0x0000	), // "ƚ" LATIN SMALL LETTER L WITH BAR
/*<!dead_bar>*/	DEADTRANS(	L'L'	,0x024D	,0x023D	,0x0000	), // "Ƚ" LATIN CAPITAL LETTER L WITH BAR
/*<!dead_bar>*/	DEADTRANS(	L'O'	,0x024D	,0x019F	,0x0000	), // "Ɵ" LATIN CAPITAL LETTER O WITH MIDDLE TILDE
/*<!dead_bar>*/	DEADTRANS(	L'o'	,0x024D	,0x0275	,0x0000	), // "ɵ" LATIN SMALL LETTER BARRED O
/*<!dead_bar>*/	DEADTRANS(	L'p'	,0x024D	,0x1D7D	,0x0000	), // "ᵽ" LATIN SMALL LETTER P WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'P'	,0x024D	,0x2C63	,0x0000	), // "Ᵽ" LATIN CAPITAL LETTER P WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'Q'	,0x024D	,0x02A1	,0x0000	), // "ʡ" LATIN LETTER GLOTTAL STOP WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'q'	,0x024D	,0x02A1	,0x0000	), // "ʡ" LATIN LETTER GLOTTAL STOP WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'R'	,0x024D	,0x024C	,0x0000	), // "Ɍ" LATIN CAPITAL LETTER R WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'r'	,0x024D	,0x024D	,0x0000	), // "ɍ" LATIN SMALL LETTER R WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'S'	,0x024D	,0xA7C9	,0x0000	), // "Ꟊ" LATIN CAPITAL LETTER S WITH SHORT STROKE OVERLAY
/*<!dead_bar>*/	DEADTRANS(	L's'	,0x024D	,0xA7CA	,0x0000	), // "ꟊ" LATIN SMALL LETTER S WITH SHORT STROKE OVERLAY
/*<!dead_bar>*/	DEADTRANS(	L'T'	,0x024D	,0x0166	,0x0000	), // "Ŧ" LATIN CAPITAL LETTER T WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L't'	,0x024D	,0x0167	,0x0000	), // "ŧ" LATIN SMALL LETTER T WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'U'	,0x024D	,0x0244	,0x0000	), // "Ʉ" LATIN CAPITAL LETTER U BAR
/*<!dead_bar>*/	DEADTRANS(	L'u'	,0x024D	,0x0289	,0x0000	), // "ʉ" LATIN SMALL LETTER U BAR
/*<!dead_bar>*/	DEADTRANS(	L'Y'	,0x024D	,0x024E	,0x0000	), // "Ɏ" LATIN CAPITAL LETTER Y WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'y'	,0x024D	,0x024F	,0x0000	), // "ɏ" LATIN SMALL LETTER Y WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'Z'	,0x024D	,0x01B5	,0x0000	), // "Ƶ" LATIN CAPITAL LETTER Z WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	L'z'	,0x024D	,0x01B6	,0x0000	), // "ƶ" LATIN SMALL LETTER Z WITH STROKE
/*<!dead_bar>*/	DEADTRANS(	0x00A0	,0x024D	,0x02D7	,0x0000	), // "˗" MODIFIER LETTER MINUS SIGN
/*<!dead_bar>*/	DEADTRANS(	0x202F	,0x024D	,0x02D7	,0x0000	), // "˗" MODIFIER LETTER MINUS SIGN
/*<!dead_bar>*/	DEADTRANS(	L' '	,0x024D	,0x0335	,0x0000	), // "̵" COMBINING SHORT STROKE OVERLAY
/*<!dead_bar>*/	DEADTRANS(	0x200B	,0x024D	,0x0335	,0x0000	), // "̵" COMBINING SHORT STROKE OVERLAY
/*<!dead_belowcomma>*/	DEADTRANS(	L'0'	,0x0219	,0x249B	,0x0000	), // "⒛" NUMBER TWENTY FULL STOP
/*<!dead_belowcomma>*/	DEADTRANS(	L'1'	,0x0219	,0x2492	,0x0000	), // "⒒" NUMBER ELEVEN FULL STOP
/*<!dead_belowcomma>*/	DEADTRANS(	L'2'	,0x0219	,0x2493	,0x0000	), // "⒓" NUMBER TWELVE FULL STOP
/*<!dead_belowcomma>*/	DEADTRANS(	L'3'	,0x0219	,0x2494	,0x0000	), // "⒔" NUMBER THIRTEEN FULL STOP
/*<!dead_belowcomma>*/	DEADTRANS(	L'4'	,0x0219	,0x2495	,0x0000	), // "⒕" NUMBER FOURTEEN FULL STOP
/*<!dead_belowcomma>*/	DEADTRANS(	L'5'	,0x0219	,0x2496	,0x0000	), // "⒖" NUMBER FIFTEEN FULL STOP
/*<!dead_belowcomma>*/	DEADTRANS(	L'6'	,0x0219	,0x2497	,0x0000	), // "⒗" NUMBER SIXTEEN FULL STOP
/*<!dead_belowcomma>*/	DEADTRANS(	L'7'	,0x0219	,0x2498	,0x0000	), // "⒘" NUMBER SEVENTEEN FULL STOP
/*<!dead_belowcomma>*/	DEADTRANS(	L'8'	,0x0219	,0x2499	,0x0000	), // "⒙" NUMBER EIGHTEEN FULL STOP
/*<!dead_belowcomma>*/	DEADTRANS(	L'9'	,0x0219	,0x249A	,0x0000	), // "⒚" NUMBER NINETEEN FULL STOP
/*<!dead_belowcomma>*/	DEADTRANS(	L'A'	,0x0219	,0xA7BA	,0x0000	), // "Ꞻ" LATIN CAPITAL LETTER GLOTTAL A
/*<!dead_belowcomma>*/	DEADTRANS(	L'a'	,0x0219	,0xA7BB	,0x0000	), // "ꞻ" LATIN SMALL LETTER GLOTTAL A
/*<!dead_belowcomma>*/	DEADTRANS(	L'I'	,0x0219	,0xA7BC	,0x0000	), // "Ꞽ" LATIN CAPITAL LETTER GLOTTAL I
/*<!dead_belowcomma>*/	DEADTRANS(	L'i'	,0x0219	,0xA7BD	,0x0000	), // "ꞽ" LATIN SMALL LETTER GLOTTAL I
/*<!dead_belowcomma>*/	DEADTRANS(	L'K'	,0x0219	,0xA72E	,0x0000	), // "Ꜯ" LATIN CAPITAL LETTER CUATRILLO WITH COMMA
/*<!dead_belowcomma>*/	DEADTRANS(	L'k'	,0x0219	,0xA72F	,0x0000	), // "ꜯ" LATIN SMALL LETTER CUATRILLO WITH COMMA
/*<!dead_belowcomma>*/	DEADTRANS(	L'S'	,0x0219	,0x0218	,0x0000	), // "Ș" LATIN CAPITAL LETTER S WITH COMMA BELOW
/*<!dead_belowcomma>*/	DEADTRANS(	L's'	,0x0219	,0x0219	,0x0000	), // "ș" LATIN SMALL LETTER S WITH COMMA BELOW
/*<!dead_belowcomma>*/	DEADTRANS(	L'T'	,0x0219	,0x021A	,0x0000	), // "Ț" LATIN CAPITAL LETTER T WITH COMMA BELOW
/*<!dead_belowcomma>*/	DEADTRANS(	L't'	,0x0219	,0x021B	,0x0000	), // "ț" LATIN SMALL LETTER T WITH COMMA BELOW
/*<!dead_belowcomma>*/	DEADTRANS(	L'U'	,0x0219	,0xA7BE	,0x0000	), // "Ꞿ" LATIN CAPITAL LETTER GLOTTAL U
/*<!dead_belowcomma>*/	DEADTRANS(	L'u'	,0x0219	,0xA7BF	,0x0000	), // "ꞿ" LATIN SMALL LETTER GLOTTAL U
/*<!dead_belowcomma>*/	DEADTRANS(	0x00A0	,0x0219	,0x2E34	,0x0000	), // "⸴" RAISED COMMA
/*<!dead_belowcomma>*/	DEADTRANS(	0x202F	,0x0219	,0x2E34	,0x0000	), // "⸴" RAISED COMMA
/*<!dead_belowcomma>*/	DEADTRANS(	L' '	,0x0219	,0x0326	,0x0000	), // "̦" COMBINING COMMA BELOW
/*<!dead_belowcomma>*/	DEADTRANS(	0x200B	,0x0219	,0x0326	,0x0000	), // "̦" COMBINING COMMA BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'='	,0x1E05	,0x2A66	,0x0000	), // "⩦" EQUALS SIGN WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'-'	,0x1E05	,0x2A2A	,0x0000	), // "⨪" MINUS SIGN WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'+'	,0x1E05	,0x2A25	,0x0000	), // "⨥" PLUS SIGN WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'_'	,0x1E05	,0x20E8	,0x0000	), // "⃨" COMBINING TRIPLE UNDERDOT
/*<!dead_belowdot>*/	DEADTRANS(	L'0'	,0x1E05	,0x2E2A	,0x0000	), // "⸪" TWO DOTS OVER ONE DOT PUNCTUATION
/*<!dead_belowdot>*/	DEADTRANS(	L'1'	,0x1E05	,0x2E2B	,0x0000	), // "⸫" ONE DOT OVER TWO DOTS PUNCTUATION
/*<!dead_belowdot>*/	DEADTRANS(	L'2'	,0x1E05	,0x205A	,0x0000	), // "⁚" TWO DOT PUNCTUATION
/*<!dead_belowdot>*/	DEADTRANS(	L'3'	,0x1E05	,0x205D	,0x0000	), // "⁝" TRICOLON
/*<!dead_belowdot>*/	DEADTRANS(	L'4'	,0x1E05	,0x205E	,0x0000	), // "⁞" VERTICAL FOUR DOTS
/*<!dead_belowdot>*/	DEADTRANS(	L'5'	,0x1E05	,0x2059	,0x0000	), // "⁙" FIVE DOT PUNCTUATION
/*<!dead_belowdot>*/	DEADTRANS(	L'6'	,0x1E05	,0x2E3D	,0x0000	), // "⸽" VERTICAL SIX DOTS
/*<!dead_belowdot>*/	DEADTRANS(	L'7'	,0x1E05	,0x2E2C	,0x0000	), // "⸬" SQUARED FOUR DOT PUNCTUATION
/*<!dead_belowdot>*/	DEADTRANS(	L'8'	,0x1E05	,0x2058	,0x0000	), // "⁘" FOUR DOT PUNCTUATION
/*<!dead_belowdot>*/	DEADTRANS(	L'9'	,0x1E05	,0x205B	,0x0000	), // "⁛" FOUR DOT MARK
/*<!dead_belowdot>*/	DEADTRANS(	L'A'	,0x1E05	,0x1EA0	,0x0000	), // "Ạ" LATIN CAPITAL LETTER A WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'a'	,0x1E05	,0x1EA1	,0x0000	), // "ạ" LATIN SMALL LETTER A WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'B'	,0x1E05	,0x1E04	,0x0000	), // "Ḅ" LATIN CAPITAL LETTER B WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'b'	,0x1E05	,0x1E05	,0x0000	), // "ḅ" LATIN SMALL LETTER B WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'D'	,0x1E05	,0x1E0C	,0x0000	), // "Ḍ" LATIN CAPITAL LETTER D WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'd'	,0x1E05	,0x1E0D	,0x0000	), // "ḍ" LATIN SMALL LETTER D WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'E'	,0x1E05	,0x1EB8	,0x0000	), // "Ẹ" LATIN CAPITAL LETTER E WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'e'	,0x1E05	,0x1EB9	,0x0000	), // "ẹ" LATIN SMALL LETTER E WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'H'	,0x1E05	,0x1E24	,0x0000	), // "Ḥ" LATIN CAPITAL LETTER H WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'h'	,0x1E05	,0x1E25	,0x0000	), // "ḥ" LATIN SMALL LETTER H WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'I'	,0x1E05	,0x1ECA	,0x0000	), // "Ị" LATIN CAPITAL LETTER I WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'i'	,0x1E05	,0x1ECB	,0x0000	), // "ị" LATIN SMALL LETTER I WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'K'	,0x1E05	,0x1E32	,0x0000	), // "Ḳ" LATIN CAPITAL LETTER K WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'k'	,0x1E05	,0x1E33	,0x0000	), // "ḳ" LATIN SMALL LETTER K WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'L'	,0x1E05	,0x1E36	,0x0000	), // "Ḷ" LATIN CAPITAL LETTER L WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'l'	,0x1E05	,0x1E37	,0x0000	), // "ḷ" LATIN SMALL LETTER L WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'M'	,0x1E05	,0x1E42	,0x0000	), // "Ṃ" LATIN CAPITAL LETTER M WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'm'	,0x1E05	,0x1E43	,0x0000	), // "ṃ" LATIN SMALL LETTER M WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'N'	,0x1E05	,0x1E46	,0x0000	), // "Ṇ" LATIN CAPITAL LETTER N WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'n'	,0x1E05	,0x1E47	,0x0000	), // "ṇ" LATIN SMALL LETTER N WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'O'	,0x1E05	,0x1ECC	,0x0000	), // "Ọ" LATIN CAPITAL LETTER O WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'o'	,0x1E05	,0x1ECD	,0x0000	), // "ọ" LATIN SMALL LETTER O WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'R'	,0x1E05	,0x1E5A	,0x0000	), // "Ṛ" LATIN CAPITAL LETTER R WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'r'	,0x1E05	,0x1E5B	,0x0000	), // "ṛ" LATIN SMALL LETTER R WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'S'	,0x1E05	,0x1E62	,0x0000	), // "Ṣ" LATIN CAPITAL LETTER S WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L's'	,0x1E05	,0x1E63	,0x0000	), // "ṣ" LATIN SMALL LETTER S WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'T'	,0x1E05	,0x1E6C	,0x0000	), // "Ṭ" LATIN CAPITAL LETTER T WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L't'	,0x1E05	,0x1E6D	,0x0000	), // "ṭ" LATIN SMALL LETTER T WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'U'	,0x1E05	,0x1EE4	,0x0000	), // "Ụ" LATIN CAPITAL LETTER U WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'u'	,0x1E05	,0x1EE5	,0x0000	), // "ụ" LATIN SMALL LETTER U WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'V'	,0x1E05	,0x1E7E	,0x0000	), // "Ṿ" LATIN CAPITAL LETTER V WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'v'	,0x1E05	,0x1E7F	,0x0000	), // "ṿ" LATIN SMALL LETTER V WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'W'	,0x1E05	,0x1E88	,0x0000	), // "Ẉ" LATIN CAPITAL LETTER W WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'w'	,0x1E05	,0x1E89	,0x0000	), // "ẉ" LATIN SMALL LETTER W WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'Y'	,0x1E05	,0x1EF4	,0x0000	), // "Ỵ" LATIN CAPITAL LETTER Y WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'y'	,0x1E05	,0x1EF5	,0x0000	), // "ỵ" LATIN SMALL LETTER Y WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'Z'	,0x1E05	,0x1E92	,0x0000	), // "Ẓ" LATIN CAPITAL LETTER Z WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	L'z'	,0x1E05	,0x1E93	,0x0000	), // "ẓ" LATIN SMALL LETTER Z WITH DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	0x00A0	,0x1E05	,0x2E33	,0x0000	), // "⸳" RAISED DOT
/*<!dead_belowdot>*/	DEADTRANS(	0x202F	,0x1E05	,0x2E33	,0x0000	), // "⸳" RAISED DOT
/*<!dead_belowdot>*/	DEADTRANS(	L' '	,0x1E05	,0x0323	,0x0000	), // "̣" COMBINING DOT BELOW
/*<!dead_belowdot>*/	DEADTRANS(	0x200B	,0x1E05	,0x0323	,0x0000	), // "̣" COMBINING DOT BELOW
/*<!dead_breve>*/	DEADTRANS(	L'='	,0x0115	,0x035D	,0x0000	), // "͝" COMBINING DOUBLE BREVE
/*<!dead_breve>*/	DEADTRANS(	L'A'	,0x0115	,0x0102	,0x0000	), // "Ă" LATIN CAPITAL LETTER A WITH BREVE
/*<!dead_breve>*/	DEADTRANS(	L'a'	,0x0115	,0x0103	,0x0000	), // "ă" LATIN SMALL LETTER A WITH BREVE
/*<!dead_breve>*/	DEADTRANS(	0x00C0	,0x0115	,0x1EB0	,0x0000	), // "Ằ" LATIN CAPITAL LETTER A WITH BREVE AND GRAVE
/*<!dead_breve>*/	DEADTRANS(	0x00E0	,0x0115	,0x1EB1	,0x0000	), // "ằ" LATIN SMALL LETTER A WITH BREVE AND GRAVE
/*<!dead_breve>*/	DEADTRANS(	L'C'	,0x0115	,0x02D2	,0x0000	), // "˒" MODIFIER LETTER CENTRED RIGHT HALF RING
/*<!dead_breve>*/	DEADTRANS(	L'c'	,0x0115	,0x02D2	,0x0000	), // "˒" MODIFIER LETTER CENTRED RIGHT HALF RING
/*<!dead_breve>*/	DEADTRANS(	L'E'	,0x0115	,0x0114	,0x0000	), // "Ĕ" LATIN CAPITAL LETTER E WITH BREVE
/*<!dead_breve>*/	DEADTRANS(	L'e'	,0x0115	,0x0115	,0x0000	), // "ĕ" LATIN SMALL LETTER E WITH BREVE
/*<!dead_breve>*/	DEADTRANS(	0x2014	,0x0115	,0x035D	,0x0000	), // "͝" COMBINING DOUBLE BREVE
/*<!dead_breve>*/	DEADTRANS(	L'G'	,0x0115	,0x011E	,0x0000	), // "Ğ" LATIN CAPITAL LETTER G WITH BREVE
/*<!dead_breve>*/	DEADTRANS(	L'g'	,0x0115	,0x011F	,0x0000	), // "ğ" LATIN SMALL LETTER G WITH BREVE
/*<!dead_breve>*/	DEADTRANS(	L'H'	,0x0115	,0x1E2A	,0x0000	), // "Ḫ" LATIN CAPITAL LETTER H WITH BREVE BELOW
/*<!dead_breve>*/	DEADTRANS(	L'h'	,0x0115	,0x1E2B	,0x0000	), // "ḫ" LATIN SMALL LETTER H WITH BREVE BELOW
/*<!dead_breve>*/	DEADTRANS(	L'I'	,0x0115	,0x012C	,0x0000	), // "Ĭ" LATIN CAPITAL LETTER I WITH BREVE
/*<!dead_breve>*/	DEADTRANS(	L'i'	,0x0115	,0x012D	,0x0000	), // "ĭ" LATIN SMALL LETTER I WITH BREVE
/*<!dead_breve>*/	DEADTRANS(	L'O'	,0x0115	,0x014E	,0x0000	), // "Ŏ" LATIN CAPITAL LETTER O WITH BREVE
/*<!dead_breve>*/	DEADTRANS(	L'o'	,0x0115	,0x014F	,0x0000	), // "ŏ" LATIN SMALL LETTER O WITH BREVE
/*<!dead_breve>*/	DEADTRANS(	L'U'	,0x0115	,0x016C	,0x0000	), // "Ŭ" LATIN CAPITAL LETTER U WITH BREVE
/*<!dead_breve>*/	DEADTRANS(	L'u'	,0x0115	,0x016D	,0x0000	), // "ŭ" LATIN SMALL LETTER U WITH BREVE
/*<!dead_breve>*/	DEADTRANS(	L'y'	,0x0115	,0xAB5A	,0x0000	), // "ꭚ" LATIN SMALL LETTER Y WITH SHORT RIGHT LEG
/*<!dead_breve>*/	DEADTRANS(	0x00A0	,0x0115	,0x02D8	,0x0000	), // "˘" BREVE
/*<!dead_breve>*/	DEADTRANS(	0x202F	,0x0115	,0x02D8	,0x0000	), // "˘" BREVE
/*<!dead_breve>*/	DEADTRANS(	L' '	,0x0115	,0x0306	,0x0000	), // "̆" COMBINING BREVE
/*<!dead_breve>*/	DEADTRANS(	0x200B	,0x0115	,0x0306	,0x0000	), // "̆" COMBINING BREVE
/*<!dead_caron>*/	DEADTRANS(	L'|'	,0x021F	,0x2E37	,0x0000	), // "⸷" DAGGER WITH RIGHT GUARD
/*<!dead_caron>*/	DEADTRANS(	L'0'	,0x021F	,0x2080	,0x0000	), // "₀" SUBSCRIPT ZERO
/*<!dead_caron>*/	DEADTRANS(	L'1'	,0x021F	,0x2081	,0x0000	), // "₁" SUBSCRIPT ONE
/*<!dead_caron>*/	DEADTRANS(	L'2'	,0x021F	,0x2082	,0x0000	), // "₂" SUBSCRIPT TWO
/*<!dead_caron>*/	DEADTRANS(	L'3'	,0x021F	,0x2083	,0x0000	), // "₃" SUBSCRIPT THREE
/*<!dead_caron>*/	DEADTRANS(	L'4'	,0x021F	,0x2084	,0x0000	), // "₄" SUBSCRIPT FOUR
/*<!dead_caron>*/	DEADTRANS(	L'5'	,0x021F	,0x2085	,0x0000	), // "₅" SUBSCRIPT FIVE
/*<!dead_caron>*/	DEADTRANS(	L'6'	,0x021F	,0x2086	,0x0000	), // "₆" SUBSCRIPT SIX
/*<!dead_caron>*/	DEADTRANS(	L'7'	,0x021F	,0x2087	,0x0000	), // "₇" SUBSCRIPT SEVEN
/*<!dead_caron>*/	DEADTRANS(	L'8'	,0x021F	,0x2088	,0x0000	), // "₈" SUBSCRIPT EIGHT
/*<!dead_caron>*/	DEADTRANS(	L'9'	,0x021F	,0x2089	,0x0000	), // "₉" SUBSCRIPT NINE
/*<!dead_caron>*/	DEADTRANS(	L'A'	,0x021F	,0x01CD	,0x0000	), // "Ǎ" LATIN CAPITAL LETTER A WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'a'	,0x021F	,0x01CE	,0x0000	), // "ǎ" LATIN SMALL LETTER A WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'C'	,0x021F	,0x010C	,0x0000	), // "Č" LATIN CAPITAL LETTER C WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'c'	,0x021F	,0x010D	,0x0000	), // "č" LATIN SMALL LETTER C WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'D'	,0x021F	,0x010E	,0x0000	), // "Ď" LATIN CAPITAL LETTER D WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'd'	,0x021F	,0x010F	,0x0000	), // "ď" LATIN SMALL LETTER D WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'E'	,0x021F	,0x011A	,0x0000	), // "Ě" LATIN CAPITAL LETTER E WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'e'	,0x021F	,0x011B	,0x0000	), // "ě" LATIN SMALL LETTER E WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'G'	,0x021F	,0x01E6	,0x0000	), // "Ǧ" LATIN CAPITAL LETTER G WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'g'	,0x021F	,0x01E7	,0x0000	), // "ǧ" LATIN SMALL LETTER G WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'H'	,0x021F	,0x021E	,0x0000	), // "Ȟ" LATIN CAPITAL LETTER H WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'h'	,0x021F	,0x021F	,0x0000	), // "ȟ" LATIN SMALL LETTER H WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'I'	,0x021F	,0x01CF	,0x0000	), // "Ǐ" LATIN CAPITAL LETTER I WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'i'	,0x021F	,0x01D0	,0x0000	), // "ǐ" LATIN SMALL LETTER I WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'j'	,0x021F	,0x01F0	,0x0000	), // "ǰ" LATIN SMALL LETTER J WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'K'	,0x021F	,0x01E8	,0x0000	), // "Ǩ" LATIN CAPITAL LETTER K WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'k'	,0x021F	,0x01E9	,0x0000	), // "ǩ" LATIN SMALL LETTER K WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'L'	,0x021F	,0x013D	,0x0000	), // "Ľ" LATIN CAPITAL LETTER L WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'l'	,0x021F	,0x013E	,0x0000	), // "ľ" LATIN SMALL LETTER L WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'N'	,0x021F	,0x0147	,0x0000	), // "Ň" LATIN CAPITAL LETTER N WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'n'	,0x021F	,0x0148	,0x0000	), // "ň" LATIN SMALL LETTER N WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'O'	,0x021F	,0x01D1	,0x0000	), // "Ǒ" LATIN CAPITAL LETTER O WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'o'	,0x021F	,0x01D2	,0x0000	), // "ǒ" LATIN SMALL LETTER O WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'R'	,0x021F	,0x0158	,0x0000	), // "Ř" LATIN CAPITAL LETTER R WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'r'	,0x021F	,0x0159	,0x0000	), // "ř" LATIN SMALL LETTER R WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'S'	,0x021F	,0x0160	,0x0000	), // "Š" LATIN CAPITAL LETTER S WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L's'	,0x021F	,0x0161	,0x0000	), // "š" LATIN SMALL LETTER S WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'T'	,0x021F	,0x0164	,0x0000	), // "Ť" LATIN CAPITAL LETTER T WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L't'	,0x021F	,0x0165	,0x0000	), // "ť" LATIN SMALL LETTER T WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'U'	,0x021F	,0x01D3	,0x0000	), // "Ǔ" LATIN CAPITAL LETTER U WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'u'	,0x021F	,0x01D4	,0x0000	), // "ǔ" LATIN SMALL LETTER U WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'Z'	,0x021F	,0x017D	,0x0000	), // "Ž" LATIN CAPITAL LETTER Z WITH CARON
/*<!dead_caron>*/	DEADTRANS(	L'z'	,0x021F	,0x017E	,0x0000	), // "ž" LATIN SMALL LETTER Z WITH CARON
/*<!dead_caron>*/	DEADTRANS(	0x00A0	,0x021F	,0x02C7	,0x0000	), // "ˇ" CARON
/*<!dead_caron>*/	DEADTRANS(	0x202F	,0x021F	,0x02C7	,0x0000	), // "ˇ" CARON
/*<!dead_caron>*/	DEADTRANS(	L' '	,0x021F	,0x030C	,0x0000	), // "̌" COMBINING CARON
/*<!dead_caron>*/	DEADTRANS(	0x200B	,0x021F	,0x030C	,0x0000	), // "̌" COMBINING CARON
/*<!dead_cedilla>*/	DEADTRANS(	L'0'	,0x00E7	,0x2491	,0x0000	), // "⒑" NUMBER TEN FULL STOP
/*<!dead_cedilla>*/	DEADTRANS(	L'1'	,0x00E7	,0x2488	,0x0000	), // "⒈" DIGIT ONE FULL STOP
/*<!dead_cedilla>*/	DEADTRANS(	L'2'	,0x00E7	,0x2489	,0x0000	), // "⒉" DIGIT TWO FULL STOP
/*<!dead_cedilla>*/	DEADTRANS(	L'3'	,0x00E7	,0x248A	,0x0000	), // "⒊" DIGIT THREE FULL STOP
/*<!dead_cedilla>*/	DEADTRANS(	L'4'	,0x00E7	,0x248B	,0x0000	), // "⒋" DIGIT FOUR FULL STOP
/*<!dead_cedilla>*/	DEADTRANS(	L'5'	,0x00E7	,0x248C	,0x0000	), // "⒌" DIGIT FIVE FULL STOP
/*<!dead_cedilla>*/	DEADTRANS(	L'6'	,0x00E7	,0x248D	,0x0000	), // "⒍" DIGIT SIX FULL STOP
/*<!dead_cedilla>*/	DEADTRANS(	L'7'	,0x00E7	,0x248E	,0x0000	), // "⒎" DIGIT SEVEN FULL STOP
/*<!dead_cedilla>*/	DEADTRANS(	L'8'	,0x00E7	,0x248F	,0x0000	), // "⒏" DIGIT EIGHT FULL STOP
/*<!dead_cedilla>*/	DEADTRANS(	L'9'	,0x00E7	,0x2490	,0x0000	), // "⒐" DIGIT NINE FULL STOP
/*<!dead_cedilla>*/	DEADTRANS(	L'C'	,0x00E7	,0x00C7	,0x0000	), // "Ç" LATIN CAPITAL LETTER C WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'c'	,0x00E7	,0x00E7	,0x0000	), // "ç" LATIN SMALL LETTER C WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'D'	,0x00E7	,0x1E10	,0x0000	), // "Ḑ" LATIN CAPITAL LETTER D WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'd'	,0x00E7	,0x1E11	,0x0000	), // "ḑ" LATIN SMALL LETTER D WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'E'	,0x00E7	,0x0228	,0x0000	), // "Ȩ" LATIN CAPITAL LETTER E WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'e'	,0x00E7	,0x0229	,0x0000	), // "ȩ" LATIN SMALL LETTER E WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'G'	,0x00E7	,0x0122	,0x0000	), // "Ģ" LATIN CAPITAL LETTER G WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'g'	,0x00E7	,0x0123	,0x0000	), // "ģ" LATIN SMALL LETTER G WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'H'	,0x00E7	,0x1E28	,0x0000	), // "Ḩ" LATIN CAPITAL LETTER H WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'h'	,0x00E7	,0x1E29	,0x0000	), // "ḩ" LATIN SMALL LETTER H WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'K'	,0x00E7	,0x0136	,0x0000	), // "Ķ" LATIN CAPITAL LETTER K WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'k'	,0x00E7	,0x0137	,0x0000	), // "ķ" LATIN SMALL LETTER K WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'L'	,0x00E7	,0x013B	,0x0000	), // "Ļ" LATIN CAPITAL LETTER L WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'l'	,0x00E7	,0x013C	,0x0000	), // "ļ" LATIN SMALL LETTER L WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'N'	,0x00E7	,0x0145	,0x0000	), // "Ņ" LATIN CAPITAL LETTER N WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'n'	,0x00E7	,0x0146	,0x0000	), // "ņ" LATIN SMALL LETTER N WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'R'	,0x00E7	,0x0156	,0x0000	), // "Ŗ" LATIN CAPITAL LETTER R WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'r'	,0x00E7	,0x0157	,0x0000	), // "ŗ" LATIN SMALL LETTER R WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'S'	,0x00E7	,0x015E	,0x0000	), // "Ş" LATIN CAPITAL LETTER S WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L's'	,0x00E7	,0x015F	,0x0000	), // "ş" LATIN SMALL LETTER S WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L'T'	,0x00E7	,0x0162	,0x0000	), // "Ţ" LATIN CAPITAL LETTER T WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L't'	,0x00E7	,0x0163	,0x0000	), // "ţ" LATIN SMALL LETTER T WITH CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	0x00A0	,0x00E7	,0x00B8	,0x0000	), // "¸" CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	0x202F	,0x00E7	,0x00B8	,0x0000	), // "¸" CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	L' '	,0x00E7	,0x0327	,0x0000	), // "̧" COMBINING CEDILLA
/*<!dead_cedilla>*/	DEADTRANS(	0x200B	,0x00E7	,0x0327	,0x0000	), // "̧" COMBINING CEDILLA
/*<!dead_circumflex>*/	DEADTRANS(	L'\''	,0x00EA	,0x2018	,0x0000	), // "‘" LEFT SINGLE QUOTATION MARK, single turned comma quotation mark
/*<!dead_circumflex>*/	DEADTRANS(	0x2019	,0x00EA	,0x2018	,0x0000	), // "‘" LEFT SINGLE QUOTATION MARK, single turned comma quotation mark
/*<!dead_circumflex>*/	DEADTRANS(	L'~'	,0x00EA	,0x2A6F	,0x0000	), // "⩯" ALMOST EQUAL TO WITH CIRCUMFLEX ACCENT
/*<!dead_circumflex>*/	DEADTRANS(	L'*'	,0x00EA	,0x2042	,0x0000	), // "⁂" ASTERISM
/*<!dead_circumflex>*/	DEADTRANS(	L'|'	,0x00EA	,0x2E36	,0x0000	), // "⸶" DAGGER WITH LEFT GUARD
/*<!dead_circumflex>*/	DEADTRANS(	L','	,0x00EA	,0x02BB	,0x0000	), // "ʻ" MODIFIER LETTER TURNED COMMA
/*<!dead_circumflex>*/	DEADTRANS(	L'$'	,0x00EA	,0x017F	,0x0000	), // "ſ" LATIN SMALL LETTER LONG S
/*<!dead_circumflex>*/	DEADTRANS(	L'='	,0x00EA	,0x1DCD	,0x0000	), // "᷍" COMBINING DOUBLE CIRCUMFLEX ABOVE
/*<!dead_circumflex>*/	DEADTRANS(	L'+'	,0x00EA	,0x2A23	,0x0000	), // "⨣" PLUS SIGN WITH CIRCUMFLEX ACCENT ABOVE
/*<!dead_circumflex>*/	DEADTRANS(	L'"'	,0x00EA	,0x201C	,0x0000	), // "“" LEFT DOUBLE QUOTATION MARK, double turned comma quotation mark
/*<!dead_circumflex>*/	DEADTRANS(	0x20AC	,0x00EA	,0x201C	,0x0000	), // "“" LEFT DOUBLE QUOTATION MARK, double turned comma quotation mark
/*<!dead_circumflex>*/	DEADTRANS(	L'0'	,0x00EA	,0x2070	,0x0000	), // "⁰" SUPERSCRIPT ZERO
/*<!dead_circumflex>*/	DEADTRANS(	L'1'	,0x00EA	,0x00B9	,0x0000	), // "¹" SUPERSCRIPT ONE
/*<!dead_circumflex>*/	DEADTRANS(	L'2'	,0x00EA	,0x00B2	,0x0000	), // "²" SUPERSCRIPT TWO
/*<!dead_circumflex>*/	DEADTRANS(	L'3'	,0x00EA	,0x00B3	,0x0000	), // "³" SUPERSCRIPT THREE
/*<!dead_circumflex>*/	DEADTRANS(	L'4'	,0x00EA	,0x2074	,0x0000	), // "⁴" SUPERSCRIPT FOUR
/*<!dead_circumflex>*/	DEADTRANS(	L'5'	,0x00EA	,0x2075	,0x0000	), // "⁵" SUPERSCRIPT FIVE
/*<!dead_circumflex>*/	DEADTRANS(	L'6'	,0x00EA	,0x2076	,0x0000	), // "⁶" SUPERSCRIPT SIX
/*<!dead_circumflex>*/	DEADTRANS(	L'7'	,0x00EA	,0x2077	,0x0000	), // "⁷" SUPERSCRIPT SEVEN
/*<!dead_circumflex>*/	DEADTRANS(	L'8'	,0x00EA	,0x2078	,0x0000	), // "⁸" SUPERSCRIPT EIGHT
/*<!dead_circumflex>*/	DEADTRANS(	L'9'	,0x00EA	,0x2079	,0x0000	), // "⁹" SUPERSCRIPT NINE
/*<!dead_circumflex>*/	DEADTRANS(	L'A'	,0x00EA	,0x00C2	,0x0000	), // "Â" LATIN CAPITAL LETTER A WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'a'	,0x00EA	,0x00E2	,0x0000	), // "â" LATIN SMALL LETTER A WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	0x00C0	,0x00EA	,0x1EA6	,0x0000	), // "Ầ" LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND GRAVE
/*<!dead_circumflex>*/	DEADTRANS(	0x00E0	,0x00EA	,0x1EA7	,0x0000	), // "ầ" LATIN SMALL LETTER A WITH CIRCUMFLEX AND GRAVE
/*<!dead_circumflex>*/	DEADTRANS(	L'B'	,0x00EA	,0x016C	,0x0000	), // "Ŭ" LATIN CAPITAL LETTER U WITH BREVE: Esperanto
/*<!dead_circumflex>*/	DEADTRANS(	L'b'	,0x00EA	,0x016D	,0x0000	), // "ŭ" LATIN SMALL LETTER U WITH BREVE: Esperanto
/*<!dead_circumflex>*/	DEADTRANS(	L'C'	,0x00EA	,0x0108	,0x0000	), // "Ĉ" LATIN CAPITAL LETTER C WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'c'	,0x00EA	,0x0109	,0x0000	), // "ĉ" LATIN SMALL LETTER C WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	0x00C7	,0x00EA	,0x00D1	,0x0000	), // "Ñ" LATIN CAPITAL LETTER N WITH TILDE
/*<!dead_circumflex>*/	DEADTRANS(	0x00E7	,0x00EA	,0x00F1	,0x0000	), // "ñ" LATIN SMALL LETTER N WITH TILDE
/*<!dead_circumflex>*/	DEADTRANS(	L'D'	,0x00EA	,0x1AB0	,0x0000	), // "᪰" COMBINING DOUBLED CIRCUMFLEX ACCENT
/*<!dead_circumflex>*/	DEADTRANS(	L'd'	,0x00EA	,0x1AB0	,0x0000	), // "᪰" COMBINING DOUBLED CIRCUMFLEX ACCENT
/*<!dead_circumflex>*/	DEADTRANS(	L'E'	,0x00EA	,0x00CA	,0x0000	), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'e'	,0x00EA	,0x00EA	,0x0000	), // "ê" LATIN SMALL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	0x00C9	,0x00EA	,0x1EBE	,0x0000	), // "Ế" LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND ACUTE
/*<!dead_circumflex>*/	DEADTRANS(	0x00E9	,0x00EA	,0x1EBF	,0x0000	), // "ế" LATIN SMALL LETTER E WITH CIRCUMFLEX AND ACUTE
/*<!dead_circumflex>*/	DEADTRANS(	0x00C8	,0x00EA	,0x1EC0	,0x0000	), // "Ề" LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND GRAVE
/*<!dead_circumflex>*/	DEADTRANS(	0x00E8	,0x00EA	,0x1EC1	,0x0000	), // "ề" LATIN SMALL LETTER E WITH CIRCUMFLEX AND GRAVE
/*<!dead_circumflex>*/	DEADTRANS(	0x2014	,0x00EA	,0x1DCD	,0x0000	), // "᷍" COMBINING DOUBLE CIRCUMFLEX ABOVE
/*<!dead_circumflex>*/	DEADTRANS(	L'F'	,0x00EA	,0x0053	,0x0000	), // "S" LATIN CAPITAL LETTER S
/*<!dead_circumflex>*/	DEADTRANS(	L'f'	,0x00EA	,0x017F	,0x0000	), // "ſ" LATIN SMALL LETTER LONG S
/*<!dead_circumflex>*/	DEADTRANS(	L'G'	,0x00EA	,0x011C	,0x0000	), // "Ĝ" LATIN CAPITAL LETTER G WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'g'	,0x00EA	,0x011D	,0x0000	), // "ĝ" LATIN SMALL LETTER G WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'H'	,0x00EA	,0x0124	,0x0000	), // "Ĥ" LATIN CAPITAL LETTER H WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'h'	,0x00EA	,0x0125	,0x0000	), // "ĥ" LATIN SMALL LETTER H WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'I'	,0x00EA	,0x00CE	,0x0000	), // "Î" LATIN CAPITAL LETTER I WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'i'	,0x00EA	,0x00EE	,0x0000	), // "î" LATIN SMALL LETTER I WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'J'	,0x00EA	,0x0134	,0x0000	), // "Ĵ" LATIN CAPITAL LETTER J WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'j'	,0x00EA	,0x0135	,0x0000	), // "ĵ" LATIN SMALL LETTER J WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'O'	,0x00EA	,0x00D4	,0x0000	), // "Ô" LATIN CAPITAL LETTER O WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'o'	,0x00EA	,0x00F4	,0x0000	), // "ô" LATIN SMALL LETTER O WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'S'	,0x00EA	,0x015C	,0x0000	), // "Ŝ" LATIN CAPITAL LETTER S WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L's'	,0x00EA	,0x015D	,0x0000	), // "ŝ" LATIN SMALL LETTER S WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	0x00B3	,0x00EA	,0x2033	,0x0000	), // "″" DOUBLE PRIME
/*<!dead_circumflex>*/	DEADTRANS(	0x00B2	,0x00EA	,0x2032	,0x0000	), // "′" PRIME
/*<!dead_circumflex>*/	DEADTRANS(	L'U'	,0x00EA	,0x00DB	,0x0000	), // "Û" LATIN CAPITAL LETTER U WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'u'	,0x00EA	,0x00FB	,0x0000	), // "û" LATIN SMALL LETTER U WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	0x00F9	,0x00EA	,0x016C	,0x0000	), // "Ŭ" LATIN CAPITAL LETTER U WITH BREVE
/*<!dead_circumflex>*/	DEADTRANS(	0x00F9	,0x00EA	,0x016D	,0x0000	), // "ŭ" LATIN SMALL LETTER U WITH BREVE
/*<!dead_circumflex>*/	DEADTRANS(	L'W'	,0x00EA	,0x0174	,0x0000	), // "Ŵ" LATIN CAPITAL LETTER W WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'w'	,0x00EA	,0x0175	,0x0000	), // "ŵ" LATIN SMALL LETTER W WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'Y'	,0x00EA	,0x0176	,0x0000	), // "Ŷ" LATIN CAPITAL LETTER Y WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'y'	,0x00EA	,0x0177	,0x0000	), // "ŷ" LATIN SMALL LETTER Y WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'Z'	,0x00EA	,0x1E90	,0x0000	), // "Ẑ" LATIN CAPITAL LETTER Z WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	L'z'	,0x00EA	,0x1E91	,0x0000	), // "ẑ" LATIN SMALL LETTER Z WITH CIRCUMFLEX
/*<!dead_circumflex>*/	DEADTRANS(	0x00A0	,0x00EA	,0x005E	,0x0000	), // "^" CIRCUMFLEX ACCENT
/*<!dead_circumflex>*/	DEADTRANS(	0x202F	,0x00EA	,0x02C6	,0x0000	), // "ˆ" MODIFIER LETTER CIRCUMFLEX ACCENT
/*<!dead_circumflex>*/	DEADTRANS(	L' '	,0x00EA	,0x0302	,0x0000	), // "̂" COMBINING CIRCUMFLEX ACCENT
/*<!dead_circumflex>*/	DEADTRANS(	0x200B	,0x00EA	,0x0302	,0x0000	), // "̂" COMBINING CIRCUMFLEX ACCENT
/*<!dead_currency>*/	DEADTRANS(	L'0'	,0x00A4	,0x2231	,0x0000	), // "∱" CLOCKWISE INTEGRAL
/*<!dead_currency>*/	DEADTRANS(	L'1'	,0x00A4	,0x222B	,0x0000	), // "∫" INTEGRAL
/*<!dead_currency>*/	DEADTRANS(	L'2'	,0x00A4	,0x222C	,0x0000	), // "∬" DOUBLE INTEGRAL
/*<!dead_currency>*/	DEADTRANS(	L'3'	,0x00A4	,0x222D	,0x0000	), // "∭" TRIPLE INTEGRAL
/*<!dead_currency>*/	DEADTRANS(	L'4'	,0x00A4	,0x2A0C	,0x0000	), // "⨌" QUADRUPLE INTEGRAL OPERATOR
/*<!dead_currency>*/	DEADTRANS(	L'5'	,0x00A4	,0x222E	,0x0000	), // "∮" CONTOUR INTEGRAL
/*<!dead_currency>*/	DEADTRANS(	L'6'	,0x00A4	,0x222F	,0x0000	), // "∯" SURFACE INTEGRAL
/*<!dead_currency>*/	DEADTRANS(	L'7'	,0x00A4	,0x2230	,0x0000	), // "∰" VOLUME INTEGRAL
/*<!dead_currency>*/	DEADTRANS(	L'8'	,0x00A4	,0x2232	,0x0000	), // "∲" CLOCKWISE CONTOUR INTEGRAL
/*<!dead_currency>*/	DEADTRANS(	L'9'	,0x00A4	,0x2233	,0x0000	), // "∳" ANTICLOCKWISE CONTOUR INTEGRAL
/*<!dead_currency>*/	DEADTRANS(	L'a'	,0x00A4	,0x060B	,0x0000	), // "؋" AFGHANI SIGN
/*<!dead_currency>*/	DEADTRANS(	L'A'	,0x00A4	,0x20B3	,0x0000	), // "₳" AUSTRAL SIGN
/*<!dead_currency>*/	DEADTRANS(	L'b'	,0x00A4	,0x0E3F	,0x0000	), // "฿" THAI CURRENCY SYMBOL BAHT
/*<!dead_currency>*/	DEADTRANS(	L'B'	,0x00A4	,0x20B1	,0x0000	), // "₱" PESO SIGN
/*<!dead_currency>*/	DEADTRANS(	L'c'	,0x00A4	,0x00A2	,0x0000	), // "¢" CENT SIGN
/*<!dead_currency>*/	DEADTRANS(	L'C'	,0x00A4	,0x20A1	,0x0000	), // "₡" COLON SIGN
/*<!dead_currency>*/	DEADTRANS(	0x00C7	,0x00A4	,0x20B5	,0x0000	), // "₵" CEDI SIGN
/*<!dead_currency>*/	DEADTRANS(	0x00E7	,0x00A4	,0x20B5	,0x0000	), // "₵" CEDI SIGN
/*<!dead_currency>*/	DEADTRANS(	L'd'	,0x00A4	,0x20AB	,0x0000	), // "₫" DONG SIGN
/*<!dead_currency>*/	DEADTRANS(	L'D'	,0x00A4	,0x20AF	,0x0000	), // "₯" DRACHMA SIGN
/*<!dead_currency>*/	DEADTRANS(	L'E'	,0x00A4	,0x20A0	,0x0000	), // "₠" EURO-CURRENCY SIGN
/*<!dead_currency>*/	DEADTRANS(	L'e'	,0x00A4	,0x20AC	,0x0000	), // "€" EURO SIGN
/*<!dead_currency>*/	DEADTRANS(	L'f'	,0x00A4	,0x0192	,0x0000	), // "ƒ" LATIN SMALL LETTER F WITH HOOK
/*<!dead_currency>*/	DEADTRANS(	L'F'	,0x00A4	,0x20A3	,0x0000	), // "₣" FRENCH FRANC SIGN
/*<!dead_currency>*/	DEADTRANS(	L'G'	,0x00A4	,0x20B2	,0x0000	), // "₲" GUARANI SIGN
/*<!dead_currency>*/	DEADTRANS(	L'g'	,0x00A4	,0x20B2	,0x0000	), // "₲" GUARANI SIGN
/*<!dead_currency>*/	DEADTRANS(	L'H'	,0x00A4	,0x20B4	,0x0000	), // "₴" HRYVNIA SIGN
/*<!dead_currency>*/	DEADTRANS(	L'h'	,0x00A4	,0x20B4	,0x0000	), // "₴" HRYVNIA SIGN
/*<!dead_currency>*/	DEADTRANS(	L'I'	,0x00A4	,0x17DB	,0x0000	), // "៛" KHMER CURRENCY SYMBOL RIEL
/*<!dead_currency>*/	DEADTRANS(	L'i'	,0x00A4	,0xFDFC	,0x0000	), // "﷼" RIAL SIGN
/*<!dead_currency>*/	DEADTRANS(	L'J'	,0x00A4	,0x09F2	,0x0000	), // "৲" BENGALI RUPEE MARK
/*<!dead_currency>*/	DEADTRANS(	L'j'	,0x00A4	,0x20B9	,0x0000	), // "₹" INDIAN RUPEE SIGN
/*<!dead_currency>*/	DEADTRANS(	L'K'	,0x00A4	,0x20AD	,0x0000	), // "₭" KIP SIGN
/*<!dead_currency>*/	DEADTRANS(	L'k'	,0x00A4	,0x20AD	,0x0000	), // "₭" KIP SIGN
/*<!dead_currency>*/	DEADTRANS(	L'l'	,0x00A4	,0x00A3	,0x0000	), // "£" POUND SIGN
/*<!dead_currency>*/	DEADTRANS(	L'L'	,0x00A4	,0x20A4	,0x0000	), // "₤" LIRA SIGN
/*<!dead_currency>*/	DEADTRANS(	L'm'	,0x00A4	,0x20A5	,0x0000	), // "₥" MILL SIGN
/*<!dead_currency>*/	DEADTRANS(	L'M'	,0x00A4	,0x2133	,0x0000	), // "ℳ" SCRIPT CAPITAL M
/*<!dead_currency>*/	DEADTRANS(	L'N'	,0x00A4	,0x20A6	,0x0000	), // "₦" NAIRA SIGN
/*<!dead_currency>*/	DEADTRANS(	L'n'	,0x00A4	,0x20A6	,0x0000	), // "₦" NAIRA SIGN
/*<!dead_currency>*/	DEADTRANS(	L'O'	,0x00A4	,0x0AF1	,0x0000	), // "૱" GUJARATI RUPEE SIGN
/*<!dead_currency>*/	DEADTRANS(	L'o'	,0x00A4	,0x0BF9	,0x0000	), // "௹" TAMIL RUPEE SIGN
/*<!dead_currency>*/	DEADTRANS(	L'P'	,0x00A4	,0x20A7	,0x0000	), // "₧" PESETA SIGN
/*<!dead_currency>*/	DEADTRANS(	L'p'	,0x00A4	,0x20B0	,0x0000	), // "₰" GERMAN PENNY SIGN
/*<!dead_currency>*/	DEADTRANS(	L'q'	,0x00A4	,0x058F	,0x0000	), // "֏" ARMENIAN DRAM SIGN
/*<!dead_currency>*/	DEADTRANS(	L'Q'	,0x00A4	,0x20B9	,0x0000	), // "₹" INDIAN RUPEE SIGN
/*<!dead_currency>*/	DEADTRANS(	L'r'	,0x00A4	,0x20A2	,0x0000	), // "₢" CRUZEIRO SIGN
/*<!dead_currency>*/	DEADTRANS(	L'R'	,0x00A4	,0x20A8	,0x0000	), // "₨" RUPEE SIGN
/*<!dead_currency>*/	DEADTRANS(	L's'	,0x00A4	,0x20AA	,0x0000	), // "₪" NEW SHEQEL SIGN
/*<!dead_currency>*/	DEADTRANS(	L'S'	,0x00A4	,0x20C0	,0x0000	), // "⃀" SOM SIGN
/*<!dead_currency>*/	DEADTRANS(	L't'	,0x00A4	,0x09F3	,0x0000	), // "৳" BENGALI RUPEE SIGN
/*<!dead_currency>*/	DEADTRANS(	L'T'	,0x00A4	,0x20AE	,0x0000	), // "₮" TUGRIK SIGN
/*<!dead_currency>*/	DEADTRANS(	L'u'	,0x00A4	,0x5143	,0x0000	), // "元" YUAN / WEN
/*<!dead_currency>*/	DEADTRANS(	L'U'	,0x00A4	,0x5713	,0x0000	), // "圓" YUAN / WEN
/*<!dead_currency>*/	DEADTRANS(	L'V'	,0x00A4	,0x20BA	,0x0000	), // "₺" TURKISH LIRA SIGN
/*<!dead_currency>*/	DEADTRANS(	L'v'	,0x00A4	,0x20BE	,0x0000	), // "₾" LARI SIGN
/*<!dead_currency>*/	DEADTRANS(	L'W'	,0x00A4	,0x20A9	,0x0000	), // "₩" WON SIGN
/*<!dead_currency>*/	DEADTRANS(	L'w'	,0x00A4	,0x20A9	,0x0000	), // "₩" WON SIGN
/*<!dead_currency>*/	DEADTRANS(	L'X'	,0x00A4	,0x20B8	,0x0000	), // "₸" TENGE SIGN
/*<!dead_currency>*/	DEADTRANS(	L'x'	,0x00A4	,0x20BC	,0x0000	), // "₼" MANAT SIGN
/*<!dead_currency>*/	DEADTRANS(	L'y'	,0x00A4	,0x00A5	,0x0000	), // "¥" YEN SIGN
/*<!dead_currency>*/	DEADTRANS(	L'Y'	,0x00A4	,0x5186	,0x0000	), // "円" YEN
/*<!dead_currency>*/	DEADTRANS(	L'z'	,0x00A4	,0x20B7	,0x0000	), // "₷" SPESMILO SIGN
/*<!dead_currency>*/	DEADTRANS(	L'Z'	,0x00A4	,0x20BD	,0x0000	), // "₽" RUBLE SIGN
/*<!dead_currency>*/	DEADTRANS(	0x00A0	,0x00A4	,0x00A4	,0x0000	), // "¤" CURRENCY SIGN
/*<!dead_currency>*/	DEADTRANS(	0x202F	,0x00A4	,0x00A4	,0x0000	), // "¤" CURRENCY SIGN
/*<!dead_currency>*/	DEADTRANS(	L' '	,0x00A4	,0x00A4	,0x0000	), // "¤" CURRENCY SIGN
/*<!dead_currency>*/	DEADTRANS(	0x200B	,0x00A4	,0x00A4	,0x0000	), // "¤" CURRENCY SIGN
/*<!dead_diaeresis>*/	DEADTRANS(	L'\''	,0x00EB	,0x201A	,0x0000	), // "‚" SINGLE LOW-9 QUOTATION MARK, low single comma quotation mark
/*<!dead_diaeresis>*/	DEADTRANS(	0x2019	,0x00EB	,0x201A	,0x0000	), // "‚" SINGLE LOW-9 QUOTATION MARK, low single comma quotation mark
/*<!dead_diaeresis>*/	DEADTRANS(	L'*'	,0x00EB	,0x2051	,0x0000	), // "⁑" TWO ASTERISKS ALIGNED VERTICALLY
/*<!dead_diaeresis>*/	DEADTRANS(	L'\\'	,0x00EB	,0x00A6	,0x0000	), // "¦" BROKEN BAR repurposed as multikey symbol
/*<!dead_diaeresis>*/	DEADTRANS(	L'"'	,0x00EB	,0x201E	,0x0000	), // "„" DOUBLE LOW-9 QUOTATION MARK, low double comma quotation mark
/*<!dead_diaeresis>*/	DEADTRANS(	0x20AC	,0x00EB	,0x201E	,0x0000	), // "„" DOUBLE LOW-9 QUOTATION MARK, low double comma quotation mark
/*<!dead_diaeresis>*/	DEADTRANS(	L'/'	,0x00EB	,0x2016	,0x0000	), // "‖" DOUBLE VERTICAL LINE
/*<!dead_diaeresis>*/	DEADTRANS(	L'0'	,0x00EB	,0x2070	,0x0000	), // "⁰" SUPERSCRIPT ZERO
/*<!dead_diaeresis>*/	DEADTRANS(	L'1'	,0x00EB	,0x00B9	,0x0000	), // "¹" SUPERSCRIPT ONE
/*<!dead_diaeresis>*/	DEADTRANS(	L'2'	,0x00EB	,0x00B2	,0x0000	), // "²" SUPERSCRIPT TWO
/*<!dead_diaeresis>*/	DEADTRANS(	L'3'	,0x00EB	,0x00B3	,0x0000	), // "³" SUPERSCRIPT THREE
/*<!dead_diaeresis>*/	DEADTRANS(	L'4'	,0x00EB	,0x2074	,0x0000	), // "⁴" SUPERSCRIPT FOUR
/*<!dead_diaeresis>*/	DEADTRANS(	L'5'	,0x00EB	,0x2075	,0x0000	), // "⁵" SUPERSCRIPT FIVE
/*<!dead_diaeresis>*/	DEADTRANS(	L'6'	,0x00EB	,0x2076	,0x0000	), // "⁶" SUPERSCRIPT SIX
/*<!dead_diaeresis>*/	DEADTRANS(	L'7'	,0x00EB	,0x2077	,0x0000	), // "⁷" SUPERSCRIPT SEVEN
/*<!dead_diaeresis>*/	DEADTRANS(	L'8'	,0x00EB	,0x2078	,0x0000	), // "⁸" SUPERSCRIPT EIGHT
/*<!dead_diaeresis>*/	DEADTRANS(	L'9'	,0x00EB	,0x2079	,0x0000	), // "⁹" SUPERSCRIPT NINE
/*<!dead_diaeresis>*/	DEADTRANS(	L'A'	,0x00EB	,0x00C4	,0x0000	), // "Ä" LATIN CAPITAL LETTER A WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L'a'	,0x00EB	,0x00E4	,0x0000	), // "ä" LATIN SMALL LETTER A WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	0x00C7	,0x00EB	,0x00D8	,0x0000	), // "Ø" LATIN CAPITAL LETTER O WITH STROKE
/*<!dead_diaeresis>*/	DEADTRANS(	0x00E7	,0x00EB	,0x00F8	,0x0000	), // "ø" LATIN SMALL LETTER O WITH STROKE
/*<!dead_diaeresis>*/	DEADTRANS(	L'E'	,0x00EB	,0x00CB	,0x0000	), // "Ë" LATIN CAPITAL LETTER E WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L'e'	,0x00EB	,0x00EB	,0x0000	), // "ë" LATIN SMALL LETTER E WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L'H'	,0x00EB	,0x1E26	,0x0000	), // "Ḧ" LATIN CAPITAL LETTER H WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L'h'	,0x00EB	,0x1E27	,0x0000	), // "ḧ" LATIN SMALL LETTER H WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L'I'	,0x00EB	,0x00CF	,0x0000	), // "Ï" LATIN CAPITAL LETTER I WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L'i'	,0x00EB	,0x00EF	,0x0000	), // "ï" LATIN SMALL LETTER I WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L'O'	,0x00EB	,0x00D6	,0x0000	), // "Ö" LATIN CAPITAL LETTER O WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L'o'	,0x00EB	,0x00F6	,0x0000	), // "ö" LATIN SMALL LETTER O WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L't'	,0x00EB	,0x1E97	,0x0000	), // "ẗ" LATIN SMALL LETTER T WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L'U'	,0x00EB	,0x00DC	,0x0000	), // "Ü" LATIN CAPITAL LETTER U WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L'u'	,0x00EB	,0x00FC	,0x0000	), // "ü" LATIN SMALL LETTER U WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	0x00F9	,0x00EB	,0x01DB	,0x0000	), // "Ǜ" LATIN CAPITAL LETTER U WITH DIAERESIS AND GRAVE
/*<!dead_diaeresis>*/	DEADTRANS(	0x00F9	,0x00EB	,0x01DC	,0x0000	), // "ǜ" LATIN SMALL LETTER U WITH DIAERESIS AND GRAVE
/*<!dead_diaeresis>*/	DEADTRANS(	L'W'	,0x00EB	,0x1E84	,0x0000	), // "Ẅ" LATIN CAPITAL LETTER W WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L'w'	,0x00EB	,0x1E85	,0x0000	), // "ẅ" LATIN SMALL LETTER W WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L'X'	,0x00EB	,0x1E8C	,0x0000	), // "Ẍ" LATIN CAPITAL LETTER X WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L'x'	,0x00EB	,0x1E8D	,0x0000	), // "ẍ" LATIN SMALL LETTER X WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L'y'	,0x00EB	,0x00FF	,0x0000	), // "ÿ" LATIN SMALL LETTER Y WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L'Y'	,0x00EB	,0x0178	,0x0000	), // "Ÿ" LATIN CAPITAL LETTER Y WITH DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	0x00A0	,0x00EB	,0x00A8	,0x0000	), // "¨" DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	0x202F	,0x00EB	,0x00A8	,0x0000	), // "¨" DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	L' '	,0x00EB	,0x0308	,0x0000	), // "̈" COMBINING DIAERESIS
/*<!dead_diaeresis>*/	DEADTRANS(	0x200B	,0x00EB	,0x0308	,0x0000	), // "̈" COMBINING DIAERESIS
/*<!dead_doubleacute>*/	DEADTRANS(	L'\''	,0x0151	,0x030E	,0x0000	), // "̎" COMBINING DOUBLE VERTICAL LINE ABOVE: Marshallese
/*<!dead_doubleacute>*/	DEADTRANS(	0x2019	,0x0151	,0x030E	,0x0000	), // "̎" COMBINING DOUBLE VERTICAL LINE ABOVE: Marshallese
/*<!dead_doubleacute>*/	DEADTRANS(	L'='	,0x0151	,0x02F6	,0x0000	), // "˶" MODIFIER LETTER MIDDLE DOUBLE ACUTE ACCENT
/*<!dead_doubleacute>*/	DEADTRANS(	L'0'	,0x0151	,0x24FE	,0x0000	), // "⓾" DOUBLE CIRCLED NUMBER TEN
/*<!dead_doubleacute>*/	DEADTRANS(	L'1'	,0x0151	,0x24F5	,0x0000	), // "⓵" DOUBLE CIRCLED DIGIT ONE
/*<!dead_doubleacute>*/	DEADTRANS(	L'2'	,0x0151	,0x24F6	,0x0000	), // "⓶" DOUBLE CIRCLED DIGIT TWO
/*<!dead_doubleacute>*/	DEADTRANS(	L'3'	,0x0151	,0x24F7	,0x0000	), // "⓷" DOUBLE CIRCLED DIGIT THREE
/*<!dead_doubleacute>*/	DEADTRANS(	L'4'	,0x0151	,0x24F8	,0x0000	), // "⓸" DOUBLE CIRCLED DIGIT FOUR
/*<!dead_doubleacute>*/	DEADTRANS(	L'5'	,0x0151	,0x24F9	,0x0000	), // "⓹" DOUBLE CIRCLED DIGIT FIVE
/*<!dead_doubleacute>*/	DEADTRANS(	L'6'	,0x0151	,0x24FA	,0x0000	), // "⓺" DOUBLE CIRCLED DIGIT SIX
/*<!dead_doubleacute>*/	DEADTRANS(	L'7'	,0x0151	,0x24FB	,0x0000	), // "⓻" DOUBLE CIRCLED DIGIT SEVEN
/*<!dead_doubleacute>*/	DEADTRANS(	L'8'	,0x0151	,0x24FC	,0x0000	), // "⓼" DOUBLE CIRCLED DIGIT EIGHT
/*<!dead_doubleacute>*/	DEADTRANS(	L'9'	,0x0151	,0x24FD	,0x0000	), // "⓽" DOUBLE CIRCLED DIGIT NINE
/*<!dead_doubleacute>*/	DEADTRANS(	L'O'	,0x0151	,0x0150	,0x0000	), // "Ő" LATIN CAPITAL LETTER O WITH DOUBLE ACUTE
/*<!dead_doubleacute>*/	DEADTRANS(	L'o'	,0x0151	,0x0151	,0x0000	), // "ő" LATIN SMALL LETTER O WITH DOUBLE ACUTE
/*<!dead_doubleacute>*/	DEADTRANS(	L'U'	,0x0151	,0x0170	,0x0000	), // "Ű" LATIN CAPITAL LETTER U WITH DOUBLE ACUTE
/*<!dead_doubleacute>*/	DEADTRANS(	L'u'	,0x0151	,0x0171	,0x0000	), // "ű" LATIN SMALL LETTER U WITH DOUBLE ACUTE
/*<!dead_doubleacute>*/	DEADTRANS(	0x00A0	,0x0151	,0x02DD	,0x0000	), // "˝" DOUBLE ACUTE ACCENT
/*<!dead_doubleacute>*/	DEADTRANS(	0x202F	,0x0151	,0x02DD	,0x0000	), // "˝" DOUBLE ACUTE ACCENT
/*<!dead_doubleacute>*/	DEADTRANS(	L' '	,0x0151	,0x030B	,0x0000	), // "̋" COMBINING DOUBLE ACUTE ACCENT
/*<!dead_doubleacute>*/	DEADTRANS(	0x200B	,0x0151	,0x030B	,0x0000	), // "̋" COMBINING DOUBLE ACUTE ACCENT
/*<!dead_flag>*/	DEADTRANS(	0x021F	,0x2690	,0x200C	,0x0000	), // "‌" ZERO WIDTH NON-JOINER, cursive non-joiner
/*<!dead_flag>*/	DEADTRANS(	0x00EA	,0x2690	,0x2060	,0x0000	), // "⁠" WORD JOINER
/*<!dead_flag>*/	DEADTRANS(	L'-'	,0x2690	,0x2E40	,0x0000	), // "⹀" DOUBLE HYPHEN
/*<!dead_flag>*/	DEADTRANS(	L'0'	,0x2690	,0x21D5	,0x0000	), // "⇕" UP DOWN DOUBLE ARROW
/*<!dead_flag>*/	DEADTRANS(	L'1'	,0x2690	,0x21D9	,0x0000	), // "⇙" SOUTH WEST DOUBLE ARROW
/*<!dead_flag>*/	DEADTRANS(	L'2'	,0x2690	,0x21D3	,0x0000	), // "⇓" DOWNWARDS DOUBLE ARROW
/*<!dead_flag>*/	DEADTRANS(	L'3'	,0x2690	,0x21D8	,0x0000	), // "⇘" SOUTH EAST DOUBLE ARROW
/*<!dead_flag>*/	DEADTRANS(	L'4'	,0x2690	,0x21D0	,0x0000	), // "⇐" LEFTWARDS DOUBLE ARROW
/*<!dead_flag>*/	DEADTRANS(	L'5'	,0x2690	,0x21D4	,0x0000	), // "⇔" LEFT RIGHT DOUBLE ARROW
/*<!dead_flag>*/	DEADTRANS(	L'6'	,0x2690	,0x21D2	,0x0000	), // "⇒" RIGHTWARDS DOUBLE ARROW
/*<!dead_flag>*/	DEADTRANS(	L'7'	,0x2690	,0x21D6	,0x0000	), // "⇖" NORTH WEST DOUBLE ARROW
/*<!dead_flag>*/	DEADTRANS(	L'8'	,0x2690	,0x21D1	,0x0000	), // "⇑" UPWARDS DOUBLE ARROW
/*<!dead_flag>*/	DEADTRANS(	L'9'	,0x2690	,0x21D7	,0x0000	), // "⇗" NORTH EAST DOUBLE ARROW
/*<!dead_flag>*/	DEADTRANS(	0x00A0	,0x2690	,0x02ED	,0x0000	), // "˭" MODIFIER LETTER UNASPIRATED
/*<!dead_flag>*/	DEADTRANS(	0x202F	,0x2690	,0x02ED	,0x0000	), // "˭" MODIFIER LETTER UNASPIRATED
/*<!dead_flag>*/	DEADTRANS(	L' '	,0x2690	,0x0347	,0x0000	), // "͇" COMBINING EQUALS SIGN BELOW
/*<!dead_grave>*/	DEADTRANS(	L'&'	,0x00F2	,0x0316	,0x0000	), // "̖" COMBINING GRAVE ACCENT BELOW
/*<!dead_grave>*/	DEADTRANS(	L'\''	,0x00F2	,0x201B	,0x0000	), // "‛" SINGLE HIGH-REVERSED-9 QUOTATION MARK, single reversed comma quotation mark
/*<!dead_grave>*/	DEADTRANS(	0x2019	,0x00F2	,0x201B	,0x0000	), // "‛" SINGLE HIGH-REVERSED-9 QUOTATION MARK, single reversed comma quotation mark
/*<!dead_grave>*/	DEADTRANS(	L'*'	,0x00F2	,0x02DF	,0x0000	), // "˟" MODIFIER LETTER CROSS ACCENT, Swedish grave accent
/*<!dead_grave>*/	DEADTRANS(	L'='	,0x00F2	,0x02F4	,0x0000	), // "˴" MODIFIER LETTER MIDDLE GRAVE ACCENT
/*<!dead_grave>*/	DEADTRANS(	L'"'	,0x00F2	,0x201F	,0x0000	), // "‟" DOUBLE HIGH-REVERSED-9 QUOTATION MARK, double reversed comma quotation mark
/*<!dead_grave>*/	DEADTRANS(	0x20AC	,0x00F2	,0x201F	,0x0000	), // "‟" DOUBLE HIGH-REVERSED-9 QUOTATION MARK, double reversed comma quotation mark
/*<!dead_grave>*/	DEADTRANS(	L'_'	,0x00F2	,0x02CE	,0x0000	), // "ˎ" MODIFIER LETTER LOW GRAVE ACCENT
/*<!dead_grave>*/	DEADTRANS(	L'1'	,0x00F2	,0x2035	,0x0000	), // "‵" REVERSED PRIME
/*<!dead_grave>*/	DEADTRANS(	L'2'	,0x00F2	,0x2036	,0x0000	), // "‶" REVERSED DOUBLE PRIME
/*<!dead_grave>*/	DEADTRANS(	L'3'	,0x00F2	,0x2037	,0x0000	), // "‷" REVERSED TRIPLE PRIME
/*<!dead_grave>*/	DEADTRANS(	L'A'	,0x00F2	,0x00C0	,0x0000	), // "À" LATIN CAPITAL LETTER A WITH GRAVE
/*<!dead_grave>*/	DEADTRANS(	L'a'	,0x00F2	,0x00E0	,0x0000	), // "à" LATIN SMALL LETTER A WITH GRAVE
/*<!dead_grave>*/	DEADTRANS(	L'E'	,0x00F2	,0x00C8	,0x0000	), // "È" LATIN CAPITAL LETTER E WITH GRAVE
/*<!dead_grave>*/	DEADTRANS(	L'e'	,0x00F2	,0x00E8	,0x0000	), // "è" LATIN SMALL LETTER E WITH GRAVE
/*<!dead_grave>*/	DEADTRANS(	L'I'	,0x00F2	,0x00CC	,0x0000	), // "Ì" LATIN CAPITAL LETTER I WITH GRAVE
/*<!dead_grave>*/	DEADTRANS(	L'i'	,0x00F2	,0x00EC	,0x0000	), // "ì" LATIN SMALL LETTER I WITH GRAVE
/*<!dead_grave>*/	DEADTRANS(	L'N'	,0x00F2	,0x01F8	,0x0000	), // "Ǹ" LATIN CAPITAL LETTER N WITH GRAVE
/*<!dead_grave>*/	DEADTRANS(	L'n'	,0x00F2	,0x01F9	,0x0000	), // "ǹ" LATIN SMALL LETTER N WITH GRAVE
/*<!dead_grave>*/	DEADTRANS(	L'O'	,0x00F2	,0x00D2	,0x0000	), // "Ò" LATIN CAPITAL LETTER O WITH GRAVE
/*<!dead_grave>*/	DEADTRANS(	L'o'	,0x00F2	,0x00F2	,0x0000	), // "ò" LATIN SMALL LETTER O WITH GRAVE
/*<!dead_grave>*/	DEADTRANS(	L'U'	,0x00F2	,0x00D9	,0x0000	), // "Ù" LATIN CAPITAL LETTER U WITH GRAVE
/*<!dead_grave>*/	DEADTRANS(	L'u'	,0x00F2	,0x00F9	,0x0000	), // "ù" LATIN SMALL LETTER U WITH GRAVE
/*<!dead_grave>*/	DEADTRANS(	L'W'	,0x00F2	,0x1E80	,0x0000	), // "Ẁ" LATIN CAPITAL LETTER W WITH GRAVE
/*<!dead_grave>*/	DEADTRANS(	L'w'	,0x00F2	,0x1E81	,0x0000	), // "ẁ" LATIN SMALL LETTER W WITH GRAVE
/*<!dead_grave>*/	DEADTRANS(	L'Y'	,0x00F2	,0x1EF2	,0x0000	), // "Ỳ" LATIN CAPITAL LETTER Y WITH GRAVE
/*<!dead_grave>*/	DEADTRANS(	L'y'	,0x00F2	,0x1EF3	,0x0000	), // "ỳ" LATIN SMALL LETTER Y WITH GRAVE
/*<!dead_grave>*/	DEADTRANS(	0x00A0	,0x00F2	,0x0060	,0x0000	), // "`" GRAVE ACCENT
/*<!dead_grave>*/	DEADTRANS(	0x202F	,0x00F2	,0x02CB	,0x0000	), // "ˋ" MODIFIER LETTER GRAVE ACCENT
/*<!dead_grave>*/	DEADTRANS(	L' '	,0x00F2	,0x0300	,0x0000	), // "̀" COMBINING GRAVE ACCENT
/*<!dead_grave>*/	DEADTRANS(	0x200B	,0x00F2	,0x0300	,0x0000	), // "̀" COMBINING GRAVE ACCENT
/*<!dead_greek>*/	DEADTRANS(	L'*'	,0x03B5	,0x229B	,0x0000	), // "⊛" CIRCLED ASTERISK OPERATOR
/*<!dead_greek>*/	DEADTRANS(	L'|'	,0x03B5	,0x29B6	,0x0000	), // "⦶" CIRCLED VERTICAL BAR
/*<!dead_greek>*/	DEADTRANS(	L':'	,0x03B5	,0x2A38	,0x0000	), // "⨸" CIRCLED DIVISION SIGN
/*<!dead_greek>*/	DEADTRANS(	L'='	,0x03B5	,0x229C	,0x0000	), // "⊜" CIRCLED EQUALS
/*<!dead_greek>*/	DEADTRANS(	L'`'	,0x03B5	,0x24EA	,0x0000	), // "⓪" CIRCLED DIGIT ZERO
/*<!dead_greek>*/	DEADTRANS(	L'>'	,0x03B5	,0x29C1	,0x0000	), // "⧁" CIRCLED GREATER-THAN
/*<!dead_greek>*/	DEADTRANS(	L'<'	,0x03B5	,0x29C0	,0x0000	), // "⧀" CIRCLED LESS-THAN
/*<!dead_greek>*/	DEADTRANS(	L'-'	,0x03B5	,0x2296	,0x0000	), // "⊖" CIRCLED MINUS
/*<!dead_greek>*/	DEADTRANS(	L')'	,0x03B5	,0x229A	,0x0000	), // "⊚" CIRCLED RING OPERATOR
/*<!dead_greek>*/	DEADTRANS(	L'.'	,0x03B5	,0x2299	,0x0000	), // "⊙" CIRCLED DOT OPERATOR
/*<!dead_greek>*/	DEADTRANS(	L'+'	,0x03B5	,0x2295	,0x0000	), // "⊕" CIRCLED PLUS
/*<!dead_greek>*/	DEADTRANS(	L';'	,0x03B5	,0x2297	,0x0000	), // "⊗" CIRCLED TIMES
/*<!dead_greek>*/	DEADTRANS(	L'/'	,0x03B5	,0x2298	,0x0000	), // "⊘" CIRCLED DIVISION SLASH
/*<!dead_greek>*/	DEADTRANS(	L'_'	,0x03B5	,0x229D	,0x0000	), // "⊝" CIRCLED DASH
/*<!dead_greek>*/	DEADTRANS(	L'0'	,0x03B5	,0x2469	,0x0000	), // "⑩" CIRCLED NUMBER TEN
/*<!dead_greek>*/	DEADTRANS(	L'1'	,0x03B5	,0x2460	,0x0000	), // "①" CIRCLED DIGIT ONE
/*<!dead_greek>*/	DEADTRANS(	L'2'	,0x03B5	,0x2461	,0x0000	), // "②" CIRCLED DIGIT TWO
/*<!dead_greek>*/	DEADTRANS(	L'3'	,0x03B5	,0x2462	,0x0000	), // "③" CIRCLED DIGIT THREE
/*<!dead_greek>*/	DEADTRANS(	L'4'	,0x03B5	,0x2463	,0x0000	), // "④" CIRCLED DIGIT FOUR
/*<!dead_greek>*/	DEADTRANS(	L'5'	,0x03B5	,0x2464	,0x0000	), // "⑤" CIRCLED DIGIT FIVE
/*<!dead_greek>*/	DEADTRANS(	L'6'	,0x03B5	,0x2465	,0x0000	), // "⑥" CIRCLED DIGIT SIX
/*<!dead_greek>*/	DEADTRANS(	L'7'	,0x03B5	,0x2466	,0x0000	), // "⑦" CIRCLED DIGIT SEVEN
/*<!dead_greek>*/	DEADTRANS(	L'8'	,0x03B5	,0x2467	,0x0000	), // "⑧" CIRCLED DIGIT EIGHT
/*<!dead_greek>*/	DEADTRANS(	L'9'	,0x03B5	,0x2468	,0x0000	), // "⑨" CIRCLED DIGIT NINE
/*<!dead_greek>*/	DEADTRANS(	L'A'	,0x03B5	,0x0391	,0x0000	), // "Α" GREEK CAPITAL LETTER ALPHA
/*<!dead_greek>*/	DEADTRANS(	L'a'	,0x03B5	,0x03B1	,0x0000	), // "α" GREEK SMALL LETTER ALPHA
/*<!dead_greek>*/	DEADTRANS(	L'B'	,0x03B5	,0x0392	,0x0000	), // "Β" GREEK CAPITAL LETTER BETA
/*<!dead_greek>*/	DEADTRANS(	L'b'	,0x03B5	,0x03B2	,0x0000	), // "β" GREEK SMALL LETTER BETA
/*<!dead_greek>*/	DEADTRANS(	L'C'	,0x03B5	,0x03A8	,0x0000	), // "Ψ" GREEK CAPITAL LETTER PSI
/*<!dead_greek>*/	DEADTRANS(	L'c'	,0x03B5	,0x03C8	,0x0000	), // "ψ" GREEK SMALL LETTER PSI
/*<!dead_greek>*/	DEADTRANS(	L'D'	,0x03B5	,0x0394	,0x0000	), // "Δ" GREEK CAPITAL LETTER DELTA
/*<!dead_greek>*/	DEADTRANS(	L'd'	,0x03B5	,0x03B4	,0x0000	), // "δ" GREEK SMALL LETTER DELTA
/*<!dead_greek>*/	DEADTRANS(	0x00B0	,0x03B5	,0x229A	,0x0000	), // "⊚" CIRCLED RING OPERATOR
/*<!dead_greek>*/	DEADTRANS(	0x00F7	,0x03B5	,0x2A38	,0x0000	), // "⨸" CIRCLED DIVISION SIGN
/*<!dead_greek>*/	DEADTRANS(	L'E'	,0x03B5	,0x0395	,0x0000	), // "Ε" GREEK CAPITAL LETTER EPSILON
/*<!dead_greek>*/	DEADTRANS(	L'e'	,0x03B5	,0x03B5	,0x0000	), // "ε" GREEK SMALL LETTER EPSILON
/*<!dead_greek>*/	DEADTRANS(	0x2014	,0x03B5	,0x229D	,0x0000	), // "⊝" CIRCLED DASH
/*<!dead_greek>*/	DEADTRANS(	0x2013	,0x03B5	,0x229D	,0x0000	), // "⊝" CIRCLED DASH
/*<!dead_greek>*/	DEADTRANS(	L'F'	,0x03B5	,0x03A6	,0x0000	), // "Φ" GREEK CAPITAL LETTER PHI
/*<!dead_greek>*/	DEADTRANS(	L'f'	,0x03B5	,0x03C6	,0x0000	), // "φ" GREEK SMALL LETTER PHI
/*<!dead_greek>*/	DEADTRANS(	L'G'	,0x03B5	,0x0393	,0x0000	), // "Γ" GREEK CAPITAL LETTER GAMMA
/*<!dead_greek>*/	DEADTRANS(	L'g'	,0x03B5	,0x03B3	,0x0000	), // "γ" GREEK SMALL LETTER GAMMA
/*<!dead_greek>*/	DEADTRANS(	L'H'	,0x03B5	,0x0397	,0x0000	), // "Η" GREEK CAPITAL LETTER ETA
/*<!dead_greek>*/	DEADTRANS(	L'h'	,0x03B5	,0x03B7	,0x0000	), // "η" GREEK SMALL LETTER ETA
/*<!dead_greek>*/	DEADTRANS(	L'I'	,0x03B5	,0x0399	,0x0000	), // "Ι" GREEK CAPITAL LETTER IOTA
/*<!dead_greek>*/	DEADTRANS(	L'i'	,0x03B5	,0x03B9	,0x0000	), // "ι" GREEK SMALL LETTER IOTA
/*<!dead_greek>*/	DEADTRANS(	L'J'	,0x03B5	,0x039E	,0x0000	), // "Ξ" GREEK CAPITAL LETTER XI
/*<!dead_greek>*/	DEADTRANS(	L'j'	,0x03B5	,0x03BE	,0x0000	), // "ξ" GREEK SMALL LETTER XI
/*<!dead_greek>*/	DEADTRANS(	L'K'	,0x03B5	,0x039A	,0x0000	), // "Κ" GREEK CAPITAL LETTER KAPPA
/*<!dead_greek>*/	DEADTRANS(	L'k'	,0x03B5	,0x03BA	,0x0000	), // "κ" GREEK SMALL LETTER KAPPA
/*<!dead_greek>*/	DEADTRANS(	L'L'	,0x03B5	,0x039B	,0x0000	), // "Λ" GREEK CAPITAL LETTER LAMDA
/*<!dead_greek>*/	DEADTRANS(	L'l'	,0x03B5	,0x03BB	,0x0000	), // "λ" GREEK SMALL LETTER LAMDA
/*<!dead_greek>*/	DEADTRANS(	L'M'	,0x03B5	,0x039C	,0x0000	), // "Μ" GREEK CAPITAL LETTER MU
/*<!dead_greek>*/	DEADTRANS(	L'm'	,0x03B5	,0x03BC	,0x0000	), // "μ" GREEK SMALL LETTER MU
/*<!dead_greek>*/	DEADTRANS(	0x00D7	,0x03B5	,0x2297	,0x0000	), // "⊗" CIRCLED TIMES
/*<!dead_greek>*/	DEADTRANS(	L'N'	,0x03B5	,0x039D	,0x0000	), // "Ν" GREEK CAPITAL LETTER NU
/*<!dead_greek>*/	DEADTRANS(	L'n'	,0x03B5	,0x03BD	,0x0000	), // "ν" GREEK SMALL LETTER NU
/*<!dead_greek>*/	DEADTRANS(	L'O'	,0x03B5	,0x039F	,0x0000	), // "Ο" GREEK CAPITAL LETTER OMICRON
/*<!dead_greek>*/	DEADTRANS(	L'o'	,0x03B5	,0x03BF	,0x0000	), // "ο" GREEK SMALL LETTER OMICRON
/*<!dead_greek>*/	DEADTRANS(	L'P'	,0x03B5	,0x03A0	,0x0000	), // "Π" GREEK CAPITAL LETTER PI
/*<!dead_greek>*/	DEADTRANS(	L'p'	,0x03B5	,0x03C0	,0x0000	), // "π" GREEK SMALL LETTER PI
/*<!dead_greek>*/	DEADTRANS(	L'Q'	,0x03B5	,0x03F4	,0x0000	), // "ϴ" GREEK CAPITAL THETA SYMBOL
/*<!dead_greek>*/	DEADTRANS(	L'q'	,0x03B5	,0x03D1	,0x0000	), // "ϑ" GREEK THETA SYMBOL
/*<!dead_greek>*/	DEADTRANS(	L'R'	,0x03B5	,0x03A1	,0x0000	), // "Ρ" GREEK CAPITAL LETTER RHO
/*<!dead_greek>*/	DEADTRANS(	L'r'	,0x03B5	,0x03C1	,0x0000	), // "ρ" GREEK SMALL LETTER RHO
/*<!dead_greek>*/	DEADTRANS(	L'S'	,0x03B5	,0x03A3	,0x0000	), // "Σ" GREEK CAPITAL LETTER SIGMA
/*<!dead_greek>*/	DEADTRANS(	L's'	,0x03B5	,0x03C3	,0x0000	), // "σ" GREEK SMALL LETTER SIGMA
/*<!dead_greek>*/	DEADTRANS(	L'T'	,0x03B5	,0x03A4	,0x0000	), // "Τ" GREEK CAPITAL LETTER TAU
/*<!dead_greek>*/	DEADTRANS(	L't'	,0x03B5	,0x03C4	,0x0000	), // "τ" GREEK SMALL LETTER TAU
/*<!dead_greek>*/	DEADTRANS(	L'U'	,0x03B5	,0x0398	,0x0000	), // "Θ" GREEK CAPITAL LETTER THETA
/*<!dead_greek>*/	DEADTRANS(	L'u'	,0x03B5	,0x03B8	,0x0000	), // "θ" GREEK SMALL LETTER THETA
/*<!dead_greek>*/	DEADTRANS(	L'V'	,0x03B5	,0x03A9	,0x0000	), // "Ω" GREEK CAPITAL LETTER OMEGA
/*<!dead_greek>*/	DEADTRANS(	L'v'	,0x03B5	,0x03C9	,0x0000	), // "ω" GREEK SMALL LETTER OMEGA
/*<!dead_greek>*/	DEADTRANS(	L'w'	,0x03B5	,0x03C2	,0x0000	), // "ς" GREEK SMALL LETTER FINAL SIGMA
/*<!dead_greek>*/	DEADTRANS(	L'W'	,0x03B5	,0x2207	,0x0000	), // "∇" NABLA
/*<!dead_greek>*/	DEADTRANS(	L'X'	,0x03B5	,0x03A7	,0x0000	), // "Χ" GREEK CAPITAL LETTER CHI
/*<!dead_greek>*/	DEADTRANS(	L'x'	,0x03B5	,0x03C7	,0x0000	), // "χ" GREEK SMALL LETTER CHI
/*<!dead_greek>*/	DEADTRANS(	L'Y'	,0x03B5	,0x03A5	,0x0000	), // "Υ" GREEK CAPITAL LETTER UPSILON
/*<!dead_greek>*/	DEADTRANS(	L'y'	,0x03B5	,0x03C5	,0x0000	), // "υ" GREEK SMALL LETTER UPSILON
/*<!dead_greek>*/	DEADTRANS(	L'Z'	,0x03B5	,0x0396	,0x0000	), // "Ζ" GREEK CAPITAL LETTER ZETA
/*<!dead_greek>*/	DEADTRANS(	L'z'	,0x03B5	,0x03B6	,0x0000	), // "ζ" GREEK SMALL LETTER ZETA
/*<!dead_greek>*/	DEADTRANS(	0x00A0	,0x03B5	,0x1FBE	,0x0000	), // "ι" GREEK PROSGEGRAMMENI
/*<!dead_greek>*/	DEADTRANS(	0x202F	,0x03B5	,0x1FBE	,0x0000	), // "ι" GREEK PROSGEGRAMMENI
/*<!dead_greek>*/	DEADTRANS(	L' '	,0x03B5	,0x0345	,0x0000	), // "ͅ" COMBINING GREEK YPOGEGRAMMENI
/*<!dead_greek>*/	DEADTRANS(	0x200B	,0x03B5	,0x0345	,0x0000	), // "ͅ" COMBINING GREEK YPOGEGRAMMENI
/*<!dead_group>*/	DEADTRANS(	0x00E1	,0x2460	,0x0024	,0x0000	), // "$" DOLLAR SIGN
/*<!dead_group>*/	DEADTRANS(	0x00EA	,0x2460	,0x005E	,0x0000	), // "^" CIRCUMFLEX ACCENT
/*<!dead_group>*/	DEADTRANS(	0x00EB	,0x2460	,0x003D	,0x0000	), // "=" EQUALS SIGN
/*<!dead_group>*/	DEADTRANS(	0x00F2	,0x2460	,0x00A4	,0x0000	), // "¤" CURRENCY SIGN
/*<!dead_group>*/	DEADTRANS(	0x03B5	,0x2460	,0x25CC	,0x0000	), // "◌" DOTTED CIRCLE, generic base character for combining diacritics
/*<!dead_group>*/	DEADTRANS(	L'@'	,0x2460	,0x25CC	,0x0000	), // "◌" DOTTED CIRCLE, generic base character for combining diacritics
/*<!dead_group>*/	DEADTRANS(	L'&'	,0x2460	,0x03C0	,0x0000	), // "π" GREEK SMALL LETTER PI math
/*<!dead_group>*/	DEADTRANS(	L'\''	,0x2460	,0x02BC	,0x0000	), // "ʼ" MODIFIER LETTER APOSTROPHE
/*<!dead_group>*/	DEADTRANS(	0x2019	,0x2460	,0x02BC	,0x0000	), // "ʼ" MODIFIER LETTER APOSTROPHE
/*<!dead_group>*/	DEADTRANS(	L'^'	,0x2460	,0x26A0	,0x0000	), // "⚠" WARNING SIGN emoji, ergonomic mapping
/*<!dead_group>*/	DEADTRANS(	L'~'	,0x2460	,0x2243	,0x0000	), // "≃" ASYMPTOTICALLY EQUAL TO math
/*<!dead_group>*/	DEADTRANS(	L'*'	,0x2460	,0x2717	,0x0000	), // "✗" BALLOT X
/*<!dead_group>*/	DEADTRANS(	L'\\'	,0x2460	,0x221A	,0x0000	), // "√" SQUARE ROOT math
/*<!dead_group>*/	DEADTRANS(	L'|'	,0x2460	,0x2020	,0x0000	), // "†" DAGGER
/*<!dead_group>*/	DEADTRANS(	L'{'	,0x2460	,0x222B	,0x0000	), // "∫" INTEGRAL math
/*<!dead_group>*/	DEADTRANS(	L'}'	,0x2460	,0x03A9	,0x0000	), // "Ω" GREEK CAPITAL LETTER OMEGA
/*<!dead_group>*/	DEADTRANS(	L'['	,0x2460	,0x27E8	,0x0000	), // "⟨" MATHEMATICAL LEFT ANGLE BRACKET math
/*<!dead_group>*/	DEADTRANS(	L']'	,0x2460	,0x27E9	,0x0000	), // "⟩" MATHEMATICAL RIGHT ANGLE BRACKET math
/*<!dead_group>*/	DEADTRANS(	L':'	,0x2460	,0x22C5	,0x0000	), // "⋅" DOT OPERATOR math
/*<!dead_group>*/	DEADTRANS(	L','	,0x2460	,0x2764	,0x0000	), // "❤" HEAVY BLACK HEART emoji, red heart, most-used in France
/*<!dead_group>*/	DEADTRANS(	L'$'	,0x2460	,0x2423	,0x0000	), // "␣" OPEN BOX, space character
/*<!dead_group>*/	DEADTRANS(	L'='	,0x2460	,0x2261	,0x0000	), // "≡" IDENTICAL TO math
/*<!dead_group>*/	DEADTRANS(	L'!'	,0x2460	,0x00A1	,0x0000	), // "¡" INVERTED EXCLAMATION MARK
/*<!dead_group>*/	DEADTRANS(	L'`'	,0x2460	,0x02BB	,0x0000	), // "ʻ" MODIFIER LETTER TURNED COMMA
/*<!dead_group>*/	DEADTRANS(	L'>'	,0x2460	,0x2714	,0x0000	), // "✔" HEAVY CHECK MARK emoji
/*<!dead_group>*/	DEADTRANS(	L'<'	,0x2460	,0x2713	,0x0000	), // "✓" CHECK MARK
/*<!dead_group>*/	DEADTRANS(	L'-'	,0x2460	,0x2043	,0x0000	), // "⁃" HYPHEN BULLET
/*<!dead_group>*/	DEADTRANS(	L'#'	,0x2460	,0x2610	,0x0000	), // "☐" BALLOT BOX
/*<!dead_group>*/	DEADTRANS(	L'('	,0x2460	,0x2300	,0x0000	), // "⌀" DIAMETER SIGN math
/*<!dead_group>*/	DEADTRANS(	L')'	,0x2460	,0x2794	,0x0000	), // "➔" HEAVY WIDE-HEADED RIGHTWARDS ARROW
/*<!dead_group>*/	DEADTRANS(	L'%'	,0x2460	,0x2606	,0x0000	), // "☆" WHITE STAR math
/*<!dead_group>*/	DEADTRANS(	L'.'	,0x2460	,0x2027	,0x0000	), // "‧" HYPHENATION POINT
/*<!dead_group>*/	DEADTRANS(	L'+'	,0x2460	,0x00B1	,0x0000	), // "±" PLUS-MINUS SIGN math
/*<!dead_group>*/	DEADTRANS(	L'?'	,0x2460	,0x00BF	,0x0000	), // "¿" INVERTED QUESTION MARK
/*<!dead_group>*/	DEADTRANS(	L'"'	,0x2460	,0x2605	,0x0000	), // "★" BLACK STAR math
/*<!dead_group>*/	DEADTRANS(	0x20AC	,0x2460	,0x2605	,0x0000	), // "★" BLACK STAR math
/*<!dead_group>*/	DEADTRANS(	L';'	,0x2460	,0x02D0	,0x0000	), // "ː" MODIFIER LETTER TRIANGULAR COLON
/*<!dead_group>*/	DEADTRANS(	0x00A7	,0x2460	,0x02D0	,0x0000	), // "ː" MODIFIER LETTER TRIANGULAR COLON
/*<!dead_group>*/	DEADTRANS(	L'/'	,0x2460	,0x2718	,0x0000	), // "✘" HEAVY BALLOT X
/*<!dead_group>*/	DEADTRANS(	L'_'	,0x2460	,0x2022	,0x0000	), // "•" BULLET
/*<!dead_group>*/	DEADTRANS(	L'A'	,0x2460	,0x00C6	,0x0000	), // "Æ" LATIN CAPITAL LETTER AE
/*<!dead_group>*/	DEADTRANS(	L'a'	,0x2460	,0x00E6	,0x0000	), // "æ" LATIN SMALL LETTER AE
/*<!dead_group>*/	DEADTRANS(	0x00C4	,0x2460	,0x00C5	,0x0000	), // "Å" LATIN CAPITAL LETTER A WITH RING ABOVE shortcut for Swiss layout
/*<!dead_group>*/	DEADTRANS(	0x00E4	,0x2460	,0x00E5	,0x0000	), // "å" LATIN SMALL LETTER A WITH RING ABOVE shortcut for Swiss layout
/*<!dead_group>*/	DEADTRANS(	0x00C0	,0x2460	,0x00C5	,0x0000	), // "Å" LATIN CAPITAL LETTER A WITH RING ABOVE shortcut
/*<!dead_group>*/	DEADTRANS(	0x00E0	,0x2460	,0x00E5	,0x0000	), // "å" LATIN SMALL LETTER A WITH RING ABOVE shortcut
/*<!dead_group>*/	DEADTRANS(	L'B'	,0x2460	,0x0189	,0x0000	), // "Ɖ" LATIN CAPITAL LETTER AFRICAN D
/*<!dead_group>*/	DEADTRANS(	L'b'	,0x2460	,0x0256	,0x0000	), // "ɖ" LATIN SMALL LETTER D WITH TAIL
/*<!dead_group>*/	DEADTRANS(	L'C'	,0x2460	,0x0186	,0x0000	), // "Ɔ" LATIN CAPITAL LETTER OPEN O
/*<!dead_group>*/	DEADTRANS(	L'c'	,0x2460	,0x0254	,0x0000	), // "ɔ" LATIN SMALL LETTER OPEN O
/*<!dead_group>*/	DEADTRANS(	0x00C7	,0x2460	,0x00D8	,0x0000	), // "Ø" LATIN CAPITAL LETTER O WITH STROKE shortcut
/*<!dead_group>*/	DEADTRANS(	0x00E7	,0x2460	,0x00F8	,0x0000	), // "ø" LATIN SMALL LETTER O WITH STROKE shortcut
/*<!dead_group>*/	DEADTRANS(	L'D'	,0x2460	,0x00D0	,0x0000	), // "Ð" LATIN CAPITAL LETTER ETH
/*<!dead_group>*/	DEADTRANS(	L'd'	,0x2460	,0x00F0	,0x0000	), // "ð" LATIN SMALL LETTER ETH
/*<!dead_group>*/	DEADTRANS(	L'E'	,0x2460	,0x018E	,0x0000	), // "Ǝ" LATIN CAPITAL LETTER REVERSED E
/*<!dead_group>*/	DEADTRANS(	L'e'	,0x2460	,0x01DD	,0x0000	), // "ǝ" LATIN SMALL LETTER TURNED E
/*<!dead_group>*/	DEADTRANS(	0x00C9	,0x2460	,0x00B2	,0x0000	), // "²" SUPERSCRIPT TWO shortcut for African and Breton variants
/*<!dead_group>*/	DEADTRANS(	0x00E9	,0x2460	,0x00B2	,0x0000	), // "²" SUPERSCRIPT TWO shortcut for African and Breton variants
/*<!dead_group>*/	DEADTRANS(	0x00C8	,0x2460	,0x00D1	,0x0000	), // "Ñ" LATIN CAPITAL LETTER N WITH TILDE shortcut
/*<!dead_group>*/	DEADTRANS(	0x00E8	,0x2460	,0x00F1	,0x0000	), // "ñ" LATIN SMALL LETTER N WITH TILDE shortcut
/*<!dead_group>*/	DEADTRANS(	0x2014	,0x2460	,0x2E3B	,0x0000	), // "⸻" THREE-EM DASH
/*<!dead_group>*/	DEADTRANS(	0x2013	,0x2460	,0x2E3A	,0x0000	), // "⸺" TWO-EM DASH
/*<!dead_group>*/	DEADTRANS(	L'F'	,0x2460	,0x0191	,0x0000	), // "Ƒ" LATIN CAPITAL LETTER F WITH HOOK
/*<!dead_group>*/	DEADTRANS(	L'f'	,0x2460	,0x0192	,0x0000	), // "ƒ" LATIN SMALL LETTER F WITH HOOK
/*<!dead_group>*/	DEADTRANS(	L'G'	,0x2460	,0x014A	,0x0000	), // "Ŋ" LATIN CAPITAL LETTER ENG
/*<!dead_group>*/	DEADTRANS(	L'g'	,0x2460	,0x014B	,0x0000	), // "ŋ" LATIN SMALL LETTER ENG
/*<!dead_group>*/	DEADTRANS(	0x00AB	,0x2460	,0x0025	,0x0000	), // "%" PERCENT SIGN
/*<!dead_group>*/	DEADTRANS(	0x00BB	,0x2460	,0x00B5	,0x0000	), // "µ" MICRO SIGN
/*<!dead_group>*/	DEADTRANS(	L'H'	,0x2460	,0x018F	,0x0000	), // "Ə" LATIN CAPITAL LETTER SCHWA
/*<!dead_group>*/	DEADTRANS(	L'h'	,0x2460	,0x0259	,0x0000	), // "ə" LATIN SMALL LETTER SCHWA
/*<!dead_group>*/	DEADTRANS(	L'I'	,0x2460	,0x0196	,0x0000	), // "Ɩ" LATIN CAPITAL LETTER IOTA
/*<!dead_group>*/	DEADTRANS(	L'i'	,0x2460	,0x0269	,0x0000	), // "ɩ" LATIN SMALL LETTER IOTA
/*<!dead_group>*/	DEADTRANS(	L'J'	,0x2460	,0x0132	,0x0000	), // "Ĳ" LATIN CAPITAL LIGATURE IJ
/*<!dead_group>*/	DEADTRANS(	L'j'	,0x2460	,0x0133	,0x0000	), // "ĳ" LATIN SMALL LIGATURE IJ
/*<!dead_group>*/	DEADTRANS(	L'k'	,0x2460	,0x0251	,0x0000	), // "ɑ" LATIN SMALL LETTER ALPHA
/*<!dead_group>*/	DEADTRANS(	L'K'	,0x2460	,0x2C6D	,0x0000	), // "Ɑ" LATIN CAPITAL LETTER ALPHA
/*<!dead_group>*/	DEADTRANS(	L'l'	,0x2460	,0x02BF	,0x0000	), // "ʿ" MODIFIER LETTER LEFT HALF RING
/*<!dead_group>*/	DEADTRANS(	L'L'	,0x2460	,0x2113	,0x0000	), // "ℓ" SCRIPT SMALL L
/*<!dead_group>*/	DEADTRANS(	L'M'	,0x2460	,0x0294	,0x0000	), // "ʔ" LATIN LETTER GLOTTAL STOP
/*<!dead_group>*/	DEADTRANS(	L'm'	,0x2460	,0x02BE	,0x0000	), // "ʾ" MODIFIER LETTER RIGHT HALF RING
/*<!dead_group>*/	DEADTRANS(	L'N'	,0x2460	,0x019D	,0x0000	), // "Ɲ" LATIN CAPITAL LETTER N WITH LEFT HOOK
/*<!dead_group>*/	DEADTRANS(	L'n'	,0x2460	,0x0272	,0x0000	), // "ɲ" LATIN SMALL LETTER N WITH LEFT HOOK
/*<!dead_group>*/	DEADTRANS(	0x00F1	,0x2460	,0x2015	,0x0000	), // "―" HORIZONTAL BAR
/*<!dead_group>*/	DEADTRANS(	0x00D1	,0x2460	,0x2015	,0x0000	), // "―" HORIZONTAL BAR
/*<!dead_group>*/	DEADTRANS(	L'O'	,0x2460	,0x0152	,0x0000	), // "Œ" LATIN CAPITAL LIGATURE OE
/*<!dead_group>*/	DEADTRANS(	L'o'	,0x2460	,0x0153	,0x0000	), // "œ" LATIN SMALL LIGATURE OE
/*<!dead_group>*/	DEADTRANS(	0x00D6	,0x2460	,0x00D8	,0x0000	), // "Ø" LATIN CAPITAL LETTER O WITH STROKE shortcut for Swiss layout
/*<!dead_group>*/	DEADTRANS(	0x00F6	,0x2460	,0x00F8	,0x0000	), // "ø" LATIN SMALL LETTER O WITH STROKE shortcut for Swiss layout
/*<!dead_group>*/	DEADTRANS(	0x0254	,0x2460	,0x2015	,0x0000	), // "―" HORIZONTAL BAR
/*<!dead_group>*/	DEADTRANS(	0x0186	,0x2460	,0x2015	,0x0000	), // "―" HORIZONTAL BAR
/*<!dead_group>*/	DEADTRANS(	L'P'	,0x2460	,0x00B7	,0x0000	), // "·" MIDDLE DOT
/*<!dead_group>*/	DEADTRANS(	L'p'	,0x2460	,0x00B7	,0x0000	), // "·" MIDDLE DOT
/*<!dead_group>*/	DEADTRANS(	L'Q'	,0x2460	,0x0241	,0x0000	), // "Ɂ" LATIN CAPITAL LETTER GLOTTAL STOP
/*<!dead_group>*/	DEADTRANS(	L'q'	,0x2460	,0x0242	,0x0000	), // "ɂ" LATIN SMALL LETTER GLOTTAL STOP
/*<!dead_group>*/	DEADTRANS(	L'R'	,0x2460	,0x211F	,0x0000	), // "℟" RESPONSE
/*<!dead_group>*/	DEADTRANS(	L'r'	,0x2460	,0x211F	,0x0000	), // "℟" RESPONSE
/*<!dead_group>*/	DEADTRANS(	L's'	,0x2460	,0x00DF	,0x0000	), // "ß" LATIN SMALL LETTER SHARP S
/*<!dead_group>*/	DEADTRANS(	L'S'	,0x2460	,0x1E9E	,0x0000	), // "ẞ" LATIN CAPITAL LETTER SHARP S
/*<!dead_group>*/	DEADTRANS(	L'T'	,0x2460	,0x00DE	,0x0000	), // "Þ" LATIN CAPITAL LETTER THORN
/*<!dead_group>*/	DEADTRANS(	L't'	,0x2460	,0x00FE	,0x0000	), // "þ" LATIN SMALL LETTER THORN
/*<!dead_group>*/	DEADTRANS(	0x00B2	,0x2460	,0x0026	,0x0000	), // "&" AMPERSAND
/*<!dead_group>*/	DEADTRANS(	0x02BB	,0x2460	,0x2015	,0x0000	), // "―" HORIZONTAL BAR
/*<!dead_group>*/	DEADTRANS(	0x2039	,0x2460	,0x00A8	,0x0000	), // "¨" DIAERESIS
/*<!dead_group>*/	DEADTRANS(	0x203A	,0x2460	,0x00A3	,0x0000	), // "£" POUND SIGN
/*<!dead_group>*/	DEADTRANS(	0x2212	,0x2460	,0x2012	,0x0000	), // "‒" FIGURE DASH
/*<!dead_group>*/	DEADTRANS(	L'U'	,0x2460	,0x01B2	,0x0000	), // "Ʋ" LATIN CAPITAL LETTER V WITH HOOK
/*<!dead_group>*/	DEADTRANS(	L'u'	,0x2460	,0x028B	,0x0000	), // "ʋ" LATIN SMALL LETTER V WITH HOOK
/*<!dead_group>*/	DEADTRANS(	0x00DC	,0x2460	,0x00D1	,0x0000	), // "Ñ" LATIN CAPITAL LETTER N WITH TILDE shortcut for Swiss layout
/*<!dead_group>*/	DEADTRANS(	0x00FC	,0x2460	,0x00F1	,0x0000	), // "ñ" LATIN SMALL LETTER N WITH TILDE shortcut for Swiss layout
/*<!dead_group>*/	DEADTRANS(	0x00FC	,0x2460	,0x00F1	,0x0000	), // "ñ" LATIN SMALL LETTER N WITH TILDE shortcut for Swiss layout
/*<!dead_group>*/	DEADTRANS(	0x00FC	,0x2460	,0x00F1	,0x0000	), // "ñ" LATIN SMALL LETTER N WITH TILDE shortcut for Swiss layout
/*<!dead_group>*/	DEADTRANS(	0x00FC	,0x2460	,0x00F1	,0x0000	), // "ñ" LATIN SMALL LETTER N WITH TILDE shortcut for Swiss layout
/*<!dead_group>*/	DEADTRANS(	0x00FC	,0x2460	,0x00F1	,0x0000	), // "ñ" LATIN SMALL LETTER N WITH TILDE shortcut for Swiss layout
/*<!dead_group>*/	DEADTRANS(	0x00FC	,0x2460	,0x00F1	,0x0000	), // "ñ" LATIN SMALL LETTER N WITH TILDE shortcut for Swiss layout
/*<!dead_group>*/	DEADTRANS(	0x00FC	,0x2460	,0x00F1	,0x0000	), // "ñ" LATIN SMALL LETTER N WITH TILDE shortcut for Swiss layout
/*<!dead_group>*/	DEADTRANS(	L'V'	,0x2460	,0x2123	,0x0000	), // "℣" VERSICLE
/*<!dead_group>*/	DEADTRANS(	L'v'	,0x2460	,0x2123	,0x0000	), // "℣" VERSICLE
/*<!dead_group>*/	DEADTRANS(	L'W'	,0x2460	,0x01A9	,0x0000	), // "Ʃ" LATIN CAPITAL LETTER ESH
/*<!dead_group>*/	DEADTRANS(	L'w'	,0x2460	,0x0283	,0x0000	), // "ʃ" LATIN SMALL LETTER ESH
/*<!dead_group>*/	DEADTRANS(	L'X'	,0x2460	,0x0190	,0x0000	), // "Ɛ" LATIN CAPITAL LETTER OPEN E
/*<!dead_group>*/	DEADTRANS(	L'x'	,0x2460	,0x025B	,0x0000	), // "ɛ" LATIN SMALL LETTER OPEN E
/*<!dead_group>*/	DEADTRANS(	L'Y'	,0x2460	,0x01B1	,0x0000	), // "Ʊ" LATIN CAPITAL LETTER UPSILON
/*<!dead_group>*/	DEADTRANS(	L'y'	,0x2460	,0x028A	,0x0000	), // "ʊ" LATIN SMALL LETTER UPSILON
/*<!dead_group>*/	DEADTRANS(	L'Z'	,0x2460	,0x01B7	,0x0000	), // "Ʒ" LATIN CAPITAL LETTER EZH
/*<!dead_group>*/	DEADTRANS(	L'z'	,0x2460	,0x0292	,0x0000	), // "ʒ" LATIN SMALL LETTER EZH
/*<!dead_group>*/	DEADTRANS(	0x00A0	,0x2460	,0x2001	,0x0000	), // " " EM QUAD
/*<!dead_group>*/	DEADTRANS(	0x202F	,0x2460	,0x200A	,0x0000	), // " " HAIR SPACE
/*<!dead_group>*/	DEADTRANS(	L' '	,0x2460	,0x2003	,0x0000	), // " " EM SPACE
/*<!dead_hook>*/	DEADTRANS(	L'.'	,0x0192	,0x2055	,0x0000	), // "⁕" FLOWER PUNCTUATION MARK
/*<!dead_hook>*/	DEADTRANS(	L'1'	,0x0192	,0x02E9	,0x0000	), // "˩" MODIFIER LETTER EXTRA-LOW TONE BAR
/*<!dead_hook>*/	DEADTRANS(	L'2'	,0x0192	,0x02E8	,0x0000	), // "˨" MODIFIER LETTER LOW TONE BAR
/*<!dead_hook>*/	DEADTRANS(	L'3'	,0x0192	,0x02E7	,0x0000	), // "˧" MODIFIER LETTER MID TONE BAR
/*<!dead_hook>*/	DEADTRANS(	L'4'	,0x0192	,0x02E6	,0x0000	), // "˦" MODIFIER LETTER HIGH TONE BAR
/*<!dead_hook>*/	DEADTRANS(	L'5'	,0x0192	,0x02E5	,0x0000	), // "˥" MODIFIER LETTER EXTRA-HIGH TONE BAR
/*<!dead_hook>*/	DEADTRANS(	L'B'	,0x0192	,0x0181	,0x0000	), // "Ɓ" LATIN CAPITAL LETTER B WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'b'	,0x0192	,0x0253	,0x0000	), // "ɓ" LATIN SMALL LETTER B WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'C'	,0x0192	,0x0187	,0x0000	), // "Ƈ" LATIN CAPITAL LETTER C WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'c'	,0x0192	,0x0188	,0x0000	), // "ƈ" LATIN SMALL LETTER C WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'D'	,0x0192	,0x018A	,0x0000	), // "Ɗ" LATIN CAPITAL LETTER D WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'd'	,0x0192	,0x0257	,0x0000	), // "ɗ" LATIN SMALL LETTER D WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'e'	,0x0192	,0x025D	,0x0000	), // "ɝ" LATIN SMALL LETTER REVERSED OPEN E WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'F'	,0x0192	,0x0191	,0x0000	), // "Ƒ" LATIN CAPITAL LETTER F WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'f'	,0x0192	,0x0192	,0x0000	), // "ƒ" LATIN SMALL LETTER F WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'G'	,0x0192	,0x0193	,0x0000	), // "Ɠ" LATIN CAPITAL LETTER G WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'g'	,0x0192	,0x0260	,0x0000	), // "ɠ" LATIN SMALL LETTER G WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'h'	,0x0192	,0x0266	,0x0000	), // "ɦ" LATIN SMALL LETTER H WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'H'	,0x0192	,0xA7AA	,0x0000	), // "Ɦ" LATIN CAPITAL LETTER H WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'j'	,0x0192	,0x0284	,0x0000	), // "ʄ" LATIN SMALL LETTER DOTLESS J WITH STROKE AND HOOK
/*<!dead_hook>*/	DEADTRANS(	L'K'	,0x0192	,0x0198	,0x0000	), // "Ƙ" LATIN CAPITAL LETTER K WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'k'	,0x0192	,0x0199	,0x0000	), // "ƙ" LATIN SMALL LETTER K WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'l'	,0x0192	,0xDF11	,0x0000	), // High surrogate: D837; U+1DF11 "𝼑" LATIN SMALL LETTER L WITH FISHHOOK
/*<!dead_hook>*/	DEADTRANS(	L'm'	,0x0192	,0x0271	,0x0000	), // "ɱ" LATIN SMALL LETTER M WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'M'	,0x0192	,0x2C6E	,0x0000	), // "Ɱ" LATIN CAPITAL LETTER M WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'N'	,0x0192	,0x019D	,0x0000	), // "Ɲ" LATIN CAPITAL LETTER N WITH LEFT HOOK
/*<!dead_hook>*/	DEADTRANS(	L'n'	,0x0192	,0x0272	,0x0000	), // "ɲ" LATIN SMALL LETTER N WITH LEFT HOOK
/*<!dead_hook>*/	DEADTRANS(	L'P'	,0x0192	,0x01A4	,0x0000	), // "Ƥ" LATIN CAPITAL LETTER P WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'p'	,0x0192	,0x01A5	,0x0000	), // "ƥ" LATIN SMALL LETTER P WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'q'	,0x0192	,0x02A0	,0x0000	), // "ʠ" LATIN SMALL LETTER Q WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'r'	,0x0192	,0x027E	,0x0000	), // "ɾ" LATIN SMALL LETTER R WITH FISHHOOK
/*<!dead_hook>*/	DEADTRANS(	L's'	,0x0192	,0x0282	,0x0000	), // "ʂ" LATIN SMALL LETTER S WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'S'	,0x0192	,0xA7C5	,0x0000	), // "Ʂ" LATIN CAPITAL LETTER S WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'T'	,0x0192	,0x01AC	,0x0000	), // "Ƭ" LATIN CAPITAL LETTER T WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L't'	,0x0192	,0x01AD	,0x0000	), // "ƭ" LATIN SMALL LETTER T WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'V'	,0x0192	,0x01B2	,0x0000	), // "Ʋ" LATIN CAPITAL LETTER V WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'v'	,0x0192	,0x028B	,0x0000	), // "ʋ" LATIN SMALL LETTER V WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'W'	,0x0192	,0x2C72	,0x0000	), // "Ⱳ" LATIN CAPITAL LETTER W WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'w'	,0x0192	,0x2C73	,0x0000	), // "ⱳ" LATIN SMALL LETTER W WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'Y'	,0x0192	,0x01B3	,0x0000	), // "Ƴ" LATIN CAPITAL LETTER Y WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'y'	,0x0192	,0x01B4	,0x0000	), // "ƴ" LATIN SMALL LETTER Y WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'Z'	,0x0192	,0x0224	,0x0000	), // "Ȥ" LATIN CAPITAL LETTER Z WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	L'z'	,0x0192	,0x0225	,0x0000	), // "ȥ" LATIN SMALL LETTER Z WITH HOOK
/*<!dead_hook>*/	DEADTRANS(	0x00A0	,0x0192	,0x02DE	,0x0000	), // "˞" MODIFIER LETTER RHOTIC HOOK
/*<!dead_hook>*/	DEADTRANS(	0x202F	,0x0192	,0x02DE	,0x0000	), // "˞" MODIFIER LETTER RHOTIC HOOK
/*<!dead_hook>*/	DEADTRANS(	L' '	,0x0192	,0x0321	,0x0000	), // "̡" COMBINING PALATALIZED HOOK BELOW
/*<!dead_hook>*/	DEADTRANS(	0x200B	,0x0192	,0x0321	,0x0000	), // "̡" COMBINING PALATALIZED HOOK BELOW
/*<!dead_horn>*/	DEADTRANS(	L'&'	,0x01A1	,0x1ACA	,0x0000	), // "᫊" COMBINING DOUBLE PLUS SIGN BELOW
/*<!dead_horn>*/	DEADTRANS(	L'>'	,0x01A1	,0x2945	,0x0000	), // "⥅" RIGHTWARDS ARROW WITH PLUS BELOW
/*<!dead_horn>*/	DEADTRANS(	L'<'	,0x01A1	,0x2946	,0x0000	), // "⥆" LEFTWARDS ARROW WITH PLUS BELOW
/*<!dead_horn>*/	DEADTRANS(	L'"'	,0x01A1	,0x1AC9	,0x0000	), // "᫉" COMBINING DOUBLE PLUS SIGN ABOVE
/*<!dead_horn>*/	DEADTRANS(	0x20AC	,0x01A1	,0x1AC9	,0x0000	), // "᫉" COMBINING DOUBLE PLUS SIGN ABOVE
/*<!dead_horn>*/	DEADTRANS(	L'0'	,0x01A1	,0x2195	,0x0000	), // "↕" UP DOWN ARROW emoji
/*<!dead_horn>*/	DEADTRANS(	L'1'	,0x01A1	,0x2199	,0x0000	), // "↙" SOUTH WEST ARROW emoji
/*<!dead_horn>*/	DEADTRANS(	L'2'	,0x01A1	,0x2193	,0x0000	), // "↓" DOWNWARDS ARROW
/*<!dead_horn>*/	DEADTRANS(	L'3'	,0x01A1	,0x2198	,0x0000	), // "↘" SOUTH EAST ARROW emoji
/*<!dead_horn>*/	DEADTRANS(	L'4'	,0x01A1	,0x2190	,0x0000	), // "←" LEFTWARDS ARROW
/*<!dead_horn>*/	DEADTRANS(	L'5'	,0x01A1	,0x2194	,0x0000	), // "↔" LEFT RIGHT ARROW emoji
/*<!dead_horn>*/	DEADTRANS(	L'6'	,0x01A1	,0x2192	,0x0000	), // "→" RIGHTWARDS ARROW
/*<!dead_horn>*/	DEADTRANS(	L'7'	,0x01A1	,0x2196	,0x0000	), // "↖" NORTH WEST ARROW emoji
/*<!dead_horn>*/	DEADTRANS(	L'8'	,0x01A1	,0x2191	,0x0000	), // "↑" UPWARDS ARROW
/*<!dead_horn>*/	DEADTRANS(	L'9'	,0x01A1	,0x2197	,0x0000	), // "↗" NORTH EAST ARROW emoji
/*<!dead_horn>*/	DEADTRANS(	L'A'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'a'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'B'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'b'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'C'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'c'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'D'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'd'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'e'	,0x01A1	,0x2C78	,0x0000	), // "ⱸ" LATIN SMALL LETTER E WITH NOTCH
/*<!dead_horn>*/	DEADTRANS(	L'F'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'f'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'G'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'g'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'H'	,0x01A1	,0x2C67	,0x0000	), // "Ⱨ" LATIN CAPITAL LETTER H WITH DESCENDER
/*<!dead_horn>*/	DEADTRANS(	L'h'	,0x01A1	,0x2C68	,0x0000	), // "ⱨ" LATIN SMALL LETTER H WITH DESCENDER
/*<!dead_horn>*/	DEADTRANS(	L'I'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'i'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'J'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'j'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'K'	,0x01A1	,0x2C69	,0x0000	), // "Ⱪ" LATIN CAPITAL LETTER K WITH DESCENDER
/*<!dead_horn>*/	DEADTRANS(	L'k'	,0x01A1	,0x2C6A	,0x0000	), // "ⱪ" LATIN SMALL LETTER K WITH DESCENDER
/*<!dead_horn>*/	DEADTRANS(	L'L'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'l'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'M'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'm'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'N'	,0x01A1	,0xA790	,0x0000	), // "Ꞑ" LATIN CAPITAL LETTER N WITH DESCENDER
/*<!dead_horn>*/	DEADTRANS(	L'n'	,0x01A1	,0xA791	,0x0000	), // "ꞑ" LATIN SMALL LETTER N WITH DESCENDER
/*<!dead_horn>*/	DEADTRANS(	L'O'	,0x01A1	,0x01A0	,0x0000	), // "Ơ" LATIN CAPITAL LETTER O WITH HORN
/*<!dead_horn>*/	DEADTRANS(	L'o'	,0x01A1	,0x01A1	,0x0000	), // "ơ" LATIN SMALL LETTER O WITH HORN
/*<!dead_horn>*/	DEADTRANS(	L'P'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'p'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'Q'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'q'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'R'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'r'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'S'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L's'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'T'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L't'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'U'	,0x01A1	,0x01AF	,0x0000	), // "Ư" LATIN CAPITAL LETTER U WITH HORN
/*<!dead_horn>*/	DEADTRANS(	L'u'	,0x01A1	,0x01B0	,0x0000	), // "ư" LATIN SMALL LETTER U WITH HORN
/*<!dead_horn>*/	DEADTRANS(	0x00F9	,0x01A1	,0x1EEA	,0x0000	), // "Ừ" LATIN CAPITAL LETTER U WITH HORN AND GRAVE
/*<!dead_horn>*/	DEADTRANS(	0x00F9	,0x01A1	,0x1EEB	,0x0000	), // "ừ" LATIN SMALL LETTER U WITH HORN AND GRAVE
/*<!dead_horn>*/	DEADTRANS(	L'V'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'v'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'W'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'w'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'X'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'x'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'Y'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'y'	,0x01A1	,0x02D6	,0x0000	), // "˖" MODIFIER LETTER PLUS SIGN
/*<!dead_horn>*/	DEADTRANS(	L'Z'	,0x01A1	,0x2C6B	,0x0000	), // "Ⱬ" LATIN CAPITAL LETTER Z WITH DESCENDER
/*<!dead_horn>*/	DEADTRANS(	L'z'	,0x01A1	,0x2C6C	,0x0000	), // "ⱬ" LATIN SMALL LETTER Z WITH DESCENDER
/*<!dead_horn>*/	DEADTRANS(	0x00A0	,0x01A1	,0xA71A	,0x0000	), // "ꜚ" MODIFIER LETTER LOWER RIGHT CORNER ANGLE
/*<!dead_horn>*/	DEADTRANS(	0x202F	,0x01A1	,0xA71A	,0x0000	), // "ꜚ" MODIFIER LETTER LOWER RIGHT CORNER ANGLE
/*<!dead_horn>*/	DEADTRANS(	L' '	,0x01A1	,0x031B	,0x0000	), // "̛" COMBINING HORN
/*<!dead_horn>*/	DEADTRANS(	0x200B	,0x01A1	,0x031B	,0x0000	), // "̛" COMBINING HORN
/*<!dead_invertedbreve>*/	DEADTRANS(	L'='	,0x0213	,0x0361	,0x0000	), // "͡" COMBINING DOUBLE INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	L'A'	,0x0213	,0x0202	,0x0000	), // "Ȃ" LATIN CAPITAL LETTER A WITH INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	L'a'	,0x0213	,0x0203	,0x0000	), // "ȃ" LATIN SMALL LETTER A WITH INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	L'C'	,0x0213	,0x02D3	,0x0000	), // "˓" MODIFIER LETTER CENTRED LEFT HALF RING
/*<!dead_invertedbreve>*/	DEADTRANS(	L'c'	,0x0213	,0x02D3	,0x0000	), // "˓" MODIFIER LETTER CENTRED LEFT HALF RING
/*<!dead_invertedbreve>*/	DEADTRANS(	L'E'	,0x0213	,0x0206	,0x0000	), // "Ȇ" LATIN CAPITAL LETTER E WITH INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	L'e'	,0x0213	,0x0207	,0x0000	), // "ȇ" LATIN SMALL LETTER E WITH INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	0x2014	,0x0213	,0x0361	,0x0000	), // "͡" COMBINING DOUBLE INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	L'f'	,0x0213	,0xDF00	,0x0000	), // High surrogate: D837; U+1DF00 "𝼀" LATIN SMALL LETTER FENG DIGRAPH WITH TRILL
/*<!dead_invertedbreve>*/	DEADTRANS(	L'G'	,0x0213	,0x2050	,0x0000	), // "⁐" CLOSE UP
/*<!dead_invertedbreve>*/	DEADTRANS(	L'g'	,0x0213	,0x2050	,0x0000	), // "⁐" CLOSE UP
/*<!dead_invertedbreve>*/	DEADTRANS(	L'I'	,0x0213	,0x020A	,0x0000	), // "Ȋ" LATIN CAPITAL LETTER I WITH INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	L'i'	,0x0213	,0x020B	,0x0000	), // "ȋ" LATIN SMALL LETTER I WITH INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	L'O'	,0x0213	,0x020E	,0x0000	), // "Ȏ" LATIN CAPITAL LETTER O WITH INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	L'o'	,0x0213	,0x020F	,0x0000	), // "ȏ" LATIN SMALL LETTER O WITH INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	L'R'	,0x0213	,0x0212	,0x0000	), // "Ȓ" LATIN CAPITAL LETTER R WITH INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	L'r'	,0x0213	,0x0213	,0x0000	), // "ȓ" LATIN SMALL LETTER R WITH INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	L'U'	,0x0213	,0x0216	,0x0000	), // "Ȗ" LATIN CAPITAL LETTER U WITH INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	L'u'	,0x0213	,0x0217	,0x0000	), // "ȗ" LATIN SMALL LETTER U WITH INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	0x00A0	,0x0213	,0xAB5B	,0x0000	), // "꭛" MODIFIER BREVE WITH INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	0x202F	,0x0213	,0xAB5B	,0x0000	), // "꭛" MODIFIER BREVE WITH INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	L' '	,0x0213	,0x0311	,0x0000	), // "̑" COMBINING INVERTED BREVE
/*<!dead_invertedbreve>*/	DEADTRANS(	0x200B	,0x0213	,0x0311	,0x0000	), // "̑" COMBINING INVERTED BREVE
/*<!dead_legacygrave>*/	DEADTRANS(	L'A'	,L'`'	,0x00C0	,0x0000	), // "À" LATIN CAPITAL LETTER A WITH GRAVE
/*<!dead_legacygrave>*/	DEADTRANS(	L'a'	,L'`'	,0x00E0	,0x0000	), // "à" LATIN SMALL LETTER A WITH GRAVE
/*<!dead_legacygrave>*/	DEADTRANS(	L'E'	,L'`'	,0x00C8	,0x0000	), // "È" LATIN CAPITAL LETTER E WITH GRAVE
/*<!dead_legacygrave>*/	DEADTRANS(	L'e'	,L'`'	,0x00E8	,0x0000	), // "è" LATIN SMALL LETTER E WITH GRAVE
/*<!dead_legacygrave>*/	DEADTRANS(	L'I'	,L'`'	,0x00CC	,0x0000	), // "Ì" LATIN CAPITAL LETTER I WITH GRAVE
/*<!dead_legacygrave>*/	DEADTRANS(	L'i'	,L'`'	,0x00EC	,0x0000	), // "ì" LATIN SMALL LETTER I WITH GRAVE
/*<!dead_legacygrave>*/	DEADTRANS(	L'N'	,L'`'	,0x01F8	,0x0000	), // "Ǹ" LATIN CAPITAL LETTER N WITH GRAVE
/*<!dead_legacygrave>*/	DEADTRANS(	L'n'	,L'`'	,0x01F9	,0x0000	), // "ǹ" LATIN SMALL LETTER N WITH GRAVE
/*<!dead_legacygrave>*/	DEADTRANS(	L'O'	,L'`'	,0x00D2	,0x0000	), // "Ò" LATIN CAPITAL LETTER O WITH GRAVE
/*<!dead_legacygrave>*/	DEADTRANS(	L'o'	,L'`'	,0x00F2	,0x0000	), // "ò" LATIN SMALL LETTER O WITH GRAVE
/*<!dead_legacygrave>*/	DEADTRANS(	L'U'	,L'`'	,0x00D9	,0x0000	), // "Ù" LATIN CAPITAL LETTER U WITH GRAVE
/*<!dead_legacygrave>*/	DEADTRANS(	L'u'	,L'`'	,0x00F9	,0x0000	), // "ù" LATIN SMALL LETTER U WITH GRAVE
/*<!dead_legacygrave>*/	DEADTRANS(	L'W'	,L'`'	,0x1E80	,0x0000	), // "Ẁ" LATIN CAPITAL LETTER W WITH GRAVE
/*<!dead_legacygrave>*/	DEADTRANS(	L'w'	,L'`'	,0x1E81	,0x0000	), // "ẁ" LATIN SMALL LETTER W WITH GRAVE
/*<!dead_legacygrave>*/	DEADTRANS(	L'Y'	,L'`'	,0x1EF2	,0x0000	), // "Ỳ" LATIN CAPITAL LETTER Y WITH GRAVE
/*<!dead_legacygrave>*/	DEADTRANS(	L'y'	,L'`'	,0x1EF3	,0x0000	), // "ỳ" LATIN SMALL LETTER Y WITH GRAVE
/*<!dead_legacygrave>*/	DEADTRANS(	L' '	,L'`'	,0x0060	,0x0000	), // "`" GRAVE ACCENT
/*<!dead_legacytilde>*/	DEADTRANS(	L'A'	,L'~'	,0x00C3	,0x0000	), // "Ã" LATIN CAPITAL LETTER A WITH TILDE
/*<!dead_legacytilde>*/	DEADTRANS(	L'a'	,L'~'	,0x00E3	,0x0000	), // "ã" LATIN SMALL LETTER A WITH TILDE
/*<!dead_legacytilde>*/	DEADTRANS(	L'E'	,L'~'	,0x1EBC	,0x0000	), // "Ẽ" LATIN CAPITAL LETTER E WITH TILDE
/*<!dead_legacytilde>*/	DEADTRANS(	L'e'	,L'~'	,0x1EBD	,0x0000	), // "ẽ" LATIN SMALL LETTER E WITH TILDE
/*<!dead_legacytilde>*/	DEADTRANS(	L'I'	,L'~'	,0x0128	,0x0000	), // "Ĩ" LATIN CAPITAL LETTER I WITH TILDE
/*<!dead_legacytilde>*/	DEADTRANS(	L'i'	,L'~'	,0x0129	,0x0000	), // "ĩ" LATIN SMALL LETTER I WITH TILDE
/*<!dead_legacytilde>*/	DEADTRANS(	L'N'	,L'~'	,0x00D1	,0x0000	), // "Ñ" LATIN CAPITAL LETTER N WITH TILDE
/*<!dead_legacytilde>*/	DEADTRANS(	L'n'	,L'~'	,0x00F1	,0x0000	), // "ñ" LATIN SMALL LETTER N WITH TILDE
/*<!dead_legacytilde>*/	DEADTRANS(	L'O'	,L'~'	,0x00D5	,0x0000	), // "Õ" LATIN CAPITAL LETTER O WITH TILDE
/*<!dead_legacytilde>*/	DEADTRANS(	L'o'	,L'~'	,0x00F5	,0x0000	), // "õ" LATIN SMALL LETTER O WITH TILDE
/*<!dead_legacytilde>*/	DEADTRANS(	L'U'	,L'~'	,0x0168	,0x0000	), // "Ũ" LATIN CAPITAL LETTER U WITH TILDE
/*<!dead_legacytilde>*/	DEADTRANS(	L'u'	,L'~'	,0x0169	,0x0000	), // "ũ" LATIN SMALL LETTER U WITH TILDE
/*<!dead_legacytilde>*/	DEADTRANS(	L'V'	,L'~'	,0x1E7C	,0x0000	), // "Ṽ" LATIN CAPITAL LETTER V WITH TILDE
/*<!dead_legacytilde>*/	DEADTRANS(	L'v'	,L'~'	,0x1E7D	,0x0000	), // "ṽ" LATIN SMALL LETTER V WITH TILDE
/*<!dead_legacytilde>*/	DEADTRANS(	L'Y'	,L'~'	,0x1EF8	,0x0000	), // "Ỹ" LATIN CAPITAL LETTER Y WITH TILDE
/*<!dead_legacytilde>*/	DEADTRANS(	L'y'	,L'~'	,0x1EF9	,0x0000	), // "ỹ" LATIN SMALL LETTER Y WITH TILDE
/*<!dead_legacytilde>*/	DEADTRANS(	L' '	,L'~'	,0x007E	,0x0000	), // "~" TILDE
/*<!dead_macron>*/	DEADTRANS(	L'&'	,0x0101	,0xFE26	,0x0000	), // "︦" COMBINING CONJOINING MACRON
/*<!dead_macron>*/	DEADTRANS(	L'\''	,0x0101	,0x2A42	,0x0000	), // "⩂" UNION WITH OVERBAR
/*<!dead_macron>*/	DEADTRANS(	0x2019	,0x0101	,0x2A42	,0x0000	), // "⩂" UNION WITH OVERBAR
/*<!dead_macron>*/	DEADTRANS(	L'{'	,0x0101	,0x2A43	,0x0000	), // "⩃" INTERSECTION WITH OVERBAR
/*<!dead_macron>*/	DEADTRANS(	L'}'	,0x0101	,0x29B1	,0x0000	), // "⦱" EMPTY SET WITH OVERBAR
/*<!dead_macron>*/	DEADTRANS(	L'='	,0x0101	,0x035E	,0x0000	), // "͞" COMBINING DOUBLE MACRON
/*<!dead_macron>*/	DEADTRANS(	L'`'	,0x0101	,0x22BC	,0x0000	), // "⊼" NAND
/*<!dead_macron>*/	DEADTRANS(	L'?'	,0x0101	,0x22BD	,0x0000	), // "⊽" NOR
/*<!dead_macron>*/	DEADTRANS(	L'/'	,0x0101	,0x29F6	,0x0000	), // "⧶" SOLIDUS WITH OVERBAR
/*<!dead_macron>*/	DEADTRANS(	L'0'	,0x0101	,0x2AFE	,0x0000	), // "⫾" WHITE VERTICAL BAR
/*<!dead_macron>*/	DEADTRANS(	L'1'	,0x0101	,0x2223	,0x0000	), // "∣" DIVIDES
/*<!dead_macron>*/	DEADTRANS(	L'2'	,0x0101	,0x2016	,0x0000	), // "‖" DOUBLE VERTICAL LINE
/*<!dead_macron>*/	DEADTRANS(	L'3'	,0x0101	,0x2980	,0x0000	), // "⦀" TRIPLE VERTICAL BAR DELIMITER
/*<!dead_macron>*/	DEADTRANS(	L'4'	,0x0101	,0x2225	,0x0000	), // "∥" PARALLEL TO
/*<!dead_macron>*/	DEADTRANS(	L'5'	,0x0101	,0x01C0	,0x0000	), // "ǀ" LATIN LETTER DENTAL CLICK
/*<!dead_macron>*/	DEADTRANS(	L'6'	,0x0101	,0x2AF4	,0x0000	), // "⫴" TRIPLE VERTICAL BAR BINARY RELATION
/*<!dead_macron>*/	DEADTRANS(	L'7'	,0x0101	,0x2AFF	,0x0000	), // "⫿" N-ARY WHITE VERTICAL BAR
/*<!dead_macron>*/	DEADTRANS(	L'8'	,0x0101	,0x01C1	,0x0000	), // "ǁ" LATIN LETTER LATERAL CLICK
/*<!dead_macron>*/	DEADTRANS(	L'9'	,0x0101	,0x2AFC	,0x0000	), // "⫼" LARGE TRIPLE VERTICAL BAR OPERATOR
/*<!dead_macron>*/	DEADTRANS(	L'A'	,0x0101	,0x0100	,0x0000	), // "Ā" LATIN CAPITAL LETTER A WITH MACRON
/*<!dead_macron>*/	DEADTRANS(	L'a'	,0x0101	,0x0101	,0x0000	), // "ā" LATIN SMALL LETTER A WITH MACRON
/*<!dead_macron>*/	DEADTRANS(	L'B'	,0x0101	,0x0182	,0x0000	), // "Ƃ" LATIN CAPITAL LETTER B WITH TOPBAR
/*<!dead_macron>*/	DEADTRANS(	L'b'	,0x0101	,0x0183	,0x0000	), // "ƃ" LATIN SMALL LETTER B WITH TOPBAR
/*<!dead_macron>*/	DEADTRANS(	L'c'	,0x0101	,0x00A2	,0x0000	), // "¢" CENT SIGN
/*<!dead_macron>*/	DEADTRANS(	L'C'	,0x0101	,0x20B5	,0x0000	), // "₵" CEDI SIGN
/*<!dead_macron>*/	DEADTRANS(	L'D'	,0x0101	,0x018B	,0x0000	), // "Ƌ" LATIN CAPITAL LETTER D WITH TOPBAR
/*<!dead_macron>*/	DEADTRANS(	L'd'	,0x0101	,0x018C	,0x0000	), // "ƌ" LATIN SMALL LETTER D WITH TOPBAR
/*<!dead_macron>*/	DEADTRANS(	L'E'	,0x0101	,0x0112	,0x0000	), // "Ē" LATIN CAPITAL LETTER E WITH MACRON
/*<!dead_macron>*/	DEADTRANS(	L'e'	,0x0101	,0x0113	,0x0000	), // "ē" LATIN SMALL LETTER E WITH MACRON
/*<!dead_macron>*/	DEADTRANS(	0x00C9	,0x0101	,0x1E16	,0x0000	), // "Ḗ" LATIN CAPITAL LETTER E WITH MACRON AND ACUTE
/*<!dead_macron>*/	DEADTRANS(	0x00E9	,0x0101	,0x1E17	,0x0000	), // "ḗ" LATIN SMALL LETTER E WITH MACRON AND ACUTE
/*<!dead_macron>*/	DEADTRANS(	0x00C8	,0x0101	,0x1E14	,0x0000	), // "Ḕ" LATIN CAPITAL LETTER E WITH MACRON AND GRAVE
/*<!dead_macron>*/	DEADTRANS(	0x00E8	,0x0101	,0x1E15	,0x0000	), // "ḕ" LATIN SMALL LETTER E WITH MACRON AND GRAVE
/*<!dead_macron>*/	DEADTRANS(	0x2014	,0x0101	,0x035E	,0x0000	), // "͞" COMBINING DOUBLE MACRON
/*<!dead_macron>*/	DEADTRANS(	L'F'	,0x0101	,0xFE24	,0x0000	), // "︤" COMBINING MACRON LEFT HALF
/*<!dead_macron>*/	DEADTRANS(	L'f'	,0x0101	,0xFE25	,0x0000	), // "︥" COMBINING MACRON RIGHT HALF
/*<!dead_macron>*/	DEADTRANS(	L'G'	,0x0101	,0x1E20	,0x0000	), // "Ḡ" LATIN CAPITAL LETTER G WITH MACRON
/*<!dead_macron>*/	DEADTRANS(	L'g'	,0x0101	,0x1E21	,0x0000	), // "ḡ" LATIN SMALL LETTER G WITH MACRON
/*<!dead_macron>*/	DEADTRANS(	L'H'	,0x0101	,0xFE24	,0x0000	), // "︤" COMBINING MACRON LEFT HALF
/*<!dead_macron>*/	DEADTRANS(	L'h'	,0x0101	,0xFE25	,0x0000	), // "︥" COMBINING MACRON RIGHT HALF
/*<!dead_macron>*/	DEADTRANS(	L'I'	,0x0101	,0x012A	,0x0000	), // "Ī" LATIN CAPITAL LETTER I WITH MACRON
/*<!dead_macron>*/	DEADTRANS(	L'i'	,0x0101	,0x012B	,0x0000	), // "ī" LATIN SMALL LETTER I WITH MACRON
/*<!dead_macron>*/	DEADTRANS(	L'J'	,0x0101	,0xFE24	,0x0000	), // "︤" COMBINING MACRON LEFT HALF
/*<!dead_macron>*/	DEADTRANS(	L'j'	,0x0101	,0xFE25	,0x0000	), // "︥" COMBINING MACRON RIGHT HALF
/*<!dead_macron>*/	DEADTRANS(	L'K'	,0x0101	,0xFE24	,0x0000	), // "︤" COMBINING MACRON LEFT HALF
/*<!dead_macron>*/	DEADTRANS(	L'k'	,0x0101	,0xFE25	,0x0000	), // "︥" COMBINING MACRON RIGHT HALF
/*<!dead_macron>*/	DEADTRANS(	L'L'	,0x0101	,0x22F6	,0x0000	), // "⋶" ELEMENT OF WITH OVERBAR
/*<!dead_macron>*/	DEADTRANS(	L'l'	,0x0101	,0x22F7	,0x0000	), // "⋷" SMALL ELEMENT OF WITH OVERBAR
/*<!dead_macron>*/	DEADTRANS(	L'M'	,0x0101	,0x22FD	,0x0000	), // "⋽" CONTAINS WITH OVERBAR
/*<!dead_macron>*/	DEADTRANS(	L'm'	,0x0101	,0x22FE	,0x0000	), // "⋾" SMALL CONTAINS WITH OVERBAR
/*<!dead_macron>*/	DEADTRANS(	L'O'	,0x0101	,0x014C	,0x0000	), // "Ō" LATIN CAPITAL LETTER O WITH MACRON
/*<!dead_macron>*/	DEADTRANS(	L'o'	,0x0101	,0x014D	,0x0000	), // "ō" LATIN SMALL LETTER O WITH MACRON
/*<!dead_macron>*/	DEADTRANS(	L'Q'	,0x0101	,0xFE24	,0x0000	), // "︤" COMBINING MACRON LEFT HALF
/*<!dead_macron>*/	DEADTRANS(	L'q'	,0x0101	,0xFE25	,0x0000	), // "︥" COMBINING MACRON RIGHT HALF
/*<!dead_macron>*/	DEADTRANS(	L'R'	,0x0101	,0x027A	,0x0000	), // "ɺ" LATIN SMALL LETTER TURNED R WITH LONG LEG
/*<!dead_macron>*/	DEADTRANS(	L'r'	,0x0101	,0x027C	,0x0000	), // "ɼ" LATIN SMALL LETTER R WITH LONG LEG
/*<!dead_macron>*/	DEADTRANS(	L'S'	,0x0101	,0x2A1B	,0x0000	), // "⨛" INTEGRAL WITH OVERBAR
/*<!dead_macron>*/	DEADTRANS(	L's'	,0x0101	,0x2A1B	,0x0000	), // "⨛" INTEGRAL WITH OVERBAR
/*<!dead_macron>*/	DEADTRANS(	L'T'	,0x0101	,0x2AE7	,0x0000	), // "⫧" SHORT DOWN TACK WITH OVERBAR
/*<!dead_macron>*/	DEADTRANS(	L't'	,0x0101	,0x2AE7	,0x0000	), // "⫧" SHORT DOWN TACK WITH OVERBAR
/*<!dead_macron>*/	DEADTRANS(	L'U'	,0x0101	,0x016A	,0x0000	), // "Ū" LATIN CAPITAL LETTER U WITH MACRON
/*<!dead_macron>*/	DEADTRANS(	L'u'	,0x0101	,0x016B	,0x0000	), // "ū" LATIN SMALL LETTER U WITH MACRON
/*<!dead_macron>*/	DEADTRANS(	L'V'	,0x0101	,0xFE24	,0x0000	), // "︤" COMBINING MACRON LEFT HALF
/*<!dead_macron>*/	DEADTRANS(	L'v'	,0x0101	,0xFE25	,0x0000	), // "︥" COMBINING MACRON RIGHT HALF
/*<!dead_macron>*/	DEADTRANS(	L'Y'	,0x0101	,0x0232	,0x0000	), // "Ȳ" LATIN CAPITAL LETTER Y WITH MACRON
/*<!dead_macron>*/	DEADTRANS(	L'y'	,0x0101	,0x0233	,0x0000	), // "ȳ" LATIN SMALL LETTER Y WITH MACRON
/*<!dead_macron>*/	DEADTRANS(	L'Z'	,0x0101	,0xFE24	,0x0000	), // "︤" COMBINING MACRON LEFT HALF
/*<!dead_macron>*/	DEADTRANS(	L'z'	,0x0101	,0xFE25	,0x0000	), // "︥" COMBINING MACRON RIGHT HALF
/*<!dead_macron>*/	DEADTRANS(	0x00A0	,0x0101	,0x00AF	,0x0000	), // "¯" MACRON
/*<!dead_macron>*/	DEADTRANS(	0x202F	,0x0101	,0x02C9	,0x0000	), // "ˉ" MODIFIER LETTER MACRON
/*<!dead_macron>*/	DEADTRANS(	L' '	,0x0101	,0x0304	,0x0000	), // "̄" COMBINING MACRON
/*<!dead_macron>*/	DEADTRANS(	0x200B	,0x0101	,0x0304	,0x0000	), // "̄" COMBINING MACRON
/*<!dead_ogonek>*/	DEADTRANS(	0x1EBB	,0x01EB	,0x20E3	,0x0000	), // "⃣" COMBINING ENCLOSING KEYCAP
/*<!dead_ogonek>*/	DEADTRANS(	L'0'	,0x01EB	,0x2789	,0x0000	), // "➉" DINGBAT CIRCLED SANS-SERIF NUMBER TEN
/*<!dead_ogonek>*/	DEADTRANS(	L'1'	,0x01EB	,0x2780	,0x0000	), // "➀" DINGBAT CIRCLED SANS-SERIF DIGIT ONE
/*<!dead_ogonek>*/	DEADTRANS(	L'2'	,0x01EB	,0x2781	,0x0000	), // "➁" DINGBAT CIRCLED SANS-SERIF DIGIT TWO
/*<!dead_ogonek>*/	DEADTRANS(	L'3'	,0x01EB	,0x2782	,0x0000	), // "➂" DINGBAT CIRCLED SANS-SERIF DIGIT THREE
/*<!dead_ogonek>*/	DEADTRANS(	L'4'	,0x01EB	,0x2783	,0x0000	), // "➃" DINGBAT CIRCLED SANS-SERIF DIGIT FOUR
/*<!dead_ogonek>*/	DEADTRANS(	L'5'	,0x01EB	,0x2784	,0x0000	), // "➄" DINGBAT CIRCLED SANS-SERIF DIGIT FIVE
/*<!dead_ogonek>*/	DEADTRANS(	L'6'	,0x01EB	,0x2785	,0x0000	), // "➅" DINGBAT CIRCLED SANS-SERIF DIGIT SIX
/*<!dead_ogonek>*/	DEADTRANS(	L'7'	,0x01EB	,0x2786	,0x0000	), // "➆" DINGBAT CIRCLED SANS-SERIF DIGIT SEVEN
/*<!dead_ogonek>*/	DEADTRANS(	L'8'	,0x01EB	,0x2787	,0x0000	), // "➇" DINGBAT CIRCLED SANS-SERIF DIGIT EIGHT
/*<!dead_ogonek>*/	DEADTRANS(	L'9'	,0x01EB	,0x2788	,0x0000	), // "➈" DINGBAT CIRCLED SANS-SERIF DIGIT NINE
/*<!dead_ogonek>*/	DEADTRANS(	L'A'	,0x01EB	,0x0104	,0x0000	), // "Ą" LATIN CAPITAL LETTER A WITH OGONEK
/*<!dead_ogonek>*/	DEADTRANS(	L'a'	,0x01EB	,0x0105	,0x0000	), // "ą" LATIN SMALL LETTER A WITH OGONEK
/*<!dead_ogonek>*/	DEADTRANS(	L'E'	,0x01EB	,0x0118	,0x0000	), // "Ę" LATIN CAPITAL LETTER E WITH OGONEK
/*<!dead_ogonek>*/	DEADTRANS(	L'e'	,0x01EB	,0x0119	,0x0000	), // "ę" LATIN SMALL LETTER E WITH OGONEK
/*<!dead_ogonek>*/	DEADTRANS(	L'I'	,0x01EB	,0x012E	,0x0000	), // "Į" LATIN CAPITAL LETTER I WITH OGONEK
/*<!dead_ogonek>*/	DEADTRANS(	L'i'	,0x01EB	,0x012F	,0x0000	), // "į" LATIN SMALL LETTER I WITH OGONEK
/*<!dead_ogonek>*/	DEADTRANS(	L'O'	,0x01EB	,0x01EA	,0x0000	), // "Ǫ" LATIN CAPITAL LETTER O WITH OGONEK
/*<!dead_ogonek>*/	DEADTRANS(	L'o'	,0x01EB	,0x01EB	,0x0000	), // "ǫ" LATIN SMALL LETTER O WITH OGONEK
/*<!dead_ogonek>*/	DEADTRANS(	L'U'	,0x01EB	,0x0172	,0x0000	), // "Ų" LATIN CAPITAL LETTER U WITH OGONEK
/*<!dead_ogonek>*/	DEADTRANS(	L'u'	,0x01EB	,0x0173	,0x0000	), // "ų" LATIN SMALL LETTER U WITH OGONEK
/*<!dead_ogonek>*/	DEADTRANS(	0x00A0	,0x01EB	,0x02DB	,0x0000	), // "˛" OGONEK
/*<!dead_ogonek>*/	DEADTRANS(	0x202F	,0x01EB	,0x02DB	,0x0000	), // "˛" OGONEK
/*<!dead_ogonek>*/	DEADTRANS(	L' '	,0x01EB	,0x0328	,0x0000	), // "̨" COMBINING OGONEK
/*<!dead_ogonek>*/	DEADTRANS(	0x200B	,0x01EB	,0x0328	,0x0000	), // "̨" COMBINING OGONEK
/*<!dead_retroflexhook>*/	DEADTRANS(	L'!'	,0x0273	,0xDF0A	,0x0000	), // High surrogate: D837; U+1DF0A "𝼊" LATIN LETTER RETROFLEX CLICK WITH RETROFLEX HOOK
/*<!dead_retroflexhook>*/	DEADTRANS(	L'0'	,0x0273	,0x2672	,0x0000	), // "♲" UNIVERSAL RECYCLING SYMBOL
/*<!dead_retroflexhook>*/	DEADTRANS(	L'1'	,0x0273	,0x2673	,0x0000	), // "♳" RECYCLING SYMBOL FOR TYPE-1 PLASTICS
/*<!dead_retroflexhook>*/	DEADTRANS(	L'2'	,0x0273	,0x2674	,0x0000	), // "♴" RECYCLING SYMBOL FOR TYPE-2 PLASTICS
/*<!dead_retroflexhook>*/	DEADTRANS(	L'3'	,0x0273	,0x2675	,0x0000	), // "♵" RECYCLING SYMBOL FOR TYPE-3 PLASTICS
/*<!dead_retroflexhook>*/	DEADTRANS(	L'4'	,0x0273	,0x2676	,0x0000	), // "♶" RECYCLING SYMBOL FOR TYPE-4 PLASTICS
/*<!dead_retroflexhook>*/	DEADTRANS(	L'5'	,0x0273	,0x2677	,0x0000	), // "♷" RECYCLING SYMBOL FOR TYPE-5 PLASTICS
/*<!dead_retroflexhook>*/	DEADTRANS(	L'6'	,0x0273	,0x2678	,0x0000	), // "♸" RECYCLING SYMBOL FOR TYPE-6 PLASTICS
/*<!dead_retroflexhook>*/	DEADTRANS(	L'7'	,0x0273	,0x2679	,0x0000	), // "♹" RECYCLING SYMBOL FOR TYPE-7 PLASTICS
/*<!dead_retroflexhook>*/	DEADTRANS(	L'8'	,0x0273	,0x267A	,0x0000	), // "♺" RECYCLING SYMBOL FOR GENERIC MATERIALS
/*<!dead_retroflexhook>*/	DEADTRANS(	L'9'	,0x0273	,0x267B	,0x0000	), // "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!dead_retroflexhook>*/	DEADTRANS(	L'a'	,0x0273	,0x1D8F	,0x0000	), // "ᶏ" LATIN SMALL LETTER A WITH RETROFLEX HOOK
/*<!dead_retroflexhook>*/	DEADTRANS(	L'c'	,0x0273	,0xDF1D	,0x0000	), // High surrogate: D837; U+1DF1D "𝼝" LATIN SMALL LETTER C WITH RETROFLEX HOOK
/*<!dead_retroflexhook>*/	DEADTRANS(	L'D'	,0x0273	,0x0189	,0x0000	), // "Ɖ" LATIN CAPITAL LETTER AFRICAN D
/*<!dead_retroflexhook>*/	DEADTRANS(	L'd'	,0x0273	,0x0256	,0x0000	), // "ɖ" LATIN SMALL LETTER D WITH TAIL
/*<!dead_retroflexhook>*/	DEADTRANS(	L'e'	,0x0273	,0x1D92	,0x0000	), // "ᶒ" LATIN SMALL LETTER E WITH RETROFLEX HOOK
/*<!dead_retroflexhook>*/	DEADTRANS(	L'i'	,0x0273	,0x1D96	,0x0000	), // "ᶖ" LATIN SMALL LETTER I WITH RETROFLEX HOOK
/*<!dead_retroflexhook>*/	DEADTRANS(	L'l'	,0x0273	,0x026D	,0x0000	), // "ɭ" LATIN SMALL LETTER L WITH RETROFLEX HOOK
/*<!dead_retroflexhook>*/	DEADTRANS(	L'n'	,0x0273	,0x0273	,0x0000	), // "ɳ" LATIN SMALL LETTER N WITH RETROFLEX HOOK
/*<!dead_retroflexhook>*/	DEADTRANS(	L'o'	,0x0273	,0xDF1B	,0x0000	), // High surrogate: D837; U+1DF1B "𝼛" LATIN SMALL LETTER O WITH RETROFLEX HOOK
/*<!dead_retroflexhook>*/	DEADTRANS(	L'P'	,0x0273	,0xA754	,0x0000	), // "Ꝕ" LATIN CAPITAL LETTER P WITH SQUIRREL TAIL
/*<!dead_retroflexhook>*/	DEADTRANS(	L'p'	,0x0273	,0xA755	,0x0000	), // "ꝕ" LATIN SMALL LETTER P WITH SQUIRREL TAIL
/*<!dead_retroflexhook>*/	DEADTRANS(	L'Q'	,0x0273	,0x024A	,0x0000	), // "Ɋ" LATIN CAPITAL LETTER SMALL Q WITH HOOK TAIL
/*<!dead_retroflexhook>*/	DEADTRANS(	L'q'	,0x0273	,0x024B	,0x0000	), // "ɋ" LATIN SMALL LETTER Q WITH HOOK TAIL
/*<!dead_retroflexhook>*/	DEADTRANS(	L'r'	,0x0273	,0x027D	,0x0000	), // "ɽ" LATIN SMALL LETTER R WITH TAIL
/*<!dead_retroflexhook>*/	DEADTRANS(	L'R'	,0x0273	,0x2C64	,0x0000	), // "Ɽ" LATIN CAPITAL LETTER R WITH TAIL
/*<!dead_retroflexhook>*/	DEADTRANS(	L's'	,0x0273	,0x0282	,0x0000	), // "ʂ" LATIN SMALL LETTER S WITH HOOK
/*<!dead_retroflexhook>*/	DEADTRANS(	L'T'	,0x0273	,0x01AE	,0x0000	), // "Ʈ" LATIN CAPITAL LETTER T WITH RETROFLEX HOOK
/*<!dead_retroflexhook>*/	DEADTRANS(	L't'	,0x0273	,0x0288	,0x0000	), // "ʈ" LATIN SMALL LETTER T WITH RETROFLEX HOOK
/*<!dead_retroflexhook>*/	DEADTRANS(	L'u'	,0x0273	,0x1D99	,0x0000	), // "ᶙ" LATIN SMALL LETTER U WITH RETROFLEX HOOK
/*<!dead_retroflexhook>*/	DEADTRANS(	L'v'	,0x0273	,0x2C71	,0x0000	), // "ⱱ" LATIN SMALL LETTER V WITH RIGHT HOOK
/*<!dead_retroflexhook>*/	DEADTRANS(	L'z'	,0x0273	,0x0290	,0x0000	), // "ʐ" LATIN SMALL LETTER Z WITH RETROFLEX HOOK
/*<!dead_retroflexhook>*/	DEADTRANS(	0x00A0	,0x0273	,0x02FE	,0x0000	), // "˾" MODIFIER LETTER OPEN SHELF
/*<!dead_retroflexhook>*/	DEADTRANS(	0x202F	,0x0273	,0x02FE	,0x0000	), // "˾" MODIFIER LETTER OPEN SHELF
/*<!dead_retroflexhook>*/	DEADTRANS(	L' '	,0x0273	,0x0322	,0x0000	), // "̢" COMBINING RETROFLEX HOOK BELOW
/*<!dead_retroflexhook>*/	DEADTRANS(	0x200B	,0x0273	,0x0322	,0x0000	), // "̢" COMBINING RETROFLEX HOOK BELOW
/*<!dead_reversed>*/	DEADTRANS(	L'\''	,0x019E	,0x02BD	,0x0000	), // "ʽ" MODIFIER LETTER REVERSED COMMA
/*<!dead_reversed>*/	DEADTRANS(	0x2019	,0x019E	,0x02BD	,0x0000	), // "ʽ" MODIFIER LETTER REVERSED COMMA
/*<!dead_reversed>*/	DEADTRANS(	L'~'	,0x019E	,0x223D	,0x0000	), // "∽" REVERSED TILDE
/*<!dead_reversed>*/	DEADTRANS(	L'}'	,0x019E	,0x29B0	,0x0000	), // "⦰" REVERSED EMPTY SET
/*<!dead_reversed>*/	DEADTRANS(	L','	,0x019E	,0x2E41	,0x0000	), // "⹁" REVERSED COMMA
/*<!dead_reversed>*/	DEADTRANS(	L'='	,0x019E	,0x22CD	,0x0000	), // "⋍" REVERSED TILDE EQUALS
/*<!dead_reversed>*/	DEADTRANS(	L'`'	,0x019E	,0x2310	,0x0000	), // "⌐" REVERSED NOT SIGN
/*<!dead_reversed>*/	DEADTRANS(	L'?'	,0x019E	,0x2E2E	,0x0000	), // "⸮" REVERSED QUESTION MARK
/*<!dead_reversed>*/	DEADTRANS(	L';'	,0x019E	,0x204F	,0x0000	), // "⁏" REVERSED SEMICOLON
/*<!dead_reversed>*/	DEADTRANS(	0x00A7	,0x019E	,0x204F	,0x0000	), // "⁏" REVERSED SEMICOLON
/*<!dead_reversed>*/	DEADTRANS(	L'_'	,0x019E	,0x2B88	,0x0000	), // "⮈" LEFTWARDS BLACK CIRCLED WHITE ARROW
/*<!dead_reversed>*/	DEADTRANS(	L'1'	,0x019E	,0x2216	,0x0000	), // "∖" SET MINUS
/*<!dead_reversed>*/	DEADTRANS(	L'2'	,0x019E	,0x29F9	,0x0000	), // "⧹" BIG REVERSE SOLIDUS
/*<!dead_reversed>*/	DEADTRANS(	L'3'	,0x019E	,0x27CD	,0x0000	), // "⟍" MATHEMATICAL FALLING DIAGONAL
/*<!dead_reversed>*/	DEADTRANS(	L'4'	,0x019E	,0x29F5	,0x0000	), // "⧵" REVERSE SOLIDUS OPERATOR
/*<!dead_reversed>*/	DEADTRANS(	L'B'	,0x019E	,0x204D	,0x0000	), // "⁍" BLACK RIGHTWARDS BULLET
/*<!dead_reversed>*/	DEADTRANS(	L'b'	,0x019E	,0x204D	,0x0000	), // "⁍" BLACK RIGHTWARDS BULLET
/*<!dead_reversed>*/	DEADTRANS(	L'C'	,0x019E	,0x2183	,0x0000	), // "Ↄ" ROMAN NUMERAL REVERSED ONE HUNDRED
/*<!dead_reversed>*/	DEADTRANS(	L'c'	,0x019E	,0x2184	,0x0000	), // "ↄ" LATIN SMALL LETTER REVERSED C
/*<!dead_reversed>*/	DEADTRANS(	L'D'	,0x019E	,0x204C	,0x0000	), // "⁌" BLACK LEFTWARDS BULLET
/*<!dead_reversed>*/	DEADTRANS(	L'd'	,0x019E	,0x204C	,0x0000	), // "⁌" BLACK LEFTWARDS BULLET
/*<!dead_reversed>*/	DEADTRANS(	L'E'	,0x019E	,0x018E	,0x0000	), // "Ǝ" LATIN CAPITAL LETTER REVERSED E
/*<!dead_reversed>*/	DEADTRANS(	L'e'	,0x019E	,0x0258	,0x0000	), // "ɘ" LATIN SMALL LETTER REVERSED E
/*<!dead_reversed>*/	DEADTRANS(	L'F'	,0x019E	,0xA7FB	,0x0000	), // "ꟻ" LATIN EPIGRAPHIC LETTER REVERSED F
/*<!dead_reversed>*/	DEADTRANS(	L'g'	,0x019E	,0xDF01	,0x0000	), // High surrogate: D837; U+1DF01 "𝼁" LATIN SMALL LETTER REVERSED SCRIPT G
/*<!dead_reversed>*/	DEADTRANS(	L'H'	,0x019E	,0xA7F5	,0x0000	), // "Ꟶ" LATIN CAPITAL LETTER REVERSED HALF H
/*<!dead_reversed>*/	DEADTRANS(	L'h'	,0x019E	,0xA7F6	,0x0000	), // "ꟶ" LATIN SMALL LETTER REVERSED HALF H
/*<!dead_reversed>*/	DEADTRANS(	L'k'	,0x019E	,0xDF03	,0x0000	), // High surrogate: D837; U+1DF03 "𝼃" LATIN SMALL LETTER REVERSED K
/*<!dead_reversed>*/	DEADTRANS(	L'L'	,0x019E	,0x2143	,0x0000	), // "⅃" REVERSED SANS-SERIF CAPITAL L
/*<!dead_reversed>*/	DEADTRANS(	L'N'	,0x019E	,0x1D0E	,0x0000	), // "ᴎ" LATIN LETTER SMALL CAPITAL REVERSED N
/*<!dead_reversed>*/	DEADTRANS(	L'n'	,0x019E	,0xDF07	,0x0000	), // High surrogate: D837; U+1DF07 "𝼇" LATIN SMALL LETTER REVERSED ENG
/*<!dead_reversed>*/	DEADTRANS(	L'o'	,0x019E	,0xAB43	,0x0000	), // "ꭃ" LATIN SMALL LETTER TURNED O OPEN-O
/*<!dead_reversed>*/	DEADTRANS(	L'p'	,0x019E	,0x204B	,0x0000	), // "⁋" REVERSED PILCROW SIGN
/*<!dead_reversed>*/	DEADTRANS(	L'P'	,0x019E	,0xA7FC	,0x0000	), // "ꟼ" LATIN EPIGRAPHIC LETTER REVERSED P
/*<!dead_reversed>*/	DEADTRANS(	0x00A7	,0x019E	,0x204B	,0x0000	), // "⁋" REVERSED PILCROW SIGN
/*<!dead_reversed>*/	DEADTRANS(	L'q'	,0x019E	,0x0295	,0x0000	), // "ʕ" LATIN LETTER PHARYNGEAL VOICED FRICATIVE
/*<!dead_reversed>*/	DEADTRANS(	L'Q'	,0x019E	,0x02A2	,0x0000	), // "ʢ" LATIN LETTER REVERSED GLOTTAL STOP WITH STROKE
/*<!dead_reversed>*/	DEADTRANS(	L'r'	,0x019E	,0x027F	,0x0000	), // "ɿ" LATIN SMALL LETTER REVERSED R WITH FISHHOOK
/*<!dead_reversed>*/	DEADTRANS(	L'R'	,0x019E	,0x1D19	,0x0000	), // "ᴙ" LATIN LETTER SMALL CAPITAL REVERSED R
/*<!dead_reversed>*/	DEADTRANS(	L'S'	,0x019E	,0x01AA	,0x0000	), // "ƪ" LATIN LETTER REVERSED ESH LOOP
/*<!dead_reversed>*/	DEADTRANS(	L's'	,0x019E	,0x0285	,0x0000	), // "ʅ" LATIN SMALL LETTER SQUAT REVERSED ESH
/*<!dead_reversed>*/	DEADTRANS(	L'x'	,0x019E	,0x025C	,0x0000	), // "ɜ" LATIN SMALL LETTER REVERSED OPEN E
/*<!dead_reversed>*/	DEADTRANS(	L'X'	,0x019E	,0xA7AB	,0x0000	), // "Ɜ" LATIN CAPITAL LETTER REVERSED OPEN E
/*<!dead_reversed>*/	DEADTRANS(	L'Z'	,0x019E	,0x01B8	,0x0000	), // "Ƹ" LATIN CAPITAL LETTER EZH REVERSED
/*<!dead_reversed>*/	DEADTRANS(	L'z'	,0x019E	,0x01B9	,0x0000	), // "ƹ" LATIN SMALL LETTER EZH REVERSED
/*<!dead_reversed>*/	DEADTRANS(	0x00A0	,0x019E	,0x02BD	,0x0000	), // "ʽ" MODIFIER LETTER REVERSED COMMA
/*<!dead_reversed>*/	DEADTRANS(	0x202F	,0x019E	,0x02BD	,0x0000	), // "ʽ" MODIFIER LETTER REVERSED COMMA
/*<!dead_reversed>*/	DEADTRANS(	L' '	,0x019E	,0x0314	,0x0000	), // "̔" COMBINING REVERSED COMMA ABOVE
/*<!dead_reversed>*/	DEADTRANS(	0x200B	,0x019E	,0x0314	,0x0000	), // "̔" COMBINING REVERSED COMMA ABOVE
/*<!dead_stroke>*/	DEADTRANS(	L'^'	,0x00F8	,0xDFA2	,0x0000	), // High surrogate: D801; U+107A2 "𐞢" MODIFIER LETTER SMALL O WITH STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'|'	,0x00F8	,0x2224	,0x0000	), // "∤" DOES NOT DIVIDE
/*<!dead_stroke>*/	DEADTRANS(	L'='	,0x00F8	,0x2260	,0x0000	), // "≠" NOT EQUAL TO
/*<!dead_stroke>*/	DEADTRANS(	L'>'	,0x00F8	,0x226F	,0x0000	), // "≯" NOT GREATER-THAN
/*<!dead_stroke>*/	DEADTRANS(	L'<'	,0x00F8	,0x226E	,0x0000	), // "≮" NOT LESS-THAN
/*<!dead_stroke>*/	DEADTRANS(	L'"'	,0x00F8	,0x2204	,0x0000	), // "∄" THERE DOES NOT EXIST
/*<!dead_stroke>*/	DEADTRANS(	0x20AC	,0x00F8	,0x2204	,0x0000	), // "∄" THERE DOES NOT EXIST
/*<!dead_stroke>*/	DEADTRANS(	L'1'	,0x00F8	,0x2215	,0x0000	), // "∕" DIVISION SLASH
/*<!dead_stroke>*/	DEADTRANS(	L'2'	,0x00F8	,0x29F8	,0x0000	), // "⧸" BIG SOLIDUS
/*<!dead_stroke>*/	DEADTRANS(	L'3'	,0x00F8	,0x27CB	,0x0000	), // "⟋" MATHEMATICAL RISING DIAGONAL
/*<!dead_stroke>*/	DEADTRANS(	L'4'	,0x00F8	,0x2044	,0x0000	), // "⁄" FRACTION SLASH
/*<!dead_stroke>*/	DEADTRANS(	L'A'	,0x00F8	,0x023A	,0x0000	), // "Ⱥ" LATIN CAPITAL LETTER A WITH STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'a'	,0x00F8	,0x2C65	,0x0000	), // "ⱥ" LATIN SMALL LETTER A WITH STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'b'	,0x00F8	,0x0180	,0x0000	), // "ƀ" LATIN SMALL LETTER B WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'B'	,0x00F8	,0x0243	,0x0000	), // "Ƀ" LATIN CAPITAL LETTER B WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'C'	,0x00F8	,0x023B	,0x0000	), // "Ȼ" LATIN CAPITAL LETTER C WITH STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'c'	,0x00F8	,0x023C	,0x0000	), // "ȼ" LATIN SMALL LETTER C WITH STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'D'	,0x00F8	,0x0110	,0x0000	), // "Đ" LATIN CAPITAL LETTER D WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'd'	,0x00F8	,0x0111	,0x0000	), // "đ" LATIN SMALL LETTER D WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'E'	,0x00F8	,0x0246	,0x0000	), // "Ɇ" LATIN CAPITAL LETTER E WITH STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'e'	,0x00F8	,0x0247	,0x0000	), // "ɇ" LATIN SMALL LETTER E WITH STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'F'	,0x00F8	,0xA798	,0x0000	), // "Ꞙ" LATIN CAPITAL LETTER F WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'f'	,0x00F8	,0xA799	,0x0000	), // "ꞙ" LATIN SMALL LETTER F WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'G'	,0x00F8	,0xA7A0	,0x0000	), // "Ꞡ" LATIN CAPITAL LETTER G WITH OBLIQUE STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'g'	,0x00F8	,0xA7A1	,0x0000	), // "ꞡ" LATIN SMALL LETTER G WITH OBLIQUE STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'H'	,0x00F8	,0x0126	,0x0000	), // "Ħ" LATIN CAPITAL LETTER H WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'h'	,0x00F8	,0x0127	,0x0000	), // "ħ" LATIN SMALL LETTER H WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'I'	,0x00F8	,0x0197	,0x0000	), // "Ɨ" LATIN CAPITAL LETTER I WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'i'	,0x00F8	,0x0268	,0x0000	), // "ɨ" LATIN SMALL LETTER I WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'J'	,0x00F8	,0x0248	,0x0000	), // "Ɉ" LATIN CAPITAL LETTER J WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'j'	,0x00F8	,0x0249	,0x0000	), // "ɉ" LATIN SMALL LETTER J WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'K'	,0x00F8	,0xA742	,0x0000	), // "Ꝃ" LATIN CAPITAL LETTER K WITH DIAGONAL STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'k'	,0x00F8	,0xA743	,0x0000	), // "ꝃ" LATIN SMALL LETTER K WITH DIAGONAL STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'L'	,0x00F8	,0x0141	,0x0000	), // "Ł" LATIN CAPITAL LETTER L WITH STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'l'	,0x00F8	,0x0142	,0x0000	), // "ł" LATIN SMALL LETTER L WITH STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'N'	,0x00F8	,0xA7A4	,0x0000	), // "Ꞥ" LATIN CAPITAL LETTER N WITH OBLIQUE STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'n'	,0x00F8	,0xA7A5	,0x0000	), // "ꞥ" LATIN SMALL LETTER N WITH OBLIQUE STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'O'	,0x00F8	,0x00D8	,0x0000	), // "Ø" LATIN CAPITAL LETTER O WITH STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'o'	,0x00F8	,0x00F8	,0x0000	), // "ø" LATIN SMALL LETTER O WITH STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'p'	,0x00F8	,0x1D7D	,0x0000	), // "ᵽ" LATIN SMALL LETTER P WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'P'	,0x00F8	,0x2C63	,0x0000	), // "Ᵽ" LATIN CAPITAL LETTER P WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'Q'	,0x00F8	,0xA758	,0x0000	), // "Ꝙ" LATIN CAPITAL LETTER Q WITH DIAGONAL STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'q'	,0x00F8	,0xA759	,0x0000	), // "ꝙ" LATIN SMALL LETTER Q WITH DIAGONAL STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'R'	,0x00F8	,0xA7A6	,0x0000	), // "Ꞧ" LATIN CAPITAL LETTER R WITH OBLIQUE STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'r'	,0x00F8	,0xA7A7	,0x0000	), // "ꞧ" LATIN SMALL LETTER R WITH OBLIQUE STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'S'	,0x00F8	,0xA7CC	,0x0000	), // "Ꟍ" LATIN CAPITAL LETTER S WITH DIAGONAL STROKE
/*<!dead_stroke>*/	DEADTRANS(	L's'	,0x00F8	,0xA7CD	,0x0000	), // "ꟍ" LATIN SMALL LETTER S WITH DIAGONAL STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'T'	,0x00F8	,0x023E	,0x0000	), // "Ⱦ" LATIN CAPITAL LETTER T WITH DIAGONAL STROKE
/*<!dead_stroke>*/	DEADTRANS(	L't'	,0x00F8	,0x2C66	,0x0000	), // "ⱦ" LATIN SMALL LETTER T WITH DIAGONAL STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'U'	,0x00F8	,0xA7B8	,0x0000	), // "Ꞹ" LATIN CAPITAL LETTER U WITH STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'u'	,0x00F8	,0xA7B9	,0x0000	), // "ꞹ" LATIN SMALL LETTER U WITH STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'V'	,0x00F8	,0xA75E	,0x0000	), // "Ꝟ" LATIN CAPITAL LETTER V WITH DIAGONAL STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'v'	,0x00F8	,0xA75F	,0x0000	), // "ꝟ" LATIN SMALL LETTER V WITH DIAGONAL STROKE
/*<!dead_stroke>*/	DEADTRANS(	L'Y'	,0x00F8	,0x024E	,0x0000	), // "Ɏ" LATIN CAPITAL LETTER Y WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'y'	,0x00F8	,0x024F	,0x0000	), // "ɏ" LATIN SMALL LETTER Y WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'Z'	,0x00F8	,0x01B5	,0x0000	), // "Ƶ" LATIN CAPITAL LETTER Z WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	L'z'	,0x00F8	,0x01B6	,0x0000	), // "ƶ" LATIN SMALL LETTER Z WITH STROKE (lenient)
/*<!dead_stroke>*/	DEADTRANS(	0x00A0	,0x00F8	,0x2215	,0x0000	), // "∕" DIVISION SLASH
/*<!dead_stroke>*/	DEADTRANS(	0x202F	,0x00F8	,0x2215	,0x0000	), // "∕" DIVISION SLASH
/*<!dead_stroke>*/	DEADTRANS(	L' '	,0x00F8	,0x0338	,0x0000	), // "̸" COMBINING LONG SOLIDUS OVERLAY
/*<!dead_stroke>*/	DEADTRANS(	0x200B	,0x00F8	,0x0338	,0x0000	), // "̸" COMBINING LONG SOLIDUS OVERLAY
/*<!dead_subscript>*/	DEADTRANS(	L'='	,L'_'	,0x208C	,0x0000	), // "₌" SUBSCRIPT EQUALS SIGN
/*<!dead_subscript>*/	DEADTRANS(	L'-'	,L'_'	,0x208B	,0x0000	), // "₋" SUBSCRIPT MINUS
/*<!dead_subscript>*/	DEADTRANS(	L'('	,L'_'	,0x208D	,0x0000	), // "₍" SUBSCRIPT LEFT PARENTHESIS
/*<!dead_subscript>*/	DEADTRANS(	L')'	,L'_'	,0x208E	,0x0000	), // "₎" SUBSCRIPT RIGHT PARENTHESIS
/*<!dead_subscript>*/	DEADTRANS(	L'+'	,L'_'	,0x208A	,0x0000	), // "₊" SUBSCRIPT PLUS SIGN
/*<!dead_subscript>*/	DEADTRANS(	L'0'	,L'_'	,0x2080	,0x0000	), // "₀" SUBSCRIPT ZERO
/*<!dead_subscript>*/	DEADTRANS(	L'1'	,L'_'	,0x2081	,0x0000	), // "₁" SUBSCRIPT ONE
/*<!dead_subscript>*/	DEADTRANS(	L'2'	,L'_'	,0x2082	,0x0000	), // "₂" SUBSCRIPT TWO
/*<!dead_subscript>*/	DEADTRANS(	L'3'	,L'_'	,0x2083	,0x0000	), // "₃" SUBSCRIPT THREE
/*<!dead_subscript>*/	DEADTRANS(	L'4'	,L'_'	,0x2084	,0x0000	), // "₄" SUBSCRIPT FOUR
/*<!dead_subscript>*/	DEADTRANS(	L'5'	,L'_'	,0x2085	,0x0000	), // "₅" SUBSCRIPT FIVE
/*<!dead_subscript>*/	DEADTRANS(	L'6'	,L'_'	,0x2086	,0x0000	), // "₆" SUBSCRIPT SIX
/*<!dead_subscript>*/	DEADTRANS(	L'7'	,L'_'	,0x2087	,0x0000	), // "₇" SUBSCRIPT SEVEN
/*<!dead_subscript>*/	DEADTRANS(	L'8'	,L'_'	,0x2088	,0x0000	), // "₈" SUBSCRIPT EIGHT
/*<!dead_subscript>*/	DEADTRANS(	L'9'	,L'_'	,0x2089	,0x0000	), // "₉" SUBSCRIPT NINE
/*<!dead_subscript>*/	DEADTRANS(	L'A'	,L'_'	,0x1D00	,0x0000	), // "ᴀ" LATIN LETTER SMALL CAPITAL A
/*<!dead_subscript>*/	DEADTRANS(	L'a'	,L'_'	,0x2090	,0x0000	), // "ₐ" LATIN SUBSCRIPT SMALL LETTER A
/*<!dead_subscript>*/	DEADTRANS(	L'B'	,L'_'	,0x0299	,0x0000	), // "ʙ" LATIN LETTER SMALL CAPITAL B
/*<!dead_subscript>*/	DEADTRANS(	L'b'	,L'_'	,0x1D66	,0x0000	), // "ᵦ" GREEK SUBSCRIPT SMALL LETTER BETA
/*<!dead_subscript>*/	DEADTRANS(	L'C'	,L'_'	,0x1D04	,0x0000	), // "ᴄ" LATIN LETTER SMALL CAPITAL C
/*<!dead_subscript>*/	DEADTRANS(	L'c'	,L'_'	,0x1D28	,0x0000	), // "ᴨ" GREEK LETTER SMALL CAPITAL PI
/*<!dead_subscript>*/	DEADTRANS(	L'D'	,L'_'	,0x1D05	,0x0000	), // "ᴅ" LATIN LETTER SMALL CAPITAL D
/*<!dead_subscript>*/	DEADTRANS(	L'd'	,L'_'	,0x1D29	,0x0000	), // "ᴩ" GREEK LETTER SMALL CAPITAL RHO
/*<!dead_subscript>*/	DEADTRANS(	L'E'	,L'_'	,0x1D07	,0x0000	), // "ᴇ" LATIN LETTER SMALL CAPITAL E
/*<!dead_subscript>*/	DEADTRANS(	L'e'	,L'_'	,0x2091	,0x0000	), // "ₑ" LATIN SUBSCRIPT SMALL LETTER E
/*<!dead_subscript>*/	DEADTRANS(	0x2026	,L'_'	,0x20E8	,0x0000	), // "⃨" COMBINING TRIPLE UNDERDOT
/*<!dead_subscript>*/	DEADTRANS(	L'f'	,L'_'	,0x1D69	,0x0000	), // "ᵩ" GREEK SUBSCRIPT SMALL LETTER PHI
/*<!dead_subscript>*/	DEADTRANS(	L'F'	,L'_'	,0xA730	,0x0000	), // "ꜰ" LATIN LETTER SMALL CAPITAL F
/*<!dead_subscript>*/	DEADTRANS(	L'G'	,L'_'	,0x0262	,0x0000	), // "ɢ" LATIN LETTER SMALL CAPITAL G
/*<!dead_subscript>*/	DEADTRANS(	L'g'	,L'_'	,0x1D26	,0x0000	), // "ᴦ" GREEK LETTER SMALL CAPITAL GAMMA
/*<!dead_subscript>*/	DEADTRANS(	L'H'	,L'_'	,0x029C	,0x0000	), // "ʜ" LATIN LETTER SMALL CAPITAL H
/*<!dead_subscript>*/	DEADTRANS(	L'h'	,L'_'	,0x2095	,0x0000	), // "ₕ" LATIN SUBSCRIPT SMALL LETTER H
/*<!dead_subscript>*/	DEADTRANS(	L'I'	,L'_'	,0x026A	,0x0000	), // "ɪ" LATIN LETTER SMALL CAPITAL I
/*<!dead_subscript>*/	DEADTRANS(	L'i'	,L'_'	,0x1D62	,0x0000	), // "ᵢ" LATIN SUBSCRIPT SMALL LETTER I
/*<!dead_subscript>*/	DEADTRANS(	L'J'	,L'_'	,0x1D0A	,0x0000	), // "ᴊ" LATIN LETTER SMALL CAPITAL J
/*<!dead_subscript>*/	DEADTRANS(	L'j'	,L'_'	,0x2C7C	,0x0000	), // "ⱼ" LATIN SUBSCRIPT SMALL LETTER J
/*<!dead_subscript>*/	DEADTRANS(	L'K'	,L'_'	,0x1D0B	,0x0000	), // "ᴋ" LATIN LETTER SMALL CAPITAL K
/*<!dead_subscript>*/	DEADTRANS(	L'k'	,L'_'	,0x2096	,0x0000	), // "ₖ" LATIN SUBSCRIPT SMALL LETTER K
/*<!dead_subscript>*/	DEADTRANS(	L'L'	,L'_'	,0x029F	,0x0000	), // "ʟ" LATIN LETTER SMALL CAPITAL L
/*<!dead_subscript>*/	DEADTRANS(	L'l'	,L'_'	,0x2097	,0x0000	), // "ₗ" LATIN SUBSCRIPT SMALL LETTER L
/*<!dead_subscript>*/	DEADTRANS(	L'M'	,L'_'	,0x1D0D	,0x0000	), // "ᴍ" LATIN LETTER SMALL CAPITAL M
/*<!dead_subscript>*/	DEADTRANS(	L'm'	,L'_'	,0x2098	,0x0000	), // "ₘ" LATIN SUBSCRIPT SMALL LETTER M
/*<!dead_subscript>*/	DEADTRANS(	L'N'	,L'_'	,0x0274	,0x0000	), // "ɴ" LATIN LETTER SMALL CAPITAL N
/*<!dead_subscript>*/	DEADTRANS(	L'n'	,L'_'	,0x2099	,0x0000	), // "ₙ" LATIN SUBSCRIPT SMALL LETTER N
/*<!dead_subscript>*/	DEADTRANS(	L'O'	,L'_'	,0x1D0F	,0x0000	), // "ᴏ" LATIN LETTER SMALL CAPITAL O
/*<!dead_subscript>*/	DEADTRANS(	L'o'	,L'_'	,0x2092	,0x0000	), // "ₒ" LATIN SUBSCRIPT SMALL LETTER O
/*<!dead_subscript>*/	DEADTRANS(	L'P'	,L'_'	,0x1D18	,0x0000	), // "ᴘ" LATIN LETTER SMALL CAPITAL P
/*<!dead_subscript>*/	DEADTRANS(	L'p'	,L'_'	,0x209A	,0x0000	), // "ₚ" LATIN SUBSCRIPT SMALL LETTER P
/*<!dead_subscript>*/	DEADTRANS(	L'q'	,L'_'	,0x1D68	,0x0000	), // "ᵨ" GREEK SUBSCRIPT SMALL LETTER RHO
/*<!dead_subscript>*/	DEADTRANS(	L'Q'	,L'_'	,0xA7AF	,0x0000	), // "ꞯ" LATIN LETTER SMALL CAPITAL Q
/*<!dead_subscript>*/	DEADTRANS(	L'R'	,L'_'	,0x0280	,0x0000	), // "ʀ" LATIN LETTER SMALL CAPITAL R
/*<!dead_subscript>*/	DEADTRANS(	L'r'	,L'_'	,0x1D63	,0x0000	), // "ᵣ" LATIN SUBSCRIPT SMALL LETTER R
/*<!dead_subscript>*/	DEADTRANS(	L's'	,L'_'	,0x209B	,0x0000	), // "ₛ" LATIN SUBSCRIPT SMALL LETTER S
/*<!dead_subscript>*/	DEADTRANS(	L'S'	,L'_'	,0xA731	,0x0000	), // "ꜱ" LATIN LETTER SMALL CAPITAL S
/*<!dead_subscript>*/	DEADTRANS(	L'T'	,L'_'	,0x1D1B	,0x0000	), // "ᴛ" LATIN LETTER SMALL CAPITAL T
/*<!dead_subscript>*/	DEADTRANS(	L't'	,L'_'	,0x209C	,0x0000	), // "ₜ" LATIN SUBSCRIPT SMALL LETTER T
/*<!dead_subscript>*/	DEADTRANS(	L'U'	,L'_'	,0x1D1C	,0x0000	), // "ᴜ" LATIN LETTER SMALL CAPITAL U
/*<!dead_subscript>*/	DEADTRANS(	L'u'	,L'_'	,0x1D64	,0x0000	), // "ᵤ" LATIN SUBSCRIPT SMALL LETTER U
/*<!dead_subscript>*/	DEADTRANS(	L'V'	,L'_'	,0x1D20	,0x0000	), // "ᴠ" LATIN LETTER SMALL CAPITAL V
/*<!dead_subscript>*/	DEADTRANS(	L'v'	,L'_'	,0x1D65	,0x0000	), // "ᵥ" LATIN SUBSCRIPT SMALL LETTER V
/*<!dead_subscript>*/	DEADTRANS(	L'W'	,L'_'	,0x1D21	,0x0000	), // "ᴡ" LATIN LETTER SMALL CAPITAL W
/*<!dead_subscript>*/	DEADTRANS(	L'w'	,L'_'	,0x1D27	,0x0000	), // "ᴧ" GREEK LETTER SMALL CAPITAL LAMDA
/*<!dead_subscript>*/	DEADTRANS(	L'X'	,L'_'	,0x1D6A	,0x0000	), // "ᵪ" GREEK SUBSCRIPT SMALL LETTER CHI
/*<!dead_subscript>*/	DEADTRANS(	L'x'	,L'_'	,0x2093	,0x0000	), // "ₓ" LATIN SUBSCRIPT SMALL LETTER X
/*<!dead_subscript>*/	DEADTRANS(	L'Y'	,L'_'	,0x028F	,0x0000	), // "ʏ" LATIN LETTER SMALL CAPITAL Y
/*<!dead_subscript>*/	DEADTRANS(	L'y'	,L'_'	,0x1D67	,0x0000	), // "ᵧ" GREEK SUBSCRIPT SMALL LETTER GAMMA
/*<!dead_subscript>*/	DEADTRANS(	L'Z'	,L'_'	,0x1D22	,0x0000	), // "ᴢ" LATIN LETTER SMALL CAPITAL Z
/*<!dead_subscript>*/	DEADTRANS(	L'z'	,L'_'	,0x1D2A	,0x0000	), // "ᴪ" GREEK LETTER SMALL CAPITAL PSI
/*<!dead_subscript>*/	DEADTRANS(	0x00A0	,L'_'	,0x005F	,0x0000	), // "_" LOW LINE
/*<!dead_subscript>*/	DEADTRANS(	0x202F	,L'_'	,0x005F	,0x0000	), // "_" LOW LINE
/*<!dead_subscript>*/	DEADTRANS(	L' '	,L'_'	,0x0332	,0x0000	), // "̲" COMBINING LOW LINE
/*<!dead_subscript>*/	DEADTRANS(	0x200B	,L'_'	,0x0332	,0x0000	), // "̲" COMBINING LOW LINE
/*<!dead_superscript>*/	DEADTRANS(	0x00F8	,L'^'	,0xDFA2	,0x0000	), // High surrogate: D801; U+107A2 "𐞢" MODIFIER LETTER SMALL O WITH STROKE
/*<!dead_superscript>*/	DEADTRANS(	L'\''	,L'^'	,0x2019	,0x0000	), // "’" RIGHT SINGLE QUOTATION MARK, single comma quotation mark
/*<!dead_superscript>*/	DEADTRANS(	0x2019	,L'^'	,0x2019	,0x0000	), // "’" RIGHT SINGLE QUOTATION MARK, single comma quotation mark
/*<!dead_superscript>*/	DEADTRANS(	L'*'	,L'^'	,0x2042	,0x0000	), // "⁂" ASTERISM
/*<!dead_superscript>*/	DEADTRANS(	L':'	,L'^'	,0x02F8	,0x0000	), // "˸" MODIFIER LETTER RAISED COLON
/*<!dead_superscript>*/	DEADTRANS(	L','	,L'^'	,0x02BC	,0x0000	), // "ʼ" MODIFIER LETTER APOSTROPHE
/*<!dead_superscript>*/	DEADTRANS(	L'='	,L'^'	,0x207C	,0x0000	), // "⁼" SUPERSCRIPT EQUALS SIGN
/*<!dead_superscript>*/	DEADTRANS(	L'!'	,L'^'	,0xA71D	,0x0000	), // "ꜝ" MODIFIER LETTER RAISED EXCLAMATION MARK
/*<!dead_superscript>*/	DEADTRANS(	L'>'	,L'^'	,0xA71C	,0x0000	), // "ꜜ" MODIFIER LETTER RAISED DOWN ARROW
/*<!dead_superscript>*/	DEADTRANS(	L'<'	,L'^'	,0xA71B	,0x0000	), // "ꜛ" MODIFIER LETTER RAISED UP ARROW
/*<!dead_superscript>*/	DEADTRANS(	L'-'	,L'^'	,0x207B	,0x0000	), // "⁻" SUPERSCRIPT MINUS
/*<!dead_superscript>*/	DEADTRANS(	L'('	,L'^'	,0x207D	,0x0000	), // "⁽" SUPERSCRIPT LEFT PARENTHESIS
/*<!dead_superscript>*/	DEADTRANS(	L')'	,L'^'	,0x207E	,0x0000	), // "⁾" SUPERSCRIPT RIGHT PARENTHESIS
/*<!dead_superscript>*/	DEADTRANS(	L'.'	,L'^'	,0x00B7	,0x0000	), // "·" MIDDLE DOT
/*<!dead_superscript>*/	DEADTRANS(	L'+'	,L'^'	,0x207A	,0x0000	), // "⁺" SUPERSCRIPT PLUS SIGN
/*<!dead_superscript>*/	DEADTRANS(	L'"'	,L'^'	,0x201D	,0x0000	), // "”" RIGHT DOUBLE QUOTATION MARK, double comma quotation mark
/*<!dead_superscript>*/	DEADTRANS(	0x20AC	,L'^'	,0x201D	,0x0000	), // "”" RIGHT DOUBLE QUOTATION MARK, double comma quotation mark
/*<!dead_superscript>*/	DEADTRANS(	L'0'	,L'^'	,0x2070	,0x0000	), // "⁰" SUPERSCRIPT ZERO
/*<!dead_superscript>*/	DEADTRANS(	L'1'	,L'^'	,0x00B9	,0x0000	), // "¹" SUPERSCRIPT ONE
/*<!dead_superscript>*/	DEADTRANS(	L'2'	,L'^'	,0x00B2	,0x0000	), // "²" SUPERSCRIPT TWO
/*<!dead_superscript>*/	DEADTRANS(	L'3'	,L'^'	,0x00B3	,0x0000	), // "³" SUPERSCRIPT THREE
/*<!dead_superscript>*/	DEADTRANS(	L'4'	,L'^'	,0x2074	,0x0000	), // "⁴" SUPERSCRIPT FOUR
/*<!dead_superscript>*/	DEADTRANS(	L'5'	,L'^'	,0x2075	,0x0000	), // "⁵" SUPERSCRIPT FIVE
/*<!dead_superscript>*/	DEADTRANS(	L'6'	,L'^'	,0x2076	,0x0000	), // "⁶" SUPERSCRIPT SIX
/*<!dead_superscript>*/	DEADTRANS(	L'7'	,L'^'	,0x2077	,0x0000	), // "⁷" SUPERSCRIPT SEVEN
/*<!dead_superscript>*/	DEADTRANS(	L'8'	,L'^'	,0x2078	,0x0000	), // "⁸" SUPERSCRIPT EIGHT
/*<!dead_superscript>*/	DEADTRANS(	L'9'	,L'^'	,0x2079	,0x0000	), // "⁹" SUPERSCRIPT NINE
/*<!dead_superscript>*/	DEADTRANS(	L'A'	,L'^'	,0x1D2C	,0x0000	), // "ᴬ" MODIFIER LETTER CAPITAL A
/*<!dead_superscript>*/	DEADTRANS(	L'a'	,L'^'	,0x1D43	,0x0000	), // "ᵃ" MODIFIER LETTER SMALL A
/*<!dead_superscript>*/	DEADTRANS(	L'B'	,L'^'	,0x1D2E	,0x0000	), // "ᴮ" MODIFIER LETTER CAPITAL B
/*<!dead_superscript>*/	DEADTRANS(	L'b'	,L'^'	,0x1D47	,0x0000	), // "ᵇ" MODIFIER LETTER SMALL B
/*<!dead_superscript>*/	DEADTRANS(	L'c'	,L'^'	,0x1D9C	,0x0000	), // "ᶜ" MODIFIER LETTER SMALL C
/*<!dead_superscript>*/	DEADTRANS(	L'C'	,L'^'	,0xA7F2	,0x0000	), // "ꟲ" MODIFIER LETTER CAPITAL C: Chatino (Oaxaca, Mexico)
/*<!dead_superscript>*/	DEADTRANS(	L'D'	,L'^'	,0x1D30	,0x0000	), // "ᴰ" MODIFIER LETTER CAPITAL D
/*<!dead_superscript>*/	DEADTRANS(	L'd'	,L'^'	,0x1D48	,0x0000	), // "ᵈ" MODIFIER LETTER SMALL D
/*<!dead_superscript>*/	DEADTRANS(	L'E'	,L'^'	,0x1D31	,0x0000	), // "ᴱ" MODIFIER LETTER CAPITAL E
/*<!dead_superscript>*/	DEADTRANS(	L'e'	,L'^'	,0x1D49	,0x0000	), // "ᵉ" MODIFIER LETTER SMALL E
/*<!dead_superscript>*/	DEADTRANS(	L'f'	,L'^'	,0x1DA0	,0x0000	), // "ᶠ" MODIFIER LETTER SMALL F
/*<!dead_superscript>*/	DEADTRANS(	L'F'	,L'^'	,0xA7F3	,0x0000	), // "ꟳ" MODIFIER LETTER CAPITAL F: Chatino (Oaxaca, Mexico)
/*<!dead_superscript>*/	DEADTRANS(	L'G'	,L'^'	,0x1D33	,0x0000	), // "ᴳ" MODIFIER LETTER CAPITAL G
/*<!dead_superscript>*/	DEADTRANS(	L'g'	,L'^'	,0x1D4D	,0x0000	), // "ᵍ" MODIFIER LETTER SMALL G
/*<!dead_superscript>*/	DEADTRANS(	L'h'	,L'^'	,0x02B0	,0x0000	), // "ʰ" MODIFIER LETTER SMALL H
/*<!dead_superscript>*/	DEADTRANS(	L'H'	,L'^'	,0x1D34	,0x0000	), // "ᴴ" MODIFIER LETTER CAPITAL H
/*<!dead_superscript>*/	DEADTRANS(	L'I'	,L'^'	,0x1D35	,0x0000	), // "ᴵ" MODIFIER LETTER CAPITAL I
/*<!dead_superscript>*/	DEADTRANS(	L'i'	,L'^'	,0x2071	,0x0000	), // "ⁱ" SUPERSCRIPT LATIN SMALL LETTER I
/*<!dead_superscript>*/	DEADTRANS(	L'j'	,L'^'	,0x02B2	,0x0000	), // "ʲ" MODIFIER LETTER SMALL J
/*<!dead_superscript>*/	DEADTRANS(	L'J'	,L'^'	,0x1D36	,0x0000	), // "ᴶ" MODIFIER LETTER CAPITAL J
/*<!dead_superscript>*/	DEADTRANS(	L'K'	,L'^'	,0x1D37	,0x0000	), // "ᴷ" MODIFIER LETTER CAPITAL K
/*<!dead_superscript>*/	DEADTRANS(	L'k'	,L'^'	,0x1D4F	,0x0000	), // "ᵏ" MODIFIER LETTER SMALL K
/*<!dead_superscript>*/	DEADTRANS(	L'l'	,L'^'	,0x02E1	,0x0000	), // "ˡ" MODIFIER LETTER SMALL L
/*<!dead_superscript>*/	DEADTRANS(	L'L'	,L'^'	,0x1D38	,0x0000	), // "ᴸ" MODIFIER LETTER CAPITAL L
/*<!dead_superscript>*/	DEADTRANS(	L'M'	,L'^'	,0x1D39	,0x0000	), // "ᴹ" MODIFIER LETTER CAPITAL M
/*<!dead_superscript>*/	DEADTRANS(	L'm'	,L'^'	,0x1D50	,0x0000	), // "ᵐ" MODIFIER LETTER SMALL M
/*<!dead_superscript>*/	DEADTRANS(	L'N'	,L'^'	,0x1D3A	,0x0000	), // "ᴺ" MODIFIER LETTER CAPITAL N
/*<!dead_superscript>*/	DEADTRANS(	L'n'	,L'^'	,0x207F	,0x0000	), // "ⁿ" SUPERSCRIPT LATIN SMALL LETTER N
/*<!dead_superscript>*/	DEADTRANS(	L'O'	,L'^'	,0x1D3C	,0x0000	), // "ᴼ" MODIFIER LETTER CAPITAL O
/*<!dead_superscript>*/	DEADTRANS(	L'o'	,L'^'	,0x1D52	,0x0000	), // "ᵒ" MODIFIER LETTER SMALL O
/*<!dead_superscript>*/	DEADTRANS(	L'P'	,L'^'	,0x1D3E	,0x0000	), // "ᴾ" MODIFIER LETTER CAPITAL P
/*<!dead_superscript>*/	DEADTRANS(	L'p'	,L'^'	,0x1D56	,0x0000	), // "ᵖ" MODIFIER LETTER SMALL P
/*<!dead_superscript>*/	DEADTRANS(	L'Q'	,L'^'	,0xA7F4	,0x0000	), // "ꟴ" MODIFIER LETTER CAPITAL Q
/*<!dead_superscript>*/	DEADTRANS(	L'q'	,L'^'	,0xDFA5	,0x0000	), // High surrogate: D801; U+107A5 "𐞥" MODIFIER LETTER SMALL Q
/*<!dead_superscript>*/	DEADTRANS(	L'r'	,L'^'	,0x02B3	,0x0000	), // "ʳ" MODIFIER LETTER SMALL R
/*<!dead_superscript>*/	DEADTRANS(	L'R'	,L'^'	,0x1D3F	,0x0000	), // "ᴿ" MODIFIER LETTER CAPITAL R
/*<!dead_superscript>*/	DEADTRANS(	L's'	,L'^'	,0x02E2	,0x0000	), // "ˢ" MODIFIER LETTER SMALL S
/*<!dead_superscript>*/	DEADTRANS(	L'S'	,L'^'	,0x2204	,0x0000	), // "∄" THERE DOES NOT EXIST
/*<!dead_superscript>*/	DEADTRANS(	L'T'	,L'^'	,0x1D40	,0x0000	), // "ᵀ" MODIFIER LETTER CAPITAL T
/*<!dead_superscript>*/	DEADTRANS(	L't'	,L'^'	,0x1D57	,0x0000	), // "ᵗ" MODIFIER LETTER SMALL T
/*<!dead_superscript>*/	DEADTRANS(	L'U'	,L'^'	,0x1D41	,0x0000	), // "ᵁ" MODIFIER LETTER CAPITAL U
/*<!dead_superscript>*/	DEADTRANS(	L'u'	,L'^'	,0x1D58	,0x0000	), // "ᵘ" MODIFIER LETTER SMALL U
/*<!dead_superscript>*/	DEADTRANS(	L'v'	,L'^'	,0x1D5B	,0x0000	), // "ᵛ" MODIFIER LETTER SMALL V
/*<!dead_superscript>*/	DEADTRANS(	L'V'	,L'^'	,0x2C7D	,0x0000	), // "ⱽ" MODIFIER LETTER CAPITAL V
/*<!dead_superscript>*/	DEADTRANS(	L'w'	,L'^'	,0x02B7	,0x0000	), // "ʷ" MODIFIER LETTER SMALL W
/*<!dead_superscript>*/	DEADTRANS(	L'W'	,L'^'	,0x1D42	,0x0000	), // "ᵂ" MODIFIER LETTER CAPITAL W
/*<!dead_superscript>*/	DEADTRANS(	L'x'	,L'^'	,0x02E3	,0x0000	), // "ˣ" MODIFIER LETTER SMALL X
/*<!dead_superscript>*/	DEADTRANS(	L'X'	,L'^'	,0x2204	,0x0000	), // "∄" THERE DOES NOT EXIST
/*<!dead_superscript>*/	DEADTRANS(	L'y'	,L'^'	,0x02B8	,0x0000	), // "ʸ" MODIFIER LETTER SMALL Y
/*<!dead_superscript>*/	DEADTRANS(	L'Y'	,L'^'	,0x2204	,0x0000	), // "∄" THERE DOES NOT EXIST
/*<!dead_superscript>*/	DEADTRANS(	L'z'	,L'^'	,0x1DBB	,0x0000	), // "ᶻ" MODIFIER LETTER SMALL Z
/*<!dead_superscript>*/	DEADTRANS(	L'Z'	,L'^'	,0x2204	,0x0000	), // "∄" THERE DOES NOT EXIST
/*<!dead_superscript>*/	DEADTRANS(	0x00A0	,L'^'	,0x203E	,0x0000	), // "‾" OVERLINE
/*<!dead_superscript>*/	DEADTRANS(	0x202F	,L'^'	,0x203E	,0x0000	), // "‾" OVERLINE
/*<!dead_superscript>*/	DEADTRANS(	L' '	,L'^'	,0x0305	,0x0000	), // "̅" COMBINING OVERLINE
/*<!dead_superscript>*/	DEADTRANS(	0x200B	,L'^'	,0x0305	,0x0000	), // "̅" COMBINING OVERLINE
/*<!dead_tilde>*/	DEADTRANS(	L'*'	,0x00F5	,0x2051	,0x0000	), // "⁑" TWO ASTERISKS ALIGNED VERTICALLY
/*<!dead_tilde>*/	DEADTRANS(	L'='	,0x00F5	,0x0360	,0x0000	), // "͠" COMBINING DOUBLE TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'#'	,0x00F5	,0x29E4	,0x0000	), // "⧤" EQUALS SIGN AND SLANTED PARALLEL WITH TILDE ABOVE
/*<!dead_tilde>*/	DEADTRANS(	L'+'	,0x00F5	,0x2A24	,0x0000	), // "⨤" PLUS SIGN WITH TILDE ABOVE
/*<!dead_tilde>*/	DEADTRANS(	L'"'	,0x00F5	,0x201D	,0x0000	), // "”" RIGHT DOUBLE QUOTATION MARK, double comma quotation mark
/*<!dead_tilde>*/	DEADTRANS(	0x20AC	,0x00F5	,0x201D	,0x0000	), // "”" RIGHT DOUBLE QUOTATION MARK, double comma quotation mark
/*<!dead_tilde>*/	DEADTRANS(	L'_'	,0x00F5	,0x2053	,0x0000	), // "⁓" SWUNG DASH
/*<!dead_tilde>*/	DEADTRANS(	L'0'	,0x00F5	,0x02D5	,0x0000	), // "˕" MODIFIER LETTER DOWN TACK
/*<!dead_tilde>*/	DEADTRANS(	L'1'	,0x00F5	,0x2020	,0x0000	), // "†" DAGGER
/*<!dead_tilde>*/	DEADTRANS(	L'2'	,0x00F5	,0x2021	,0x0000	), // "‡" DOUBLE DAGGER
/*<!dead_tilde>*/	DEADTRANS(	L'3'	,0x00F5	,0x2E4B	,0x0000	), // "⹋" TRIPLE DAGGER
/*<!dead_tilde>*/	DEADTRANS(	L'4'	,0x00F5	,0x2E36	,0x0000	), // "⸶" DAGGER WITH LEFT GUARD
/*<!dead_tilde>*/	DEADTRANS(	L'5'	,0x00F5	,0x2E38	,0x0000	), // "⸸" TURNED DAGGER
/*<!dead_tilde>*/	DEADTRANS(	L'6'	,0x00F5	,0x2E37	,0x0000	), // "⸷" DAGGER WITH RIGHT GUARD
/*<!dead_tilde>*/	DEADTRANS(	L'7'	,0x00F5	,0xAB6A	,0x0000	), // "꭪" MODIFIER LETTER LEFT TACK
/*<!dead_tilde>*/	DEADTRANS(	L'8'	,0x00F5	,0x02D4	,0x0000	), // "˔" MODIFIER LETTER UP TACK
/*<!dead_tilde>*/	DEADTRANS(	L'9'	,0x00F5	,0xAB6B	,0x0000	), // "꭫" MODIFIER LETTER RIGHT TACK
/*<!dead_tilde>*/	DEADTRANS(	L'A'	,0x00F5	,0x00C3	,0x0000	), // "Ã" LATIN CAPITAL LETTER A WITH TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'a'	,0x00F5	,0x00E3	,0x0000	), // "ã" LATIN SMALL LETTER A WITH TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'b'	,0x00F5	,0x1D6C	,0x0000	), // "ᵬ" LATIN SMALL LETTER B WITH MIDDLE TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'C'	,0x00F5	,0xFE22	,0x0000	), // "︢" COMBINING DOUBLE TILDE LEFT HALF
/*<!dead_tilde>*/	DEADTRANS(	L'c'	,0x00F5	,0xFE23	,0x0000	), // "︣" COMBINING DOUBLE TILDE RIGHT HALF
/*<!dead_tilde>*/	DEADTRANS(	L'd'	,0x00F5	,0x1D6D	,0x0000	), // "ᵭ" LATIN SMALL LETTER D WITH MIDDLE TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'E'	,0x00F5	,0x1EBC	,0x0000	), // "Ẽ" LATIN CAPITAL LETTER E WITH TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'e'	,0x00F5	,0x1EBD	,0x0000	), // "ẽ" LATIN SMALL LETTER E WITH TILDE
/*<!dead_tilde>*/	DEADTRANS(	0x2014	,0x00F5	,0x0360	,0x0000	), // "͠" COMBINING DOUBLE TILDE
/*<!dead_tilde>*/	DEADTRANS(	0x2013	,0x00F5	,0x2053	,0x0000	), // "⁓" SWUNG DASH
/*<!dead_tilde>*/	DEADTRANS(	L'f'	,0x00F5	,0x1D6E	,0x0000	), // "ᵮ" LATIN SMALL LETTER F WITH MIDDLE TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'G'	,0x00F5	,0xFE22	,0x0000	), // "︢" COMBINING DOUBLE TILDE LEFT HALF
/*<!dead_tilde>*/	DEADTRANS(	L'g'	,0x00F5	,0xFE23	,0x0000	), // "︣" COMBINING DOUBLE TILDE RIGHT HALF
/*<!dead_tilde>*/	DEADTRANS(	0x2015	,0x00F5	,0x2053	,0x0000	), // "⁓" SWUNG DASH
/*<!dead_tilde>*/	DEADTRANS(	L'H'	,0x00F5	,0xFE22	,0x0000	), // "︢" COMBINING DOUBLE TILDE LEFT HALF
/*<!dead_tilde>*/	DEADTRANS(	L'h'	,0x00F5	,0xFE23	,0x0000	), // "︣" COMBINING DOUBLE TILDE RIGHT HALF
/*<!dead_tilde>*/	DEADTRANS(	L'I'	,0x00F5	,0x0128	,0x0000	), // "Ĩ" LATIN CAPITAL LETTER I WITH TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'i'	,0x00F5	,0x0129	,0x0000	), // "ĩ" LATIN SMALL LETTER I WITH TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'K'	,0x00F5	,0xFE22	,0x0000	), // "︢" COMBINING DOUBLE TILDE LEFT HALF
/*<!dead_tilde>*/	DEADTRANS(	L'k'	,0x00F5	,0xFE23	,0x0000	), // "︣" COMBINING DOUBLE TILDE RIGHT HALF
/*<!dead_tilde>*/	DEADTRANS(	L'N'	,0x00F5	,0x00D1	,0x0000	), // "Ñ" LATIN CAPITAL LETTER N WITH TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'n'	,0x00F5	,0x00F1	,0x0000	), // "ñ" LATIN SMALL LETTER N WITH TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'O'	,0x00F5	,0x00D5	,0x0000	), // "Õ" LATIN CAPITAL LETTER O WITH TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'o'	,0x00F5	,0x00F5	,0x0000	), // "õ" LATIN SMALL LETTER O WITH TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'p'	,0x00F5	,0x1D71	,0x0000	), // "ᵱ" LATIN SMALL LETTER P WITH MIDDLE TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'Q'	,0x00F5	,0xFE22	,0x0000	), // "︢" COMBINING DOUBLE TILDE LEFT HALF
/*<!dead_tilde>*/	DEADTRANS(	L'q'	,0x00F5	,0xFE23	,0x0000	), // "︣" COMBINING DOUBLE TILDE RIGHT HALF
/*<!dead_tilde>*/	DEADTRANS(	L's'	,0x00F5	,0x1D74	,0x0000	), // "ᵴ" LATIN SMALL LETTER S WITH MIDDLE TILDE
/*<!dead_tilde>*/	DEADTRANS(	L't'	,0x00F5	,0x1D75	,0x0000	), // "ᵵ" LATIN SMALL LETTER T WITH MIDDLE TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'U'	,0x00F5	,0x0168	,0x0000	), // "Ũ" LATIN CAPITAL LETTER U WITH TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'u'	,0x00F5	,0x0169	,0x0000	), // "ũ" LATIN SMALL LETTER U WITH TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'V'	,0x00F5	,0x1E7C	,0x0000	), // "Ṽ" LATIN CAPITAL LETTER V WITH TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'v'	,0x00F5	,0x1E7D	,0x0000	), // "ṽ" LATIN SMALL LETTER V WITH TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'W'	,0x00F5	,0xFE22	,0x0000	), // "︢" COMBINING DOUBLE TILDE LEFT HALF
/*<!dead_tilde>*/	DEADTRANS(	L'w'	,0x00F5	,0xFE23	,0x0000	), // "︣" COMBINING DOUBLE TILDE RIGHT HALF
/*<!dead_tilde>*/	DEADTRANS(	L'Y'	,0x00F5	,0x1EF8	,0x0000	), // "Ỹ" LATIN CAPITAL LETTER Y WITH TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'y'	,0x00F5	,0x1EF9	,0x0000	), // "ỹ" LATIN SMALL LETTER Y WITH TILDE
/*<!dead_tilde>*/	DEADTRANS(	L'z'	,0x00F5	,0x1D76	,0x0000	), // "ᵶ" LATIN SMALL LETTER Z WITH MIDDLE TILDE
/*<!dead_tilde>*/	DEADTRANS(	0x00A0	,0x00F5	,0x007E	,0x0000	), // "~" TILDE
/*<!dead_tilde>*/	DEADTRANS(	0x202F	,0x00F5	,0x02DC	,0x0000	), // "˜" SMALL TILDE
/*<!dead_tilde>*/	DEADTRANS(	L' '	,0x00F5	,0x0303	,0x0000	), // "̃" COMBINING TILDE
/*<!dead_tilde>*/	DEADTRANS(	0x200B	,0x00F5	,0x0303	,0x0000	), // "̃" COMBINING TILDE
/*<!dead_turned>*/	DEADTRANS(	L'&'	,0x0250	,0x214B	,0x0000	), // "⅋" TURNED AMPERSAND
/*<!dead_turned>*/	DEADTRANS(	L'\''	,0x0250	,0x02BB	,0x0000	), // "ʻ" MODIFIER LETTER TURNED COMMA
/*<!dead_turned>*/	DEADTRANS(	0x2019	,0x0250	,0x02BB	,0x0000	), // "ʻ" MODIFIER LETTER TURNED COMMA
/*<!dead_turned>*/	DEADTRANS(	L'|'	,0x0250	,0x2E38	,0x0000	), // "⸸" TURNED DAGGER
/*<!dead_turned>*/	DEADTRANS(	L','	,0x0250	,0x2E32	,0x0000	), // "⸲" TURNED COMMA
/*<!dead_turned>*/	DEADTRANS(	L'!'	,0x0250	,0x00A1	,0x0000	), // "¡" INVERTED EXCLAMATION MARK
/*<!dead_turned>*/	DEADTRANS(	L'('	,0x0250	,0x2040	,0x0000	), // "⁀" CHARACTER TIE
/*<!dead_turned>*/	DEADTRANS(	L')'	,0x0250	,0x203F	,0x0000	), // "‿" UNDERTIE
/*<!dead_turned>*/	DEADTRANS(	L'?'	,0x0250	,0x00BF	,0x0000	), // "¿" INVERTED QUESTION MARK
/*<!dead_turned>*/	DEADTRANS(	L';'	,0x0250	,0x2E35	,0x0000	), // "⸵" TURNED SEMICOLON
/*<!dead_turned>*/	DEADTRANS(	0x00A7	,0x0250	,0x2E35	,0x0000	), // "⸵" TURNED SEMICOLON
/*<!dead_turned>*/	DEADTRANS(	L'2'	,0x0250	,0x218A	,0x0000	), // "↊" TURNED DIGIT TWO
/*<!dead_turned>*/	DEADTRANS(	L'3'	,0x0250	,0x218B	,0x0000	), // "↋" TURNED DIGIT THREE
/*<!dead_turned>*/	DEADTRANS(	L'8'	,0x0250	,0x221E	,0x0000	), // "∞" INFINITY
/*<!dead_turned>*/	DEADTRANS(	L'a'	,0x0250	,0x0250	,0x0000	), // "ɐ" LATIN SMALL LETTER TURNED A
/*<!dead_turned>*/	DEADTRANS(	L'A'	,0x0250	,0x2C6F	,0x0000	), // "Ɐ" LATIN CAPITAL LETTER TURNED A
/*<!dead_turned>*/	DEADTRANS(	L'B'	,0x0250	,0xA4ED	,0x0000	), // "ꓭ" LISU LETTER GHA
/*<!dead_turned>*/	DEADTRANS(	L'C'	,0x0250	,0x0186	,0x0000	), // "Ɔ" LATIN CAPITAL LETTER OPEN O
/*<!dead_turned>*/	DEADTRANS(	L'c'	,0x0250	,0x0254	,0x0000	), // "ɔ" LATIN SMALL LETTER OPEN O
/*<!dead_turned>*/	DEADTRANS(	L'D'	,0x0250	,0xA4F7	,0x0000	), // "ꓷ" LISU LETTER OE
/*<!dead_turned>*/	DEADTRANS(	L'E'	,0x0250	,0x018E	,0x0000	), // "Ǝ" LATIN CAPITAL LETTER REVERSED E
/*<!dead_turned>*/	DEADTRANS(	L'e'	,0x0250	,0x01DD	,0x0000	), // "ǝ" LATIN SMALL LETTER TURNED E
/*<!dead_turned>*/	DEADTRANS(	L'f'	,0x0250	,0x025F	,0x0000	), // "ɟ" LATIN SMALL LETTER DOTLESS J WITH STROKE
/*<!dead_turned>*/	DEADTRANS(	L'F'	,0x0250	,0xA4DE	,0x0000	), // "ꓞ" LISU LETTER TSHA
/*<!dead_turned>*/	DEADTRANS(	L'g'	,0x0250	,0x1D77	,0x0000	), // "ᵷ" LATIN SMALL LETTER TURNED G
/*<!dead_turned>*/	DEADTRANS(	L'G'	,0x0250	,0x2141	,0x0000	), // "⅁" TURNED SANS-SERIF CAPITAL G
/*<!dead_turned>*/	DEADTRANS(	L'h'	,0x0250	,0x0265	,0x0000	), // "ɥ" LATIN SMALL LETTER TURNED H
/*<!dead_turned>*/	DEADTRANS(	L'H'	,0x0250	,0xA78D	,0x0000	), // "Ɥ" LATIN CAPITAL LETTER TURNED H
/*<!dead_turned>*/	DEADTRANS(	L'i'	,0x0250	,0x1D09	,0x0000	), // "ᴉ" LATIN SMALL LETTER TURNED I
/*<!dead_turned>*/	DEADTRANS(	L'I'	,0x0250	,0xA7F7	,0x0000	), // "ꟷ" LATIN EPIGRAPHIC LETTER SIDEWAYS I
/*<!dead_turned>*/	DEADTRANS(	L'J'	,0x0250	,0xA4E9	,0x0000	), // "ꓩ" LISU LETTER FA
/*<!dead_turned>*/	DEADTRANS(	L'k'	,0x0250	,0x029E	,0x0000	), // "ʞ" LATIN SMALL LETTER TURNED K
/*<!dead_turned>*/	DEADTRANS(	L'K'	,0x0250	,0xA7B0	,0x0000	), // "Ʞ" LATIN CAPITAL LETTER TURNED K
/*<!dead_turned>*/	DEADTRANS(	L'L'	,0x0250	,0xA780	,0x0000	), // "Ꞁ" LATIN CAPITAL LETTER TURNED L
/*<!dead_turned>*/	DEADTRANS(	L'l'	,0x0250	,0xA781	,0x0000	), // "ꞁ" LATIN SMALL LETTER TURNED L
/*<!dead_turned>*/	DEADTRANS(	L'M'	,0x0250	,0x019C	,0x0000	), // "Ɯ" LATIN CAPITAL LETTER TURNED M
/*<!dead_turned>*/	DEADTRANS(	L'm'	,0x0250	,0x026F	,0x0000	), // "ɯ" LATIN SMALL LETTER TURNED M
/*<!dead_turned>*/	DEADTRANS(	L'N'	,0x0250	,0xA4E0	,0x0000	), // "ꓠ" LISU LETTER NA
/*<!dead_turned>*/	DEADTRANS(	L'o'	,0x0250	,0x1D11	,0x0000	), // "ᴑ" LATIN SMALL LETTER SIDEWAYS O
/*<!dead_turned>*/	DEADTRANS(	L'O'	,0x0250	,0xA4F3	,0x0000	), // "ꓳ" LISU LETTER O
/*<!dead_turned>*/	DEADTRANS(	L'P'	,0x0250	,0xA4D2	,0x0000	), // "ꓒ" LISU LETTER PHA
/*<!dead_turned>*/	DEADTRANS(	L'Q'	,0x0250	,0x213A	,0x0000	), // "℺" ROTATED CAPITAL Q
/*<!dead_turned>*/	DEADTRANS(	L'r'	,0x0250	,0x0279	,0x0000	), // "ɹ" LATIN SMALL LETTER TURNED R
/*<!dead_turned>*/	DEADTRANS(	L'R'	,0x0250	,0xA4E4	,0x0000	), // "ꓤ" LISU LETTER ZA
/*<!dead_turned>*/	DEADTRANS(	L'S'	,0x0250	,0xA4E2	,0x0000	), // "ꓢ" LISU LETTER SA
/*<!dead_turned>*/	DEADTRANS(	L't'	,0x0250	,0x0287	,0x0000	), // "ʇ" LATIN SMALL LETTER TURNED T
/*<!dead_turned>*/	DEADTRANS(	L'T'	,0x0250	,0xA7B1	,0x0000	), // "Ʇ" LATIN CAPITAL LETTER TURNED T
/*<!dead_turned>*/	DEADTRANS(	L'U'	,0x0250	,0xA4F5	,0x0000	), // "ꓵ" LISU LETTER UE
/*<!dead_turned>*/	DEADTRANS(	L'u'	,0x0250	,0xAB51	,0x0000	), // "ꭑ" LATIN SMALL LETTER TURNED UI
/*<!dead_turned>*/	DEADTRANS(	L'V'	,0x0250	,0x0245	,0x0000	), // "Ʌ" LATIN CAPITAL LETTER TURNED V
/*<!dead_turned>*/	DEADTRANS(	L'v'	,0x0250	,0x028C	,0x0000	), // "ʌ" LATIN SMALL LETTER TURNED V
/*<!dead_turned>*/	DEADTRANS(	L'X'	,0x0250	,0xA4EB	,0x0000	), // "ꓫ" LISU LETTER SHA
/*<!dead_turned>*/	DEADTRANS(	L'y'	,0x0250	,0x028E	,0x0000	), // "ʎ" LATIN SMALL LETTER TURNED Y
/*<!dead_turned>*/	DEADTRANS(	L'Y'	,0x0250	,0x2144	,0x0000	), // "⅄" TURNED SANS-SERIF CAPITAL Y
/*<!dead_turned>*/	DEADTRANS(	L'Z'	,0x0250	,0xA4DC	,0x0000	), // "ꓜ" LISU LETTER DZA
/*<!dead_turned>*/	DEADTRANS(	0x00A0	,0x0250	,0x02BB	,0x0000	), // "ʻ" MODIFIER LETTER TURNED COMMA
/*<!dead_turned>*/	DEADTRANS(	0x202F	,0x0250	,0x02BB	,0x0000	), // "ʻ" MODIFIER LETTER TURNED COMMA
/*<!dead_turned>*/	DEADTRANS(	L' '	,0x0250	,0x0312	,0x0000	), // "̒" COMBINING TURNED COMMA ABOVE
/*<!dead_turned>*/	DEADTRANS(	0x200B	,0x0250	,0x0312	,0x0000	), // "̒" COMBINING TURNED COMMA ABOVE

/*****************************************************************************\
* Legacy dead key content is partly overridden by the transpile above.
\*****************************************************************************/

/*ACUTE&DOT_ABOVE    */	DEADTRANS(	L'S'	,0x1e65	,0x1e64	,0x0000	), // LATIN CAPITAL LETTER S WITH ACUTE AND DOT ABOVE
/*ACUTE&DOT_ABOVE    */	DEADTRANS(	L's'	,0x1e65	,0x1e65	,0x0000	), // LATIN SMALL LETTER S WITH ACUTE AND DOT ABOVE
/*ACUTE_ACCENT       */	DEADTRANS(	0x0020	,0x00e1	,L'O'	,0x0000	), // Effectiveness check
/*ACUTE_ACCENT       */	DEADTRANS(	0x00a0	,0x00e1	,0x00b4	,0x0000	), // ACUTE ACCENT
/*ACUTE_ACCENT       */	DEADTRANS(	0x202f	,0x00e1	,0x02ca	,0x0000	), // MODIFIER LETTER ACUTE ACCENT
/*ACUTE_ACCENT       */	DEADTRANS(	L'A'	,0x00e1	,0x00c1	,0x0000	), // LATIN CAPITAL LETTER A WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'a'	,0x00e1	,0x00e1	,0x0000	), // LATIN SMALL LETTER A WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'B'	,0x00e1	,0x00d1	,0x0000	), // LATIN CAPITAL LETTER N WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	L'b'	,0x00e1	,0x00f1	,0x0000	), // LATIN SMALL LETTER N WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	L'C'	,0x00e1	,0x0106	,0x0000	), // LATIN CAPITAL LETTER C WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'c'	,0x00e1	,0x0107	,0x0000	), // LATIN SMALL LETTER C WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'D'	,0x00e1	,0x0189	,0x0000	), // LATIN CAPITAL LETTER AFRICAN D
/*ACUTE_ACCENT       */	DEADTRANS(	L'd'	,0x00e1	,0x0256	,0x0000	), // LATIN SMALL LETTER D WITH TAIL
/*ACUTE_ACCENT       */	DEADTRANS(	L'E'	,0x00e1	,0x00c9	,0x0000	), // LATIN CAPITAL LETTER E WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'e'	,0x00e1	,0x00e9	,0x0000	), // LATIN SMALL LETTER E WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'F'	,0x00e1	,0x018e	,0x0000	), // LATIN CAPITAL LETTER REVERSED E
/*ACUTE_ACCENT       */	DEADTRANS(	L'f'	,0x00e1	,0x01dd	,0x0000	), // LATIN SMALL LETTER TURNED E
/*ACUTE_ACCENT       */	DEADTRANS(	L'G'	,0x00e1	,0x01f4	,0x0000	), // LATIN CAPITAL LETTER G WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'g'	,0x00e1	,0x01f5	,0x0000	), // LATIN SMALL LETTER G WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'H'	,0x00e1	,0x1e24	,0x0000	), // LATIN CAPITAL LETTER H WITH DOT BELOW
/*ACUTE_ACCENT       */	DEADTRANS(	L'h'	,0x00e1	,0x1e25	,0x0000	), // LATIN SMALL LETTER H WITH DOT BELOW
/*ACUTE_ACCENT       */	DEADTRANS(	L'I'	,0x00e1	,0x00cd	,0x0000	), // LATIN CAPITAL LETTER I WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'i'	,0x00e1	,0x00ed	,0x0000	), // LATIN SMALL LETTER I WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'J'	,0x00e1	,0x019d	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*ACUTE_ACCENT       */	DEADTRANS(	L'j'	,0x00e1	,0x0272	,0x0000	), // LATIN SMALL LETTER N WITH LEFT HOOK
/*ACUTE_ACCENT       */	DEADTRANS(	L'K'	,0x00e1	,0x1e30	,0x0000	), // LATIN CAPITAL LETTER K WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'k'	,0x00e1	,0x1e31	,0x0000	), // LATIN SMALL LETTER K WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'L'	,0x00e1	,0x0139	,0x0000	), // LATIN CAPITAL LETTER L WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'l'	,0x00e1	,0x013a	,0x0000	), // LATIN SMALL LETTER L WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'M'	,0x00e1	,0x1e3e	,0x0000	), // LATIN CAPITAL LETTER M WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'm'	,0x00e1	,0x1e3f	,0x0000	), // LATIN SMALL LETTER M WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'N'	,0x00e1	,0x0143	,0x0000	), // LATIN CAPITAL LETTER N WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'n'	,0x00e1	,0x0144	,0x0000	), // LATIN SMALL LETTER N WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'O'	,0x00e1	,0x00d3	,0x0000	), // LATIN CAPITAL LETTER O WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'o'	,0x00e1	,0x00f3	,0x0000	), // LATIN SMALL LETTER O WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'P'	,0x00e1	,0x1e54	,0x0000	), // LATIN CAPITAL LETTER P WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'p'	,0x00e1	,0x1e55	,0x0000	), // LATIN SMALL LETTER P WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'Q'	,0x00e1	,0x00a6	,0x0001	), // BROKEN BAR
/*ACUTE_ACCENT       */	DEADTRANS(	L'q'	,0x00e1	,0x00a6	,0x0001	), // BROKEN BAR
/*ACUTE_ACCENT       */	DEADTRANS(	L'R'	,0x00e1	,0x0154	,0x0000	), // LATIN CAPITAL LETTER R WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'r'	,0x00e1	,0x0155	,0x0000	), // LATIN SMALL LETTER R WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'S'	,0x00e1	,0x015a	,0x0000	), // LATIN CAPITAL LETTER S WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L's'	,0x00e1	,0x015b	,0x0000	), // LATIN SMALL LETTER S WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'T'	,0x00e1	,0x01ae	,0x0000	), // LATIN CAPITAL LETTER T WITH RETROFLEX HOOK
/*ACUTE_ACCENT       */	DEADTRANS(	L't'	,0x00e1	,0x0288	,0x0000	), // LATIN SMALL LETTER T WITH RETROFLEX HOOK
/*ACUTE_ACCENT       */	DEADTRANS(	L'U'	,0x00e1	,0x00da	,0x0000	), // LATIN CAPITAL LETTER U WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'u'	,0x00e1	,0x00fa	,0x0000	), // LATIN SMALL LETTER U WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'V'	,0x00e1	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*ACUTE_ACCENT       */	DEADTRANS(	L'v'	,0x00e1	,0x028c	,0x0000	), // LATIN SMALL LETTER TURNED V
/*ACUTE_ACCENT       */	DEADTRANS(	L'W'	,0x00e1	,0x1e82	,0x0000	), // LATIN CAPITAL LETTER W WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'w'	,0x00e1	,0x1e83	,0x0000	), // LATIN SMALL LETTER W WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'X'	,0x00e1	,0x014a	,0x0000	), // LATIN CAPITAL LETTER ENG
/*ACUTE_ACCENT       */	DEADTRANS(	L'x'	,0x00e1	,0x014b	,0x0000	), // LATIN SMALL LETTER ENG
/*ACUTE_ACCENT       */	DEADTRANS(	L'Y'	,0x00e1	,0x00dd	,0x0000	), // LATIN CAPITAL LETTER Y WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'y'	,0x00e1	,0x00fd	,0x0000	), // LATIN SMALL LETTER Y WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'Z'	,0x00e1	,0x0179	,0x0000	), // LATIN CAPITAL LETTER Z WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'z'	,0x00e1	,0x017a	,0x0000	), // LATIN SMALL LETTER Z WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00c0	,0x00e1	,0x00c3	,0x0000	), // LATIN CAPITAL LETTER A WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00e0	,0x00e1	,0x00e3	,0x0000	), // LATIN SMALL LETTER A WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00c6	,0x00e1	,0x01fc	,0x0000	), // LATIN CAPITAL LETTER AE WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00e6	,0x00e1	,0x01fd	,0x0000	), // LATIN SMALL LETTER AE WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00c7	,0x00e1	,0x1e08	,0x0000	), // LATIN CAPITAL LETTER C WITH CEDILLA AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00e7	,0x00e1	,0x1e09	,0x0000	), // LATIN SMALL LETTER C WITH CEDILLA AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00c8	,0x00e1	,0x0241	,0x0000	), // LATIN CAPITAL LETTER GLOTTAL STOP
/*ACUTE_ACCENT       */	DEADTRANS(	0x00e8	,0x00e1	,0x0242	,0x0000	), // LATIN SMALL LETTER GLOTTAL STOP
/*ACUTE_ACCENT       */	DEADTRANS(	0x00c9	,0x00e1	,0x00d5	,0x0000	), // LATIN CAPITAL LETTER O WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00e9	,0x00e1	,0x00f5	,0x0000	), // LATIN SMALL LETTER O WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	0x0152	,0x00e1	,0x00d5	,0x0000	), // LATIN CAPITAL LETTER O WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	0x0153	,0x00e1	,0x00f5	,0x0000	), // LATIN SMALL LETTER O WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00d9	,0x00e1	,0x00d1	,0x0000	), // LATIN CAPITAL LETTER N WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00f9	,0x00e1	,0x00f1	,0x0000	), // LATIN SMALL LETTER N WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	0x0021	,0x00e1	,0x2020	,0x0000	), // DAGGER
/*ACUTE_ACCENT       */	DEADTRANS(	0x0022	,0x00e1	,0x201d	,0x0000	), // RIGHT DOUBLE QUOTATION MARK
/*ACUTE_ACCENT       */	DEADTRANS(	0x0023	,0x00e1	,0x201d	,0x0000	), // RIGHT DOUBLE QUOTATION MARK
/*ACUTE_ACCENT       */	DEADTRANS(	0x0025	,0x00e1	,0x2030	,0x0000	), // PER MILLE SIGN
/*ACUTE_ACCENT       */	DEADTRANS(	0x0027	,0x00e1	,0x2019	,0x0000	), // RIGHT SINGLE QUOTATION MARK
/*ACUTE_ACCENT       */	DEADTRANS(	0x0028	,0x00e1	,0xab45	,0x0000	), // LATIN SMALL LETTER STIRRUP R
/*ACUTE_ACCENT       */	DEADTRANS(	0x0029	,0x00e1	,0x1eaf	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x002a	,0x00e1	,0x2022	,0x0000	), // BULLET
/*ACUTE_ACCENT       */	DEADTRANS(	0x002b	,0x00e1	,0x00b1	,0x0000	), // PLUS-MINUS SIGN
/*ACUTE_ACCENT       */	DEADTRANS(	0x002c	,0x00e1	,0x1edb	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x002d	,0x00e1	,0x2013	,0x0000	), // EN DASH
/*ACUTE_ACCENT       */	DEADTRANS(	0x002e	,0x00e1	,0x1e65	,0x0001	), // LATIN SMALL LETTER S WITH ACUTE AND DOT ABOVE
/*ACUTE_ACCENT       */	DEADTRANS(	0x002f	,0x00e1	,0x01ff	,0x0001	), // LATIN SMALL LETTER O WITH STROKE AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'1'	,0x00e1	,0x2032	,0x0000	), // PRIME
/*ACUTE_ACCENT       */	DEADTRANS(	L'2'	,0x00e1	,0x2033	,0x0000	), // DOUBLE PRIME
/*ACUTE_ACCENT       */	DEADTRANS(	L'3'	,0x00e1	,0x2034	,0x0000	), // TRIPLE PRIME
/*ACUTE_ACCENT       */	DEADTRANS(	L'4'	,0x00e1	,0x2057	,0x0000	), // QUADRUPLE PRIME
/*ACUTE_ACCENT       */	DEADTRANS(	L'7'	,0x00e1	,0x0294	,0x0000	), // LATIN LETTER GLOTTAL STOP
/*ACUTE_ACCENT       */	DEADTRANS(	0x003a	,0x00e1	,0x01d8	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x003c	,0x00e1	,0x1ebf	,0x0001	), // LATIN SMALL LETTER E WITH CIRCUMFLEX AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x003d	,0x00e1	,0x2260	,0x0000	), // NOT EQUAL TO
/*ACUTE_ACCENT       */	DEADTRANS(	0x00b0	,0x00e1	,0x2023	,0x0000	), // TRIANGULAR BULLET
/*ACUTE_ACCENT       */	DEADTRANS(	0x003f	,0x00e1	,0x2021	,0x0000	), // DOUBLE DAGGER
/*ACUTE_ACCENT       */	DEADTRANS(	0x0040	,0x00e1	,0x25cc	,0x0000	), // DOTTED CIRCLE
/*ACUTE_ACCENT       */	DEADTRANS(	0x007c	,0x00e1	,0x1e53	,0x0001	), // LATIN SMALL LETTER O WITH MACRON AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x0060	,0x00e1	,0x0295	,0x0000	), // LATIN LETTER PHARYNGEAL VOICED FRICATIVE
/*ACUTE_ACCENT       */	DEADTRANS(	0x007e	,0x00e1	,0x1e4d	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00ab	,0x00e1	,0x201c	,0x0000	), // LEFT DOUBLE QUOTATION MARK
/*ACUTE_ACCENT       */	DEADTRANS(	0x00bb	,0x00e1	,0x201d	,0x0000	), // RIGHT DOUBLE QUOTATION MARK
/*ACUTE_ACCENT       */	DEADTRANS(	0x00e1	,0x00e1	,0x0151	,0x0001	), // LATIN SMALL LETTER O WITH DOUBLE ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00ea	,0x00e1	,0x1ed1	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00eb	,0x00e1	,0x01d8	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00f2	,0x00e1	,0x021f	,0x0001	), // LATIN SMALL LETTER H WITH CARON
/*ACUTE_ACCENT       */	DEADTRANS(	0x00f8	,0x00e1	,0x01ff	,0x0001	), // LATIN SMALL LETTER O WITH STROKE AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x2019	,0x00e1	,0x2019	,0x0000	), // RIGHT SINGLE QUOTATION MARK
/*ACUTE_ACCENT       */	DEADTRANS(	0x2212	,0x00e1	,0x2012	,0x0000	), // FIGURE DASH
/*ACUTE_ACCENT       */	DEADTRANS(	0x2610	,0x00e1	,0x2752	,0x0000	), // UPPER RIGHT SHADOWED WHITE SQUARE
/*ACUTE_ACCENT       */	DEADTRANS(	0x222a	,0x00e1	,0x2282	,0x0000	), // SUBSET OF
/*ACUTE_ACCENT       */	DEADTRANS(	0x0101	,0x00e1	,0x1e53	,0x0001	), // LATIN SMALL LETTER O WITH MACRON AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x0115	,0x00e1	,0x1eaf	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x0229	,0x00e1	,0x1edb	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x01a1	,0x00e1	,0x1edb	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x1e57	,0x00e1	,0x1e65	,0x0001	), // LATIN SMALL LETTER S WITH ACUTE AND DOT ABOVE
/*ACUTE_BELOW        */	DEADTRANS(	0x0020	,0x02cf	,0x0317	,0x0000	), // COMBINING ACUTE ACCENT BELOW
/*ACUTE_BELOW        */	DEADTRANS(	0x00a0	,0x02cf	,0x02cf	,0x0000	), // MODIFIER LETTER LOW ACUTE ACCENT
/*ACUTE_BELOW        */	DEADTRANS(	0x202f	,0x02cf	,0x02cf	,0x0000	), // MODIFIER LETTER LOW ACUTE ACCENT
/*BAR&STROKE         */	DEADTRANS(	L'K'	,0xa745	,0xa744	,0x0000	), // LATIN CAPITAL LETTER K WITH STROKE AND DIAGONAL STROKE
/*BAR&STROKE         */	DEADTRANS(	L'k'	,0xa745	,0xa745	,0x0000	), // LATIN SMALL LETTER K WITH STROKE AND DIAGONAL STROKE
/*BAR&STROKE         */	DEADTRANS(	0x222a	,0xa745	,0x2209	,0x0000	), // NOT AN ELEMENT OF
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x0020	,0x024d	,0x0335	,0x0000	), // COMBINING SHORT STROKE OVERLAY
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'A'	,0x024d	,0xa73a	,0x0000	), // LATIN CAPITAL LETTER AV WITH HORIZONTAL BAR
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'a'	,0x024d	,0xa73b	,0x0000	), // LATIN SMALL LETTER AV WITH HORIZONTAL BAR
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'B'	,0x024d	,0x0243	,0x0000	), // LATIN CAPITAL LETTER B WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'b'	,0x024d	,0x0180	,0x0000	), // LATIN SMALL LETTER B WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'C'	,0x024d	,0xa792	,0x0000	), // LATIN CAPITAL LETTER C WITH BAR
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'c'	,0x024d	,0xa793	,0x0000	), // LATIN SMALL LETTER C WITH BAR
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'D'	,0x024d	,0x0110	,0x0000	), // LATIN CAPITAL LETTER D WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'd'	,0x024d	,0x0111	,0x0000	), // LATIN SMALL LETTER D WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'e'	,0x024d	,0xab33	,0x0000	), // LATIN SMALL LETTER BARRED E
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'F'	,0x024d	,0xa798	,0x0000	), // LATIN CAPITAL LETTER F WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'f'	,0x024d	,0xa799	,0x0000	), // LATIN SMALL LETTER F WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'G'	,0x024d	,0x01e4	,0x0000	), // LATIN CAPITAL LETTER G WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'g'	,0x024d	,0x01e5	,0x0000	), // LATIN SMALL LETTER G WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'H'	,0x024d	,0x0126	,0x0000	), // LATIN CAPITAL LETTER H WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'h'	,0x024d	,0x0127	,0x0000	), // LATIN SMALL LETTER H WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'I'	,0x024d	,0x0197	,0x0000	), // LATIN CAPITAL LETTER I WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'i'	,0x024d	,0x0268	,0x0000	), // LATIN SMALL LETTER I WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'J'	,0x024d	,0x0248	,0x0000	), // LATIN CAPITAL LETTER J WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'j'	,0x024d	,0x0249	,0x0000	), // LATIN SMALL LETTER J WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'K'	,0x024d	,0xa740	,0x0000	), // LATIN CAPITAL LETTER K WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'k'	,0x024d	,0xa741	,0x0000	), // LATIN SMALL LETTER K WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'L'	,0x024d	,0x023d	,0x0000	), // LATIN CAPITAL LETTER L WITH BAR
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'l'	,0x024d	,0x019a	,0x0000	), // LATIN SMALL LETTER L WITH BAR
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'O'	,0x024d	,0x019f	,0x0000	), // LATIN CAPITAL LETTER O WITH MIDDLE TILDE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'o'	,0x024d	,0x0275	,0x0000	), // LATIN SMALL LETTER BARRED O
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'P'	,0x024d	,0x2c63	,0x0000	), // LATIN CAPITAL LETTER P WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'p'	,0x024d	,0x1d7d	,0x0000	), // LATIN SMALL LETTER P WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'R'	,0x024d	,0x024c	,0x0000	), // LATIN CAPITAL LETTER R WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'r'	,0x024d	,0x024d	,0x0000	), // LATIN SMALL LETTER R WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'T'	,0x024d	,0x0166	,0x0000	), // LATIN CAPITAL LETTER T WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L't'	,0x024d	,0x0167	,0x0000	), // LATIN SMALL LETTER T WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'U'	,0x024d	,0x0244	,0x0000	), // LATIN CAPITAL LETTER U BAR
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'u'	,0x024d	,0x0289	,0x0000	), // LATIN SMALL LETTER U BAR
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'Y'	,0x024d	,0x024e	,0x0000	), // LATIN CAPITAL LETTER Y WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'y'	,0x024d	,0x024f	,0x0000	), // LATIN SMALL LETTER Y WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'Z'	,0x024d	,0x01b5	,0x0000	), // LATIN CAPITAL LETTER Z WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'z'	,0x024d	,0x01b6	,0x0000	), // LATIN SMALL LETTER Z WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x0025	,0x024d	,0x01be	,0x0000	), // LATIN LETTER INVERTED GLOTTAL STOP WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x0027	,0x024d	,0x02a1	,0x0000	), // LATIN LETTER GLOTTAL STOP WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x0029	,0x024d	,0x279c	,0x0000	), // HEAVY ROUND-TIPPED RIGHTWARDS ARROW
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x002b	,0x024d	,0x2213	,0x0000	), // MINUS-OR-PLUS SIGN
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x002c	,0x024d	,0x00ac	,0x0000	), // NOT SIGN
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x002d	,0x024d	,0x2013	,0x0001	), // EN DASH
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x002f	,0x024d	,0xa745	,0x0001	), // LATIN SMALL LETTER K WITH STROKE AND DIAGONAL STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'2'	,0x024d	,0x01bb	,0x0000	), // LATIN LETTER TWO WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'7'	,0x024d	,0x02a1	,0x0000	), // LATIN LETTER GLOTTAL STOP WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x003a	,0x024d	,0x00f7	,0x0000	), // DIVISION SIGN
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x003c	,0x024d	,0x2190	,0x0000	), // LEFTWARDS ARROW
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x003e	,0x024d	,0x2192	,0x0000	), // RIGHTWARDS ARROW
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x003f	,0x024d	,0x02a1	,0x0000	), // LATIN LETTER GLOTTAL STOP WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x005b	,0x024d	,0x2045	,0x0000	), // LEFT SQUARE BRACKET WITH QUILL
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x005c	,0x024d	,0x02a2	,0x0000	), // LATIN LETTER REVERSED GLOTTAL STOP WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x005d	,0x024d	,0x2046	,0x0000	), // RIGHT SQUARE BRACKET WITH QUILL
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x005f	,0x024d	,0xa751	,0x0001	), // LATIN SMALL LETTER P WITH STROKE THROUGH DESCENDER
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x007c	,0x024d	,0x2020	,0x0000	), // DAGGER
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x007d	,0x024d	,0x2794	,0x0000	), // HEAVY WIDE-HEADED RIGHTWARDS ARROW
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x2020	,0x024d	,0x2021	,0x0000	), // DOUBLE DAGGER
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x00fe	,0x024d	,0xa765	,0x0001	), // LATIN SMALL LETTER THORN WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'a'	,0xa765	,0xab30	,0x0000	), // LATIN SMALL LETTER BARRED ALPHA
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'c'	,0xa765	,0x0284	,0x0000	), // LATIN SMALL LETTER DOTLESS J WITH STROKE AND HOOK
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'i'	,0xa765	,0x1d7c	,0x0000	), // LATIN SMALL LETTER IOTA WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'l'	,0xa765	,0x019b	,0x0000	), // LATIN SMALL LETTER LAMBDA WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L's'	,0xa765	,0x1e9d	,0x0000	), // LATIN SMALL LETTER LONG S WITH HIGH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'T'	,0xa765	,0xa764	,0x0000	), // LATIN CAPITAL LETTER THORN WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L't'	,0xa765	,0xa765	,0x0000	), // LATIN SMALL LETTER THORN WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'u'	,0xa765	,0x1d7f	,0x0000	), // LATIN SMALL LETTER UPSILON WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x2019	,0x024d	,0x02a1	,0x0000	), // LATIN LETTER GLOTTAL STOP WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x222a	,0x024d	,0x2208	,0x0000	), // ELEMENT OF
/*BARRED_DESCENDER   */	DEADTRANS(	L'P'	,0xa751	,0xa750	,0x0000	), // LATIN CAPITAL LETTER P WITH STROKE THROUGH DESCENDER
/*BARRED_DESCENDER   */	DEADTRANS(	L'p'	,0xa751	,0xa751	,0x0000	), // LATIN SMALL LETTER P WITH STROKE THROUGH DESCENDER
/*BARRED_DESCENDER   */	DEADTRANS(	L'Q'	,0xa751	,0xa756	,0x0000	), // LATIN CAPITAL LETTER Q WITH STROKE THROUGH DESCENDER
/*BARRED_DESCENDER   */	DEADTRANS(	L'q'	,0xa751	,0xa757	,0x0000	), // LATIN SMALL LETTER Q WITH STROKE THROUGH DESCENDER
/*BARRED_DESCENDER   */	DEADTRANS(	L'T'	,0xa751	,0xa766	,0x0000	), // LATIN CAPITAL LETTER THORN WITH STROKE THROUGH DESCENDER
/*BARRED_DESCENDER   */	DEADTRANS(	L't'	,0xa751	,0xa767	,0x0000	), // LATIN SMALL LETTER THORN WITH STROKE THROUGH DESCENDER
/*BLACKLETTER        */	DEADTRANS(	L'e'	,0xab32	,0xab32	,0x0000	), // LATIN SMALL LETTER BLACKLETTER E
/*BLACKLETTER        */	DEADTRANS(	L'o'	,0xab32	,0xab3d	,0x0000	), // LATIN SMALL LETTER BLACKLETTER O
/*BREVE              */	DEADTRANS(	0x0020	,0x0115	,0x0306	,0x0000	), // COMBINING BREVE
/*BREVE              */	DEADTRANS(	0x202f	,0x0115	,0x02d8	,0x0000	), // BREVE
/*BREVE              */	DEADTRANS(	0x00a0	,0x0115	,0x222a	,0x0000	), // UNION
/*BREVE              */	DEADTRANS(	L'A'	,0x0115	,0x0102	,0x0000	), // LATIN CAPITAL LETTER A WITH BREVE
/*BREVE              */	DEADTRANS(	L'a'	,0x0115	,0x0103	,0x0000	), // LATIN SMALL LETTER A WITH BREVE
/*BREVE              */	DEADTRANS(	L'E'	,0x0115	,0x0114	,0x0000	), // LATIN CAPITAL LETTER E WITH BREVE
/*BREVE              */	DEADTRANS(	L'e'	,0x0115	,0x0115	,0x0000	), // LATIN SMALL LETTER E WITH BREVE
/*BREVE              */	DEADTRANS(	L'G'	,0x0115	,0x011e	,0x0000	), // LATIN CAPITAL LETTER G WITH BREVE
/*BREVE              */	DEADTRANS(	L'g'	,0x0115	,0x011f	,0x0000	), // LATIN SMALL LETTER G WITH BREVE
/*BREVE              */	DEADTRANS(	L'H'	,0x0115	,0x1e2a	,0x0000	), // LATIN CAPITAL LETTER H WITH BREVE BELOW
/*BREVE              */	DEADTRANS(	L'h'	,0x0115	,0x1e2b	,0x0000	), // LATIN SMALL LETTER H WITH BREVE BELOW
/*BREVE              */	DEADTRANS(	L'I'	,0x0115	,0x012c	,0x0000	), // LATIN CAPITAL LETTER I WITH BREVE
/*BREVE              */	DEADTRANS(	L'i'	,0x0115	,0x012d	,0x0000	), // LATIN SMALL LETTER I WITH BREVE
/*BREVE              */	DEADTRANS(	L'n'	,0x0115	,0x0149	,0x0000	), // LATIN SMALL LETTER N PRECEDED BY APOSTROPHE
/*BREVE              */	DEADTRANS(	L'O'	,0x0115	,0x014e	,0x0000	), // LATIN CAPITAL LETTER O WITH BREVE
/*BREVE              */	DEADTRANS(	L'o'	,0x0115	,0x014f	,0x0000	), // LATIN SMALL LETTER O WITH BREVE
/*BREVE              */	DEADTRANS(	L'r'	,0x0115	,0xab47	,0x0000	), // LATIN SMALL LETTER R WITHOUT HANDLE
/*BREVE              */	DEADTRANS(	L'U'	,0x0115	,0x016c	,0x0000	), // LATIN CAPITAL LETTER U WITH BREVE
/*BREVE              */	DEADTRANS(	L'u'	,0x0115	,0x016d	,0x0000	), // LATIN SMALL LETTER U WITH BREVE
/*BREVE              */	DEADTRANS(	L'y'	,0x0115	,0xab5a	,0x0000	), // LATIN SMALL LETTER Y WITH SHORT RIGHT LEG
/*BREVE              */	DEADTRANS(	0x0021	,0x0115	,0x1eb7	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND DOT BELOW
/*BREVE              */	DEADTRANS(	0x0023	,0x0115	,0xab4e	,0x0001	), // LATIN SMALL LETTER U WITH SHORT RIGHT LEG
/*BREVE              */	DEADTRANS(	0x0027	,0x0115	,0x1eaf	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND ACUTE
/*BREVE              */	DEADTRANS(	0x0028	,0x0115	,0xab5b	,0x0000	), // MODIFIER BREVE WITH INVERTED BREVE
/*BREVE              */	DEADTRANS(	0x0029	,0x0115	,0x0213	,0x0001	), // LATIN SMALL LETTER R WITH INVERTED BREVE
/*BREVE              */	DEADTRANS(	0x002c	,0x0115	,0x1e1d	,0x0001	), // LATIN SMALL LETTER E WITH CEDILLA AND BREVE
/*BREVE              */	DEADTRANS(	0x002e	,0x0115	,0x0310	,0x0000	), // COMBINING CANDRABINDU
/*BREVE              */	DEADTRANS(	0x005d	,0x0115	,0x1eb3	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND HOOK ABOVE
/*BREVE              */	DEADTRANS(	0x005f	,0x0115	,0x1dcb	,0x0000	), // COMBINING BREVE-MACRON
/*BREVE              */	DEADTRANS(	0x0060	,0x0115	,0x1eb1	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND GRAVE
/*BREVE              */	DEADTRANS(	0x007e	,0x0115	,0x1eb5	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND TILDE
/*BREVE              */	DEADTRANS(	0x00e1	,0x0115	,0x1eaf	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND ACUTE
/*BREVE              */	DEADTRANS(	0x00f2	,0x0115	,0x1eb1	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND GRAVE
/*BREVE              */	DEADTRANS(	0x00f5	,0x0115	,0x1eb5	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND TILDE
/*BREVE              */	DEADTRANS(	0x2610	,0x0115	,0x25ef	,0x0000	), // LARGE CIRCLE
/*BREVE              */	DEADTRANS(	0x0229	,0x0115	,0x1e1d	,0x0001	), // LATIN SMALL LETTER E WITH CEDILLA AND BREVE
/*BREVE              */	DEADTRANS(	0x1ebb	,0x0115	,0x1eb3	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND HOOK ABOVE
/*BREVE              */	DEADTRANS(	0x0115	,0x0115	,0x0213	,0x0001	), // LATIN SMALL LETTER R WITH INVERTED BREVE
/*BREVE              */	DEADTRANS(	0x014d	,0x0115	,0x1dcb	,0x0000	), // COMBINING BREVE-MACRON
/*BREVE              */	DEADTRANS(	0x1ee5	,0x0115	,0x1eb7	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND DOT BELOW
/*BREVE&ACUTE_ACCENT */	DEADTRANS(	L'A'	,0x1eaf	,0x1eae	,0x0000	), // LATIN CAPITAL LETTER A WITH BREVE AND ACUTE
/*BREVE&ACUTE_ACCENT */	DEADTRANS(	L'a'	,0x1eaf	,0x1eaf	,0x0000	), // LATIN SMALL LETTER A WITH BREVE AND ACUTE
/*BREVE&DOT_BELOW    */	DEADTRANS(	L'A'	,0x1eb7	,0x1eb6	,0x0000	), // LATIN CAPITAL LETTER A WITH BREVE AND DOT BELOW
/*BREVE&DOT_BELOW    */	DEADTRANS(	L'a'	,0x1eb7	,0x1eb7	,0x0000	), // LATIN SMALL LETTER A WITH BREVE AND DOT BELOW
/*BREVE&GRAVE        */	DEADTRANS(	L'A'	,0x1eb1	,0x1eb0	,0x0000	), // LATIN CAPITAL LETTER A WITH BREVE AND GRAVE
/*BREVE&GRAVE        */	DEADTRANS(	L'a'	,0x1eb1	,0x1eb1	,0x0000	), // LATIN SMALL LETTER A WITH BREVE AND GRAVE
/*BREVE&HOOK_ABOVE   */	DEADTRANS(	L'A'	,0x1eb3	,0x1eb2	,0x0000	), // LATIN CAPITAL LETTER A WITH BREVE AND HOOK ABOVE
/*BREVE&HOOK_ABOVE   */	DEADTRANS(	L'a'	,0x1eb3	,0x1eb3	,0x0000	), // LATIN SMALL LETTER A WITH BREVE AND HOOK ABOVE
/*BREVE&TILDE        */	DEADTRANS(	L'A'	,0x1eb5	,0x1eb4	,0x0000	), // LATIN CAPITAL LETTER A WITH BREVE AND TILDE
/*BREVE&TILDE        */	DEADTRANS(	L'a'	,0x1eb5	,0x1eb5	,0x0000	), // LATIN SMALL LETTER A WITH BREVE AND TILDE
/*BREVE_BELOW        */	DEADTRANS(	0x0020	,0x1e2b	,0x032e	,0x0000	), // COMBINING BREVE BELOW
/*BREVE_BELOW        */	DEADTRANS(	L'H'	,0x1e2b	,0x1e2a	,0x0000	), // LATIN CAPITAL LETTER H WITH BREVE BELOW
/*BREVE_BELOW        */	DEADTRANS(	L'h'	,0x1e2b	,0x1e2b	,0x0000	), // LATIN SMALL LETTER H WITH BREVE BELOW
/*CEDILLA            */	DEADTRANS(	0x0020	,0x0229	,0x0327	,0x0000	), // COMBINING CEDILLA
/*CEDILLA            */	DEADTRANS(	0x00a0	,0x0229	,0x00b8	,0x0000	), // CEDILLA
/*CEDILLA            */	DEADTRANS(	0x202f	,0x0229	,0x00b8	,0x0000	), // CEDILLA
/*CEDILLA            */	DEADTRANS(	L'C'	,0x0229	,0x00c7	,0x0000	), // LATIN CAPITAL LETTER C WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'c'	,0x0229	,0x00e7	,0x0000	), // LATIN SMALL LETTER C WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'D'	,0x0229	,0x1e10	,0x0000	), // LATIN CAPITAL LETTER D WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'd'	,0x0229	,0x1e11	,0x0000	), // LATIN SMALL LETTER D WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'E'	,0x0229	,0x0228	,0x0000	), // LATIN CAPITAL LETTER E WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'e'	,0x0229	,0x0229	,0x0000	), // LATIN SMALL LETTER E WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'G'	,0x0229	,0x0122	,0x0000	), // LATIN CAPITAL LETTER G WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'g'	,0x0229	,0x0123	,0x0000	), // LATIN SMALL LETTER G WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'H'	,0x0229	,0x1e28	,0x0000	), // LATIN CAPITAL LETTER H WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'h'	,0x0229	,0x1e29	,0x0000	), // LATIN SMALL LETTER H WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'K'	,0x0229	,0x0136	,0x0000	), // LATIN CAPITAL LETTER K WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'k'	,0x0229	,0x0137	,0x0000	), // LATIN SMALL LETTER K WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'L'	,0x0229	,0x013b	,0x0000	), // LATIN CAPITAL LETTER L WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'l'	,0x0229	,0x013c	,0x0000	), // LATIN SMALL LETTER L WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'N'	,0x0229	,0x0145	,0x0000	), // LATIN CAPITAL LETTER N WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'n'	,0x0229	,0x0146	,0x0000	), // LATIN SMALL LETTER N WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'R'	,0x0229	,0x0156	,0x0000	), // LATIN CAPITAL LETTER R WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'r'	,0x0229	,0x0157	,0x0000	), // LATIN SMALL LETTER R WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'S'	,0x0229	,0x015e	,0x0000	), // LATIN CAPITAL LETTER S WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L's'	,0x0229	,0x015f	,0x0000	), // LATIN SMALL LETTER S WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'T'	,0x0229	,0x0162	,0x0000	), // LATIN CAPITAL LETTER T WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L't'	,0x0229	,0x0163	,0x0000	), // LATIN SMALL LETTER T WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'x'	,0x0229	,0xab55	,0x0000	), // LATIN SMALL LETTER CHI WITH LOW LEFT SERIF
/*CEDILLA            */	DEADTRANS(	0x0027	,0x0229	,0x1e09	,0x0001	), // LATIN SMALL LETTER C WITH CEDILLA AND ACUTE
/*CEDILLA            */	DEADTRANS(	0x0029	,0x0229	,0x1e1d	,0x0001	), // LATIN SMALL LETTER E WITH CEDILLA AND BREVE
/*CEDILLA            */	DEADTRANS(	0x002c	,0x0229	,0x01b0	,0x0001	), // LATIN SMALL LETTER U WITH HORN
/*CEDILLA            */	DEADTRANS(	0x002f	,0x0229	,0xab59	,0x0000	), // LATIN SMALL LETTER X WITH LONG LEFT LEG WITH SERIF
/*CEDILLA            */	DEADTRANS(	0x003b	,0x0229	,0x2c6a	,0x0001	), // LATIN SMALL LETTER K WITH DESCENDER
/*CEDILLA            */	DEADTRANS(	0x00e1	,0x0229	,0x1e09	,0x0001	), // LATIN SMALL LETTER C WITH CEDILLA AND ACUTE
/*CEDILLA            */	DEADTRANS(	0x0115	,0x0229	,0x1e1d	,0x0001	), // LATIN SMALL LETTER E WITH CEDILLA AND BREVE
/*CEDILLA            */	DEADTRANS(	0x0229	,0x0229	,0x1ebb	,0x0001	), // LATIN SMALL LETTER E WITH HOOK ABOVE
/*CEDILLA&BREVE      */	DEADTRANS(	L'E'	,0x1e1d	,0x1e1c	,0x0000	), // LATIN CAPITAL LETTER E WITH CEDILLA AND BREVE
/*CEDILLA&BREVE      */	DEADTRANS(	L'e'	,0x1e1d	,0x1e1d	,0x0000	), // LATIN SMALL LETTER E WITH CEDILLA AND BREVE
/*CIRCLED            */	DEADTRANS(	0x0020	,0x25ef	,0x20dd	,0x0000	), // COMBINING ENCLOSING CIRCLE
/*CIRCLED            */	DEADTRANS(	0x0029	,0x25ef	,0x20dd	,0x0000	), // COMBINING ENCLOSING CIRCLE
/*CIRCLED            */	DEADTRANS(	0x003e	,0x25ef	,0x20df	,0x0000	), // COMBINING ENCLOSING DIAMOND
/*CIRCLED            */	DEADTRANS(	0x005c	,0x25ef	,0x20e0	,0x0000	), // COMBINING ENCLOSING CIRCLE BACKSLASH
/*CIRCLED            */	DEADTRANS(	0x005d	,0x25ef	,0x20de	,0x0000	), // COMBINING ENCLOSING SQUARE
/*CIRCLED            */	DEADTRANS(	0x00a0	,0x25ef	,0x25ef	,0x0000	), // LARGE CIRCLE
/*CIRCLED            */	DEADTRANS(	0x202f	,0x25ef	,0x25ef	,0x0000	), // LARGE CIRCLE
/*CIRCLED            */	DEADTRANS(	L'A'	,0x25ef	,0x24b6	,0x0000	), // CIRCLED LATIN CAPITAL LETTER A
/*CIRCLED            */	DEADTRANS(	L'a'	,0x25ef	,0x24d0	,0x0000	), // CIRCLED LATIN SMALL LETTER A
/*CIRCLED            */	DEADTRANS(	L'B'	,0x25ef	,0x24b7	,0x0000	), // CIRCLED LATIN CAPITAL LETTER B
/*CIRCLED            */	DEADTRANS(	L'b'	,0x25ef	,0x24d1	,0x0000	), // CIRCLED LATIN SMALL LETTER B
/*CIRCLED            */	DEADTRANS(	L'C'	,0x25ef	,0x24b8	,0x0000	), // CIRCLED LATIN CAPITAL LETTER C
/*CIRCLED            */	DEADTRANS(	L'c'	,0x25ef	,0x24d2	,0x0000	), // CIRCLED LATIN SMALL LETTER C
/*CIRCLED            */	DEADTRANS(	L'D'	,0x25ef	,0x24b9	,0x0000	), // CIRCLED LATIN CAPITAL LETTER D
/*CIRCLED            */	DEADTRANS(	L'd'	,0x25ef	,0x24d3	,0x0000	), // CIRCLED LATIN SMALL LETTER D
/*CIRCLED            */	DEADTRANS(	L'E'	,0x25ef	,0x24ba	,0x0000	), // CIRCLED LATIN CAPITAL LETTER E
/*CIRCLED            */	DEADTRANS(	L'e'	,0x25ef	,0x24d4	,0x0000	), // CIRCLED LATIN SMALL LETTER E
/*CIRCLED            */	DEADTRANS(	L'F'	,0x25ef	,0x24bb	,0x0000	), // CIRCLED LATIN CAPITAL LETTER F
/*CIRCLED            */	DEADTRANS(	L'f'	,0x25ef	,0x24d5	,0x0000	), // CIRCLED LATIN SMALL LETTER F
/*CIRCLED            */	DEADTRANS(	L'G'	,0x25ef	,0x24bc	,0x0000	), // CIRCLED LATIN CAPITAL LETTER G
/*CIRCLED            */	DEADTRANS(	L'g'	,0x25ef	,0x24d6	,0x0000	), // CIRCLED LATIN SMALL LETTER G
/*CIRCLED            */	DEADTRANS(	L'H'	,0x25ef	,0x24bd	,0x0000	), // CIRCLED LATIN CAPITAL LETTER H
/*CIRCLED            */	DEADTRANS(	L'h'	,0x25ef	,0x24d7	,0x0000	), // CIRCLED LATIN SMALL LETTER H
/*CIRCLED            */	DEADTRANS(	L'I'	,0x25ef	,0x24be	,0x0000	), // CIRCLED LATIN CAPITAL LETTER I
/*CIRCLED            */	DEADTRANS(	L'i'	,0x25ef	,0x24d8	,0x0000	), // CIRCLED LATIN SMALL LETTER I
/*CIRCLED            */	DEADTRANS(	L'J'	,0x25ef	,0x24bf	,0x0000	), // CIRCLED LATIN CAPITAL LETTER J
/*CIRCLED            */	DEADTRANS(	L'j'	,0x25ef	,0x24d9	,0x0000	), // CIRCLED LATIN SMALL LETTER J
/*CIRCLED            */	DEADTRANS(	L'K'	,0x25ef	,0x24c0	,0x0000	), // CIRCLED LATIN CAPITAL LETTER K
/*CIRCLED            */	DEADTRANS(	L'k'	,0x25ef	,0x24da	,0x0000	), // CIRCLED LATIN SMALL LETTER K
/*CIRCLED            */	DEADTRANS(	L'L'	,0x25ef	,0x24c1	,0x0000	), // CIRCLED LATIN CAPITAL LETTER L
/*CIRCLED            */	DEADTRANS(	L'l'	,0x25ef	,0x24db	,0x0000	), // CIRCLED LATIN SMALL LETTER L
/*CIRCLED            */	DEADTRANS(	L'M'	,0x25ef	,0x24c2	,0x0000	), // CIRCLED LATIN CAPITAL LETTER M
/*CIRCLED            */	DEADTRANS(	L'm'	,0x25ef	,0x24dc	,0x0000	), // CIRCLED LATIN SMALL LETTER M
/*CIRCLED            */	DEADTRANS(	L'N'	,0x25ef	,0x24c3	,0x0000	), // CIRCLED LATIN CAPITAL LETTER N
/*CIRCLED            */	DEADTRANS(	L'n'	,0x25ef	,0x24dd	,0x0000	), // CIRCLED LATIN SMALL LETTER N
/*CIRCLED            */	DEADTRANS(	L'O'	,0x25ef	,0x24c4	,0x0000	), // CIRCLED LATIN CAPITAL LETTER O
/*CIRCLED            */	DEADTRANS(	L'o'	,0x25ef	,0x24de	,0x0000	), // CIRCLED LATIN SMALL LETTER O
/*CIRCLED            */	DEADTRANS(	L'P'	,0x25ef	,0x24c5	,0x0000	), // CIRCLED LATIN CAPITAL LETTER P
/*CIRCLED            */	DEADTRANS(	L'p'	,0x25ef	,0x24df	,0x0000	), // CIRCLED LATIN SMALL LETTER P
/*CIRCLED            */	DEADTRANS(	L'Q'	,0x25ef	,0x24c6	,0x0000	), // CIRCLED LATIN CAPITAL LETTER Q
/*CIRCLED            */	DEADTRANS(	L'q'	,0x25ef	,0x24e0	,0x0000	), // CIRCLED LATIN SMALL LETTER Q
/*CIRCLED            */	DEADTRANS(	L'R'	,0x25ef	,0x24c7	,0x0000	), // CIRCLED LATIN CAPITAL LETTER R
/*CIRCLED            */	DEADTRANS(	L'r'	,0x25ef	,0x24e1	,0x0000	), // CIRCLED LATIN SMALL LETTER R
/*CIRCLED            */	DEADTRANS(	L'S'	,0x25ef	,0x24c8	,0x0000	), // CIRCLED LATIN CAPITAL LETTER S
/*CIRCLED            */	DEADTRANS(	L's'	,0x25ef	,0x24e2	,0x0000	), // CIRCLED LATIN SMALL LETTER S
/*CIRCLED            */	DEADTRANS(	L'T'	,0x25ef	,0x24c9	,0x0000	), // CIRCLED LATIN CAPITAL LETTER T
/*CIRCLED            */	DEADTRANS(	L't'	,0x25ef	,0x24e3	,0x0000	), // CIRCLED LATIN SMALL LETTER T
/*CIRCLED            */	DEADTRANS(	L'U'	,0x25ef	,0x24ca	,0x0000	), // CIRCLED LATIN CAPITAL LETTER U
/*CIRCLED            */	DEADTRANS(	L'u'	,0x25ef	,0x24e4	,0x0000	), // CIRCLED LATIN SMALL LETTER U
/*CIRCLED            */	DEADTRANS(	L'V'	,0x25ef	,0x24cb	,0x0000	), // CIRCLED LATIN CAPITAL LETTER V
/*CIRCLED            */	DEADTRANS(	L'v'	,0x25ef	,0x24e5	,0x0000	), // CIRCLED LATIN SMALL LETTER V
/*CIRCLED            */	DEADTRANS(	L'W'	,0x25ef	,0x24cc	,0x0000	), // CIRCLED LATIN CAPITAL LETTER W
/*CIRCLED            */	DEADTRANS(	L'w'	,0x25ef	,0x24e6	,0x0000	), // CIRCLED LATIN SMALL LETTER W
/*CIRCLED            */	DEADTRANS(	L'X'	,0x25ef	,0x24cd	,0x0000	), // CIRCLED LATIN CAPITAL LETTER X
/*CIRCLED            */	DEADTRANS(	L'x'	,0x25ef	,0x24e7	,0x0000	), // CIRCLED LATIN SMALL LETTER X
/*CIRCLED            */	DEADTRANS(	L'Y'	,0x25ef	,0x24ce	,0x0000	), // CIRCLED LATIN CAPITAL LETTER Y
/*CIRCLED            */	DEADTRANS(	L'y'	,0x25ef	,0x24e8	,0x0000	), // CIRCLED LATIN SMALL LETTER Y
/*CIRCLED            */	DEADTRANS(	L'Z'	,0x25ef	,0x24cf	,0x0000	), // CIRCLED LATIN CAPITAL LETTER Z
/*CIRCLED            */	DEADTRANS(	L'z'	,0x25ef	,0x24e9	,0x0000	), // CIRCLED LATIN SMALL LETTER Z
/*CIRCLED            */	DEADTRANS(	0x00d9	,0x25ef	,0x24ff	,0x0001	), // NEGATIVE CIRCLED DIGIT ZERO
/*CIRCLED            */	DEADTRANS(	0x00f9	,0x25ef	,0x24ff	,0x0001	), // NEGATIVE CIRCLED DIGIT ZERO
/*CIRCLED            */	DEADTRANS(	0x0023	,0x25ef	,0x24c3	,0x0001	), // CIRCLED LATIN CAPITAL LETTER N
/*CIRCLED            */	DEADTRANS(	0x0024	,0x25ef	,0x2780	,0x0001	), // DINGBAT CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED            */	DEADTRANS(	0x0025	,0x25ef	,0x24ff	,0x0001	), // NEGATIVE CIRCLED DIGIT ZERO
/*CIRCLED            */	DEADTRANS(	0x0028	,0x25ef	,0x24aa	,0x0001	), // PARENTHESIZED LATIN SMALL LETTER O
/*CIRCLED            */	DEADTRANS(	0x002a	,0x25ef	,0x229b	,0x0000	), // CIRCLED ASTERISK OPERATOR
/*CIRCLED            */	DEADTRANS(	0x002b	,0x25ef	,0x2295	,0x0000	), // CIRCLED PLUS
/*CIRCLED            */	DEADTRANS(	0x002d	,0x25ef	,0x2296	,0x0000	), // CIRCLED MINUS
/*CIRCLED            */	DEADTRANS(	0x002e	,0x25ef	,0x2299	,0x0000	), // CIRCLED DOT OPERATOR
/*CIRCLED            */	DEADTRANS(	0x002f	,0x25ef	,0x2298	,0x0000	), // CIRCLED DIVISION SLASH
/*CIRCLED            */	DEADTRANS(	L'0'	,0x25ef	,0x2469	,0x0000	), // CIRCLED NUMBER TEN
/*CIRCLED            */	DEADTRANS(	L'1'	,0x25ef	,0x2460	,0x0000	), // CIRCLED DIGIT ONE
/*CIRCLED            */	DEADTRANS(	L'2'	,0x25ef	,0x2461	,0x0000	), // CIRCLED DIGIT TWO
/*CIRCLED            */	DEADTRANS(	L'3'	,0x25ef	,0x2462	,0x0000	), // CIRCLED DIGIT THREE
/*CIRCLED            */	DEADTRANS(	L'4'	,0x25ef	,0x2463	,0x0000	), // CIRCLED DIGIT FOUR
/*CIRCLED            */	DEADTRANS(	L'5'	,0x25ef	,0x2464	,0x0000	), // CIRCLED DIGIT FIVE
/*CIRCLED            */	DEADTRANS(	L'6'	,0x25ef	,0x2465	,0x0000	), // CIRCLED DIGIT SIX
/*CIRCLED            */	DEADTRANS(	L'7'	,0x25ef	,0x2466	,0x0000	), // CIRCLED DIGIT SEVEN
/*CIRCLED            */	DEADTRANS(	L'8'	,0x25ef	,0x2467	,0x0000	), // CIRCLED DIGIT EIGHT
/*CIRCLED            */	DEADTRANS(	L'9'	,0x25ef	,0x2468	,0x0000	), // CIRCLED DIGIT NINE
/*CIRCLED            */	DEADTRANS(	0x003b	,0x25ef	,0x2297	,0x0000	), // CIRCLED TIMES
/*CIRCLED            */	DEADTRANS(	0x003d	,0x25ef	,0x229c	,0x0000	), // CIRCLED EQUALS
/*CIRCLED            */	DEADTRANS(	0x0040	,0x25ef	,0x25ce	,0x0001	), // BULLSEYE
/*CIRCLED            */	DEADTRANS(	0x005e	,0x25ef	,0x24c3	,0x0001	), // CIRCLED LATIN CAPITAL LETTER N
/*CIRCLED            */	DEADTRANS(	0x005f	,0x25ef	,0x229d	,0x0000	), // CIRCLED DASH
/*CIRCLED            */	DEADTRANS(	0x007c	,0x25ef	,0x2780	,0x0001	), // DINGBAT CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED            */	DEADTRANS(	0x00b0	,0x25ef	,0x229a	,0x0000	), // CIRCLED RING OPERATOR
/*CIRCLED            */	DEADTRANS(	0x00d7	,0x25ef	,0x2297	,0x0000	), // CIRCLED TIMES
/*CIRCLED            */	DEADTRANS(	0x00ea	,0x25ef	,0x24c3	,0x0001	), // CIRCLED LATIN CAPITAL LETTER N
/*CIRCLED            */	DEADTRANS(	0x00f2	,0x25ef	,0x2780	,0x0001	), // DINGBAT CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED            */	DEADTRANS(	0x00f5	,0x25ef	,0x2780	,0x0001	), // DINGBAT CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED            */	DEADTRANS(	0x2212	,0x25ef	,0x2296	,0x0000	), // CIRCLED MINUS
/*CIRCLED_##         */	DEADTRANS(	L'0'	,0x24c3	,0x24ea	,0x0001	), // CIRCLED DIGIT ZERO
/*CIRCLED_##         */	DEADTRANS(	L'1'	,0x24c3	,0x2469	,0x0001	), // CIRCLED NUMBER TEN
/*CIRCLED_##         */	DEADTRANS(	L'2'	,0x24c3	,0x2473	,0x0001	), // CIRCLED NUMBER TWENTY
/*CIRCLED_##         */	DEADTRANS(	L'3'	,0x24c3	,0x325a	,0x0001	), // CIRCLED NUMBER THIRTY
/*CIRCLED_##         */	DEADTRANS(	L'4'	,0x24c3	,0x32b5	,0x0001	), // CIRCLED NUMBER FORTY
/*CIRCLED_##         */	DEADTRANS(	L'5'	,0x24c3	,0x32bf	,0x0000	), // CIRCLED NUMBER FIFTY
/*CIRCLED_0#         */	DEADTRANS(	L'0'	,0x24ea	,0x24ea	,0x0000	), // CIRCLED DIGIT ZERO
/*CIRCLED_0#         */	DEADTRANS(	L'1'	,0x24ea	,0x2460	,0x0000	), // CIRCLED DIGIT ONE
/*CIRCLED_0#         */	DEADTRANS(	L'2'	,0x24ea	,0x2461	,0x0000	), // CIRCLED DIGIT TWO
/*CIRCLED_0#         */	DEADTRANS(	L'3'	,0x24ea	,0x2462	,0x0000	), // CIRCLED DIGIT THREE
/*CIRCLED_0#         */	DEADTRANS(	L'4'	,0x24ea	,0x2463	,0x0000	), // CIRCLED DIGIT FOUR
/*CIRCLED_0#         */	DEADTRANS(	L'5'	,0x24ea	,0x2464	,0x0000	), // CIRCLED DIGIT FIVE
/*CIRCLED_0#         */	DEADTRANS(	L'6'	,0x24ea	,0x2465	,0x0000	), // CIRCLED DIGIT SIX
/*CIRCLED_0#         */	DEADTRANS(	L'7'	,0x24ea	,0x2466	,0x0000	), // CIRCLED DIGIT SEVEN
/*CIRCLED_0#         */	DEADTRANS(	L'8'	,0x24ea	,0x2467	,0x0000	), // CIRCLED DIGIT EIGHT
/*CIRCLED_0#         */	DEADTRANS(	L'9'	,0x24ea	,0x2468	,0x0000	), // CIRCLED DIGIT NINE
/*CIRCLED_1#         */	DEADTRANS(	L'0'	,0x2469	,0x2469	,0x0000	), // CIRCLED NUMBER TEN
/*CIRCLED_1#         */	DEADTRANS(	L'1'	,0x2469	,0x246a	,0x0000	), // CIRCLED NUMBER ELEVEN
/*CIRCLED_1#         */	DEADTRANS(	L'2'	,0x2469	,0x246b	,0x0000	), // CIRCLED NUMBER TWELVE
/*CIRCLED_1#         */	DEADTRANS(	L'3'	,0x2469	,0x246c	,0x0000	), // CIRCLED NUMBER THIRTEEN
/*CIRCLED_1#         */	DEADTRANS(	L'4'	,0x2469	,0x246d	,0x0000	), // CIRCLED NUMBER FOURTEEN
/*CIRCLED_1#         */	DEADTRANS(	L'5'	,0x2469	,0x246e	,0x0000	), // CIRCLED NUMBER FIFTEEN
/*CIRCLED_1#         */	DEADTRANS(	L'6'	,0x2469	,0x246f	,0x0000	), // CIRCLED NUMBER SIXTEEN
/*CIRCLED_1#         */	DEADTRANS(	L'7'	,0x2469	,0x2470	,0x0000	), // CIRCLED NUMBER SEVENTEEN
/*CIRCLED_1#         */	DEADTRANS(	L'8'	,0x2469	,0x2471	,0x0000	), // CIRCLED NUMBER EIGHTEEN
/*CIRCLED_1#         */	DEADTRANS(	L'9'	,0x2469	,0x2472	,0x0000	), // CIRCLED NUMBER NINETEEN
/*CIRCLED_2#         */	DEADTRANS(	L'0'	,0x2473	,0x2473	,0x0000	), // CIRCLED NUMBER TWENTY
/*CIRCLED_2#         */	DEADTRANS(	L'1'	,0x2473	,0x3251	,0x0000	), // CIRCLED NUMBER TWENTY ONE
/*CIRCLED_2#         */	DEADTRANS(	L'2'	,0x2473	,0x3252	,0x0000	), // CIRCLED NUMBER TWENTY TWO
/*CIRCLED_2#         */	DEADTRANS(	L'3'	,0x2473	,0x3253	,0x0000	), // CIRCLED NUMBER TWENTY THREE
/*CIRCLED_2#         */	DEADTRANS(	L'4'	,0x2473	,0x3254	,0x0000	), // CIRCLED NUMBER TWENTY FOUR
/*CIRCLED_2#         */	DEADTRANS(	L'5'	,0x2473	,0x3255	,0x0000	), // CIRCLED NUMBER TWENTY FIVE
/*CIRCLED_2#         */	DEADTRANS(	L'6'	,0x2473	,0x3256	,0x0000	), // CIRCLED NUMBER TWENTY SIX
/*CIRCLED_2#         */	DEADTRANS(	L'7'	,0x2473	,0x3257	,0x0000	), // CIRCLED NUMBER TWENTY SEVEN
/*CIRCLED_2#         */	DEADTRANS(	L'8'	,0x2473	,0x3258	,0x0000	), // CIRCLED NUMBER TWENTY EIGHT
/*CIRCLED_2#         */	DEADTRANS(	L'9'	,0x2473	,0x3259	,0x0000	), // CIRCLED NUMBER TWENTY NINE
/*CIRCLED_3#         */	DEADTRANS(	L'0'	,0x325a	,0x325a	,0x0000	), // CIRCLED NUMBER THIRTY
/*CIRCLED_3#         */	DEADTRANS(	L'1'	,0x325a	,0x325b	,0x0000	), // CIRCLED NUMBER THIRTY ONE
/*CIRCLED_3#         */	DEADTRANS(	L'2'	,0x325a	,0x325c	,0x0000	), // CIRCLED NUMBER THIRTY TWO
/*CIRCLED_3#         */	DEADTRANS(	L'3'	,0x325a	,0x325d	,0x0000	), // CIRCLED NUMBER THIRTY THREE
/*CIRCLED_3#         */	DEADTRANS(	L'4'	,0x325a	,0x325e	,0x0000	), // CIRCLED NUMBER THIRTY FOUR
/*CIRCLED_3#         */	DEADTRANS(	L'5'	,0x325a	,0x325f	,0x0000	), // CIRCLED NUMBER THIRTY FIVE
/*CIRCLED_3#         */	DEADTRANS(	L'6'	,0x325a	,0x32b1	,0x0000	), // CIRCLED NUMBER THIRTY SIX
/*CIRCLED_3#         */	DEADTRANS(	L'7'	,0x325a	,0x32b2	,0x0000	), // CIRCLED NUMBER THIRTY SEVEN
/*CIRCLED_3#         */	DEADTRANS(	L'8'	,0x325a	,0x32b3	,0x0000	), // CIRCLED NUMBER THIRTY EIGHT
/*CIRCLED_3#         */	DEADTRANS(	L'9'	,0x325a	,0x32b4	,0x0000	), // CIRCLED NUMBER THIRTY NINE
/*CIRCLED_4#         */	DEADTRANS(	L'0'	,0x32b5	,0x32b5	,0x0000	), // CIRCLED NUMBER FORTY
/*CIRCLED_4#         */	DEADTRANS(	L'1'	,0x32b5	,0x32b6	,0x0000	), // CIRCLED NUMBER FORTY ONE
/*CIRCLED_4#         */	DEADTRANS(	L'2'	,0x32b5	,0x32b7	,0x0000	), // CIRCLED NUMBER FORTY TWO
/*CIRCLED_4#         */	DEADTRANS(	L'3'	,0x32b5	,0x32b8	,0x0000	), // CIRCLED NUMBER FORTY THREE
/*CIRCLED_4#         */	DEADTRANS(	L'4'	,0x32b5	,0x32b9	,0x0000	), // CIRCLED NUMBER FORTY FOUR
/*CIRCLED_4#         */	DEADTRANS(	L'5'	,0x32b5	,0x32ba	,0x0000	), // CIRCLED NUMBER FORTY FIVE
/*CIRCLED_4#         */	DEADTRANS(	L'6'	,0x32b5	,0x32bb	,0x0000	), // CIRCLED NUMBER FORTY SIX
/*CIRCLED_4#         */	DEADTRANS(	L'7'	,0x32b5	,0x32bc	,0x0000	), // CIRCLED NUMBER FORTY SEVEN
/*CIRCLED_4#         */	DEADTRANS(	L'8'	,0x32b5	,0x32bd	,0x0000	), // CIRCLED NUMBER FORTY EIGHT
/*CIRCLED_4#         */	DEADTRANS(	L'9'	,0x32b5	,0x32be	,0x0000	), // CIRCLED NUMBER FORTY NINE
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'0'	,0x25ce	,0x24fe	,0x0000	), // DOUBLE CIRCLED NUMBER TEN
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'1'	,0x25ce	,0x24f5	,0x0000	), // DOUBLE CIRCLED DIGIT ONE
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'2'	,0x25ce	,0x24f6	,0x0000	), // DOUBLE CIRCLED DIGIT TWO
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'3'	,0x25ce	,0x24f7	,0x0000	), // DOUBLE CIRCLED DIGIT THREE
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'4'	,0x25ce	,0x24f8	,0x0000	), // DOUBLE CIRCLED DIGIT FOUR
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'5'	,0x25ce	,0x24f9	,0x0000	), // DOUBLE CIRCLED DIGIT FIVE
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'6'	,0x25ce	,0x24fa	,0x0000	), // DOUBLE CIRCLED DIGIT SIX
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'7'	,0x25ce	,0x24fb	,0x0000	), // DOUBLE CIRCLED DIGIT SEVEN
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'8'	,0x25ce	,0x24fc	,0x0000	), // DOUBLE CIRCLED DIGIT EIGHT
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'9'	,0x25ce	,0x24fd	,0x0000	), // DOUBLE CIRCLED DIGIT NINE
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'0'	,0x278a	,0x2793	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF NUMBER TEN
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'1'	,0x278a	,0x278a	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'2'	,0x278a	,0x278b	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT TWO
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'3'	,0x278a	,0x278c	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT THREE
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'4'	,0x278a	,0x278d	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT FOUR
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'5'	,0x278a	,0x278e	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT FIVE
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'6'	,0x278a	,0x278f	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT SIX
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'7'	,0x278a	,0x2790	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT SEVEN
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'8'	,0x278a	,0x2791	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT EIGHT
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'9'	,0x278a	,0x2792	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT NINE
/*CIRCLED_NEG_SANS   */	DEADTRANS(	0x0023	,0x278a	,0xdd0c	,0x0000	), // U+1F10C; input D83C high surrogate first; DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ZERO
/*CIRCLED_NEG_SANS   */	DEADTRANS(	0x005e	,0x278a	,0xdd0c	,0x0000	), // U+1F10C; input D83C high surrogate first; DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ZERO
/*CIRCLED_NEG_SANS   */	DEADTRANS(	0x00ea	,0x278a	,0xdd0c	,0x0000	), // U+1F10C; input D83C high surrogate first; DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ZERO
/*CIRCLED_NEGATIVE   */	DEADTRANS(	0x0023	,0x24ff	,0x277f	,0x0001	), // DINGBAT NEGATIVE CIRCLED NUMBER TEN
/*CIRCLED_NEGATIVE   */	DEADTRANS(	0x0024	,0x24ff	,0x278a	,0x0001	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'0'	,0x24ff	,0x277f	,0x0000	), // DINGBAT NEGATIVE CIRCLED NUMBER TEN
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'1'	,0x24ff	,0x2776	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT ONE
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'2'	,0x24ff	,0x2777	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT TWO
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'3'	,0x24ff	,0x2778	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT THREE
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'4'	,0x24ff	,0x2779	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT FOUR
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'5'	,0x24ff	,0x277a	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT FIVE
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'6'	,0x24ff	,0x277b	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT SIX
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'7'	,0x24ff	,0x277c	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT SEVEN
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'8'	,0x24ff	,0x277d	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT EIGHT
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'9'	,0x24ff	,0x277e	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT NINE
/*CIRCLED_NEGATIVE   */	DEADTRANS(	0x005e	,0x24ff	,0x277f	,0x0001	), // DINGBAT NEGATIVE CIRCLED NUMBER TEN
/*CIRCLED_NEGATIVE   */	DEADTRANS(	0x007c	,0x24ff	,0x278a	,0x0001	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_NEGATIVE   */	DEADTRANS(	0x007d	,0x24ff	,0x278a	,0x0001	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_NEGATIVE   */	DEADTRANS(	0x00ea	,0x24ff	,0x277f	,0x0001	), // DINGBAT NEGATIVE CIRCLED NUMBER TEN
/*CIRCLED_NEGATIVE   */	DEADTRANS(	0x00f2	,0x24ff	,0x278a	,0x0001	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_NEGATIVE   */	DEADTRANS(	0x00f5	,0x24ff	,0x278a	,0x0001	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_NEGATIVE_##*/	DEADTRANS(	L'0'	,0x277f	,0x24f4	,0x0001	), // NEGATIVE CIRCLED NUMBER TWENTY
/*CIRCLED_NEGATIVE_##*/	DEADTRANS(	L'1'	,0x277f	,0x24eb	,0x0001	), // NEGATIVE CIRCLED NUMBER ELEVEN
/*CIRCLED_NEGATIVE_##*/	DEADTRANS(	L'2'	,0x277f	,0x24f4	,0x0000	), // NEGATIVE CIRCLED NUMBER TWENTY
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'1'	,0x24f4	,0x2776	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT ONE
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'2'	,0x24f4	,0x2777	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT TWO
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'3'	,0x24f4	,0x2778	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT THREE
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'4'	,0x24f4	,0x2779	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT FOUR
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'5'	,0x24f4	,0x277a	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT FIVE
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'6'	,0x24f4	,0x277b	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT SIX
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'7'	,0x24f4	,0x277c	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT SEVEN
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'8'	,0x24f4	,0x277d	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT EIGHT
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'9'	,0x24f4	,0x277e	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT NINE
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'0'	,0x24eb	,0x277f	,0x0000	), // DINGBAT NEGATIVE CIRCLED NUMBER TEN
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'1'	,0x24eb	,0x24eb	,0x0000	), // NEGATIVE CIRCLED NUMBER ELEVEN
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'2'	,0x24eb	,0x24ec	,0x0000	), // NEGATIVE CIRCLED NUMBER TWELVE
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'3'	,0x24eb	,0x24ed	,0x0000	), // NEGATIVE CIRCLED NUMBER THIRTEEN
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'4'	,0x24eb	,0x24ee	,0x0000	), // NEGATIVE CIRCLED NUMBER FOURTEEN
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'5'	,0x24eb	,0x24ef	,0x0000	), // NEGATIVE CIRCLED NUMBER FIFTEEN
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'6'	,0x24eb	,0x24f0	,0x0000	), // NEGATIVE CIRCLED NUMBER SIXTEEN
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'7'	,0x24eb	,0x24f1	,0x0000	), // NEGATIVE CIRCLED NUMBER SEVENTEEN
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'8'	,0x24eb	,0x24f2	,0x0000	), // NEGATIVE CIRCLED NUMBER EIGHTEEN
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'9'	,0x24eb	,0x24f3	,0x0000	), // NEGATIVE CIRCLED NUMBER NINETEEN
/*CIRCLED_SANS       */	DEADTRANS(	0x00d9	,0x2780	,0x278a	,0x0001	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_SANS       */	DEADTRANS(	0x00f9	,0x2780	,0x278a	,0x0001	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_SANS       */	DEADTRANS(	0x0023	,0x2780	,0xdd0b	,0x0000	), // U+1F10B; input D83C high surrogate first; DINGBAT CIRCLED SANS-SERIF DIGIT ZERO
/*CIRCLED_SANS       */	DEADTRANS(	0x0025	,0x2780	,0x278a	,0x0001	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_SANS       */	DEADTRANS(	L'0'	,0x2780	,0x2789	,0x0000	), // DINGBAT CIRCLED SANS-SERIF NUMBER TEN
/*CIRCLED_SANS       */	DEADTRANS(	L'1'	,0x2780	,0x2780	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_SANS       */	DEADTRANS(	L'2'	,0x2780	,0x2781	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT TWO
/*CIRCLED_SANS       */	DEADTRANS(	L'3'	,0x2780	,0x2782	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT THREE
/*CIRCLED_SANS       */	DEADTRANS(	L'4'	,0x2780	,0x2783	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT FOUR
/*CIRCLED_SANS       */	DEADTRANS(	L'5'	,0x2780	,0x2784	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT FIVE
/*CIRCLED_SANS       */	DEADTRANS(	L'6'	,0x2780	,0x2785	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT SIX
/*CIRCLED_SANS       */	DEADTRANS(	L'7'	,0x2780	,0x2786	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT SEVEN
/*CIRCLED_SANS       */	DEADTRANS(	L'8'	,0x2780	,0x2787	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT EIGHT
/*CIRCLED_SANS       */	DEADTRANS(	L'9'	,0x2780	,0x2788	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT NINE
/*CIRCLED_SANS       */	DEADTRANS(	0x005e	,0x2780	,0xdd0b	,0x0000	), // U+1F10B; input D83C high surrogate first; DINGBAT CIRCLED SANS-SERIF DIGIT ZERO
/*CIRCLED_SANS       */	DEADTRANS(	0x00ea	,0x2780	,0xdd0b	,0x0000	), // U+1F10B; input D83C high surrogate first; DINGBAT CIRCLED SANS-SERIF DIGIT ZERO
/*CIRCUMFLEX&ACUTE   */	DEADTRANS(	L'A'	,0x1ebf	,0x1ea4	,0x0000	), // LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND ACUTE
/*CIRCUMFLEX&ACUTE   */	DEADTRANS(	L'a'	,0x1ebf	,0x1ea5	,0x0000	), // LATIN SMALL LETTER A WITH CIRCUMFLEX AND ACUTE
/*CIRCUMFLEX&ACUTE   */	DEADTRANS(	L'E'	,0x1ebf	,0x1ebe	,0x0000	), // LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND ACUTE
/*CIRCUMFLEX&ACUTE   */	DEADTRANS(	L'e'	,0x1ebf	,0x1ebf	,0x0000	), // LATIN SMALL LETTER E WITH CIRCUMFLEX AND ACUTE
/*CIRCUMFLEX&ACUTE   */	DEADTRANS(	L'O'	,0x1ebf	,0x1ed0	,0x0000	), // LATIN CAPITAL LETTER O WITH CIRCUMFLEX AND ACUTE
/*CIRCUMFLEX&ACUTE   */	DEADTRANS(	L'o'	,0x1ebf	,0x1ed1	,0x0000	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND ACUTE
/*CIRCUMFLEX&ACUTE   */	DEADTRANS(	0x00c7	,0x1ebf	,0x01fe	,0x0000	), // LATIN CAPITAL LETTER O WITH STROKE AND ACUTE
/*CIRCUMFLEX&ACUTE   */	DEADTRANS(	0x00e7	,0x1ebf	,0x01ff	,0x0000	), // LATIN SMALL LETTER O WITH STROKE AND ACUTE
/*CIRCUMFLEX&DOT_BELO*/	DEADTRANS(	L'A'	,0x1ed9	,0x1eac	,0x0000	), // LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND DOT BELOW
/*CIRCUMFLEX&DOT_BELO*/	DEADTRANS(	L'a'	,0x1ed9	,0x1ead	,0x0000	), // LATIN SMALL LETTER A WITH CIRCUMFLEX AND DOT BELOW
/*CIRCUMFLEX&DOT_BELO*/	DEADTRANS(	L'E'	,0x1ed9	,0x1ec6	,0x0000	), // LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND DOT BELOW
/*CIRCUMFLEX&DOT_BELO*/	DEADTRANS(	L'e'	,0x1ed9	,0x1ec7	,0x0000	), // LATIN SMALL LETTER E WITH CIRCUMFLEX AND DOT BELOW
/*CIRCUMFLEX&DOT_BELO*/	DEADTRANS(	L'O'	,0x1ed9	,0x1ed8	,0x0000	), // LATIN CAPITAL LETTER O WITH CIRCUMFLEX AND DOT BELOW
/*CIRCUMFLEX&DOT_BELO*/	DEADTRANS(	L'o'	,0x1ed9	,0x1ed9	,0x0000	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND DOT BELOW
/*CIRCUMFLEX&GRAVE   */	DEADTRANS(	L'A'	,0x1ed3	,0x1ea6	,0x0000	), // LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND GRAVE
/*CIRCUMFLEX&GRAVE   */	DEADTRANS(	L'a'	,0x1ed3	,0x1ea7	,0x0000	), // LATIN SMALL LETTER A WITH CIRCUMFLEX AND GRAVE
/*CIRCUMFLEX&GRAVE   */	DEADTRANS(	L'E'	,0x1ed3	,0x1ec0	,0x0000	), // LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND GRAVE
/*CIRCUMFLEX&GRAVE   */	DEADTRANS(	L'e'	,0x1ed3	,0x1ec1	,0x0000	), // LATIN SMALL LETTER E WITH CIRCUMFLEX AND GRAVE
/*CIRCUMFLEX&GRAVE   */	DEADTRANS(	L'O'	,0x1ed3	,0x1ed2	,0x0000	), // LATIN CAPITAL LETTER O WITH CIRCUMFLEX AND GRAVE
/*CIRCUMFLEX&GRAVE   */	DEADTRANS(	L'o'	,0x1ed3	,0x1ed3	,0x0000	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND GRAVE
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'A'	,0x1ed5	,0x1ea8	,0x0000	), // LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND HOOK ABOVE
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'a'	,0x1ed5	,0x1ea9	,0x0000	), // LATIN SMALL LETTER A WITH CIRCUMFLEX AND HOOK ABOVE
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'D'	,0x1ed5	,0x276c	,0x0001	), // MEDIUM LEFT-POINTING ANGLE BRACKET ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'd'	,0x1ed5	,0x276c	,0x0001	), // MEDIUM LEFT-POINTING ANGLE BRACKET ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'D'	,0x276c	,0x2770	,0x0001	), // HEAVY LEFT-POINTING ANGLE BRACKET ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'd'	,0x276c	,0x2770	,0x0001	), // HEAVY LEFT-POINTING ANGLE BRACKET ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x0028	,0x2770	,0x2770	,0x0000	), // HEAVY LEFT-POINTING ANGLE BRACKET ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x0029	,0x2770	,0x2771	,0x0000	), // HEAVY RIGHT-POINTING ANGLE BRACKET ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x0028	,0x276c	,0x276c	,0x0000	), // MEDIUM LEFT-POINTING ANGLE BRACKET ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x0029	,0x276c	,0x276d	,0x0000	), // MEDIUM RIGHT-POINTING ANGLE BRACKET ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'E'	,0x1ed5	,0x1ec2	,0x0000	), // LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND HOOK ABOVE
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'e'	,0x1ed5	,0x1ec3	,0x0000	), // LATIN SMALL LETTER E WITH CIRCUMFLEX AND HOOK ABOVE
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'O'	,0x1ed5	,0x1ed4	,0x0000	), // LATIN CAPITAL LETTER O WITH CIRCUMFLEX AND HOOK ABOVE
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'o'	,0x1ed5	,0x1ed5	,0x0000	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND HOOK ABOVE
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x0028	,0x1ed5	,0x27e8	,0x0000	), // MATHEMATICAL LEFT ANGLE BRACKET
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x0029	,0x1ed5	,0x27e9	,0x0000	), // MATHEMATICAL RIGHT ANGLE BRACKET
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x003c	,0x1ed5	,0x276e	,0x0000	), // HEAVY LEFT-POINTING ANGLE QUOTATION MARK ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x003e	,0x1ed5	,0x276f	,0x0000	), // HEAVY RIGHT-POINTING ANGLE QUOTATION MARK ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x005d	,0x1ed5	,0x27ea	,0x0001	), // MATHEMATICAL LEFT DOUBLE ANGLE BRACKET
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x0028	,0x27ea	,0x27ea	,0x0000	), // MATHEMATICAL LEFT DOUBLE ANGLE BRACKET
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x0029	,0x27ea	,0x27eb	,0x0000	), // MATHEMATICAL RIGHT DOUBLE ANGLE BRACKET
/*CIRCUMFLEX&TILDE   */	DEADTRANS(	L'A'	,0x1ed7	,0x1eaa	,0x0000	), // LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND TILDE
/*CIRCUMFLEX&TILDE   */	DEADTRANS(	L'a'	,0x1ed7	,0x1eab	,0x0000	), // LATIN SMALL LETTER A WITH CIRCUMFLEX AND TILDE
/*CIRCUMFLEX&TILDE   */	DEADTRANS(	L'E'	,0x1ed7	,0x1ec4	,0x0000	), // LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND TILDE
/*CIRCUMFLEX&TILDE   */	DEADTRANS(	L'e'	,0x1ed7	,0x1ec5	,0x0000	), // LATIN SMALL LETTER E WITH CIRCUMFLEX AND TILDE
/*CIRCUMFLEX&TILDE   */	DEADTRANS(	L'O'	,0x1ed7	,0x1ed6	,0x0000	), // LATIN CAPITAL LETTER O WITH CIRCUMFLEX AND TILDE
/*CIRCUMFLEX&TILDE   */	DEADTRANS(	L'o'	,0x1ed7	,0x1ed7	,0x0000	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND TILDE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0020	,0x00ea	,0x0302	,0x0000	), // COMBINING CIRCUMFLEX ACCENT
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00a0	,0x00ea	,0x005e	,0x0000	), // CIRCUMFLEX ACCENT
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x202f	,0x00ea	,0x02c6	,0x0000	), // MODIFIER LETTER CIRCUMFLEX ACCENT
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'A'	,0x00ea	,0x00c2	,0x0000	), // LATIN CAPITAL LETTER A WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'a'	,0x00ea	,0x00e2	,0x0000	), // LATIN SMALL LETTER A WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'B'	,0x00ea	,0x00a6	,0x0000	), // BROKEN BAR
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'b'	,0x00ea	,0x00a6	,0x0000	), // BROKEN BAR
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'C'	,0x00ea	,0x0108	,0x0000	), // LATIN CAPITAL LETTER C WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'c'	,0x00ea	,0x0109	,0x0000	), // LATIN SMALL LETTER C WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'E'	,0x00ea	,0x00ca	,0x0000	), // LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'e'	,0x00ea	,0x00ea	,0x0000	), // LATIN SMALL LETTER E WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'G'	,0x00ea	,0x011c	,0x0000	), // LATIN CAPITAL LETTER G WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'g'	,0x00ea	,0x011d	,0x0000	), // LATIN SMALL LETTER G WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'H'	,0x00ea	,0x0124	,0x0000	), // LATIN CAPITAL LETTER H WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'h'	,0x00ea	,0x0125	,0x0000	), // LATIN SMALL LETTER H WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'I'	,0x00ea	,0x00ce	,0x0000	), // LATIN CAPITAL LETTER I WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'i'	,0x00ea	,0x00ee	,0x0000	), // LATIN SMALL LETTER I WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'J'	,0x00ea	,0x0134	,0x0000	), // LATIN CAPITAL LETTER J WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'j'	,0x00ea	,0x0135	,0x0000	), // LATIN SMALL LETTER J WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'O'	,0x00ea	,0x00d4	,0x0000	), // LATIN CAPITAL LETTER O WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'o'	,0x00ea	,0x00f4	,0x0000	), // LATIN SMALL LETTER O WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'S'	,0x00ea	,0x015c	,0x0000	), // LATIN CAPITAL LETTER S WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L's'	,0x00ea	,0x015d	,0x0000	), // LATIN SMALL LETTER S WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'U'	,0x00ea	,0x00db	,0x0000	), // LATIN CAPITAL LETTER U WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'u'	,0x00ea	,0x00fb	,0x0000	), // LATIN SMALL LETTER U WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'W'	,0x00ea	,0x0174	,0x0000	), // LATIN CAPITAL LETTER W WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'w'	,0x00ea	,0x0175	,0x0000	), // LATIN SMALL LETTER W WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'Y'	,0x00ea	,0x0176	,0x0000	), // LATIN CAPITAL LETTER Y WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'y'	,0x00ea	,0x0177	,0x0000	), // LATIN SMALL LETTER Y WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'Z'	,0x00ea	,0x1e90	,0x0000	), // LATIN CAPITAL LETTER Z WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'z'	,0x00ea	,0x1e91	,0x0000	), // LATIN SMALL LETTER Z WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00c0	,0x00ea	,0x00c5	,0x0000	), // LATIN CAPITAL LETTER A WITH RING ABOVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00e0	,0x00ea	,0x00e5	,0x0000	), // LATIN SMALL LETTER A WITH RING ABOVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00c6	,0x00ea	,0x00ad	,0x0000	), // SOFT HYPHEN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00e6	,0x00ea	,0x00ad	,0x0000	), // SOFT HYPHEN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00c7	,0x00ea	,0x00d8	,0x0000	), // LATIN CAPITAL LETTER O WITH STROKE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00e7	,0x00ea	,0x00f8	,0x0000	), // LATIN SMALL LETTER O WITH STROKE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00c8	,0x00ea	,0x0130	,0x0000	), // LATIN CAPITAL LETTER I WITH DOT ABOVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00e8	,0x00ea	,0x0131	,0x0000	), // LATIN SMALL LETTER DOTLESS I
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00c9	,0x00ea	,0x00b2	,0x0000	), // SUPERSCRIPT TWO
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00e9	,0x00ea	,0x00b2	,0x0000	), // SUPERSCRIPT TWO
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0152	,0x00ea	,0x0026	,0x0000	), // AMPERSAND
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0153	,0x00ea	,0x0026	,0x0000	), // AMPERSAND
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00d9	,0x00ea	,0x0026	,0x0000	), // AMPERSAND
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00f9	,0x00ea	,0x0026	,0x0000	), // AMPERSAND
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0021	,0x00ea	,0x1ed9	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND DOT BELOW
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0022	,0x00ea	,0x201c	,0x0000	), // LEFT DOUBLE QUOTATION MARK
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0023	,0x00ea	,0x00b3	,0x0000	), // SUPERSCRIPT THREE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0024	,0x00ea	,0x017f	,0x0000	), // LATIN SMALL LETTER LONG S
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0025	,0x00ea	,0x2030	,0x0000	), // PER MILLE SIGN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0027	,0x00ea	,0x2018	,0x0000	), // LEFT SINGLE QUOTATION MARK
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0028	,0x00ea	,0x02bf	,0x0000	), // MODIFIER LETTER LEFT HALF RING
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0029	,0x00ea	,0x02be	,0x0000	), // MODIFIER LETTER RIGHT HALF RING
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x002a	,0x00ea	,0x2042	,0x0000	), // ASTERISM
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x002b	,0x00ea	,0x207a	,0x0000	), // SUPERSCRIPT PLUS SIGN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x002c	,0x00ea	,0x02bc	,0x0000	), // MODIFIER LETTER APOSTROPHE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x002d	,0x00ea	,0x2014	,0x0000	), // EM DASH
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x002e	,0x00ea	,0x00b7	,0x0000	), // MIDDLE DOT
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x002f	,0x00ea	,0x2044	,0x0000	), // FRACTION SLASH
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'0'	,0x00ea	,0x2070	,0x0000	), // SUPERSCRIPT ZERO
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'1'	,0x00ea	,0x00b9	,0x0000	), // SUPERSCRIPT ONE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'2'	,0x00ea	,0x00b2	,0x0000	), // SUPERSCRIPT TWO
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'3'	,0x00ea	,0x00b3	,0x0000	), // SUPERSCRIPT THREE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'4'	,0x00ea	,0x2074	,0x0000	), // SUPERSCRIPT FOUR
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'5'	,0x00ea	,0x2075	,0x0000	), // SUPERSCRIPT FIVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'6'	,0x00ea	,0x2076	,0x0000	), // SUPERSCRIPT SIX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'7'	,0x00ea	,0x2077	,0x0000	), // SUPERSCRIPT SEVEN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'8'	,0x00ea	,0x2078	,0x0000	), // SUPERSCRIPT EIGHT
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'9'	,0x00ea	,0x2079	,0x0000	), // SUPERSCRIPT NINE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003a	,0x00ea	,0x2026	,0x0000	), // HORIZONTAL ELLIPSIS
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003b	,0x00ea	,0x2027	,0x0000	), // HYPHENATION POINT
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003c	,0x00ea	,0x2a7d	,0x0000	), // LESS-THAN OR SLANTED EQUAL TO
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003d	,0x00ea	,0x2266	,0x0000	), // LESS-THAN OVER EQUAL TO
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003e	,0x00ea	,0x2276	,0x0000	), // LESS-THAN OR GREATER-THAN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003f	,0x00ea	,0x203d	,0x0000	), // INTERROBANG
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0040	,0x00ea	,0x25b3	,0x0000	), // WHITE UP-POINTING TRIANGLE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x005b	,0x00ea	,0x0188	,0x0001	), // LATIN SMALL LETTER C WITH HOOK
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0028	,0x0188	,0x2329	,0x0000	), // LEFT-POINTING ANGLE BRACKET
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0029	,0x0188	,0x232a	,0x0000	), // RIGHT-POINTING ANGLE BRACKET
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003c	,0x0188	,0x3008	,0x0000	), // LEFT ANGLE BRACKET
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003e	,0x0188	,0x3009	,0x0000	), // RIGHT ANGLE BRACKET
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x005b	,0x0188	,0x300a	,0x0001	), // LEFT DOUBLE ANGLE BRACKET
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003c	,0x300a	,0x300a	,0x0000	), // LEFT DOUBLE ANGLE BRACKET
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003e	,0x300a	,0x300b	,0x0000	), // RIGHT DOUBLE ANGLE BRACKET
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x2026	,0x0188	,0xf900	,0x0001	), // CJK COMPATIBILITY IDEOGRAPH-F900
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x005d	,0xf900	,0x0125	,0x0000	), // LATIN SMALL LETTER H WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x005d	,0x00ea	,0x1ed5	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND HOOK ABOVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x005f	,0x00ea	,0x2264	,0x0000	), // LESS-THAN OR EQUAL TO
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0060	,0x00ea	,0x02bb	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x007c	,0x00ea	,0x2020	,0x0000	), // DAGGER
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x007e	,0x00ea	,0x1ed7	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND TILDE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x20ac	,0x00ea	,0x20a6	,0x0000	), // NAIRA SIGN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x2021	,0x00ea	,0x2e4b	,0x0000	), // TRIPLE DAGGER
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0027	,0x2460	,0x1ed1	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND ACUTE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0060	,0x2460	,0x1ed3	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND GRAVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00a7	,0x00ea	,0x00b6	,0x0000	), // PILCROW SIGN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00ab	,0x00ea	,0x2039	,0x0000	), // SINGLE LEFT-POINTING ANGLE QUOTATION MARK
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00b5	,0x00ea	,0x2208	,0x0000	), // ELEMENT OF
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00bb	,0x00ea	,0x203a	,0x0000	), // SINGLE RIGHT-POINTING ANGLE QUOTATION MARK
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00e1	,0x00ea	,0x1ed1	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND ACUTE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00ea	,0x00ea	,0x1e19	,0x0001	), // LATIN SMALL LETTER E WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00eb	,0x00ea	,0x022f	,0x0001	), // LATIN SMALL LETTER O WITH DOT ABOVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00f2	,0x00ea	,0x1ed3	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND GRAVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00f5	,0x00ea	,0x1ed7	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND TILDE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x02bc	,0x00ea	,0x02bb	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x2019	,0x00ea	,0x02bc	,0x0000	), // MODIFIER LETTER APOSTROPHE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x2212	,0x00ea	,0x207b	,0x0000	), // SUPERSCRIPT MINUS
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x2610	,0x00ea	,0x2612	,0x0000	), // BALLOT BOX WITH X
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x222a	,0x00ea	,0x2229	,0x0000	), // INTERSECTION
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x1ebb	,0x00ea	,0x1ed5	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND HOOK ABOVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0132	,0x00ea	,0x2021	,0x0000	), // DOUBLE DAGGER
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0133	,0x00ea	,0x00a5	,0x0000	), // YEN SIGN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x1ee5	,0x00ea	,0x1ed9	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND DOT BELOW
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x03b8	,0x00ea	,0x2229	,0x0000	), // INTERSECTION
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x03f4	,0x00ea	,0x222a	,0x0000	), // UNION
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x03c0	,0x00ea	,0x220b	,0x0000	), // CONTAINS AS MEMBER
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	0x0020	,0x1e19	,0x032d	,0x0000	), // COMBINING CIRCUMFLEX ACCENT BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	0x00a0	,0x1e19	,0xa788	,0x0000	), // MODIFIER LETTER LOW CIRCUMFLEX ACCENT
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	0x202f	,0x1e19	,0xa788	,0x0000	), // MODIFIER LETTER LOW CIRCUMFLEX ACCENT
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'D'	,0x1e19	,0x1e12	,0x0000	), // LATIN CAPITAL LETTER D WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'd'	,0x1e19	,0x1e13	,0x0000	), // LATIN SMALL LETTER D WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'E'	,0x1e19	,0x1e18	,0x0000	), // LATIN CAPITAL LETTER E WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'e'	,0x1e19	,0x1e19	,0x0000	), // LATIN SMALL LETTER E WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'L'	,0x1e19	,0x1e3c	,0x0000	), // LATIN CAPITAL LETTER L WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'l'	,0x1e19	,0x1e3d	,0x0000	), // LATIN SMALL LETTER L WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'N'	,0x1e19	,0x1e4a	,0x0000	), // LATIN CAPITAL LETTER N WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'n'	,0x1e19	,0x1e4b	,0x0000	), // LATIN SMALL LETTER N WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'T'	,0x1e19	,0x1e70	,0x0000	), // LATIN CAPITAL LETTER T WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L't'	,0x1e19	,0x1e71	,0x0000	), // LATIN SMALL LETTER T WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'U'	,0x1e19	,0x1e76	,0x0000	), // LATIN CAPITAL LETTER U WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'u'	,0x1e19	,0x1e77	,0x0000	), // LATIN SMALL LETTER U WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'X'	,0x1e19	,0x2716	,0x0000	), // HEAVY MULTIPLICATION X
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	0x0025	,0x1e19	,0x2031	,0x0000	), // PER TEN THOUSAND SIGN
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	0x00ea	,0x1e19	,0x021f	,0x0001	), // LATIN SMALL LETTER H WITH CARON
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	0x2610	,0x1e19	,0x2611	,0x0000	), // BALLOT BOX WITH CHECK
/*COMBINING_ABOVE    */	DEADTRANS(	L'A'	,0x002a	,0x031a	,0x0000	), // COMBINING LEFT ANGLE ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	L'a'	,0x002a	,0x0363	,0x0000	), // COMBINING LATIN SMALL LETTER A
/*COMBINING_ABOVE    */	DEADTRANS(	L'b'	,0x002a	,0x1de8	,0x0000	), // COMBINING LATIN SMALL LETTER B
/*COMBINING_ABOVE    */	DEADTRANS(	L'c'	,0x002a	,0x0368	,0x0000	), // COMBINING LATIN SMALL LETTER C
/*COMBINING_ABOVE    */	DEADTRANS(	L'd'	,0x002a	,0x0369	,0x0000	), // COMBINING LATIN SMALL LETTER D
/*COMBINING_ABOVE    */	DEADTRANS(	L'e'	,0x002a	,0x0364	,0x0000	), // COMBINING LATIN SMALL LETTER E
/*COMBINING_ABOVE    */	DEADTRANS(	L'f'	,0x002a	,0x1deb	,0x0000	), // COMBINING LATIN SMALL LETTER F
/*COMBINING_ABOVE    */	DEADTRANS(	L'G'	,0x002a	,0x1ddb	,0x0000	), // COMBINING LATIN LETTER SMALL CAPITAL G
/*COMBINING_ABOVE    */	DEADTRANS(	L'g'	,0x002a	,0x1dda	,0x0000	), // COMBINING LATIN SMALL LETTER G
/*COMBINING_ABOVE    */	DEADTRANS(	L'h'	,0x002a	,0x036a	,0x0000	), // COMBINING LATIN SMALL LETTER H
/*COMBINING_ABOVE    */	DEADTRANS(	L'i'	,0x002a	,0x0365	,0x0000	), // COMBINING LATIN SMALL LETTER I
/*COMBINING_ABOVE    */	DEADTRANS(	L'k'	,0x002a	,0x1ddc	,0x0000	), // COMBINING LATIN SMALL LETTER K
/*COMBINING_ABOVE    */	DEADTRANS(	L'L'	,0x002a	,0x1dde	,0x0000	), // COMBINING LATIN LETTER SMALL CAPITAL L
/*COMBINING_ABOVE    */	DEADTRANS(	L'l'	,0x002a	,0x1ddd	,0x0000	), // COMBINING LATIN SMALL LETTER L
/*COMBINING_ABOVE    */	DEADTRANS(	L'M'	,0x002a	,0x1ddf	,0x0000	), // COMBINING LATIN LETTER SMALL CAPITAL M
/*COMBINING_ABOVE    */	DEADTRANS(	L'm'	,0x002a	,0x036b	,0x0000	), // COMBINING LATIN SMALL LETTER M
/*COMBINING_ABOVE    */	DEADTRANS(	L'N'	,0x002a	,0x1de1	,0x0000	), // COMBINING LATIN LETTER SMALL CAPITAL N
/*COMBINING_ABOVE    */	DEADTRANS(	L'n'	,0x002a	,0x1de0	,0x0000	), // COMBINING LATIN SMALL LETTER N
/*COMBINING_ABOVE    */	DEADTRANS(	L'o'	,0x002a	,0x0366	,0x0000	), // COMBINING LATIN SMALL LETTER O
/*COMBINING_ABOVE    */	DEADTRANS(	L'p'	,0x002a	,0x1dee	,0x0000	), // COMBINING LATIN SMALL LETTER P
/*COMBINING_ABOVE    */	DEADTRANS(	L'R'	,0x002a	,0x1de2	,0x0000	), // COMBINING LATIN LETTER SMALL CAPITAL R
/*COMBINING_ABOVE    */	DEADTRANS(	L'r'	,0x002a	,0x036c	,0x0000	), // COMBINING LATIN SMALL LETTER R
/*COMBINING_ABOVE    */	DEADTRANS(	L'S'	,0x002a	,0x1dd1	,0x0000	), // COMBINING UR ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	L's'	,0x002a	,0x1de4	,0x0000	), // COMBINING LATIN SMALL LETTER S
/*COMBINING_ABOVE    */	DEADTRANS(	L'T'	,0x002a	,0x1df5	,0x0000	), // COMBINING UP TACK ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	L't'	,0x002a	,0x036d	,0x0000	), // COMBINING LATIN SMALL LETTER T
/*COMBINING_ABOVE    */	DEADTRANS(	L'u'	,0x002a	,0x0367	,0x0000	), // COMBINING LATIN SMALL LETTER U
/*COMBINING_ABOVE    */	DEADTRANS(	L'V'	,0x002a	,0x1dc3	,0x0000	), // COMBINING SUSPENSION MARK
/*COMBINING_ABOVE    */	DEADTRANS(	L'v'	,0x002a	,0x036e	,0x0000	), // COMBINING LATIN SMALL LETTER V
/*COMBINING_ABOVE    */	DEADTRANS(	L'w'	,0x002a	,0x1df1	,0x0000	), // COMBINING LATIN SMALL LETTER W
/*COMBINING_ABOVE    */	DEADTRANS(	L'X'	,0x002a	,0x033d	,0x0000	), // COMBINING X ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	L'x'	,0x002a	,0x036f	,0x0000	), // COMBINING LATIN SMALL LETTER X
/*COMBINING_ABOVE    */	DEADTRANS(	L'Z'	,0x002a	,0x035b	,0x0000	), // COMBINING ZIGZAG ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	L'z'	,0x002a	,0x1de6	,0x0000	), // COMBINING LATIN SMALL LETTER Z
/*COMBINING_ABOVE    */	DEADTRANS(	0x00e7	,0x002a	,0x1dd7	,0x0000	), // COMBINING LATIN SMALL LETTER C CEDILLA
/*COMBINING_ABOVE    */	DEADTRANS(	0x005e	,0x002a	,0x1dcd	,0x0000	), // COMBINING DOUBLE CIRCUMFLEX ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x00ea	,0x002a	,0x1dcd	,0x0000	), // COMBINING DOUBLE CIRCUMFLEX ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x00f5	,0x002a	,0x0360	,0x0000	), // COMBINING DOUBLE TILDE
/*COMBINING_ABOVE    */	DEADTRANS(	0x0022	,0x002a	,0x030e	,0x0000	), // COMBINING DOUBLE VERTICAL LINE ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x0023	,0x002a	,0x030e	,0x0000	), // COMBINING DOUBLE VERTICAL LINE ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x0026	,0x002a	,0x0363	,0x0000	), // COMBINING LATIN SMALL LETTER A
/*COMBINING_ABOVE    */	DEADTRANS(	0x0027	,0x002a	,0x030d	,0x0000	), // COMBINING VERTICAL LINE ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x0028	,0x002a	,0x0351	,0x0000	), // COMBINING LEFT HALF RING ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x0029	,0x002a	,0x0357	,0x0000	), // COMBINING RIGHT HALF RING ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x002c	,0x002a	,0x0313	,0x0000	), // COMBINING COMMA ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x002d	,0x002a	,0x1ab3	,0x0000	), // COMBINING DOWNWARDS ARROW
/*COMBINING_ABOVE    */	DEADTRANS(	L'2'	,0x002a	,0x1ab3	,0x0000	), // COMBINING DOWNWARDS ARROW
/*COMBINING_ABOVE    */	DEADTRANS(	0x005f	,0x002a	,0xfe26	,0x0000	), // COMBINING CONJOINING MACRON
/*COMBINING_ABOVE    */	DEADTRANS(	0x002e	,0x002a	,0x0358	,0x0000	), // COMBINING DOT ABOVE RIGHT
/*COMBINING_ABOVE    */	DEADTRANS(	0x00e1	,0x002a	,0x1dc1	,0x0000	), // COMBINING DOTTED ACUTE ACCENT
/*COMBINING_ABOVE    */	DEADTRANS(	0x00f2	,0x002a	,0x1dc0	,0x0000	), // COMBINING DOTTED GRAVE ACCENT
/*COMBINING_ABOVE    */	DEADTRANS(	0x002f	,0x002a	,0x1ded	,0x0000	), // COMBINING LATIN SMALL LETTER O WITH LIGHT CENTRALIZATION STROKE
/*COMBINING_ABOVE    */	DEADTRANS(	L'8'	,0x002a	,0x1ab2	,0x0000	), // COMBINING INFINITY
/*COMBINING_ABOVE    */	DEADTRANS(	L'9'	,0x002a	,0x1dd2	,0x0000	), // COMBINING US ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x003b	,0x002a	,0x1dce	,0x0000	), // COMBINING OGONEK ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x003c	,0x002a	,0x1dfe	,0x0000	), // COMBINING LEFT ARROWHEAD ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x003d	,0x002a	,0x033f	,0x0000	), // COMBINING DOUBLE OVERLINE
/*COMBINING_ABOVE    */	DEADTRANS(	0x003e	,0x002a	,0x0350	,0x0000	), // COMBINING RIGHT ARROWHEAD ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x005b	,0x002a	,0x0346	,0x0000	), // COMBINING BRIDGE ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x007e	,0x002a	,0xfe22	,0x0000	), // COMBINING DOUBLE TILDE LEFT HALF
/*COMBINING_ABOVE    */	DEADTRANS(	0x005d	,0x002a	,0xfe25	,0x0000	), // COMBINING MACRON RIGHT HALF
/*COMBINING_ABOVE    */	DEADTRANS(	0x00a3	,0x002a	,0x1dd8	,0x0000	), // COMBINING LATIN SMALL LETTER INSULAR D
/*COMBINING_ABOVE    */	DEADTRANS(	0x00a9	,0x002a	,0x1de5	,0x0001	), // COMBINING LATIN SMALL LETTER LONG S
/*COMBINING_ABOVE    */	DEADTRANS(	0x00b0	,0x002a	,0x1de3	,0x0000	), // COMBINING LATIN SMALL LETTER R ROTUNDA
/*COMBINING_ABOVE    */	DEADTRANS(	0x00b5	,0x002a	,0x1de7	,0x0000	), // COMBINING LATIN SMALL LETTER ALPHA
/*COMBINING_ABOVE    */	DEADTRANS(	0x00d7	,0x002a	,0x033d	,0x0000	), // COMBINING X ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x0020	,0x002a	,0x1ab0	,0x0000	), // COMBINING DOUBLED CIRCUMFLEX ACCENT
/*COMBINING_ABOVE    */	DEADTRANS(	0x00f9	,0x002a	,0x0315	,0x0000	), // COMBINING COMMA ABOVE RIGHT
/*COMBINING_ABOVE    */	DEADTRANS(	0x2019	,0x002a	,0x0315	,0x0000	), // COMBINING COMMA ABOVE RIGHT
/*COMBINING_ABOVE    */	DEADTRANS(	0x00eb	,0x002a	,0x1df2	,0x0000	), // COMBINING LATIN SMALL LETTER A WITH DIAERESIS
/*COMBINING_ABOVE    */	DEADTRANS(	0x00e0	,0x002a	,0x1df3	,0x0000	), // COMBINING LATIN SMALL LETTER O WITH DIAERESIS
/*COMBINING_ABOVE    */	DEADTRANS(	0x00e8	,0x002a	,0x1df4	,0x0000	), // COMBINING LATIN SMALL LETTER U WITH DIAERESIS
/*COMBINING_ABOVE    */	DEADTRANS(	0x00e9	,0x002a	,0x1df2	,0x0000	), // COMBINING LATIN SMALL LETTER A WITH DIAERESIS
/*COMBINING_BELOW    */	DEADTRANS(	L'A'	,0x2038	,0x0349	,0x0000	), // COMBINING LEFT ANGLE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'i'	,0x2038	,0x1dd0	,0x0000	), // COMBINING IS BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'j'	,0x2038	,0x1ab7	,0x0000	), // COMBINING OPEN MARK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'r'	,0x2038	,0x1dca	,0x0000	), // COMBINING LATIN SMALL LETTER R BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L's'	,0x2038	,0x1dc2	,0x0000	), // COMBINING SNAKE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L't'	,0x2038	,0x031d	,0x0001	), // COMBINING UP TACK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'b'	,0x031d	,0x031e	,0x0000	), // COMBINING DOWN TACK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'd'	,0x031d	,0x0319	,0x0000	), // COMBINING RIGHT TACK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'g'	,0x031d	,0x0318	,0x0000	), // COMBINING LEFT TACK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'h'	,0x031d	,0x031d	,0x0000	), // COMBINING UP TACK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'V'	,0x2038	,0x1dff	,0x0000	), // COMBINING RIGHT ARROWHEAD AND DOWN ARROWHEAD BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'v'	,0x2038	,0x033c	,0x0000	), // COMBINING SEAGULL BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'w'	,0x2038	,0x1ab6	,0x0000	), // COMBINING WIGGLY LINE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'x'	,0x2038	,0x0353	,0x0000	), // COMBINING X BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'z'	,0x2038	,0x1dcf	,0x0000	), // COMBINING ZIGZAG BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x00f9	,0x2038	,0x0329	,0x0000	), // COMBINING VERTICAL LINE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0022	,0x2038	,0x0348	,0x0000	), // COMBINING DOUBLE VERTICAL LINE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0024	,0x2038	,0x00c7	,0x0001	), // LATIN CAPITAL LETTER C WITH CEDILLA
/*COMBINING_BELOW    */	DEADTRANS(	0x0029	,0x00c7	,0x035c	,0x0000	), // COMBINING DOUBLE BREVE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x002d	,0x00c7	,0x0362	,0x0000	), // COMBINING DOUBLE RIGHTWARDS ARROW BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005f	,0x00c7	,0x035f	,0x0000	), // COMBINING DOUBLE MACRON BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0027	,0x2038	,0x0329	,0x0000	), // COMBINING VERTICAL LINE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0028	,0x2038	,0x031c	,0x0000	), // COMBINING LEFT HALF RING BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0020	,0x1abd	,0x032f	,0x0000	), // COMBINING INVERTED BREVE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0029	,0x1abd	,0x1abd	,0x0000	), // COMBINING PARENTHESES BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0029	,0x2038	,0x0339	,0x0000	), // COMBINING RIGHT HALF RING BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x002a	,0x2038	,0x0359	,0x0000	), // COMBINING ASTERISK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x002b	,0x2038	,0x031f	,0x0000	), // COMBINING PLUS SIGN BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x002d	,0x2038	,0x1e07	,0x0001	), // LATIN SMALL LETTER B WITH LINE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'5'	,0x1e07	,0x034d	,0x0000	), // COMBINING LEFT RIGHT ARROW BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'8'	,0x1e07	,0x034e	,0x0000	), // COMBINING UPWARDS ARROW BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x002d	,0x1e07	,0x0320	,0x0000	), // COMBINING MINUS SIGN BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005f	,0x1e07	,0xfe2d	,0x0000	), // COMBINING CONJOINING MACRON BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x002e	,0x2038	,0x1aba	,0x0000	), // COMBINING STRONG CENTRALIZATION STROKE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x002f	,0x2038	,0x1ab9	,0x0000	), // COMBINING LIGHT CENTRALIZATION STROKE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'8'	,0x2038	,0x035a	,0x0000	), // COMBINING DOUBLE RING BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x003c	,0x2038	,0x0354	,0x0000	), // COMBINING LEFT ARROWHEAD BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x003d	,0x2038	,0x2017	,0x0001	), // DOUBLE LOW LINE
/*COMBINING_BELOW    */	DEADTRANS(	L'j'	,0x2017	,0x1ab8	,0x0000	), // COMBINING DOUBLE OPEN MARK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'x'	,0x2017	,0x1ab5	,0x0000	), // COMBINING X-X BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0020	,0x2017	,0x0333	,0x0000	), // COMBINING DOUBLE LOW LINE
/*COMBINING_BELOW    */	DEADTRANS(	0x0029	,0x2017	,0x032b	,0x0000	), // COMBINING INVERTED DOUBLE ARCH BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x003d	,0x2017	,0x0347	,0x0000	), // COMBINING EQUALS SIGN BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x00a0	,0x2017	,0x2017	,0x0000	), // DOUBLE LOW LINE
/*COMBINING_BELOW    */	DEADTRANS(	0x00b0	,0x2017	,0x035a	,0x0000	), // COMBINING DOUBLE RING BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x00d7	,0x2017	,0x1ab5	,0x0000	), // COMBINING X-X BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x202f	,0x2017	,0x2017	,0x0000	), // DOUBLE LOW LINE
/*COMBINING_BELOW    */	DEADTRANS(	0x003e	,0x2038	,0x0355	,0x0000	), // COMBINING RIGHT ARROWHEAD BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005b	,0x2038	,0x032a	,0x0001	), // COMBINING BRIDGE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0028	,0x032a	,0xfe27	,0x0000	), // COMBINING LIGATURE LEFT HALF BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005b	,0x032a	,0x032a	,0x0000	), // COMBINING BRIDGE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005f	,0x032a	,0xfe2b	,0x0000	), // COMBINING MACRON LEFT HALF BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x007e	,0x032a	,0xfe29	,0x0000	), // COMBINING TILDE LEFT HALF BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005d	,0x2038	,0x033a	,0x0001	), // COMBINING INVERTED BRIDGE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0020	,0x033a	,0x0321	,0x0000	), // COMBINING PALATALIZED HOOK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0028	,0x033a	,0xfe28	,0x0000	), // COMBINING LIGATURE RIGHT HALF BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005d	,0x033a	,0x033a	,0x0000	), // COMBINING INVERTED BRIDGE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005f	,0x033a	,0xfe2c	,0x0000	), // COMBINING MACRON RIGHT HALF BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x007e	,0x033a	,0xfe2a	,0x0000	), // COMBINING TILDE RIGHT HALF BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005e	,0x2038	,0x0356	,0x0000	), // COMBINING RIGHT ARROWHEAD AND UP ARROWHEAD BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x00d7	,0x2038	,0x0353	,0x0000	), // COMBINING X BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x00e1	,0x2038	,0x02cf	,0x0000	), // MODIFIER LETTER LOW ACUTE ACCENT
/*COMBINING_BELOW    */	DEADTRANS(	0x00ea	,0x2038	,0x2041	,0x0001	), // CARET INSERTION POINT
/*COMBINING_BELOW    */	DEADTRANS(	0x0020	,0x2041	,0x032d	,0x0000	), // COMBINING CIRCUMFLEX ACCENT BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x00ea	,0x2041	,0xa788	,0x0000	), // MODIFIER LETTER LOW CIRCUMFLEX ACCENT
/*COMBINING_BELOW    */	DEADTRANS(	0x202f	,0x2041	,0x2041	,0x0000	), // CARET INSERTION POINT
/*COMBINING_BELOW    */	DEADTRANS(	0x00eb	,0x2038	,0x0324	,0x0000	), // COMBINING DIAERESIS BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x00f2	,0x2038	,0x02ce	,0x0001	), // MODIFIER LETTER LOW GRAVE ACCENT
/*COMBINING_BELOW    */	DEADTRANS(	0x0020	,0x02ce	,0x0316	,0x0000	), // COMBINING GRAVE ACCENT BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x202f	,0x02ce	,0x02ce	,0x0000	), // MODIFIER LETTER LOW GRAVE ACCENT
/*COMBINING_BELOW    */	DEADTRANS(	0x00f5	,0x2038	,0x02f7	,0x0001	), // MODIFIER LETTER LOW TILDE
/*COMBINING_BELOW    */	DEADTRANS(	0x0020	,0x02f7	,0x0330	,0x0000	), // COMBINING TILDE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x003d	,0x02f7	,0x1dfd	,0x0000	), // COMBINING ALMOST EQUAL TO BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x00f5	,0x02f7	,0x1dfd	,0x0000	), // COMBINING ALMOST EQUAL TO BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x202f	,0x02f7	,0x02f7	,0x0000	), // MODIFIER LETTER LOW TILDE
/*COMBINING_BELOW    */	DEADTRANS(	0x2019	,0x2038	,0x0329	,0x0000	), // COMBINING VERTICAL LINE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x2610	,0x2038	,0x033b	,0x0000	), // COMBINING SQUARE BELOW
/*COMBINING_OVERLAY  */	DEADTRANS(	L'P'	,0x002b	,0x204d	,0x0000	), // BLACK RIGHTWARDS BULLET
/*COMBINING_OVERLAY  */	DEADTRANS(	L'p'	,0x002b	,0x204d	,0x0000	), // BLACK RIGHTWARDS BULLET
/*COMBINING_OVERLAY  */	DEADTRANS(	L'Q'	,0x002b	,0x204c	,0x0000	), // BLACK LEFTWARDS BULLET
/*COMBINING_OVERLAY  */	DEADTRANS(	L'q'	,0x002b	,0x204c	,0x0000	), // BLACK LEFTWARDS BULLET
/*COMBINING_OVERLAY  */	DEADTRANS(	0x0025	,0x002b	,0x0337	,0x0000	), // COMBINING SHORT SOLIDUS OVERLAY
/*COMBINING_OVERLAY  */	DEADTRANS(	0x002a	,0x002b	,0x2055	,0x0000	), // FLOWER PUNCTUATION MARK
/*COMBINING_OVERLAY  */	DEADTRANS(	0x002b	,0x002b	,0x00b1	,0x0000	), // PLUS-MINUS SIGN
/*COMBINING_OVERLAY  */	DEADTRANS(	0x002d	,0x002b	,0x0335	,0x0000	), // COMBINING SHORT STROKE OVERLAY
/*COMBINING_OVERLAY  */	DEADTRANS(	0x002e	,0x002b	,0x2022	,0x0000	), // BULLET
/*COMBINING_OVERLAY  */	DEADTRANS(	0x002f	,0x002b	,0x0338	,0x0000	), // COMBINING LONG SOLIDUS OVERLAY
/*COMBINING_OVERLAY  */	DEADTRANS(	0x003a	,0x002b	,0x205c	,0x0000	), // DOTTED CROSS
/*COMBINING_OVERLAY  */	DEADTRANS(	0x003d	,0x002b	,0x2043	,0x0000	), // HYPHEN BULLET
/*COMBINING_OVERLAY  */	DEADTRANS(	0x003e	,0x002b	,0x2023	,0x0000	), // TRIANGULAR BULLET
/*COMBINING_OVERLAY  */	DEADTRANS(	0x005f	,0x002b	,0x0336	,0x0000	), // COMBINING LONG STROKE OVERLAY
/*COMBINING_OVERLAY  */	DEADTRANS(	0x007e	,0x002b	,0x026b	,0x0001	), // LATIN SMALL LETTER L WITH MIDDLE TILDE
/*COMBINING_OVERLAY  */	DEADTRANS(	0x00f5	,0x002b	,0x026b	,0x0001	), // LATIN SMALL LETTER L WITH MIDDLE TILDE
/*COMBINING_OVERLAY  */	DEADTRANS(	0x2212	,0x002b	,0x00b1	,0x0000	), // PLUS-MINUS SIGN
/*COMMA_BELOW        */	DEADTRANS(	0x0020	,0x0219	,0x0326	,0x0000	), // COMBINING COMMA BELOW
/*COMMA_BELOW        */	DEADTRANS(	L'J'	,0x0219	,0xa72e	,0x0000	), // LATIN CAPITAL LETTER CUATRILLO WITH COMMA
/*COMMA_BELOW        */	DEADTRANS(	L'j'	,0x0219	,0xa72f	,0x0000	), // LATIN SMALL LETTER CUATRILLO WITH COMMA
/*COMMA_BELOW        */	DEADTRANS(	L'S'	,0x0219	,0x0218	,0x0000	), // LATIN CAPITAL LETTER S WITH COMMA BELOW
/*COMMA_BELOW        */	DEADTRANS(	L's'	,0x0219	,0x0219	,0x0000	), // LATIN SMALL LETTER S WITH COMMA BELOW
/*COMMA_BELOW        */	DEADTRANS(	L'T'	,0x0219	,0x021a	,0x0000	), // LATIN CAPITAL LETTER T WITH COMMA BELOW
/*COMMA_BELOW        */	DEADTRANS(	L't'	,0x0219	,0x021b	,0x0000	), // LATIN SMALL LETTER T WITH COMMA BELOW
/*COMMA_BELOW        */	DEADTRANS(	L'X'	,0x0219	,0xab55	,0x0000	), // LATIN SMALL LETTER CHI WITH LOW LEFT SERIF
/*COMMA_BELOW        */	DEADTRANS(	L'x'	,0x0219	,0xab58	,0x0000	), // LATIN SMALL LETTER X WITH LONG LEFT LEG AND LOW RIGHT RING
/*COMPOSE            */	DEADTRANS(	0x202f	,0x00a6	,0x2384	,0x0000	), // COMPOSITION SYMBOL
/*COMPOSE            */	DEADTRANS(	L'A'	,0x00a6	,0x0041	,0x0001	), // LATIN CAPITAL LETTER A
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0041	,0xa732	,0x0000	), // LATIN CAPITAL LETTER AA
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0041	,0xa732	,0x0000	), // LATIN CAPITAL LETTER AA
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0041	,0x00c6	,0x0000	), // LATIN CAPITAL LETTER AE
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0041	,0x00c6	,0x0000	), // LATIN CAPITAL LETTER AE
/*COMPOSE            */	DEADTRANS(	L'I'	,0x0041	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0041	,0x2c6d	,0x0000	), // LATIN CAPITAL LETTER ALPHA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0041	,0x2c6d	,0x0000	), // LATIN CAPITAL LETTER ALPHA
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0041	,0xa734	,0x0000	), // LATIN CAPITAL LETTER AO
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0041	,0xa734	,0x0000	), // LATIN CAPITAL LETTER AO
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0041	,0x214d	,0x0000	), // AKTIESELSKAB
/*COMPOSE            */	DEADTRANS(	L'U'	,0x0041	,0xa736	,0x0000	), // LATIN CAPITAL LETTER AU
/*COMPOSE            */	DEADTRANS(	L'u'	,0x0041	,0xa736	,0x0000	), // LATIN CAPITAL LETTER AU
/*COMPOSE            */	DEADTRANS(	L'V'	,0x0041	,0xa738	,0x0000	), // LATIN CAPITAL LETTER AV
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0041	,0xa738	,0x0000	), // LATIN CAPITAL LETTER AV
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x0041	,0xa73c	,0x0000	), // LATIN CAPITAL LETTER AY
/*COMPOSE            */	DEADTRANS(	L'y'	,0x0041	,0xa73c	,0x0000	), // LATIN CAPITAL LETTER AY
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0041	,0x01c2	,0x0000	), // LATIN LETTER ALVEOLAR CLICK
/*COMPOSE            */	DEADTRANS(	0x002f	,0x0041	,0x2100	,0x0001	), // ACCOUNT OF
/*COMPOSE            */	DEADTRANS(	L'O'	,0x2100	,0x2100	,0x0000	), // ACCOUNT OF
/*COMPOSE            */	DEADTRANS(	L'S'	,0x2100	,0x214d	,0x0000	), // AKTIESELSKAB
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0041	,0xa79a	,0x0000	), // LATIN CAPITAL LETTER VOLAPUK AE
/*COMPOSE            */	DEADTRANS(	0x005f	,0x0041	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'a'	,0x00a6	,0x0061	,0x0001	), // LATIN SMALL LETTER A
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0061	,0xa732	,0x0000	), // LATIN CAPITAL LETTER AA
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0061	,0xa733	,0x0000	), // LATIN SMALL LETTER AA
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0061	,0x00c6	,0x0000	), // LATIN CAPITAL LETTER AE
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0061	,0x00e6	,0x0000	), // LATIN SMALL LETTER AE
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0061	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0061	,0x0251	,0x0000	), // LATIN SMALL LETTER ALPHA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0061	,0x0251	,0x0000	), // LATIN SMALL LETTER ALPHA
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0061	,0xa734	,0x0000	), // LATIN CAPITAL LETTER AO
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0061	,0xa735	,0x0000	), // LATIN SMALL LETTER AO
/*COMPOSE            */	DEADTRANS(	L's'	,0x0061	,0x2101	,0x0000	), // ADDRESSED TO THE SUBJECT
/*COMPOSE            */	DEADTRANS(	L'u'	,0x0061	,0xa737	,0x0000	), // LATIN SMALL LETTER AU
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0061	,0xa739	,0x0000	), // LATIN SMALL LETTER AV
/*COMPOSE            */	DEADTRANS(	L'y'	,0x0061	,0xa73d	,0x0000	), // LATIN SMALL LETTER AY
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0061	,0x01c2	,0x0000	), // LATIN LETTER ALVEOLAR CLICK
/*COMPOSE            */	DEADTRANS(	0x0029	,0x0061	,0x1e9a	,0x0000	), // LATIN SMALL LETTER A WITH RIGHT HALF RING
/*COMPOSE            */	DEADTRANS(	0x002f	,0x0061	,0x2100	,0x0001	), // ACCOUNT OF
/*COMPOSE            */	DEADTRANS(	L'o'	,0x2100	,0x2100	,0x0000	), // ACCOUNT OF
/*COMPOSE            */	DEADTRANS(	L's'	,0x2100	,0x2101	,0x0000	), // ADDRESSED TO THE SUBJECT
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0061	,0xa79b	,0x0000	), // LATIN SMALL LETTER VOLAPUK AE
/*COMPOSE            */	DEADTRANS(	0x005c	,0x0061	,0xab31	,0x0000	), // LATIN SMALL LETTER A REVERSED-SCHWA
/*COMPOSE            */	DEADTRANS(	0x005f	,0x0061	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'B'	,0x00a6	,0x0062	,0x0001	), // LATIN SMALL LETTER B
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0042	,0x264e	,0x0000	), // LIBRA
/*COMPOSE            */	DEADTRANS(	L'B'	,0x0042	,0x266d	,0x0000	), // MUSIC FLAT SIGN
/*COMPOSE            */	DEADTRANS(	L'C'	,0x0042	,0x2658	,0x0000	), // WHITE CHESS KNIGHT
/*COMPOSE            */	DEADTRANS(	L'D'	,0x0042	,0x2655	,0x0000	), // WHITE CHESS QUEEN
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0042	,0x2648	,0x0000	), // ARIES
/*COMPOSE            */	DEADTRANS(	L'F'	,0x0042	,0x2657	,0x0000	), // WHITE CHESS BISHOP
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0042	,0xa7b4	,0x0000	), // LATIN CAPITAL LETTER BETA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0042	,0xa7b4	,0x0000	), // LATIN CAPITAL LETTER BETA
/*COMPOSE            */	DEADTRANS(	L'M'	,0x0042	,0x266d	,0x0000	), // MUSIC FLAT SIGN
/*COMPOSE            */	DEADTRANS(	L'P'	,0x0042	,0x2659	,0x0000	), // WHITE CHESS PAWN
/*COMPOSE            */	DEADTRANS(	L'Q'	,0x0042	,0x266e	,0x0000	), // MUSIC NATURAL SIGN
/*COMPOSE            */	DEADTRANS(	L'R'	,0x0042	,0x2654	,0x0000	), // WHITE CHESS KING
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0042	,0x2656	,0x0000	), // WHITE CHESS ROOK
/*COMPOSE            */	DEADTRANS(	0x00c9	,0x0042	,0x2648	,0x0000	), // ARIES
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0042	,0x0298	,0x0000	), // LATIN LETTER BILABIAL CLICK
/*COMPOSE            */	DEADTRANS(	0x003c	,0x0042	,0x02fb	,0x0000	), // MODIFIER LETTER BEGIN LOW TONE
/*COMPOSE            */	DEADTRANS(	0x003e	,0x0042	,0x02fc	,0x0000	), // MODIFIER LETTER END LOW TONE
/*COMPOSE            */	DEADTRANS(	L'b'	,0x00a6	,0x0062	,0x0001	), // LATIN SMALL LETTER B
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0062	,0x264e	,0x0000	), // LIBRA
/*COMPOSE            */	DEADTRANS(	L'b'	,0x0062	,0x266d	,0x0000	), // MUSIC FLAT SIGN
/*COMPOSE            */	DEADTRANS(	L'c'	,0x0062	,0x2658	,0x0000	), // WHITE CHESS KNIGHT
/*COMPOSE            */	DEADTRANS(	L'd'	,0x0062	,0x2655	,0x0000	), // WHITE CHESS QUEEN
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0062	,0x2648	,0x0000	), // ARIES
/*COMPOSE            */	DEADTRANS(	L'f'	,0x0062	,0x2657	,0x0000	), // WHITE CHESS BISHOP
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0062	,0xa7b5	,0x0000	), // LATIN SMALL LETTER BETA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0062	,0xa7b5	,0x0000	), // LATIN SMALL LETTER BETA
/*COMPOSE            */	DEADTRANS(	L'm'	,0x0062	,0x266d	,0x0000	), // MUSIC FLAT SIGN
/*COMPOSE            */	DEADTRANS(	L'p'	,0x0062	,0x2659	,0x0000	), // WHITE CHESS PAWN
/*COMPOSE            */	DEADTRANS(	L'q'	,0x0062	,0x266e	,0x0000	), // MUSIC NATURAL SIGN
/*COMPOSE            */	DEADTRANS(	L'r'	,0x0062	,0x2654	,0x0000	), // WHITE CHESS KING
/*COMPOSE            */	DEADTRANS(	L't'	,0x0062	,0x2656	,0x0000	), // WHITE CHESS ROOK
/*COMPOSE            */	DEADTRANS(	0x00e9	,0x0062	,0x2648	,0x0000	), // ARIES
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0062	,0x0298	,0x0000	), // LATIN LETTER BILABIAL CLICK
/*COMPOSE            */	DEADTRANS(	0x003c	,0x0062	,0x02fb	,0x0000	), // MODIFIER LETTER BEGIN LOW TONE
/*COMPOSE            */	DEADTRANS(	0x003e	,0x0062	,0x02fc	,0x0000	), // MODIFIER LETTER END LOW TONE
/*COMPOSE            */	DEADTRANS(	L'C'	,0x00a6	,0x0043	,0x0001	), // LATIN CAPITAL LETTER C
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0043	,0x264b	,0x0001	), // CANCER
/*COMPOSE            */	DEADTRANS(	L'N'	,0x264b	,0x264b	,0x0000	), // CANCER
/*COMPOSE            */	DEADTRANS(	L'P'	,0x264b	,0x2651	,0x0000	), // CAPRICORN
/*COMPOSE            */	DEADTRANS(	L'C'	,0x0043	,0x2102	,0x0000	), // DOUBLE-STRUCK CAPITAL C
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0043	,0xdd2f	,0x0000	), // U+1F12F; input D83C high surrogate first; COPYLEFT SYMBOL
/*COMPOSE            */	DEADTRANS(	L'N'	,0x0043	,0x264b	,0x0000	), // CANCER
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0043	,0xa76e	,0x0000	), // LATIN CAPITAL LETTER CON
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0043	,0xa76e	,0x0000	), // LATIN CAPITAL LETTER CON
/*COMPOSE            */	DEADTRANS(	L'P'	,0x0043	,0x2651	,0x0000	), // CAPRICORN
/*COMPOSE            */	DEADTRANS(	L'R'	,0x0043	,0x00a9	,0x0000	), // COPYRIGHT SIGN
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0043	,0x0297	,0x0000	), // LATIN LETTER STRETCHED C
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x0043	,0x0436	,0x0001	), // CYRILLIC SMALL LETTER ZHE
/*COMPOSE            */	DEADTRANS(	0x00c9	,0x0043	,0x0297	,0x0000	), // LATIN LETTER STRETCHED C
/*COMPOSE            */	DEADTRANS(	0x002d	,0x0043	,0x266b	,0x0000	), // BEAMED EIGHTH NOTES
/*COMPOSE            */	DEADTRANS(	0x002f	,0x0043	,0x2105	,0x0001	), // CARE OF
/*COMPOSE            */	DEADTRANS(	L'O'	,0x2105	,0x2105	,0x0000	), // CARE OF
/*COMPOSE            */	DEADTRANS(	L'U'	,0x2105	,0x2106	,0x0000	), // CADA UNA
/*COMPOSE            */	DEADTRANS(	L'0'	,0x0043	,0x2648	,0x0001	), // ARIES
/*COMPOSE            */	DEADTRANS(	L'1'	,0x0043	,0x2651	,0x0001	), // CAPRICORN
/*COMPOSE            */	DEADTRANS(	L'4'	,0x0043	,0xa72c	,0x0000	), // LATIN CAPITAL LETTER CUATRILLO
/*COMPOSE            */	DEADTRANS(	0x003d	,0x0043	,0x266c	,0x0000	), // BEAMED SIXTEENTH NOTES
/*COMPOSE            */	DEADTRANS(	0x00ea	,0x0043	,0xa702	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN SHANG
/*COMPOSE            */	DEADTRANS(	0x00eb	,0x0043	,0xa700	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN PING
/*COMPOSE            */	DEADTRANS(	L'c'	,0x00a6	,0x0063	,0x0001	), // LATIN SMALL LETTER C
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0063	,0x264b	,0x0001	), // CANCER
/*COMPOSE            */	DEADTRANS(	L'n'	,0x264b	,0x264b	,0x0000	), // CANCER
/*COMPOSE            */	DEADTRANS(	L'p'	,0x264b	,0x2651	,0x0000	), // CAPRICORN
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0063	,0xab62	,0x0000	), // LATIN SMALL LETTER OPEN OE
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0063	,0xdd2f	,0x0000	), // U+1F12F; input D83C high surrogate first; COPYLEFT SYMBOL
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0063	,0x264b	,0x0000	), // CANCER
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0063	,0xa76e	,0x0000	), // LATIN CAPITAL LETTER CON
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0063	,0xa76f	,0x0000	), // LATIN SMALL LETTER CON
/*COMPOSE            */	DEADTRANS(	L'p'	,0x0063	,0x2651	,0x0000	), // CAPRICORN
/*COMPOSE            */	DEADTRANS(	L'r'	,0x0063	,0x00a9	,0x0000	), // COPYRIGHT SIGN
/*COMPOSE            */	DEADTRANS(	L's'	,0x0063	,0x0297	,0x0000	), // LATIN LETTER STRETCHED C
/*COMPOSE            */	DEADTRANS(	L'y'	,0x0063	,0x0448	,0x0001	), // CYRILLIC SMALL LETTER SHA
/*COMPOSE            */	DEADTRANS(	0x00e9	,0x0063	,0x0297	,0x0000	), // LATIN LETTER STRETCHED C
/*COMPOSE            */	DEADTRANS(	0x002d	,0x0063	,0x266b	,0x0000	), // BEAMED EIGHTH NOTES
/*COMPOSE            */	DEADTRANS(	0x002f	,0x0063	,0x2105	,0x0001	), // CARE OF
/*COMPOSE            */	DEADTRANS(	L'o'	,0x2105	,0x2105	,0x0000	), // CARE OF
/*COMPOSE            */	DEADTRANS(	L'u'	,0x2105	,0x2106	,0x0000	), // CADA UNA
/*COMPOSE            */	DEADTRANS(	L'4'	,0x0063	,0xa72d	,0x0000	), // LATIN SMALL LETTER CUATRILLO
/*COMPOSE            */	DEADTRANS(	0x003d	,0x0063	,0x266c	,0x0000	), // BEAMED SIXTEENTH NOTES
/*COMPOSE            */	DEADTRANS(	0x00ea	,0x0063	,0xa702	,0x0001	), // MODIFIER LETTER CHINESE TONE YIN SHANG
/*COMPOSE            */	DEADTRANS(	0x0028	,0xa702	,0xa702	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN SHANG
/*COMPOSE            */	DEADTRANS(	0x0029	,0xa702	,0xa704	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN QU
/*COMPOSE            */	DEADTRANS(	0x005f	,0xa702	,0xa703	,0x0001	), // MODIFIER LETTER CHINESE TONE YANG SHANG
/*COMPOSE            */	DEADTRANS(	0x0028	,0xa703	,0xa703	,0x0000	), // MODIFIER LETTER CHINESE TONE YANG SHANG
/*COMPOSE            */	DEADTRANS(	0x0029	,0xa703	,0xa705	,0x0000	), // MODIFIER LETTER CHINESE TONE YANG QU
/*COMPOSE            */	DEADTRANS(	0x00eb	,0x0063	,0xa700	,0x0001	), // MODIFIER LETTER CHINESE TONE YIN PING
/*COMPOSE            */	DEADTRANS(	0x0028	,0xa700	,0xa700	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN PING
/*COMPOSE            */	DEADTRANS(	0x0029	,0xa700	,0xa706	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN RU
/*COMPOSE            */	DEADTRANS(	0x005f	,0xa700	,0xa701	,0x0001	), // MODIFIER LETTER CHINESE TONE YANG PING
/*COMPOSE            */	DEADTRANS(	0x0028	,0xa701	,0xa701	,0x0000	), // MODIFIER LETTER CHINESE TONE YANG PING
/*COMPOSE            */	DEADTRANS(	0x0029	,0xa701	,0xa707	,0x0000	), // MODIFIER LETTER CHINESE TONE YANG RU
/*COMPOSE            */	DEADTRANS(	L'D'	,0x00a6	,0x0044	,0x0001	), // LATIN CAPITAL LETTER D
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0044	,0x00d0	,0x0000	), // LATIN CAPITAL LETTER ETH
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0044	,0x00d0	,0x0000	), // LATIN CAPITAL LETTER ETH
/*COMPOSE            */	DEADTRANS(	L'I'	,0x0044	,0x2300	,0x0000	), // DIAMETER SIGN
/*COMPOSE            */	DEADTRANS(	L'N'	,0x0044	,0x2669	,0x0000	), // QUARTER NOTE
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0044	,0x266f	,0x0000	), // MUSIC SHARP SIGN
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0044	,0x03f4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L't'	,0x0044	,0x03f4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L'Z'	,0x0044	,0x01f1	,0x0000	), // LATIN CAPITAL LETTER DZ
/*COMPOSE            */	DEADTRANS(	L'z'	,0x0044	,0x01f2	,0x0000	), // LATIN CAPITAL LETTER D WITH SMALL LETTER Z
/*COMPOSE            */	DEADTRANS(	0x00c8	,0x0044	,0x266f	,0x0000	), // MUSIC SHARP SIGN
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0044	,0x01c0	,0x0000	), // LATIN LETTER DENTAL CLICK
/*COMPOSE            */	DEADTRANS(	0x0023	,0x0044	,0x266f	,0x0000	), // MUSIC SHARP SIGN
/*COMPOSE            */	DEADTRANS(	0x0029	,0x0044	,0x266a	,0x0000	), // EIGHTH NOTE
/*COMPOSE            */	DEADTRANS(	0x005b	,0x0044	,0x266a	,0x0000	), // EIGHTH NOTE
/*COMPOSE            */	DEADTRANS(	0x005d	,0x0044	,0x266a	,0x0000	), // EIGHTH NOTE
/*COMPOSE            */	DEADTRANS(	L'd'	,0x00a6	,0x0064	,0x0001	), // LATIN SMALL LETTER D
/*COMPOSE            */	DEADTRANS(	L'b'	,0x0064	,0x0238	,0x0000	), // LATIN SMALL LETTER DB DIGRAPH
/*COMPOSE            */	DEADTRANS(	L'f'	,0x0064	,0xfb00	,0x0000	), // LATIN SMALL LIGATURE FF
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0064	,0x00d0	,0x0000	), // LATIN CAPITAL LETTER ETH
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0064	,0x00f0	,0x0000	), // LATIN SMALL LETTER ETH
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0064	,0x2300	,0x0000	), // DIAMETER SIGN
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0064	,0x1e9f	,0x0000	), // LATIN SMALL LETTER DELTA
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0064	,0x2669	,0x0000	), // QUARTER NOTE
/*COMPOSE            */	DEADTRANS(	L's'	,0x0064	,0x266f	,0x0000	), // MUSIC SHARP SIGN
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0064	,0x03f4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L't'	,0x0064	,0x03b8	,0x0000	), // GREEK SMALL LETTER THETA
/*COMPOSE            */	DEADTRANS(	L'u'	,0x0064	,0xa771	,0x0000	), // LATIN SMALL LETTER DUM
/*COMPOSE            */	DEADTRANS(	L'z'	,0x0064	,0x01f3	,0x0000	), // LATIN SMALL LETTER DZ
/*COMPOSE            */	DEADTRANS(	0x00e8	,0x0064	,0x266f	,0x0000	), // MUSIC SHARP SIGN
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0064	,0x01c0	,0x0000	), // LATIN LETTER DENTAL CLICK
/*COMPOSE            */	DEADTRANS(	0x0023	,0x0064	,0x266f	,0x0000	), // MUSIC SHARP SIGN
/*COMPOSE            */	DEADTRANS(	0x0026	,0x0064	,0x02a3	,0x0000	), // LATIN SMALL LETTER DZ DIGRAPH
/*COMPOSE            */	DEADTRANS(	0x0029	,0x0064	,0x266a	,0x0000	), // EIGHTH NOTE
/*COMPOSE            */	DEADTRANS(	0x005b	,0x0064	,0x266a	,0x0000	), // EIGHTH NOTE
/*COMPOSE            */	DEADTRANS(	0x005d	,0x0064	,0x266a	,0x0000	), // EIGHTH NOTE
/*COMPOSE            */	DEADTRANS(	0x00a9	,0x0064	,0x02a4	,0x0000	), // LATIN SMALL LETTER DEZH DIGRAPH
/*COMPOSE            */	DEADTRANS(	L'E'	,0x00a6	,0x0045	,0x0001	), // LATIN CAPITAL LETTER E
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0045	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0045	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0045	,0x018f	,0x0000	), // LATIN CAPITAL LETTER SCHWA
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0045	,0x018f	,0x0000	), // LATIN CAPITAL LETTER SCHWA
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0045	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0045	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0045	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0045	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0045	,0x212e	,0x0000	), // ESTIMATED SYMBOL
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0045	,0xa76a	,0x0000	), // LATIN CAPITAL LETTER ET
/*COMPOSE            */	DEADTRANS(	L't'	,0x0045	,0xa76a	,0x0000	), // LATIN CAPITAL LETTER ET
/*COMPOSE            */	DEADTRANS(	L'V'	,0x0045	,0x2205	,0x0000	), // EMPTY SET
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0045	,0xa72a	,0x0000	), // LATIN CAPITAL LETTER TRESILLO
/*COMPOSE            */	DEADTRANS(	L'7'	,0x0045	,0x204a	,0x0000	), // TIRONIAN SIGN ET
/*COMPOSE            */	DEADTRANS(	L'e'	,0x00a6	,0x0065	,0x0001	), // LATIN SMALL LETTER E
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0065	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0065	,0x025b	,0x0000	), // LATIN SMALL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0065	,0x018f	,0x0000	), // LATIN CAPITAL LETTER SCHWA
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0065	,0x0259	,0x0000	), // LATIN SMALL LETTER SCHWA
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0065	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0065	,0x025b	,0x0000	), // LATIN SMALL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0065	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0065	,0x025b	,0x0000	), // LATIN SMALL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L's'	,0x0065	,0x212e	,0x0000	), // ESTIMATED SYMBOL
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0065	,0xa76a	,0x0000	), // LATIN CAPITAL LETTER ET
/*COMPOSE            */	DEADTRANS(	L't'	,0x0065	,0xa76b	,0x0000	), // LATIN SMALL LETTER ET
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0065	,0x2205	,0x0000	), // EMPTY SET
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0065	,0xa72b	,0x0000	), // LATIN SMALL LETTER TRESILLO
/*COMPOSE            */	DEADTRANS(	L'7'	,0x0065	,0x204a	,0x0000	), // TIRONIAN SIGN ET
/*COMPOSE            */	DEADTRANS(	L'F'	,0x00a6	,0x0046	,0x0001	), // LATIN CAPITAL LETTER F
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0046	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'f'	,0x00a6	,0x0066	,0x0001	), // LATIN SMALL LETTER F
/*COMPOSE            */	DEADTRANS(	L'd'	,0x0066	,0xab35	,0x0000	), // LATIN SMALL LETTER LENIS F
/*COMPOSE            */	DEADTRANS(	L'f'	,0x0066	,0xfb00	,0x0001	), // LATIN SMALL LIGATURE FF
/*COMPOSE            */	DEADTRANS(	L'f'	,0xfb00	,0xfb00	,0x0000	), // LATIN SMALL LIGATURE FF
/*COMPOSE            */	DEADTRANS(	L'i'	,0xfb00	,0xfb03	,0x0000	), // LATIN SMALL LIGATURE FFI
/*COMPOSE            */	DEADTRANS(	L'l'	,0xfb00	,0xfb04	,0x0000	), // LATIN SMALL LIGATURE FFL
/*COMPOSE            */	DEADTRANS(	0x0020	,0xfb00	,0xfb00	,0x0000	), // LATIN SMALL LIGATURE FF
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0066	,0xfb01	,0x0000	), // LATIN SMALL LIGATURE FI
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0066	,0xfb02	,0x0000	), // LATIN SMALL LIGATURE FL
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0066	,0x02a9	,0x0000	), // LATIN SMALL LETTER FENG DIGRAPH
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0066	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'G'	,0x00a6	,0x0047	,0x0001	), // LATIN CAPITAL LETTER G
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0047	,0x264a	,0x0000	), // GEMINI
/*COMPOSE            */	DEADTRANS(	L'G'	,0x0047	,0x021c	,0x0000	), // LATIN CAPITAL LETTER YOGH
/*COMPOSE            */	DEADTRANS(	L'g'	,0x0047	,0x021c	,0x0000	), // LATIN CAPITAL LETTER YOGH
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0047	,0x01a2	,0x0000	), // LATIN CAPITAL LETTER OI
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0047	,0x01a2	,0x0000	), // LATIN CAPITAL LETTER OI
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0047	,0x0194	,0x0000	), // LATIN CAPITAL LETTER GAMMA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0047	,0x0194	,0x0000	), // LATIN CAPITAL LETTER GAMMA
/*COMPOSE            */	DEADTRANS(	L'M'	,0x0047	,0xfeff	,0x0000	), // ZERO WIDTH NO-BREAK SPACE
/*COMPOSE            */	DEADTRANS(	L'N'	,0x0047	,0x014a	,0x0000	), // LATIN CAPITAL LETTER ENG
/*COMPOSE            */	DEADTRANS(	L'R'	,0x0047	,0x03a9	,0x0000	), // GREEK CAPITAL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	0x00c9	,0x0047	,0x264a	,0x0000	), // GEMINI
/*COMPOSE            */	DEADTRANS(	L'g'	,0x00a6	,0x0067	,0x0001	), // LATIN SMALL LETTER G
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0067	,0x264a	,0x0000	), // GEMINI
/*COMPOSE            */	DEADTRANS(	L'G'	,0x0067	,0x021c	,0x0000	), // LATIN CAPITAL LETTER YOGH
/*COMPOSE            */	DEADTRANS(	L'g'	,0x0067	,0x021d	,0x0000	), // LATIN SMALL LETTER YOGH
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0067	,0x01a2	,0x0000	), // LATIN CAPITAL LETTER OI
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0067	,0x01a3	,0x0000	), // LATIN SMALL LETTER OI
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0067	,0x0263	,0x0000	), // LATIN SMALL LETTER GAMMA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0067	,0x0263	,0x0000	), // LATIN SMALL LETTER GAMMA
/*COMPOSE            */	DEADTRANS(	L'm'	,0x0067	,0x2060	,0x0000	), // WORD JOINER
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0067	,0x014b	,0x0000	), // LATIN SMALL LETTER ENG
/*COMPOSE            */	DEADTRANS(	L'r'	,0x0067	,0x03a9	,0x0000	), // GREEK CAPITAL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	0x00e9	,0x0067	,0x264a	,0x0000	), // GEMINI
/*COMPOSE            */	DEADTRANS(	L'H'	,0x00a6	,0x0048	,0x0001	), // LATIN CAPITAL LETTER H
/*COMPOSE            */	DEADTRANS(	L'D'	,0x0048	,0x00d0	,0x0000	), // LATIN CAPITAL LETTER ETH
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0048	,0x2135	,0x0000	), // ALEF SYMBOL
/*COMPOSE            */	DEADTRANS(	L'G'	,0x0048	,0x01a2	,0x0000	), // LATIN CAPITAL LETTER OI
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0048	,0x210d	,0x0000	), // DOUBLE-STRUCK CAPITAL H
/*COMPOSE            */	DEADTRANS(	L'N'	,0x0048	,0xa726	,0x0000	), // LATIN CAPITAL LETTER HENG
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0048	,0xa726	,0x0000	), // LATIN CAPITAL LETTER HENG
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0048	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0048	,0x01a9	,0x0000	), // LATIN CAPITAL LETTER ESH
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0048	,0x00de	,0x0000	), // LATIN CAPITAL LETTER THORN
/*COMPOSE            */	DEADTRANS(	L'W'	,0x0048	,0x01f6	,0x0000	), // LATIN CAPITAL LETTER HWAIR
/*COMPOSE            */	DEADTRANS(	L'w'	,0x0048	,0x01f6	,0x0000	), // LATIN CAPITAL LETTER HWAIR
/*COMPOSE            */	DEADTRANS(	L'Z'	,0x0048	,0x01b7	,0x0000	), // LATIN CAPITAL LETTER EZH
/*COMPOSE            */	DEADTRANS(	0x0028	,0x0048	,0x2c75	,0x0000	), // LATIN CAPITAL LETTER HALF H
/*COMPOSE            */	DEADTRANS(	0x003c	,0x0048	,0x02f9	,0x0000	), // MODIFIER LETTER BEGIN HIGH TONE
/*COMPOSE            */	DEADTRANS(	0x003e	,0x0048	,0x02fa	,0x0000	), // MODIFIER LETTER END HIGH TONE
/*COMPOSE            */	DEADTRANS(	L'h'	,0x00a6	,0x0068	,0x0001	), // LATIN SMALL LETTER H
/*COMPOSE            */	DEADTRANS(	L'd'	,0x0068	,0x00f0	,0x0000	), // LATIN SMALL LETTER ETH
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0068	,0x2135	,0x0000	), // ALEF SYMBOL
/*COMPOSE            */	DEADTRANS(	L'g'	,0x0068	,0x01a3	,0x0000	), // LATIN SMALL LETTER OI
/*COMPOSE            */	DEADTRANS(	L'N'	,0x0068	,0xa726	,0x0000	), // LATIN CAPITAL LETTER HENG
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0068	,0xa727	,0x0000	), // LATIN SMALL LETTER HENG
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0068	,0x0254	,0x0000	), // LATIN SMALL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L's'	,0x0068	,0x0283	,0x0000	), // LATIN SMALL LETTER ESH
/*COMPOSE            */	DEADTRANS(	L't'	,0x0068	,0x00fe	,0x0000	), // LATIN SMALL LETTER THORN
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0068	,0x0195	,0x0000	), // LATIN SMALL LETTER HV
/*COMPOSE            */	DEADTRANS(	L'z'	,0x0068	,0x0292	,0x0000	), // LATIN SMALL LETTER EZH
/*COMPOSE            */	DEADTRANS(	0x0028	,0x0068	,0x2c76	,0x0000	), // LATIN SMALL LETTER HALF H
/*COMPOSE            */	DEADTRANS(	0x003c	,0x0068	,0x02f9	,0x0000	), // MODIFIER LETTER BEGIN HIGH TONE
/*COMPOSE            */	DEADTRANS(	0x003e	,0x0068	,0x02fa	,0x0000	), // MODIFIER LETTER END HIGH TONE
/*COMPOSE            */	DEADTRANS(	L'I'	,0x00a6	,0x0049	,0x0001	), // LATIN CAPITAL LETTER I
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0049	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'D'	,0x0049	,0x2300	,0x0000	), // DIAMETER SIGN
/*COMPOSE            */	DEADTRANS(	L'F'	,0x0049	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'I'	,0x0049	,0xa7ae	,0x0000	), // LATIN CAPITAL LETTER SMALL CAPITAL I
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0049	,0xa7ae	,0x0000	), // LATIN CAPITAL LETTER SMALL CAPITAL I
/*COMPOSE            */	DEADTRANS(	L'J'	,0x0049	,0x0132	,0x0000	), // LATIN CAPITAL LIGATURE IJ
/*COMPOSE            */	DEADTRANS(	L'j'	,0x0049	,0x0132	,0x0000	), // LATIN CAPITAL LIGATURE IJ
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0049	,0x0196	,0x0000	), // LATIN CAPITAL LETTER IOTA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0049	,0x0196	,0x0000	), // LATIN CAPITAL LETTER IOTA
/*COMPOSE            */	DEADTRANS(	L'M'	,0x0049	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0049	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'P'	,0x0049	,0x00b6	,0x0000	), // PILCROW SIGN
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0049	,0xa76c	,0x0000	), // LATIN CAPITAL LETTER IS
/*COMPOSE            */	DEADTRANS(	L's'	,0x0049	,0xa76c	,0x0000	), // LATIN CAPITAL LETTER IS
/*COMPOSE            */	DEADTRANS(	0x00f9	,0x0049	,0xa78b	,0x0000	), // LATIN CAPITAL LETTER SALTILLO
/*COMPOSE            */	DEADTRANS(	0x0027	,0x0049	,0xa78b	,0x0000	), // LATIN CAPITAL LETTER SALTILLO
/*COMPOSE            */	DEADTRANS(	L'4'	,0x0049	,0xa72c	,0x0000	), // LATIN CAPITAL LETTER CUATRILLO
/*COMPOSE            */	DEADTRANS(	0x2019	,0x0049	,0xa78b	,0x0000	), // LATIN CAPITAL LETTER SALTILLO
/*COMPOSE            */	DEADTRANS(	L'i'	,0x00a6	,0x0069	,0x0001	), // LATIN SMALL LETTER I
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0069	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'd'	,0x0069	,0x2300	,0x0000	), // DIAMETER SIGN
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0069	,0xab61	,0x0000	), // LATIN SMALL LETTER IOTIFIED E
/*COMPOSE            */	DEADTRANS(	L'f'	,0x0069	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'I'	,0x0069	,0xa7ae	,0x0000	), // LATIN CAPITAL LETTER SMALL CAPITAL I
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0069	,0x026a	,0x0000	), // LATIN LETTER SMALL CAPITAL I
/*COMPOSE            */	DEADTRANS(	L'J'	,0x0069	,0x0132	,0x0000	), // LATIN CAPITAL LIGATURE IJ
/*COMPOSE            */	DEADTRANS(	L'j'	,0x0069	,0x0133	,0x0000	), // LATIN SMALL LIGATURE IJ
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0069	,0x0269	,0x0000	), // LATIN SMALL LETTER IOTA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0069	,0x0269	,0x0000	), // LATIN SMALL LETTER IOTA
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0069	,0x2282	,0x0000	), // SUBSET OF
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0069	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'P'	,0x0069	,0x00b6	,0x0000	), // PILCROW SIGN
/*COMPOSE            */	DEADTRANS(	L'p'	,0x0069	,0x00b6	,0x0000	), // PILCROW SIGN
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0069	,0xa76c	,0x0000	), // LATIN CAPITAL LETTER IS
/*COMPOSE            */	DEADTRANS(	L's'	,0x0069	,0xa76d	,0x0000	), // LATIN SMALL LETTER IS
/*COMPOSE            */	DEADTRANS(	0x00f9	,0x0069	,0xa78c	,0x0000	), // LATIN SMALL LETTER SALTILLO
/*COMPOSE            */	DEADTRANS(	0x0027	,0x0069	,0xa78c	,0x0000	), // LATIN SMALL LETTER SALTILLO
/*COMPOSE            */	DEADTRANS(	0x002f	,0x0069	,0x2284	,0x0000	), // NOT A SUBSET OF
/*COMPOSE            */	DEADTRANS(	L'4'	,0x0069	,0xa72d	,0x0000	), // LATIN SMALL LETTER CUATRILLO
/*COMPOSE            */	DEADTRANS(	0x2019	,0x0069	,0xa78c	,0x0000	), // LATIN SMALL LETTER SALTILLO
/*COMPOSE            */	DEADTRANS(	L'J'	,0x00a6	,0x004a	,0x0001	), // LATIN CAPITAL LETTER J
/*COMPOSE            */	DEADTRANS(	L'j'	,0x00a6	,0x006a	,0x0001	), // LATIN SMALL LETTER J
/*COMPOSE            */	DEADTRANS(	L'K'	,0x00a6	,0x004b	,0x0001	), // LATIN CAPITAL LETTER K
/*COMPOSE            */	DEADTRANS(	L'B'	,0x004b	,0x2328	,0x0000	), // KEYBOARD
/*COMPOSE            */	DEADTRANS(	L'k'	,0x00a6	,0x006b	,0x0001	), // LATIN SMALL LETTER K
/*COMPOSE            */	DEADTRANS(	L'b'	,0x006b	,0x2328	,0x0000	), // KEYBOARD
/*COMPOSE            */	DEADTRANS(	L'r'	,0x006b	,0x0138	,0x0000	), // LATIN SMALL LETTER KRA
/*COMPOSE            */	DEADTRANS(	L'L'	,0x00a6	,0x004c	,0x0001	), // LATIN CAPITAL LETTER L
/*COMPOSE            */	DEADTRANS(	L'A'	,0x004c	,0x2c6d	,0x0000	), // LATIN CAPITAL LETTER ALPHA
/*COMPOSE            */	DEADTRANS(	L'B'	,0x004c	,0xa7b4	,0x0000	), // LATIN CAPITAL LETTER BETA
/*COMPOSE            */	DEADTRANS(	L'E'	,0x004c	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'G'	,0x004c	,0x0194	,0x0000	), // LATIN CAPITAL LETTER GAMMA
/*COMPOSE            */	DEADTRANS(	L'I'	,0x004c	,0x264c	,0x0000	), // LEO
/*COMPOSE            */	DEADTRANS(	L'J'	,0x004c	,0x01c7	,0x0000	), // LATIN CAPITAL LETTER LJ
/*COMPOSE            */	DEADTRANS(	L'j'	,0x004c	,0x01c8	,0x0000	), // LATIN CAPITAL LETTER L WITH SMALL LETTER J
/*COMPOSE            */	DEADTRANS(	L'L'	,0x004c	,0x1efa	,0x0000	), // LATIN CAPITAL LETTER MIDDLE-WELSH LL
/*COMPOSE            */	DEADTRANS(	L'L'	,0x006c	,0x1efa	,0x0000	), // LATIN CAPITAL LETTER MIDDLE-WELSH LL
/*COMPOSE            */	DEADTRANS(	L'O'	,0x004c	,0xa7b6	,0x0000	), // LATIN CAPITAL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	L'T'	,0x004c	,0x03f4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L'X'	,0x004c	,0xa7b3	,0x0000	), // LATIN CAPITAL LETTER CHI
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x004c	,0x01b1	,0x0000	), // LATIN CAPITAL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	0x0021	,0x004c	,0x01c1	,0x0000	), // LATIN LETTER LATERAL CLICK
/*COMPOSE            */	DEADTRANS(	L'l'	,0x00a6	,0x006c	,0x0001	), // LATIN SMALL LETTER L
/*COMPOSE            */	DEADTRANS(	L'a'	,0x006c	,0x0251	,0x0000	), // LATIN SMALL LETTER ALPHA
/*COMPOSE            */	DEADTRANS(	L'b'	,0x006c	,0xa7b5	,0x0000	), // LATIN SMALL LETTER BETA
/*COMPOSE            */	DEADTRANS(	L'c'	,0x006c	,0x2113	,0x0000	), // SCRIPT SMALL L
/*COMPOSE            */	DEADTRANS(	L'd'	,0x006c	,0x1e9f	,0x0000	), // LATIN SMALL LETTER DELTA
/*COMPOSE            */	DEADTRANS(	L'e'	,0x006c	,0x025b	,0x0000	), // LATIN SMALL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'f'	,0x006c	,0xfb00	,0x0000	), // LATIN SMALL LIGATURE FF
/*COMPOSE            */	DEADTRANS(	L'g'	,0x006c	,0x0263	,0x0000	), // LATIN SMALL LETTER GAMMA
/*COMPOSE            */	DEADTRANS(	L'i'	,0x006c	,0x264c	,0x0000	), // LEO
/*COMPOSE            */	DEADTRANS(	L'j'	,0x006c	,0x01c9	,0x0000	), // LATIN SMALL LETTER LJ
/*COMPOSE            */	DEADTRANS(	L'l'	,0x004c	,0x1efa	,0x0000	), // LATIN CAPITAL LETTER MIDDLE-WELSH LL
/*COMPOSE            */	DEADTRANS(	L'l'	,0x006c	,0x1efb	,0x0000	), // LATIN SMALL LETTER MIDDLE-WELSH LL
/*COMPOSE            */	DEADTRANS(	L'o'	,0x006c	,0xa7b7	,0x0000	), // LATIN SMALL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	L's'	,0x006c	,0x02aa	,0x0000	), // LATIN SMALL LETTER LS DIGRAPH
/*COMPOSE            */	DEADTRANS(	L't'	,0x006c	,0x03b8	,0x0000	), // GREEK SMALL LETTER THETA
/*COMPOSE            */	DEADTRANS(	L'u'	,0x006c	,0xa772	,0x0000	), // LATIN SMALL LETTER LUM
/*COMPOSE            */	DEADTRANS(	L'x'	,0x006c	,0xab53	,0x0000	), // LATIN SMALL LETTER CHI
/*COMPOSE            */	DEADTRANS(	L'y'	,0x006c	,0x028a	,0x0000	), // LATIN SMALL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'z'	,0x006c	,0x02ab	,0x0001	), // LATIN SMALL LETTER LZ DIGRAPH
/*COMPOSE            */	DEADTRANS(	L'h'	,0x02ab	,0x026e	,0x0000	), // LATIN SMALL LETTER LEZH
/*COMPOSE            */	DEADTRANS(	0x0020	,0x02ab	,0x02ab	,0x0000	), // LATIN SMALL LETTER LZ DIGRAPH
/*COMPOSE            */	DEADTRANS(	0x002e	,0x02ab	,0x02ab	,0x0000	), // LATIN SMALL LETTER LZ DIGRAPH
/*COMPOSE            */	DEADTRANS(	0x0021	,0x006c	,0x01c1	,0x0000	), // LATIN LETTER LATERAL CLICK
/*COMPOSE            */	DEADTRANS(	0x0025	,0x006c	,0xab37	,0x0000	), // LATIN SMALL LETTER L WITH INVERTED LAZY S
/*COMPOSE            */	DEADTRANS(	0x00b0	,0x006c	,0xab58	,0x0000	), // LATIN SMALL LETTER X WITH LONG LEFT LEG AND LOW RIGHT RING
/*COMPOSE            */	DEADTRANS(	L'M'	,0x00a6	,0x004d	,0x0001	), // LATIN CAPITAL LETTER M
/*COMPOSE            */	DEADTRANS(	L'A'	,0x004d	,0xa7ff	,0x0000	), // LATIN EPIGRAPHIC LETTER ARCHAIC M
/*COMPOSE            */	DEADTRANS(	L'a'	,0x004d	,0xa7ff	,0x0000	), // LATIN EPIGRAPHIC LETTER ARCHAIC M
/*COMPOSE            */	DEADTRANS(	L'C'	,0x004d	,0xdd6a	,0x0000	), // U+1F16A; input D83C high surrogate first; RAISED MC SIGN
/*COMPOSE            */	DEADTRANS(	L'D'	,0x004d	,0xdd6b	,0x0000	), // U+1F16B; input D83C high surrogate first; RAISED MD SIGN
/*COMPOSE            */	DEADTRANS(	L'M'	,0x004d	,0x2133	,0x0001	), // SCRIPT CAPITAL M
/*COMPOSE            */	DEADTRANS(	L'O'	,0x004d	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'T'	,0x004d	,0x2122	,0x0000	), // TRADE MARK SIGN
/*COMPOSE            */	DEADTRANS(	L'W'	,0x004d	,0xa7ff	,0x0000	), // LATIN EPIGRAPHIC LETTER ARCHAIC M
/*COMPOSE            */	DEADTRANS(	L'm'	,0x00a6	,0x006d	,0x0001	), // LATIN SMALL LETTER M
/*COMPOSE            */	DEADTRANS(	L'A'	,0x006d	,0xa7ff	,0x0000	), // LATIN EPIGRAPHIC LETTER ARCHAIC M
/*COMPOSE            */	DEADTRANS(	L'c'	,0x006d	,0xdd6a	,0x0000	), // U+1F16A; input D83C high surrogate first; RAISED MC SIGN
/*COMPOSE            */	DEADTRANS(	L'd'	,0x006d	,0xdd6b	,0x0000	), // U+1F16B; input D83C high surrogate first; RAISED MD SIGN
/*COMPOSE            */	DEADTRANS(	L'i'	,0x006d	,0x00b5	,0x0000	), // MICRO SIGN
/*COMPOSE            */	DEADTRANS(	L'm'	,0x006d	,0x2133	,0x0001	), // SCRIPT CAPITAL M
/*COMPOSE            */	DEADTRANS(	L'o'	,0x006d	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L't'	,0x006d	,0x2122	,0x0000	), // TRADE MARK SIGN
/*COMPOSE            */	DEADTRANS(	L'u'	,0x006d	,0xa773	,0x0000	), // LATIN SMALL LETTER MUM
/*COMPOSE            */	DEADTRANS(	L'N'	,0x00a6	,0x004e	,0x0001	), // LATIN CAPITAL LETTER N
/*COMPOSE            */	DEADTRANS(	L'C'	,0x004e	,0x265e	,0x0000	), // BLACK CHESS KNIGHT
/*COMPOSE            */	DEADTRANS(	L'D'	,0x004e	,0x265b	,0x0000	), // BLACK CHESS QUEEN
/*COMPOSE            */	DEADTRANS(	L'F'	,0x004e	,0x265d	,0x0000	), // BLACK CHESS BISHOP
/*COMPOSE            */	DEADTRANS(	L'G'	,0x004e	,0x014a	,0x0000	), // LATIN CAPITAL LETTER ENG
/*COMPOSE            */	DEADTRANS(	L'g'	,0x004e	,0x014a	,0x0000	), // LATIN CAPITAL LETTER ENG
/*COMPOSE            */	DEADTRANS(	L'J'	,0x004e	,0x01ca	,0x0000	), // LATIN CAPITAL LETTER NJ
/*COMPOSE            */	DEADTRANS(	L'j'	,0x004e	,0x01cb	,0x0000	), // LATIN CAPITAL LETTER N WITH SMALL LETTER J
/*COMPOSE            */	DEADTRANS(	L'L'	,0x004e	,0x0220	,0x0000	), // LATIN CAPITAL LETTER N WITH LONG RIGHT LEG
/*COMPOSE            */	DEADTRANS(	L'l'	,0x004e	,0x0220	,0x0000	), // LATIN CAPITAL LETTER N WITH LONG RIGHT LEG
/*COMPOSE            */	DEADTRANS(	L'N'	,0x004e	,0x2115	,0x0000	), // DOUBLE-STRUCK CAPITAL N
/*COMPOSE            */	DEADTRANS(	L'O'	,0x004e	,0x2116	,0x0000	), // NUMERO SIGN
/*COMPOSE            */	DEADTRANS(	L'o'	,0x004e	,0x2116	,0x0000	), // NUMERO SIGN
/*COMPOSE            */	DEADTRANS(	L'P'	,0x004e	,0x265f	,0x0000	), // BLACK CHESS PAWN
/*COMPOSE            */	DEADTRANS(	L'R'	,0x004e	,0x265a	,0x0000	), // BLACK CHESS KING
/*COMPOSE            */	DEADTRANS(	L'T'	,0x004e	,0x265c	,0x0000	), // BLACK CHESS ROOK
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x004e	,0x019d	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*COMPOSE            */	DEADTRANS(	L'y'	,0x004e	,0x019d	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*COMPOSE            */	DEADTRANS(	L'n'	,0x00a6	,0x006e	,0x0001	), // LATIN SMALL LETTER N
/*COMPOSE            */	DEADTRANS(	L'c'	,0x006e	,0x265e	,0x0000	), // BLACK CHESS KNIGHT
/*COMPOSE            */	DEADTRANS(	L'd'	,0x006e	,0x265b	,0x0000	), // BLACK CHESS QUEEN
/*COMPOSE            */	DEADTRANS(	L'f'	,0x006e	,0x265d	,0x0000	), // BLACK CHESS BISHOP
/*COMPOSE            */	DEADTRANS(	L'G'	,0x006e	,0x014a	,0x0000	), // LATIN CAPITAL LETTER ENG
/*COMPOSE            */	DEADTRANS(	L'g'	,0x006e	,0x014b	,0x0000	), // LATIN SMALL LETTER ENG
/*COMPOSE            */	DEADTRANS(	L'i'	,0x006e	,0x2283	,0x0000	), // SUPERSET OF
/*COMPOSE            */	DEADTRANS(	L'j'	,0x006e	,0x01cc	,0x0000	), // LATIN SMALL LETTER NJ
/*COMPOSE            */	DEADTRANS(	L'l'	,0x006e	,0x019e	,0x0000	), // LATIN SMALL LETTER N WITH LONG RIGHT LEG
/*COMPOSE            */	DEADTRANS(	L'n'	,0x006e	,0x2669	,0x0000	), // QUARTER NOTE
/*COMPOSE            */	DEADTRANS(	L'O'	,0x006e	,0x2116	,0x0000	), // NUMERO SIGN
/*COMPOSE            */	DEADTRANS(	L'o'	,0x006e	,0x2116	,0x0000	), // NUMERO SIGN
/*COMPOSE            */	DEADTRANS(	L'p'	,0x006e	,0x265f	,0x0000	), // BLACK CHESS PAWN
/*COMPOSE            */	DEADTRANS(	L'r'	,0x006e	,0x265a	,0x0000	), // BLACK CHESS KING
/*COMPOSE            */	DEADTRANS(	L't'	,0x006e	,0x265c	,0x0000	), // BLACK CHESS ROOK
/*COMPOSE            */	DEADTRANS(	L'u'	,0x006e	,0xa774	,0x0000	), // LATIN SMALL LETTER NUM
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x006e	,0x019d	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*COMPOSE            */	DEADTRANS(	L'y'	,0x006e	,0x0272	,0x0000	), // LATIN SMALL LETTER N WITH LEFT HOOK
/*COMPOSE            */	DEADTRANS(	0x002f	,0x006e	,0x2285	,0x0000	), // NOT A SUPERSET OF
/*COMPOSE            */	DEADTRANS(	L'O'	,0x00a6	,0x004f	,0x0001	), // LATIN CAPITAL LETTER O
/*COMPOSE            */	DEADTRANS(	L'A'	,0x004f	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'a'	,0x004f	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'C'	,0x004f	,0x00a9	,0x0000	), // COPYRIGHT SIGN
/*COMPOSE            */	DEADTRANS(	L'D'	,0x004f	,0xdd2f	,0x0000	), // U+1F12F; input D83C high surrogate first; COPYLEFT SYMBOL
/*COMPOSE            */	DEADTRANS(	L'E'	,0x004f	,0x0152	,0x0000	), // LATIN CAPITAL LIGATURE OE
/*COMPOSE            */	DEADTRANS(	L'e'	,0x004f	,0x0152	,0x0000	), // LATIN CAPITAL LIGATURE OE
/*COMPOSE            */	DEADTRANS(	L'F'	,0x004f	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'H'	,0x004f	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'h'	,0x004f	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'I'	,0x004f	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'L'	,0x004f	,0xa7b6	,0x0000	), // LATIN CAPITAL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x004f	,0xa7b6	,0x0000	), // LATIN CAPITAL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	L'M'	,0x004f	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'O'	,0x004f	,0xa74e	,0x0000	), // LATIN CAPITAL LETTER OO
/*COMPOSE            */	DEADTRANS(	L'o'	,0x004f	,0xa74e	,0x0000	), // LATIN CAPITAL LETTER OO
/*COMPOSE            */	DEADTRANS(	L'P'	,0x004f	,0x2117	,0x0000	), // SOUND RECORDING COPYRIGHT
/*COMPOSE            */	DEADTRANS(	L'R'	,0x004f	,0x00ae	,0x0000	), // REGISTERED SIGN
/*COMPOSE            */	DEADTRANS(	L'U'	,0x004f	,0x0222	,0x0000	), // LATIN CAPITAL LETTER OU
/*COMPOSE            */	DEADTRANS(	L'u'	,0x004f	,0x0222	,0x0000	), // LATIN CAPITAL LETTER OU
/*COMPOSE            */	DEADTRANS(	L'3'	,0x004f	,0xa79c	,0x0000	), // LATIN CAPITAL LETTER VOLAPUK OE
/*COMPOSE            */	DEADTRANS(	0x005f	,0x004f	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	0x0186	,0x004f	,0xdd2f	,0x0000	), // U+1F12F; input D83C high surrogate first; COPYLEFT SYMBOL
/*COMPOSE            */	DEADTRANS(	L'o'	,0x00a6	,0x006f	,0x0001	), // LATIN SMALL LETTER O
/*COMPOSE            */	DEADTRANS(	L'A'	,0x006f	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'a'	,0x006f	,0x0254	,0x0000	), // LATIN SMALL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'c'	,0x006f	,0x00a9	,0x0000	), // COPYRIGHT SIGN
/*COMPOSE            */	DEADTRANS(	L'd'	,0x006f	,0xdd2f	,0x0000	), // U+1F12F; input D83C high surrogate first; COPYLEFT SYMBOL
/*COMPOSE            */	DEADTRANS(	L'E'	,0x006f	,0x0152	,0x0000	), // LATIN CAPITAL LIGATURE OE
/*COMPOSE            */	DEADTRANS(	L'e'	,0x006f	,0x0153	,0x0000	), // LATIN SMALL LIGATURE OE
/*COMPOSE            */	DEADTRANS(	L'f'	,0x006f	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'H'	,0x006f	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'h'	,0x006f	,0x0254	,0x0000	), // LATIN SMALL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'i'	,0x006f	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'L'	,0x006f	,0xa7b7	,0x0000	), // LATIN SMALL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x006f	,0xa7b7	,0x0000	), // LATIN SMALL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	L'm'	,0x006f	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'O'	,0x006f	,0xa74e	,0x0000	), // LATIN CAPITAL LETTER OO
/*COMPOSE            */	DEADTRANS(	L'o'	,0x006f	,0xa74f	,0x0000	), // LATIN SMALL LETTER OO
/*COMPOSE            */	DEADTRANS(	L'p'	,0x006f	,0x2117	,0x0000	), // SOUND RECORDING COPYRIGHT
/*COMPOSE            */	DEADTRANS(	L'r'	,0x006f	,0x00ae	,0x0000	), // REGISTERED SIGN
/*COMPOSE            */	DEADTRANS(	L'U'	,0x006f	,0x0222	,0x0000	), // LATIN CAPITAL LETTER OU
/*COMPOSE            */	DEADTRANS(	L'u'	,0x006f	,0x0223	,0x0000	), // LATIN SMALL LETTER OU
/*COMPOSE            */	DEADTRANS(	0x0028	,0x006f	,0x1d16	,0x0000	), // LATIN SMALL LETTER TOP HALF O
/*COMPOSE            */	DEADTRANS(	0x0029	,0x006f	,0x1d17	,0x0000	), // LATIN SMALL LETTER BOTTOM HALF O
/*COMPOSE            */	DEADTRANS(	L'3'	,0x006f	,0xa79d	,0x0000	), // LATIN SMALL LETTER VOLAPUK OE
/*COMPOSE            */	DEADTRANS(	0x005f	,0x006f	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	0x0254	,0x006f	,0xdd2f	,0x0000	), // U+1F12F; input D83C high surrogate first; COPYLEFT SYMBOL
/*COMPOSE            */	DEADTRANS(	L'P'	,0x00a6	,0x0050	,0x0000	), // LATIN CAPITAL LETTER P
/*COMPOSE            */	DEADTRANS(	L'M'	,0x0050	,0x00b6	,0x0000	), // PILCROW SIGN
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0050	,0x2653	,0x0000	), // PISCES
/*COMPOSE            */	DEADTRANS(	L'P'	,0x0050	,0x2119	,0x0000	), // DOUBLE-STRUCK CAPITAL P
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0050	,0x0297	,0x0000	), // LATIN LETTER STRETCHED C
/*COMPOSE            */	DEADTRANS(	L'p'	,0x00a6	,0x0070	,0x0001	), // LATIN SMALL LETTER P
/*COMPOSE            */	DEADTRANS(	L'g'	,0x0070	,0x0264	,0x0000	), // LATIN SMALL LETTER RAMS HORN
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0070	,0x0278	,0x0000	), // LATIN SMALL LETTER PHI
/*COMPOSE            */	DEADTRANS(	L'm'	,0x0070	,0x00b6	,0x0000	), // PILCROW SIGN
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0070	,0x2653	,0x0000	), // PISCES
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0070	,0x0297	,0x0000	), // LATIN LETTER STRETCHED C
/*COMPOSE            */	DEADTRANS(	L'Q'	,0x00a6	,0x0051	,0x0001	), // LATIN CAPITAL LETTER Q
/*COMPOSE            */	DEADTRANS(	L'Q'	,0x0051	,0x211a	,0x0000	), // DOUBLE-STRUCK CAPITAL Q
/*COMPOSE            */	DEADTRANS(	L'q'	,0x00a6	,0x0071	,0x0001	), // LATIN SMALL LETTER Q
/*COMPOSE            */	DEADTRANS(	L'p'	,0x0071	,0x0239	,0x0000	), // LATIN SMALL LETTER QP DIGRAPH
/*COMPOSE            */	DEADTRANS(	L'R'	,0x00a6	,0x0052	,0x0001	), // LATIN CAPITAL LETTER R
/*COMPOSE            */	DEADTRANS(	L'R'	,0x0052	,0x211d	,0x0000	), // DOUBLE-STRUCK CAPITAL R
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0052	,0x01c3	,0x0000	), // LATIN LETTER RETROFLEX CLICK
/*COMPOSE            */	DEADTRANS(	L'r'	,0x00a6	,0x0072	,0x0001	), // LATIN SMALL LETTER R
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0072	,0x027c	,0x0000	), // LATIN SMALL LETTER R WITH LONG LEG
/*COMPOSE            */	DEADTRANS(	L'r'	,0x0072	,0xab48	,0x0000	), // LATIN SMALL LETTER DOUBLE R
/*COMPOSE            */	DEADTRANS(	L'u'	,0x0072	,0xa775	,0x0000	), // LATIN SMALL LETTER RUM
/*COMPOSE            */	DEADTRANS(	0x00e9	,0x0072	,0xab45	,0x0000	), // LATIN SMALL LETTER STIRRUP R
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0072	,0x01c3	,0x0000	), // LATIN LETTER RETROFLEX CLICK
/*COMPOSE            */	DEADTRANS(	L'S'	,0x00a6	,0x0053	,0x0001	), // LATIN CAPITAL LETTER S
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0053	,0x2650	,0x0000	), // SAGITTARIUS
/*COMPOSE            */	DEADTRANS(	L'C'	,0x0053	,0x264f	,0x0000	), // SCORPIUS
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0053	,0x212e	,0x0000	), // ESTIMATED SYMBOL
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0053	,0x01a9	,0x0000	), // LATIN CAPITAL LETTER ESH
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0053	,0x01a9	,0x0000	), // LATIN CAPITAL LETTER ESH
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0053	,0x1e9e	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	L's'	,0x0053	,0x1e9e	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	L'Z'	,0x0053	,0x1e9e	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	L'z'	,0x0053	,0x1e9e	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	L's'	,0x00a6	,0x0073	,0x0001	), // LATIN SMALL LETTER S
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0073	,0x2650	,0x0000	), // SAGITTARIUS
/*COMPOSE            */	DEADTRANS(	L'c'	,0x0073	,0x264f	,0x0000	), // SCORPIUS
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0073	,0x212e	,0x0000	), // ESTIMATED SYMBOL
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0073	,0x01a9	,0x0000	), // LATIN CAPITAL LETTER ESH
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0073	,0x0283	,0x0000	), // LATIN SMALL LETTER ESH
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0073	,0x017f	,0x0000	), // LATIN SMALL LETTER LONG S
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0073	,0x1e9e	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	L's'	,0x0073	,0x00df	,0x0000	), // LATIN SMALL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	L't'	,0x0073	,0xfb06	,0x0000	), // LATIN SMALL LIGATURE ST
/*COMPOSE            */	DEADTRANS(	L'Z'	,0x0073	,0x1e9e	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	L'z'	,0x0073	,0x00df	,0x0000	), // LATIN SMALL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	0x002e	,0x0073	,0xa78f	,0x0000	), // LATIN LETTER SINOLOGICAL DOT
/*COMPOSE            */	DEADTRANS(	L'0'	,0x0073	,0x2648	,0x0001	), // ARIES
/*COMPOSE            */	DEADTRANS(	L'1'	,0x2648	,0x2648	,0x0000	), // ARIES
/*COMPOSE            */	DEADTRANS(	L'2'	,0x2648	,0x2649	,0x0000	), // TAURUS
/*COMPOSE            */	DEADTRANS(	L'3'	,0x2648	,0x264a	,0x0000	), // GEMINI
/*COMPOSE            */	DEADTRANS(	L'4'	,0x2648	,0x264b	,0x0000	), // CANCER
/*COMPOSE            */	DEADTRANS(	L'5'	,0x2648	,0x264c	,0x0000	), // LEO
/*COMPOSE            */	DEADTRANS(	L'6'	,0x2648	,0x264d	,0x0000	), // VIRGO
/*COMPOSE            */	DEADTRANS(	L'7'	,0x2648	,0x264e	,0x0000	), // LIBRA
/*COMPOSE            */	DEADTRANS(	L'8'	,0x2648	,0x264f	,0x0000	), // SCORPIUS
/*COMPOSE            */	DEADTRANS(	L'9'	,0x2648	,0x2650	,0x0000	), // SAGITTARIUS
/*COMPOSE            */	DEADTRANS(	L'1'	,0x0073	,0x2651	,0x0001	), // CAPRICORN
/*COMPOSE            */	DEADTRANS(	L'0'	,0x2651	,0x2651	,0x0000	), // CAPRICORN
/*COMPOSE            */	DEADTRANS(	L'1'	,0x2651	,0x2652	,0x0000	), // AQUARIUS
/*COMPOSE            */	DEADTRANS(	L'2'	,0x2651	,0x2653	,0x0000	), // PISCES
/*COMPOSE            */	DEADTRANS(	0x007c	,0x0073	,0xfb05	,0x0000	), // LATIN SMALL LIGATURE LONG S T
/*COMPOSE            */	DEADTRANS(	L'T'	,0x00a6	,0x0054	,0x0001	), // LATIN CAPITAL LETTER T
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0054	,0x2649	,0x0000	), // TAURUS
/*COMPOSE            */	DEADTRANS(	L'D'	,0x0054	,0x03f4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0054	,0x204a	,0x0000	), // TIRONIAN SIGN ET
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0054	,0x00de	,0x0000	), // LATIN CAPITAL LETTER THORN
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0054	,0x00de	,0x0000	), // LATIN CAPITAL LETTER THORN
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0054	,0x03f4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0054	,0x03f4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L'M'	,0x0054	,0x2122	,0x0000	), // TRADE MARK SIGN
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0054	,0x03f4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L't'	,0x0054	,0x03f4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L'Z'	,0x0054	,0xa728	,0x0000	), // LATIN CAPITAL LETTER TZ
/*COMPOSE            */	DEADTRANS(	L'z'	,0x0054	,0xa728	,0x0000	), // LATIN CAPITAL LETTER TZ
/*COMPOSE            */	DEADTRANS(	0x002f	,0x0054	,0x02d4	,0x0000	), // MODIFIER LETTER UP TACK
/*COMPOSE            */	DEADTRANS(	L'2'	,0x0054	,0x01a7	,0x0000	), // LATIN CAPITAL LETTER TONE TWO
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0054	,0x0417	,0x0000	), // CYRILLIC CAPITAL LETTER ZE
/*COMPOSE            */	DEADTRANS(	L'4'	,0x0054	,0x0427	,0x0000	), // CYRILLIC CAPITAL LETTER CHE
/*COMPOSE            */	DEADTRANS(	L'5'	,0x0054	,0x01bc	,0x0000	), // LATIN CAPITAL LETTER TONE FIVE
/*COMPOSE            */	DEADTRANS(	L'6'	,0x0054	,0x0184	,0x0000	), // LATIN CAPITAL LETTER TONE SIX
/*COMPOSE            */	DEADTRANS(	0x005c	,0x0054	,0x02d5	,0x0000	), // MODIFIER LETTER DOWN TACK
/*COMPOSE            */	DEADTRANS(	L't'	,0x00a6	,0x0074	,0x0001	), // LATIN SMALL LETTER T
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0074	,0x2649	,0x0000	), // TAURUS
/*COMPOSE            */	DEADTRANS(	L'c'	,0x0074	,0x02a7	,0x0000	), // LATIN SMALL LETTER TESH DIGRAPH
/*COMPOSE            */	DEADTRANS(	L'd'	,0x0074	,0x03b8	,0x0000	), // GREEK SMALL LETTER THETA
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0074	,0x204a	,0x0000	), // TIRONIAN SIGN ET
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0074	,0x00de	,0x0000	), // LATIN CAPITAL LETTER THORN
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0074	,0x00fe	,0x0000	), // LATIN SMALL LETTER THORN
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0074	,0x03f4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0074	,0x03b8	,0x0000	), // GREEK SMALL LETTER THETA
/*COMPOSE            */	DEADTRANS(	L'm'	,0x0074	,0x2122	,0x0000	), // TRADE MARK SIGN
/*COMPOSE            */	DEADTRANS(	L's'	,0x0074	,0x02a6	,0x0000	), // LATIN SMALL LETTER TS DIGRAPH
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0074	,0x03f4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L't'	,0x0074	,0x03b8	,0x0000	), // GREEK SMALL LETTER THETA
/*COMPOSE            */	DEADTRANS(	L'u'	,0x0074	,0xa777	,0x0000	), // LATIN SMALL LETTER TUM
/*COMPOSE            */	DEADTRANS(	L'Z'	,0x0074	,0xa728	,0x0000	), // LATIN CAPITAL LETTER TZ
/*COMPOSE            */	DEADTRANS(	L'z'	,0x0074	,0xa729	,0x0000	), // LATIN SMALL LETTER TZ
/*COMPOSE            */	DEADTRANS(	0x002d	,0x0074	,0x01be	,0x0000	), // LATIN LETTER INVERTED GLOTTAL STOP WITH STROKE
/*COMPOSE            */	DEADTRANS(	0x002f	,0x0074	,0x02d4	,0x0000	), // MODIFIER LETTER UP TACK
/*COMPOSE            */	DEADTRANS(	L'2'	,0x0074	,0x01a8	,0x0000	), // LATIN SMALL LETTER TONE TWO
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0074	,0x0437	,0x0000	), // CYRILLIC SMALL LETTER ZE
/*COMPOSE            */	DEADTRANS(	L'4'	,0x0074	,0x0447	,0x0000	), // CYRILLIC SMALL LETTER CHE
/*COMPOSE            */	DEADTRANS(	L'5'	,0x0074	,0x01bd	,0x0000	), // LATIN SMALL LETTER TONE FIVE
/*COMPOSE            */	DEADTRANS(	L'6'	,0x0074	,0x0185	,0x0000	), // LATIN SMALL LETTER TONE SIX
/*COMPOSE            */	DEADTRANS(	0x005c	,0x0074	,0x02d5	,0x0000	), // MODIFIER LETTER DOWN TACK
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0055	,0x01b1	,0x0000	), // LATIN CAPITAL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0055	,0x01b1	,0x0000	), // LATIN CAPITAL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0055	,0xa79e	,0x0000	), // LATIN CAPITAL LETTER VOLAPUK UE
/*COMPOSE            */	DEADTRANS(	L'u'	,0x00a6	,0x0075	,0x0001	), // LATIN SMALL LETTER U
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0075	,0x1d6b	,0x0000	), // LATIN SMALL LETTER UE
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0075	,0xab50	,0x0000	), // LATIN SMALL LETTER UI
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0075	,0x028a	,0x0000	), // LATIN SMALL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0075	,0x028a	,0x0000	), // LATIN SMALL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'm'	,0x0075	,0xa778	,0x0000	), // LATIN SMALL LETTER UM
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0075	,0xab63	,0x0000	), // LATIN SMALL LETTER UO
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0075	,0xa79f	,0x0000	), // LATIN SMALL LETTER VOLAPUK UE
/*COMPOSE            */	DEADTRANS(	L'V'	,0x00a6	,0x0056	,0x0001	), // LATIN CAPITAL LETTER V
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0056	,0x2652	,0x0000	), // AQUARIUS
/*COMPOSE            */	DEADTRANS(	L'I'	,0x0056	,0x264d	,0x0000	), // VIRGO
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0056	,0xa768	,0x0000	), // LATIN CAPITAL LETTER VEND
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0056	,0xa768	,0x0000	), // LATIN CAPITAL LETTER VEND
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0056	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*COMPOSE            */	DEADTRANS(	L't'	,0x0056	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*COMPOSE            */	DEADTRANS(	L'V'	,0x0056	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0056	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x0056	,0xa760	,0x0000	), // LATIN CAPITAL LETTER VY
/*COMPOSE            */	DEADTRANS(	L'y'	,0x0056	,0xa760	,0x0000	), // LATIN CAPITAL LETTER VY
/*COMPOSE            */	DEADTRANS(	0x002e	,0x0056	,0x02d1	,0x0000	), // MODIFIER LETTER HALF TRIANGULAR COLON
/*COMPOSE            */	DEADTRANS(	0x003a	,0x0056	,0x02d0	,0x0000	), // MODIFIER LETTER TRIANGULAR COLON
/*COMPOSE            */	DEADTRANS(	0x005b	,0x0056	,0xddf9	,0x0000	), // U+1F5F9; input D83D high surrogate first; BALLOT BOX WITH BOLD CHECK
/*COMPOSE            */	DEADTRANS(	0x2610	,0x0056	,0xddf9	,0x0000	), // U+1F5F9; input D83D high surrogate first; BALLOT BOX WITH BOLD CHECK
/*COMPOSE            */	DEADTRANS(	L'v'	,0x00a6	,0x0076	,0x0001	), // LATIN SMALL LETTER V
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0076	,0x2652	,0x0000	), // AQUARIUS
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0076	,0x264d	,0x0000	), // VIRGO
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0076	,0xa768	,0x0000	), // LATIN CAPITAL LETTER VEND
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0076	,0xa769	,0x0000	), // LATIN SMALL LETTER VEND
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0076	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*COMPOSE            */	DEADTRANS(	L't'	,0x0076	,0x028c	,0x0000	), // LATIN SMALL LETTER TURNED V
/*COMPOSE            */	DEADTRANS(	L'V'	,0x0076	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0076	,0x028c	,0x0000	), // LATIN SMALL LETTER TURNED V
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x0076	,0xa760	,0x0000	), // LATIN CAPITAL LETTER VY
/*COMPOSE            */	DEADTRANS(	L'y'	,0x0076	,0xa761	,0x0000	), // LATIN SMALL LETTER VY
/*COMPOSE            */	DEADTRANS(	0x002e	,0x0076	,0x02d1	,0x0000	), // MODIFIER LETTER HALF TRIANGULAR COLON
/*COMPOSE            */	DEADTRANS(	0x003a	,0x0076	,0x02d0	,0x0000	), // MODIFIER LETTER TRIANGULAR COLON
/*COMPOSE            */	DEADTRANS(	0x005b	,0x0076	,0x2611	,0x0000	), // BALLOT BOX WITH CHECK
/*COMPOSE            */	DEADTRANS(	0x2610	,0x0076	,0x2611	,0x0000	), // BALLOT BOX WITH CHECK
/*COMPOSE            */	DEADTRANS(	L'W'	,0x00a6	,0x0057	,0x0001	), // LATIN CAPITAL LETTER W
/*COMPOSE            */	DEADTRANS(	L'W'	,0x0057	,0x02ac	,0x0000	), // LATIN LETTER BILABIAL PERCUSSIVE
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x0057	,0x01f7	,0x0000	), // LATIN CAPITAL LETTER WYNN
/*COMPOSE            */	DEADTRANS(	L'y'	,0x0057	,0x01f7	,0x0000	), // LATIN CAPITAL LETTER WYNN
/*COMPOSE            */	DEADTRANS(	L'w'	,0x00a6	,0x0077	,0x0001	), // LATIN SMALL LETTER W
/*COMPOSE            */	DEADTRANS(	L'w'	,0x0077	,0x02ac	,0x0000	), // LATIN LETTER BILABIAL PERCUSSIVE
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x0077	,0x01f7	,0x0000	), // LATIN CAPITAL LETTER WYNN
/*COMPOSE            */	DEADTRANS(	L'y'	,0x0077	,0x01bf	,0x0000	), // LATIN LETTER WYNN
/*COMPOSE            */	DEADTRANS(	0x007c	,0x0077	,0x2307	,0x0000	), // WAVY LINE
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0058	,0xa7b3	,0x0000	), // LATIN CAPITAL LETTER CHI
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0058	,0xa7b3	,0x0000	), // LATIN CAPITAL LETTER CHI
/*COMPOSE            */	DEADTRANS(	L'X'	,0x0058	,0x00d7	,0x0000	), // MULTIPLICATION SIGN
/*COMPOSE            */	DEADTRANS(	0x003a	,0x0058	,0x203b	,0x0000	), // REFERENCE MARK
/*COMPOSE            */	DEADTRANS(	0x005b	,0x0058	,0xddf7	,0x0000	), // U+1F5F7; input D83D high surrogate first; BALLOT BOX WITH BOLD SCRIPT X
/*COMPOSE            */	DEADTRANS(	0x2610	,0x0058	,0xddf7	,0x0000	), // U+1F5F7; input D83D high surrogate first; BALLOT BOX WITH BOLD SCRIPT X
/*COMPOSE            */	DEADTRANS(	L'x'	,0x00a6	,0x0078	,0x0001	), // LATIN SMALL LETTER X
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0078	,0xab53	,0x0000	), // LATIN SMALL LETTER CHI
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0078	,0xab53	,0x0000	), // LATIN SMALL LETTER CHI
/*COMPOSE            */	DEADTRANS(	L'x'	,0x0078	,0x00d7	,0x0000	), // MULTIPLICATION SIGN
/*COMPOSE            */	DEADTRANS(	0x003a	,0x0078	,0x203b	,0x0000	), // REFERENCE MARK
/*COMPOSE            */	DEADTRANS(	0x005b	,0x0078	,0x2612	,0x0000	), // BALLOT BOX WITH X
/*COMPOSE            */	DEADTRANS(	0x2610	,0x0078	,0x2612	,0x0000	), // BALLOT BOX WITH X
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x00a6	,0x0059	,0x0001	), // LATIN CAPITAL LETTER Y
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0059	,0x02eb	,0x0000	), // MODIFIER LETTER YANG DEPARTING TONE MARK
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0059	,0x02eb	,0x0000	), // MODIFIER LETTER YANG DEPARTING TONE MARK
/*COMPOSE            */	DEADTRANS(	L'I'	,0x0059	,0x02ea	,0x0000	), // MODIFIER LETTER YIN DEPARTING TONE MARK
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0059	,0x01b1	,0x0000	), // LATIN CAPITAL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0059	,0x01b1	,0x0000	), // LATIN CAPITAL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'N'	,0x0059	,0x019d	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0059	,0x021c	,0x0000	), // LATIN CAPITAL LETTER YOGH
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0059	,0x021c	,0x0000	), // LATIN CAPITAL LETTER YOGH
/*COMPOSE            */	DEADTRANS(	L'P'	,0x0059	,0xa700	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN PING
/*COMPOSE            */	DEADTRANS(	L'p'	,0x0059	,0xa700	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN PING
/*COMPOSE            */	DEADTRANS(	L'R'	,0x0059	,0x01a6	,0x0000	), // LATIN LETTER YR
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0059	,0xa702	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN SHANG
/*COMPOSE            */	DEADTRANS(	L's'	,0x0059	,0xa702	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN SHANG
/*COMPOSE            */	DEADTRANS(	L'y'	,0x00a6	,0x0079	,0x0001	), // LATIN SMALL LETTER Y
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0079	,0x02eb	,0x0000	), // MODIFIER LETTER YANG DEPARTING TONE MARK
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0079	,0x02eb	,0x0001	), // MODIFIER LETTER YANG DEPARTING TONE MARK
/*COMPOSE            */	DEADTRANS(	L'n'	,0x02eb	,0x02eb	,0x0000	), // MODIFIER LETTER YANG DEPARTING TONE MARK
/*COMPOSE            */	DEADTRANS(	L't'	,0x02eb	,0xab60	,0x0000	), // LATIN SMALL LETTER SAKHA YAT
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0079	,0x02ea	,0x0000	), // MODIFIER LETTER YIN DEPARTING TONE MARK
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0079	,0x028a	,0x0000	), // LATIN SMALL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0079	,0x028a	,0x0000	), // LATIN SMALL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0079	,0x0272	,0x0000	), // LATIN SMALL LETTER N WITH LEFT HOOK
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0079	,0x021c	,0x0000	), // LATIN CAPITAL LETTER YOGH
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0079	,0x021d	,0x0000	), // LATIN SMALL LETTER YOGH
/*COMPOSE            */	DEADTRANS(	L'P'	,0x0079	,0xa700	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN PING
/*COMPOSE            */	DEADTRANS(	L'p'	,0x0079	,0xa700	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN PING
/*COMPOSE            */	DEADTRANS(	L'r'	,0x0079	,0x01a6	,0x0000	), // LATIN LETTER YR
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0079	,0xa702	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN SHANG
/*COMPOSE            */	DEADTRANS(	L's'	,0x0079	,0xa702	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN SHANG
/*COMPOSE            */	DEADTRANS(	L'Z'	,0x00a6	,0x005a	,0x0001	), // LATIN CAPITAL LETTER Z
/*COMPOSE            */	DEADTRANS(	L'H'	,0x005a	,0x01b7	,0x0000	), // LATIN CAPITAL LETTER EZH
/*COMPOSE            */	DEADTRANS(	L'h'	,0x005a	,0x01b7	,0x0000	), // LATIN CAPITAL LETTER EZH
/*COMPOSE            */	DEADTRANS(	L'S'	,0x005a	,0x1e9e	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	L'Z'	,0x005a	,0x2124	,0x0000	), // DOUBLE-STRUCK CAPITAL Z
/*COMPOSE            */	DEADTRANS(	L'z'	,0x00a6	,0x007a	,0x0001	), // LATIN SMALL LETTER Z
/*COMPOSE            */	DEADTRANS(	L'H'	,0x007a	,0x01b7	,0x0000	), // LATIN CAPITAL LETTER EZH
/*COMPOSE            */	DEADTRANS(	L'h'	,0x007a	,0x0292	,0x0000	), // LATIN SMALL LETTER EZH
/*COMPOSE            */	DEADTRANS(	L's'	,0x007a	,0x00df	,0x0000	), // LATIN SMALL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	0x00e8	,0x020f	,0x1abe	,0x0000	), // COMBINING PARENTHESES OVERLAY
/*COMPOSE            */	DEADTRANS(	0x00e9	,0x020f	,0x1abb	,0x0000	), // COMBINING PARENTHESES ABOVE
/*COMPOSE            */	DEADTRANS(	0x00f9	,0x020f	,0x1abb	,0x0000	), // COMBINING PARENTHESES ABOVE
/*COMPOSE            */	DEADTRANS(	0x0020	,0x00a6	,0x005f	,0x0001	), // LOW LINE
/*COMPOSE            */	DEADTRANS(	0x0021	,0x00a6	,0x1e05	,0x0001	), // LATIN SMALL LETTER B WITH DOT BELOW
/*COMPOSE            */	DEADTRANS(	0x0022	,0x00a6	,0x0151	,0x0001	), // LATIN SMALL LETTER O WITH DOUBLE ACUTE
/*COMPOSE            */	DEADTRANS(	0x0023	,0x00a6	,0x0250	,0x0001	), // LATIN SMALL LETTER TURNED A
/*COMPOSE            */	DEADTRANS(	0x0025	,0x00a6	,0x0281	,0x0001	), // LATIN LETTER SMALL CAPITAL INVERTED R
/*COMPOSE            */	DEADTRANS(	0x0026	,0x00a6	,0x0221	,0x0001	), // LATIN SMALL LETTER D WITH CURL
/*COMPOSE            */	DEADTRANS(	0x0027	,0x00a6	,0x00e1	,0x0001	), // LATIN SMALL LETTER A WITH ACUTE
/*COMPOSE            */	DEADTRANS(	0x0028	,0x00a6	,0x0213	,0x0001	), // LATIN SMALL LETTER R WITH INVERTED BREVE
/*COMPOSE            */	DEADTRANS(	0x0029	,0x00a6	,0x014f	,0x0001	), // LATIN SMALL LETTER O WITH BREVE
/*COMPOSE            */	DEADTRANS(	0x002a	,0x00a6	,0x002a	,0x0001	), // ASTERISK
/*COMPOSE            */	DEADTRANS(	0x002b	,0x00a6	,0x002b	,0x0001	), // PLUS SIGN
/*COMPOSE            */	DEADTRANS(	0x002c	,0x00a6	,0x0229	,0x0001	), // LATIN SMALL LETTER E WITH CEDILLA
/*COMPOSE            */	DEADTRANS(	0x002d	,0x00a6	,0x024d	,0x0001	), // LATIN SMALL LETTER R WITH STROKE
/*COMPOSE            */	DEADTRANS(	0x002e	,0x00a6	,0x1e57	,0x0001	), // LATIN SMALL LETTER P WITH DOT ABOVE
/*COMPOSE            */	DEADTRANS(	0x002f	,0x00a6	,0x00f8	,0x0001	), // LATIN SMALL LETTER O WITH STROKE
/*COMPOSE            */	DEADTRANS(	L'0'	,0x00a6	,0x2189	,0x0000	), // VULGAR FRACTION ZERO THIRDS
/*COMPOSE            */	DEADTRANS(	L'1'	,0x00a6	,0x0031	,0x0001	), // DIGIT ONE
/*COMPOSE            */	DEADTRANS(	0x002f	,0x0031	,0x215f	,0x0000	), // FRACTION NUMERATOR ONE
/*COMPOSE            */	DEADTRANS(	L'1'	,0x0031	,0x2152	,0x0000	), // VULGAR FRACTION ONE TENTH
/*COMPOSE            */	DEADTRANS(	L'2'	,0x0031	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0031	,0x2153	,0x0000	), // VULGAR FRACTION ONE THIRD
/*COMPOSE            */	DEADTRANS(	L'4'	,0x0031	,0x00bc	,0x0000	), // VULGAR FRACTION ONE QUARTER
/*COMPOSE            */	DEADTRANS(	L'5'	,0x0031	,0x2155	,0x0000	), // VULGAR FRACTION ONE FIFTH
/*COMPOSE            */	DEADTRANS(	L'6'	,0x0031	,0x2159	,0x0000	), // VULGAR FRACTION ONE SIXTH
/*COMPOSE            */	DEADTRANS(	L'7'	,0x0031	,0x2150	,0x0000	), // VULGAR FRACTION ONE SEVENTH
/*COMPOSE            */	DEADTRANS(	L'8'	,0x0031	,0x215b	,0x0000	), // VULGAR FRACTION ONE EIGHTH
/*COMPOSE            */	DEADTRANS(	L'9'	,0x0031	,0x2151	,0x0000	), // VULGAR FRACTION ONE NINTH
/*COMPOSE            */	DEADTRANS(	L'2'	,0x00a6	,0x0032	,0x0001	), // DIGIT TWO
/*COMPOSE            */	DEADTRANS(	L'V'	,0x0032	,0x221a	,0x0000	), // SQUARE ROOT
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0032	,0x221a	,0x0000	), // SQUARE ROOT
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0032	,0x2154	,0x0000	), // VULGAR FRACTION TWO THIRDS
/*COMPOSE            */	DEADTRANS(	L'5'	,0x0032	,0x2156	,0x0000	), // VULGAR FRACTION TWO FIFTHS
/*COMPOSE            */	DEADTRANS(	0x003c	,0x0032	,0x226a	,0x0000	), // MUCH LESS-THAN
/*COMPOSE            */	DEADTRANS(	0x003e	,0x0032	,0x226b	,0x0000	), // MUCH GREATER-THAN
/*COMPOSE            */	DEADTRANS(	L'3'	,0x00a6	,0x0033	,0x0001	), // DIGIT THREE
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0033	,0xa722	,0x0000	), // LATIN CAPITAL LETTER EGYPTOLOGICAL ALEF
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0033	,0xa723	,0x0000	), // LATIN SMALL LETTER EGYPTOLOGICAL ALEF
/*COMPOSE            */	DEADTRANS(	L'V'	,0x0033	,0x221b	,0x0000	), // CUBE ROOT
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0033	,0x221b	,0x0000	), // CUBE ROOT
/*COMPOSE            */	DEADTRANS(	L'4'	,0x0033	,0x00be	,0x0000	), // VULGAR FRACTION THREE QUARTERS
/*COMPOSE            */	DEADTRANS(	L'5'	,0x0033	,0x2157	,0x0000	), // VULGAR FRACTION THREE FIFTHS
/*COMPOSE            */	DEADTRANS(	L'8'	,0x0033	,0x215c	,0x0000	), // VULGAR FRACTION THREE EIGHTHS
/*COMPOSE            */	DEADTRANS(	0x003c	,0x0033	,0x22d8	,0x0000	), // VERY MUCH LESS-THAN
/*COMPOSE            */	DEADTRANS(	0x003e	,0x0033	,0x22d9	,0x0000	), // VERY MUCH GREATER-THAN
/*COMPOSE            */	DEADTRANS(	L'4'	,0x00a6	,0x0034	,0x0001	), // DIGIT FOUR
/*COMPOSE            */	DEADTRANS(	L'V'	,0x0034	,0x221c	,0x0000	), // FOURTH ROOT
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0034	,0x221c	,0x0000	), // FOURTH ROOT
/*COMPOSE            */	DEADTRANS(	L'5'	,0x0034	,0x2158	,0x0000	), // VULGAR FRACTION FOUR FIFTHS
/*COMPOSE            */	DEADTRANS(	L'5'	,0x00a6	,0x0035	,0x0001	), // DIGIT FIVE
/*COMPOSE            */	DEADTRANS(	L'6'	,0x0035	,0x215a	,0x0000	), // VULGAR FRACTION FIVE SIXTHS
/*COMPOSE            */	DEADTRANS(	L'8'	,0x0035	,0x215d	,0x0000	), // VULGAR FRACTION FIVE EIGHTHS
/*COMPOSE            */	DEADTRANS(	L'6'	,0x00a6	,0x007c	,0x0001	), // VERTICAL LINE
/*COMPOSE            */	DEADTRANS(	L'7'	,0x00a6	,0x0037	,0x0001	), // DIGIT SEVEN
/*COMPOSE            */	DEADTRANS(	L'I'	,0x0037	,0x0296	,0x0000	), // LATIN LETTER INVERTED GLOTTAL STOP
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0037	,0x0296	,0x0000	), // LATIN LETTER INVERTED GLOTTAL STOP
/*COMPOSE            */	DEADTRANS(	L'M'	,0x0037	,0x0241	,0x0000	), // LATIN CAPITAL LETTER GLOTTAL STOP
/*COMPOSE            */	DEADTRANS(	L'm'	,0x0037	,0x0242	,0x0000	), // LATIN SMALL LETTER GLOTTAL STOP
/*COMPOSE            */	DEADTRANS(	L'R'	,0x0037	,0x0295	,0x0000	), // LATIN LETTER PHARYNGEAL VOICED FRICATIVE
/*COMPOSE            */	DEADTRANS(	L'r'	,0x0037	,0x0295	,0x0000	), // LATIN LETTER PHARYNGEAL VOICED FRICATIVE
/*COMPOSE            */	DEADTRANS(	L'U'	,0x0037	,0x0294	,0x0000	), // LATIN LETTER GLOTTAL STOP
/*COMPOSE            */	DEADTRANS(	L'u'	,0x0037	,0x0294	,0x0000	), // LATIN LETTER GLOTTAL STOP
/*COMPOSE            */	DEADTRANS(	L'8'	,0x0037	,0x215e	,0x0000	), // VULGAR FRACTION SEVEN EIGHTHS
/*COMPOSE            */	DEADTRANS(	L'8'	,0x00a6	,0x0038	,0x0001	), // DIGIT EIGHT
/*COMPOSE            */	DEADTRANS(	0x003c	,0x0038	,0x2702	,0x0001	), // BLACK SCISSORS
/*COMPOSE            */	DEADTRANS(	L'A'	,0x2702	,0x2700	,0x0000	), // BLACK SAFETY SCISSORS
/*COMPOSE            */	DEADTRANS(	L'a'	,0x2702	,0x2700	,0x0000	), // BLACK SAFETY SCISSORS
/*COMPOSE            */	DEADTRANS(	L'B'	,0x2702	,0x2704	,0x0000	), // WHITE SCISSORS
/*COMPOSE            */	DEADTRANS(	L'b'	,0x2702	,0x2704	,0x0000	), // WHITE SCISSORS
/*COMPOSE            */	DEADTRANS(	L'I'	,0x2702	,0x2703	,0x0000	), // LOWER BLADE SCISSORS
/*COMPOSE            */	DEADTRANS(	L'i'	,0x2702	,0x2703	,0x0000	), // LOWER BLADE SCISSORS
/*COMPOSE            */	DEADTRANS(	L'N'	,0x2702	,0x2702	,0x0000	), // BLACK SCISSORS
/*COMPOSE            */	DEADTRANS(	L'n'	,0x2702	,0x2702	,0x0000	), // BLACK SCISSORS
/*COMPOSE            */	DEADTRANS(	L'S'	,0x2702	,0x2701	,0x0000	), // UPPER BLADE SCISSORS
/*COMPOSE            */	DEADTRANS(	L's'	,0x2702	,0x2701	,0x0000	), // UPPER BLADE SCISSORS
/*COMPOSE            */	DEADTRANS(	0x002f	,0x2702	,0x2701	,0x0000	), // UPPER BLADE SCISSORS
/*COMPOSE            */	DEADTRANS(	0x005c	,0x2702	,0x2703	,0x0000	), // LOWER BLADE SCISSORS
/*COMPOSE            */	DEADTRANS(	0x003a	,0x00a6	,0x00eb	,0x0001	), // LATIN SMALL LETTER E WITH DIAERESIS
/*COMPOSE            */	DEADTRANS(	0x003b	,0x00a6	,0x0219	,0x0001	), // LATIN SMALL LETTER S WITH COMMA BELOW
/*COMPOSE            */	DEADTRANS(	0x003c	,0x00a6	,0x00ea	,0x0001	), // LATIN SMALL LETTER E WITH CIRCUMFLEX
/*COMPOSE            */	DEADTRANS(	0x003d	,0x00a6	,0x003d	,0x0001	), // EQUALS SIGN
/*COMPOSE            */	DEADTRANS(	0x003e	,0x00a6	,0x021f	,0x0001	), // LATIN SMALL LETTER H WITH CARON
/*COMPOSE            */	DEADTRANS(	0x003f	,0x00a6	,0x003f	,0x0001	), // QUESTION MARK
/*COMPOSE            */	DEADTRANS(	0x2b06	,0x00a6	,0x005e	,0x0001	), // CIRCUMFLEX ACCENT
/*COMPOSE            */	DEADTRANS(	0x0021	,0x003f	,0x2048	,0x0000	), // QUESTION EXCLAMATION MARK
/*COMPOSE            */	DEADTRANS(	0x0025	,0x003f	,0x1d24	,0x0000	), // LATIN LETTER VOICED LARYNGEAL SPIRANT
/*COMPOSE            */	DEADTRANS(	0x002b	,0x003f	,0x203d	,0x0000	), // INTERROBANG
/*COMPOSE            */	DEADTRANS(	0x002e	,0x003f	,0x203d	,0x0000	), // INTERROBANG
/*COMPOSE            */	DEADTRANS(	0x003f	,0x003f	,0x2047	,0x0000	), // DOUBLE QUESTION MARK
/*COMPOSE            */	DEADTRANS(	0x0040	,0x00a6	,0x25ef	,0x0001	), // LARGE CIRCLE
/*COMPOSE            */	DEADTRANS(	0x005b	,0x00a6	,0x01eb	,0x0001	), // LATIN SMALL LETTER O WITH OGONEK
/*COMPOSE            */	DEADTRANS(	0x005c	,0x00a6	,0x1d19	,0x0001	), // LATIN LETTER SMALL CAPITAL REVERSED R
/*COMPOSE            */	DEADTRANS(	0x005d	,0x00a6	,0x1ebb	,0x0001	), // LATIN SMALL LETTER E WITH HOOK ABOVE
/*COMPOSE            */	DEADTRANS(	0x005e	,0x00a6	,0x005e	,0x0001	), // CIRCUMFLEX ACCENT
/*COMPOSE            */	DEADTRANS(	0x0060	,0x00a6	,0x00f2	,0x0001	), // LATIN SMALL LETTER O WITH GRAVE
/*COMPOSE            */	DEADTRANS(	0x007b	,0x00a6	,0x0273	,0x0001	), // LATIN SMALL LETTER N WITH RETROFLEX HOOK
/*COMPOSE            */	DEADTRANS(	0x007c	,0x00a6	,0x0101	,0x0001	), // LATIN SMALL LETTER A WITH MACRON
/*COMPOSE            */	DEADTRANS(	0x007d	,0x00a6	,0x0192	,0x0001	), // LATIN SMALL LETTER F WITH HOOK
/*COMPOSE            */	DEADTRANS(	0x007e	,0x00a6	,0x00f5	,0x0001	), // LATIN SMALL LETTER O WITH TILDE
/*COMPOSE            */	DEADTRANS(	0x20ac	,0x00a6	,0x00a4	,0x0001	), // CURRENCY SIGN
/*COMPOSE            */	DEADTRANS(	0x00a4	,0x00a6	,0x1d79	,0x0001	), // LATIN SMALL LETTER INSULAR G
/*COMPOSE            */	DEADTRANS(	0x00a9	,0x00a6	,0x00ae	,0x0001	), // REGISTERED SIGN
/*COMPOSE            */	DEADTRANS(	0x00b0	,0x00a6	,0x00e5	,0x0001	), // LATIN SMALL LETTER A WITH RING ABOVE
/*COMPOSE            */	DEADTRANS(	0x00b5	,0x00a6	,0x03a9	,0x0001	), // GREEK CAPITAL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	0x00f9	,0x03b5	,0x0313	,0x0000	), // COMBINING COMMA ABOVE
/*COMPOSE            */	DEADTRANS(	0x0027	,0x03b5	,0x0313	,0x0000	), // COMBINING COMMA ABOVE
/*COMPOSE            */	DEADTRANS(	0x2019	,0x03b5	,0x0313	,0x0000	), // COMBINING COMMA ABOVE
/*COMPOSE            */	DEADTRANS(	0x00ea	,0x00a6	,0x2191	,0x0001	), // UPWARDS ARROW
/*COMPOSE            */	DEADTRANS(	0x00eb	,0x00a6	,0x2193	,0x0001	), // DOWNWARDS ARROW
/*COMPOSE            */	DEADTRANS(	0x002e	,0x2193	,0x1ab4	,0x0000	), // COMBINING TRIPLE DOT
/*COMPOSE            */	DEADTRANS(	0x003a	,0x2193	,0x205a	,0x0000	), // TWO DOT PUNCTUATION
/*COMPOSE            */	DEADTRANS(	0x00eb	,0x2193	,0x205b	,0x0000	), // FOUR DOT MARK
/*COMPOSE            */	DEADTRANS(	0x00f2	,0x00a6	,0x00d2	,0x0001	), // LATIN CAPITAL LETTER O WITH GRAVE
/*COMPOSE            */	DEADTRANS(	0x0027	,0x00d2	,0x0312	,0x0000	), // COMBINING TURNED COMMA ABOVE
/*COMPOSE            */	DEADTRANS(	0x2019	,0x00d2	,0x0312	,0x0000	), // COMBINING TURNED COMMA ABOVE
/*COMPOSE            */	DEADTRANS(	0x00f5	,0x00a6	,0x00d5	,0x0001	), // LATIN CAPITAL LETTER O WITH TILDE
/*COMPOSE            */	DEADTRANS(	0x00f9	,0x00d5	,0x0314	,0x0000	), // COMBINING REVERSED COMMA ABOVE
/*COMPOSE            */	DEADTRANS(	0x0027	,0x00d5	,0x0314	,0x0000	), // COMBINING REVERSED COMMA ABOVE
/*COMPOSE            */	DEADTRANS(	0x00a3	,0x00d5	,0x1e1b	,0x0001	), // LATIN SMALL LETTER E WITH TILDE BELOW
/*COMPOSE            */	DEADTRANS(	0x2019	,0x00d5	,0x0314	,0x0000	), // COMBINING REVERSED COMMA ABOVE
/*COMPOSE            */	DEADTRANS(	0x02bc	,0x00a6	,0x0149	,0x0000	), // LATIN SMALL LETTER N PRECEDED BY APOSTROPHE
/*COMPOSE            */	DEADTRANS(	0x2019	,0x00a6	,0x0149	,0x0001	), // LATIN SMALL LETTER N PRECEDED BY APOSTROPHE
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0149	,0x0149	,0x0000	), // LATIN SMALL LETTER N PRECEDED BY APOSTROPHE
/*COMPOSE            */	DEADTRANS(	0x2610	,0x00a6	,0x2610	,0x0001	), // BALLOT BOX
/*COMPOSE            */	DEADTRANS(	L'O'	,0x2610	,0x2384	,0x0000	), // COMPOSITION SYMBOL
/*COMPOSE            */	DEADTRANS(	L'o'	,0x2610	,0x2384	,0x0000	), // COMPOSITION SYMBOL
/*COMPOSE            */	DEADTRANS(	0x0040	,0x2610	,0x2384	,0x0000	), // COMPOSITION SYMBOL
/*CROSSED_TAIL       */	DEADTRANS(	L'g'	,0xab3a	,0xab36	,0x0000	), // LATIN SMALL LETTER SCRIPT G WITH CROSSED-TAIL
/*CROSSED_TAIL       */	DEADTRANS(	L'J'	,0xab3a	,0xa7b2	,0x0000	), // LATIN CAPITAL LETTER J WITH CROSSED-TAIL
/*CROSSED_TAIL       */	DEADTRANS(	L'j'	,0xab3a	,0x029d	,0x0000	), // LATIN SMALL LETTER J WITH CROSSED-TAIL
/*CROSSED_TAIL       */	DEADTRANS(	L'm'	,0xab3a	,0xab3a	,0x0000	), // LATIN SMALL LETTER M WITH CROSSED-TAIL
/*CROSSED_TAIL       */	DEADTRANS(	L'n'	,0xab3a	,0xab3b	,0x0000	), // LATIN SMALL LETTER N WITH CROSSED-TAIL
/*CROSSED_TAIL       */	DEADTRANS(	L'r'	,0xab3a	,0xab49	,0x0000	), // LATIN SMALL LETTER R WITH CROSSED-TAIL
/*CROSSED_TAIL       */	DEADTRANS(	0x003d	,0xab3a	,0xab4a	,0x0000	), // LATIN SMALL LETTER DOUBLE R WITH CROSSED-TAIL
/*CROSSED_TAIL       */	DEADTRANS(	0x00a9	,0xab3a	,0xab3c	,0x0000	), // LATIN SMALL LETTER ENG WITH CROSSED-TAIL
/*CURL               */	DEADTRANS(	L'a'	,0x0221	,0x1d25	,0x0000	), // LATIN LETTER AIN
/*CURL               */	DEADTRANS(	L'c'	,0x0221	,0x0255	,0x0000	), // LATIN SMALL LETTER C WITH CURL
/*CURL               */	DEADTRANS(	L'd'	,0x0221	,0x0221	,0x0000	), // LATIN SMALL LETTER D WITH CURL
/*CURL               */	DEADTRANS(	L'g'	,0x0221	,0xab36	,0x0000	), // LATIN SMALL LETTER SCRIPT G WITH CROSSED-TAIL
/*CURL               */	DEADTRANS(	L'J'	,0x0221	,0xa7b2	,0x0000	), // LATIN CAPITAL LETTER J WITH CROSSED-TAIL
/*CURL               */	DEADTRANS(	L'j'	,0x0221	,0x029d	,0x0000	), // LATIN SMALL LETTER J WITH CROSSED-TAIL
/*CURL               */	DEADTRANS(	L'l'	,0x0221	,0x0234	,0x0000	), // LATIN SMALL LETTER L WITH CURL
/*CURL               */	DEADTRANS(	L'n'	,0x0221	,0x0235	,0x0000	), // LATIN SMALL LETTER N WITH CURL
/*CURL               */	DEADTRANS(	L'O'	,0x0221	,0xa74c	,0x0000	), // LATIN CAPITAL LETTER O WITH LOOP
/*CURL               */	DEADTRANS(	L'o'	,0x0221	,0xa74d	,0x0000	), // LATIN SMALL LETTER O WITH LOOP
/*CURL               */	DEADTRANS(	L's'	,0x0221	,0x0286	,0x0000	), // LATIN SMALL LETTER ESH WITH CURL
/*CURL               */	DEADTRANS(	L't'	,0x0221	,0x0236	,0x0000	), // LATIN SMALL LETTER T WITH CURL
/*CURL               */	DEADTRANS(	L'v'	,0x0221	,0x2c74	,0x0000	), // LATIN SMALL LETTER V WITH CURL
/*CURL               */	DEADTRANS(	L'X'	,0x0221	,0xab3a	,0x0001	), // LATIN SMALL LETTER M WITH CROSSED-TAIL
/*CURL               */	DEADTRANS(	L'x'	,0x0221	,0xab3a	,0x0001	), // LATIN SMALL LETTER M WITH CROSSED-TAIL
/*CURL               */	DEADTRANS(	L'Y'	,0x0221	,0x1efe	,0x0000	), // LATIN CAPITAL LETTER Y WITH LOOP
/*CURL               */	DEADTRANS(	L'y'	,0x0221	,0x1eff	,0x0000	), // LATIN SMALL LETTER Y WITH LOOP
/*CURL               */	DEADTRANS(	L'z'	,0x0221	,0x0291	,0x0000	), // LATIN SMALL LETTER Z WITH CURL
/*CURL               */	DEADTRANS(	0x0026	,0x0221	,0x2113	,0x0001	), // SCRIPT SMALL L
/*CURL               */	DEADTRANS(	0x002e	,0x0221	,0x2055	,0x0000	), // FLOWER PUNCTUATION MARK
/*CURL               */	DEADTRANS(	0x007c	,0x0221	,0x2055	,0x0001	), // FLOWER PUNCTUATION MARK
/*CURL               */	DEADTRANS(	L'A'	,0x2055	,0xa724	,0x0000	), // LATIN CAPITAL LETTER EGYPTOLOGICAL AIN
/*CURL               */	DEADTRANS(	L'a'	,0x2055	,0xa725	,0x0000	), // LATIN SMALL LETTER EGYPTOLOGICAL AIN
/*CURL               */	DEADTRANS(	0x00a9	,0x0221	,0x0255	,0x0001	), // LATIN SMALL LETTER C WITH CURL
/*CURL               */	DEADTRANS(	L'd'	,0x0255	,0x02a5	,0x0000	), // LATIN SMALL LETTER DZ DIGRAPH WITH CURL
/*CURL               */	DEADTRANS(	L's'	,0x0255	,0x0286	,0x0000	), // LATIN SMALL LETTER ESH WITH CURL
/*CURL               */	DEADTRANS(	L't'	,0x0255	,0x02a8	,0x0000	), // LATIN SMALL LETTER TC DIGRAPH WITH CURL
/*CURL               */	DEADTRANS(	L'z'	,0x0255	,0x0293	,0x0000	), // LATIN SMALL LETTER EZH WITH CURL
/*CURRENCY           */	DEADTRANS(	0x0020	,0x00a4	,0x00a4	,0x0000	), // CURRENCY SIGN
/*CURRENCY           */	DEADTRANS(	0x202f	,0x00a4	,0x00a4	,0x0000	), // CURRENCY SIGN
/*CURRENCY           */	DEADTRANS(	L'A'	,0x00a4	,0x20b3	,0x0000	), // AUSTRAL SIGN
/*CURRENCY           */	DEADTRANS(	L'a'	,0x00a4	,0x060b	,0x0000	), // AFGHANI SIGN
/*CURRENCY           */	DEADTRANS(	L'B'	,0x00a4	,0x0e3f	,0x0000	), // THAI CURRENCY SYMBOL BAHT
/*CURRENCY           */	DEADTRANS(	L'b'	,0x00a4	,0x20bf	,0x0000	), // BITCOIN SIGN
/*CURRENCY           */	DEADTRANS(	L'C'	,0x00a4	,0x20b5	,0x0000	), // CEDI SIGN
/*CURRENCY           */	DEADTRANS(	L'c'	,0x00a4	,0x00a2	,0x0001	), // CENT SIGN
/*CURRENCY           */	DEADTRANS(	L'e'	,0x00a2	,0x20b5	,0x0000	), // CEDI SIGN
/*CURRENCY           */	DEADTRANS(	L'o'	,0x00a2	,0x20a1	,0x0000	), // COLON SIGN
/*CURRENCY           */	DEADTRANS(	L'r'	,0x00a2	,0x20a2	,0x0000	), // CRUZEIRO SIGN
/*CURRENCY           */	DEADTRANS(	0x002f	,0x00a2	,0x00a2	,0x0000	), // CENT SIGN
/*CURRENCY           */	DEADTRANS(	L'D'	,0x00a4	,0x20af	,0x0000	), // DRACHMA SIGN
/*CURRENCY           */	DEADTRANS(	L'd'	,0x00a4	,0x20ab	,0x0000	), // DONG SIGN
/*CURRENCY           */	DEADTRANS(	L'E'	,0x00a4	,0x20ac	,0x0000	), // EURO SIGN
/*CURRENCY           */	DEADTRANS(	L'e'	,0x00a4	,0x20ac	,0x0000	), // EURO SIGN
/*CURRENCY           */	DEADTRANS(	L'F'	,0x00a4	,0x20a3	,0x0000	), // FRENCH FRANC SIGN
/*CURRENCY           */	DEADTRANS(	L'f'	,0x00a4	,0x0192	,0x0000	), // LATIN SMALL LETTER F WITH HOOK
/*CURRENCY           */	DEADTRANS(	L'G'	,0x00a4	,0x20b2	,0x0000	), // GUARANI SIGN
/*CURRENCY           */	DEADTRANS(	L'H'	,0x00a4	,0x20bd	,0x0000	), // RUBLE SIGN
/*CURRENCY           */	DEADTRANS(	L'h'	,0x00a4	,0x20b4	,0x0000	), // HRYVNIA SIGN
/*CURRENCY           */	DEADTRANS(	L'I'	,0x00a4	,0x20a4	,0x0000	), // LIRA SIGN
/*CURRENCY           */	DEADTRANS(	L'K'	,0x00a4	,0x20ad	,0x0000	), // KIP SIGN
/*CURRENCY           */	DEADTRANS(	L'k'	,0x00a4	,0x17db	,0x0000	), // KHMER CURRENCY SYMBOL RIEL
/*CURRENCY           */	DEADTRANS(	L'L'	,0x00a4	,0x20be	,0x0000	), // LARI SIGN
/*CURRENCY           */	DEADTRANS(	L'l'	,0x00a4	,0x20ba	,0x0000	), // TURKISH LIRA SIGN
/*CURRENCY           */	DEADTRANS(	L'M'	,0x00a4	,0x20bc	,0x0000	), // MANAT SIGN
/*CURRENCY           */	DEADTRANS(	L'm'	,0x00a4	,0x20a5	,0x0000	), // MILL SIGN
/*CURRENCY           */	DEADTRANS(	L'N'	,0x00a4	,0x20a6	,0x0000	), // NAIRA SIGN
/*CURRENCY           */	DEADTRANS(	L'n'	,0x00a4	,0x20aa	,0x0000	), // NEW SHEQEL SIGN
/*CURRENCY           */	DEADTRANS(	L'O'	,0x00a4	,0x20a1	,0x0000	), // COLON SIGN
/*CURRENCY           */	DEADTRANS(	L'o'	,0x00a4	,0x20a1	,0x0000	), // COLON SIGN
/*CURRENCY           */	DEADTRANS(	L'P'	,0x00a4	,0x20b1	,0x0000	), // PESO SIGN
/*CURRENCY           */	DEADTRANS(	L'p'	,0x00a4	,0x20a7	,0x0001	), // PESETA SIGN
/*CURRENCY           */	DEADTRANS(	L'f'	,0x20a7	,0x20b0	,0x0000	), // GERMAN PENNY SIGN
/*CURRENCY           */	DEADTRANS(	L't'	,0x20a7	,0x20a7	,0x0000	), // PESETA SIGN
/*CURRENCY           */	DEADTRANS(	L'Q'	,0x00a4	,0x00a4	,0x0000	), // CURRENCY SIGN
/*CURRENCY           */	DEADTRANS(	L'q'	,0x00a4	,0x00a4	,0x0000	), // CURRENCY SIGN
/*CURRENCY           */	DEADTRANS(	L'R'	,0x00a4	,0x20b9	,0x0001	), // INDIAN RUPEE SIGN
/*CURRENCY           */	DEADTRANS(	L'b'	,0x20b9	,0x09f2	,0x0000	), // BENGALI RUPEE MARK
/*CURRENCY           */	DEADTRANS(	L'g'	,0x20b9	,0x0af1	,0x0000	), // GUJARATI RUPEE SIGN
/*CURRENCY           */	DEADTRANS(	L'r'	,0x20b9	,0x20b9	,0x0000	), // INDIAN RUPEE SIGN
/*CURRENCY           */	DEADTRANS(	L's'	,0x20b9	,0x20a8	,0x0000	), // RUPEE SIGN
/*CURRENCY           */	DEADTRANS(	L't'	,0x20b9	,0x0bf9	,0x0000	), // TAMIL RUPEE SIGN
/*CURRENCY           */	DEADTRANS(	L'r'	,0x00a4	,0xfdfc	,0x0000	), // RIAL SIGN
/*CURRENCY           */	DEADTRANS(	L'S'	,0x00a4	,0x20b7	,0x0000	), // SPESMILO SIGN
/*CURRENCY           */	DEADTRANS(	0x007c	,0x00a4	,0x0024	,0x0000	), // DOLLAR SIGN
/*CURRENCY           */	DEADTRANS(	L'T'	,0x00a4	,0x20b8	,0x0000	), // TENGE SIGN
/*CURRENCY           */	DEADTRANS(	L't'	,0x00a4	,0x20ae	,0x0000	), // TUGRIK SIGN
/*CURRENCY           */	DEADTRANS(	L'W'	,0x00a4	,0x20a9	,0x0000	), // WON SIGN
/*CURRENCY           */	DEADTRANS(	L'w'	,0x00a4	,0x20a9	,0x0000	), // WON SIGN
/*CURRENCY           */	DEADTRANS(	L'X'	,0x00a4	,0x2133	,0x0000	), // SCRIPT CAPITAL M
/*CURRENCY           */	DEADTRANS(	L'Y'	,0x00a4	,0x00a5	,0x0000	), // YEN SIGN
/*CURRENCY           */	DEADTRANS(	L'y'	,0x00a4	,0x00a5	,0x0000	), // YEN SIGN
/*CURRENCY           */	DEADTRANS(	L'Z'	,0x00a4	,0x20a2	,0x0000	), // CRUZEIRO SIGN
/*CURRENCY           */	DEADTRANS(	L'z'	,0x00a4	,0x20a2	,0x0000	), // CRUZEIRO SIGN
/*CURRENCY           */	DEADTRANS(	0x20ac	,0x00a4	,0x20a0	,0x0000	), // EURO-CURRENCY SIGN
/*CURRENCY           */	DEADTRANS(	0x00a3	,0x00a4	,0x00a3	,0x0000	), // POUND SIGN
/*CURRENCY           */	DEADTRANS(	0x00b5	,0x00a4	,0x20bb	,0x0000	), // NORDIC MARK SIGN
/*CURRENCY           */	DEADTRANS(	0x2610	,0x00a4	,0x20b6	,0x0000	), // LIVRE TOURNOIS SIGN
/*CYRILLIC           */	DEADTRANS(	L'A'	,0x0436	,0x0410	,0x0000	), // CYRILLIC CAPITAL LETTER A
/*CYRILLIC           */	DEADTRANS(	L'a'	,0x0436	,0x0430	,0x0000	), // CYRILLIC SMALL LETTER A
/*CYRILLIC           */	DEADTRANS(	L'B'	,0x0436	,0x0411	,0x0000	), // CYRILLIC CAPITAL LETTER BE
/*CYRILLIC           */	DEADTRANS(	L'b'	,0x0436	,0x0431	,0x0000	), // CYRILLIC SMALL LETTER BE
/*CYRILLIC           */	DEADTRANS(	L'C'	,0x0436	,0x0426	,0x0000	), // CYRILLIC CAPITAL LETTER TSE
/*CYRILLIC           */	DEADTRANS(	L'c'	,0x0436	,0x0446	,0x0000	), // CYRILLIC SMALL LETTER TSE
/*CYRILLIC           */	DEADTRANS(	L'D'	,0x0436	,0x0414	,0x0000	), // CYRILLIC CAPITAL LETTER DE
/*CYRILLIC           */	DEADTRANS(	L'd'	,0x0436	,0x0434	,0x0000	), // CYRILLIC SMALL LETTER DE
/*CYRILLIC           */	DEADTRANS(	L'E'	,0x0436	,0x0415	,0x0000	), // CYRILLIC CAPITAL LETTER IE
/*CYRILLIC           */	DEADTRANS(	L'e'	,0x0436	,0x0435	,0x0000	), // CYRILLIC SMALL LETTER IE
/*CYRILLIC           */	DEADTRANS(	L'F'	,0x0436	,0x0424	,0x0000	), // CYRILLIC CAPITAL LETTER EF
/*CYRILLIC           */	DEADTRANS(	L'f'	,0x0436	,0x0444	,0x0000	), // CYRILLIC SMALL LETTER EF
/*CYRILLIC           */	DEADTRANS(	L'G'	,0x0436	,0x0413	,0x0000	), // CYRILLIC CAPITAL LETTER GHE
/*CYRILLIC           */	DEADTRANS(	L'g'	,0x0436	,0x0433	,0x0000	), // CYRILLIC SMALL LETTER GHE
/*CYRILLIC           */	DEADTRANS(	L'H'	,0x0436	,0x0425	,0x0000	), // CYRILLIC CAPITAL LETTER HA
/*CYRILLIC           */	DEADTRANS(	L'h'	,0x0436	,0x0445	,0x0000	), // CYRILLIC SMALL LETTER HA
/*CYRILLIC           */	DEADTRANS(	L'I'	,0x0436	,0x0418	,0x0000	), // CYRILLIC CAPITAL LETTER I
/*CYRILLIC           */	DEADTRANS(	L'i'	,0x0436	,0x0438	,0x0000	), // CYRILLIC SMALL LETTER I
/*CYRILLIC           */	DEADTRANS(	L'J'	,0x0436	,0x0419	,0x0000	), // CYRILLIC CAPITAL LETTER SHORT I
/*CYRILLIC           */	DEADTRANS(	L'j'	,0x0436	,0x0439	,0x0000	), // CYRILLIC SMALL LETTER SHORT I
/*CYRILLIC           */	DEADTRANS(	L'K'	,0x0436	,0x041a	,0x0000	), // CYRILLIC CAPITAL LETTER KA
/*CYRILLIC           */	DEADTRANS(	L'k'	,0x0436	,0x043a	,0x0000	), // CYRILLIC SMALL LETTER KA
/*CYRILLIC           */	DEADTRANS(	L'L'	,0x0436	,0x041b	,0x0000	), // CYRILLIC CAPITAL LETTER EL
/*CYRILLIC           */	DEADTRANS(	L'l'	,0x0436	,0x043b	,0x0000	), // CYRILLIC SMALL LETTER EL
/*CYRILLIC           */	DEADTRANS(	L'M'	,0x0436	,0x041c	,0x0000	), // CYRILLIC CAPITAL LETTER EM
/*CYRILLIC           */	DEADTRANS(	L'm'	,0x0436	,0x043c	,0x0000	), // CYRILLIC SMALL LETTER EM
/*CYRILLIC           */	DEADTRANS(	L'N'	,0x0436	,0x041d	,0x0000	), // CYRILLIC CAPITAL LETTER EN
/*CYRILLIC           */	DEADTRANS(	L'n'	,0x0436	,0x043d	,0x0000	), // CYRILLIC SMALL LETTER EN
/*CYRILLIC           */	DEADTRANS(	L'O'	,0x0436	,0x041e	,0x0000	), // CYRILLIC CAPITAL LETTER O
/*CYRILLIC           */	DEADTRANS(	L'o'	,0x0436	,0x043e	,0x0000	), // CYRILLIC SMALL LETTER O
/*CYRILLIC           */	DEADTRANS(	L'P'	,0x0436	,0x041f	,0x0000	), // CYRILLIC CAPITAL LETTER PE
/*CYRILLIC           */	DEADTRANS(	L'p'	,0x0436	,0x043f	,0x0000	), // CYRILLIC SMALL LETTER PE
/*CYRILLIC           */	DEADTRANS(	L'Q'	,0x0436	,0x0427	,0x0000	), // CYRILLIC CAPITAL LETTER CHE
/*CYRILLIC           */	DEADTRANS(	L'q'	,0x0436	,0x0447	,0x0000	), // CYRILLIC SMALL LETTER CHE
/*CYRILLIC           */	DEADTRANS(	L'R'	,0x0436	,0x0420	,0x0000	), // CYRILLIC CAPITAL LETTER ER
/*CYRILLIC           */	DEADTRANS(	L'r'	,0x0436	,0x0440	,0x0000	), // CYRILLIC SMALL LETTER ER
/*CYRILLIC           */	DEADTRANS(	L'S'	,0x0436	,0x0421	,0x0000	), // CYRILLIC CAPITAL LETTER ES
/*CYRILLIC           */	DEADTRANS(	L's'	,0x0436	,0x0441	,0x0000	), // CYRILLIC SMALL LETTER ES
/*CYRILLIC           */	DEADTRANS(	L'T'	,0x0436	,0x0422	,0x0000	), // CYRILLIC CAPITAL LETTER TE
/*CYRILLIC           */	DEADTRANS(	L't'	,0x0436	,0x0442	,0x0000	), // CYRILLIC SMALL LETTER TE
/*CYRILLIC           */	DEADTRANS(	L'U'	,0x0436	,0x0423	,0x0000	), // CYRILLIC CAPITAL LETTER U
/*CYRILLIC           */	DEADTRANS(	L'u'	,0x0436	,0x0443	,0x0000	), // CYRILLIC SMALL LETTER U
/*CYRILLIC           */	DEADTRANS(	L'V'	,0x0436	,0x0412	,0x0000	), // CYRILLIC CAPITAL LETTER VE
/*CYRILLIC           */	DEADTRANS(	L'v'	,0x0436	,0x0432	,0x0000	), // CYRILLIC SMALL LETTER VE
/*CYRILLIC           */	DEADTRANS(	L'W'	,0x0436	,0x0428	,0x0000	), // CYRILLIC CAPITAL LETTER SHA
/*CYRILLIC           */	DEADTRANS(	L'w'	,0x0436	,0x0448	,0x0000	), // CYRILLIC SMALL LETTER SHA
/*CYRILLIC           */	DEADTRANS(	L'X'	,0x0436	,0x0416	,0x0000	), // CYRILLIC CAPITAL LETTER ZHE
/*CYRILLIC           */	DEADTRANS(	L'x'	,0x0436	,0x0436	,0x0000	), // CYRILLIC SMALL LETTER ZHE
/*CYRILLIC           */	DEADTRANS(	L'Y'	,0x0436	,0x042a	,0x0000	), // CYRILLIC CAPITAL LETTER HARD SIGN
/*CYRILLIC           */	DEADTRANS(	L'y'	,0x0436	,0x044a	,0x0000	), // CYRILLIC SMALL LETTER HARD SIGN
/*CYRILLIC           */	DEADTRANS(	L'Z'	,0x0436	,0x0417	,0x0000	), // CYRILLIC CAPITAL LETTER ZE
/*CYRILLIC           */	DEADTRANS(	L'z'	,0x0436	,0x0437	,0x0000	), // CYRILLIC SMALL LETTER ZE
/*CYRILLIC           */	DEADTRANS(	0x002a	,0x0436	,0x0482	,0x0000	), // CYRILLIC THOUSANDS SIGN
/*CYRILLIC           */	DEADTRANS(	0x0436	,0x0436	,0x0416	,0x0001	), // CYRILLIC CAPITAL LETTER ZHE
/*CYRILLIC           */	DEADTRANS(	0x1f12	,0x0436	,0x0482	,0x0000	), // CYRILLIC THOUSANDS SIGN
/*CYRILLIC           */	DEADTRANS(	0x00e1	,0x0436	,0x0449	,0x0000	), // CYRILLIC SMALL LETTER SHCHA
/*CYRILLIC           */	DEADTRANS(	0x1f7d	,0x0436	,0x0449	,0x0000	), // CYRILLIC SMALL LETTER SHCHA
/*CYRILLIC           */	DEADTRANS(	0x00ea	,0x0436	,0x044f	,0x0000	), // CYRILLIC SMALL LETTER YA
/*CYRILLIC           */	DEADTRANS(	0x1fc6	,0x0436	,0x044f	,0x0000	), // CYRILLIC SMALL LETTER YA
/*CYRILLIC           */	DEADTRANS(	0x00eb	,0x0436	,0x042f	,0x0000	), // CYRILLIC CAPITAL LETTER YA
/*CYRILLIC           */	DEADTRANS(	0x03ca	,0x0436	,0x042f	,0x0000	), // CYRILLIC CAPITAL LETTER YA
/*CYRILLIC           */	DEADTRANS(	0x00f2	,0x0436	,0x044c	,0x0000	), // CYRILLIC SMALL LETTER SOFT SIGN
/*CYRILLIC           */	DEADTRANS(	0x1f70	,0x0436	,0x044c	,0x0000	), // CYRILLIC SMALL LETTER SOFT SIGN
/*CYRILLIC           */	DEADTRANS(	0x00f5	,0x0436	,0x0429	,0x0000	), // CYRILLIC CAPITAL LETTER SHCHA
/*CYRILLIC           */	DEADTRANS(	0x1f14	,0x0436	,0x0429	,0x0000	), // CYRILLIC CAPITAL LETTER SHCHA
/*CYRILLIC           */	DEADTRANS(	0x03cc	,0x0436	,0x045d	,0x0000	), // CYRILLIC SMALL LETTER I WITH GRAVE
/*CYRILLIC           */	DEADTRANS(	0x2019	,0x0436	,0x045d	,0x0000	), // CYRILLIC SMALL LETTER I WITH GRAVE
/*CYRILLIC           */	DEADTRANS(	0x02bc	,0x0436	,0x040d	,0x0000	), // CYRILLIC CAPITAL LETTER I WITH GRAVE
/*CYRILLIC           */	DEADTRANS(	0x0390	,0x0436	,0x040d	,0x0000	), // CYRILLIC CAPITAL LETTER I WITH GRAVE
/*CYRILLIC           */	DEADTRANS(	0x0391	,0x0436	,0x0410	,0x0000	), // CYRILLIC CAPITAL LETTER A
/*CYRILLIC           */	DEADTRANS(	0x03b1	,0x0436	,0x0430	,0x0000	), // CYRILLIC SMALL LETTER A
/*CYRILLIC           */	DEADTRANS(	0x0392	,0x0436	,0x0411	,0x0000	), // CYRILLIC CAPITAL LETTER BE
/*CYRILLIC           */	DEADTRANS(	0x03b2	,0x0436	,0x0431	,0x0000	), // CYRILLIC SMALL LETTER BE
/*CYRILLIC           */	DEADTRANS(	0x0393	,0x0436	,0x0413	,0x0000	), // CYRILLIC CAPITAL LETTER GHE
/*CYRILLIC           */	DEADTRANS(	0x03b3	,0x0436	,0x0433	,0x0000	), // CYRILLIC SMALL LETTER GHE
/*CYRILLIC           */	DEADTRANS(	0x0394	,0x0436	,0x0414	,0x0000	), // CYRILLIC CAPITAL LETTER DE
/*CYRILLIC           */	DEADTRANS(	0x03b4	,0x0436	,0x0434	,0x0000	), // CYRILLIC SMALL LETTER DE
/*CYRILLIC           */	DEADTRANS(	0x0395	,0x0436	,0x0415	,0x0000	), // CYRILLIC CAPITAL LETTER IE
/*CYRILLIC           */	DEADTRANS(	0x03b5	,0x0436	,0x0435	,0x0000	), // CYRILLIC SMALL LETTER IE
/*CYRILLIC           */	DEADTRANS(	0x0396	,0x0436	,0x0417	,0x0000	), // CYRILLIC CAPITAL LETTER ZE
/*CYRILLIC           */	DEADTRANS(	0x03b6	,0x0436	,0x0437	,0x0000	), // CYRILLIC SMALL LETTER ZE
/*CYRILLIC           */	DEADTRANS(	0x0397	,0x0436	,0x0425	,0x0000	), // CYRILLIC CAPITAL LETTER HA
/*CYRILLIC           */	DEADTRANS(	0x03b7	,0x0436	,0x0445	,0x0000	), // CYRILLIC SMALL LETTER HA
/*CYRILLIC           */	DEADTRANS(	0x0398	,0x0436	,0x0423	,0x0000	), // CYRILLIC CAPITAL LETTER U
/*CYRILLIC           */	DEADTRANS(	0x03b8	,0x0436	,0x0443	,0x0000	), // CYRILLIC SMALL LETTER U
/*CYRILLIC           */	DEADTRANS(	0x0399	,0x0436	,0x0418	,0x0000	), // CYRILLIC CAPITAL LETTER I
/*CYRILLIC           */	DEADTRANS(	0x03b9	,0x0436	,0x0438	,0x0000	), // CYRILLIC SMALL LETTER I
/*CYRILLIC           */	DEADTRANS(	0x039a	,0x0436	,0x041a	,0x0000	), // CYRILLIC CAPITAL LETTER KA
/*CYRILLIC           */	DEADTRANS(	0x03ba	,0x0436	,0x043a	,0x0000	), // CYRILLIC SMALL LETTER KA
/*CYRILLIC           */	DEADTRANS(	0x039b	,0x0436	,0x041b	,0x0000	), // CYRILLIC CAPITAL LETTER EL
/*CYRILLIC           */	DEADTRANS(	0x03bb	,0x0436	,0x043b	,0x0000	), // CYRILLIC SMALL LETTER EL
/*CYRILLIC           */	DEADTRANS(	0x039c	,0x0436	,0x041c	,0x0000	), // CYRILLIC CAPITAL LETTER EM
/*CYRILLIC           */	DEADTRANS(	0x03bc	,0x0436	,0x043c	,0x0000	), // CYRILLIC SMALL LETTER EM
/*CYRILLIC           */	DEADTRANS(	0x039d	,0x0436	,0x041d	,0x0000	), // CYRILLIC CAPITAL LETTER EN
/*CYRILLIC           */	DEADTRANS(	0x03bd	,0x0436	,0x043d	,0x0000	), // CYRILLIC SMALL LETTER EN
/*CYRILLIC           */	DEADTRANS(	0x039e	,0x0436	,0x0419	,0x0000	), // CYRILLIC CAPITAL LETTER SHORT I
/*CYRILLIC           */	DEADTRANS(	0x03be	,0x0436	,0x0439	,0x0000	), // CYRILLIC SMALL LETTER SHORT I
/*CYRILLIC           */	DEADTRANS(	0x039f	,0x0436	,0x041e	,0x0000	), // CYRILLIC CAPITAL LETTER O
/*CYRILLIC           */	DEADTRANS(	0x03bf	,0x0436	,0x043e	,0x0000	), // CYRILLIC SMALL LETTER O
/*CYRILLIC           */	DEADTRANS(	0x03a0	,0x0436	,0x041f	,0x0000	), // CYRILLIC CAPITAL LETTER PE
/*CYRILLIC           */	DEADTRANS(	0x03c0	,0x0436	,0x043f	,0x0000	), // CYRILLIC SMALL LETTER PE
/*CYRILLIC           */	DEADTRANS(	0x03a1	,0x0436	,0x0420	,0x0000	), // CYRILLIC CAPITAL LETTER ER
/*CYRILLIC           */	DEADTRANS(	0x03c1	,0x0436	,0x0440	,0x0000	), // CYRILLIC SMALL LETTER ER
/*CYRILLIC           */	DEADTRANS(	0x03a3	,0x0436	,0x0421	,0x0000	), // CYRILLIC CAPITAL LETTER ES
/*CYRILLIC           */	DEADTRANS(	0x03c2	,0x0436	,0x0447	,0x0000	), // CYRILLIC SMALL LETTER CHE
/*CYRILLIC           */	DEADTRANS(	0x03c3	,0x0436	,0x0441	,0x0000	), // CYRILLIC SMALL LETTER ES
/*CYRILLIC           */	DEADTRANS(	0x03a4	,0x0436	,0x0422	,0x0000	), // CYRILLIC CAPITAL LETTER TE
/*CYRILLIC           */	DEADTRANS(	0x03c4	,0x0436	,0x0442	,0x0000	), // CYRILLIC SMALL LETTER TE
/*CYRILLIC           */	DEADTRANS(	0x03a5	,0x0436	,0x042a	,0x0000	), // CYRILLIC CAPITAL LETTER HARD SIGN
/*CYRILLIC           */	DEADTRANS(	0x03c5	,0x0436	,0x044a	,0x0000	), // CYRILLIC SMALL LETTER HARD SIGN
/*CYRILLIC           */	DEADTRANS(	0x03a6	,0x0436	,0x0424	,0x0000	), // CYRILLIC CAPITAL LETTER EF
/*CYRILLIC           */	DEADTRANS(	0x03c6	,0x0436	,0x0444	,0x0000	), // CYRILLIC SMALL LETTER EF
/*CYRILLIC           */	DEADTRANS(	0x03a7	,0x0436	,0x0416	,0x0000	), // CYRILLIC CAPITAL LETTER ZHE
/*CYRILLIC           */	DEADTRANS(	0x03c7	,0x0436	,0x0436	,0x0000	), // CYRILLIC SMALL LETTER ZHE
/*CYRILLIC           */	DEADTRANS(	0x03a8	,0x0436	,0x0426	,0x0000	), // CYRILLIC CAPITAL LETTER TSE
/*CYRILLIC           */	DEADTRANS(	0x03c8	,0x0436	,0x0446	,0x0000	), // CYRILLIC SMALL LETTER TSE
/*CYRILLIC           */	DEADTRANS(	0x03a9	,0x0436	,0x0412	,0x0000	), // CYRILLIC CAPITAL LETTER VE
/*CYRILLIC           */	DEADTRANS(	0x03c9	,0x0436	,0x0432	,0x0000	), // CYRILLIC SMALL LETTER VE
/*CYRILLIC           */	DEADTRANS(	0x03da	,0x0436	,0x0428	,0x0000	), // CYRILLIC CAPITAL LETTER SHA
/*CYRILLIC           */	DEADTRANS(	0x0448	,0x0436	,0x0448	,0x0000	), // CYRILLIC SMALL LETTER SHA
/*CYRILLIC           */	DEADTRANS(	0x2211	,0x0436	,0x0427	,0x0000	), // CYRILLIC CAPITAL LETTER CHE
/*DESCENDER          */	DEADTRANS(	L'e'	,0x2c6a	,0x2c78	,0x0000	), // LATIN SMALL LETTER E WITH NOTCH
/*DESCENDER          */	DEADTRANS(	L'H'	,0x2c6a	,0x2c67	,0x0000	), // LATIN CAPITAL LETTER H WITH DESCENDER
/*DESCENDER          */	DEADTRANS(	L'h'	,0x2c6a	,0x2c68	,0x0000	), // LATIN SMALL LETTER H WITH DESCENDER
/*DESCENDER          */	DEADTRANS(	L'K'	,0x2c6a	,0x2c69	,0x0000	), // LATIN CAPITAL LETTER K WITH DESCENDER
/*DESCENDER          */	DEADTRANS(	L'k'	,0x2c6a	,0x2c6a	,0x0000	), // LATIN SMALL LETTER K WITH DESCENDER
/*DESCENDER          */	DEADTRANS(	L'N'	,0x2c6a	,0xa790	,0x0000	), // LATIN CAPITAL LETTER N WITH DESCENDER
/*DESCENDER          */	DEADTRANS(	L'n'	,0x2c6a	,0xa791	,0x0000	), // LATIN SMALL LETTER N WITH DESCENDER
/*DESCENDER          */	DEADTRANS(	L'Z'	,0x2c6a	,0x2c6b	,0x0000	), // LATIN CAPITAL LETTER Z WITH DESCENDER
/*DESCENDER          */	DEADTRANS(	L'z'	,0x2c6a	,0x2c6c	,0x0000	), // LATIN SMALL LETTER Z WITH DESCENDER
/*DIAERESIS          */	DEADTRANS(	0x0020	,0x00eb	,0x0308	,0x0000	), // COMBINING DIAERESIS
/*DIAERESIS          */	DEADTRANS(	0x00b0	,0x00eb	,0x1ab1	,0x0000	), // COMBINING DIAERESIS-RING
/*DIAERESIS          */	DEADTRANS(	0x00a0	,0x00eb	,0x00a8	,0x0000	), // DIAERESIS
/*DIAERESIS          */	DEADTRANS(	0x202f	,0x00eb	,0x00a8	,0x0000	), // DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'A'	,0x00eb	,0x00c4	,0x0000	), // LATIN CAPITAL LETTER A WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'a'	,0x00eb	,0x00e4	,0x0000	), // LATIN SMALL LETTER A WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'B'	,0x00eb	,0x014a	,0x0000	), // LATIN CAPITAL LETTER ENG
/*DIAERESIS          */	DEADTRANS(	L'b'	,0x00eb	,0x014b	,0x0000	), // LATIN SMALL LETTER ENG
/*DIAERESIS          */	DEADTRANS(	L'C'	,0x00eb	,0x00b0	,0x0000	), // DEGREE SIGN
/*DIAERESIS          */	DEADTRANS(	L'c'	,0x00eb	,0x00b0	,0x0000	), // DEGREE SIGN
/*DIAERESIS          */	DEADTRANS(	L'D'	,0x00eb	,0x00d0	,0x0000	), // LATIN CAPITAL LETTER ETH
/*DIAERESIS          */	DEADTRANS(	L'd'	,0x00eb	,0x00f0	,0x0000	), // LATIN SMALL LETTER ETH
/*DIAERESIS          */	DEADTRANS(	L'E'	,0x00eb	,0x00cb	,0x0000	), // LATIN CAPITAL LETTER E WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'e'	,0x00eb	,0x00eb	,0x0000	), // LATIN SMALL LETTER E WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'F'	,0x00eb	,0x00a6	,0x0000	), // BROKEN BAR
/*DIAERESIS          */	DEADTRANS(	L'f'	,0x00eb	,0x00a6	,0x0000	), // BROKEN BAR
/*DIAERESIS          */	DEADTRANS(	L'G'	,0x00eb	,0x0194	,0x0000	), // LATIN CAPITAL LETTER GAMMA
/*DIAERESIS          */	DEADTRANS(	L'g'	,0x00eb	,0x0263	,0x0000	), // LATIN SMALL LETTER GAMMA
/*DIAERESIS          */	DEADTRANS(	L'H'	,0x00eb	,0x1e26	,0x0000	), // LATIN CAPITAL LETTER H WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'h'	,0x00eb	,0x1e27	,0x0000	), // LATIN SMALL LETTER H WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'I'	,0x00eb	,0x00cf	,0x0000	), // LATIN CAPITAL LETTER I WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'i'	,0x00eb	,0x00ef	,0x0000	), // LATIN SMALL LETTER I WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'J'	,0x00eb	,0x0196	,0x0000	), // LATIN CAPITAL LETTER IOTA
/*DIAERESIS          */	DEADTRANS(	L'j'	,0x00eb	,0x0269	,0x0000	), // LATIN SMALL LETTER IOTA
/*DIAERESIS          */	DEADTRANS(	L'l'	,0x00eb	,0x019b	,0x0000	), // LATIN SMALL LETTER LAMBDA WITH STROKE
/*DIAERESIS          */	DEADTRANS(	L'O'	,0x00eb	,0x00d6	,0x0000	), // LATIN CAPITAL LETTER O WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'o'	,0x00eb	,0x00f6	,0x0000	), // LATIN SMALL LETTER O WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'Q'	,0x00eb	,0x2c6d	,0x0000	), // LATIN CAPITAL LETTER ALPHA
/*DIAERESIS          */	DEADTRANS(	L'q'	,0x00eb	,0x0251	,0x0000	), // LATIN SMALL LETTER ALPHA
/*DIAERESIS          */	DEADTRANS(	L'r'	,0x00eb	,0x027e	,0x0000	), // LATIN SMALL LETTER R WITH FISHHOOK
/*DIAERESIS          */	DEADTRANS(	L'S'	,0x00eb	,0x1e9e	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*DIAERESIS          */	DEADTRANS(	L's'	,0x00eb	,0x00df	,0x0000	), // LATIN SMALL LETTER SHARP S
/*DIAERESIS          */	DEADTRANS(	L'T'	,0x00eb	,0x2021	,0x0000	), // DOUBLE DAGGER
/*DIAERESIS          */	DEADTRANS(	0x2011	,0x00eb	,0x2010	,0x0000	), // HYPHEN
/*DIAERESIS          */	DEADTRANS(	L't'	,0x00eb	,0x1e97	,0x0000	), // LATIN SMALL LETTER T WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'U'	,0x00eb	,0x00dc	,0x0000	), // LATIN CAPITAL LETTER U WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'u'	,0x00eb	,0x00fc	,0x0000	), // LATIN SMALL LETTER U WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'W'	,0x00eb	,0x1e84	,0x0000	), // LATIN CAPITAL LETTER W WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'w'	,0x00eb	,0x1e85	,0x0000	), // LATIN SMALL LETTER W WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'X'	,0x00eb	,0x1e8c	,0x0000	), // LATIN CAPITAL LETTER X WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'x'	,0x00eb	,0x1e8d	,0x0000	), // LATIN SMALL LETTER X WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'Y'	,0x00eb	,0x0178	,0x0000	), // LATIN CAPITAL LETTER Y WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'y'	,0x00eb	,0x00ff	,0x0000	), // LATIN SMALL LETTER Y WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'Z'	,0x00eb	,0x2260	,0x0000	), // NOT EQUAL TO
/*DIAERESIS          */	DEADTRANS(	L'z'	,0x00eb	,0x2260	,0x0000	), // NOT EQUAL TO
/*DIAERESIS          */	DEADTRANS(	0x00c9	,0x00c0	,0x00c5	,0x0000	), // LATIN CAPITAL LETTER A WITH RING ABOVE
/*DIAERESIS          */	DEADTRANS(	0x00e9	,0x00e0	,0x00e5	,0x0000	), // LATIN SMALL LETTER A WITH RING ABOVE
/*DIAERESIS          */	DEADTRANS(	0x00c9	,0x00eb	,0x00c5	,0x0000	), // LATIN CAPITAL LETTER A WITH RING ABOVE
/*DIAERESIS          */	DEADTRANS(	0x00e9	,0x00eb	,0x00e5	,0x0000	), // LATIN SMALL LETTER A WITH RING ABOVE
/*DIAERESIS          */	DEADTRANS(	0x0152	,0x00eb	,0x00d8	,0x0000	), // LATIN CAPITAL LETTER O WITH STROKE
/*DIAERESIS          */	DEADTRANS(	0x0153	,0x00eb	,0x00f8	,0x0000	), // LATIN SMALL LETTER O WITH STROKE
/*DIAERESIS          */	DEADTRANS(	0x0021	,0x00eb	,0x00a1	,0x0000	), // INVERTED EXCLAMATION MARK
/*DIAERESIS          */	DEADTRANS(	0x0022	,0x00eb	,0x201e	,0x0000	), // DOUBLE LOW-9 QUOTATION MARK
/*DIAERESIS          */	DEADTRANS(	0x0023	,0x00eb	,0x201e	,0x0000	), // DOUBLE LOW-9 QUOTATION MARK
/*DIAERESIS          */	DEADTRANS(	0x0027	,0x00eb	,0x201a	,0x0000	), // SINGLE LOW-9 QUOTATION MARK
/*DIAERESIS          */	DEADTRANS(	0x0028	,0x00eb	,0x208d	,0x0000	), // SUBSCRIPT LEFT PARENTHESIS
/*DIAERESIS          */	DEADTRANS(	0x0029	,0x00eb	,0x208e	,0x0000	), // SUBSCRIPT RIGHT PARENTHESIS
/*DIAERESIS          */	DEADTRANS(	0x002a	,0x00eb	,0x2051	,0x0000	), // TWO ASTERISKS ALIGNED VERTICALLY
/*DIAERESIS          */	DEADTRANS(	0x002b	,0x00eb	,0x208a	,0x0000	), // SUBSCRIPT PLUS SIGN
/*DIAERESIS          */	DEADTRANS(	0x002d	,0x00eb	,0x2e3a	,0x0000	), // TWO-EM DASH
/*DIAERESIS          */	DEADTRANS(	0x002e	,0x00eb	,0x2026	,0x0000	), // HORIZONTAL ELLIPSIS
/*DIAERESIS          */	DEADTRANS(	0x002f	,0x00eb	,0x2052	,0x0000	), // COMMERCIAL MINUS SIGN
/*DIAERESIS          */	DEADTRANS(	L'0'	,0x00eb	,0x2080	,0x0000	), // SUBSCRIPT ZERO
/*DIAERESIS          */	DEADTRANS(	L'1'	,0x00eb	,0x2081	,0x0000	), // SUBSCRIPT ONE
/*DIAERESIS          */	DEADTRANS(	L'2'	,0x00eb	,0x2082	,0x0000	), // SUBSCRIPT TWO
/*DIAERESIS          */	DEADTRANS(	L'3'	,0x00eb	,0x2083	,0x0000	), // SUBSCRIPT THREE
/*DIAERESIS          */	DEADTRANS(	L'4'	,0x00eb	,0x2084	,0x0000	), // SUBSCRIPT FOUR
/*DIAERESIS          */	DEADTRANS(	L'5'	,0x00eb	,0x2085	,0x0000	), // SUBSCRIPT FIVE
/*DIAERESIS          */	DEADTRANS(	L'6'	,0x00eb	,0x2086	,0x0000	), // SUBSCRIPT SIX
/*DIAERESIS          */	DEADTRANS(	L'7'	,0x00eb	,0x2087	,0x0000	), // SUBSCRIPT SEVEN
/*DIAERESIS          */	DEADTRANS(	L'8'	,0x00eb	,0x2088	,0x0000	), // SUBSCRIPT EIGHT
/*DIAERESIS          */	DEADTRANS(	L'9'	,0x00eb	,0x2089	,0x0000	), // SUBSCRIPT NINE
/*DIAERESIS          */	DEADTRANS(	0x003a	,0x00eb	,0x2026	,0x0000	), // HORIZONTAL ELLIPSIS
/*DIAERESIS          */	DEADTRANS(	0x003e	,0x00eb	,0x01da	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND CARON
/*DIAERESIS          */	DEADTRANS(	0x003d	,0x00eb	,0x208c	,0x0000	), // SUBSCRIPT EQUALS SIGN
/*DIAERESIS          */	DEADTRANS(	0x003f	,0x00eb	,0x00bf	,0x0000	), // INVERTED QUESTION MARK
/*DIAERESIS          */	DEADTRANS(	0x0060	,0x00eb	,0x01dc	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND GRAVE
/*DIAERESIS          */	DEADTRANS(	0x005f	,0x00eb	,0x022b	,0x0001	), // LATIN SMALL LETTER O WITH DIAERESIS AND MACRON
/*DIAERESIS          */	DEADTRANS(	0x007c	,0x00eb	,0x00a6	,0x0000	), // BROKEN BAR
/*DIAERESIS          */	DEADTRANS(	0x007e	,0x00eb	,0x1e4f	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND DIAERESIS
/*DIAERESIS          */	DEADTRANS(	0x00a9	,0x00eb	,0x00f6	,0x0001	), // LATIN SMALL LETTER O WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	0x0027	,0x00f6	,0x01d8	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND ACUTE
/*DIAERESIS          */	DEADTRANS(	0x00a7	,0x00eb	,0x204b	,0x0000	), // REVERSED PILCROW SIGN
/*DIAERESIS          */	DEADTRANS(	0x00ab	,0x00eb	,0x2039	,0x0000	), // SINGLE LEFT-POINTING ANGLE QUOTATION MARK
/*DIAERESIS          */	DEADTRANS(	0x00b5	,0x00eb	,0x2282	,0x0000	), // SUBSET OF
/*DIAERESIS          */	DEADTRANS(	0x00bb	,0x00eb	,0x203a	,0x0000	), // SINGLE RIGHT-POINTING ANGLE QUOTATION MARK
/*DIAERESIS          */	DEADTRANS(	0x00e1	,0x00eb	,0x01d8	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND ACUTE
/*DIAERESIS          */	DEADTRANS(	0x00ea	,0x00eb	,0x1ecd	,0x0001	), // LATIN SMALL LETTER O WITH DOT BELOW
/*DIAERESIS          */	DEADTRANS(	0x00eb	,0x00eb	,0x1e73	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS BELOW
/*DIAERESIS          */	DEADTRANS(	0x00f2	,0x00eb	,0x01dc	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND GRAVE
/*DIAERESIS          */	DEADTRANS(	0x00f5	,0x00eb	,0x1e4f	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND DIAERESIS
/*DIAERESIS          */	DEADTRANS(	0x02bc	,0x00eb	,0x02bb	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*DIAERESIS          */	DEADTRANS(	0x2019	,0x00eb	,0x201a	,0x0000	), // SINGLE LOW-9 QUOTATION MARK
/*DIAERESIS          */	DEADTRANS(	0x2212	,0x00eb	,0x208b	,0x0000	), // SUBSCRIPT MINUS
/*DIAERESIS          */	DEADTRANS(	0x2610	,0x00eb	,0x2611	,0x0000	), // BALLOT BOX WITH CHECK
/*DIAERESIS          */	DEADTRANS(	0x021f	,0x00eb	,0x01da	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND CARON
/*DIAERESIS          */	DEADTRANS(	0x014d	,0x00eb	,0x022b	,0x0001	), // LATIN SMALL LETTER O WITH DIAERESIS AND MACRON
/*DIAERESIS          */	DEADTRANS(	0x03c0	,0x00eb	,0x2283	,0x0000	), // SUPERSET OF
/*DIAERESIS&ACUTE    */	DEADTRANS(	L'I'	,0x01d8	,0x1e2e	,0x0000	), // LATIN CAPITAL LETTER I WITH DIAERESIS AND ACUTE
/*DIAERESIS&ACUTE    */	DEADTRANS(	L'i'	,0x01d8	,0x1e2f	,0x0000	), // LATIN SMALL LETTER I WITH DIAERESIS AND ACUTE
/*DIAERESIS&ACUTE    */	DEADTRANS(	L'U'	,0x01d8	,0x01d7	,0x0000	), // LATIN CAPITAL LETTER U WITH DIAERESIS AND ACUTE
/*DIAERESIS&ACUTE    */	DEADTRANS(	L'u'	,0x01d8	,0x01d8	,0x0000	), // LATIN SMALL LETTER U WITH DIAERESIS AND ACUTE
/*DIAERESIS&GRAVE    */	DEADTRANS(	L'U'	,0x01dc	,0x01db	,0x0000	), // LATIN CAPITAL LETTER U WITH DIAERESIS AND GRAVE
/*DIAERESIS&GRAVE    */	DEADTRANS(	L'u'	,0x01dc	,0x01dc	,0x0000	), // LATIN SMALL LETTER U WITH DIAERESIS AND GRAVE
/*DIAERESIS&HACEK    */	DEADTRANS(	L'U'	,0x01da	,0x01d9	,0x0000	), // LATIN CAPITAL LETTER U WITH DIAERESIS AND CARON
/*DIAERESIS&HACEK    */	DEADTRANS(	L'u'	,0x01da	,0x01da	,0x0000	), // LATIN SMALL LETTER U WITH DIAERESIS AND CARON
/*DIAERESIS&MACRON   */	DEADTRANS(	L'A'	,0x022b	,0x01de	,0x0000	), // LATIN CAPITAL LETTER A WITH DIAERESIS AND MACRON
/*DIAERESIS&MACRON   */	DEADTRANS(	L'a'	,0x022b	,0x01df	,0x0000	), // LATIN SMALL LETTER A WITH DIAERESIS AND MACRON
/*DIAERESIS&MACRON   */	DEADTRANS(	L'O'	,0x022b	,0x022a	,0x0000	), // LATIN CAPITAL LETTER O WITH DIAERESIS AND MACRON
/*DIAERESIS&MACRON   */	DEADTRANS(	L'o'	,0x022b	,0x022b	,0x0000	), // LATIN SMALL LETTER O WITH DIAERESIS AND MACRON
/*DIAERESIS&MACRON   */	DEADTRANS(	L'U'	,0x022b	,0x01d5	,0x0000	), // LATIN CAPITAL LETTER U WITH DIAERESIS AND MACRON
/*DIAERESIS&MACRON   */	DEADTRANS(	L'u'	,0x022b	,0x01d6	,0x0000	), // LATIN SMALL LETTER U WITH DIAERESIS AND MACRON
/*DIAERESIS_BELOW    */	DEADTRANS(	0x0020	,0x1e73	,0x0324	,0x0000	), // COMBINING DIAERESIS BELOW
/*DIAERESIS_BELOW    */	DEADTRANS(	L'U'	,0x1e73	,0x1e72	,0x0000	), // LATIN CAPITAL LETTER U WITH DIAERESIS BELOW
/*DIAERESIS_BELOW    */	DEADTRANS(	L'u'	,0x1e73	,0x1e73	,0x0000	), // LATIN SMALL LETTER U WITH DIAERESIS BELOW
/*DOT_ABOVE          */	DEADTRANS(	0x0020	,0x1e57	,0x0307	,0x0000	), // COMBINING DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x0028	,0x1e57	,0x0352	,0x0000	), // COMBINING FERMATA
/*DOT_ABOVE          */	DEADTRANS(	0x0029	,0x1e57	,0x0310	,0x0000	), // COMBINING CANDRABINDU
/*DOT_ABOVE          */	DEADTRANS(	0x00eb	,0x1e57	,0x1ab4	,0x0000	), // COMBINING TRIPLE DOT
/*DOT_ABOVE          */	DEADTRANS(	0x00a0	,0x1e57	,0x02d9	,0x0000	), // DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x202f	,0x1e57	,0x02d9	,0x0000	), // DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'A'	,0x1e57	,0x0226	,0x0000	), // LATIN CAPITAL LETTER A WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'a'	,0x1e57	,0x0227	,0x0000	), // LATIN SMALL LETTER A WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'B'	,0x1e57	,0x1e02	,0x0000	), // LATIN CAPITAL LETTER B WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'b'	,0x1e57	,0x1e03	,0x0000	), // LATIN SMALL LETTER B WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'C'	,0x1e57	,0x010a	,0x0000	), // LATIN CAPITAL LETTER C WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'c'	,0x1e57	,0x010b	,0x0000	), // LATIN SMALL LETTER C WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'D'	,0x1e57	,0x1e0a	,0x0000	), // LATIN CAPITAL LETTER D WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'd'	,0x1e57	,0x1e0b	,0x0000	), // LATIN SMALL LETTER D WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'E'	,0x1e57	,0x0116	,0x0000	), // LATIN CAPITAL LETTER E WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'e'	,0x1e57	,0x0117	,0x0000	), // LATIN SMALL LETTER E WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'F'	,0x1e57	,0x1e1e	,0x0000	), // LATIN CAPITAL LETTER F WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'f'	,0x1e57	,0x1e1f	,0x0000	), // LATIN SMALL LETTER F WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'G'	,0x1e57	,0x0120	,0x0000	), // LATIN CAPITAL LETTER G WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'g'	,0x1e57	,0x0121	,0x0000	), // LATIN SMALL LETTER G WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'H'	,0x1e57	,0x1e22	,0x0000	), // LATIN CAPITAL LETTER H WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'h'	,0x1e57	,0x1e23	,0x0000	), // LATIN SMALL LETTER H WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'I'	,0x1e57	,0x0130	,0x0000	), // LATIN CAPITAL LETTER I WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'i'	,0x1e57	,0x0131	,0x0000	), // LATIN SMALL LETTER DOTLESS I
/*DOT_ABOVE          */	DEADTRANS(	L'j'	,0x1e57	,0x0237	,0x0000	), // LATIN SMALL LETTER DOTLESS J
/*DOT_ABOVE          */	DEADTRANS(	L'L'	,0x1e57	,0x013f	,0x0000	), // LATIN CAPITAL LETTER L WITH MIDDLE DOT
/*DOT_ABOVE          */	DEADTRANS(	L'l'	,0x1e57	,0x0140	,0x0000	), // LATIN SMALL LETTER L WITH MIDDLE DOT
/*DOT_ABOVE          */	DEADTRANS(	L'M'	,0x1e57	,0x1e40	,0x0000	), // LATIN CAPITAL LETTER M WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'm'	,0x1e57	,0x1e41	,0x0000	), // LATIN SMALL LETTER M WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'N'	,0x1e57	,0x1e44	,0x0000	), // LATIN CAPITAL LETTER N WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'n'	,0x1e57	,0x1e45	,0x0000	), // LATIN SMALL LETTER N WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'O'	,0x1e57	,0x022e	,0x0000	), // LATIN CAPITAL LETTER O WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'o'	,0x1e57	,0x022f	,0x0000	), // LATIN SMALL LETTER O WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'P'	,0x1e57	,0x1e56	,0x0000	), // LATIN CAPITAL LETTER P WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'p'	,0x1e57	,0x1e57	,0x0000	), // LATIN SMALL LETTER P WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'R'	,0x1e57	,0x1e58	,0x0000	), // LATIN CAPITAL LETTER R WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'r'	,0x1e57	,0x1e59	,0x0000	), // LATIN SMALL LETTER R WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'S'	,0x1e57	,0x1e60	,0x0000	), // LATIN CAPITAL LETTER S WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L's'	,0x1e57	,0x1e61	,0x0000	), // LATIN SMALL LETTER S WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'T'	,0x1e57	,0x1e6a	,0x0000	), // LATIN CAPITAL LETTER T WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L't'	,0x1e57	,0x1e6b	,0x0000	), // LATIN SMALL LETTER T WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'W'	,0x1e57	,0x1e86	,0x0000	), // LATIN CAPITAL LETTER W WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'w'	,0x1e57	,0x1e87	,0x0000	), // LATIN SMALL LETTER W WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'X'	,0x1e57	,0x1e8a	,0x0000	), // LATIN CAPITAL LETTER X WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'x'	,0x1e57	,0x1e8b	,0x0000	), // LATIN SMALL LETTER X WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'Y'	,0x1e57	,0x1e8e	,0x0000	), // LATIN CAPITAL LETTER Y WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'y'	,0x1e57	,0x1e8f	,0x0000	), // LATIN SMALL LETTER Y WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'Z'	,0x1e57	,0x017b	,0x0000	), // LATIN CAPITAL LETTER Z WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'z'	,0x1e57	,0x017c	,0x0000	), // LATIN SMALL LETTER Z WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x0021	,0x1e57	,0x1e69	,0x0001	), // LATIN SMALL LETTER S WITH DOT BELOW AND DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x0025	,0x1e57	,0x2052	,0x0000	), // COMMERCIAL MINUS SIGN
/*DOT_ABOVE          */	DEADTRANS(	0x0027	,0x1e57	,0x1e65	,0x0001	), // LATIN SMALL LETTER S WITH ACUTE AND DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x002e	,0x1e57	,0x2026	,0x0000	), // HORIZONTAL ELLIPSIS
/*DOT_ABOVE          */	DEADTRANS(	0x002f	,0x1e57	,0x2052	,0x0000	), // COMMERCIAL MINUS SIGN
/*DOT_ABOVE          */	DEADTRANS(	L'1'	,0x1e57	,0x2024	,0x0000	), // ONE DOT LEADER
/*DOT_ABOVE          */	DEADTRANS(	L'2'	,0x1e57	,0x2025	,0x0000	), // TWO DOT LEADER
/*DOT_ABOVE          */	DEADTRANS(	L'3'	,0x1e57	,0x2026	,0x0000	), // HORIZONTAL ELLIPSIS
/*DOT_ABOVE          */	DEADTRANS(	0x003a	,0x1e57	,0x2056	,0x0000	), // THREE DOT PUNCTUATION
/*DOT_ABOVE          */	DEADTRANS(	0x003e	,0x1e57	,0x1e67	,0x0001	), // LATIN SMALL LETTER S WITH CARON AND DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x005f	,0x1e57	,0x0231	,0x0001	), // LATIN SMALL LETTER O WITH DOT ABOVE AND MACRON
/*DOT_ABOVE          */	DEADTRANS(	L'0'	,0x1e9b	,0xa70c	,0x0000	), // MODIFIER LETTER EXTRA-LOW DOTTED TONE BAR
/*DOT_ABOVE          */	DEADTRANS(	L'1'	,0x1e9b	,0xa70b	,0x0000	), // MODIFIER LETTER LOW DOTTED TONE BAR
/*DOT_ABOVE          */	DEADTRANS(	L'2'	,0x1e9b	,0xa70a	,0x0000	), // MODIFIER LETTER MID DOTTED TONE BAR
/*DOT_ABOVE          */	DEADTRANS(	L'3'	,0x1e9b	,0xa709	,0x0000	), // MODIFIER LETTER HIGH DOTTED TONE BAR
/*DOT_ABOVE          */	DEADTRANS(	L'4'	,0x1e9b	,0xa708	,0x0000	), // MODIFIER LETTER EXTRA-HIGH DOTTED TONE BAR
/*DOT_ABOVE          */	DEADTRANS(	0x00e1	,0x1e57	,0x1e65	,0x0001	), // LATIN SMALL LETTER S WITH ACUTE AND DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x021f	,0x1e57	,0x1e67	,0x0001	), // LATIN SMALL LETTER S WITH CARON AND DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x014d	,0x1e57	,0x0231	,0x0001	), // LATIN SMALL LETTER O WITH DOT ABOVE AND MACRON
/*DOT_ABOVE          */	DEADTRANS(	0x1ee5	,0x1e57	,0x1e69	,0x0001	), // LATIN SMALL LETTER S WITH DOT BELOW AND DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x017f	,0x1e57	,0x1e9b	,0x0001	), // LATIN SMALL LETTER LONG S WITH DOT ABOVE
/*DOT_ABOVE&DOT_BELOW*/	DEADTRANS(	L'S'	,0x1e69	,0x1e68	,0x0000	), // LATIN CAPITAL LETTER S WITH DOT BELOW AND DOT ABOVE
/*DOT_ABOVE&DOT_BELOW*/	DEADTRANS(	L's'	,0x1e69	,0x1e69	,0x0000	), // LATIN SMALL LETTER S WITH DOT BELOW AND DOT ABOVE
/*DOT_ABOVE&MACRON   */	DEADTRANS(	L'A'	,0x0231	,0x01e0	,0x0000	), // LATIN CAPITAL LETTER A WITH DOT ABOVE AND MACRON
/*DOT_ABOVE&MACRON   */	DEADTRANS(	L'a'	,0x0231	,0x01e1	,0x0000	), // LATIN SMALL LETTER A WITH DOT ABOVE AND MACRON
/*DOT_ABOVE&MACRON   */	DEADTRANS(	L'O'	,0x0231	,0x0230	,0x0000	), // LATIN CAPITAL LETTER O WITH DOT ABOVE AND MACRON
/*DOT_ABOVE&MACRON   */	DEADTRANS(	L'o'	,0x0231	,0x0231	,0x0000	), // LATIN SMALL LETTER O WITH DOT ABOVE AND MACRON
/*DOT_BELOW          */	DEADTRANS(	0x0020	,0x1e05	,0x0323	,0x0000	), // COMBINING DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'A'	,0x1e05	,0x1ea0	,0x0000	), // LATIN CAPITAL LETTER A WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'a'	,0x1e05	,0x1ea1	,0x0000	), // LATIN SMALL LETTER A WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'B'	,0x1e05	,0x1e04	,0x0000	), // LATIN CAPITAL LETTER B WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'b'	,0x1e05	,0x1e05	,0x0000	), // LATIN SMALL LETTER B WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'D'	,0x1e05	,0x1e0c	,0x0000	), // LATIN CAPITAL LETTER D WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'd'	,0x1e05	,0x1e0d	,0x0000	), // LATIN SMALL LETTER D WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'E'	,0x1e05	,0x1eb8	,0x0000	), // LATIN CAPITAL LETTER E WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'e'	,0x1e05	,0x1eb9	,0x0000	), // LATIN SMALL LETTER E WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'H'	,0x1e05	,0x1e24	,0x0000	), // LATIN CAPITAL LETTER H WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'h'	,0x1e05	,0x1e25	,0x0000	), // LATIN SMALL LETTER H WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'I'	,0x1e05	,0x1eca	,0x0000	), // LATIN CAPITAL LETTER I WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'i'	,0x1e05	,0x1ecb	,0x0000	), // LATIN SMALL LETTER I WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'K'	,0x1e05	,0x1e32	,0x0000	), // LATIN CAPITAL LETTER K WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'k'	,0x1e05	,0x1e33	,0x0000	), // LATIN SMALL LETTER K WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'L'	,0x1e05	,0x1e36	,0x0000	), // LATIN CAPITAL LETTER L WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'l'	,0x1e05	,0x1e37	,0x0000	), // LATIN SMALL LETTER L WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'M'	,0x1e05	,0x1e42	,0x0000	), // LATIN CAPITAL LETTER M WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'm'	,0x1e05	,0x1e43	,0x0000	), // LATIN SMALL LETTER M WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'N'	,0x1e05	,0x1e46	,0x0000	), // LATIN CAPITAL LETTER N WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'n'	,0x1e05	,0x1e47	,0x0000	), // LATIN SMALL LETTER N WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'O'	,0x1e05	,0x1ecc	,0x0000	), // LATIN CAPITAL LETTER O WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'o'	,0x1e05	,0x1ecd	,0x0000	), // LATIN SMALL LETTER O WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'R'	,0x1e05	,0x1e5a	,0x0000	), // LATIN CAPITAL LETTER R WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'r'	,0x1e05	,0x1e5b	,0x0000	), // LATIN SMALL LETTER R WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'S'	,0x1e05	,0x1e62	,0x0000	), // LATIN CAPITAL LETTER S WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L's'	,0x1e05	,0x1e63	,0x0000	), // LATIN SMALL LETTER S WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'T'	,0x1e05	,0x1e6c	,0x0000	), // LATIN CAPITAL LETTER T WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L't'	,0x1e05	,0x1e6d	,0x0000	), // LATIN SMALL LETTER T WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'U'	,0x1e05	,0x1ee4	,0x0000	), // LATIN CAPITAL LETTER U WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'u'	,0x1e05	,0x1ee5	,0x0000	), // LATIN SMALL LETTER U WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'V'	,0x1e05	,0x1e7e	,0x0000	), // LATIN CAPITAL LETTER V WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'v'	,0x1e05	,0x1e7f	,0x0000	), // LATIN SMALL LETTER V WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'W'	,0x1e05	,0x1e88	,0x0000	), // LATIN CAPITAL LETTER W WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'w'	,0x1e05	,0x1e89	,0x0000	), // LATIN SMALL LETTER W WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'Y'	,0x1e05	,0x1ef4	,0x0000	), // LATIN CAPITAL LETTER Y WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'y'	,0x1e05	,0x1ef5	,0x0000	), // LATIN SMALL LETTER Y WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'Z'	,0x1e05	,0x1e92	,0x0000	), // LATIN CAPITAL LETTER Z WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'z'	,0x1e05	,0x1e93	,0x0000	), // LATIN SMALL LETTER Z WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	0x0021	,0x1e05	,0x203c	,0x0000	), // DOUBLE EXCLAMATION MARK
/*DOT_BELOW          */	DEADTRANS(	0x0029	,0x1e05	,0x1eb7	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	0x002b	,0x1e05	,0x203d	,0x0000	), // INTERROBANG
/*DOT_BELOW          */	DEADTRANS(	0x002c	,0x1e05	,0x1ee3	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	0x002e	,0x1e05	,0x1e69	,0x0001	), // LATIN SMALL LETTER S WITH DOT BELOW AND DOT ABOVE
/*DOT_BELOW          */	DEADTRANS(	0x003f	,0x1e69	,0x203d	,0x0000	), // INTERROBANG
/*DOT_BELOW          */	DEADTRANS(	0x003a	,0x1e05	,0x205d	,0x0000	), // TRICOLON
/*DOT_BELOW          */	DEADTRANS(	0x003f	,0x1e05	,0x2049	,0x0000	), // EXCLAMATION QUESTION MARK
/*DOT_BELOW          */	DEADTRANS(	0x005e	,0x1e05	,0x1ed9	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	0x005f	,0x1e05	,0x1e5d	,0x0001	), // LATIN SMALL LETTER R WITH DOT BELOW AND MACRON
/*DOT_BELOW          */	DEADTRANS(	0x00ea	,0x1e05	,0x1ed9	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	0x0229	,0x1e05	,0x1ee3	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	0x022f	,0x1e05	,0x1e69	,0x0001	), // LATIN SMALL LETTER S WITH DOT BELOW AND DOT ABOVE
/*DOT_BELOW          */	DEADTRANS(	0x014f	,0x1e05	,0x1eb7	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	0x014d	,0x1e05	,0x1e5d	,0x0001	), // LATIN SMALL LETTER R WITH DOT BELOW AND MACRON
/*DOT_BELOW          */	DEADTRANS(	0x01a1	,0x1e05	,0x1ee3	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	0x002d	,0x1e05	,0xa719	,0x0000	), // MODIFIER LETTER DOT HORIZONTAL BAR
/*DOT_BELOW          */	DEADTRANS(	0x002f	,0x1e05	,0xa718	,0x0000	), // MODIFIER LETTER DOT SLASH
/*DOT_BELOW          */	DEADTRANS(	0x007c	,0x1e05	,0xa717	,0x0000	), // MODIFIER LETTER DOT VERTICAL BAR
/*DOT_BELOW&MACRON   */	DEADTRANS(	L'L'	,0x1e5d	,0x1e38	,0x0000	), // LATIN CAPITAL LETTER L WITH DOT BELOW AND MACRON
/*DOT_BELOW&MACRON   */	DEADTRANS(	L'l'	,0x1e5d	,0x1e39	,0x0000	), // LATIN SMALL LETTER L WITH DOT BELOW AND MACRON
/*DOT_BELOW&MACRON   */	DEADTRANS(	L'R'	,0x1e5d	,0x1e5c	,0x0000	), // LATIN CAPITAL LETTER R WITH DOT BELOW AND MACRON
/*DOT_BELOW&MACRON   */	DEADTRANS(	L'r'	,0x1e5d	,0x1e5d	,0x0000	), // LATIN SMALL LETTER R WITH DOT BELOW AND MACRON
/*DOUBLE             */	DEADTRANS(	0x0020	,0x003d	,0x030b	,0x0000	), // COMBINING DOUBLE ACUTE ACCENT
/*DOUBLE             */	DEADTRANS(	0x202f	,0x003d	,0xa78a	,0x0000	), // MODIFIER LETTER SHORT EQUALS SIGN
/*DOUBLE             */	DEADTRANS(	L'L'	,0x003d	,0x2c60	,0x0000	), // LATIN CAPITAL LETTER L WITH DOUBLE BAR
/*DOUBLE             */	DEADTRANS(	L'l'	,0x003d	,0x2c61	,0x0000	), // LATIN SMALL LETTER L WITH DOUBLE BAR
/*DOUBLE             */	DEADTRANS(	L'O'	,0x003d	,0x0150	,0x0000	), // LATIN CAPITAL LETTER O WITH DOUBLE ACUTE
/*DOUBLE             */	DEADTRANS(	L'o'	,0x003d	,0x0151	,0x0000	), // LATIN SMALL LETTER O WITH DOUBLE ACUTE
/*DOUBLE             */	DEADTRANS(	L'U'	,0x003d	,0x0170	,0x0000	), // LATIN CAPITAL LETTER U WITH DOUBLE ACUTE
/*DOUBLE             */	DEADTRANS(	L'u'	,0x003d	,0x0171	,0x0000	), // LATIN SMALL LETTER U WITH DOUBLE ACUTE
/*DOUBLE             */	DEADTRANS(	0x0021	,0x003d	,0x203c	,0x0001	), // DOUBLE EXCLAMATION MARK
/*DOUBLE             */	DEADTRANS(	0x0025	,0x003d	,0x2031	,0x0000	), // PER TEN THOUSAND SIGN
/*DOUBLE             */	DEADTRANS(	0x0027	,0x003d	,0x0151	,0x0001	), // LATIN SMALL LETTER O WITH DOUBLE ACUTE
/*DOUBLE             */	DEADTRANS(	0x002d	,0x003d	,0x2261	,0x0000	), // IDENTICAL TO
/*DOUBLE             */	DEADTRANS(	0x002f	,0x003d	,0x2288	,0x0001	), // NEITHER A SUBSET OF NOR EQUAL TO
/*DOUBLE             */	DEADTRANS(	L'i'	,0x2288	,0x2288	,0x0000	), // NEITHER A SUBSET OF NOR EQUAL TO
/*DOUBLE             */	DEADTRANS(	L'n'	,0x2288	,0x2289	,0x0000	), // NEITHER A SUPERSET OF NOR EQUAL TO
/*DOUBLE             */	DEADTRANS(	0x002d	,0x2288	,0x2262	,0x0000	), // NOT IDENTICAL TO
/*DOUBLE             */	DEADTRANS(	L'0'	,0x003d	,0x21d5	,0x0000	), // UP DOWN DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'1'	,0x003d	,0x21d9	,0x0000	), // SOUTH WEST DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'2'	,0x003d	,0x21d3	,0x0000	), // DOWNWARDS DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'3'	,0x003d	,0x21d8	,0x0000	), // SOUTH EAST DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'4'	,0x003d	,0x21d0	,0x0000	), // LEFTWARDS DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'5'	,0x003d	,0x21d4	,0x0000	), // LEFT RIGHT DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'6'	,0x003d	,0x21d2	,0x0000	), // RIGHTWARDS DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'7'	,0x003d	,0x21d6	,0x0000	), // NORTH WEST DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'8'	,0x003d	,0x21d1	,0x0000	), // UPWARDS DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'9'	,0x003d	,0x21d7	,0x0000	), // NORTH EAST DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	0x003c	,0x003d	,0x21d0	,0x0000	), // LEFTWARDS DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	0x003d	,0x003d	,0x2263	,0x0000	), // STRICTLY EQUIVALENT TO
/*DOUBLE             */	DEADTRANS(	0x003e	,0x003d	,0x21d2	,0x0000	), // RIGHTWARDS DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	0x003f	,0x003d	,0x2047	,0x0000	), // DOUBLE QUESTION MARK
/*DOUBLE             */	DEADTRANS(	0x005f	,0x003d	,0x2017	,0x0000	), // DOUBLE LOW LINE
/*DOUBLE             */	DEADTRANS(	0x0060	,0x003d	,0x020d	,0x0001	), // LATIN SMALL LETTER O WITH DOUBLE GRAVE
/*DOUBLE             */	DEADTRANS(	0x007c	,0x0151	,0x2021	,0x0000	), // DOUBLE DAGGER
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x0020	,0x0151	,0x030b	,0x0000	), // COMBINING DOUBLE ACUTE ACCENT
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x00a0	,0x0151	,0x02dd	,0x0000	), // DOUBLE ACUTE ACCENT
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x202f	,0x0151	,0x02dd	,0x0000	), // DOUBLE ACUTE ACCENT
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'A'	,0x0151	,0x00c3	,0x0000	), // LATIN CAPITAL LETTER A WITH TILDE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'a'	,0x0151	,0x00e3	,0x0000	), // LATIN SMALL LETTER A WITH TILDE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'E'	,0x0151	,0x018e	,0x0000	), // LATIN CAPITAL LETTER REVERSED E
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'e'	,0x0151	,0x01dd	,0x0000	), // LATIN SMALL LETTER TURNED E
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'i'	,0x0151	,0x2286	,0x0000	), // SUBSET OF OR EQUAL TO
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'N'	,0x0151	,0x00d1	,0x0000	), // LATIN CAPITAL LETTER N WITH TILDE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'n'	,0x0151	,0x00f1	,0x0000	), // LATIN SMALL LETTER N WITH TILDE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'O'	,0x0151	,0x0150	,0x0000	), // LATIN CAPITAL LETTER O WITH DOUBLE ACUTE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'o'	,0x0151	,0x0151	,0x0000	), // LATIN SMALL LETTER O WITH DOUBLE ACUTE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L't'	,0x0151	,0x2021	,0x0000	), // DOUBLE DAGGER
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'U'	,0x0151	,0x0170	,0x0000	), // LATIN CAPITAL LETTER U WITH DOUBLE ACUTE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'u'	,0x0151	,0x0171	,0x0000	), // LATIN SMALL LETTER U WITH DOUBLE ACUTE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x0152	,0x0151	,0x01fe	,0x0000	), // LATIN CAPITAL LETTER O WITH STROKE AND ACUTE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x0153	,0x0151	,0x01ff	,0x0000	), // LATIN SMALL LETTER O WITH STROKE AND ACUTE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x0022	,0x0151	,0x02ee	,0x0000	), // MODIFIER LETTER DOUBLE APOSTROPHE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x0023	,0x0151	,0x02ee	,0x0000	), // MODIFIER LETTER DOUBLE APOSTROPHE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x0027	,0x0151	,0x02bc	,0x0000	), // MODIFIER LETTER APOSTROPHE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x002b	,0x0151	,0x02f6	,0x0000	), // MODIFIER LETTER MIDDLE DOUBLE ACUTE ACCENT
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'0'	,0x0151	,0x2195	,0x0000	), // UP DOWN ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'1'	,0x0151	,0x2199	,0x0000	), // SOUTH WEST ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'2'	,0x0151	,0x2193	,0x0000	), // DOWNWARDS ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'3'	,0x0151	,0x2198	,0x0000	), // SOUTH EAST ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'4'	,0x0151	,0x2190	,0x0000	), // LEFTWARDS ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'5'	,0x0151	,0x2194	,0x0000	), // LEFT RIGHT ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'6'	,0x0151	,0x2192	,0x0000	), // RIGHTWARDS ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'7'	,0x0151	,0x2196	,0x0000	), // NORTH WEST ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'8'	,0x0151	,0x2191	,0x0000	), // UPWARDS ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'9'	,0x0151	,0x2197	,0x0000	), // NORTH EAST ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x003d	,0x0151	,0x02ba	,0x0000	), // MODIFIER LETTER DOUBLE PRIME
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x00ea	,0x0151	,0x1ab0	,0x0000	), // COMBINING DOUBLED CIRCUMFLEX ACCENT
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x2019	,0x0151	,0x02bc	,0x0000	), // MODIFIER LETTER APOSTROPHE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x2610	,0x0151	,0x2750	,0x0000	), // UPPER RIGHT DROP-SHADOWED WHITE SQUARE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x222a	,0x0151	,0x2284	,0x0000	), // NOT A SUBSET OF
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x0020	,0x020d	,0x030f	,0x0000	), // COMBINING DOUBLE GRAVE ACCENT
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x00c0	,0x020d	,0x02f5	,0x0000	), // MODIFIER LETTER MIDDLE DOUBLE GRAVE ACCENT
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x00e0	,0x020d	,0x02f5	,0x0000	), // MODIFIER LETTER MIDDLE DOUBLE GRAVE ACCENT
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x00a0	,0x020d	,0x02f5	,0x0000	), // MODIFIER LETTER MIDDLE DOUBLE GRAVE ACCENT
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x202f	,0x020d	,0x02f5	,0x0000	), // MODIFIER LETTER MIDDLE DOUBLE GRAVE ACCENT
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'A'	,0x020d	,0x0200	,0x0000	), // LATIN CAPITAL LETTER A WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'a'	,0x020d	,0x0201	,0x0000	), // LATIN SMALL LETTER A WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'E'	,0x020d	,0x0204	,0x0000	), // LATIN CAPITAL LETTER E WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'e'	,0x020d	,0x0205	,0x0000	), // LATIN SMALL LETTER E WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'I'	,0x020d	,0x0208	,0x0000	), // LATIN CAPITAL LETTER I WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'i'	,0x020d	,0x0209	,0x0000	), // LATIN SMALL LETTER I WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'N'	,0x020d	,0x1daf	,0x0000	), // MODIFIER LETTER SMALL N WITH RETROFLEX HOOK
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'n'	,0x020d	,0x0273	,0x0000	), // LATIN SMALL LETTER N WITH RETROFLEX HOOK
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'O'	,0x020d	,0x020c	,0x0000	), // LATIN CAPITAL LETTER O WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'o'	,0x020d	,0x020d	,0x0000	), // LATIN SMALL LETTER O WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'R'	,0x020d	,0x0210	,0x0000	), // LATIN CAPITAL LETTER R WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'r'	,0x020d	,0x0211	,0x0000	), // LATIN SMALL LETTER R WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'U'	,0x020d	,0x0214	,0x0000	), // LATIN CAPITAL LETTER U WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'u'	,0x020d	,0x0215	,0x0000	), // LATIN SMALL LETTER U WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'W'	,0x020d	,0x2c72	,0x0000	), // LATIN CAPITAL LETTER W WITH HOOK
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'w'	,0x020d	,0x2c73	,0x0000	), // LATIN SMALL LETTER W WITH HOOK
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'Y'	,0x020d	,0x01b3	,0x0000	), // LATIN CAPITAL LETTER Y WITH HOOK
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'y'	,0x020d	,0x01b4	,0x0000	), // LATIN SMALL LETTER Y WITH HOOK
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x0152	,0x020d	,0x00d8	,0x0000	), // LATIN CAPITAL LETTER O WITH STROKE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x0153	,0x020d	,0x00f8	,0x0000	), // LATIN SMALL LETTER O WITH STROKE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x00f9	,0x020d	,0x02bb	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x0027	,0x020d	,0x02bb	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'0'	,0x020d	,0x21d5	,0x0000	), // UP DOWN DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'1'	,0x020d	,0x21d9	,0x0000	), // SOUTH WEST DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'2'	,0x020d	,0x21d3	,0x0000	), // DOWNWARDS DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'3'	,0x020d	,0x21d8	,0x0000	), // SOUTH EAST DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'4'	,0x020d	,0x21d0	,0x0000	), // LEFTWARDS DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'5'	,0x020d	,0x21d4	,0x0000	), // LEFT RIGHT DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'6'	,0x020d	,0x21d2	,0x0000	), // RIGHTWARDS DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'7'	,0x020d	,0x21d6	,0x0000	), // NORTH WEST DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'8'	,0x020d	,0x21d1	,0x0000	), // UPWARDS DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'9'	,0x020d	,0x21d7	,0x0000	), // NORTH EAST DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x2019	,0x020d	,0x02bb	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x2610	,0x020d	,0x274f	,0x0000	), // LOWER RIGHT DROP-SHADOWED WHITE SQUARE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x222a	,0x020d	,0x2285	,0x0000	), // NOT A SUPERSET OF
/*DOUBLE_MIDDLE_TILDE*/	DEADTRANS(	L'l'	,0xab38	,0xab38	,0x0000	), // LATIN SMALL LETTER L WITH DOUBLE MIDDLE TILDE
/*DOUBLE_TILDE       */	DEADTRANS(	L'l'	,0x00d5	,0xab38	,0x0000	), // LATIN SMALL LETTER L WITH DOUBLE MIDDLE TILDE
/*DOUBLE_TILDE       */	DEADTRANS(	0x003d	,0x00d5	,0x2243	,0x0000	), // ASYMPTOTICALLY EQUAL TO
/*G_DASIA            */	DEADTRANS(	0x00a0	,0x1f51	,0x1ffe	,0x0000	), // GREEK DASIA
/*G_DASIA            */	DEADTRANS(	0x202f	,0x1f51	,0x1ffe	,0x0000	), // GREEK DASIA
/*G_DASIA            */	DEADTRANS(	L'A'	,0x1f51	,0x1f09	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'a'	,0x1f51	,0x1f01	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'E'	,0x1f51	,0x1f19	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'e'	,0x1f51	,0x1f11	,0x0000	), // GREEK SMALL LETTER EPSILON WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'H'	,0x1f51	,0x1f29	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'h'	,0x1f51	,0x1f21	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'I'	,0x1f51	,0x1f39	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'i'	,0x1f51	,0x1f31	,0x0000	), // GREEK SMALL LETTER IOTA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'O'	,0x1f51	,0x1f49	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'o'	,0x1f51	,0x1f41	,0x0000	), // GREEK SMALL LETTER OMICRON WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'R'	,0x1f51	,0x1fec	,0x0000	), // GREEK CAPITAL LETTER RHO WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'r'	,0x1f51	,0x1fe5	,0x0000	), // GREEK SMALL LETTER RHO WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'V'	,0x1f51	,0x1f69	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'v'	,0x1f51	,0x1f61	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'W'	,0x1f51	,0x1f69	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'w'	,0x1f51	,0x1f61	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'Y'	,0x1f51	,0x1f59	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'y'	,0x1f51	,0x1f51	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x1f70	,0x1f51	,0x1f53	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND VARIA
/*G_DASIA            */	DEADTRANS(	0x1f7d	,0x1f51	,0x1f55	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND OXIA
/*G_DASIA            */	DEADTRANS(	0x1fc3	,0x1f51	,0x1fa1	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA            */	DEADTRANS(	0x1fc6	,0x1f51	,0x1f57	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND PERISPOMENI
/*G_DASIA            */	DEADTRANS(	0x002c	,0x1f51	,0x1f55	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND OXIA
/*G_DASIA            */	DEADTRANS(	0x003b	,0x1f51	,0x1fa1	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA            */	DEADTRANS(	0x0060	,0x1f51	,0x1f53	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND VARIA
/*G_DASIA            */	DEADTRANS(	0x007e	,0x1f51	,0x1f57	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND PERISPOMENI
/*G_DASIA            */	DEADTRANS(	0x0391	,0x1f51	,0x1f09	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03b1	,0x1f51	,0x1f01	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x0395	,0x1f51	,0x1f19	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03b5	,0x1f51	,0x1f11	,0x0000	), // GREEK SMALL LETTER EPSILON WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x0397	,0x1f51	,0x1f29	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03b7	,0x1f51	,0x1f21	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x0399	,0x1f51	,0x1f39	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03b9	,0x1f51	,0x1f31	,0x0000	), // GREEK SMALL LETTER IOTA WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x039f	,0x1f51	,0x1f49	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03bf	,0x1f51	,0x1f41	,0x0000	), // GREEK SMALL LETTER OMICRON WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03a1	,0x1f51	,0x1fec	,0x0000	), // GREEK CAPITAL LETTER RHO WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03c1	,0x1f51	,0x1fe5	,0x0000	), // GREEK SMALL LETTER RHO WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03a5	,0x1f51	,0x1f59	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03c5	,0x1f51	,0x1f51	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03a9	,0x1f51	,0x1f69	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03c9	,0x1f51	,0x1f61	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA
/*G_DASIA&I          */	DEADTRANS(	L'A'	,0x1fa1	,0x1f89	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND PROSGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	L'a'	,0x1fa1	,0x1f81	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	L'H'	,0x1fa1	,0x1f99	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND PROSGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	L'h'	,0x1fa1	,0x1f91	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	L'V'	,0x1fa1	,0x1fa9	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PROSGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	L'v'	,0x1fa1	,0x1fa1	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	L'W'	,0x1fa1	,0x1fa9	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PROSGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	L'w'	,0x1fa1	,0x1fa1	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x1f70	,0x1fa1	,0x1f93	,0x0001	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x1f7d	,0x1fa1	,0x1fa5	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x002c	,0x1fa1	,0x1fa5	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x0060	,0x1fa1	,0x1f93	,0x0001	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x0391	,0x1fa1	,0x1f89	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND PROSGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x03b1	,0x1fa1	,0x1f81	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x0397	,0x1fa1	,0x1f99	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND PROSGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x03b7	,0x1fa1	,0x1f91	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x03a9	,0x1fa1	,0x1fa9	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PROSGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x03c9	,0x1fa1	,0x1fa1	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA       */	DEADTRANS(	0x00a0	,0x1f55	,0x1fde	,0x0000	), // GREEK DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'A'	,0x1f55	,0x1f0d	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'a'	,0x1f55	,0x1f05	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'E'	,0x1f55	,0x1f1d	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'e'	,0x1f55	,0x1f15	,0x0000	), // GREEK SMALL LETTER EPSILON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'H'	,0x1f55	,0x1f2d	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'h'	,0x1f55	,0x1f25	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'I'	,0x1f55	,0x1f3d	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'i'	,0x1f55	,0x1f35	,0x0000	), // GREEK SMALL LETTER IOTA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'O'	,0x1f55	,0x1f4d	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'o'	,0x1f55	,0x1f45	,0x0000	), // GREEK SMALL LETTER OMICRON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'V'	,0x1f55	,0x1f6d	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'v'	,0x1f55	,0x1f65	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'W'	,0x1f55	,0x1f6d	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'w'	,0x1f55	,0x1f65	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'Y'	,0x1f55	,0x1f5d	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'y'	,0x1f55	,0x1f55	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x1fc3	,0x1f55	,0x1fa5	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA       */	DEADTRANS(	0x003b	,0x1f55	,0x1fa5	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA       */	DEADTRANS(	0x0391	,0x1f55	,0x1f0d	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03b1	,0x1f55	,0x1f05	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x0395	,0x1f55	,0x1f1d	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03b5	,0x1f55	,0x1f15	,0x0000	), // GREEK SMALL LETTER EPSILON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x0397	,0x1f55	,0x1f2d	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03b7	,0x1f55	,0x1f25	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x0399	,0x1f55	,0x1f3d	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03b9	,0x1f55	,0x1f35	,0x0000	), // GREEK SMALL LETTER IOTA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x039f	,0x1f55	,0x1f4d	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03bf	,0x1f55	,0x1f45	,0x0000	), // GREEK SMALL LETTER OMICRON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03a5	,0x1f55	,0x1f5d	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03c5	,0x1f55	,0x1f55	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03a9	,0x1f55	,0x1f6d	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03c9	,0x1f55	,0x1f65	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA
/*G_DASIA&OXIA&I     */	DEADTRANS(	0x0391	,0x1fa5	,0x1f8d	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND OXIA AND PROSGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	0x0397	,0x1fa5	,0x1f9d	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND OXIA AND PROSGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	0x03a9	,0x1fa5	,0x1fad	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND OXIA AND PROSGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	0x03b1	,0x1fa5	,0x1f85	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	0x03b7	,0x1fa5	,0x1f95	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	0x03c9	,0x1fa5	,0x1fa5	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	L'A'	,0x1fa5	,0x1f8d	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND OXIA AND PROSGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	L'H'	,0x1fa5	,0x1f9d	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND OXIA AND PROSGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	L'V'	,0x1fa5	,0x1fad	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND OXIA AND PROSGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	L'W'	,0x1fa5	,0x1fad	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND OXIA AND PROSGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	L'a'	,0x1fa5	,0x1f85	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	L'h'	,0x1fa5	,0x1f95	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	L'v'	,0x1fa5	,0x1fa5	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	L'w'	,0x1fa5	,0x1fa5	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x00a0	,0x1f57	,0x1fdf	,0x0000	), // GREEK DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x202f	,0x1f57	,0x1fdf	,0x0000	), // GREEK DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'A'	,0x1f57	,0x1f0f	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'a'	,0x1f57	,0x1f07	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'H'	,0x1f57	,0x1f2f	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'h'	,0x1f57	,0x1f27	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'I'	,0x1f57	,0x1f3f	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'i'	,0x1f57	,0x1f37	,0x0000	), // GREEK SMALL LETTER IOTA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'V'	,0x1f57	,0x1f6f	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'v'	,0x1f57	,0x1f67	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'W'	,0x1f57	,0x1f6f	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'w'	,0x1f57	,0x1f67	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'Y'	,0x1f57	,0x1f5f	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'y'	,0x1f57	,0x1f57	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x1fc3	,0x1f57	,0x1f87	,0x0001	), // GREEK SMALL LETTER ALPHA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x003b	,0x1f57	,0x1f87	,0x0001	), // GREEK SMALL LETTER ALPHA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x0391	,0x1f57	,0x1f0f	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x03b1	,0x1f57	,0x1f07	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x0397	,0x1f57	,0x1f2f	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x03b7	,0x1f57	,0x1f27	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x0399	,0x1f57	,0x1f3f	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x03b9	,0x1f57	,0x1f37	,0x0000	), // GREEK SMALL LETTER IOTA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x03a5	,0x1f57	,0x1f5f	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x03c5	,0x1f57	,0x1f57	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x03a9	,0x1f57	,0x1f6f	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x03c9	,0x1f57	,0x1f67	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	L'A'	,0x1f87	,0x1f8f	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND PERISPOMENI AND PROSGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	L'H'	,0x1f87	,0x1f9f	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND PERISPOMENI AND PROSGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	L'V'	,0x1f87	,0x1faf	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PERISPOMENI AND PROSGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	L'W'	,0x1f87	,0x1faf	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PERISPOMENI AND PROSGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	L'a'	,0x1f87	,0x1f87	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	L'h'	,0x1f87	,0x1f97	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	L'v'	,0x1f87	,0x1fa7	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	L'w'	,0x1f87	,0x1fa7	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	0x0391	,0x1f87	,0x1f8f	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND PERISPOMENI AND PROSGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	0x03b1	,0x1f87	,0x1f87	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	0x0397	,0x1f87	,0x1f9f	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND PERISPOMENI AND PROSGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	0x03b7	,0x1f87	,0x1f97	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	0x03a9	,0x1f87	,0x1faf	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PERISPOMENI AND PROSGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	0x03c9	,0x1f87	,0x1fa7	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&VARIA      */	DEADTRANS(	0x00a0	,0x1f53	,0x1fdd	,0x0000	), // GREEK DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'A'	,0x1f53	,0x1f0b	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'a'	,0x1f53	,0x1f03	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'E'	,0x1f53	,0x1f1b	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'e'	,0x1f53	,0x1f13	,0x0000	), // GREEK SMALL LETTER EPSILON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'H'	,0x1f53	,0x1f2b	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'h'	,0x1f53	,0x1f23	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'I'	,0x1f53	,0x1f3b	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'i'	,0x1f53	,0x1f33	,0x0000	), // GREEK SMALL LETTER IOTA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'O'	,0x1f53	,0x1f4b	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'o'	,0x1f53	,0x1f43	,0x0000	), // GREEK SMALL LETTER OMICRON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'V'	,0x1f53	,0x1f6b	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'v'	,0x1f53	,0x1f63	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'W'	,0x1f53	,0x1f6b	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'w'	,0x1f53	,0x1f63	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'Y'	,0x1f53	,0x1f5b	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'y'	,0x1f53	,0x1f53	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x1fc3	,0x1f53	,0x1f93	,0x0001	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&VARIA      */	DEADTRANS(	0x003b	,0x1f53	,0x1f93	,0x0001	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&VARIA      */	DEADTRANS(	0x0391	,0x1f53	,0x1f0b	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03b1	,0x1f53	,0x1f03	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x0395	,0x1f53	,0x1f1b	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03b5	,0x1f53	,0x1f13	,0x0000	), // GREEK SMALL LETTER EPSILON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x0397	,0x1f53	,0x1f2b	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03b7	,0x1f53	,0x1f23	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x0399	,0x1f53	,0x1f3b	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03b9	,0x1f53	,0x1f33	,0x0000	), // GREEK SMALL LETTER IOTA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x039f	,0x1f53	,0x1f4b	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03bf	,0x1f53	,0x1f43	,0x0000	), // GREEK SMALL LETTER OMICRON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03a5	,0x1f53	,0x1f5b	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03c5	,0x1f53	,0x1f53	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03a9	,0x1f53	,0x1f6b	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03c9	,0x1f53	,0x1f63	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND VARIA
/*G_DASIA&VARIA&I    */	DEADTRANS(	L'A'	,0x1f93	,0x1f8b	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND VARIA AND PROSGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	L'H'	,0x1f93	,0x1f9b	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND VARIA AND PROSGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	L'V'	,0x1f93	,0x1fab	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND VARIA AND PROSGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	L'W'	,0x1f93	,0x1fab	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND VARIA AND PROSGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	L'a'	,0x1f93	,0x1f83	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	L'h'	,0x1f93	,0x1f93	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	L'v'	,0x1f93	,0x1fa3	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	L'w'	,0x1f93	,0x1fa3	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	0x0391	,0x1f93	,0x1f8b	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND VARIA AND PROSGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	0x03b1	,0x1f93	,0x1f83	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	0x0397	,0x1f93	,0x1f9b	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND VARIA AND PROSGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	0x03b7	,0x1f93	,0x1f93	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	0x03a9	,0x1f93	,0x1fab	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND VARIA AND PROSGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	0x03c9	,0x1f93	,0x1fa3	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DIALYTIKA        */	DEADTRANS(	0x0020	,0x03ca	,0x0308	,0x0000	), // COMBINING DIAERESIS
/*G_DIALYTIKA        */	DEADTRANS(	0x00a0	,0x03ca	,0x00a8	,0x0000	), // DIAERESIS
/*G_DIALYTIKA        */	DEADTRANS(	0x202f	,0x03ca	,0x00a8	,0x0000	), // DIAERESIS
/*G_DIALYTIKA        */	DEADTRANS(	L'I'	,0x03ca	,0x03aa	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DIALYTIKA
/*G_DIALYTIKA        */	DEADTRANS(	L'i'	,0x03ca	,0x03ca	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA
/*G_DIALYTIKA        */	DEADTRANS(	L'Y'	,0x03ca	,0x03ab	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DIALYTIKA
/*G_DIALYTIKA        */	DEADTRANS(	L'y'	,0x03ca	,0x03cb	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA
/*G_DIALYTIKA        */	DEADTRANS(	0x03cc	,0x03ca	,0x0390	,0x0001	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS
/*G_DIALYTIKA        */	DEADTRANS(	0x1f70	,0x03ca	,0x1fe2	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND VARIA
/*G_DIALYTIKA        */	DEADTRANS(	0x1f7d	,0x03ca	,0x1fe3	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND OXIA
/*G_DIALYTIKA        */	DEADTRANS(	0x1fc6	,0x03ca	,0x1fe7	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND PERISPOMENI
/*G_DIALYTIKA        */	DEADTRANS(	0x002c	,0x03ca	,0x1fe3	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND OXIA
/*G_DIALYTIKA        */	DEADTRANS(	0x0027	,0x03ca	,0x0390	,0x0001	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS
/*G_DIALYTIKA        */	DEADTRANS(	0x0060	,0x03ca	,0x1fe2	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND VARIA
/*G_DIALYTIKA        */	DEADTRANS(	0x007e	,0x03ca	,0x1fe7	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND PERISPOMENI
/*G_DIALYTIKA        */	DEADTRANS(	0x0399	,0x03ca	,0x03aa	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DIALYTIKA
/*G_DIALYTIKA        */	DEADTRANS(	0x03b9	,0x03ca	,0x03ca	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA
/*G_DIALYTIKA        */	DEADTRANS(	0x03a5	,0x03ca	,0x03ab	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DIALYTIKA
/*G_DIALYTIKA        */	DEADTRANS(	0x03c5	,0x03ca	,0x03cb	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA
/*G_DIALYTIKA&OXIA   */	DEADTRANS(	0x00a0	,0x1fe3	,0x1fee	,0x0000	), // GREEK DIALYTIKA AND OXIA
/*G_DIALYTIKA&OXIA   */	DEADTRANS(	L'i'	,0x1fe3	,0x1fd3	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND OXIA
/*G_DIALYTIKA&OXIA   */	DEADTRANS(	L'y'	,0x1fe3	,0x1fe3	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND OXIA
/*G_DIALYTIKA&OXIA   */	DEADTRANS(	0x03b9	,0x1fe3	,0x1fd3	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND OXIA
/*G_DIALYTIKA&OXIA   */	DEADTRANS(	0x03c5	,0x1fe3	,0x1fe3	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND OXIA
/*G_DIALYTIKA&PERI   */	DEADTRANS(	0x00a0	,0x1fe7	,0x1fc1	,0x0000	), // GREEK DIALYTIKA AND PERISPOMENI
/*G_DIALYTIKA&PERI   */	DEADTRANS(	L'i'	,0x1fe7	,0x1fd7	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND PERISPOMENI
/*G_DIALYTIKA&PERI   */	DEADTRANS(	L'y'	,0x1fe7	,0x1fe7	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND PERISPOMENI
/*G_DIALYTIKA&PERI   */	DEADTRANS(	0x03b9	,0x1fe7	,0x1fd7	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND PERISPOMENI
/*G_DIALYTIKA&PERI   */	DEADTRANS(	0x03c5	,0x1fe7	,0x1fe7	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND PERISPOMENI
/*G_DIALYTIKA&TONOS  */	DEADTRANS(	0x0020	,0x0390	,0x0344	,0x0000	), // COMBINING GREEK DIALYTIKA TONOS
/*G_DIALYTIKA&TONOS  */	DEADTRANS(	0x00a0	,0x0390	,0x0385	,0x0000	), // GREEK DIALYTIKA TONOS
/*G_DIALYTIKA&TONOS  */	DEADTRANS(	0x202f	,0x0390	,0x0385	,0x0000	), // GREEK DIALYTIKA TONOS
/*G_DIALYTIKA&TONOS  */	DEADTRANS(	L'i'	,0x0390	,0x0390	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS
/*G_DIALYTIKA&TONOS  */	DEADTRANS(	L'y'	,0x0390	,0x03b0	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND TONOS
/*G_DIALYTIKA&TONOS  */	DEADTRANS(	0x03b9	,0x0390	,0x0390	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS
/*G_DIALYTIKA&TONOS  */	DEADTRANS(	0x03c5	,0x0390	,0x03b0	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND TONOS
/*G_DIALYTIKA&VARIA  */	DEADTRANS(	0x00a0	,0x1fe2	,0x1fed	,0x0000	), // GREEK DIALYTIKA AND VARIA
/*G_DIALYTIKA&VARIA  */	DEADTRANS(	L'i'	,0x1fe2	,0x1fd2	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND VARIA
/*G_DIALYTIKA&VARIA  */	DEADTRANS(	L'y'	,0x1fe2	,0x1fe2	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND VARIA
/*G_DIALYTIKA&VARIA  */	DEADTRANS(	0x03b9	,0x1fe2	,0x1fd2	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND VARIA
/*G_DIALYTIKA&VARIA  */	DEADTRANS(	0x03c5	,0x1fe2	,0x1fe2	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND VARIA
/*G_KORONIS          */	DEADTRANS(	0x0020	,0x1fbd	,0x0343	,0x0000	), // COMBINING GREEK KORONIS
/*G_KORONIS          */	DEADTRANS(	0x00a0	,0x1fbd	,0x1fbd	,0x0000	), // GREEK KORONIS
/*G_MACRON           */	DEADTRANS(	0x0020	,0x1fb1	,0x0304	,0x0000	), // COMBINING MACRON
/*G_MACRON           */	DEADTRANS(	0x00a0	,0x1fb1	,0x00af	,0x0000	), // MACRON
/*G_MACRON           */	DEADTRANS(	0x202f	,0x1fb1	,0x02c9	,0x0000	), // MODIFIER LETTER MACRON
/*G_MACRON           */	DEADTRANS(	L'A'	,0x1fb1	,0x1fb9	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH MACRON
/*G_MACRON           */	DEADTRANS(	L'a'	,0x1fb1	,0x1fb1	,0x0000	), // GREEK SMALL LETTER ALPHA WITH MACRON
/*G_MACRON           */	DEADTRANS(	L'I'	,0x1fb1	,0x1fd9	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH MACRON
/*G_MACRON           */	DEADTRANS(	L'i'	,0x1fb1	,0x1fd1	,0x0000	), // GREEK SMALL LETTER IOTA WITH MACRON
/*G_MACRON           */	DEADTRANS(	L'Y'	,0x1fb1	,0x1fe9	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH MACRON
/*G_MACRON           */	DEADTRANS(	L'y'	,0x1fb1	,0x1fe1	,0x0000	), // GREEK SMALL LETTER UPSILON WITH MACRON
/*G_MACRON           */	DEADTRANS(	0x0391	,0x1fb1	,0x1fb9	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH MACRON
/*G_MACRON           */	DEADTRANS(	0x03b1	,0x1fb1	,0x1fb1	,0x0000	), // GREEK SMALL LETTER ALPHA WITH MACRON
/*G_MACRON           */	DEADTRANS(	0x0399	,0x1fb1	,0x1fd9	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH MACRON
/*G_MACRON           */	DEADTRANS(	0x03b9	,0x1fb1	,0x1fd1	,0x0000	), // GREEK SMALL LETTER IOTA WITH MACRON
/*G_MACRON           */	DEADTRANS(	0x03a5	,0x1fb1	,0x1fe9	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH MACRON
/*G_MACRON           */	DEADTRANS(	0x03c5	,0x1fb1	,0x1fe1	,0x0000	), // GREEK SMALL LETTER UPSILON WITH MACRON
/*G_OXIA             */	DEADTRANS(	0x0020	,0x1f7d	,0x0301	,0x0000	), // COMBINING ACUTE ACCENT
/*G_OXIA             */	DEADTRANS(	0x00a0	,0x1f7d	,0x1ffd	,0x0000	), // GREEK OXIA
/*G_OXIA             */	DEADTRANS(	0x202f	,0x1f7d	,0x1ffd	,0x0000	), // GREEK OXIA
/*G_OXIA             */	DEADTRANS(	L'A'	,0x1f7d	,0x1fbb	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'a'	,0x1f7d	,0x1f71	,0x0000	), // GREEK SMALL LETTER ALPHA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'E'	,0x1f7d	,0x1fc9	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'e'	,0x1f7d	,0x1f73	,0x0000	), // GREEK SMALL LETTER EPSILON WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'H'	,0x1f7d	,0x1fcb	,0x0000	), // GREEK CAPITAL LETTER ETA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'h'	,0x1f7d	,0x1f75	,0x0000	), // GREEK SMALL LETTER ETA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'I'	,0x1f7d	,0x1fdb	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'i'	,0x1f7d	,0x1f77	,0x0000	), // GREEK SMALL LETTER IOTA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'O'	,0x1f7d	,0x1ff9	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'o'	,0x1f7d	,0x1f79	,0x0000	), // GREEK SMALL LETTER OMICRON WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'V'	,0x1f7d	,0x1ffb	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'v'	,0x1f7d	,0x1f7d	,0x0000	), // GREEK SMALL LETTER OMEGA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'W'	,0x1f7d	,0x1ffb	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'w'	,0x1f7d	,0x1f7d	,0x0000	), // GREEK SMALL LETTER OMEGA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'Y'	,0x1f7d	,0x1feb	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'y'	,0x1f7d	,0x1f7b	,0x0000	), // GREEK SMALL LETTER UPSILON WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x1f10	,0x1f7d	,0x1f14	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI AND OXIA
/*G_OXIA             */	DEADTRANS(	0x1f51	,0x1f7d	,0x1f55	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND OXIA
/*G_OXIA             */	DEADTRANS(	0x003c	,0x1f7d	,0x1f55	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND OXIA
/*G_OXIA             */	DEADTRANS(	0x003e	,0x1f7d	,0x1f14	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI AND OXIA
/*G_OXIA             */	DEADTRANS(	0x0391	,0x1f7d	,0x1fbb	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03b1	,0x1f7d	,0x1f71	,0x0000	), // GREEK SMALL LETTER ALPHA WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x0395	,0x1f7d	,0x1fc9	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03b5	,0x1f7d	,0x1f73	,0x0000	), // GREEK SMALL LETTER EPSILON WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x0397	,0x1f7d	,0x1fcb	,0x0000	), // GREEK CAPITAL LETTER ETA WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03b7	,0x1f7d	,0x1f75	,0x0000	), // GREEK SMALL LETTER ETA WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x0399	,0x1f7d	,0x1fdb	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03b9	,0x1f7d	,0x1f77	,0x0000	), // GREEK SMALL LETTER IOTA WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x039f	,0x1f7d	,0x1ff9	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03bf	,0x1f7d	,0x1f79	,0x0000	), // GREEK SMALL LETTER OMICRON WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03a5	,0x1f7d	,0x1feb	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03c5	,0x1f7d	,0x1f7b	,0x0000	), // GREEK SMALL LETTER UPSILON WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03a9	,0x1f7d	,0x1ffb	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03c9	,0x1f7d	,0x1f7d	,0x0000	), // GREEK SMALL LETTER OMEGA WITH OXIA
/*G_OXIA&I           */	DEADTRANS(	L'a'	,0x1ff4	,0x1fb4	,0x0000	), // GREEK SMALL LETTER ALPHA WITH OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	L'h'	,0x1ff4	,0x1fc4	,0x0000	), // GREEK SMALL LETTER ETA WITH OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	L'v'	,0x1ff4	,0x1ff4	,0x0000	), // GREEK SMALL LETTER OMEGA WITH OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	L'w'	,0x1ff4	,0x1ff4	,0x0000	), // GREEK SMALL LETTER OMEGA WITH OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	0x1f10	,0x1ff4	,0x1f84	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	0x1f51	,0x1ff4	,0x1fa5	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	0x003c	,0x1ff4	,0x1fa5	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	0x003e	,0x1ff4	,0x1f84	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	0x03b1	,0x1ff4	,0x1fb4	,0x0000	), // GREEK SMALL LETTER ALPHA WITH OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	0x03b7	,0x1ff4	,0x1fc4	,0x0000	), // GREEK SMALL LETTER ETA WITH OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	0x03c9	,0x1ff4	,0x1ff4	,0x0000	), // GREEK SMALL LETTER OMEGA WITH OXIA AND YPOGEGRAMMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x0020	,0x1fc6	,0x0342	,0x0000	), // COMBINING GREEK PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x00a0	,0x1fc6	,0x1fc0	,0x0000	), // GREEK PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x202f	,0x1fc6	,0x1fc0	,0x0000	), // GREEK PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	L'a'	,0x1fc6	,0x1fb6	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	L'h'	,0x1fc6	,0x1fc6	,0x0000	), // GREEK SMALL LETTER ETA WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	L'i'	,0x1fc6	,0x1fd6	,0x0000	), // GREEK SMALL LETTER IOTA WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	L'v'	,0x1fc6	,0x1ff6	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	L'w'	,0x1fc6	,0x1ff6	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	L'y'	,0x1fc6	,0x1fe6	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x1f10	,0x1fc6	,0x1f26	,0x0001	), // GREEK SMALL LETTER ETA WITH PSILI AND PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x1f51	,0x1fc6	,0x1f57	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x003c	,0x1fc6	,0x1f57	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x003e	,0x1fc6	,0x1f26	,0x0001	), // GREEK SMALL LETTER ETA WITH PSILI AND PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x03b1	,0x1fc6	,0x1fb6	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x03b7	,0x1fc6	,0x1fc6	,0x0000	), // GREEK SMALL LETTER ETA WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x03b9	,0x1fc6	,0x1fd6	,0x0000	), // GREEK SMALL LETTER IOTA WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x03c5	,0x1fc6	,0x1fe6	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x03c9	,0x1fc6	,0x1ff6	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PERISPOMENI
/*G_PERISPOMENI&I    */	DEADTRANS(	L'a'	,0x1fc7	,0x1fb7	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_PERISPOMENI&I    */	DEADTRANS(	L'h'	,0x1fc7	,0x1fc7	,0x0000	), // GREEK SMALL LETTER ETA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_PERISPOMENI&I    */	DEADTRANS(	L'v'	,0x1fc7	,0x1ff7	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_PERISPOMENI&I    */	DEADTRANS(	L'w'	,0x1fc7	,0x1ff7	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_PERISPOMENI&I    */	DEADTRANS(	0x03b1	,0x1fc7	,0x1fb7	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_PERISPOMENI&I    */	DEADTRANS(	0x03b7	,0x1fc7	,0x1fc7	,0x0000	), // GREEK SMALL LETTER ETA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_PERISPOMENI&I    */	DEADTRANS(	0x03c9	,0x1fc7	,0x1ff7	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI            */	DEADTRANS(	0x00a0	,0x1f10	,0x1fbf	,0x0000	), // GREEK PSILI
/*G_PSILI            */	DEADTRANS(	0x202f	,0x1f10	,0x1fbf	,0x0000	), // GREEK PSILI
/*G_PSILI            */	DEADTRANS(	L'A'	,0x1f10	,0x1f08	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'a'	,0x1f10	,0x1f00	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'E'	,0x1f10	,0x1f18	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'e'	,0x1f10	,0x1f10	,0x0000	), // GREEK SMALL LETTER EPSILON WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'H'	,0x1f10	,0x1f28	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'h'	,0x1f10	,0x1f20	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'I'	,0x1f10	,0x1f38	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'i'	,0x1f10	,0x1f30	,0x0000	), // GREEK SMALL LETTER IOTA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'O'	,0x1f10	,0x1f48	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'o'	,0x1f10	,0x1f40	,0x0000	), // GREEK SMALL LETTER OMICRON WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'r'	,0x1f10	,0x1fe4	,0x0000	), // GREEK SMALL LETTER RHO WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'V'	,0x1f10	,0x1f68	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'v'	,0x1f10	,0x1f60	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'W'	,0x1f10	,0x1f68	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'w'	,0x1f10	,0x1f60	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'y'	,0x1f10	,0x1f50	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x1f70	,0x1f10	,0x1f12	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI AND VARIA
/*G_PSILI            */	DEADTRANS(	0x1f7d	,0x1f10	,0x1f14	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI AND OXIA
/*G_PSILI            */	DEADTRANS(	0x1fc3	,0x1f10	,0x1f90	,0x0001	), // GREEK SMALL LETTER ETA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI            */	DEADTRANS(	0x1fc6	,0x1f10	,0x1f26	,0x0001	), // GREEK SMALL LETTER ETA WITH PSILI AND PERISPOMENI
/*G_PSILI            */	DEADTRANS(	0x002c	,0x1f10	,0x1f14	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI AND OXIA
/*G_PSILI            */	DEADTRANS(	0x003b	,0x1f10	,0x1f90	,0x0001	), // GREEK SMALL LETTER ETA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI            */	DEADTRANS(	0x0060	,0x1f10	,0x1f12	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI AND VARIA
/*G_PSILI            */	DEADTRANS(	0x007e	,0x1f10	,0x1f26	,0x0001	), // GREEK SMALL LETTER ETA WITH PSILI AND PERISPOMENI
/*G_PSILI            */	DEADTRANS(	0x0391	,0x1f10	,0x1f08	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03b1	,0x1f10	,0x1f00	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x0395	,0x1f10	,0x1f18	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03b5	,0x1f10	,0x1f10	,0x0000	), // GREEK SMALL LETTER EPSILON WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x0397	,0x1f10	,0x1f28	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03b7	,0x1f10	,0x1f20	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x0399	,0x1f10	,0x1f38	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03b9	,0x1f10	,0x1f30	,0x0000	), // GREEK SMALL LETTER IOTA WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x039f	,0x1f10	,0x1f48	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03bf	,0x1f10	,0x1f40	,0x0000	), // GREEK SMALL LETTER OMICRON WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03c1	,0x1f10	,0x1fe4	,0x0000	), // GREEK SMALL LETTER RHO WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03c5	,0x1f10	,0x1f50	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03a9	,0x1f10	,0x1f68	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03c9	,0x1f10	,0x1f60	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI
/*G_PSILI&I          */	DEADTRANS(	L'A'	,0x1f90	,0x1f88	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND PROSGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	L'a'	,0x1f90	,0x1f80	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	L'H'	,0x1f90	,0x1f98	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND PROSGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	L'h'	,0x1f90	,0x1f90	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	L'V'	,0x1f90	,0x1fa8	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PROSGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	L'v'	,0x1f90	,0x1fa0	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	L'W'	,0x1f90	,0x1fa8	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PROSGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	L'w'	,0x1f90	,0x1fa0	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x1f70	,0x1f90	,0x1f82	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x1f7d	,0x1f90	,0x1f84	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x002c	,0x1f90	,0x1f84	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x0060	,0x1f90	,0x1f82	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x0391	,0x1f90	,0x1f88	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND PROSGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x03b1	,0x1f90	,0x1f80	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x0397	,0x1f90	,0x1f98	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND PROSGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x03b7	,0x1f90	,0x1f90	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x03a9	,0x1f90	,0x1fa8	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PROSGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x03c9	,0x1f90	,0x1fa0	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI&OXIA       */	DEADTRANS(	0x00a0	,0x1f14	,0x1fce	,0x0000	), // GREEK PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'A'	,0x1f14	,0x1f0c	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'a'	,0x1f14	,0x1f04	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'E'	,0x1f14	,0x1f1c	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'e'	,0x1f14	,0x1f14	,0x0000	), // GREEK SMALL LETTER EPSILON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'H'	,0x1f14	,0x1f2c	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'h'	,0x1f14	,0x1f24	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'I'	,0x1f14	,0x1f3c	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'i'	,0x1f14	,0x1f34	,0x0000	), // GREEK SMALL LETTER IOTA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'O'	,0x1f14	,0x1f4c	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'o'	,0x1f14	,0x1f44	,0x0000	), // GREEK SMALL LETTER OMICRON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'V'	,0x1f14	,0x1f6c	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'v'	,0x1f14	,0x1f64	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'W'	,0x1f14	,0x1f6c	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'w'	,0x1f14	,0x1f64	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'y'	,0x1f14	,0x1f54	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x1fc3	,0x1f14	,0x1f84	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&OXIA       */	DEADTRANS(	0x003b	,0x1f14	,0x1f84	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&OXIA       */	DEADTRANS(	0x0391	,0x1f14	,0x1f0c	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x03b1	,0x1f14	,0x1f04	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x0395	,0x1f14	,0x1f1c	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x03b5	,0x1f14	,0x1f14	,0x0000	), // GREEK SMALL LETTER EPSILON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x0397	,0x1f14	,0x1f2c	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x03b7	,0x1f14	,0x1f24	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x0399	,0x1f14	,0x1f3c	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x03b9	,0x1f14	,0x1f34	,0x0000	), // GREEK SMALL LETTER IOTA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x039f	,0x1f14	,0x1f4c	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x03bf	,0x1f14	,0x1f44	,0x0000	), // GREEK SMALL LETTER OMICRON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x03c5	,0x1f14	,0x1f54	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x03a9	,0x1f14	,0x1f6c	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x03c9	,0x1f14	,0x1f64	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND OXIA
/*G_PSILI&OXIA&I     */	DEADTRANS(	L'A'	,0x1f84	,0x1f8c	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND OXIA AND PROSGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	L'a'	,0x1f84	,0x1f84	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	L'H'	,0x1f84	,0x1f9c	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND OXIA AND PROSGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	L'h'	,0x1f84	,0x1f94	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	L'V'	,0x1f84	,0x1fac	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND OXIA AND PROSGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	L'v'	,0x1f84	,0x1fa4	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	L'W'	,0x1f84	,0x1fac	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND OXIA AND PROSGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	L'w'	,0x1f84	,0x1fa4	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	0x0391	,0x1f84	,0x1f8c	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND OXIA AND PROSGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	0x03b1	,0x1f84	,0x1f84	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	0x0397	,0x1f84	,0x1f9c	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND OXIA AND PROSGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	0x03b7	,0x1f84	,0x1f94	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	0x03a9	,0x1f84	,0x1fac	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND OXIA AND PROSGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	0x03c9	,0x1f84	,0x1fa4	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x00a0	,0x1f26	,0x1fcf	,0x0000	), // GREEK PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x202f	,0x1f26	,0x1fcf	,0x0000	), // GREEK PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'A'	,0x1f26	,0x1f0e	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'a'	,0x1f26	,0x1f06	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'H'	,0x1f26	,0x1f2e	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'h'	,0x1f26	,0x1f26	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'I'	,0x1f26	,0x1f3e	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'i'	,0x1f26	,0x1f36	,0x0000	), // GREEK SMALL LETTER IOTA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'V'	,0x1f26	,0x1f6e	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'v'	,0x1f26	,0x1f66	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'W'	,0x1f26	,0x1f6e	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'w'	,0x1f26	,0x1f66	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'y'	,0x1f26	,0x1f56	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x1fc3	,0x1f26	,0x1fa6	,0x0001	), // GREEK SMALL LETTER OMEGA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x003b	,0x1f26	,0x1fa6	,0x0001	), // GREEK SMALL LETTER OMEGA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x0391	,0x1f26	,0x1f0e	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x03b1	,0x1f26	,0x1f06	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x0397	,0x1f26	,0x1f2e	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x03b7	,0x1f26	,0x1f26	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x0399	,0x1f26	,0x1f3e	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x03b9	,0x1f26	,0x1f36	,0x0000	), // GREEK SMALL LETTER IOTA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x03c5	,0x1f26	,0x1f56	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x03a9	,0x1f26	,0x1f6e	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x03c9	,0x1f26	,0x1f66	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	L'A'	,0x1fa6	,0x1f8e	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND PERISPOMENI AND PROSGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	L'a'	,0x1fa6	,0x1f86	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	L'H'	,0x1fa6	,0x1f9e	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND PERISPOMENI AND PROSGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	L'h'	,0x1fa6	,0x1f96	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	L'V'	,0x1fa6	,0x1fae	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PERISPOMENI AND PROSGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	L'v'	,0x1fa6	,0x1fa6	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	L'W'	,0x1fa6	,0x1fae	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PERISPOMENI AND PROSGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	L'w'	,0x1fa6	,0x1fa6	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	0x0391	,0x1fa6	,0x1f8e	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND PERISPOMENI AND PROSGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	0x03b1	,0x1fa6	,0x1f86	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	0x0397	,0x1fa6	,0x1f9e	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND PERISPOMENI AND PROSGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	0x03b7	,0x1fa6	,0x1f96	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	0x03a9	,0x1fa6	,0x1fae	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PERISPOMENI AND PROSGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	0x03c9	,0x1fa6	,0x1fa6	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&VARIA      */	DEADTRANS(	0x00a0	,0x1f12	,0x1fcd	,0x0000	), // GREEK PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'A'	,0x1f12	,0x1f0a	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'a'	,0x1f12	,0x1f02	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'E'	,0x1f12	,0x1f1a	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'e'	,0x1f12	,0x1f12	,0x0000	), // GREEK SMALL LETTER EPSILON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'H'	,0x1f12	,0x1f2a	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'h'	,0x1f12	,0x1f22	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'I'	,0x1f12	,0x1f3a	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'i'	,0x1f12	,0x1f32	,0x0000	), // GREEK SMALL LETTER IOTA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'O'	,0x1f12	,0x1f4a	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'o'	,0x1f12	,0x1f42	,0x0000	), // GREEK SMALL LETTER OMICRON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'V'	,0x1f12	,0x1f6a	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'v'	,0x1f12	,0x1f62	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'W'	,0x1f12	,0x1f6a	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'w'	,0x1f12	,0x1f62	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'y'	,0x1f12	,0x1f52	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x1fc3	,0x1f12	,0x1f82	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&VARIA      */	DEADTRANS(	0x003b	,0x1f12	,0x1f82	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&VARIA      */	DEADTRANS(	0x0391	,0x1f12	,0x1f0a	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x03b1	,0x1f12	,0x1f02	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x0395	,0x1f12	,0x1f1a	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x03b5	,0x1f12	,0x1f12	,0x0000	), // GREEK SMALL LETTER EPSILON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x0397	,0x1f12	,0x1f2a	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x03b7	,0x1f12	,0x1f22	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x0399	,0x1f12	,0x1f3a	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x03b9	,0x1f12	,0x1f32	,0x0000	), // GREEK SMALL LETTER IOTA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x039f	,0x1f12	,0x1f4a	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x03bf	,0x1f12	,0x1f42	,0x0000	), // GREEK SMALL LETTER OMICRON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x03c5	,0x1f12	,0x1f52	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x03a9	,0x1f12	,0x1f6a	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x03c9	,0x1f12	,0x1f62	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND VARIA
/*G_PSILI&VARIA&I    */	DEADTRANS(	L'A'	,0x1f82	,0x1f8a	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND VARIA AND PROSGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	L'a'	,0x1f82	,0x1f82	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	L'H'	,0x1f82	,0x1f9a	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND VARIA AND PROSGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	L'h'	,0x1f82	,0x1f92	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	L'V'	,0x1f82	,0x1faa	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND VARIA AND PROSGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	L'v'	,0x1f82	,0x1fa2	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	L'W'	,0x1f82	,0x1faa	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND VARIA AND PROSGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	L'w'	,0x1f82	,0x1fa2	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	0x0391	,0x1f82	,0x1f8a	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND VARIA AND PROSGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	0x03b1	,0x1f82	,0x1f82	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	0x0397	,0x1f82	,0x1f9a	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND VARIA AND PROSGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	0x03b7	,0x1f82	,0x1f92	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	0x03a9	,0x1f82	,0x1faa	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND VARIA AND PROSGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	0x03c9	,0x1f82	,0x1fa2	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_TONOS            */	DEADTRANS(	0x0020	,0x03cc	,0x0301	,0x0000	), // COMBINING ACUTE ACCENT
/*G_TONOS            */	DEADTRANS(	0x00a0	,0x03cc	,0x0384	,0x0000	), // GREEK TONOS
/*G_TONOS            */	DEADTRANS(	0x202f	,0x03cc	,0x0384	,0x0000	), // GREEK TONOS
/*G_TONOS            */	DEADTRANS(	L'A'	,0x03cc	,0x0386	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'a'	,0x03cc	,0x03ac	,0x0000	), // GREEK SMALL LETTER ALPHA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'E'	,0x03cc	,0x0388	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'e'	,0x03cc	,0x03ad	,0x0000	), // GREEK SMALL LETTER EPSILON WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'H'	,0x03cc	,0x0389	,0x0000	), // GREEK CAPITAL LETTER ETA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'h'	,0x03cc	,0x03ae	,0x0000	), // GREEK SMALL LETTER ETA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'I'	,0x03cc	,0x038a	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'i'	,0x03cc	,0x03af	,0x0000	), // GREEK SMALL LETTER IOTA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'O'	,0x03cc	,0x038c	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'o'	,0x03cc	,0x03cc	,0x0000	), // GREEK SMALL LETTER OMICRON WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'V'	,0x03cc	,0x038f	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'v'	,0x03cc	,0x03ce	,0x0000	), // GREEK SMALL LETTER OMEGA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'W'	,0x03cc	,0x038f	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'w'	,0x03cc	,0x03ce	,0x0000	), // GREEK SMALL LETTER OMEGA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'Y'	,0x03cc	,0x038e	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'y'	,0x03cc	,0x03cd	,0x0000	), // GREEK SMALL LETTER UPSILON WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03ca	,0x03cc	,0x0390	,0x0001	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS
/*G_TONOS            */	DEADTRANS(	0x003a	,0x03cc	,0x0390	,0x0001	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS
/*G_TONOS            */	DEADTRANS(	0x0391	,0x03cc	,0x0386	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03b1	,0x03cc	,0x03ac	,0x0000	), // GREEK SMALL LETTER ALPHA WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x0395	,0x03cc	,0x0388	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03b5	,0x03cc	,0x03ad	,0x0000	), // GREEK SMALL LETTER EPSILON WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x0397	,0x03cc	,0x0389	,0x0000	), // GREEK CAPITAL LETTER ETA WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03b7	,0x03cc	,0x03ae	,0x0000	), // GREEK SMALL LETTER ETA WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x0399	,0x03cc	,0x038a	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03b9	,0x03cc	,0x03af	,0x0000	), // GREEK SMALL LETTER IOTA WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x039f	,0x03cc	,0x038c	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03bf	,0x03cc	,0x03cc	,0x0000	), // GREEK SMALL LETTER OMICRON WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03a5	,0x03cc	,0x038e	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03c5	,0x03cc	,0x03cd	,0x0000	), // GREEK SMALL LETTER UPSILON WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03a9	,0x03cc	,0x038f	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03c9	,0x03cc	,0x03ce	,0x0000	), // GREEK SMALL LETTER OMEGA WITH TONOS
/*G_VARIA            */	DEADTRANS(	0x0020	,0x1f70	,0x0300	,0x0000	), // COMBINING GRAVE ACCENT
/*G_VARIA            */	DEADTRANS(	0x00a0	,0x1f70	,0x1fef	,0x0000	), // GREEK VARIA
/*G_VARIA            */	DEADTRANS(	0x202f	,0x1f70	,0x1fef	,0x0000	), // GREEK VARIA
/*G_VARIA            */	DEADTRANS(	L'A'	,0x1f70	,0x1fba	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'a'	,0x1f70	,0x1f70	,0x0000	), // GREEK SMALL LETTER ALPHA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'E'	,0x1f70	,0x1fc8	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'e'	,0x1f70	,0x1f72	,0x0000	), // GREEK SMALL LETTER EPSILON WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'H'	,0x1f70	,0x1fca	,0x0000	), // GREEK CAPITAL LETTER ETA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'h'	,0x1f70	,0x1f74	,0x0000	), // GREEK SMALL LETTER ETA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'I'	,0x1f70	,0x1fda	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'i'	,0x1f70	,0x1f76	,0x0000	), // GREEK SMALL LETTER IOTA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'O'	,0x1f70	,0x1ff8	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'o'	,0x1f70	,0x1f78	,0x0000	), // GREEK SMALL LETTER OMICRON WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'V'	,0x1f70	,0x1ffa	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'v'	,0x1f70	,0x1f7c	,0x0000	), // GREEK SMALL LETTER OMEGA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'W'	,0x1f70	,0x1ffa	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'w'	,0x1f70	,0x1f7c	,0x0000	), // GREEK SMALL LETTER OMEGA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'Y'	,0x1f70	,0x1fea	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'y'	,0x1f70	,0x1f7a	,0x0000	), // GREEK SMALL LETTER UPSILON WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x1f10	,0x1f70	,0x1f12	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI AND VARIA
/*G_VARIA            */	DEADTRANS(	0x1f51	,0x1f70	,0x1f53	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND VARIA
/*G_VARIA            */	DEADTRANS(	0x003c	,0x1f70	,0x1f53	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND VARIA
/*G_VARIA            */	DEADTRANS(	0x003e	,0x1f70	,0x1f12	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI AND VARIA
/*G_VARIA            */	DEADTRANS(	0x0391	,0x1f70	,0x1fba	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03b1	,0x1f70	,0x1f70	,0x0000	), // GREEK SMALL LETTER ALPHA WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x0395	,0x1f70	,0x1fc8	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03b5	,0x1f70	,0x1f72	,0x0000	), // GREEK SMALL LETTER EPSILON WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x0397	,0x1f70	,0x1fca	,0x0000	), // GREEK CAPITAL LETTER ETA WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03b7	,0x1f70	,0x1f74	,0x0000	), // GREEK SMALL LETTER ETA WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x0399	,0x1f70	,0x1fda	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03b9	,0x1f70	,0x1f76	,0x0000	), // GREEK SMALL LETTER IOTA WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x039f	,0x1f70	,0x1ff8	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03bf	,0x1f70	,0x1f78	,0x0000	), // GREEK SMALL LETTER OMICRON WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03a5	,0x1f70	,0x1fea	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03c5	,0x1f70	,0x1f7a	,0x0000	), // GREEK SMALL LETTER UPSILON WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03a9	,0x1f70	,0x1ffa	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03c9	,0x1f70	,0x1f7c	,0x0000	), // GREEK SMALL LETTER OMEGA WITH VARIA
/*G_VARIA&I          */	DEADTRANS(	L'a'	,0x1fb2	,0x1fb2	,0x0000	), // GREEK SMALL LETTER ALPHA WITH VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	L'h'	,0x1fb2	,0x1fc2	,0x0000	), // GREEK SMALL LETTER ETA WITH VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	L'v'	,0x1fb2	,0x1ff2	,0x0000	), // GREEK SMALL LETTER OMEGA WITH VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	L'w'	,0x1fb2	,0x1ff2	,0x0000	), // GREEK SMALL LETTER OMEGA WITH VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	0x1f10	,0x1fb2	,0x1f82	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	0x1f51	,0x1fb2	,0x1f93	,0x0001	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	0x003c	,0x1fb2	,0x1f93	,0x0001	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	0x003e	,0x1fb2	,0x1f82	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	0x03b1	,0x1fb2	,0x1fb2	,0x0000	), // GREEK SMALL LETTER ALPHA WITH VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	0x03b7	,0x1fb2	,0x1fc2	,0x0000	), // GREEK SMALL LETTER ETA WITH VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	0x03c9	,0x1fb2	,0x1ff2	,0x0000	), // GREEK SMALL LETTER OMEGA WITH VARIA AND YPOGEGRAMMENI
/*G_VRACHY           */	DEADTRANS(	0x0020	,0x1fe0	,0x0306	,0x0000	), // COMBINING BREVE
/*G_VRACHY           */	DEADTRANS(	L'A'	,0x1fe0	,0x1fb8	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	L'a'	,0x1fe0	,0x1fb0	,0x0000	), // GREEK SMALL LETTER ALPHA WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	L'I'	,0x1fe0	,0x1fd8	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	L'i'	,0x1fe0	,0x1fd0	,0x0000	), // GREEK SMALL LETTER IOTA WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	L'Y'	,0x1fe0	,0x1fe8	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	L'y'	,0x1fe0	,0x1fe0	,0x0000	), // GREEK SMALL LETTER UPSILON WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	0x0391	,0x1fe0	,0x1fb8	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	0x03b1	,0x1fe0	,0x1fb0	,0x0000	), // GREEK SMALL LETTER ALPHA WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	0x0399	,0x1fe0	,0x1fd8	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	0x03b9	,0x1fe0	,0x1fd0	,0x0000	), // GREEK SMALL LETTER IOTA WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	0x03a5	,0x1fe0	,0x1fe8	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	0x03c5	,0x1fe0	,0x1fe0	,0x0000	), // GREEK SMALL LETTER UPSILON WITH VRACHY
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x00a0	,0x1fc3	,0x037a	,0x0000	), // GREEK YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x202f	,0x1fc3	,0x1fbe	,0x0000	), // GREEK PROSGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	L'A'	,0x1fc3	,0x1fbc	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PROSGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	L'a'	,0x1fc3	,0x1fb3	,0x0000	), // GREEK SMALL LETTER ALPHA WITH YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	L'H'	,0x1fc3	,0x1fcc	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PROSGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	L'h'	,0x1fc3	,0x1fc3	,0x0000	), // GREEK SMALL LETTER ETA WITH YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	L'V'	,0x1fc3	,0x1ffc	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PROSGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	L'v'	,0x1fc3	,0x1ff3	,0x0000	), // GREEK SMALL LETTER OMEGA WITH YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	L'W'	,0x1fc3	,0x1ffc	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PROSGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	L'w'	,0x1fc3	,0x1ff3	,0x0000	), // GREEK SMALL LETTER OMEGA WITH YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x1f10	,0x1fc3	,0x1f90	,0x0001	), // GREEK SMALL LETTER ETA WITH PSILI AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x1f51	,0x1fc3	,0x1fa1	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x1f70	,0x1fc3	,0x1fb2	,0x0001	), // GREEK SMALL LETTER ALPHA WITH VARIA AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x1f7d	,0x1fc3	,0x1ff4	,0x0001	), // GREEK SMALL LETTER OMEGA WITH OXIA AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x1fc6	,0x1fc3	,0x1fc7	,0x0001	), // GREEK SMALL LETTER ETA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x0020	,0x1fc3	,0x0345	,0x0000	), // COMBINING GREEK YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x002c	,0x1fc3	,0x1ff4	,0x0001	), // GREEK SMALL LETTER OMEGA WITH OXIA AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x003c	,0x1fc3	,0x1fa1	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x003e	,0x1fc3	,0x1f90	,0x0001	), // GREEK SMALL LETTER ETA WITH PSILI AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x0060	,0x1fc3	,0x1fb2	,0x0001	), // GREEK SMALL LETTER ALPHA WITH VARIA AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x007e	,0x1fc3	,0x1fc7	,0x0001	), // GREEK SMALL LETTER ETA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x0391	,0x1fc3	,0x1fbc	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PROSGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x03b1	,0x1fc3	,0x1fb3	,0x0000	), // GREEK SMALL LETTER ALPHA WITH YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x0397	,0x1fc3	,0x1fcc	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PROSGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x03b7	,0x1fc3	,0x1fc3	,0x0000	), // GREEK SMALL LETTER ETA WITH YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x03a9	,0x1fc3	,0x1ffc	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PROSGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x03c9	,0x1fc3	,0x1ff3	,0x0000	), // GREEK SMALL LETTER OMEGA WITH YPOGEGRAMMENI
/*GRAVE_ACCENT       */	DEADTRANS(	0x0020	,0x00f2	,0x0300	,0x0000	), // COMBINING GRAVE ACCENT
/*GRAVE_ACCENT       */	DEADTRANS(	0x00f2	,0x021f	,0x1dc8	,0x0000	), // COMBINING GRAVE-ACUTE-GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x00a0	,0x00f2	,0x0060	,0x0000	), // GRAVE ACCENT
/*GRAVE_ACCENT       */	DEADTRANS(	0x00a3	,0x00f2	,0x02ce	,0x0000	), // MODIFIER LETTER LOW GRAVE ACCENT
/*GRAVE_ACCENT       */	DEADTRANS(	0x202f	,0x00f2	,0x02cb	,0x0000	), // MODIFIER LETTER GRAVE ACCENT
/*GRAVE_ACCENT       */	DEADTRANS(	L'A'	,0x00f2	,0x00c0	,0x0000	), // LATIN CAPITAL LETTER A WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'a'	,0x00f2	,0x00e0	,0x0000	), // LATIN SMALL LETTER A WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'B'	,0x00f2	,0x0181	,0x0000	), // LATIN CAPITAL LETTER B WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'b'	,0x00f2	,0x0253	,0x0000	), // LATIN SMALL LETTER B WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'C'	,0x00f2	,0x0187	,0x0000	), // LATIN CAPITAL LETTER C WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'c'	,0x00f2	,0x0188	,0x0000	), // LATIN SMALL LETTER C WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'D'	,0x00f2	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*GRAVE_ACCENT       */	DEADTRANS(	L'd'	,0x00f2	,0x0254	,0x0000	), // LATIN SMALL LETTER OPEN O
/*GRAVE_ACCENT       */	DEADTRANS(	L'E'	,0x00f2	,0x00c8	,0x0000	), // LATIN CAPITAL LETTER E WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'e'	,0x00f2	,0x00e8	,0x0000	), // LATIN SMALL LETTER E WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'F'	,0x00f2	,0x0191	,0x0000	), // LATIN CAPITAL LETTER F WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'f'	,0x00f2	,0x0192	,0x0000	), // LATIN SMALL LETTER F WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'G'	,0x00f2	,0x0193	,0x0000	), // LATIN CAPITAL LETTER G WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'g'	,0x00f2	,0x0260	,0x0000	), // LATIN SMALL LETTER G WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'H'	,0x00f2	,0xa7aa	,0x0000	), // LATIN CAPITAL LETTER H WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'h'	,0x00f2	,0x0266	,0x0000	), // LATIN SMALL LETTER H WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'I'	,0x00f2	,0x00cc	,0x0000	), // LATIN CAPITAL LETTER I WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'i'	,0x00f2	,0x00ec	,0x0000	), // LATIN SMALL LETTER I WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'J'	,0x00f2	,0x0132	,0x0000	), // LATIN CAPITAL LIGATURE IJ
/*GRAVE_ACCENT       */	DEADTRANS(	L'j'	,0x00f2	,0x0133	,0x0000	), // LATIN SMALL LIGATURE IJ
/*GRAVE_ACCENT       */	DEADTRANS(	L'K'	,0x00f2	,0x0198	,0x0000	), // LATIN CAPITAL LETTER K WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'k'	,0x00f2	,0x0199	,0x0000	), // LATIN SMALL LETTER K WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'L'	,0x00f2	,0x01b3	,0x0000	), // LATIN CAPITAL LETTER Y WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'l'	,0x00f2	,0x01b4	,0x0000	), // LATIN SMALL LETTER Y WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'M'	,0x00f2	,0x2c6e	,0x0000	), // LATIN CAPITAL LETTER M WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'm'	,0x00f2	,0x0271	,0x0000	), // LATIN SMALL LETTER M WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'N'	,0x00f2	,0x01f8	,0x0000	), // LATIN CAPITAL LETTER N WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'n'	,0x00f2	,0x01f9	,0x0000	), // LATIN SMALL LETTER N WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'O'	,0x00f2	,0x00d2	,0x0000	), // LATIN CAPITAL LETTER O WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'o'	,0x00f2	,0x00f2	,0x0000	), // LATIN SMALL LETTER O WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'P'	,0x00f2	,0x01a4	,0x0000	), // LATIN CAPITAL LETTER P WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'p'	,0x00f2	,0x01a5	,0x0000	), // LATIN SMALL LETTER P WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'Q'	,0x00f2	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*GRAVE_ACCENT       */	DEADTRANS(	L'q'	,0x00f2	,0x025b	,0x0000	), // LATIN SMALL LETTER OPEN E
/*GRAVE_ACCENT       */	DEADTRANS(	L'R'	,0x00f2	,0x2c64	,0x0000	), // LATIN CAPITAL LETTER R WITH TAIL
/*GRAVE_ACCENT       */	DEADTRANS(	L'r'	,0x00f2	,0x027d	,0x0000	), // LATIN SMALL LETTER R WITH TAIL
/*GRAVE_ACCENT       */	DEADTRANS(	L'S'	,0x00f2	,0x017f	,0x0000	), // LATIN SMALL LETTER LONG S
/*GRAVE_ACCENT       */	DEADTRANS(	L's'	,0x00f2	,0x017f	,0x0000	), // LATIN SMALL LETTER LONG S
/*GRAVE_ACCENT       */	DEADTRANS(	L'T'	,0x00f2	,0x01ac	,0x0000	), // LATIN CAPITAL LETTER T WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L't'	,0x00f2	,0x01ad	,0x0000	), // LATIN SMALL LETTER T WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'U'	,0x00f2	,0x00d9	,0x0000	), // LATIN CAPITAL LETTER U WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'u'	,0x00f2	,0x00f9	,0x0000	), // LATIN SMALL LETTER U WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'V'	,0x00f2	,0x01b2	,0x0000	), // LATIN CAPITAL LETTER V WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'v'	,0x00f2	,0x028b	,0x0000	), // LATIN SMALL LETTER V WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'W'	,0x00f2	,0x1e80	,0x0000	), // LATIN CAPITAL LETTER W WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'w'	,0x00f2	,0x1e81	,0x0000	), // LATIN SMALL LETTER W WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'X'	,0x00f2	,0x019d	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'x'	,0x00f2	,0x0272	,0x0000	), // LATIN SMALL LETTER N WITH LEFT HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'Y'	,0x00f2	,0x1ef2	,0x0000	), // LATIN CAPITAL LETTER Y WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'y'	,0x00f2	,0x1ef3	,0x0000	), // LATIN SMALL LETTER Y WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'Z'	,0x00f2	,0x0224	,0x0000	), // LATIN CAPITAL LETTER Z WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'z'	,0x00f2	,0x0225	,0x0000	), // LATIN SMALL LETTER Z WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	0x00c0	,0x00f2	,0x00c4	,0x0000	), // LATIN CAPITAL LETTER A WITH DIAERESIS
/*GRAVE_ACCENT       */	DEADTRANS(	0x00e0	,0x00f2	,0x00e4	,0x0000	), // LATIN SMALL LETTER A WITH DIAERESIS
/*GRAVE_ACCENT       */	DEADTRANS(	0x00c6	,0x00f2	,0x00c4	,0x0000	), // LATIN CAPITAL LETTER A WITH DIAERESIS
/*GRAVE_ACCENT       */	DEADTRANS(	0x00e6	,0x00f2	,0x00e4	,0x0000	), // LATIN SMALL LETTER A WITH DIAERESIS
/*GRAVE_ACCENT       */	DEADTRANS(	0x00c7	,0x00f2	,0x1e9e	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*GRAVE_ACCENT       */	DEADTRANS(	0x00e7	,0x00f2	,0x00df	,0x0000	), // LATIN SMALL LETTER SHARP S
/*GRAVE_ACCENT       */	DEADTRANS(	0x00c8	,0x00f2	,0x00d8	,0x0000	), // LATIN CAPITAL LETTER O WITH STROKE
/*GRAVE_ACCENT       */	DEADTRANS(	0x00e8	,0x00f2	,0x00f8	,0x0000	), // LATIN SMALL LETTER O WITH STROKE
/*GRAVE_ACCENT       */	DEADTRANS(	0x00c9	,0x00f2	,0x00c5	,0x0000	), // LATIN CAPITAL LETTER A WITH RING ABOVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x00e9	,0x00f2	,0x00e5	,0x0000	), // LATIN SMALL LETTER A WITH RING ABOVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x0152	,0x00f2	,0x00c6	,0x0000	), // LATIN CAPITAL LETTER AE
/*GRAVE_ACCENT       */	DEADTRANS(	0x0153	,0x00f2	,0x00e6	,0x0000	), // LATIN SMALL LETTER AE
/*GRAVE_ACCENT       */	DEADTRANS(	0x00d9	,0x00f2	,0x00dc	,0x0000	), // LATIN CAPITAL LETTER U WITH DIAERESIS
/*GRAVE_ACCENT       */	DEADTRANS(	0x00f9	,0x00f2	,0x00fc	,0x0000	), // LATIN SMALL LETTER U WITH DIAERESIS
/*GRAVE_ACCENT       */	DEADTRANS(	0x0021	,0x00f2	,0x01c3	,0x0000	), // LATIN LETTER RETROFLEX CLICK
/*GRAVE_ACCENT       */	DEADTRANS(	0x0022	,0x00f2	,0x201f	,0x0000	), // DOUBLE HIGH-REVERSED-9 QUOTATION MARK
/*GRAVE_ACCENT       */	DEADTRANS(	0x0023	,0x00f2	,0x201c	,0x0000	), // LEFT DOUBLE QUOTATION MARK
/*GRAVE_ACCENT       */	DEADTRANS(	0x0025	,0x00f2	,0x2031	,0x0000	), // PER TEN THOUSAND SIGN
/*GRAVE_ACCENT       */	DEADTRANS(	0x0027	,0x00f2	,0x201b	,0x0000	), // SINGLE HIGH-REVERSED-9 QUOTATION MARK
/*GRAVE_ACCENT       */	DEADTRANS(	0x0029	,0x00f2	,0x1eb1	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x002a	,0x00f2	,0x00d7	,0x0000	), // MULTIPLICATION SIGN
/*GRAVE_ACCENT       */	DEADTRANS(	0x002b	,0x00f2	,0x02f4	,0x0000	), // MODIFIER LETTER MIDDLE GRAVE ACCENT
/*GRAVE_ACCENT       */	DEADTRANS(	0x002c	,0x00f2	,0x1edd	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x002d	,0x00f2	,0x2015	,0x0000	), // HORIZONTAL BAR
/*GRAVE_ACCENT       */	DEADTRANS(	0x002e	,0x00f2	,0x00d7	,0x0000	), // MULTIPLICATION SIGN
/*GRAVE_ACCENT       */	DEADTRANS(	0x002f	,0x00f2	,0x00f7	,0x0000	), // DIVISION SIGN
/*GRAVE_ACCENT       */	DEADTRANS(	L'0'	,0x00f2	,0x0298	,0x0000	), // LATIN LETTER BILABIAL CLICK
/*GRAVE_ACCENT       */	DEADTRANS(	L'1'	,0x00f2	,0x2035	,0x0000	), // REVERSED PRIME
/*GRAVE_ACCENT       */	DEADTRANS(	L'2'	,0x00f2	,0x2036	,0x0000	), // REVERSED DOUBLE PRIME
/*GRAVE_ACCENT       */	DEADTRANS(	L'3'	,0x00f2	,0x2037	,0x0000	), // REVERSED TRIPLE PRIME
/*GRAVE_ACCENT       */	DEADTRANS(	L'6'	,0x00f2	,0x01c0	,0x0000	), // LATIN LETTER DENTAL CLICK
/*GRAVE_ACCENT       */	DEADTRANS(	L'7'	,0x00f2	,0x0296	,0x0000	), // LATIN LETTER INVERTED GLOTTAL STOP
/*GRAVE_ACCENT       */	DEADTRANS(	0x003a	,0x00f2	,0x01dc	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x003b	,0x00f2	,0x00d7	,0x0000	), // MULTIPLICATION SIGN
/*GRAVE_ACCENT       */	DEADTRANS(	0x003c	,0x00f2	,0x2264	,0x0000	), // LESS-THAN OR EQUAL TO
/*GRAVE_ACCENT       */	DEADTRANS(	0x003d	,0x00f2	,0x00ad	,0x0000	), // SOFT HYPHEN
/*GRAVE_ACCENT       */	DEADTRANS(	0x003e	,0x00f2	,0x2265	,0x0000	), // GREATER-THAN OR EQUAL TO
/*GRAVE_ACCENT       */	DEADTRANS(	0x003f	,0x00f2	,0x0294	,0x0000	), // LATIN LETTER GLOTTAL STOP
/*GRAVE_ACCENT       */	DEADTRANS(	0x0040	,0x00f2	,0x20dd	,0x0000	), // COMBINING ENCLOSING CIRCLE
/*GRAVE_ACCENT       */	DEADTRANS(	0x005e	,0x00f2	,0x1ed3	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x005f	,0x00f2	,0x1e51	,0x0001	), // LATIN SMALL LETTER O WITH MACRON AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x0060	,0x00f2	,0x020d	,0x0001	), // LATIN SMALL LETTER O WITH DOUBLE GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x007c	,0x00f2	,0x01c1	,0x0000	), // LATIN LETTER LATERAL CLICK
/*GRAVE_ACCENT       */	DEADTRANS(	0x00a9	,0x00f2	,0x01f9	,0x0001	), // LATIN SMALL LETTER N WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x00a7	,0x00f2	,0x203b	,0x0000	), // REFERENCE MARK
/*GRAVE_ACCENT       */	DEADTRANS(	0x00ab	,0x00f2	,0x2039	,0x0000	), // SINGLE LEFT-POINTING ANGLE QUOTATION MARK
/*GRAVE_ACCENT       */	DEADTRANS(	0x00b5	,0x00f2	,0x03c0	,0x0000	), // GREEK SMALL LETTER PI
/*GRAVE_ACCENT       */	DEADTRANS(	0x00bb	,0x00f2	,0x203a	,0x0000	), // SINGLE RIGHT-POINTING ANGLE QUOTATION MARK
/*GRAVE_ACCENT       */	DEADTRANS(	0x00e1	,0x00f2	,0x021f	,0x0001	), // LATIN SMALL LETTER H WITH CARON
/*GRAVE_ACCENT       */	DEADTRANS(	0x00ea	,0x00f2	,0x1ed3	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x00eb	,0x00f2	,0x1ecd	,0x0001	), // LATIN SMALL LETTER O WITH DOT BELOW
/*GRAVE_ACCENT       */	DEADTRANS(	0x00f2	,0x00f2	,0x020d	,0x0001	), // LATIN SMALL LETTER O WITH DOUBLE GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x2019	,0x00f2	,0x2018	,0x0000	), // LEFT SINGLE QUOTATION MARK
/*GRAVE_ACCENT       */	DEADTRANS(	0x2212	,0x00f2	,0x2011	,0x0000	), // NON-BREAKING HYPHEN
/*GRAVE_ACCENT       */	DEADTRANS(	0x2610	,0x00f2	,0x2751	,0x0000	), // LOWER RIGHT SHADOWED WHITE SQUARE
/*GRAVE_ACCENT       */	DEADTRANS(	0x222a	,0x00f2	,0x2228	,0x0000	), // LOGICAL OR
/*GRAVE_ACCENT       */	DEADTRANS(	0x0186	,0x00f2	,0x019f	,0x0000	), // LATIN CAPITAL LETTER O WITH MIDDLE TILDE
/*GRAVE_ACCENT       */	DEADTRANS(	0x0254	,0x00f2	,0x0275	,0x0000	), // LATIN SMALL LETTER BARRED O
/*GRAVE_ACCENT       */	DEADTRANS(	0x0229	,0x00f2	,0x1edd	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x014f	,0x00f2	,0x1eb1	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x014d	,0x00f2	,0x1e51	,0x0001	), // LATIN SMALL LETTER O WITH MACRON AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x01a1	,0x00f2	,0x1edd	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND GRAVE
/*GRAVE_BELOW        */	DEADTRANS(	0x00a0	,0x02ce	,0x02ce	,0x0000	), // MODIFIER LETTER LOW GRAVE ACCENT
/*GREEK              */	DEADTRANS(	L'A'	,0x03b5	,0x0391	,0x0000	), // GREEK CAPITAL LETTER ALPHA
/*GREEK              */	DEADTRANS(	L'a'	,0x03b5	,0x03b1	,0x0000	), // GREEK SMALL LETTER ALPHA
/*GREEK              */	DEADTRANS(	L'B'	,0x03b5	,0x0392	,0x0000	), // GREEK CAPITAL LETTER BETA
/*GREEK              */	DEADTRANS(	L'b'	,0x03b5	,0x03b2	,0x0000	), // GREEK SMALL LETTER BETA
/*GREEK              */	DEADTRANS(	L'C'	,0x03b5	,0x03a8	,0x0000	), // GREEK CAPITAL LETTER PSI
/*GREEK              */	DEADTRANS(	L'c'	,0x03b5	,0x03c8	,0x0000	), // GREEK SMALL LETTER PSI
/*GREEK              */	DEADTRANS(	L'D'	,0x03b5	,0x0394	,0x0000	), // GREEK CAPITAL LETTER DELTA
/*GREEK              */	DEADTRANS(	L'd'	,0x03b5	,0x03b4	,0x0000	), // GREEK SMALL LETTER DELTA
/*GREEK              */	DEADTRANS(	L'E'	,0x03b5	,0x0395	,0x0000	), // GREEK CAPITAL LETTER EPSILON
/*GREEK              */	DEADTRANS(	L'e'	,0x03b5	,0x03b5	,0x0000	), // GREEK SMALL LETTER EPSILON
/*GREEK              */	DEADTRANS(	L'F'	,0x03b5	,0x03a6	,0x0000	), // GREEK CAPITAL LETTER PHI
/*GREEK              */	DEADTRANS(	L'f'	,0x03b5	,0x03c6	,0x0000	), // GREEK SMALL LETTER PHI
/*GREEK              */	DEADTRANS(	L'G'	,0x03b5	,0x0393	,0x0000	), // GREEK CAPITAL LETTER GAMMA
/*GREEK              */	DEADTRANS(	L'g'	,0x03b5	,0x03b3	,0x0000	), // GREEK SMALL LETTER GAMMA
/*GREEK              */	DEADTRANS(	L'H'	,0x03b5	,0x0397	,0x0000	), // GREEK CAPITAL LETTER ETA
/*GREEK              */	DEADTRANS(	L'h'	,0x03b5	,0x03b7	,0x0000	), // GREEK SMALL LETTER ETA
/*GREEK              */	DEADTRANS(	L'I'	,0x03b5	,0x0399	,0x0000	), // GREEK CAPITAL LETTER IOTA
/*GREEK              */	DEADTRANS(	L'i'	,0x03b5	,0x03b9	,0x0000	), // GREEK SMALL LETTER IOTA
/*GREEK              */	DEADTRANS(	L'J'	,0x03b5	,0x039e	,0x0000	), // GREEK CAPITAL LETTER XI
/*GREEK              */	DEADTRANS(	L'j'	,0x03b5	,0x03be	,0x0000	), // GREEK SMALL LETTER XI
/*GREEK              */	DEADTRANS(	L'K'	,0x03b5	,0x039a	,0x0000	), // GREEK CAPITAL LETTER KAPPA
/*GREEK              */	DEADTRANS(	L'k'	,0x03b5	,0x03ba	,0x0000	), // GREEK SMALL LETTER KAPPA
/*GREEK              */	DEADTRANS(	L'L'	,0x03b5	,0x039b	,0x0000	), // GREEK CAPITAL LETTER LAMDA
/*GREEK              */	DEADTRANS(	L'l'	,0x03b5	,0x03bb	,0x0000	), // GREEK SMALL LETTER LAMDA
/*GREEK              */	DEADTRANS(	L'M'	,0x03b5	,0x039c	,0x0000	), // GREEK CAPITAL LETTER MU
/*GREEK              */	DEADTRANS(	L'm'	,0x03b5	,0x03bc	,0x0000	), // GREEK SMALL LETTER MU
/*GREEK              */	DEADTRANS(	L'N'	,0x03b5	,0x039d	,0x0000	), // GREEK CAPITAL LETTER NU
/*GREEK              */	DEADTRANS(	L'n'	,0x03b5	,0x03bd	,0x0000	), // GREEK SMALL LETTER NU
/*GREEK              */	DEADTRANS(	L'O'	,0x03b5	,0x039f	,0x0000	), // GREEK CAPITAL LETTER OMICRON
/*GREEK              */	DEADTRANS(	L'o'	,0x03b5	,0x03bf	,0x0000	), // GREEK SMALL LETTER OMICRON
/*GREEK              */	DEADTRANS(	L'P'	,0x03b5	,0x03a0	,0x0000	), // GREEK CAPITAL LETTER PI
/*GREEK              */	DEADTRANS(	L'p'	,0x03b5	,0x03c0	,0x0000	), // GREEK SMALL LETTER PI
/*GREEK              */	DEADTRANS(	L'Q'	,0x03b5	,0x2211	,0x0000	), // N-ARY SUMMATION
/*GREEK              */	DEADTRANS(	L'q'	,0x03b5	,0x03c2	,0x0000	), // GREEK SMALL LETTER FINAL SIGMA
/*GREEK              */	DEADTRANS(	L'R'	,0x03b5	,0x03a1	,0x0000	), // GREEK CAPITAL LETTER RHO
/*GREEK              */	DEADTRANS(	L'r'	,0x03b5	,0x03c1	,0x0000	), // GREEK SMALL LETTER RHO
/*GREEK              */	DEADTRANS(	L'S'	,0x03b5	,0x03a3	,0x0000	), // GREEK CAPITAL LETTER SIGMA
/*GREEK              */	DEADTRANS(	L's'	,0x03b5	,0x03c3	,0x0000	), // GREEK SMALL LETTER SIGMA
/*GREEK              */	DEADTRANS(	L'T'	,0x03b5	,0x03a4	,0x0000	), // GREEK CAPITAL LETTER TAU
/*GREEK              */	DEADTRANS(	L't'	,0x03b5	,0x03c4	,0x0000	), // GREEK SMALL LETTER TAU
/*GREEK              */	DEADTRANS(	L'U'	,0x03b5	,0x0398	,0x0000	), // GREEK CAPITAL LETTER THETA
/*GREEK              */	DEADTRANS(	L'u'	,0x03b5	,0x03b8	,0x0000	), // GREEK SMALL LETTER THETA
/*GREEK              */	DEADTRANS(	L'V'	,0x03b5	,0x03a9	,0x0000	), // GREEK CAPITAL LETTER OMEGA
/*GREEK              */	DEADTRANS(	L'v'	,0x03b5	,0x03c9	,0x0000	), // GREEK SMALL LETTER OMEGA
/*GREEK              */	DEADTRANS(	L'W'	,0x03b5	,0x03a9	,0x0000	), // GREEK CAPITAL LETTER OMEGA
/*GREEK              */	DEADTRANS(	L'w'	,0x03b5	,0x03c9	,0x0000	), // GREEK SMALL LETTER OMEGA
/*GREEK              */	DEADTRANS(	L'X'	,0x03b5	,0x03a7	,0x0000	), // GREEK CAPITAL LETTER CHI
/*GREEK              */	DEADTRANS(	L'x'	,0x03b5	,0x03c7	,0x0000	), // GREEK SMALL LETTER CHI
/*GREEK              */	DEADTRANS(	L'Y'	,0x03b5	,0x03a5	,0x0000	), // GREEK CAPITAL LETTER UPSILON
/*GREEK              */	DEADTRANS(	L'y'	,0x03b5	,0x03c5	,0x0000	), // GREEK SMALL LETTER UPSILON
/*GREEK              */	DEADTRANS(	L'Z'	,0x03b5	,0x0396	,0x0000	), // GREEK CAPITAL LETTER ZETA
/*GREEK              */	DEADTRANS(	L'z'	,0x03b5	,0x03b6	,0x0000	), // GREEK SMALL LETTER ZETA
/*GREEK              */	DEADTRANS(	0x0029	,0x03b5	,0x1fe0	,0x0001	), // GREEK SMALL LETTER UPSILON WITH VRACHY
/*GREEK              */	DEADTRANS(	0x03b5	,0x03b5	,0x0395	,0x0001	), // GREEK CAPITAL LETTER EPSILON
/*GREEK              */	DEADTRANS(	0x002c	,0x03b5	,0x1f7d	,0x0001	), // GREEK SMALL LETTER OMEGA WITH OXIA
/*GREEK              */	DEADTRANS(	0x003a	,0x03b5	,0x03ca	,0x0001	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA
/*GREEK              */	DEADTRANS(	0x003b	,0x03b5	,0x1fc3	,0x0001	), // GREEK SMALL LETTER ETA WITH YPOGEGRAMMENI
/*GREEK              */	DEADTRANS(	0x003c	,0x03b5	,0x1f51	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA
/*GREEK              */	DEADTRANS(	0x003e	,0x03b5	,0x1f10	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI
/*GREEK              */	DEADTRANS(	0x005f	,0x03b5	,0x1fb1	,0x0001	), // GREEK SMALL LETTER ALPHA WITH MACRON
/*GREEK              */	DEADTRANS(	0x0060	,0x03b5	,0x1f70	,0x0001	), // GREEK SMALL LETTER ALPHA WITH VARIA
/*GREEK              */	DEADTRANS(	0x007e	,0x03b5	,0x1fc6	,0x0001	), // GREEK SMALL LETTER ETA WITH PERISPOMENI
/*GREEK              */	DEADTRANS(	0x00b5	,0x03b5	,0x0448	,0x0001	), // CYRILLIC SMALL LETTER SHA
/*GREEK              */	DEADTRANS(	0x1f70	,0x03b5	,0x1f70	,0x0001	), // GREEK SMALL LETTER ALPHA WITH VARIA
/*GREEK              */	DEADTRANS(	0x1fb1	,0x03b5	,0x1fb1	,0x0001	), // GREEK SMALL LETTER ALPHA WITH MACRON
/*GREEK              */	DEADTRANS(	0x1f10	,0x03b5	,0x1f10	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI
/*GREEK              */	DEADTRANS(	0x1fc6	,0x03b5	,0x1fc6	,0x0001	), // GREEK SMALL LETTER ETA WITH PERISPOMENI
/*GREEK              */	DEADTRANS(	0x1fc3	,0x03b5	,0x1fc3	,0x0001	), // GREEK SMALL LETTER ETA WITH YPOGEGRAMMENI
/*GREEK              */	DEADTRANS(	0x03ca	,0x03b5	,0x03ca	,0x0001	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA
/*GREEK              */	DEADTRANS(	0x03cc	,0x03b5	,0x03cc	,0x0001	), // GREEK SMALL LETTER OMICRON WITH TONOS
/*GREEK              */	DEADTRANS(	0x1fe0	,0x03b5	,0x1fe0	,0x0001	), // GREEK SMALL LETTER UPSILON WITH VRACHY
/*GREEK              */	DEADTRANS(	0x1f51	,0x03b5	,0x1f51	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA
/*GREEK              */	DEADTRANS(	0x1f7d	,0x03b5	,0x1f7d	,0x0001	), // GREEK SMALL LETTER OMEGA WITH OXIA
/*GREEK_LOCK         */	DEADTRANS(	L'A'	,0x0395	,0x0391	,0x0001	), // GREEK CAPITAL LETTER ALPHA
/*GREEK_LOCK         */	DEADTRANS(	L'a'	,0x0395	,0x03b1	,0x0001	), // GREEK SMALL LETTER ALPHA
/*GREEK_LOCK         */	DEADTRANS(	L'B'	,0x0395	,0x0392	,0x0001	), // GREEK CAPITAL LETTER BETA
/*GREEK_LOCK         */	DEADTRANS(	L'b'	,0x0395	,0x03b2	,0x0001	), // GREEK SMALL LETTER BETA
/*GREEK_LOCK         */	DEADTRANS(	L'C'	,0x0395	,0x03a8	,0x0001	), // GREEK CAPITAL LETTER PSI
/*GREEK_LOCK         */	DEADTRANS(	L'c'	,0x0395	,0x03c8	,0x0001	), // GREEK SMALL LETTER PSI
/*GREEK_LOCK         */	DEADTRANS(	L'D'	,0x0395	,0x0394	,0x0001	), // GREEK CAPITAL LETTER DELTA
/*GREEK_LOCK         */	DEADTRANS(	L'd'	,0x0395	,0x03b4	,0x0001	), // GREEK SMALL LETTER DELTA
/*GREEK_LOCK         */	DEADTRANS(	L'E'	,0x0395	,0x0395	,0x0001	), // GREEK CAPITAL LETTER EPSILON
/*GREEK_LOCK         */	DEADTRANS(	L'e'	,0x0395	,0x03b5	,0x0001	), // GREEK SMALL LETTER EPSILON
/*GREEK_LOCK         */	DEADTRANS(	L'F'	,0x0395	,0x03a6	,0x0001	), // GREEK CAPITAL LETTER PHI
/*GREEK_LOCK         */	DEADTRANS(	L'f'	,0x0395	,0x03c6	,0x0001	), // GREEK SMALL LETTER PHI
/*GREEK_LOCK         */	DEADTRANS(	L'G'	,0x0395	,0x0393	,0x0001	), // GREEK CAPITAL LETTER GAMMA
/*GREEK_LOCK         */	DEADTRANS(	L'g'	,0x0395	,0x03b3	,0x0001	), // GREEK SMALL LETTER GAMMA
/*GREEK_LOCK         */	DEADTRANS(	L'H'	,0x0395	,0x0397	,0x0001	), // GREEK CAPITAL LETTER ETA
/*GREEK_LOCK         */	DEADTRANS(	L'h'	,0x0395	,0x03b7	,0x0001	), // GREEK SMALL LETTER ETA
/*GREEK_LOCK         */	DEADTRANS(	L'I'	,0x0395	,0x0399	,0x0001	), // GREEK CAPITAL LETTER IOTA
/*GREEK_LOCK         */	DEADTRANS(	L'i'	,0x0395	,0x03b9	,0x0001	), // GREEK SMALL LETTER IOTA
/*GREEK_LOCK         */	DEADTRANS(	L'J'	,0x0395	,0x039e	,0x0001	), // GREEK CAPITAL LETTER XI
/*GREEK_LOCK         */	DEADTRANS(	L'j'	,0x0395	,0x03be	,0x0001	), // GREEK SMALL LETTER XI
/*GREEK_LOCK         */	DEADTRANS(	L'K'	,0x0395	,0x039a	,0x0001	), // GREEK CAPITAL LETTER KAPPA
/*GREEK_LOCK         */	DEADTRANS(	L'k'	,0x0395	,0x03ba	,0x0001	), // GREEK SMALL LETTER KAPPA
/*GREEK_LOCK         */	DEADTRANS(	L'L'	,0x0395	,0x039b	,0x0001	), // GREEK CAPITAL LETTER LAMDA
/*GREEK_LOCK         */	DEADTRANS(	L'l'	,0x0395	,0x03bb	,0x0001	), // GREEK SMALL LETTER LAMDA
/*GREEK_LOCK         */	DEADTRANS(	L'M'	,0x0395	,0x039c	,0x0001	), // GREEK CAPITAL LETTER MU
/*GREEK_LOCK         */	DEADTRANS(	L'm'	,0x0395	,0x03bc	,0x0001	), // GREEK SMALL LETTER MU
/*GREEK_LOCK         */	DEADTRANS(	L'N'	,0x0395	,0x039d	,0x0001	), // GREEK CAPITAL LETTER NU
/*GREEK_LOCK         */	DEADTRANS(	L'n'	,0x0395	,0x03bd	,0x0001	), // GREEK SMALL LETTER NU
/*GREEK_LOCK         */	DEADTRANS(	L'O'	,0x0395	,0x039f	,0x0001	), // GREEK CAPITAL LETTER OMICRON
/*GREEK_LOCK         */	DEADTRANS(	L'o'	,0x0395	,0x03bf	,0x0001	), // GREEK SMALL LETTER OMICRON
/*GREEK_LOCK         */	DEADTRANS(	L'P'	,0x0395	,0x03a0	,0x0001	), // GREEK CAPITAL LETTER PI
/*GREEK_LOCK         */	DEADTRANS(	L'p'	,0x0395	,0x03c0	,0x0001	), // GREEK SMALL LETTER PI
/*GREEK_LOCK         */	DEADTRANS(	L'Q'	,0x0395	,0x2211	,0x0001	), // N-ARY SUMMATION
/*GREEK_LOCK         */	DEADTRANS(	L'q'	,0x0395	,0x03c2	,0x0001	), // GREEK SMALL LETTER FINAL SIGMA
/*GREEK_LOCK         */	DEADTRANS(	L'R'	,0x0395	,0x03a1	,0x0001	), // GREEK CAPITAL LETTER RHO
/*GREEK_LOCK         */	DEADTRANS(	L'r'	,0x0395	,0x03c1	,0x0001	), // GREEK SMALL LETTER RHO
/*GREEK_LOCK         */	DEADTRANS(	L'S'	,0x0395	,0x03a3	,0x0001	), // GREEK CAPITAL LETTER SIGMA
/*GREEK_LOCK         */	DEADTRANS(	L's'	,0x0395	,0x03c3	,0x0001	), // GREEK SMALL LETTER SIGMA
/*GREEK_LOCK         */	DEADTRANS(	L'T'	,0x0395	,0x03a4	,0x0001	), // GREEK CAPITAL LETTER TAU
/*GREEK_LOCK         */	DEADTRANS(	L't'	,0x0395	,0x03c4	,0x0001	), // GREEK SMALL LETTER TAU
/*GREEK_LOCK         */	DEADTRANS(	L'U'	,0x0395	,0x0398	,0x0001	), // GREEK CAPITAL LETTER THETA
/*GREEK_LOCK         */	DEADTRANS(	L'u'	,0x0395	,0x03b8	,0x0001	), // GREEK SMALL LETTER THETA
/*GREEK_LOCK         */	DEADTRANS(	L'V'	,0x0395	,0x03a9	,0x0001	), // GREEK CAPITAL LETTER OMEGA
/*GREEK_LOCK         */	DEADTRANS(	L'v'	,0x0395	,0x03c9	,0x0001	), // GREEK SMALL LETTER OMEGA
/*GREEK_LOCK         */	DEADTRANS(	L'W'	,0x0395	,0x03a9	,0x0001	), // GREEK CAPITAL LETTER OMEGA
/*GREEK_LOCK         */	DEADTRANS(	L'w'	,0x0395	,0x03c9	,0x0001	), // GREEK SMALL LETTER OMEGA
/*GREEK_LOCK         */	DEADTRANS(	L'X'	,0x0395	,0x03a7	,0x0001	), // GREEK CAPITAL LETTER CHI
/*GREEK_LOCK         */	DEADTRANS(	L'x'	,0x0395	,0x03c7	,0x0001	), // GREEK SMALL LETTER CHI
/*GREEK_LOCK         */	DEADTRANS(	L'Y'	,0x0395	,0x03a5	,0x0001	), // GREEK CAPITAL LETTER UPSILON
/*GREEK_LOCK         */	DEADTRANS(	L'y'	,0x0395	,0x03c5	,0x0001	), // GREEK SMALL LETTER UPSILON
/*GREEK_LOCK         */	DEADTRANS(	L'Z'	,0x0395	,0x0396	,0x0001	), // GREEK CAPITAL LETTER ZETA
/*GREEK_LOCK         */	DEADTRANS(	L'z'	,0x0395	,0x03b6	,0x0001	), // GREEK SMALL LETTER ZETA
/*GREEK_LOCK         */	DEADTRANS(	0x0029	,0x0395	,0x1fe0	,0x0001	), // GREEK SMALL LETTER UPSILON WITH VRACHY
/*GREEK_LOCK         */	DEADTRANS(	0x002c	,0x0395	,0x1f7d	,0x0001	), // GREEK SMALL LETTER OMEGA WITH OXIA
/*GREEK_LOCK         */	DEADTRANS(	0x003a	,0x0395	,0x03ca	,0x0001	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA
/*GREEK_LOCK         */	DEADTRANS(	0x003b	,0x0395	,0x1fc3	,0x0001	), // GREEK SMALL LETTER ETA WITH YPOGEGRAMMENI
/*GREEK_LOCK         */	DEADTRANS(	0x003c	,0x0395	,0x1f51	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA
/*GREEK_LOCK         */	DEADTRANS(	0x003e	,0x0395	,0x1f10	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI
/*GREEK_LOCK         */	DEADTRANS(	0x005f	,0x0395	,0x1fb1	,0x0001	), // GREEK SMALL LETTER ALPHA WITH MACRON
/*GREEK_LOCK         */	DEADTRANS(	0x0060	,0x0395	,0x1f70	,0x0001	), // GREEK SMALL LETTER ALPHA WITH VARIA
/*GREEK_LOCK         */	DEADTRANS(	0x007e	,0x0395	,0x1fc6	,0x0001	), // GREEK SMALL LETTER ETA WITH PERISPOMENI
/*GREEK_LOCK         */	DEADTRANS(	0x00b5	,0x0395	,0x0448	,0x0001	), // CYRILLIC SMALL LETTER SHA
/*GREEK_LOCK         */	DEADTRANS(	0x1f70	,0x0395	,0x1f70	,0x0001	), // GREEK SMALL LETTER ALPHA WITH VARIA
/*GREEK_LOCK         */	DEADTRANS(	0x1fb1	,0x0395	,0x1fb1	,0x0001	), // GREEK SMALL LETTER ALPHA WITH MACRON
/*GREEK_LOCK         */	DEADTRANS(	0x1f10	,0x0395	,0x1f10	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI
/*GREEK_LOCK         */	DEADTRANS(	0x1fc6	,0x0395	,0x1fc6	,0x0001	), // GREEK SMALL LETTER ETA WITH PERISPOMENI
/*GREEK_LOCK         */	DEADTRANS(	0x1fc3	,0x0395	,0x1fc3	,0x0001	), // GREEK SMALL LETTER ETA WITH YPOGEGRAMMENI
/*GREEK_LOCK         */	DEADTRANS(	0x03ca	,0x0395	,0x03ca	,0x0001	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA
/*GREEK_LOCK         */	DEADTRANS(	0x03cc	,0x0395	,0x03cc	,0x0001	), // GREEK SMALL LETTER OMICRON WITH TONOS
/*GREEK_LOCK         */	DEADTRANS(	0x1fe0	,0x0395	,0x1fe0	,0x0001	), // GREEK SMALL LETTER UPSILON WITH VRACHY
/*GREEK_LOCK         */	DEADTRANS(	0x1f51	,0x0395	,0x1f51	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA
/*GREEK_LOCK         */	DEADTRANS(	0x1f7d	,0x0395	,0x1f7d	,0x0001	), // GREEK SMALL LETTER OMEGA WITH OXIA
/*GROUP_02           */	DEADTRANS(	L'A'	,0x2460	,0x00c6	,0x0000	), // LATIN CAPITAL LETTER AE
/*GROUP_02           */	DEADTRANS(	L'a'	,0x2460	,0x00e6	,0x0000	), // LATIN SMALL LETTER AE
/*GROUP_02           */	DEADTRANS(	L'B'	,0x2460	,0xa7b4	,0x0000	), // LATIN CAPITAL LETTER BETA
/*GROUP_02           */	DEADTRANS(	L'b'	,0x2460	,0xa7b5	,0x0000	), // LATIN SMALL LETTER BETA
/*GROUP_02           */	DEADTRANS(	L'C'	,0x2460	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*GROUP_02           */	DEADTRANS(	L'c'	,0x2460	,0x0254	,0x0000	), // LATIN SMALL LETTER OPEN O
/*GROUP_02           */	DEADTRANS(	L'D'	,0x2460	,0x00d0	,0x0000	), // LATIN CAPITAL LETTER ETH
/*GROUP_02           */	DEADTRANS(	L'd'	,0x2460	,0x00f0	,0x0000	), // LATIN SMALL LETTER ETH
/*GROUP_02           */	DEADTRANS(	L'E'	,0x2460	,0x018e	,0x0000	), // LATIN CAPITAL LETTER REVERSED E
/*GROUP_02           */	DEADTRANS(	L'e'	,0x2460	,0x01dd	,0x0000	), // LATIN SMALL LETTER TURNED E
/*GROUP_02           */	DEADTRANS(	L'F'	,0x2460	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*GROUP_02           */	DEADTRANS(	L'f'	,0x2460	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*GROUP_02           */	DEADTRANS(	L'G'	,0x2460	,0x0194	,0x0000	), // LATIN CAPITAL LETTER GAMMA
/*GROUP_02           */	DEADTRANS(	L'g'	,0x2460	,0x0263	,0x0000	), // LATIN SMALL LETTER GAMMA
/*GROUP_02           */	DEADTRANS(	L'H'	,0x2460	,0x0241	,0x0000	), // LATIN CAPITAL LETTER GLOTTAL STOP
/*GROUP_02           */	DEADTRANS(	L'h'	,0x2460	,0x0242	,0x0000	), // LATIN SMALL LETTER GLOTTAL STOP
/*GROUP_02           */	DEADTRANS(	L'I'	,0x2460	,0x0196	,0x0000	), // LATIN CAPITAL LETTER IOTA
/*GROUP_02           */	DEADTRANS(	L'i'	,0x2460	,0x0269	,0x0000	), // LATIN SMALL LETTER IOTA
/*GROUP_02           */	DEADTRANS(	L'J'	,0x2460	,0x0132	,0x0000	), // LATIN CAPITAL LIGATURE IJ
/*GROUP_02           */	DEADTRANS(	L'j'	,0x2460	,0x0133	,0x0000	), // LATIN SMALL LIGATURE IJ
/*GROUP_02           */	DEADTRANS(	L'K'	,0x2460	,0x019d	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*GROUP_02           */	DEADTRANS(	L'k'	,0x2460	,0x0272	,0x0000	), // LATIN SMALL LETTER N WITH LEFT HOOK
/*GROUP_02           */	DEADTRANS(	L'L'	,0x2460	,0x021c	,0x0000	), // LATIN CAPITAL LETTER YOGH
/*GROUP_02           */	DEADTRANS(	L'l'	,0x2460	,0x021d	,0x0000	), // LATIN SMALL LETTER YOGH
/*GROUP_02           */	DEADTRANS(	L'M'	,0x2460	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*GROUP_02           */	DEADTRANS(	L'm'	,0x2460	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*GROUP_02           */	DEADTRANS(	L'N'	,0x2460	,0x014a	,0x0000	), // LATIN CAPITAL LETTER ENG
/*GROUP_02           */	DEADTRANS(	L'n'	,0x2460	,0x014b	,0x0000	), // LATIN SMALL LETTER ENG
/*GROUP_02           */	DEADTRANS(	L'O'	,0x2460	,0x0152	,0x0000	), // LATIN CAPITAL LIGATURE OE
/*GROUP_02           */	DEADTRANS(	L'o'	,0x2460	,0x0153	,0x0000	), // LATIN SMALL LIGATURE OE
/*GROUP_02           */	DEADTRANS(	L'P'	,0x2460	,0x018f	,0x0000	), // LATIN CAPITAL LETTER SCHWA
/*GROUP_02           */	DEADTRANS(	L'p'	,0x2460	,0x0259	,0x0000	), // LATIN SMALL LETTER SCHWA
/*GROUP_02           */	DEADTRANS(	L'Q'	,0x2460	,0x004b	,0x0000	), // LATIN CAPITAL LETTER K
/*GROUP_02           */	DEADTRANS(	L'q'	,0x2460	,0x0138	,0x0000	), // LATIN SMALL LETTER KRA
/*GROUP_02           */	DEADTRANS(	L'R'	,0x2460	,0xa78b	,0x0000	), // LATIN CAPITAL LETTER SALTILLO
/*GROUP_02           */	DEADTRANS(	L'r'	,0x2460	,0xa78c	,0x0000	), // LATIN SMALL LETTER SALTILLO
/*GROUP_02           */	DEADTRANS(	L'S'	,0x2460	,0x1e9e	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*GROUP_02           */	DEADTRANS(	L's'	,0x2460	,0x00df	,0x0000	), // LATIN SMALL LETTER SHARP S
/*GROUP_02           */	DEADTRANS(	L'T'	,0x2460	,0x00de	,0x0000	), // LATIN CAPITAL LETTER THORN
/*GROUP_02           */	DEADTRANS(	L't'	,0x2460	,0x00fe	,0x0000	), // LATIN SMALL LETTER THORN
/*GROUP_02           */	DEADTRANS(	L'U'	,0x2460	,0xa78d	,0x0000	), // LATIN CAPITAL LETTER TURNED H
/*GROUP_02           */	DEADTRANS(	L'u'	,0x2460	,0x0265	,0x0000	), // LATIN SMALL LETTER TURNED H
/*GROUP_02           */	DEADTRANS(	L'V'	,0x2460	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*GROUP_02           */	DEADTRANS(	L'v'	,0x2460	,0x028c	,0x0000	), // LATIN SMALL LETTER TURNED V
/*GROUP_02           */	DEADTRANS(	L'W'	,0x2460	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*GROUP_02           */	DEADTRANS(	L'w'	,0x2460	,0x025b	,0x0000	), // LATIN SMALL LETTER OPEN E
/*GROUP_02           */	DEADTRANS(	L'X'	,0x2460	,0xa7b3	,0x0000	), // LATIN CAPITAL LETTER CHI
/*GROUP_02           */	DEADTRANS(	L'x'	,0x2460	,0xab53	,0x0000	), // LATIN SMALL LETTER CHI
/*GROUP_02           */	DEADTRANS(	L'Y'	,0x2460	,0x01b1	,0x0000	), // LATIN CAPITAL LETTER UPSILON
/*GROUP_02           */	DEADTRANS(	L'y'	,0x2460	,0x028a	,0x0000	), // LATIN SMALL LETTER UPSILON
/*GROUP_02           */	DEADTRANS(	L'Z'	,0x2460	,0x01b7	,0x0000	), // LATIN CAPITAL LETTER EZH
/*GROUP_02           */	DEADTRANS(	L'z'	,0x2460	,0x0292	,0x0000	), // LATIN SMALL LETTER EZH
/*GROUP_02           */	DEADTRANS(	0x00c0	,0x2460	,0x2c6d	,0x0000	), // LATIN CAPITAL LETTER ALPHA
/*GROUP_02           */	DEADTRANS(	0x00e0	,0x2460	,0x0251	,0x0000	), // LATIN SMALL LETTER ALPHA
/*GROUP_02           */	DEADTRANS(	0x00c6	,0x2460	,0xa7ae	,0x0000	), // LATIN CAPITAL LETTER SMALL CAPITAL I
/*GROUP_02           */	DEADTRANS(	0x00e6	,0x2460	,0x026a	,0x0000	), // LATIN LETTER SMALL CAPITAL I
/*GROUP_02           */	DEADTRANS(	0x00c7	,0x2460	,0x01a9	,0x0000	), // LATIN CAPITAL LETTER ESH
/*GROUP_02           */	DEADTRANS(	0x00e7	,0x2460	,0x0283	,0x0000	), // LATIN SMALL LETTER ESH
/*GROUP_02           */	DEADTRANS(	0x00c8	,0x2460	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*GROUP_02           */	DEADTRANS(	0x00e8	,0x2460	,0x025b	,0x0000	), // LATIN SMALL LETTER OPEN E
/*GROUP_02           */	DEADTRANS(	0x00c9	,0x2460	,0xa722	,0x0000	), // LATIN CAPITAL LETTER EGYPTOLOGICAL ALEF
/*GROUP_02           */	DEADTRANS(	0x00e9	,0x2460	,0xa723	,0x0000	), // LATIN SMALL LETTER EGYPTOLOGICAL ALEF
/*GROUP_02           */	DEADTRANS(	0x0152	,0x2460	,0xa7b6	,0x0000	), // LATIN CAPITAL LETTER OMEGA
/*GROUP_02           */	DEADTRANS(	0x0153	,0x2460	,0xa7b7	,0x0000	), // LATIN SMALL LETTER OMEGA
/*GROUP_02           */	DEADTRANS(	0x00d9	,0x2460	,0x0398	,0x0000	), // GREEK CAPITAL LETTER THETA
/*GROUP_02           */	DEADTRANS(	0x00f9	,0x2460	,0x03b8	,0x0000	), // GREEK SMALL LETTER THETA
/*GROUP_02           */	DEADTRANS(	0x0020	,0x2460	,0x2002	,0x0000	), // EN SPACE
/*GROUP_02           */	DEADTRANS(	0x0021	,0x2460	,0x00a1	,0x0000	), // INVERTED EXCLAMATION MARK
/*GROUP_02           */	DEADTRANS(	0x0022	,0x2460	,0x2033	,0x0000	), // DOUBLE PRIME
/*GROUP_02           */	DEADTRANS(	0x0023	,0x2460	,0x00a2	,0x0000	), // CENT SIGN
/*GROUP_02           */	DEADTRANS(	0x0024	,0x2460	,0x017f	,0x0000	), // LATIN SMALL LETTER LONG S
/*GROUP_02           */	DEADTRANS(	0x0025	,0x2460	,0x2030	,0x0000	), // PER MILLE SIGN
/*GROUP_02           */	DEADTRANS(	0x0026	,0x2460	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*GROUP_02           */	DEADTRANS(	0x0027	,0x2460	,0x2032	,0x0000	), // PRIME
/*GROUP_02           */	DEADTRANS(	0x0028	,0x2460	,0x02bf	,0x0000	), // MODIFIER LETTER LEFT HALF RING
/*GROUP_02           */	DEADTRANS(	0x0029	,0x2460	,0x02be	,0x0000	), // MODIFIER LETTER RIGHT HALF RING
/*GROUP_02           */	DEADTRANS(	0x002a	,0x2460	,0x2022	,0x0000	), // BULLET
/*GROUP_02           */	DEADTRANS(	0x002b	,0x2460	,0x00b1	,0x0000	), // PLUS-MINUS SIGN
/*GROUP_02           */	DEADTRANS(	0x002c	,0x2460	,0x02bc	,0x0000	), // MODIFIER LETTER APOSTROPHE
/*GROUP_02           */	DEADTRANS(	0x002d	,0x2460	,0x2043	,0x0000	), // HYPHEN BULLET
/*GROUP_02           */	DEADTRANS(	0x002e	,0x2460	,0x2027	,0x0000	), // HYPHENATION POINT
/*GROUP_02           */	DEADTRANS(	0x002f	,0x2460	,0x2044	,0x0000	), // FRACTION SLASH
/*GROUP_02           */	DEADTRANS(	L'0'	,0x2460	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_02           */	DEADTRANS(	L'1'	,0x2460	,0x00b9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_02           */	DEADTRANS(	L'2'	,0x2460	,0x00bd	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_02           */	DEADTRANS(	L'3'	,0x2460	,0x00b3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_02           */	DEADTRANS(	L'4'	,0x2460	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_02           */	DEADTRANS(	L'5'	,0x2460	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_02           */	DEADTRANS(	L'6'	,0x2460	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_02           */	DEADTRANS(	L'7'	,0x2460	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_02           */	DEADTRANS(	L'8'	,0x2460	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_02           */	DEADTRANS(	L'9'	,0x2460	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_02           */	DEADTRANS(	0x003a	,0x2460	,0x00a6	,0x0000	), // BROKEN BAR
/*GROUP_02           */	DEADTRANS(	0x003b	,0x2460	,0x02bb	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*GROUP_02           */	DEADTRANS(	0x003c	,0x2460	,0x2023	,0x0000	), // TRIANGULAR BULLET
/*GROUP_02           */	DEADTRANS(	0x003d	,0x2460	,0x2243	,0x0000	), // ASYMPTOTICALLY EQUAL TO
/*GROUP_02           */	DEADTRANS(	0x003e	,0x2460	,0x2794	,0x0000	), // HEAVY WIDE-HEADED RIGHTWARDS ARROW
/*GROUP_02           */	DEADTRANS(	0x003f	,0x2460	,0x00bf	,0x0000	), // INVERTED QUESTION MARK
/*GROUP_02           */	DEADTRANS(	0x0040	,0x2460	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*GROUP_02           */	DEADTRANS(	0x005b	,0x2460	,0x00ab	,0x0000	), // LEFT-POINTING DOUBLE ANGLE QUOTATION MARK
/*GROUP_02           */	DEADTRANS(	0x005c	,0x2460	,0x203b	,0x0000	), // REFERENCE MARK
/*GROUP_02           */	DEADTRANS(	0x005d	,0x2460	,0x00bb	,0x0000	), // RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK
/*GROUP_02           */	DEADTRANS(	0x005e	,0x2460	,0x266f	,0x0000	), // MUSIC SHARP SIGN
/*GROUP_02           */	DEADTRANS(	0x005f	,0x2460	,0x203e	,0x0000	), // OVERLINE
/*GROUP_02           */	DEADTRANS(	0x0060	,0x2460	,0x266d	,0x0000	), // MUSIC FLAT SIGN
/*GROUP_02           */	DEADTRANS(	0x007b	,0x2460	,0x2039	,0x0000	), // SINGLE LEFT-POINTING ANGLE QUOTATION MARK
/*GROUP_02           */	DEADTRANS(	0x007c	,0x2460	,0x2016	,0x0000	), // DOUBLE VERTICAL LINE
/*GROUP_02           */	DEADTRANS(	0x007d	,0x2460	,0x203a	,0x0000	), // SINGLE RIGHT-POINTING ANGLE QUOTATION MARK
/*GROUP_02           */	DEADTRANS(	0x007e	,0x2460	,0x2248	,0x0000	), // ALMOST EQUAL TO
/*GROUP_02           */	DEADTRANS(	0x20ac	,0x2460	,0x20bd	,0x0000	), // RUBLE SIGN
/*GROUP_02           */	DEADTRANS(	0x2026	,0x2460	,0x2999	,0x0000	), // DOTTED FENCE
/*GROUP_02           */	DEADTRANS(	0x00a0	,0x2460	,0x2003	,0x0000	), // EM SPACE
/*GROUP_02           */	DEADTRANS(	0x00a7	,0x2460	,0x00a1	,0x0000	), // INVERTED EXCLAMATION MARK
/*GROUP_02           */	DEADTRANS(	0x00b0	,0x2460	,0x25cc	,0x0000	), // DOTTED CIRCLE
/*GROUP_02           */	DEADTRANS(	0x00b2	,0x2460	,0x00b3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_02           */	DEADTRANS(	0x00b7	,0x2460	,0x2022	,0x0000	), // BULLET
/*GROUP_02           */	DEADTRANS(	0x2019	,0x2460	,0x02bc	,0x0000	), // MODIFIER LETTER APOSTROPHE
/*GROUP_02           */	DEADTRANS(	0x222a	,0x2460	,0x2229	,0x0000	), // INTERSECTION
/*GROUP_03           */	DEADTRANS(	L'A'	,0x00b3	,0x2c6d	,0x0000	), // LATIN CAPITAL LETTER ALPHA
/*GROUP_03           */	DEADTRANS(	L'a'	,0x00b3	,0x0251	,0x0000	), // LATIN SMALL LETTER ALPHA
/*GROUP_03           */	DEADTRANS(	L'B'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'b'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'C'	,0x00b3	,0xa722	,0x0000	), // LATIN CAPITAL LETTER EGYPTOLOGICAL ALEF
/*GROUP_03           */	DEADTRANS(	L'c'	,0x00b3	,0xa723	,0x0000	), // LATIN SMALL LETTER EGYPTOLOGICAL ALEF
/*GROUP_03           */	DEADTRANS(	L'D'	,0x00b3	,0x0189	,0x0000	), // LATIN CAPITAL LETTER AFRICAN D
/*GROUP_03           */	DEADTRANS(	L'd'	,0x00b3	,0x0256	,0x0000	), // LATIN SMALL LETTER D WITH TAIL
/*GROUP_03           */	DEADTRANS(	L'E'	,0x00b3	,0x018f	,0x0000	), // LATIN CAPITAL LETTER SCHWA
/*GROUP_03           */	DEADTRANS(	L'e'	,0x00b3	,0x0259	,0x0000	), // LATIN SMALL LETTER SCHWA
/*GROUP_03           */	DEADTRANS(	L'F'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'f'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'G'	,0x00b3	,0x021c	,0x0000	), // LATIN CAPITAL LETTER YOGH
/*GROUP_03           */	DEADTRANS(	L'g'	,0x00b3	,0x021d	,0x0000	), // LATIN SMALL LETTER YOGH
/*GROUP_03           */	DEADTRANS(	L'H'	,0x00b3	,0xa78b	,0x0000	), // LATIN CAPITAL LETTER SALTILLO
/*GROUP_03           */	DEADTRANS(	L'h'	,0x00b3	,0xa78c	,0x0000	), // LATIN SMALL LETTER SALTILLO
/*GROUP_03           */	DEADTRANS(	L'I'	,0x00b3	,0xa7ae	,0x0000	), // LATIN CAPITAL LETTER SMALL CAPITAL I
/*GROUP_03           */	DEADTRANS(	L'i'	,0x00b3	,0x026a	,0x0000	), // LATIN LETTER SMALL CAPITAL I
/*GROUP_03           */	DEADTRANS(	L'J'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'j'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'K'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'k'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'L'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'l'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'M'	,0x00b3	,0xa724	,0x0000	), // LATIN CAPITAL LETTER EGYPTOLOGICAL AIN
/*GROUP_03           */	DEADTRANS(	L'm'	,0x00b3	,0xa725	,0x0000	), // LATIN SMALL LETTER EGYPTOLOGICAL AIN
/*GROUP_03           */	DEADTRANS(	L'N'	,0x00b3	,0x019d	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*GROUP_03           */	DEADTRANS(	L'n'	,0x00b3	,0x0272	,0x0000	), // LATIN SMALL LETTER N WITH LEFT HOOK
/*GROUP_03           */	DEADTRANS(	L'O'	,0x00b3	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*GROUP_03           */	DEADTRANS(	L'o'	,0x00b3	,0x0254	,0x0000	), // LATIN SMALL LETTER OPEN O
/*GROUP_03           */	DEADTRANS(	L'P'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'p'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'Q'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'q'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'R'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'r'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'S'	,0x00b3	,0x01a9	,0x0000	), // LATIN CAPITAL LETTER ESH
/*GROUP_03           */	DEADTRANS(	L's'	,0x00b3	,0x0283	,0x0000	), // LATIN SMALL LETTER ESH
/*GROUP_03           */	DEADTRANS(	L'T'	,0x00b3	,0x0398	,0x0000	), // GREEK CAPITAL LETTER THETA
/*GROUP_03           */	DEADTRANS(	L't'	,0x00b3	,0x03b8	,0x0000	), // GREEK SMALL LETTER THETA
/*GROUP_03           */	DEADTRANS(	L'U'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'u'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'V'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'v'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'W'	,0x00b3	,0x01f7	,0x0000	), // LATIN CAPITAL LETTER WYNN
/*GROUP_03           */	DEADTRANS(	L'w'	,0x00b3	,0x01bf	,0x0000	), // LATIN LETTER WYNN
/*GROUP_03           */	DEADTRANS(	L'X'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'x'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'Y'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'y'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'Z'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'z'	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00c0	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00e0	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00c6	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00e6	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00c7	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00e7	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00c8	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00e8	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00c9	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00e9	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0152	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0153	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00d9	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00f9	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0020	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0021	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0022	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0023	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0024	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0025	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0026	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0027	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0028	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0029	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x002a	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x002b	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x002c	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x002d	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x002e	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x002f	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'0'	,0x00b3	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_03           */	DEADTRANS(	L'1'	,0x00b3	,0x00b9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_03           */	DEADTRANS(	L'2'	,0x00b3	,0x00bd	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_03           */	DEADTRANS(	L'3'	,0x00b3	,0x00b3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_03           */	DEADTRANS(	L'4'	,0x00b3	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_03           */	DEADTRANS(	L'5'	,0x00b3	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_03           */	DEADTRANS(	L'6'	,0x00b3	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_03           */	DEADTRANS(	L'7'	,0x00b3	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_03           */	DEADTRANS(	L'8'	,0x00b3	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_03           */	DEADTRANS(	L'9'	,0x00b3	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_03           */	DEADTRANS(	0x003a	,0x00b3	,0x2999	,0x0000	), // DOTTED FENCE
/*GROUP_03           */	DEADTRANS(	0x003b	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x003c	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x003d	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x003e	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x003f	,0x00b3	,0x0294	,0x0000	), // LATIN LETTER GLOTTAL STOP
/*GROUP_03           */	DEADTRANS(	0x0040	,0x00b3	,0x25cb	,0x0000	), // WHITE CIRCLE
/*GROUP_03           */	DEADTRANS(	0x005b	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x005c	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x005d	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x005e	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x005f	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0060	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0060	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x007b	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x007c	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x007d	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x007e	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x20ac	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x2026	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00a0	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00a7	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00b0	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00b2	,0x00b3	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_03           */	DEADTRANS(	0x00b7	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x2019	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x222a	,0x00b3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_04           */	DEADTRANS(	L'A'	,0x2074	,0xa722	,0x0000	), // LATIN CAPITAL LETTER EGYPTOLOGICAL ALEF
/*GROUP_04           */	DEADTRANS(	L'a'	,0x2074	,0xa723	,0x0000	), // LATIN SMALL LETTER EGYPTOLOGICAL ALEF
/*GROUP_04           */	DEADTRANS(	L'B'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'b'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'C'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'c'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'D'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'd'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'E'	,0x2074	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*GROUP_04           */	DEADTRANS(	L'e'	,0x2074	,0x025b	,0x0000	), // LATIN SMALL LETTER OPEN E
/*GROUP_04           */	DEADTRANS(	L'F'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'f'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'G'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'g'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'H'	,0x2074	,0xa724	,0x0000	), // LATIN CAPITAL LETTER EGYPTOLOGICAL AIN
/*GROUP_04           */	DEADTRANS(	L'h'	,0x2074	,0xa725	,0x0000	), // LATIN SMALL LETTER EGYPTOLOGICAL AIN
/*GROUP_04           */	DEADTRANS(	L'I'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'i'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'J'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'j'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'K'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'k'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'L'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'l'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'M'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'm'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'N'	,0x2074	,0x0220	,0x0000	), // LATIN CAPITAL LETTER N WITH LONG RIGHT LEG
/*GROUP_04           */	DEADTRANS(	L'n'	,0x2074	,0x019e	,0x0000	), // LATIN SMALL LETTER N WITH LONG RIGHT LEG
/*GROUP_04           */	DEADTRANS(	L'O'	,0x2074	,0xa7b6	,0x0000	), // LATIN CAPITAL LETTER OMEGA
/*GROUP_04           */	DEADTRANS(	L'o'	,0x2074	,0xa7b7	,0x0000	), // LATIN SMALL LETTER OMEGA
/*GROUP_04           */	DEADTRANS(	L'P'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'p'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'Q'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'q'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'R'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'r'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'S'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L's'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'T'	,0x2074	,0x03f4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*GROUP_04           */	DEADTRANS(	L't'	,0x2074	,0x03b8	,0x0000	), // GREEK SMALL LETTER THETA
/*GROUP_04           */	DEADTRANS(	L'U'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'u'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'V'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'v'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'W'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'w'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'X'	,0x2074	,0x2714	,0x0000	), // HEAVY CHECK MARK
/*GROUP_04           */	DEADTRANS(	L'x'	,0x2074	,0x2713	,0x0000	), // CHECK MARK
/*GROUP_04           */	DEADTRANS(	L'Y'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'y'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'Z'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'z'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00c0	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00e0	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00c6	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00e6	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00c7	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00e7	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00c8	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00e8	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00c9	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00e9	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0152	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0153	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00d9	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00f9	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0020	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0021	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0022	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0023	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0024	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0025	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0026	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0027	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0028	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0029	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x002a	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x002b	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x002c	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x002d	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x002e	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x002f	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'0'	,0x2074	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_04           */	DEADTRANS(	L'1'	,0x2074	,0x00b9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_04           */	DEADTRANS(	L'2'	,0x2074	,0x00bd	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_04           */	DEADTRANS(	L'3'	,0x2074	,0x00b3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_04           */	DEADTRANS(	L'4'	,0x2074	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_04           */	DEADTRANS(	L'5'	,0x2074	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_04           */	DEADTRANS(	L'6'	,0x2074	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_04           */	DEADTRANS(	L'7'	,0x2074	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_04           */	DEADTRANS(	L'8'	,0x2074	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_04           */	DEADTRANS(	L'9'	,0x2074	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_04           */	DEADTRANS(	0x003a	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x003b	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x003c	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x003d	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x003e	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x003f	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0040	,0x2074	,0x25cc	,0x0000	), // DOTTED CIRCLE
/*GROUP_04           */	DEADTRANS(	0x005b	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x005c	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x005d	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x005e	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x005f	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0060	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0060	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x007b	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x007c	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x007d	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x007e	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x20ac	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x2026	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00a0	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00a7	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00b0	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00b2	,0x2074	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_04           */	DEADTRANS(	0x00b7	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x2019	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x222a	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_05           */	DEADTRANS(	L'A'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'a'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'B'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'b'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'C'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'c'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'D'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'd'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'E'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'e'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'F'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'f'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'G'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'g'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'H'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'h'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'I'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'i'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'J'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'j'	,0x2075	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_05           */	DEADTRANS(	L'K'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'k'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'L'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'l'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'M'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'm'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'N'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'n'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'O'	,0x2075	,0x0222	,0x0000	), // LATIN CAPITAL LETTER OU
/*GROUP_05           */	DEADTRANS(	L'o'	,0x2075	,0x0223	,0x0000	), // LATIN SMALL LETTER OU
/*GROUP_05           */	DEADTRANS(	L'P'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'p'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'Q'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'q'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'R'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'r'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'S'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L's'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'T'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L't'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'U'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'u'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'V'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'v'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'W'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'w'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'X'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'x'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'Y'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'y'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'Z'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'z'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00c0	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00e0	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00c6	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00e6	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00c7	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00e7	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00c8	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00e8	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00c9	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00e9	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0152	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0153	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00d9	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00f9	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0020	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0021	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0022	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0023	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0024	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0025	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0026	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0027	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0028	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0029	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x002a	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x002b	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x002c	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x002d	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x002e	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x002f	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'0'	,0x2075	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_05           */	DEADTRANS(	L'1'	,0x2075	,0x00b9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_05           */	DEADTRANS(	L'2'	,0x2075	,0x00bd	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_05           */	DEADTRANS(	L'3'	,0x2075	,0x00b3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_05           */	DEADTRANS(	L'4'	,0x2075	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_05           */	DEADTRANS(	L'5'	,0x2075	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_05           */	DEADTRANS(	L'6'	,0x2075	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_05           */	DEADTRANS(	L'7'	,0x2075	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_05           */	DEADTRANS(	L'8'	,0x2075	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_05           */	DEADTRANS(	L'9'	,0x2075	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_05           */	DEADTRANS(	0x003a	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x003b	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x003c	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x003d	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x003e	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x003f	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0040	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x005b	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x005c	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x005d	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x005e	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x005f	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0060	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0060	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x007b	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x007c	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x007d	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x007e	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x20ac	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x2026	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00a0	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00a7	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00b0	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00b2	,0x2075	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_05           */	DEADTRANS(	0x00b7	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x2019	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x222a	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_06           */	DEADTRANS(	L'A'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'a'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'B'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'b'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'C'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'c'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'D'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'd'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'E'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'e'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'F'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'f'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'G'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'g'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'H'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'h'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'I'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'i'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'J'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'j'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'K'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'k'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'L'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'l'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'M'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'm'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'N'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'n'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'O'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'o'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'P'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'p'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'Q'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'q'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'R'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'r'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'S'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L's'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'T'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L't'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'U'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'u'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'V'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'v'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'W'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'w'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'X'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'x'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'Y'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'y'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'Z'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'z'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00c0	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00e0	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00c6	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00e6	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00c7	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00e7	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00c8	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00e8	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00c9	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00e9	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0152	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0153	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00d9	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00f9	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0020	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0021	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0022	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0023	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0024	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0025	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0026	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0027	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0028	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0029	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x002a	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x002b	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x002c	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x002d	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x002e	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x002f	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'0'	,0x2076	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_06           */	DEADTRANS(	L'1'	,0x2076	,0x00b9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_06           */	DEADTRANS(	L'2'	,0x2076	,0x00bd	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_06           */	DEADTRANS(	L'3'	,0x2076	,0x00b3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_06           */	DEADTRANS(	L'4'	,0x2076	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_06           */	DEADTRANS(	L'5'	,0x2076	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_06           */	DEADTRANS(	L'6'	,0x2076	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_06           */	DEADTRANS(	L'7'	,0x2076	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_06           */	DEADTRANS(	L'8'	,0x2076	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_06           */	DEADTRANS(	L'9'	,0x2076	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_06           */	DEADTRANS(	0x003a	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x003b	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x003c	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x003d	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x003e	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x003f	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0040	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x005b	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x005c	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x005d	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x005e	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x005f	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0060	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0060	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x007b	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x007c	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x007d	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x007e	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x20ac	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x2026	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00a0	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00a7	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00b0	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00b2	,0x2076	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_06           */	DEADTRANS(	0x00b7	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x2019	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x222a	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_07           */	DEADTRANS(	L'A'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'a'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'B'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'b'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'C'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'c'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'D'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'd'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'E'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'e'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'F'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'f'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'G'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'g'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'H'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'h'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'I'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'i'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'J'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'j'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'K'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'k'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'L'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'l'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'M'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'm'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'N'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'n'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'O'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'o'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'P'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'p'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'Q'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'q'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'R'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'r'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'S'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L's'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'T'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L't'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'U'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'u'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'V'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'v'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'W'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'w'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'X'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'x'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'Y'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'y'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'Z'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'z'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00c0	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00e0	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00c6	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00e6	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00c7	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00e7	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00c8	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00e8	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00c9	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00e9	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0152	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0153	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00d9	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00f9	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0020	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0021	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0022	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0023	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0024	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0025	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0026	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0027	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0028	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0029	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x002a	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x002b	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x002c	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x002d	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x002e	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x002f	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'0'	,0x2077	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_07           */	DEADTRANS(	L'1'	,0x2077	,0x00b9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_07           */	DEADTRANS(	L'2'	,0x2077	,0x00bd	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_07           */	DEADTRANS(	L'3'	,0x2077	,0x00b3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_07           */	DEADTRANS(	L'4'	,0x2077	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_07           */	DEADTRANS(	L'5'	,0x2077	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_07           */	DEADTRANS(	L'6'	,0x2077	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_07           */	DEADTRANS(	L'7'	,0x2077	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_07           */	DEADTRANS(	L'8'	,0x2077	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_07           */	DEADTRANS(	L'9'	,0x2077	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_07           */	DEADTRANS(	0x003a	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x003b	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x003c	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x003d	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x003e	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x003f	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0040	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x005b	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x005c	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x005d	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x005e	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x005f	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0060	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0060	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x007b	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x007c	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x007d	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x007e	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x20ac	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x2026	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00a0	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00a7	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00b0	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00b2	,0x2077	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_07           */	DEADTRANS(	0x00b7	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x2019	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x222a	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_08           */	DEADTRANS(	L'A'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'a'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'B'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'b'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'C'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'c'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'D'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'd'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'E'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'e'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'F'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'f'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'G'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'g'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'H'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'h'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'I'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'i'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'J'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'j'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'K'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'k'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'L'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'l'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'M'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'm'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'N'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'n'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'O'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'o'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'P'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'p'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'Q'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'q'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'R'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'r'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'S'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L's'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'T'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L't'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'U'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'u'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'V'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'v'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'W'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'w'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'X'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'x'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'Y'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'y'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'Z'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'z'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00c0	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00e0	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00c6	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00e6	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00c7	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00e7	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00c8	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00e8	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00c9	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00e9	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0152	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0153	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00d9	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00f9	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0020	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0021	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0022	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0023	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0024	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0025	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0026	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0027	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0028	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0029	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x002a	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x002b	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x002c	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x002d	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x002e	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x002f	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'0'	,0x2078	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_08           */	DEADTRANS(	L'1'	,0x2078	,0x00b9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_08           */	DEADTRANS(	L'2'	,0x2078	,0x00bd	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_08           */	DEADTRANS(	L'3'	,0x2078	,0x00b3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_08           */	DEADTRANS(	L'4'	,0x2078	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_08           */	DEADTRANS(	L'5'	,0x2078	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_08           */	DEADTRANS(	L'6'	,0x2078	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_08           */	DEADTRANS(	L'7'	,0x2078	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_08           */	DEADTRANS(	L'8'	,0x2078	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_08           */	DEADTRANS(	L'9'	,0x2078	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_08           */	DEADTRANS(	0x003a	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x003b	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x003c	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x003d	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x003e	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x003f	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0040	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x005b	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x005c	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x005d	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x005e	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x005f	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0060	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0060	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x007b	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x007c	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x007d	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x007e	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x20ac	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x2026	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00a0	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00a7	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00b0	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00b2	,0x2078	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_08           */	DEADTRANS(	0x00b7	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x2019	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x222a	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_09           */	DEADTRANS(	L'A'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'a'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'B'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'b'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'C'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'c'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'D'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'd'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'E'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'e'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'F'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'f'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'G'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'g'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'H'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'h'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'I'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'i'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'J'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'j'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'K'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'k'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'L'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'l'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'M'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'm'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'N'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'n'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'O'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'o'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'P'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'p'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'Q'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'q'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'R'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'r'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'S'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L's'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'T'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L't'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'U'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'u'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'V'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'v'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'W'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'w'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'X'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'x'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'Y'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'y'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'Z'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'z'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00c0	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00e0	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00c6	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00e6	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00c7	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00e7	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00c8	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00e8	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00c9	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00e9	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0152	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0153	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00d9	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00f9	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0020	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0021	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0022	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0023	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0024	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0025	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0026	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0027	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0028	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0029	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x002a	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x002b	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x002c	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x002d	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x002e	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x002f	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'0'	,0x2079	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_09           */	DEADTRANS(	L'1'	,0x2079	,0x00b9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_09           */	DEADTRANS(	L'2'	,0x2079	,0x00bd	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_09           */	DEADTRANS(	L'3'	,0x2079	,0x00b3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_09           */	DEADTRANS(	L'4'	,0x2079	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_09           */	DEADTRANS(	L'5'	,0x2079	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_09           */	DEADTRANS(	L'6'	,0x2079	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_09           */	DEADTRANS(	L'7'	,0x2079	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_09           */	DEADTRANS(	L'8'	,0x2079	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_09           */	DEADTRANS(	L'9'	,0x2079	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_09           */	DEADTRANS(	0x003a	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x003b	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x003c	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x003d	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x003e	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x003f	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0040	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x005b	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x005c	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x005d	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x005e	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x005f	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0060	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0060	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x007b	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x007c	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x007d	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x007e	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x20ac	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x2026	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00a0	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00a7	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00b0	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00b2	,0x2079	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_09           */	DEADTRANS(	0x00b7	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x2019	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x222a	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_10           */	DEADTRANS(	L'A'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'a'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'B'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'b'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'C'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'c'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'D'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'd'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'E'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'e'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'F'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'f'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'G'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'g'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'H'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'h'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'I'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'i'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'J'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'j'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'K'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'k'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'L'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'l'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'M'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'm'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'N'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'n'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'O'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'o'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'P'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'p'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'Q'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'q'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'R'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'r'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'S'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L's'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'T'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L't'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'U'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'u'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'V'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'v'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'W'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'w'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'X'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'x'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'Y'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'y'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'Z'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'z'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00c0	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00e0	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00c6	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00e6	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00c7	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00e7	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00c8	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00e8	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00c9	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00e9	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0152	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0153	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00d9	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00f9	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0020	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0021	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0022	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0023	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0024	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0025	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0026	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0027	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0028	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0029	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x002a	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x002b	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x002c	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x002d	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x002e	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x002f	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'0'	,0x2070	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_10           */	DEADTRANS(	L'1'	,0x2070	,0x00b9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_10           */	DEADTRANS(	L'2'	,0x2070	,0x00bd	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_10           */	DEADTRANS(	L'3'	,0x2070	,0x00b3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_10           */	DEADTRANS(	L'4'	,0x2070	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_10           */	DEADTRANS(	L'5'	,0x2070	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_10           */	DEADTRANS(	L'6'	,0x2070	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_10           */	DEADTRANS(	L'7'	,0x2070	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_10           */	DEADTRANS(	L'8'	,0x2070	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_10           */	DEADTRANS(	L'9'	,0x2070	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_10           */	DEADTRANS(	0x003a	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x003b	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x003c	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x003d	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x003e	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x003f	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0040	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x005b	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x005c	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x005d	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x005e	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x005f	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0060	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0060	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x007b	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x007c	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x007d	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x007e	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x20ac	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x2026	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00a0	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00a7	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00b0	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00b2	,0x2070	,0x00b9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_10           */	DEADTRANS(	0x00b7	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x2019	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x222a	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_11           */	DEADTRANS(	L'A'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'a'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'B'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'b'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'C'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'c'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'D'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'd'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'E'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'e'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'F'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'f'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'G'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'g'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'H'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'h'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'I'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'i'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'J'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'j'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'K'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'k'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'L'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'l'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'M'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'm'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'N'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'n'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'O'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'o'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'P'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'p'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'Q'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'q'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'R'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'r'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'S'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L's'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'T'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L't'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'U'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'u'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'V'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'v'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'W'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'w'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'X'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'x'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'Y'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'y'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'Z'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'z'	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00c0	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00e0	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00c6	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00e6	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00c7	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00e7	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00c8	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00e8	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00c9	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00e9	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0152	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0153	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00d9	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00f9	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0020	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0021	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0022	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0023	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0024	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0025	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0026	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0027	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0028	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0029	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x002a	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x002b	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x002c	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x002d	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x002e	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x002f	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'0'	,0x00b9	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_11           */	DEADTRANS(	L'1'	,0x00b9	,0x00b9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_11           */	DEADTRANS(	L'2'	,0x00b9	,0x00bd	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_11           */	DEADTRANS(	L'3'	,0x00b9	,0x00b3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_11           */	DEADTRANS(	L'4'	,0x00b9	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_11           */	DEADTRANS(	L'5'	,0x00b9	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_11           */	DEADTRANS(	L'6'	,0x00b9	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_11           */	DEADTRANS(	L'7'	,0x00b9	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_11           */	DEADTRANS(	L'8'	,0x00b9	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_11           */	DEADTRANS(	L'9'	,0x00b9	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_11           */	DEADTRANS(	0x003a	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x003b	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x003c	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x003d	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x003e	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x003f	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0040	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x005b	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x005c	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x005d	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x005e	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x005f	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0060	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0060	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x007b	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x007c	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x007d	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x007e	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x20ac	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x2026	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00a0	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00a7	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00b0	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00b2	,0x00b9	,0x00b2	,0x0001	), // SUPERSCRIPT TWO
/*GROUP_11           */	DEADTRANS(	0x00b7	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x2019	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x222a	,0x00b9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_12           */	DEADTRANS(	L'A'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'a'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'B'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'b'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'C'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'c'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'D'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'd'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'E'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'e'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'F'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'f'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'G'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'g'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'H'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'h'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'I'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'i'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'J'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'j'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'K'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'k'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'L'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'l'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'M'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'm'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'N'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'n'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'O'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'o'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'P'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'p'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'Q'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'q'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'R'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'r'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'S'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L's'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'T'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L't'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'U'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'u'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'V'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'v'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'W'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'w'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'X'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'x'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'Y'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'y'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'Z'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'z'	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00c0	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00e0	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00c6	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00e6	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00c7	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00e7	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00c8	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00e8	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00c9	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00e9	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0152	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0153	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00d9	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00f9	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0020	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0021	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0022	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0023	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0024	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0025	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0026	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0027	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0028	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0029	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x002a	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x002b	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x002c	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x002d	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x002e	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x002f	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'0'	,0x00bd	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_12           */	DEADTRANS(	L'1'	,0x00bd	,0x00b9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_12           */	DEADTRANS(	L'2'	,0x00bd	,0x00bd	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'3'	,0x00bd	,0x00b3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_12           */	DEADTRANS(	L'4'	,0x00bd	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_12           */	DEADTRANS(	L'5'	,0x00bd	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_12           */	DEADTRANS(	L'6'	,0x00bd	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_12           */	DEADTRANS(	L'7'	,0x00bd	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_12           */	DEADTRANS(	L'8'	,0x00bd	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_12           */	DEADTRANS(	L'9'	,0x00bd	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_12           */	DEADTRANS(	0x003a	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x003b	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x003c	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x003d	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x003e	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x003f	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0040	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x005b	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x005c	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x005d	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x005e	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x005f	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0060	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0060	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x007b	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x007c	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x007d	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x007e	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x20ac	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x2026	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00a0	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00a7	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00b0	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00b2	,0x00bd	,0x00bd	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00b7	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x2019	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x222a	,0x00bd	,0x00bd	,0x0000	), // VULGAR FRACTION ONE HALF
/*HACEK              */	DEADTRANS(	0x0020	,0x021f	,0x030c	,0x0000	), // COMBINING CARON
/*HACEK              */	DEADTRANS(	0x00a3	,0x021f	,0x032c	,0x0000	), // COMBINING CARON BELOW
/*HACEK              */	DEADTRANS(	0x00a0	,0x021f	,0x02c7	,0x0000	), // CARON
/*HACEK              */	DEADTRANS(	0x202f	,0x021f	,0x02c7	,0x0000	), // CARON
/*HACEK              */	DEADTRANS(	0x00e1	,0x021f	,0x1dc9	,0x0000	), // COMBINING ACUTE-GRAVE-ACUTE
/*HACEK              */	DEADTRANS(	L'A'	,0x021f	,0x01cd	,0x0000	), // LATIN CAPITAL LETTER A WITH CARON
/*HACEK              */	DEADTRANS(	L'a'	,0x021f	,0x01ce	,0x0000	), // LATIN SMALL LETTER A WITH CARON
/*HACEK              */	DEADTRANS(	L'C'	,0x021f	,0x010c	,0x0000	), // LATIN CAPITAL LETTER C WITH CARON
/*HACEK              */	DEADTRANS(	L'c'	,0x021f	,0x010d	,0x0000	), // LATIN SMALL LETTER C WITH CARON
/*HACEK              */	DEADTRANS(	L'D'	,0x021f	,0x010e	,0x0000	), // LATIN CAPITAL LETTER D WITH CARON
/*HACEK              */	DEADTRANS(	L'd'	,0x021f	,0x010f	,0x0000	), // LATIN SMALL LETTER D WITH CARON
/*HACEK              */	DEADTRANS(	L'E'	,0x021f	,0x011a	,0x0000	), // LATIN CAPITAL LETTER E WITH CARON
/*HACEK              */	DEADTRANS(	L'e'	,0x021f	,0x011b	,0x0000	), // LATIN SMALL LETTER E WITH CARON
/*HACEK              */	DEADTRANS(	L'F'	,0x021f	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*HACEK              */	DEADTRANS(	L'f'	,0x021f	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*HACEK              */	DEADTRANS(	L'G'	,0x021f	,0x01e6	,0x0000	), // LATIN CAPITAL LETTER G WITH CARON
/*HACEK              */	DEADTRANS(	L'g'	,0x021f	,0x01e7	,0x0000	), // LATIN SMALL LETTER G WITH CARON
/*HACEK              */	DEADTRANS(	L'H'	,0x021f	,0x021e	,0x0000	), // LATIN CAPITAL LETTER H WITH CARON
/*HACEK              */	DEADTRANS(	L'h'	,0x021f	,0x021f	,0x0000	), // LATIN SMALL LETTER H WITH CARON
/*HACEK              */	DEADTRANS(	L'I'	,0x021f	,0x01cf	,0x0000	), // LATIN CAPITAL LETTER I WITH CARON
/*HACEK              */	DEADTRANS(	L'i'	,0x021f	,0x01d0	,0x0000	), // LATIN SMALL LETTER I WITH CARON
/*HACEK              */	DEADTRANS(	L'j'	,0x021f	,0x01f0	,0x0000	), // LATIN SMALL LETTER J WITH CARON
/*HACEK              */	DEADTRANS(	L'K'	,0x021f	,0x01e8	,0x0000	), // LATIN CAPITAL LETTER K WITH CARON
/*HACEK              */	DEADTRANS(	L'k'	,0x021f	,0x01e9	,0x0000	), // LATIN SMALL LETTER K WITH CARON
/*HACEK              */	DEADTRANS(	L'L'	,0x021f	,0x013d	,0x0000	), // LATIN CAPITAL LETTER L WITH CARON
/*HACEK              */	DEADTRANS(	L'l'	,0x021f	,0x013e	,0x0000	), // LATIN SMALL LETTER L WITH CARON
/*HACEK              */	DEADTRANS(	L'M'	,0x021f	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*HACEK              */	DEADTRANS(	L'm'	,0x021f	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*HACEK              */	DEADTRANS(	L'N'	,0x021f	,0x0147	,0x0000	), // LATIN CAPITAL LETTER N WITH CARON
/*HACEK              */	DEADTRANS(	L'n'	,0x021f	,0x0148	,0x0000	), // LATIN SMALL LETTER N WITH CARON
/*HACEK              */	DEADTRANS(	L'O'	,0x021f	,0x01d1	,0x0000	), // LATIN CAPITAL LETTER O WITH CARON
/*HACEK              */	DEADTRANS(	L'o'	,0x021f	,0x01d2	,0x0000	), // LATIN SMALL LETTER O WITH CARON
/*HACEK              */	DEADTRANS(	L'R'	,0x021f	,0x0158	,0x0000	), // LATIN CAPITAL LETTER R WITH CARON
/*HACEK              */	DEADTRANS(	L'r'	,0x021f	,0x0159	,0x0000	), // LATIN SMALL LETTER R WITH CARON
/*HACEK              */	DEADTRANS(	L'S'	,0x021f	,0x0160	,0x0000	), // LATIN CAPITAL LETTER S WITH CARON
/*HACEK              */	DEADTRANS(	L's'	,0x021f	,0x0161	,0x0000	), // LATIN SMALL LETTER S WITH CARON
/*HACEK              */	DEADTRANS(	L'T'	,0x021f	,0x0164	,0x0000	), // LATIN CAPITAL LETTER T WITH CARON
/*HACEK              */	DEADTRANS(	L't'	,0x021f	,0x0165	,0x0000	), // LATIN SMALL LETTER T WITH CARON
/*HACEK              */	DEADTRANS(	L'U'	,0x021f	,0x01d3	,0x0000	), // LATIN CAPITAL LETTER U WITH CARON
/*HACEK              */	DEADTRANS(	L'u'	,0x021f	,0x01d4	,0x0000	), // LATIN SMALL LETTER U WITH CARON
/*HACEK              */	DEADTRANS(	L'Z'	,0x021f	,0x017d	,0x0000	), // LATIN CAPITAL LETTER Z WITH CARON
/*HACEK              */	DEADTRANS(	L'z'	,0x021f	,0x017e	,0x0000	), // LATIN SMALL LETTER Z WITH CARON
/*HACEK              */	DEADTRANS(	0x00c9	,0x021f	,0x2082	,0x0000	), // SUBSCRIPT TWO
/*HACEK              */	DEADTRANS(	0x00e9	,0x021f	,0x2082	,0x0000	), // SUBSCRIPT TWO
/*HACEK              */	DEADTRANS(	0x0152	,0x021f	,0x2082	,0x0000	), // SUBSCRIPT TWO
/*HACEK              */	DEADTRANS(	0x0153	,0x021f	,0x2082	,0x0000	), // SUBSCRIPT TWO
/*HACEK              */	DEADTRANS(	0x00f9	,0x021f	,0x02bb	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*HACEK              */	DEADTRANS(	0x0023	,0x021f	,0x2083	,0x0000	), // SUBSCRIPT THREE
/*HACEK              */	DEADTRANS(	0x0025	,0x021f	,0x2031	,0x0001	), // PER TEN THOUSAND SIGN
/*HACEK              */	DEADTRANS(	0x0027	,0x021f	,0x02bb	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*HACEK              */	DEADTRANS(	0x002e	,0x021f	,0x1e67	,0x0001	), // LATIN SMALL LETTER S WITH CARON AND DOT ABOVE
/*HACEK              */	DEADTRANS(	L'0'	,0x021f	,0x2080	,0x0000	), // SUBSCRIPT ZERO
/*HACEK              */	DEADTRANS(	L'1'	,0x021f	,0x2081	,0x0000	), // SUBSCRIPT ONE
/*HACEK              */	DEADTRANS(	L'2'	,0x021f	,0x2082	,0x0000	), // SUBSCRIPT TWO
/*HACEK              */	DEADTRANS(	L'3'	,0x021f	,0x2083	,0x0000	), // SUBSCRIPT THREE
/*HACEK              */	DEADTRANS(	L'4'	,0x021f	,0x2084	,0x0000	), // SUBSCRIPT FOUR
/*HACEK              */	DEADTRANS(	L'5'	,0x021f	,0x2085	,0x0000	), // SUBSCRIPT FIVE
/*HACEK              */	DEADTRANS(	L'6'	,0x021f	,0x2086	,0x0000	), // SUBSCRIPT SIX
/*HACEK              */	DEADTRANS(	L'7'	,0x021f	,0x2087	,0x0000	), // SUBSCRIPT SEVEN
/*HACEK              */	DEADTRANS(	L'8'	,0x021f	,0x2088	,0x0000	), // SUBSCRIPT EIGHT
/*HACEK              */	DEADTRANS(	L'9'	,0x021f	,0x2089	,0x0000	), // SUBSCRIPT NINE
/*HACEK              */	DEADTRANS(	0x003c	,0x021f	,0x2277	,0x0000	), // GREATER-THAN OR LESS-THAN
/*HACEK              */	DEADTRANS(	0x003d	,0x021f	,0x2267	,0x0000	), // GREATER-THAN OVER EQUAL TO
/*HACEK              */	DEADTRANS(	0x003e	,0x021f	,0x2a7e	,0x0000	), // GREATER-THAN OR SLANTED EQUAL TO
/*HACEK              */	DEADTRANS(	0x0040	,0x021f	,0x25b2	,0x0000	), // BLACK UP-POINTING TRIANGLE
/*HACEK              */	DEADTRANS(	0x005f	,0x021f	,0x2265	,0x0000	), // GREATER-THAN OR EQUAL TO
/*HACEK              */	DEADTRANS(	0x007c	,0x021f	,0x2021	,0x0000	), // DOUBLE DAGGER
/*HACEK              */	DEADTRANS(	0x00a9	,0x021f	,0x010d	,0x0001	), // LATIN SMALL LETTER C WITH CARON
/*HACEK              */	DEADTRANS(	L'D'	,0x010d	,0x01c5	,0x0001	), // LATIN CAPITAL LETTER D WITH SMALL LETTER Z WITH CARON
/*HACEK              */	DEADTRANS(	L'Z'	,0x01c5	,0x01c4	,0x0000	), // LATIN CAPITAL LETTER DZ WITH CARON
/*HACEK              */	DEADTRANS(	L'z'	,0x01c5	,0x01c5	,0x0000	), // LATIN CAPITAL LETTER D WITH SMALL LETTER Z WITH CARON
/*HACEK              */	DEADTRANS(	L'd'	,0x010d	,0x01c6	,0x0000	), // LATIN SMALL LETTER DZ WITH CARON
/*HACEK              */	DEADTRANS(	L'Z'	,0x010d	,0x01ee	,0x0000	), // LATIN CAPITAL LETTER EZH WITH CARON
/*HACEK              */	DEADTRANS(	L'z'	,0x010d	,0x01ef	,0x0000	), // LATIN SMALL LETTER EZH WITH CARON
/*HACEK              */	DEADTRANS(	0x00ea	,0x021f	,0x1e19	,0x0001	), // LATIN SMALL LETTER E WITH CIRCUMFLEX BELOW
/*HACEK              */	DEADTRANS(	0x00eb	,0x021f	,0x01da	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND CARON
/*HACEK              */	DEADTRANS(	0x00c8	,0x01da	,0x01d9	,0x0000	), // LATIN CAPITAL LETTER U WITH DIAERESIS AND CARON
/*HACEK              */	DEADTRANS(	0x00e8	,0x01da	,0x01da	,0x0000	), // LATIN SMALL LETTER U WITH DIAERESIS AND CARON
/*HACEK              */	DEADTRANS(	0x2019	,0x021f	,0x02bb	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*HACEK              */	DEADTRANS(	0x2610	,0x021f	,0x2611	,0x0000	), // BALLOT BOX WITH CHECK
/*HACEK              */	DEADTRANS(	0x022f	,0x021f	,0x1e67	,0x0001	), // LATIN SMALL LETTER S WITH CARON AND DOT ABOVE
/*HACEK&DOT_ABOVE    */	DEADTRANS(	L'S'	,0x1e67	,0x1e66	,0x0000	), // LATIN CAPITAL LETTER S WITH CARON AND DOT ABOVE
/*HACEK&DOT_ABOVE    */	DEADTRANS(	L's'	,0x1e67	,0x1e67	,0x0000	), // LATIN SMALL LETTER S WITH CARON AND DOT ABOVE
/*HEBREW             */	DEADTRANS(	L'a'	,0x05d0	,0x05d0	,0x0000	), // HEBREW LETTER ALEF
/*HEBREW             */	DEADTRANS(	0x05d0	,0x05d0	,0x05d1	,0x0001	), // HEBREW LETTER BET
/*HEBREW             */	DEADTRANS(	L'b'	,0x05d0	,0x05d1	,0x0000	), // HEBREW LETTER BET
/*HEBREW             */	DEADTRANS(	L'd'	,0x05d0	,0x05d3	,0x0000	), // HEBREW LETTER DALET
/*HEBREW             */	DEADTRANS(	L'g'	,0x05d0	,0x05d2	,0x0000	), // HEBREW LETTER GIMEL
/*HEBREW             */	DEADTRANS(	L'h'	,0x05d0	,0x05d4	,0x0000	), // HEBREW LETTER HE
/*HEBREW             */	DEADTRANS(	L'i'	,0x05d0	,0x05d5	,0x0000	), // HEBREW LETTER VAV
/*HEBREW             */	DEADTRANS(	L'j'	,0x05d0	,0x05d9	,0x0000	), // HEBREW LETTER YOD
/*HEBREW             */	DEADTRANS(	L'K'	,0x05d0	,0x05da	,0x0000	), // HEBREW LETTER FINAL KAF
/*HEBREW             */	DEADTRANS(	L'k'	,0x05d0	,0x05db	,0x0000	), // HEBREW LETTER KAF
/*HEBREW             */	DEADTRANS(	L'l'	,0x05d0	,0x05dc	,0x0000	), // HEBREW LETTER LAMED
/*HEBREW             */	DEADTRANS(	L'M'	,0x05d0	,0x05dd	,0x0000	), // HEBREW LETTER FINAL MEM
/*HEBREW             */	DEADTRANS(	L'm'	,0x05d0	,0x05de	,0x0000	), // HEBREW LETTER MEM
/*HEBREW             */	DEADTRANS(	L'N'	,0x05d0	,0x05df	,0x0000	), // HEBREW LETTER FINAL NUN
/*HEBREW             */	DEADTRANS(	L'n'	,0x05d0	,0x05e0	,0x0000	), // HEBREW LETTER NUN
/*HEBREW             */	DEADTRANS(	L'P'	,0x05d0	,0x05e3	,0x0000	), // HEBREW LETTER FINAL PE
/*HEBREW             */	DEADTRANS(	L'p'	,0x05d0	,0x05e4	,0x0000	), // HEBREW LETTER PE
/*HEBREW             */	DEADTRANS(	L'q'	,0x05d0	,0x05e7	,0x0000	), // HEBREW LETTER QOF
/*HEBREW             */	DEADTRANS(	L'r'	,0x05d0	,0x05e8	,0x0000	), // HEBREW LETTER RESH
/*HEBREW             */	DEADTRANS(	L's'	,0x05d0	,0x05e1	,0x0000	), // HEBREW LETTER SAMEKH
/*HEBREW             */	DEADTRANS(	L't'	,0x05d0	,0x05ea	,0x0000	), // HEBREW LETTER TAV
/*HEBREW             */	DEADTRANS(	L'u'	,0x05d0	,0x05d8	,0x0000	), // HEBREW LETTER TET
/*HEBREW             */	DEADTRANS(	L'v'	,0x05d0	,0x05e2	,0x0000	), // HEBREW LETTER AYIN
/*HEBREW             */	DEADTRANS(	L'w'	,0x05d0	,0x05e9	,0x0000	), // HEBREW LETTER SHIN
/*HEBREW             */	DEADTRANS(	L'x'	,0x05d0	,0x05d7	,0x0000	), // HEBREW LETTER HET
/*HEBREW             */	DEADTRANS(	L'Y'	,0x05d0	,0x05e5	,0x0000	), // HEBREW LETTER FINAL TSADI
/*HEBREW             */	DEADTRANS(	L'y'	,0x05d0	,0x05e6	,0x0000	), // HEBREW LETTER TSADI
/*HEBREW             */	DEADTRANS(	L'z'	,0x05d0	,0x05d6	,0x0000	), // HEBREW LETTER ZAYIN
/*HEBREW_LOCK        */	DEADTRANS(	L'a'	,0x05d1	,0x05d0	,0x0001	), // HEBREW LETTER ALEF
/*HEBREW_LOCK        */	DEADTRANS(	L'b'	,0x05d1	,0x05d1	,0x0001	), // HEBREW LETTER BET
/*HEBREW_LOCK        */	DEADTRANS(	L'd'	,0x05d1	,0x05d3	,0x0001	), // HEBREW LETTER DALET
/*HEBREW_LOCK        */	DEADTRANS(	L'g'	,0x05d1	,0x05d2	,0x0001	), // HEBREW LETTER GIMEL
/*HEBREW_LOCK        */	DEADTRANS(	L'h'	,0x05d1	,0x05d4	,0x0001	), // HEBREW LETTER HE
/*HEBREW_LOCK        */	DEADTRANS(	L'i'	,0x05d1	,0x05d5	,0x0001	), // HEBREW LETTER VAV
/*HEBREW_LOCK        */	DEADTRANS(	L'j'	,0x05d1	,0x05d9	,0x0001	), // HEBREW LETTER YOD
/*HEBREW_LOCK        */	DEADTRANS(	L'K'	,0x05d1	,0x05da	,0x0001	), // HEBREW LETTER FINAL KAF
/*HEBREW_LOCK        */	DEADTRANS(	L'k'	,0x05d1	,0x05db	,0x0001	), // HEBREW LETTER KAF
/*HEBREW_LOCK        */	DEADTRANS(	L'l'	,0x05d1	,0x05dc	,0x0001	), // HEBREW LETTER LAMED
/*HEBREW_LOCK        */	DEADTRANS(	L'M'	,0x05d1	,0x05dd	,0x0001	), // HEBREW LETTER FINAL MEM
/*HEBREW_LOCK        */	DEADTRANS(	L'm'	,0x05d1	,0x05de	,0x0001	), // HEBREW LETTER MEM
/*HEBREW_LOCK        */	DEADTRANS(	L'N'	,0x05d1	,0x05df	,0x0001	), // HEBREW LETTER FINAL NUN
/*HEBREW_LOCK        */	DEADTRANS(	L'n'	,0x05d1	,0x05e0	,0x0001	), // HEBREW LETTER NUN
/*HEBREW_LOCK        */	DEADTRANS(	L'P'	,0x05d1	,0x05e3	,0x0001	), // HEBREW LETTER FINAL PE
/*HEBREW_LOCK        */	DEADTRANS(	L'p'	,0x05d1	,0x05e4	,0x0001	), // HEBREW LETTER PE
/*HEBREW_LOCK        */	DEADTRANS(	L'q'	,0x05d1	,0x05e7	,0x0001	), // HEBREW LETTER QOF
/*HEBREW_LOCK        */	DEADTRANS(	L'r'	,0x05d1	,0x05e8	,0x0001	), // HEBREW LETTER RESH
/*HEBREW_LOCK        */	DEADTRANS(	L's'	,0x05d1	,0x05e1	,0x0001	), // HEBREW LETTER SAMEKH
/*HEBREW_LOCK        */	DEADTRANS(	L't'	,0x05d1	,0x05ea	,0x0001	), // HEBREW LETTER TAV
/*HEBREW_LOCK        */	DEADTRANS(	L'u'	,0x05d1	,0x05d8	,0x0001	), // HEBREW LETTER TET
/*HEBREW_LOCK        */	DEADTRANS(	L'v'	,0x05d1	,0x05e2	,0x0001	), // HEBREW LETTER AYIN
/*HEBREW_LOCK        */	DEADTRANS(	L'w'	,0x05d1	,0x05e9	,0x0001	), // HEBREW LETTER SHIN
/*HEBREW_LOCK        */	DEADTRANS(	L'x'	,0x05d1	,0x05d7	,0x0001	), // HEBREW LETTER HET
/*HEBREW_LOCK        */	DEADTRANS(	L'Y'	,0x05d1	,0x05e5	,0x0001	), // HEBREW LETTER FINAL TSADI
/*HEBREW_LOCK        */	DEADTRANS(	L'y'	,0x05d1	,0x05e6	,0x0001	), // HEBREW LETTER TSADI
/*HEBREW_LOCK        */	DEADTRANS(	L'z'	,0x05d1	,0x05d6	,0x0001	), // HEBREW LETTER ZAYIN
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'B'	,0x0183	,0x0182	,0x0000	), // LATIN CAPITAL LETTER B WITH TOPBAR
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'b'	,0x0183	,0x0183	,0x0000	), // LATIN SMALL LETTER B WITH TOPBAR
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'D'	,0x0183	,0x018b	,0x0000	), // LATIN CAPITAL LETTER D WITH TOPBAR
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'd'	,0x0183	,0x018c	,0x0000	), // LATIN SMALL LETTER D WITH TOPBAR
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'H'	,0x0183	,0xa7f8	,0x0000	), // MODIFIER LETTER CAPITAL H WITH STROKE
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'i'	,0x0183	,0x1da4	,0x0000	), // MODIFIER LETTER SMALL I WITH STROKE
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'L'	,0x0183	,0xa748	,0x0000	), // LATIN CAPITAL LETTER L WITH HIGH STROKE
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'l'	,0x0183	,0xa749	,0x0000	), // LATIN SMALL LETTER L WITH HIGH STROKE
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'o'	,0x0183	,0x1db1	,0x0000	), // MODIFIER LETTER SMALL BARRED O
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'u'	,0x0183	,0x1db6	,0x0000	), // MODIFIER LETTER SMALL U BAR
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'v'	,0x0183	,0x02c5	,0x0000	), // MODIFIER LETTER DOWN ARROWHEAD
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	0x002d	,0x0183	,0x207b	,0x0000	), // SUPERSCRIPT MINUS
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'2'	,0x0183	,0xa71c	,0x0000	), // MODIFIER LETTER RAISED DOWN ARROW
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'8'	,0x0183	,0xa71b	,0x0000	), // MODIFIER LETTER RAISED UP ARROW
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	0x003c	,0x0183	,0x02c2	,0x0000	), // MODIFIER LETTER LEFT ARROWHEAD
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	0x003e	,0x0183	,0x02c3	,0x0000	), // MODIFIER LETTER RIGHT ARROWHEAD
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	0x005e	,0x0183	,0x02c4	,0x0000	), // MODIFIER LETTER UP ARROWHEAD
/*HOOK_ABOVE         */	DEADTRANS(	0x0020	,0x1ebb	,0x0309	,0x0000	), // COMBINING HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'A'	,0x1ebb	,0x1ea2	,0x0000	), // LATIN CAPITAL LETTER A WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'a'	,0x1ebb	,0x1ea3	,0x0000	), // LATIN SMALL LETTER A WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'b'	,0x1ebb	,0x1d80	,0x0000	), // LATIN SMALL LETTER B WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'c'	,0x1ebb	,0xa794	,0x0000	), // LATIN SMALL LETTER C WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'd'	,0x1ebb	,0x1d81	,0x0000	), // LATIN SMALL LETTER D WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'E'	,0x1ebb	,0x1eba	,0x0000	), // LATIN CAPITAL LETTER E WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'e'	,0x1ebb	,0x1ebb	,0x0000	), // LATIN SMALL LETTER E WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'f'	,0x1ebb	,0x1d82	,0x0000	), // LATIN SMALL LETTER F WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'g'	,0x1ebb	,0x1d83	,0x0000	), // LATIN SMALL LETTER G WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'h'	,0x1ebb	,0xa795	,0x0000	), // LATIN SMALL LETTER H WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'I'	,0x1ebb	,0x1ec8	,0x0000	), // LATIN CAPITAL LETTER I WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'i'	,0x1ebb	,0x1ec9	,0x0000	), // LATIN SMALL LETTER I WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'k'	,0x1ebb	,0x1d84	,0x0000	), // LATIN SMALL LETTER K WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'l'	,0x1ebb	,0x1d85	,0x0000	), // LATIN SMALL LETTER L WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'm'	,0x1ebb	,0x1d86	,0x0000	), // LATIN SMALL LETTER M WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'n'	,0x1ebb	,0x1d87	,0x0000	), // LATIN SMALL LETTER N WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'O'	,0x1ebb	,0x1ece	,0x0000	), // LATIN CAPITAL LETTER O WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'o'	,0x1ebb	,0x1ecf	,0x0000	), // LATIN SMALL LETTER O WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'p'	,0x1ebb	,0x1d88	,0x0000	), // LATIN SMALL LETTER P WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'r'	,0x1ebb	,0x1d89	,0x0000	), // LATIN SMALL LETTER R WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L's'	,0x1ebb	,0x1d8a	,0x0000	), // LATIN SMALL LETTER S WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L't'	,0x1ebb	,0x01ab	,0x0000	), // LATIN SMALL LETTER T WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'U'	,0x1ebb	,0x1ee6	,0x0000	), // LATIN CAPITAL LETTER U WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'u'	,0x1ebb	,0x1ee7	,0x0000	), // LATIN SMALL LETTER U WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'v'	,0x1ebb	,0x1d8c	,0x0000	), // LATIN SMALL LETTER V WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'x'	,0x1ebb	,0x1d8d	,0x0000	), // LATIN SMALL LETTER X WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'Y'	,0x1ebb	,0x1ef6	,0x0000	), // LATIN CAPITAL LETTER Y WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'y'	,0x1ebb	,0x1ef7	,0x0000	), // LATIN SMALL LETTER Y WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'z'	,0x1ebb	,0x1d8e	,0x0000	), // LATIN SMALL LETTER Z WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	0x0029	,0x1ebb	,0x1eb3	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	0x002c	,0x1ebb	,0x1edf	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	0x002d	,0x1ecf	,0x266b	,0x0000	), // BEAMED EIGHTH NOTES
/*HOOK_ABOVE         */	DEADTRANS(	0x003c	,0x1ebb	,0x1ed5	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	0x003d	,0x1ecf	,0x266c	,0x0000	), // BEAMED SIXTEENTH NOTES
/*HOOK_ABOVE         */	DEADTRANS(	0x005d	,0x1ebb	,0xab32	,0x0001	), // LATIN SMALL LETTER BLACKLETTER E
/*HOOK_ABOVE         */	DEADTRANS(	0x00a9	,0x1ebb	,0x1d8b	,0x0001	), // LATIN SMALL LETTER ESH WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'c'	,0x1d8b	,0x1d8b	,0x0000	), // LATIN SMALL LETTER ESH WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L's'	,0x1d8b	,0x1d8b	,0x0000	), // LATIN SMALL LETTER ESH WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	0x00ea	,0x1ebb	,0x1ed5	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	0x0229	,0x1ebb	,0x1edf	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	0x014f	,0x1ebb	,0x1eb3	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	0x01a1	,0x1ebb	,0x1edf	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND HOOK ABOVE
/*HORN               */	DEADTRANS(	0x0020	,0x01a1	,0x031b	,0x0000	), // COMBINING HORN
/*HORN               */	DEADTRANS(	L'O'	,0x01a1	,0x01a0	,0x0000	), // LATIN CAPITAL LETTER O WITH HORN
/*HORN               */	DEADTRANS(	L'o'	,0x01a1	,0x01a1	,0x0000	), // LATIN SMALL LETTER O WITH HORN
/*HORN               */	DEADTRANS(	L'U'	,0x01a1	,0x01af	,0x0000	), // LATIN CAPITAL LETTER U WITH HORN
/*HORN               */	DEADTRANS(	L'u'	,0x01a1	,0x01b0	,0x0000	), // LATIN SMALL LETTER U WITH HORN
/*HORN               */	DEADTRANS(	0x0021	,0x01a1	,0x1ee3	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND DOT BELOW
/*HORN               */	DEADTRANS(	0x0027	,0x01a1	,0x1edb	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND ACUTE
/*HORN               */	DEADTRANS(	0x005d	,0x01a1	,0x1edf	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND HOOK ABOVE
/*HORN               */	DEADTRANS(	0x0060	,0x01a1	,0x1edd	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND GRAVE
/*HORN               */	DEADTRANS(	0x007e	,0x01a1	,0x1ee1	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND TILDE
/*HORN               */	DEADTRANS(	0x00e1	,0x01a1	,0x1edb	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND ACUTE
/*HORN               */	DEADTRANS(	0x00f2	,0x01a1	,0x1edd	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND GRAVE
/*HORN               */	DEADTRANS(	0x00f5	,0x01a1	,0x1ee1	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND TILDE
/*HORN               */	DEADTRANS(	0x1ebb	,0x01a1	,0x1edf	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND HOOK ABOVE
/*HORN               */	DEADTRANS(	0x1ee5	,0x01a1	,0x1ee3	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND DOT BELOW
/*HORN&ACUTE_ACCENT  */	DEADTRANS(	L'C'	,0x1e09	,0x1e08	,0x0000	), // LATIN CAPITAL LETTER C WITH CEDILLA AND ACUTE
/*HORN&ACUTE_ACCENT  */	DEADTRANS(	L'c'	,0x1e09	,0x1e09	,0x0000	), // LATIN SMALL LETTER C WITH CEDILLA AND ACUTE
/*HORN&ACUTE_ACCENT  */	DEADTRANS(	L'O'	,0x1e09	,0x1eda	,0x0000	), // LATIN CAPITAL LETTER O WITH HORN AND ACUTE
/*HORN&ACUTE_ACCENT  */	DEADTRANS(	L'o'	,0x1e09	,0x1edb	,0x0000	), // LATIN SMALL LETTER O WITH HORN AND ACUTE
/*HORN&ACUTE_ACCENT  */	DEADTRANS(	L'U'	,0x1e09	,0x1ee8	,0x0000	), // LATIN CAPITAL LETTER U WITH HORN AND ACUTE
/*HORN&ACUTE_ACCENT  */	DEADTRANS(	L'u'	,0x1e09	,0x1ee9	,0x0000	), // LATIN SMALL LETTER U WITH HORN AND ACUTE
/*HORN&DOT_BELOW     */	DEADTRANS(	L'O'	,0x1ee3	,0x1ee2	,0x0000	), // LATIN CAPITAL LETTER O WITH HORN AND DOT BELOW
/*HORN&DOT_BELOW     */	DEADTRANS(	L'o'	,0x1ee3	,0x1ee3	,0x0000	), // LATIN SMALL LETTER O WITH HORN AND DOT BELOW
/*HORN&DOT_BELOW     */	DEADTRANS(	L'U'	,0x1ee3	,0x1ef0	,0x0000	), // LATIN CAPITAL LETTER U WITH HORN AND DOT BELOW
/*HORN&DOT_BELOW     */	DEADTRANS(	L'u'	,0x1ee3	,0x1ef1	,0x0000	), // LATIN SMALL LETTER U WITH HORN AND DOT BELOW
/*HORN&GRAVE         */	DEADTRANS(	L'O'	,0x1edd	,0x1edc	,0x0000	), // LATIN CAPITAL LETTER O WITH HORN AND GRAVE
/*HORN&GRAVE         */	DEADTRANS(	L'o'	,0x1edd	,0x1edd	,0x0000	), // LATIN SMALL LETTER O WITH HORN AND GRAVE
/*HORN&GRAVE         */	DEADTRANS(	L'U'	,0x1edd	,0x1eea	,0x0000	), // LATIN CAPITAL LETTER U WITH HORN AND GRAVE
/*HORN&GRAVE         */	DEADTRANS(	L'u'	,0x1edd	,0x1eeb	,0x0000	), // LATIN SMALL LETTER U WITH HORN AND GRAVE
/*HORN&HOOK_ABOVE    */	DEADTRANS(	L'O'	,0x1edf	,0x1ede	,0x0000	), // LATIN CAPITAL LETTER O WITH HORN AND HOOK ABOVE
/*HORN&HOOK_ABOVE    */	DEADTRANS(	L'o'	,0x1edf	,0x1edf	,0x0000	), // LATIN SMALL LETTER O WITH HORN AND HOOK ABOVE
/*HORN&HOOK_ABOVE    */	DEADTRANS(	L'U'	,0x1edf	,0x1eec	,0x0000	), // LATIN CAPITAL LETTER U WITH HORN AND HOOK ABOVE
/*HORN&HOOK_ABOVE    */	DEADTRANS(	L'u'	,0x1edf	,0x1eed	,0x0000	), // LATIN SMALL LETTER U WITH HORN AND HOOK ABOVE
/*HORN&TILDE         */	DEADTRANS(	L'O'	,0x1ee1	,0x1ee0	,0x0000	), // LATIN CAPITAL LETTER O WITH HORN AND TILDE
/*HORN&TILDE         */	DEADTRANS(	L'o'	,0x1ee1	,0x1ee1	,0x0000	), // LATIN SMALL LETTER O WITH HORN AND TILDE
/*HORN&TILDE         */	DEADTRANS(	L'U'	,0x1ee1	,0x1eee	,0x0000	), // LATIN CAPITAL LETTER U WITH HORN AND TILDE
/*HORN&TILDE         */	DEADTRANS(	L'u'	,0x1ee1	,0x1eef	,0x0000	), // LATIN SMALL LETTER U WITH HORN AND TILDE
/*INSULAR            */	DEADTRANS(	L'D'	,0x1d79	,0xa779	,0x0000	), // LATIN CAPITAL LETTER INSULAR D
/*INSULAR            */	DEADTRANS(	L'd'	,0x1d79	,0xa77a	,0x0000	), // LATIN SMALL LETTER INSULAR D
/*INSULAR            */	DEADTRANS(	L'F'	,0x1d79	,0xa77b	,0x0000	), // LATIN CAPITAL LETTER INSULAR F
/*INSULAR            */	DEADTRANS(	L'f'	,0x1d79	,0xa77c	,0x0000	), // LATIN SMALL LETTER INSULAR F
/*INSULAR            */	DEADTRANS(	L'G'	,0x1d79	,0xa77d	,0x0000	), // LATIN CAPITAL LETTER INSULAR G
/*INSULAR            */	DEADTRANS(	L'g'	,0x1d79	,0x1d79	,0x0000	), // LATIN SMALL LETTER INSULAR G
/*INSULAR            */	DEADTRANS(	L'R'	,0x1d79	,0xa782	,0x0000	), // LATIN CAPITAL LETTER INSULAR R
/*INSULAR            */	DEADTRANS(	L'r'	,0x1d79	,0xa783	,0x0000	), // LATIN SMALL LETTER INSULAR R
/*INSULAR            */	DEADTRANS(	L'S'	,0x1d79	,0xa784	,0x0000	), // LATIN CAPITAL LETTER INSULAR S
/*INSULAR            */	DEADTRANS(	L's'	,0x1d79	,0xa785	,0x0000	), // LATIN SMALL LETTER INSULAR S
/*INSULAR            */	DEADTRANS(	L'T'	,0x1d79	,0xa786	,0x0000	), // LATIN CAPITAL LETTER INSULAR T
/*INSULAR            */	DEADTRANS(	L't'	,0x1d79	,0xa787	,0x0000	), // LATIN SMALL LETTER INSULAR T
/*INVERTED           */	DEADTRANS(	L'A'	,0x0281	,0x2c6f	,0x0000	), // LATIN CAPITAL LETTER TURNED A
/*INVERTED           */	DEADTRANS(	L'a'	,0x0281	,0xab64	,0x0000	), // LATIN SMALL LETTER INVERTED ALPHA
/*INVERTED           */	DEADTRANS(	L'M'	,0x0281	,0xa7fd	,0x0000	), // LATIN EPIGRAPHIC LETTER INVERTED M
/*INVERTED           */	DEADTRANS(	L'o'	,0x0281	,0xab40	,0x0000	), // LATIN SMALL LETTER INVERTED OE
/*INVERTED           */	DEADTRANS(	L'T'	,0x0281	,0xa7b1	,0x0000	), // LATIN CAPITAL LETTER TURNED T
/*INVERTED           */	DEADTRANS(	L'V'	,0x0281	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*INVERTED           */	DEADTRANS(	L'v'	,0x0281	,0x028c	,0x0000	), // LATIN SMALL LETTER TURNED V
/*INVERTED           */	DEADTRANS(	0x00f9	,0x0281	,0x0296	,0x0000	), // LATIN LETTER INVERTED GLOTTAL STOP
/*INVERTED           */	DEADTRANS(	0x0021	,0x0281	,0x00a1	,0x0000	), // INVERTED EXCLAMATION MARK
/*INVERTED           */	DEADTRANS(	0x0025	,0x0281	,0x2030	,0x0000	), // PER MILLE SIGN
/*INVERTED           */	DEADTRANS(	0x0027	,0x0281	,0x0296	,0x0000	), // LATIN LETTER INVERTED GLOTTAL STOP
/*INVERTED           */	DEADTRANS(	0x003f	,0x0281	,0x00bf	,0x0000	), // INVERTED QUESTION MARK
/*INVERTED           */	DEADTRANS(	0x2019	,0x0281	,0x0296	,0x0000	), // LATIN LETTER INVERTED GLOTTAL STOP
/*INVERTED_BREVE     */	DEADTRANS(	0x0020	,0x0213	,0x0311	,0x0000	), // COMBINING INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	0x202f	,0x0213	,0x2229	,0x0000	), // INTERSECTION
/*INVERTED_BREVE     */	DEADTRANS(	0x00a0	,0x0213	,0x2229	,0x0000	), // INTERSECTION
/*INVERTED_BREVE     */	DEADTRANS(	0x0029	,0x0213	,0x2050	,0x0000	), // CLOSE UP
/*INVERTED_BREVE     */	DEADTRANS(	0x002e	,0x0213	,0x0352	,0x0000	), // COMBINING FERMATA
/*INVERTED_BREVE     */	DEADTRANS(	L'A'	,0x0213	,0x0202	,0x0000	), // LATIN CAPITAL LETTER A WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'a'	,0x0213	,0x0203	,0x0000	), // LATIN SMALL LETTER A WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'E'	,0x0213	,0x0206	,0x0000	), // LATIN CAPITAL LETTER E WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'e'	,0x0213	,0x0207	,0x0000	), // LATIN SMALL LETTER E WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'H'	,0x0213	,0x1e2a	,0x0000	), // LATIN CAPITAL LETTER H WITH BREVE BELOW
/*INVERTED_BREVE     */	DEADTRANS(	L'h'	,0x0213	,0x1e2b	,0x0000	), // LATIN SMALL LETTER H WITH BREVE BELOW
/*INVERTED_BREVE     */	DEADTRANS(	L'I'	,0x0213	,0x020a	,0x0000	), // LATIN CAPITAL LETTER I WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'i'	,0x0213	,0x020b	,0x0000	), // LATIN SMALL LETTER I WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'O'	,0x0213	,0x020e	,0x0000	), // LATIN CAPITAL LETTER O WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'o'	,0x0213	,0x020f	,0x0000	), // LATIN SMALL LETTER O WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'R'	,0x0213	,0x0212	,0x0000	), // LATIN CAPITAL LETTER R WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'r'	,0x0213	,0x0213	,0x0000	), // LATIN SMALL LETTER R WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'U'	,0x0213	,0x0216	,0x0000	), // LATIN CAPITAL LETTER U WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'u'	,0x0213	,0x0217	,0x0000	), // LATIN SMALL LETTER U WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	0x0115	,0x0213	,0x1e2b	,0x0000	), // LATIN SMALL LETTER H WITH BREVE BELOW
/*LONG               */	DEADTRANS(	L'c'	,0x007c	,0x0297	,0x0000	), // LATIN LETTER STRETCHED C
/*LONG               */	DEADTRANS(	L'I'	,0x007c	,0xa7fe	,0x0000	), // LATIN EPIGRAPHIC LETTER I LONGA
/*LONG               */	DEADTRANS(	L'i'	,0x007c	,0xa7fe	,0x0000	), // LATIN EPIGRAPHIC LETTER I LONGA
/*LONG               */	DEADTRANS(	L'N'	,0x007c	,0x0220	,0x0000	), // LATIN CAPITAL LETTER N WITH LONG RIGHT LEG
/*LONG               */	DEADTRANS(	L'n'	,0x007c	,0x019e	,0x0000	), // LATIN SMALL LETTER N WITH LONG RIGHT LEG
/*LONG               */	DEADTRANS(	L'o'	,0x007c	,0x2c77	,0x0000	), // LATIN SMALL LETTER TAILLESS PHI
/*LONG               */	DEADTRANS(	L'P'	,0x007c	,0x00b6	,0x0000	), // PILCROW SIGN
/*LONG               */	DEADTRANS(	L'p'	,0x007c	,0x00b6	,0x0000	), // PILCROW SIGN
/*LONG               */	DEADTRANS(	L'R'	,0x007c	,0xab46	,0x0000	), // LATIN LETTER SMALL CAPITAL R WITH RIGHT LEG
/*LONG               */	DEADTRANS(	L'r'	,0x007c	,0x027c	,0x0000	), // LATIN SMALL LETTER R WITH LONG LEG
/*LONG               */	DEADTRANS(	L'V'	,0x007c	,0xa768	,0x0000	), // LATIN CAPITAL LETTER VEND
/*LONG               */	DEADTRANS(	L'v'	,0x007c	,0xa769	,0x0000	), // LATIN SMALL LETTER VEND
/*LONG               */	DEADTRANS(	L'x'	,0x007c	,0xab57	,0x0000	), // LATIN SMALL LETTER X WITH LONG LEFT LEG
/*LONG               */	DEADTRANS(	L'0'	,0x007c	,0x02e9	,0x0000	), // MODIFIER LETTER EXTRA-LOW TONE BAR
/*LONG               */	DEADTRANS(	L'1'	,0x007c	,0x02e8	,0x0000	), // MODIFIER LETTER LOW TONE BAR
/*LONG               */	DEADTRANS(	L'2'	,0x007c	,0x02e7	,0x0000	), // MODIFIER LETTER MID TONE BAR
/*LONG               */	DEADTRANS(	L'3'	,0x007c	,0x02e6	,0x0000	), // MODIFIER LETTER HIGH TONE BAR
/*LONG               */	DEADTRANS(	L'4'	,0x007c	,0x02e5	,0x0000	), // MODIFIER LETTER EXTRA-HIGH TONE BAR
/*LONG               */	DEADTRANS(	0x0023	,0x007c	,0x2e38	,0x0000	), // TURNED DAGGER
/*LONG               */	DEADTRANS(	0x0025	,0x007c	,0x2e4b	,0x0000	), // TRIPLE DAGGER
/*LONG               */	DEADTRANS(	0x002b	,0x007c	,0x2020	,0x0000	), // DAGGER
/*LONG               */	DEADTRANS(	0x002d	,0x007c	,0xa714	,0x0001	), // MODIFIER LETTER MID LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'0'	,0xa714	,0xa716	,0x0000	), // MODIFIER LETTER EXTRA-LOW LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'1'	,0xa714	,0xa715	,0x0000	), // MODIFIER LETTER LOW LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'2'	,0xa714	,0xa714	,0x0000	), // MODIFIER LETTER MID LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'3'	,0xa714	,0xa713	,0x0000	), // MODIFIER LETTER HIGH LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'4'	,0xa714	,0xa712	,0x0000	), // MODIFIER LETTER EXTRA-HIGH LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	0x002e	,0x007c	,0xa70f	,0x0001	), // MODIFIER LETTER MID DOTTED LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'0'	,0xa70f	,0xa711	,0x0000	), // MODIFIER LETTER EXTRA-LOW DOTTED LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'1'	,0xa70f	,0xa710	,0x0000	), // MODIFIER LETTER LOW DOTTED LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'2'	,0xa70f	,0xa70f	,0x0000	), // MODIFIER LETTER MID DOTTED LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'3'	,0xa70f	,0xa70e	,0x0000	), // MODIFIER LETTER HIGH DOTTED LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'4'	,0xa70f	,0xa70d	,0x0000	), // MODIFIER LETTER EXTRA-HIGH DOTTED LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	0x003a	,0xa70f	,0x205b	,0x0000	), // FOUR DOT MARK
/*LONG               */	DEADTRANS(	0x003a	,0x007c	,0x205a	,0x0000	), // TWO DOT PUNCTUATION
/*LONG               */	DEADTRANS(	0x003c	,0x007c	,0x2e36	,0x0000	), // DAGGER WITH LEFT GUARD
/*LONG               */	DEADTRANS(	0x003d	,0x007c	,0x2021	,0x0000	), // DOUBLE DAGGER
/*LONG               */	DEADTRANS(	0x003e	,0x007c	,0x2e37	,0x0000	), // DAGGER WITH RIGHT GUARD
/*LONG               */	DEADTRANS(	0x007c	,0x007c	,0x2016	,0x0000	), // DOUBLE VERTICAL LINE
/*LONG               */	DEADTRANS(	0x00b0	,0x007c	,0x2020	,0x0000	), // DAGGER
/*LONG_BAR           */	DEADTRANS(	0x0020	,0x2013	,0x0336	,0x0000	), // COMBINING LONG STROKE OVERLAY
/*LONG_BAR           */	DEADTRANS(	0x0021	,0x2013	,0x2013	,0x0000	), // EN DASH
/*LONG_BAR           */	DEADTRANS(	0x002d	,0x2013	,0x2014	,0x0000	), // EM DASH
/*LONG_BAR           */	DEADTRANS(	L'O'	,0x2013	,0xa74a	,0x0000	), // LATIN CAPITAL LETTER O WITH LONG STROKE OVERLAY
/*LONG_BAR           */	DEADTRANS(	L'o'	,0x2013	,0xa74b	,0x0000	), // LATIN SMALL LETTER O WITH LONG STROKE OVERLAY
/*LONG_BAR           */	DEADTRANS(	L'0'	,0x2013	,0x2195	,0x0000	), // UP DOWN ARROW
/*LONG_BAR           */	DEADTRANS(	L'1'	,0x2013	,0x2199	,0x0000	), // SOUTH WEST ARROW
/*LONG_BAR           */	DEADTRANS(	L'2'	,0x2013	,0x2193	,0x0000	), // DOWNWARDS ARROW
/*LONG_BAR           */	DEADTRANS(	L'3'	,0x2013	,0x2198	,0x0000	), // SOUTH EAST ARROW
/*LONG_BAR           */	DEADTRANS(	L'4'	,0x2013	,0x2190	,0x0000	), // LEFTWARDS ARROW
/*LONG_BAR           */	DEADTRANS(	L'5'	,0x2013	,0x2194	,0x0000	), // LEFT RIGHT ARROW
/*LONG_BAR           */	DEADTRANS(	L'6'	,0x2013	,0x2192	,0x0000	), // RIGHTWARDS ARROW
/*LONG_BAR           */	DEADTRANS(	L'7'	,0x2013	,0x2196	,0x0000	), // NORTH WEST ARROW
/*LONG_BAR           */	DEADTRANS(	L'8'	,0x2013	,0x2191	,0x0000	), // UPWARDS ARROW
/*LONG_BAR           */	DEADTRANS(	L'9'	,0x2013	,0x2197	,0x0000	), // NORTH EAST ARROW
/*M_BOLD             */	DEADTRANS(	L'A'	,0x212c	,0xdc00	,0x0000	), // U+1D400; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL A
/*M_BOLD             */	DEADTRANS(	L'a'	,0x212c	,0xdc1a	,0x0000	), // U+1D41A; input D835 high surrogate first; MATHEMATICAL BOLD SMALL A
/*M_BOLD             */	DEADTRANS(	L'B'	,0x212c	,0xdc01	,0x0000	), // U+1D401; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL B
/*M_BOLD             */	DEADTRANS(	L'b'	,0x212c	,0xdc1b	,0x0000	), // U+1D41B; input D835 high surrogate first; MATHEMATICAL BOLD SMALL B
/*M_BOLD             */	DEADTRANS(	L'C'	,0x212c	,0xdc02	,0x0000	), // U+1D402; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL C
/*M_BOLD             */	DEADTRANS(	L'c'	,0x212c	,0xdc1c	,0x0000	), // U+1D41C; input D835 high surrogate first; MATHEMATICAL BOLD SMALL C
/*M_BOLD             */	DEADTRANS(	L'D'	,0x212c	,0xdc03	,0x0000	), // U+1D403; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL D
/*M_BOLD             */	DEADTRANS(	L'd'	,0x212c	,0xdc1d	,0x0000	), // U+1D41D; input D835 high surrogate first; MATHEMATICAL BOLD SMALL D
/*M_BOLD             */	DEADTRANS(	L'E'	,0x212c	,0xdc04	,0x0000	), // U+1D404; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL E
/*M_BOLD             */	DEADTRANS(	L'e'	,0x212c	,0xdc1e	,0x0000	), // U+1D41E; input D835 high surrogate first; MATHEMATICAL BOLD SMALL E
/*M_BOLD             */	DEADTRANS(	L'F'	,0x212c	,0xdc05	,0x0000	), // U+1D405; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL F
/*M_BOLD             */	DEADTRANS(	L'f'	,0x212c	,0xdc1f	,0x0000	), // U+1D41F; input D835 high surrogate first; MATHEMATICAL BOLD SMALL F
/*M_BOLD             */	DEADTRANS(	L'G'	,0x212c	,0xdc06	,0x0000	), // U+1D406; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL G
/*M_BOLD             */	DEADTRANS(	L'g'	,0x212c	,0xdc20	,0x0000	), // U+1D420; input D835 high surrogate first; MATHEMATICAL BOLD SMALL G
/*M_BOLD             */	DEADTRANS(	L'H'	,0x212c	,0xdc07	,0x0000	), // U+1D407; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL H
/*M_BOLD             */	DEADTRANS(	L'h'	,0x212c	,0xdc21	,0x0000	), // U+1D421; input D835 high surrogate first; MATHEMATICAL BOLD SMALL H
/*M_BOLD             */	DEADTRANS(	L'I'	,0x212c	,0xdc08	,0x0000	), // U+1D408; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL I
/*M_BOLD             */	DEADTRANS(	L'i'	,0x212c	,0xdc22	,0x0000	), // U+1D422; input D835 high surrogate first; MATHEMATICAL BOLD SMALL I
/*M_BOLD             */	DEADTRANS(	L'J'	,0x212c	,0xdc09	,0x0000	), // U+1D409; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL J
/*M_BOLD             */	DEADTRANS(	L'j'	,0x212c	,0xdc23	,0x0000	), // U+1D423; input D835 high surrogate first; MATHEMATICAL BOLD SMALL J
/*M_BOLD             */	DEADTRANS(	L'K'	,0x212c	,0xdc0a	,0x0000	), // U+1D40A; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL K
/*M_BOLD             */	DEADTRANS(	L'k'	,0x212c	,0xdc24	,0x0000	), // U+1D424; input D835 high surrogate first; MATHEMATICAL BOLD SMALL K
/*M_BOLD             */	DEADTRANS(	L'L'	,0x212c	,0xdc0b	,0x0000	), // U+1D40B; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL L
/*M_BOLD             */	DEADTRANS(	L'l'	,0x212c	,0xdc25	,0x0000	), // U+1D425; input D835 high surrogate first; MATHEMATICAL BOLD SMALL L
/*M_BOLD             */	DEADTRANS(	L'M'	,0x212c	,0xdc0c	,0x0000	), // U+1D40C; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL M
/*M_BOLD             */	DEADTRANS(	L'm'	,0x212c	,0xdc26	,0x0000	), // U+1D426; input D835 high surrogate first; MATHEMATICAL BOLD SMALL M
/*M_BOLD             */	DEADTRANS(	L'N'	,0x212c	,0xdc0d	,0x0000	), // U+1D40D; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL N
/*M_BOLD             */	DEADTRANS(	L'n'	,0x212c	,0xdc27	,0x0000	), // U+1D427; input D835 high surrogate first; MATHEMATICAL BOLD SMALL N
/*M_BOLD             */	DEADTRANS(	L'O'	,0x212c	,0xdc0e	,0x0000	), // U+1D40E; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL O
/*M_BOLD             */	DEADTRANS(	L'o'	,0x212c	,0xdc28	,0x0000	), // U+1D428; input D835 high surrogate first; MATHEMATICAL BOLD SMALL O
/*M_BOLD             */	DEADTRANS(	L'P'	,0x212c	,0xdc0f	,0x0000	), // U+1D40F; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL P
/*M_BOLD             */	DEADTRANS(	L'p'	,0x212c	,0xdc29	,0x0000	), // U+1D429; input D835 high surrogate first; MATHEMATICAL BOLD SMALL P
/*M_BOLD             */	DEADTRANS(	L'Q'	,0x212c	,0xdc10	,0x0000	), // U+1D410; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL Q
/*M_BOLD             */	DEADTRANS(	L'q'	,0x212c	,0xdc2a	,0x0000	), // U+1D42A; input D835 high surrogate first; MATHEMATICAL BOLD SMALL Q
/*M_BOLD             */	DEADTRANS(	L'R'	,0x212c	,0xdc11	,0x0000	), // U+1D411; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL R
/*M_BOLD             */	DEADTRANS(	L'r'	,0x212c	,0xdc2b	,0x0000	), // U+1D42B; input D835 high surrogate first; MATHEMATICAL BOLD SMALL R
/*M_BOLD             */	DEADTRANS(	L'S'	,0x212c	,0xdc12	,0x0000	), // U+1D412; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL S
/*M_BOLD             */	DEADTRANS(	L's'	,0x212c	,0xdc2c	,0x0000	), // U+1D42C; input D835 high surrogate first; MATHEMATICAL BOLD SMALL S
/*M_BOLD             */	DEADTRANS(	L'T'	,0x212c	,0xdc13	,0x0000	), // U+1D413; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL T
/*M_BOLD             */	DEADTRANS(	L't'	,0x212c	,0xdc2d	,0x0000	), // U+1D42D; input D835 high surrogate first; MATHEMATICAL BOLD SMALL T
/*M_BOLD             */	DEADTRANS(	L'U'	,0x212c	,0xdc14	,0x0000	), // U+1D414; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL U
/*M_BOLD             */	DEADTRANS(	L'u'	,0x212c	,0xdc2e	,0x0000	), // U+1D42E; input D835 high surrogate first; MATHEMATICAL BOLD SMALL U
/*M_BOLD             */	DEADTRANS(	L'V'	,0x212c	,0xdc15	,0x0000	), // U+1D415; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL V
/*M_BOLD             */	DEADTRANS(	L'v'	,0x212c	,0xdc2f	,0x0000	), // U+1D42F; input D835 high surrogate first; MATHEMATICAL BOLD SMALL V
/*M_BOLD             */	DEADTRANS(	L'W'	,0x212c	,0xdc16	,0x0000	), // U+1D416; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL W
/*M_BOLD             */	DEADTRANS(	L'w'	,0x212c	,0xdc30	,0x0000	), // U+1D430; input D835 high surrogate first; MATHEMATICAL BOLD SMALL W
/*M_BOLD             */	DEADTRANS(	L'X'	,0x212c	,0xdc17	,0x0000	), // U+1D417; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL X
/*M_BOLD             */	DEADTRANS(	L'x'	,0x212c	,0xdc31	,0x0000	), // U+1D431; input D835 high surrogate first; MATHEMATICAL BOLD SMALL X
/*M_BOLD             */	DEADTRANS(	L'Y'	,0x212c	,0xdc18	,0x0000	), // U+1D418; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL Y
/*M_BOLD             */	DEADTRANS(	L'y'	,0x212c	,0xdc32	,0x0000	), // U+1D432; input D835 high surrogate first; MATHEMATICAL BOLD SMALL Y
/*M_BOLD             */	DEADTRANS(	L'Z'	,0x212c	,0xdc19	,0x0000	), // U+1D419; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL Z
/*M_BOLD             */	DEADTRANS(	L'z'	,0x212c	,0xdc33	,0x0000	), // U+1D433; input D835 high surrogate first; MATHEMATICAL BOLD SMALL Z
/*M_BOLD             */	DEADTRANS(	0x0024	,0x212c	,0x211b	,0x0001	), // SCRIPT CAPITAL R
/*M_BOLD             */	DEADTRANS(	0x0025	,0x212c	,0x211c	,0x0001	), // BLACK-LETTER CAPITAL R
/*M_BOLD             */	DEADTRANS(	0x0026	,0x212c	,0x2131	,0x0001	), // SCRIPT CAPITAL F
/*M_BOLD             */	DEADTRANS(	0x002f	,0x212c	,0x2110	,0x0001	), // SCRIPT CAPITAL I
/*M_BOLD_ITALIC      */	DEADTRANS(	L'A'	,0x2110	,0xdc68	,0x0000	), // U+1D468; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL A
/*M_BOLD_ITALIC      */	DEADTRANS(	L'a'	,0x2110	,0xdc82	,0x0000	), // U+1D482; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL A
/*M_BOLD_ITALIC      */	DEADTRANS(	L'B'	,0x2110	,0xdc69	,0x0000	), // U+1D469; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL B
/*M_BOLD_ITALIC      */	DEADTRANS(	L'b'	,0x2110	,0xdc83	,0x0000	), // U+1D483; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL B
/*M_BOLD_ITALIC      */	DEADTRANS(	L'C'	,0x2110	,0xdc6a	,0x0000	), // U+1D46A; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL C
/*M_BOLD_ITALIC      */	DEADTRANS(	L'c'	,0x2110	,0xdc84	,0x0000	), // U+1D484; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL C
/*M_BOLD_ITALIC      */	DEADTRANS(	L'D'	,0x2110	,0xdc6b	,0x0000	), // U+1D46B; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL D
/*M_BOLD_ITALIC      */	DEADTRANS(	L'd'	,0x2110	,0xdc85	,0x0000	), // U+1D485; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL D
/*M_BOLD_ITALIC      */	DEADTRANS(	L'E'	,0x2110	,0xdc6c	,0x0000	), // U+1D46C; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL E
/*M_BOLD_ITALIC      */	DEADTRANS(	L'e'	,0x2110	,0xdc86	,0x0000	), // U+1D486; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL E
/*M_BOLD_ITALIC      */	DEADTRANS(	L'F'	,0x2110	,0xdc6d	,0x0000	), // U+1D46D; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL F
/*M_BOLD_ITALIC      */	DEADTRANS(	L'f'	,0x2110	,0xdc87	,0x0000	), // U+1D487; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL F
/*M_BOLD_ITALIC      */	DEADTRANS(	L'G'	,0x2110	,0xdc6e	,0x0000	), // U+1D46E; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL G
/*M_BOLD_ITALIC      */	DEADTRANS(	L'g'	,0x2110	,0xdc88	,0x0000	), // U+1D488; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL G
/*M_BOLD_ITALIC      */	DEADTRANS(	L'H'	,0x2110	,0xdc6f	,0x0000	), // U+1D46F; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL H
/*M_BOLD_ITALIC      */	DEADTRANS(	L'h'	,0x2110	,0xdc89	,0x0000	), // U+1D489; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL H
/*M_BOLD_ITALIC      */	DEADTRANS(	L'I'	,0x2110	,0xdc70	,0x0000	), // U+1D470; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL I
/*M_BOLD_ITALIC      */	DEADTRANS(	L'i'	,0x2110	,0xdc8a	,0x0000	), // U+1D48A; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL I
/*M_BOLD_ITALIC      */	DEADTRANS(	L'J'	,0x2110	,0xdc71	,0x0000	), // U+1D471; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL J
/*M_BOLD_ITALIC      */	DEADTRANS(	L'j'	,0x2110	,0xdc8b	,0x0000	), // U+1D48B; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL J
/*M_BOLD_ITALIC      */	DEADTRANS(	L'K'	,0x2110	,0xdc72	,0x0000	), // U+1D472; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL K
/*M_BOLD_ITALIC      */	DEADTRANS(	L'k'	,0x2110	,0xdc8c	,0x0000	), // U+1D48C; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL K
/*M_BOLD_ITALIC      */	DEADTRANS(	L'L'	,0x2110	,0xdc73	,0x0000	), // U+1D473; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL L
/*M_BOLD_ITALIC      */	DEADTRANS(	L'l'	,0x2110	,0xdc8d	,0x0000	), // U+1D48D; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL L
/*M_BOLD_ITALIC      */	DEADTRANS(	L'M'	,0x2110	,0xdc74	,0x0000	), // U+1D474; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL M
/*M_BOLD_ITALIC      */	DEADTRANS(	L'm'	,0x2110	,0xdc8e	,0x0000	), // U+1D48E; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL M
/*M_BOLD_ITALIC      */	DEADTRANS(	L'N'	,0x2110	,0xdc75	,0x0000	), // U+1D475; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL N
/*M_BOLD_ITALIC      */	DEADTRANS(	L'n'	,0x2110	,0xdc8f	,0x0000	), // U+1D48F; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL N
/*M_BOLD_ITALIC      */	DEADTRANS(	L'O'	,0x2110	,0xdc76	,0x0000	), // U+1D476; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL O
/*M_BOLD_ITALIC      */	DEADTRANS(	L'o'	,0x2110	,0xdc90	,0x0000	), // U+1D490; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL O
/*M_BOLD_ITALIC      */	DEADTRANS(	L'P'	,0x2110	,0xdc77	,0x0000	), // U+1D477; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL P
/*M_BOLD_ITALIC      */	DEADTRANS(	L'p'	,0x2110	,0xdc91	,0x0000	), // U+1D491; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL P
/*M_BOLD_ITALIC      */	DEADTRANS(	L'Q'	,0x2110	,0xdc78	,0x0000	), // U+1D478; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL Q
/*M_BOLD_ITALIC      */	DEADTRANS(	L'q'	,0x2110	,0xdc92	,0x0000	), // U+1D492; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL Q
/*M_BOLD_ITALIC      */	DEADTRANS(	L'R'	,0x2110	,0xdc79	,0x0000	), // U+1D479; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL R
/*M_BOLD_ITALIC      */	DEADTRANS(	L'r'	,0x2110	,0xdc93	,0x0000	), // U+1D493; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL R
/*M_BOLD_ITALIC      */	DEADTRANS(	L'S'	,0x2110	,0xdc7a	,0x0000	), // U+1D47A; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL S
/*M_BOLD_ITALIC      */	DEADTRANS(	L's'	,0x2110	,0xdc94	,0x0000	), // U+1D494; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL S
/*M_BOLD_ITALIC      */	DEADTRANS(	L'T'	,0x2110	,0xdc7b	,0x0000	), // U+1D47B; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL T
/*M_BOLD_ITALIC      */	DEADTRANS(	L't'	,0x2110	,0xdc95	,0x0000	), // U+1D495; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL T
/*M_BOLD_ITALIC      */	DEADTRANS(	L'U'	,0x2110	,0xdc7c	,0x0000	), // U+1D47C; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL U
/*M_BOLD_ITALIC      */	DEADTRANS(	L'u'	,0x2110	,0xdc96	,0x0000	), // U+1D496; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL U
/*M_BOLD_ITALIC      */	DEADTRANS(	L'V'	,0x2110	,0xdc7d	,0x0000	), // U+1D47D; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL V
/*M_BOLD_ITALIC      */	DEADTRANS(	L'v'	,0x2110	,0xdc97	,0x0000	), // U+1D497; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL V
/*M_BOLD_ITALIC      */	DEADTRANS(	L'W'	,0x2110	,0xdc7e	,0x0000	), // U+1D47E; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL W
/*M_BOLD_ITALIC      */	DEADTRANS(	L'w'	,0x2110	,0xdc98	,0x0000	), // U+1D498; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL W
/*M_BOLD_ITALIC      */	DEADTRANS(	L'X'	,0x2110	,0xdc7f	,0x0000	), // U+1D47F; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL X
/*M_BOLD_ITALIC      */	DEADTRANS(	L'x'	,0x2110	,0xdc99	,0x0000	), // U+1D499; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL X
/*M_BOLD_ITALIC      */	DEADTRANS(	L'Y'	,0x2110	,0xdc80	,0x0000	), // U+1D480; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL Y
/*M_BOLD_ITALIC      */	DEADTRANS(	L'y'	,0x2110	,0xdc9a	,0x0000	), // U+1D49A; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL Y
/*M_BOLD_ITALIC      */	DEADTRANS(	L'Z'	,0x2110	,0xdc81	,0x0000	), // U+1D481; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL Z
/*M_BOLD_ITALIC      */	DEADTRANS(	L'z'	,0x2110	,0xdc9b	,0x0000	), // U+1D49B; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL Z
/*M_BOLD_ITALIC      */	DEADTRANS(	0x0024	,0x2110	,0x2130	,0x0001	), // SCRIPT CAPITAL E
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'A'	,0x211c	,0xdd6c	,0x0000	), // U+1D56C; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL A
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'a'	,0x211c	,0xdd86	,0x0000	), // U+1D586; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL A
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'B'	,0x211c	,0xdd6d	,0x0000	), // U+1D56D; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL B
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'b'	,0x211c	,0xdd87	,0x0000	), // U+1D587; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL B
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'C'	,0x211c	,0xdd6e	,0x0000	), // U+1D56E; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL C
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'c'	,0x211c	,0xdd88	,0x0000	), // U+1D588; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL C
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'D'	,0x211c	,0xdd6f	,0x0000	), // U+1D56F; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL D
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'd'	,0x211c	,0xdd89	,0x0000	), // U+1D589; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL D
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'E'	,0x211c	,0xdd70	,0x0000	), // U+1D570; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL E
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'e'	,0x211c	,0xdd8a	,0x0000	), // U+1D58A; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL E
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'F'	,0x211c	,0xdd71	,0x0000	), // U+1D571; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL F
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'f'	,0x211c	,0xdd8b	,0x0000	), // U+1D58B; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL F
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'G'	,0x211c	,0xdd72	,0x0000	), // U+1D572; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL G
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'g'	,0x211c	,0xdd8c	,0x0000	), // U+1D58C; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL G
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'H'	,0x211c	,0xdd73	,0x0000	), // U+1D573; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL H
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'h'	,0x211c	,0xdd8d	,0x0000	), // U+1D58D; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL H
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'I'	,0x211c	,0xdd74	,0x0000	), // U+1D574; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL I
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'i'	,0x211c	,0xdd8e	,0x0000	), // U+1D58E; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL I
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'J'	,0x211c	,0xdd75	,0x0000	), // U+1D575; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL J
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'j'	,0x211c	,0xdd8f	,0x0000	), // U+1D58F; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL J
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'K'	,0x211c	,0xdd76	,0x0000	), // U+1D576; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL K
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'k'	,0x211c	,0xdd90	,0x0000	), // U+1D590; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL K
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'L'	,0x211c	,0xdd77	,0x0000	), // U+1D577; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL L
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'l'	,0x211c	,0xdd91	,0x0000	), // U+1D591; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL L
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'M'	,0x211c	,0xdd78	,0x0000	), // U+1D578; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL M
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'm'	,0x211c	,0xdd92	,0x0000	), // U+1D592; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL M
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'N'	,0x211c	,0xdd79	,0x0000	), // U+1D579; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL N
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'n'	,0x211c	,0xdd93	,0x0000	), // U+1D593; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL N
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'O'	,0x211c	,0xdd7a	,0x0000	), // U+1D57A; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL O
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'o'	,0x211c	,0xdd94	,0x0000	), // U+1D594; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL O
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'P'	,0x211c	,0xdd7b	,0x0000	), // U+1D57B; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL P
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'p'	,0x211c	,0xdd95	,0x0000	), // U+1D595; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL P
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'Q'	,0x211c	,0xdd7c	,0x0000	), // U+1D57C; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL Q
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'q'	,0x211c	,0xdd96	,0x0000	), // U+1D596; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL Q
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'R'	,0x211c	,0xdd7d	,0x0000	), // U+1D57D; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL R
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'r'	,0x211c	,0xdd97	,0x0000	), // U+1D597; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL R
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'S'	,0x211c	,0xdd7e	,0x0000	), // U+1D57E; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL S
/*M_BOLD_SCRIPT      */	DEADTRANS(	L's'	,0x211c	,0xdd98	,0x0000	), // U+1D598; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL S
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'T'	,0x211c	,0xdd7f	,0x0000	), // U+1D57F; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL T
/*M_BOLD_SCRIPT      */	DEADTRANS(	L't'	,0x211c	,0xdd99	,0x0000	), // U+1D599; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL T
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'U'	,0x211c	,0xdd80	,0x0000	), // U+1D580; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL U
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'u'	,0x211c	,0xdd9a	,0x0000	), // U+1D59A; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL U
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'V'	,0x211c	,0xdd81	,0x0000	), // U+1D581; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL V
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'v'	,0x211c	,0xdd9b	,0x0000	), // U+1D59B; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL V
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'W'	,0x211c	,0xdd82	,0x0000	), // U+1D582; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL W
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'w'	,0x211c	,0xdd9c	,0x0000	), // U+1D59C; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL W
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'X'	,0x211c	,0xdd83	,0x0000	), // U+1D583; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL X
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'x'	,0x211c	,0xdd9d	,0x0000	), // U+1D59D; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL X
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'Y'	,0x211c	,0xdd84	,0x0000	), // U+1D584; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL Y
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'y'	,0x211c	,0xdd9e	,0x0000	), // U+1D59E; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL Y
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'Z'	,0x211c	,0xdd85	,0x0000	), // U+1D585; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL Z
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'z'	,0x211c	,0xdd9f	,0x0000	), // U+1D59F; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL Z
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'A'	,0x2131	,0xdcd0	,0x0000	), // U+1D4D0; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL A
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'a'	,0x2131	,0xdcea	,0x0000	), // U+1D4EA; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL A
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'B'	,0x2131	,0xdcd1	,0x0000	), // U+1D4D1; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL B
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'b'	,0x2131	,0xdceb	,0x0000	), // U+1D4EB; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL B
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'C'	,0x2131	,0xdcd2	,0x0000	), // U+1D4D2; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL C
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'c'	,0x2131	,0xdcec	,0x0000	), // U+1D4EC; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL C
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'D'	,0x2131	,0xdcd3	,0x0000	), // U+1D4D3; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL D
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'd'	,0x2131	,0xdced	,0x0000	), // U+1D4ED; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL D
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'E'	,0x2131	,0xdcd4	,0x0000	), // U+1D4D4; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL E
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'e'	,0x2131	,0xdcee	,0x0000	), // U+1D4EE; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL E
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'F'	,0x2131	,0xdcd5	,0x0000	), // U+1D4D5; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL F
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'f'	,0x2131	,0xdcef	,0x0000	), // U+1D4EF; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL F
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'G'	,0x2131	,0xdcd6	,0x0000	), // U+1D4D6; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL G
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'g'	,0x2131	,0xdcf0	,0x0000	), // U+1D4F0; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL G
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'H'	,0x2131	,0xdcd7	,0x0000	), // U+1D4D7; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL H
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'h'	,0x2131	,0xdcf1	,0x0000	), // U+1D4F1; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL H
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'I'	,0x2131	,0xdcd8	,0x0000	), // U+1D4D8; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL I
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'i'	,0x2131	,0xdcf2	,0x0000	), // U+1D4F2; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL I
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'J'	,0x2131	,0xdcd9	,0x0000	), // U+1D4D9; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL J
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'j'	,0x2131	,0xdcf3	,0x0000	), // U+1D4F3; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL J
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'K'	,0x2131	,0xdcda	,0x0000	), // U+1D4DA; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL K
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'k'	,0x2131	,0xdcf4	,0x0000	), // U+1D4F4; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL K
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'L'	,0x2131	,0xdcdb	,0x0000	), // U+1D4DB; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL L
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'l'	,0x2131	,0xdcf5	,0x0000	), // U+1D4F5; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL L
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'M'	,0x2131	,0xdcdc	,0x0000	), // U+1D4DC; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL M
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'm'	,0x2131	,0xdcf6	,0x0000	), // U+1D4F6; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL M
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'N'	,0x2131	,0xdcdd	,0x0000	), // U+1D4DD; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL N
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'n'	,0x2131	,0xdcf7	,0x0000	), // U+1D4F7; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL N
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'O'	,0x2131	,0xdcde	,0x0000	), // U+1D4DE; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL O
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'o'	,0x2131	,0xdcf8	,0x0000	), // U+1D4F8; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL O
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'P'	,0x2131	,0xdcdf	,0x0000	), // U+1D4DF; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL P
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'p'	,0x2131	,0xdcf9	,0x0000	), // U+1D4F9; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL P
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'Q'	,0x2131	,0xdce0	,0x0000	), // U+1D4E0; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL Q
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'q'	,0x2131	,0xdcfa	,0x0000	), // U+1D4FA; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL Q
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'R'	,0x2131	,0xdce1	,0x0000	), // U+1D4E1; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL R
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'r'	,0x2131	,0xdcfb	,0x0000	), // U+1D4FB; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL R
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'S'	,0x2131	,0xdce2	,0x0000	), // U+1D4E2; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL S
/*M_BOLD_SCRIPT      */	DEADTRANS(	L's'	,0x2131	,0xdcfc	,0x0000	), // U+1D4FC; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL S
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'T'	,0x2131	,0xdce3	,0x0000	), // U+1D4E3; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL T
/*M_BOLD_SCRIPT      */	DEADTRANS(	L't'	,0x2131	,0xdcfd	,0x0000	), // U+1D4FD; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL T
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'U'	,0x2131	,0xdce4	,0x0000	), // U+1D4E4; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL U
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'u'	,0x2131	,0xdcfe	,0x0000	), // U+1D4FE; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL U
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'V'	,0x2131	,0xdce5	,0x0000	), // U+1D4E5; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL V
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'v'	,0x2131	,0xdcff	,0x0000	), // U+1D4FF; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL V
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'W'	,0x2131	,0xdce6	,0x0000	), // U+1D4E6; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL W
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'w'	,0x2131	,0xdd00	,0x0000	), // U+1D500; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL W
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'X'	,0x2131	,0xdce7	,0x0000	), // U+1D4E7; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL X
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'x'	,0x2131	,0xdd01	,0x0000	), // U+1D501; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL X
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'Y'	,0x2131	,0xdce8	,0x0000	), // U+1D4E8; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL Y
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'y'	,0x2131	,0xdd02	,0x0000	), // U+1D502; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL Y
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'Z'	,0x2131	,0xdce9	,0x0000	), // U+1D4E9; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL Z
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'z'	,0x2131	,0xdd03	,0x0000	), // U+1D503; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL Z
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'A'	,0x2115	,0xdd38	,0x0000	), // U+1D538; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL A
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'a'	,0x2115	,0xdd52	,0x0000	), // U+1D552; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL A
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'B'	,0x2115	,0xdd39	,0x0000	), // U+1D539; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL B
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'b'	,0x2115	,0xdd53	,0x0000	), // U+1D553; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL B
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'C'	,0x2115	,0x2102	,0x0000	), // DOUBLE-STRUCK CAPITAL C
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'c'	,0x2115	,0xdd54	,0x0000	), // U+1D554; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL C
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'D'	,0x2115	,0xdd3b	,0x0000	), // U+1D53B; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL D
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'd'	,0x2115	,0xdd55	,0x0000	), // U+1D555; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL D
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'E'	,0x2115	,0xdd3c	,0x0000	), // U+1D53C; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL E
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'e'	,0x2115	,0xdd56	,0x0000	), // U+1D556; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL E
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'F'	,0x2115	,0xdd3d	,0x0000	), // U+1D53D; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL F
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'f'	,0x2115	,0xdd57	,0x0000	), // U+1D557; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL F
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'G'	,0x2115	,0xdd3e	,0x0000	), // U+1D53E; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL G
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'g'	,0x2115	,0xdd58	,0x0000	), // U+1D558; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL G
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'H'	,0x2115	,0x210d	,0x0000	), // DOUBLE-STRUCK CAPITAL H
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'h'	,0x2115	,0xdd59	,0x0000	), // U+1D559; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL H
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'I'	,0x2115	,0xdd40	,0x0000	), // U+1D540; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL I
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'i'	,0x2115	,0xdd5a	,0x0000	), // U+1D55A; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL I
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'J'	,0x2115	,0xdd41	,0x0000	), // U+1D541; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL J
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'j'	,0x2115	,0xdd5b	,0x0000	), // U+1D55B; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL J
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'K'	,0x2115	,0xdd42	,0x0000	), // U+1D542; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL K
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'k'	,0x2115	,0xdd5c	,0x0000	), // U+1D55C; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL K
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'L'	,0x2115	,0xdd43	,0x0000	), // U+1D543; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL L
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'l'	,0x2115	,0xdd5d	,0x0000	), // U+1D55D; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL L
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'M'	,0x2115	,0xdd44	,0x0000	), // U+1D544; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL M
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'm'	,0x2115	,0xdd5e	,0x0000	), // U+1D55E; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL M
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'N'	,0x2115	,0x2115	,0x0000	), // DOUBLE-STRUCK CAPITAL N
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'n'	,0x2115	,0xdd5f	,0x0000	), // U+1D55F; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL N
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'O'	,0x2115	,0xdd46	,0x0000	), // U+1D546; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL O
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'o'	,0x2115	,0xdd60	,0x0000	), // U+1D560; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL O
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'P'	,0x2115	,0x2119	,0x0000	), // DOUBLE-STRUCK CAPITAL P
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'p'	,0x2115	,0xdd61	,0x0000	), // U+1D561; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL P
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'Q'	,0x2115	,0x211a	,0x0000	), // DOUBLE-STRUCK CAPITAL Q
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'q'	,0x2115	,0xdd62	,0x0000	), // U+1D562; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL Q
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'R'	,0x2115	,0x211d	,0x0000	), // DOUBLE-STRUCK CAPITAL R
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'r'	,0x2115	,0xdd63	,0x0000	), // U+1D563; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL R
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'S'	,0x2115	,0xdd4a	,0x0000	), // U+1D54A; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL S
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L's'	,0x2115	,0xdd64	,0x0000	), // U+1D564; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL S
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'T'	,0x2115	,0xdd4b	,0x0000	), // U+1D54B; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL T
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L't'	,0x2115	,0xdd65	,0x0000	), // U+1D565; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL T
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'U'	,0x2115	,0xdd4c	,0x0000	), // U+1D54C; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL U
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'u'	,0x2115	,0xdd66	,0x0000	), // U+1D566; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL U
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'V'	,0x2115	,0xdd4d	,0x0000	), // U+1D54D; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL V
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'v'	,0x2115	,0xdd67	,0x0000	), // U+1D567; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL V
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'W'	,0x2115	,0xdd4e	,0x0000	), // U+1D54E; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL W
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'w'	,0x2115	,0xdd68	,0x0000	), // U+1D568; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL W
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'X'	,0x2115	,0xdd4f	,0x0000	), // U+1D54F; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL X
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'x'	,0x2115	,0xdd69	,0x0000	), // U+1D569; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL X
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'Y'	,0x2115	,0xdd50	,0x0000	), // U+1D550; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL Y
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'y'	,0x2115	,0xdd6a	,0x0000	), // U+1D56A; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL Y
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'Z'	,0x2115	,0x2124	,0x0000	), // DOUBLE-STRUCK CAPITAL Z
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'z'	,0x2115	,0xdd6b	,0x0000	), // U+1D56B; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL Z
/*M_FRAKTUR          */	DEADTRANS(	L'A'	,0x212d	,0xdd04	,0x0000	), // U+1D504; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL A
/*M_FRAKTUR          */	DEADTRANS(	L'a'	,0x212d	,0xdd1e	,0x0000	), // U+1D51E; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL A
/*M_FRAKTUR          */	DEADTRANS(	L'B'	,0x212d	,0xdd05	,0x0000	), // U+1D505; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL B
/*M_FRAKTUR          */	DEADTRANS(	L'b'	,0x212d	,0xdd1f	,0x0000	), // U+1D51F; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL B
/*M_FRAKTUR          */	DEADTRANS(	L'C'	,0x212d	,0x212d	,0x0000	), // BLACK-LETTER CAPITAL C
/*M_FRAKTUR          */	DEADTRANS(	L'c'	,0x212d	,0xdd20	,0x0000	), // U+1D520; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL C
/*M_FRAKTUR          */	DEADTRANS(	L'D'	,0x212d	,0xdd07	,0x0000	), // U+1D507; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL D
/*M_FRAKTUR          */	DEADTRANS(	L'd'	,0x212d	,0xdd21	,0x0000	), // U+1D521; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL D
/*M_FRAKTUR          */	DEADTRANS(	L'E'	,0x212d	,0xdd08	,0x0000	), // U+1D508; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL E
/*M_FRAKTUR          */	DEADTRANS(	L'e'	,0x212d	,0xdd22	,0x0000	), // U+1D522; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL E
/*M_FRAKTUR          */	DEADTRANS(	L'F'	,0x212d	,0xdd09	,0x0000	), // U+1D509; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL F
/*M_FRAKTUR          */	DEADTRANS(	L'f'	,0x212d	,0xdd23	,0x0000	), // U+1D523; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL F
/*M_FRAKTUR          */	DEADTRANS(	L'G'	,0x212d	,0xdd0a	,0x0000	), // U+1D50A; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL G
/*M_FRAKTUR          */	DEADTRANS(	L'g'	,0x212d	,0xdd24	,0x0000	), // U+1D524; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL G
/*M_FRAKTUR          */	DEADTRANS(	L'H'	,0x212d	,0x210c	,0x0000	), // BLACK-LETTER CAPITAL H
/*M_FRAKTUR          */	DEADTRANS(	L'h'	,0x212d	,0xdd25	,0x0000	), // U+1D525; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL H
/*M_FRAKTUR          */	DEADTRANS(	L'I'	,0x212d	,0x2111	,0x0000	), // BLACK-LETTER CAPITAL I
/*M_FRAKTUR          */	DEADTRANS(	L'i'	,0x212d	,0xdd26	,0x0000	), // U+1D526; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL I
/*M_FRAKTUR          */	DEADTRANS(	L'J'	,0x212d	,0xdd0d	,0x0000	), // U+1D50D; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL J
/*M_FRAKTUR          */	DEADTRANS(	L'j'	,0x212d	,0xdd27	,0x0000	), // U+1D527; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL J
/*M_FRAKTUR          */	DEADTRANS(	L'K'	,0x212d	,0xdd0e	,0x0000	), // U+1D50E; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL K
/*M_FRAKTUR          */	DEADTRANS(	L'k'	,0x212d	,0xdd28	,0x0000	), // U+1D528; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL K
/*M_FRAKTUR          */	DEADTRANS(	L'L'	,0x212d	,0xdd0f	,0x0000	), // U+1D50F; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL L
/*M_FRAKTUR          */	DEADTRANS(	L'l'	,0x212d	,0xdd29	,0x0000	), // U+1D529; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL L
/*M_FRAKTUR          */	DEADTRANS(	L'M'	,0x212d	,0xdd10	,0x0000	), // U+1D510; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL M
/*M_FRAKTUR          */	DEADTRANS(	L'm'	,0x212d	,0xdd2a	,0x0000	), // U+1D52A; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL M
/*M_FRAKTUR          */	DEADTRANS(	L'N'	,0x212d	,0xdd11	,0x0000	), // U+1D511; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL N
/*M_FRAKTUR          */	DEADTRANS(	L'n'	,0x212d	,0xdd2b	,0x0000	), // U+1D52B; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL N
/*M_FRAKTUR          */	DEADTRANS(	L'O'	,0x212d	,0xdd12	,0x0000	), // U+1D512; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL O
/*M_FRAKTUR          */	DEADTRANS(	L'o'	,0x212d	,0xdd2c	,0x0000	), // U+1D52C; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL O
/*M_FRAKTUR          */	DEADTRANS(	L'P'	,0x212d	,0xdd13	,0x0000	), // U+1D513; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL P
/*M_FRAKTUR          */	DEADTRANS(	L'p'	,0x212d	,0xdd2d	,0x0000	), // U+1D52D; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL P
/*M_FRAKTUR          */	DEADTRANS(	L'Q'	,0x212d	,0xdd14	,0x0000	), // U+1D514; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL Q
/*M_FRAKTUR          */	DEADTRANS(	L'q'	,0x212d	,0xdd2e	,0x0000	), // U+1D52E; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL Q
/*M_FRAKTUR          */	DEADTRANS(	L'R'	,0x212d	,0x211c	,0x0000	), // BLACK-LETTER CAPITAL R
/*M_FRAKTUR          */	DEADTRANS(	L'r'	,0x212d	,0xdd2f	,0x0000	), // U+1D52F; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL R
/*M_FRAKTUR          */	DEADTRANS(	L'S'	,0x212d	,0xdd16	,0x0000	), // U+1D516; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL S
/*M_FRAKTUR          */	DEADTRANS(	L's'	,0x212d	,0xdd30	,0x0000	), // U+1D530; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL S
/*M_FRAKTUR          */	DEADTRANS(	L'T'	,0x212d	,0xdd17	,0x0000	), // U+1D517; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL T
/*M_FRAKTUR          */	DEADTRANS(	L't'	,0x212d	,0xdd31	,0x0000	), // U+1D531; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL T
/*M_FRAKTUR          */	DEADTRANS(	L'U'	,0x212d	,0xdd18	,0x0000	), // U+1D518; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL U
/*M_FRAKTUR          */	DEADTRANS(	L'u'	,0x212d	,0xdd32	,0x0000	), // U+1D532; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL U
/*M_FRAKTUR          */	DEADTRANS(	L'V'	,0x212d	,0xdd19	,0x0000	), // U+1D519; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL V
/*M_FRAKTUR          */	DEADTRANS(	L'v'	,0x212d	,0xdd33	,0x0000	), // U+1D533; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL V
/*M_FRAKTUR          */	DEADTRANS(	L'W'	,0x212d	,0xdd1a	,0x0000	), // U+1D51A; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL W
/*M_FRAKTUR          */	DEADTRANS(	L'w'	,0x212d	,0xdd34	,0x0000	), // U+1D534; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL W
/*M_FRAKTUR          */	DEADTRANS(	L'X'	,0x212d	,0xdd1b	,0x0000	), // U+1D51B; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL X
/*M_FRAKTUR          */	DEADTRANS(	L'x'	,0x212d	,0xdd35	,0x0000	), // U+1D535; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL X
/*M_FRAKTUR          */	DEADTRANS(	L'Y'	,0x212d	,0xdd1c	,0x0000	), // U+1D51C; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL Y
/*M_FRAKTUR          */	DEADTRANS(	L'y'	,0x212d	,0xdd36	,0x0000	), // U+1D536; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL Y
/*M_FRAKTUR          */	DEADTRANS(	L'Z'	,0x212d	,0x2128	,0x0000	), // BLACK-LETTER CAPITAL Z
/*M_FRAKTUR          */	DEADTRANS(	L'z'	,0x212d	,0xdd37	,0x0000	), // U+1D537; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL Z
/*M_FRAKTUR          */	DEADTRANS(	0x002a	,0x212d	,0x211c	,0x0001	), // BLACK-LETTER CAPITAL R
/*M_ITALIC           */	DEADTRANS(	L'A'	,0x210e	,0xdc34	,0x0000	), // U+1D434; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL A
/*M_ITALIC           */	DEADTRANS(	L'a'	,0x210e	,0xdc4e	,0x0000	), // U+1D44E; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL A
/*M_ITALIC           */	DEADTRANS(	L'B'	,0x210e	,0xdc35	,0x0000	), // U+1D435; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL B
/*M_ITALIC           */	DEADTRANS(	L'b'	,0x210e	,0xdc4f	,0x0000	), // U+1D44F; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL B
/*M_ITALIC           */	DEADTRANS(	L'C'	,0x210e	,0xdc36	,0x0000	), // U+1D436; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL C
/*M_ITALIC           */	DEADTRANS(	L'c'	,0x210e	,0xdc50	,0x0000	), // U+1D450; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL C
/*M_ITALIC           */	DEADTRANS(	L'D'	,0x210e	,0xdc37	,0x0000	), // U+1D437; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL D
/*M_ITALIC           */	DEADTRANS(	L'd'	,0x210e	,0xdc51	,0x0000	), // U+1D451; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL D
/*M_ITALIC           */	DEADTRANS(	L'E'	,0x210e	,0xdc38	,0x0000	), // U+1D438; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL E
/*M_ITALIC           */	DEADTRANS(	L'e'	,0x210e	,0xdc52	,0x0000	), // U+1D452; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL E
/*M_ITALIC           */	DEADTRANS(	L'F'	,0x210e	,0xdc39	,0x0000	), // U+1D439; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL F
/*M_ITALIC           */	DEADTRANS(	L'f'	,0x210e	,0xdc53	,0x0000	), // U+1D453; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL F
/*M_ITALIC           */	DEADTRANS(	L'G'	,0x210e	,0xdc3a	,0x0000	), // U+1D43A; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL G
/*M_ITALIC           */	DEADTRANS(	L'g'	,0x210e	,0xdc54	,0x0000	), // U+1D454; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL G
/*M_ITALIC           */	DEADTRANS(	L'H'	,0x210e	,0xdc3b	,0x0000	), // U+1D43B; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL H
/*M_ITALIC           */	DEADTRANS(	L'h'	,0x210e	,0x210e	,0x0000	), // PLANCK CONSTANT
/*M_ITALIC           */	DEADTRANS(	L'I'	,0x210e	,0xdc3c	,0x0000	), // U+1D43C; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL I
/*M_ITALIC           */	DEADTRANS(	L'i'	,0x210e	,0xdc56	,0x0000	), // U+1D456; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL I
/*M_ITALIC           */	DEADTRANS(	L'J'	,0x210e	,0xdc3d	,0x0000	), // U+1D43D; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL J
/*M_ITALIC           */	DEADTRANS(	L'j'	,0x210e	,0xdc57	,0x0000	), // U+1D457; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL J
/*M_ITALIC           */	DEADTRANS(	L'K'	,0x210e	,0xdc3e	,0x0000	), // U+1D43E; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL K
/*M_ITALIC           */	DEADTRANS(	L'k'	,0x210e	,0xdc58	,0x0000	), // U+1D458; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL K
/*M_ITALIC           */	DEADTRANS(	L'L'	,0x210e	,0xdc3f	,0x0000	), // U+1D43F; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL L
/*M_ITALIC           */	DEADTRANS(	L'l'	,0x210e	,0xdc59	,0x0000	), // U+1D459; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL L
/*M_ITALIC           */	DEADTRANS(	L'M'	,0x210e	,0xdc40	,0x0000	), // U+1D440; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL M
/*M_ITALIC           */	DEADTRANS(	L'm'	,0x210e	,0xdc5a	,0x0000	), // U+1D45A; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL M
/*M_ITALIC           */	DEADTRANS(	L'N'	,0x210e	,0xdc41	,0x0000	), // U+1D441; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL N
/*M_ITALIC           */	DEADTRANS(	L'n'	,0x210e	,0xdc5b	,0x0000	), // U+1D45B; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL N
/*M_ITALIC           */	DEADTRANS(	L'O'	,0x210e	,0xdc42	,0x0000	), // U+1D442; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL O
/*M_ITALIC           */	DEADTRANS(	L'o'	,0x210e	,0xdc5c	,0x0000	), // U+1D45C; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL O
/*M_ITALIC           */	DEADTRANS(	L'P'	,0x210e	,0xdc43	,0x0000	), // U+1D443; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL P
/*M_ITALIC           */	DEADTRANS(	L'p'	,0x210e	,0xdc5d	,0x0000	), // U+1D45D; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL P
/*M_ITALIC           */	DEADTRANS(	L'Q'	,0x210e	,0xdc44	,0x0000	), // U+1D444; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL Q
/*M_ITALIC           */	DEADTRANS(	L'q'	,0x210e	,0xdc5e	,0x0000	), // U+1D45E; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL Q
/*M_ITALIC           */	DEADTRANS(	L'R'	,0x210e	,0xdc45	,0x0000	), // U+1D445; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL R
/*M_ITALIC           */	DEADTRANS(	L'r'	,0x210e	,0xdc5f	,0x0000	), // U+1D45F; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL R
/*M_ITALIC           */	DEADTRANS(	L'S'	,0x210e	,0xdc46	,0x0000	), // U+1D446; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL S
/*M_ITALIC           */	DEADTRANS(	L's'	,0x210e	,0xdc60	,0x0000	), // U+1D460; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL S
/*M_ITALIC           */	DEADTRANS(	L'T'	,0x210e	,0xdc47	,0x0000	), // U+1D447; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL T
/*M_ITALIC           */	DEADTRANS(	L't'	,0x210e	,0xdc61	,0x0000	), // U+1D461; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL T
/*M_ITALIC           */	DEADTRANS(	L'U'	,0x210e	,0xdc48	,0x0000	), // U+1D448; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL U
/*M_ITALIC           */	DEADTRANS(	L'u'	,0x210e	,0xdc62	,0x0000	), // U+1D462; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL U
/*M_ITALIC           */	DEADTRANS(	L'V'	,0x210e	,0xdc49	,0x0000	), // U+1D449; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL V
/*M_ITALIC           */	DEADTRANS(	L'v'	,0x210e	,0xdc63	,0x0000	), // U+1D463; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL V
/*M_ITALIC           */	DEADTRANS(	L'W'	,0x210e	,0xdc4a	,0x0000	), // U+1D44A; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL W
/*M_ITALIC           */	DEADTRANS(	L'w'	,0x210e	,0xdc64	,0x0000	), // U+1D464; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL W
/*M_ITALIC           */	DEADTRANS(	L'X'	,0x210e	,0xdc4b	,0x0000	), // U+1D44B; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL X
/*M_ITALIC           */	DEADTRANS(	L'x'	,0x210e	,0xdc65	,0x0000	), // U+1D465; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL X
/*M_ITALIC           */	DEADTRANS(	L'Y'	,0x210e	,0xdc4c	,0x0000	), // U+1D44C; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL Y
/*M_ITALIC           */	DEADTRANS(	L'y'	,0x210e	,0xdc66	,0x0000	), // U+1D466; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL Y
/*M_ITALIC           */	DEADTRANS(	L'Z'	,0x210e	,0xdc4d	,0x0000	), // U+1D44D; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL Z
/*M_ITALIC           */	DEADTRANS(	L'z'	,0x210e	,0xdc67	,0x0000	), // U+1D467; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL Z
/*M_ITALIC           */	DEADTRANS(	0x0024	,0x210e	,0x2112	,0x0001	), // SCRIPT CAPITAL L
/*M_ITALIC           */	DEADTRANS(	0x002a	,0x210e	,0x2110	,0x0001	), // SCRIPT CAPITAL I
/*M_ITALIC           */	DEADTRANS(	0x002c	,0x210e	,0xdea5	,0x0000	), // U+1D6A5; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL DOTLESS J
/*M_ITALIC           */	DEADTRANS(	0x002e	,0x210e	,0xdea4	,0x0000	), // U+1D6A4; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL DOTLESS I
/*M_ITALIC           */	DEADTRANS(	0x003b	,0x210e	,0xdea4	,0x0000	), // U+1D6A4; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL DOTLESS I
/*M_MONOSPACE        */	DEADTRANS(	L'A'	,0x2102	,0xde70	,0x0000	), // U+1D670; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL A
/*M_MONOSPACE        */	DEADTRANS(	L'a'	,0x2102	,0xde8a	,0x0000	), // U+1D68A; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL A
/*M_MONOSPACE        */	DEADTRANS(	L'B'	,0x2102	,0xde71	,0x0000	), // U+1D671; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL B
/*M_MONOSPACE        */	DEADTRANS(	L'b'	,0x2102	,0xde8b	,0x0000	), // U+1D68B; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL B
/*M_MONOSPACE        */	DEADTRANS(	L'C'	,0x2102	,0xde72	,0x0000	), // U+1D672; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL C
/*M_MONOSPACE        */	DEADTRANS(	L'c'	,0x2102	,0xde8c	,0x0000	), // U+1D68C; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL C
/*M_MONOSPACE        */	DEADTRANS(	L'D'	,0x2102	,0xde73	,0x0000	), // U+1D673; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL D
/*M_MONOSPACE        */	DEADTRANS(	L'd'	,0x2102	,0xde8d	,0x0000	), // U+1D68D; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL D
/*M_MONOSPACE        */	DEADTRANS(	L'E'	,0x2102	,0xde74	,0x0000	), // U+1D674; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL E
/*M_MONOSPACE        */	DEADTRANS(	L'e'	,0x2102	,0xde8e	,0x0000	), // U+1D68E; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL E
/*M_MONOSPACE        */	DEADTRANS(	L'F'	,0x2102	,0xde75	,0x0000	), // U+1D675; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL F
/*M_MONOSPACE        */	DEADTRANS(	L'f'	,0x2102	,0xde8f	,0x0000	), // U+1D68F; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL F
/*M_MONOSPACE        */	DEADTRANS(	L'G'	,0x2102	,0xde76	,0x0000	), // U+1D676; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL G
/*M_MONOSPACE        */	DEADTRANS(	L'g'	,0x2102	,0xde90	,0x0000	), // U+1D690; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL G
/*M_MONOSPACE        */	DEADTRANS(	L'H'	,0x2102	,0xde77	,0x0000	), // U+1D677; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL H
/*M_MONOSPACE        */	DEADTRANS(	L'h'	,0x2102	,0xde91	,0x0000	), // U+1D691; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL H
/*M_MONOSPACE        */	DEADTRANS(	L'I'	,0x2102	,0xde78	,0x0000	), // U+1D678; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL I
/*M_MONOSPACE        */	DEADTRANS(	L'i'	,0x2102	,0xde92	,0x0000	), // U+1D692; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL I
/*M_MONOSPACE        */	DEADTRANS(	L'J'	,0x2102	,0xde79	,0x0000	), // U+1D679; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL J
/*M_MONOSPACE        */	DEADTRANS(	L'j'	,0x2102	,0xde93	,0x0000	), // U+1D693; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL J
/*M_MONOSPACE        */	DEADTRANS(	L'K'	,0x2102	,0xde7a	,0x0000	), // U+1D67A; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL K
/*M_MONOSPACE        */	DEADTRANS(	L'k'	,0x2102	,0xde94	,0x0000	), // U+1D694; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL K
/*M_MONOSPACE        */	DEADTRANS(	L'L'	,0x2102	,0xde7b	,0x0000	), // U+1D67B; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL L
/*M_MONOSPACE        */	DEADTRANS(	L'l'	,0x2102	,0xde95	,0x0000	), // U+1D695; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL L
/*M_MONOSPACE        */	DEADTRANS(	L'M'	,0x2102	,0xde7c	,0x0000	), // U+1D67C; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL M
/*M_MONOSPACE        */	DEADTRANS(	L'm'	,0x2102	,0xde96	,0x0000	), // U+1D696; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL M
/*M_MONOSPACE        */	DEADTRANS(	L'N'	,0x2102	,0xde7d	,0x0000	), // U+1D67D; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL N
/*M_MONOSPACE        */	DEADTRANS(	L'n'	,0x2102	,0xde97	,0x0000	), // U+1D697; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL N
/*M_MONOSPACE        */	DEADTRANS(	L'O'	,0x2102	,0xde7e	,0x0000	), // U+1D67E; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL O
/*M_MONOSPACE        */	DEADTRANS(	L'o'	,0x2102	,0xde98	,0x0000	), // U+1D698; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL O
/*M_MONOSPACE        */	DEADTRANS(	L'P'	,0x2102	,0xde7f	,0x0000	), // U+1D67F; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL P
/*M_MONOSPACE        */	DEADTRANS(	L'p'	,0x2102	,0xde99	,0x0000	), // U+1D699; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL P
/*M_MONOSPACE        */	DEADTRANS(	L'Q'	,0x2102	,0xde80	,0x0000	), // U+1D680; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL Q
/*M_MONOSPACE        */	DEADTRANS(	L'q'	,0x2102	,0xde9a	,0x0000	), // U+1D69A; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL Q
/*M_MONOSPACE        */	DEADTRANS(	L'R'	,0x2102	,0xde81	,0x0000	), // U+1D681; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL R
/*M_MONOSPACE        */	DEADTRANS(	L'r'	,0x2102	,0xde9b	,0x0000	), // U+1D69B; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL R
/*M_MONOSPACE        */	DEADTRANS(	L'S'	,0x2102	,0xde82	,0x0000	), // U+1D682; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL S
/*M_MONOSPACE        */	DEADTRANS(	L's'	,0x2102	,0xde9c	,0x0000	), // U+1D69C; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL S
/*M_MONOSPACE        */	DEADTRANS(	L'T'	,0x2102	,0xde83	,0x0000	), // U+1D683; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL T
/*M_MONOSPACE        */	DEADTRANS(	L't'	,0x2102	,0xde9d	,0x0000	), // U+1D69D; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL T
/*M_MONOSPACE        */	DEADTRANS(	L'U'	,0x2102	,0xde84	,0x0000	), // U+1D684; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL U
/*M_MONOSPACE        */	DEADTRANS(	L'u'	,0x2102	,0xde9e	,0x0000	), // U+1D69E; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL U
/*M_MONOSPACE        */	DEADTRANS(	L'V'	,0x2102	,0xde85	,0x0000	), // U+1D685; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL V
/*M_MONOSPACE        */	DEADTRANS(	L'v'	,0x2102	,0xde9f	,0x0000	), // U+1D69F; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL V
/*M_MONOSPACE        */	DEADTRANS(	L'W'	,0x2102	,0xde86	,0x0000	), // U+1D686; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL W
/*M_MONOSPACE        */	DEADTRANS(	L'w'	,0x2102	,0xdea0	,0x0000	), // U+1D6A0; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL W
/*M_MONOSPACE        */	DEADTRANS(	L'X'	,0x2102	,0xde87	,0x0000	), // U+1D687; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL X
/*M_MONOSPACE        */	DEADTRANS(	L'x'	,0x2102	,0xdea1	,0x0000	), // U+1D6A1; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL X
/*M_MONOSPACE        */	DEADTRANS(	L'Y'	,0x2102	,0xde88	,0x0000	), // U+1D688; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL Y
/*M_MONOSPACE        */	DEADTRANS(	L'y'	,0x2102	,0xdea2	,0x0000	), // U+1D6A2; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL Y
/*M_MONOSPACE        */	DEADTRANS(	L'Z'	,0x2102	,0xde89	,0x0000	), // U+1D689; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL Z
/*M_MONOSPACE        */	DEADTRANS(	L'z'	,0x2102	,0xdea3	,0x0000	), // U+1D6A3; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL Z
/*M_SANS             */	DEADTRANS(	L'A'	,0x210b	,0xdda0	,0x0000	), // U+1D5A0; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL A
/*M_SANS             */	DEADTRANS(	L'a'	,0x210b	,0xddba	,0x0000	), // U+1D5BA; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL A
/*M_SANS             */	DEADTRANS(	L'B'	,0x210b	,0xdda1	,0x0000	), // U+1D5A1; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL B
/*M_SANS             */	DEADTRANS(	L'b'	,0x210b	,0xddbb	,0x0000	), // U+1D5BB; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL B
/*M_SANS             */	DEADTRANS(	L'C'	,0x210b	,0xdda2	,0x0000	), // U+1D5A2; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL C
/*M_SANS             */	DEADTRANS(	L'c'	,0x210b	,0xddbc	,0x0000	), // U+1D5BC; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL C
/*M_SANS             */	DEADTRANS(	L'D'	,0x210b	,0xdda3	,0x0000	), // U+1D5A3; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL D
/*M_SANS             */	DEADTRANS(	L'd'	,0x210b	,0xddbd	,0x0000	), // U+1D5BD; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL D
/*M_SANS             */	DEADTRANS(	L'E'	,0x210b	,0xdda4	,0x0000	), // U+1D5A4; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL E
/*M_SANS             */	DEADTRANS(	L'e'	,0x210b	,0xddbe	,0x0000	), // U+1D5BE; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL E
/*M_SANS             */	DEADTRANS(	L'F'	,0x210b	,0xdda5	,0x0000	), // U+1D5A5; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL F
/*M_SANS             */	DEADTRANS(	L'f'	,0x210b	,0xddbf	,0x0000	), // U+1D5BF; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL F
/*M_SANS             */	DEADTRANS(	L'G'	,0x210b	,0xdda6	,0x0000	), // U+1D5A6; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL G
/*M_SANS             */	DEADTRANS(	L'g'	,0x210b	,0xddc0	,0x0000	), // U+1D5C0; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL G
/*M_SANS             */	DEADTRANS(	L'H'	,0x210b	,0xdda7	,0x0000	), // U+1D5A7; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL H
/*M_SANS             */	DEADTRANS(	L'h'	,0x210b	,0xddc1	,0x0000	), // U+1D5C1; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL H
/*M_SANS             */	DEADTRANS(	L'I'	,0x210b	,0xdda8	,0x0000	), // U+1D5A8; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL I
/*M_SANS             */	DEADTRANS(	L'i'	,0x210b	,0xddc2	,0x0000	), // U+1D5C2; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL I
/*M_SANS             */	DEADTRANS(	L'J'	,0x210b	,0xdda9	,0x0000	), // U+1D5A9; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL J
/*M_SANS             */	DEADTRANS(	L'j'	,0x210b	,0xddc3	,0x0000	), // U+1D5C3; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL J
/*M_SANS             */	DEADTRANS(	L'K'	,0x210b	,0xddaa	,0x0000	), // U+1D5AA; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL K
/*M_SANS             */	DEADTRANS(	L'k'	,0x210b	,0xddc4	,0x0000	), // U+1D5C4; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL K
/*M_SANS             */	DEADTRANS(	L'L'	,0x210b	,0xddab	,0x0000	), // U+1D5AB; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL L
/*M_SANS             */	DEADTRANS(	L'l'	,0x210b	,0xddc5	,0x0000	), // U+1D5C5; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL L
/*M_SANS             */	DEADTRANS(	L'M'	,0x210b	,0xddac	,0x0000	), // U+1D5AC; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL M
/*M_SANS             */	DEADTRANS(	L'm'	,0x210b	,0xddc6	,0x0000	), // U+1D5C6; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL M
/*M_SANS             */	DEADTRANS(	L'N'	,0x210b	,0xddad	,0x0000	), // U+1D5AD; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL N
/*M_SANS             */	DEADTRANS(	L'n'	,0x210b	,0xddc7	,0x0000	), // U+1D5C7; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL N
/*M_SANS             */	DEADTRANS(	L'O'	,0x210b	,0xddae	,0x0000	), // U+1D5AE; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL O
/*M_SANS             */	DEADTRANS(	L'o'	,0x210b	,0xddc8	,0x0000	), // U+1D5C8; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL O
/*M_SANS             */	DEADTRANS(	L'P'	,0x210b	,0xddaf	,0x0000	), // U+1D5AF; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL P
/*M_SANS             */	DEADTRANS(	L'p'	,0x210b	,0xddc9	,0x0000	), // U+1D5C9; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL P
/*M_SANS             */	DEADTRANS(	L'Q'	,0x210b	,0xddb0	,0x0000	), // U+1D5B0; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL Q
/*M_SANS             */	DEADTRANS(	L'q'	,0x210b	,0xddca	,0x0000	), // U+1D5CA; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL Q
/*M_SANS             */	DEADTRANS(	L'R'	,0x210b	,0xddb1	,0x0000	), // U+1D5B1; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL R
/*M_SANS             */	DEADTRANS(	L'r'	,0x210b	,0xddcb	,0x0000	), // U+1D5CB; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL R
/*M_SANS             */	DEADTRANS(	L'S'	,0x210b	,0xddb2	,0x0000	), // U+1D5B2; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL S
/*M_SANS             */	DEADTRANS(	L's'	,0x210b	,0xddcc	,0x0000	), // U+1D5CC; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL S
/*M_SANS             */	DEADTRANS(	L'T'	,0x210b	,0xddb3	,0x0000	), // U+1D5B3; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL T
/*M_SANS             */	DEADTRANS(	L't'	,0x210b	,0xddcd	,0x0000	), // U+1D5CD; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL T
/*M_SANS             */	DEADTRANS(	L'U'	,0x210b	,0xddb4	,0x0000	), // U+1D5B4; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL U
/*M_SANS             */	DEADTRANS(	L'u'	,0x210b	,0xddce	,0x0000	), // U+1D5CE; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL U
/*M_SANS             */	DEADTRANS(	L'V'	,0x210b	,0xddb5	,0x0000	), // U+1D5B5; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL V
/*M_SANS             */	DEADTRANS(	L'v'	,0x210b	,0xddcf	,0x0000	), // U+1D5CF; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL V
/*M_SANS             */	DEADTRANS(	L'W'	,0x210b	,0xddb6	,0x0000	), // U+1D5B6; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL W
/*M_SANS             */	DEADTRANS(	L'w'	,0x210b	,0xddd0	,0x0000	), // U+1D5D0; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL W
/*M_SANS             */	DEADTRANS(	L'X'	,0x210b	,0xddb7	,0x0000	), // U+1D5B7; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL X
/*M_SANS             */	DEADTRANS(	L'x'	,0x210b	,0xddd1	,0x0000	), // U+1D5D1; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL X
/*M_SANS             */	DEADTRANS(	L'Y'	,0x210b	,0xddb8	,0x0000	), // U+1D5B8; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL Y
/*M_SANS             */	DEADTRANS(	L'y'	,0x210b	,0xddd2	,0x0000	), // U+1D5D2; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL Y
/*M_SANS             */	DEADTRANS(	L'Z'	,0x210b	,0xddb9	,0x0000	), // U+1D5B9; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL Z
/*M_SANS             */	DEADTRANS(	L'z'	,0x210b	,0xddd3	,0x0000	), // U+1D5D3; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL Z
/*M_SANS             */	DEADTRANS(	0x002a	,0x210b	,0x211b	,0x0001	), // SCRIPT CAPITAL R
/*M_SANS             */	DEADTRANS(	0x002f	,0x210b	,0x2112	,0x0001	), // SCRIPT CAPITAL L
/*M_SANS_BOLD        */	DEADTRANS(	L'A'	,0x211b	,0xddd4	,0x0000	), // U+1D5D4; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL A
/*M_SANS_BOLD        */	DEADTRANS(	L'a'	,0x211b	,0xddee	,0x0000	), // U+1D5EE; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL A
/*M_SANS_BOLD        */	DEADTRANS(	L'B'	,0x211b	,0xddd5	,0x0000	), // U+1D5D5; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL B
/*M_SANS_BOLD        */	DEADTRANS(	L'b'	,0x211b	,0xddef	,0x0000	), // U+1D5EF; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL B
/*M_SANS_BOLD        */	DEADTRANS(	L'C'	,0x211b	,0xddd6	,0x0000	), // U+1D5D6; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL C
/*M_SANS_BOLD        */	DEADTRANS(	L'c'	,0x211b	,0xddf0	,0x0000	), // U+1D5F0; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL C
/*M_SANS_BOLD        */	DEADTRANS(	L'D'	,0x211b	,0xddd7	,0x0000	), // U+1D5D7; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL D
/*M_SANS_BOLD        */	DEADTRANS(	L'd'	,0x211b	,0xddf1	,0x0000	), // U+1D5F1; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL D
/*M_SANS_BOLD        */	DEADTRANS(	L'E'	,0x211b	,0xddd8	,0x0000	), // U+1D5D8; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL E
/*M_SANS_BOLD        */	DEADTRANS(	L'e'	,0x211b	,0xddf2	,0x0000	), // U+1D5F2; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL E
/*M_SANS_BOLD        */	DEADTRANS(	L'F'	,0x211b	,0xddd9	,0x0000	), // U+1D5D9; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL F
/*M_SANS_BOLD        */	DEADTRANS(	L'f'	,0x211b	,0xddf3	,0x0000	), // U+1D5F3; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL F
/*M_SANS_BOLD        */	DEADTRANS(	L'G'	,0x211b	,0xddda	,0x0000	), // U+1D5DA; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL G
/*M_SANS_BOLD        */	DEADTRANS(	L'g'	,0x211b	,0xddf4	,0x0000	), // U+1D5F4; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL G
/*M_SANS_BOLD        */	DEADTRANS(	L'H'	,0x211b	,0xdddb	,0x0000	), // U+1D5DB; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL H
/*M_SANS_BOLD        */	DEADTRANS(	L'h'	,0x211b	,0xddf5	,0x0000	), // U+1D5F5; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL H
/*M_SANS_BOLD        */	DEADTRANS(	L'I'	,0x211b	,0xdddc	,0x0000	), // U+1D5DC; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL I
/*M_SANS_BOLD        */	DEADTRANS(	L'i'	,0x211b	,0xddf6	,0x0000	), // U+1D5F6; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL I
/*M_SANS_BOLD        */	DEADTRANS(	L'J'	,0x211b	,0xdddd	,0x0000	), // U+1D5DD; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL J
/*M_SANS_BOLD        */	DEADTRANS(	L'j'	,0x211b	,0xddf7	,0x0000	), // U+1D5F7; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL J
/*M_SANS_BOLD        */	DEADTRANS(	L'K'	,0x211b	,0xddde	,0x0000	), // U+1D5DE; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL K
/*M_SANS_BOLD        */	DEADTRANS(	L'k'	,0x211b	,0xddf8	,0x0000	), // U+1D5F8; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL K
/*M_SANS_BOLD        */	DEADTRANS(	L'L'	,0x211b	,0xdddf	,0x0000	), // U+1D5DF; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL L
/*M_SANS_BOLD        */	DEADTRANS(	L'l'	,0x211b	,0xddf9	,0x0000	), // U+1D5F9; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL L
/*M_SANS_BOLD        */	DEADTRANS(	L'M'	,0x211b	,0xdde0	,0x0000	), // U+1D5E0; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL M
/*M_SANS_BOLD        */	DEADTRANS(	L'm'	,0x211b	,0xddfa	,0x0000	), // U+1D5FA; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL M
/*M_SANS_BOLD        */	DEADTRANS(	L'N'	,0x211b	,0xdde1	,0x0000	), // U+1D5E1; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL N
/*M_SANS_BOLD        */	DEADTRANS(	L'n'	,0x211b	,0xddfb	,0x0000	), // U+1D5FB; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL N
/*M_SANS_BOLD        */	DEADTRANS(	L'O'	,0x211b	,0xdde2	,0x0000	), // U+1D5E2; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL O
/*M_SANS_BOLD        */	DEADTRANS(	L'o'	,0x211b	,0xddfc	,0x0000	), // U+1D5FC; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL O
/*M_SANS_BOLD        */	DEADTRANS(	L'P'	,0x211b	,0xdde3	,0x0000	), // U+1D5E3; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL P
/*M_SANS_BOLD        */	DEADTRANS(	L'p'	,0x211b	,0xddfd	,0x0000	), // U+1D5FD; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL P
/*M_SANS_BOLD        */	DEADTRANS(	L'Q'	,0x211b	,0xdde4	,0x0000	), // U+1D5E4; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL Q
/*M_SANS_BOLD        */	DEADTRANS(	L'q'	,0x211b	,0xddfe	,0x0000	), // U+1D5FE; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL Q
/*M_SANS_BOLD        */	DEADTRANS(	L'R'	,0x211b	,0xdde5	,0x0000	), // U+1D5E5; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL R
/*M_SANS_BOLD        */	DEADTRANS(	L'r'	,0x211b	,0xddff	,0x0000	), // U+1D5FF; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL R
/*M_SANS_BOLD        */	DEADTRANS(	L'S'	,0x211b	,0xdde6	,0x0000	), // U+1D5E6; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL S
/*M_SANS_BOLD        */	DEADTRANS(	L's'	,0x211b	,0xde00	,0x0000	), // U+1D600; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL S
/*M_SANS_BOLD        */	DEADTRANS(	L'T'	,0x211b	,0xdde7	,0x0000	), // U+1D5E7; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL T
/*M_SANS_BOLD        */	DEADTRANS(	L't'	,0x211b	,0xde01	,0x0000	), // U+1D601; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL T
/*M_SANS_BOLD        */	DEADTRANS(	L'U'	,0x211b	,0xdde8	,0x0000	), // U+1D5E8; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL U
/*M_SANS_BOLD        */	DEADTRANS(	L'u'	,0x211b	,0xde02	,0x0000	), // U+1D602; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL U
/*M_SANS_BOLD        */	DEADTRANS(	L'V'	,0x211b	,0xdde9	,0x0000	), // U+1D5E9; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL V
/*M_SANS_BOLD        */	DEADTRANS(	L'v'	,0x211b	,0xde03	,0x0000	), // U+1D603; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL V
/*M_SANS_BOLD        */	DEADTRANS(	L'W'	,0x211b	,0xddea	,0x0000	), // U+1D5EA; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL W
/*M_SANS_BOLD        */	DEADTRANS(	L'w'	,0x211b	,0xde04	,0x0000	), // U+1D604; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL W
/*M_SANS_BOLD        */	DEADTRANS(	L'X'	,0x211b	,0xddeb	,0x0000	), // U+1D5EB; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL X
/*M_SANS_BOLD        */	DEADTRANS(	L'x'	,0x211b	,0xde05	,0x0000	), // U+1D605; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL X
/*M_SANS_BOLD        */	DEADTRANS(	L'Y'	,0x211b	,0xddec	,0x0000	), // U+1D5EC; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL Y
/*M_SANS_BOLD        */	DEADTRANS(	L'y'	,0x211b	,0xde06	,0x0000	), // U+1D606; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL Y
/*M_SANS_BOLD        */	DEADTRANS(	L'Z'	,0x211b	,0xdded	,0x0000	), // U+1D5ED; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL Z
/*M_SANS_BOLD        */	DEADTRANS(	L'z'	,0x211b	,0xde07	,0x0000	), // U+1D607; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL Z
/*M_SANS_BOLD        */	DEADTRANS(	0x002f	,0x211b	,0x2130	,0x0001	), // SCRIPT CAPITAL E
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'A'	,0x2130	,0xde3c	,0x0000	), // U+1D63C; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL A
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'B'	,0x2130	,0xde3d	,0x0000	), // U+1D63D; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL B
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'C'	,0x2130	,0xde3e	,0x0000	), // U+1D63E; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL C
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'D'	,0x2130	,0xde3f	,0x0000	), // U+1D63F; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL D
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'E'	,0x2130	,0xde40	,0x0000	), // U+1D640; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL E
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'F'	,0x2130	,0xde41	,0x0000	), // U+1D641; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL F
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'G'	,0x2130	,0xde42	,0x0000	), // U+1D642; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL G
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'H'	,0x2130	,0xde43	,0x0000	), // U+1D643; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL H
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'I'	,0x2130	,0xde44	,0x0000	), // U+1D644; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL I
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'J'	,0x2130	,0xde45	,0x0000	), // U+1D645; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL J
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'K'	,0x2130	,0xde46	,0x0000	), // U+1D646; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL K
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'L'	,0x2130	,0xde47	,0x0000	), // U+1D647; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL L
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'M'	,0x2130	,0xde48	,0x0000	), // U+1D648; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL M
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'N'	,0x2130	,0xde49	,0x0000	), // U+1D649; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL N
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'O'	,0x2130	,0xde4a	,0x0000	), // U+1D64A; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL O
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'P'	,0x2130	,0xde4b	,0x0000	), // U+1D64B; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL P
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'Q'	,0x2130	,0xde4c	,0x0000	), // U+1D64C; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL Q
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'R'	,0x2130	,0xde4d	,0x0000	), // U+1D64D; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL R
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'S'	,0x2130	,0xde4e	,0x0000	), // U+1D64E; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL S
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'T'	,0x2130	,0xde4f	,0x0000	), // U+1D64F; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL T
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'U'	,0x2130	,0xde50	,0x0000	), // U+1D650; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL U
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'V'	,0x2130	,0xde51	,0x0000	), // U+1D651; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL V
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'W'	,0x2130	,0xde52	,0x0000	), // U+1D652; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL W
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'X'	,0x2130	,0xde53	,0x0000	), // U+1D653; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL X
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'Y'	,0x2130	,0xde54	,0x0000	), // U+1D654; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL Y
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'Z'	,0x2130	,0xde55	,0x0000	), // U+1D655; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL Z
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'a'	,0x2130	,0xde56	,0x0000	), // U+1D656; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL A
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'b'	,0x2130	,0xde57	,0x0000	), // U+1D657; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL B
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'c'	,0x2130	,0xde58	,0x0000	), // U+1D658; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL C
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'd'	,0x2130	,0xde59	,0x0000	), // U+1D659; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL D
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'e'	,0x2130	,0xde5a	,0x0000	), // U+1D65A; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL E
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'f'	,0x2130	,0xde5b	,0x0000	), // U+1D65B; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL F
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'g'	,0x2130	,0xde5c	,0x0000	), // U+1D65C; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL G
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'h'	,0x2130	,0xde5d	,0x0000	), // U+1D65D; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL H
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'i'	,0x2130	,0xde5e	,0x0000	), // U+1D65E; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL I
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'j'	,0x2130	,0xde5f	,0x0000	), // U+1D65F; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL J
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'k'	,0x2130	,0xde60	,0x0000	), // U+1D660; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL K
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'l'	,0x2130	,0xde61	,0x0000	), // U+1D661; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL L
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'm'	,0x2130	,0xde62	,0x0000	), // U+1D662; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL M
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'n'	,0x2130	,0xde63	,0x0000	), // U+1D663; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL N
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'o'	,0x2130	,0xde64	,0x0000	), // U+1D664; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL O
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'p'	,0x2130	,0xde65	,0x0000	), // U+1D665; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL P
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'q'	,0x2130	,0xde66	,0x0000	), // U+1D666; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL Q
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'r'	,0x2130	,0xde67	,0x0000	), // U+1D667; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL R
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L's'	,0x2130	,0xde68	,0x0000	), // U+1D668; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL S
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L't'	,0x2130	,0xde69	,0x0000	), // U+1D669; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL T
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'u'	,0x2130	,0xde6a	,0x0000	), // U+1D66A; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL U
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'v'	,0x2130	,0xde6b	,0x0000	), // U+1D66B; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL V
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'w'	,0x2130	,0xde6c	,0x0000	), // U+1D66C; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL W
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'x'	,0x2130	,0xde6d	,0x0000	), // U+1D66D; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL X
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'y'	,0x2130	,0xde6e	,0x0000	), // U+1D66E; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL Y
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'z'	,0x2130	,0xde6f	,0x0000	), // U+1D66F; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL Z
/*M_SANS_ITALIC      */	DEADTRANS(	L'A'	,0x2112	,0xde08	,0x0000	), // U+1D608; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL A
/*M_SANS_ITALIC      */	DEADTRANS(	L'a'	,0x2112	,0xde22	,0x0000	), // U+1D622; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL A
/*M_SANS_ITALIC      */	DEADTRANS(	L'B'	,0x2112	,0xde09	,0x0000	), // U+1D609; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL B
/*M_SANS_ITALIC      */	DEADTRANS(	L'b'	,0x2112	,0xde23	,0x0000	), // U+1D623; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL B
/*M_SANS_ITALIC      */	DEADTRANS(	L'C'	,0x2112	,0xde0a	,0x0000	), // U+1D60A; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL C
/*M_SANS_ITALIC      */	DEADTRANS(	L'c'	,0x2112	,0xde24	,0x0000	), // U+1D624; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL C
/*M_SANS_ITALIC      */	DEADTRANS(	L'D'	,0x2112	,0xde0b	,0x0000	), // U+1D60B; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL D
/*M_SANS_ITALIC      */	DEADTRANS(	L'd'	,0x2112	,0xde25	,0x0000	), // U+1D625; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL D
/*M_SANS_ITALIC      */	DEADTRANS(	L'E'	,0x2112	,0xde0c	,0x0000	), // U+1D60C; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL E
/*M_SANS_ITALIC      */	DEADTRANS(	L'e'	,0x2112	,0xde26	,0x0000	), // U+1D626; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL E
/*M_SANS_ITALIC      */	DEADTRANS(	L'F'	,0x2112	,0xde0d	,0x0000	), // U+1D60D; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL F
/*M_SANS_ITALIC      */	DEADTRANS(	L'f'	,0x2112	,0xde27	,0x0000	), // U+1D627; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL F
/*M_SANS_ITALIC      */	DEADTRANS(	L'G'	,0x2112	,0xde0e	,0x0000	), // U+1D60E; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL G
/*M_SANS_ITALIC      */	DEADTRANS(	L'g'	,0x2112	,0xde28	,0x0000	), // U+1D628; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL G
/*M_SANS_ITALIC      */	DEADTRANS(	L'H'	,0x2112	,0xde0f	,0x0000	), // U+1D60F; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL H
/*M_SANS_ITALIC      */	DEADTRANS(	L'h'	,0x2112	,0xde29	,0x0000	), // U+1D629; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL H
/*M_SANS_ITALIC      */	DEADTRANS(	L'I'	,0x2112	,0xde10	,0x0000	), // U+1D610; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL I
/*M_SANS_ITALIC      */	DEADTRANS(	L'i'	,0x2112	,0xde2a	,0x0000	), // U+1D62A; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL I
/*M_SANS_ITALIC      */	DEADTRANS(	L'J'	,0x2112	,0xde11	,0x0000	), // U+1D611; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL J
/*M_SANS_ITALIC      */	DEADTRANS(	L'j'	,0x2112	,0xde2b	,0x0000	), // U+1D62B; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL J
/*M_SANS_ITALIC      */	DEADTRANS(	L'K'	,0x2112	,0xde12	,0x0000	), // U+1D612; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL K
/*M_SANS_ITALIC      */	DEADTRANS(	L'k'	,0x2112	,0xde2c	,0x0000	), // U+1D62C; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL K
/*M_SANS_ITALIC      */	DEADTRANS(	L'L'	,0x2112	,0xde13	,0x0000	), // U+1D613; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL L
/*M_SANS_ITALIC      */	DEADTRANS(	L'l'	,0x2112	,0xde2d	,0x0000	), // U+1D62D; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL L
/*M_SANS_ITALIC      */	DEADTRANS(	L'M'	,0x2112	,0xde14	,0x0000	), // U+1D614; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL M
/*M_SANS_ITALIC      */	DEADTRANS(	L'm'	,0x2112	,0xde2e	,0x0000	), // U+1D62E; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL M
/*M_SANS_ITALIC      */	DEADTRANS(	L'N'	,0x2112	,0xde15	,0x0000	), // U+1D615; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL N
/*M_SANS_ITALIC      */	DEADTRANS(	L'n'	,0x2112	,0xde2f	,0x0000	), // U+1D62F; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL N
/*M_SANS_ITALIC      */	DEADTRANS(	L'O'	,0x2112	,0xde16	,0x0000	), // U+1D616; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL O
/*M_SANS_ITALIC      */	DEADTRANS(	L'o'	,0x2112	,0xde30	,0x0000	), // U+1D630; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL O
/*M_SANS_ITALIC      */	DEADTRANS(	L'P'	,0x2112	,0xde17	,0x0000	), // U+1D617; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL P
/*M_SANS_ITALIC      */	DEADTRANS(	L'p'	,0x2112	,0xde31	,0x0000	), // U+1D631; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL P
/*M_SANS_ITALIC      */	DEADTRANS(	L'Q'	,0x2112	,0xde18	,0x0000	), // U+1D618; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL Q
/*M_SANS_ITALIC      */	DEADTRANS(	L'q'	,0x2112	,0xde32	,0x0000	), // U+1D632; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL Q
/*M_SANS_ITALIC      */	DEADTRANS(	L'R'	,0x2112	,0xde19	,0x0000	), // U+1D619; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL R
/*M_SANS_ITALIC      */	DEADTRANS(	L'r'	,0x2112	,0xde33	,0x0000	), // U+1D633; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL R
/*M_SANS_ITALIC      */	DEADTRANS(	L'S'	,0x2112	,0xde1a	,0x0000	), // U+1D61A; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL S
/*M_SANS_ITALIC      */	DEADTRANS(	L's'	,0x2112	,0xde34	,0x0000	), // U+1D634; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL S
/*M_SANS_ITALIC      */	DEADTRANS(	L'T'	,0x2112	,0xde1b	,0x0000	), // U+1D61B; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL T
/*M_SANS_ITALIC      */	DEADTRANS(	L't'	,0x2112	,0xde35	,0x0000	), // U+1D635; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL T
/*M_SANS_ITALIC      */	DEADTRANS(	L'U'	,0x2112	,0xde1c	,0x0000	), // U+1D61C; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL U
/*M_SANS_ITALIC      */	DEADTRANS(	L'u'	,0x2112	,0xde36	,0x0000	), // U+1D636; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL U
/*M_SANS_ITALIC      */	DEADTRANS(	L'V'	,0x2112	,0xde1d	,0x0000	), // U+1D61D; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL V
/*M_SANS_ITALIC      */	DEADTRANS(	L'v'	,0x2112	,0xde37	,0x0000	), // U+1D637; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL V
/*M_SANS_ITALIC      */	DEADTRANS(	L'W'	,0x2112	,0xde1e	,0x0000	), // U+1D61E; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL W
/*M_SANS_ITALIC      */	DEADTRANS(	L'w'	,0x2112	,0xde38	,0x0000	), // U+1D638; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL W
/*M_SANS_ITALIC      */	DEADTRANS(	L'X'	,0x2112	,0xde1f	,0x0000	), // U+1D61F; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL X
/*M_SANS_ITALIC      */	DEADTRANS(	L'x'	,0x2112	,0xde39	,0x0000	), // U+1D639; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL X
/*M_SANS_ITALIC      */	DEADTRANS(	L'Y'	,0x2112	,0xde20	,0x0000	), // U+1D620; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL Y
/*M_SANS_ITALIC      */	DEADTRANS(	L'y'	,0x2112	,0xde3a	,0x0000	), // U+1D63A; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL Y
/*M_SANS_ITALIC      */	DEADTRANS(	L'Z'	,0x2112	,0xde21	,0x0000	), // U+1D621; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL Z
/*M_SANS_ITALIC      */	DEADTRANS(	L'z'	,0x2112	,0xde3b	,0x0000	), // U+1D63B; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL Z
/*M_SANS_ITALIC      */	DEADTRANS(	0x002a	,0x2112	,0x2130	,0x0001	), // SCRIPT CAPITAL E
/*M_SCRIPT           */	DEADTRANS(	L'A'	,0x212f	,0xdc9c	,0x0000	), // U+1D49C; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL A
/*M_SCRIPT           */	DEADTRANS(	L'a'	,0x212f	,0xdcb6	,0x0000	), // U+1D4B6; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL A
/*M_SCRIPT           */	DEADTRANS(	L'B'	,0x212f	,0x212c	,0x0000	), // SCRIPT CAPITAL B
/*M_SCRIPT           */	DEADTRANS(	L'b'	,0x212f	,0xdcb7	,0x0000	), // U+1D4B7; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL B
/*M_SCRIPT           */	DEADTRANS(	L'C'	,0x212f	,0xdc9e	,0x0000	), // U+1D49E; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL C
/*M_SCRIPT           */	DEADTRANS(	L'c'	,0x212f	,0xdcb8	,0x0000	), // U+1D4B8; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL C
/*M_SCRIPT           */	DEADTRANS(	L'D'	,0x212f	,0xdc9f	,0x0000	), // U+1D49F; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL D
/*M_SCRIPT           */	DEADTRANS(	L'd'	,0x212f	,0xdcb9	,0x0000	), // U+1D4B9; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL D
/*M_SCRIPT           */	DEADTRANS(	L'E'	,0x212f	,0x2130	,0x0000	), // SCRIPT CAPITAL E
/*M_SCRIPT           */	DEADTRANS(	L'e'	,0x212f	,0x212f	,0x0000	), // SCRIPT SMALL E
/*M_SCRIPT           */	DEADTRANS(	L'F'	,0x212f	,0x2131	,0x0000	), // SCRIPT CAPITAL F
/*M_SCRIPT           */	DEADTRANS(	L'f'	,0x212f	,0xdcbb	,0x0000	), // U+1D4BB; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL F
/*M_SCRIPT           */	DEADTRANS(	L'G'	,0x212f	,0xdca2	,0x0000	), // U+1D4A2; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL G
/*M_SCRIPT           */	DEADTRANS(	L'g'	,0x212f	,0x210a	,0x0000	), // SCRIPT SMALL G
/*M_SCRIPT           */	DEADTRANS(	L'H'	,0x212f	,0x210b	,0x0000	), // SCRIPT CAPITAL H
/*M_SCRIPT           */	DEADTRANS(	L'h'	,0x212f	,0xdcbd	,0x0000	), // U+1D4BD; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL H
/*M_SCRIPT           */	DEADTRANS(	L'I'	,0x212f	,0x2110	,0x0000	), // SCRIPT CAPITAL I
/*M_SCRIPT           */	DEADTRANS(	L'i'	,0x212f	,0xdcbe	,0x0000	), // U+1D4BE; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL I
/*M_SCRIPT           */	DEADTRANS(	L'J'	,0x212f	,0xdca5	,0x0000	), // U+1D4A5; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL J
/*M_SCRIPT           */	DEADTRANS(	L'j'	,0x212f	,0xdcbf	,0x0000	), // U+1D4BF; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL J
/*M_SCRIPT           */	DEADTRANS(	L'K'	,0x212f	,0xdca6	,0x0000	), // U+1D4A6; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL K
/*M_SCRIPT           */	DEADTRANS(	L'k'	,0x212f	,0xdcc0	,0x0000	), // U+1D4C0; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL K
/*M_SCRIPT           */	DEADTRANS(	L'L'	,0x212f	,0x2112	,0x0000	), // SCRIPT CAPITAL L
/*M_SCRIPT           */	DEADTRANS(	L'l'	,0x212f	,0xdcc1	,0x0000	), // U+1D4C1; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL L
/*M_SCRIPT           */	DEADTRANS(	L'M'	,0x212f	,0x2133	,0x0000	), // SCRIPT CAPITAL M
/*M_SCRIPT           */	DEADTRANS(	L'm'	,0x212f	,0xdcc2	,0x0000	), // U+1D4C2; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL M
/*M_SCRIPT           */	DEADTRANS(	L'N'	,0x212f	,0xdca9	,0x0000	), // U+1D4A9; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL N
/*M_SCRIPT           */	DEADTRANS(	L'n'	,0x212f	,0xdcc3	,0x0000	), // U+1D4C3; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL N
/*M_SCRIPT           */	DEADTRANS(	L'O'	,0x212f	,0xdcaa	,0x0000	), // U+1D4AA; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL O
/*M_SCRIPT           */	DEADTRANS(	L'o'	,0x212f	,0x2134	,0x0000	), // SCRIPT SMALL O
/*M_SCRIPT           */	DEADTRANS(	L'P'	,0x212f	,0xdcab	,0x0000	), // U+1D4AB; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL P
/*M_SCRIPT           */	DEADTRANS(	L'p'	,0x212f	,0xdcc5	,0x0000	), // U+1D4C5; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL P
/*M_SCRIPT           */	DEADTRANS(	L'Q'	,0x212f	,0xdcac	,0x0000	), // U+1D4AC; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL Q
/*M_SCRIPT           */	DEADTRANS(	L'q'	,0x212f	,0xdcc6	,0x0000	), // U+1D4C6; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL Q
/*M_SCRIPT           */	DEADTRANS(	L'R'	,0x212f	,0x211b	,0x0000	), // SCRIPT CAPITAL R
/*M_SCRIPT           */	DEADTRANS(	L'r'	,0x212f	,0xdcc7	,0x0000	), // U+1D4C7; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL R
/*M_SCRIPT           */	DEADTRANS(	L'S'	,0x212f	,0xdcae	,0x0000	), // U+1D4AE; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL S
/*M_SCRIPT           */	DEADTRANS(	L's'	,0x212f	,0xdcc8	,0x0000	), // U+1D4C8; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL S
/*M_SCRIPT           */	DEADTRANS(	L'T'	,0x212f	,0xdcaf	,0x0000	), // U+1D4AF; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL T
/*M_SCRIPT           */	DEADTRANS(	L't'	,0x212f	,0xdcc9	,0x0000	), // U+1D4C9; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL T
/*M_SCRIPT           */	DEADTRANS(	L'U'	,0x212f	,0xdcb0	,0x0000	), // U+1D4B0; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL U
/*M_SCRIPT           */	DEADTRANS(	L'u'	,0x212f	,0xdcca	,0x0000	), // U+1D4CA; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL U
/*M_SCRIPT           */	DEADTRANS(	L'V'	,0x212f	,0xdcb1	,0x0000	), // U+1D4B1; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL V
/*M_SCRIPT           */	DEADTRANS(	L'v'	,0x212f	,0xdccb	,0x0000	), // U+1D4CB; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL V
/*M_SCRIPT           */	DEADTRANS(	L'W'	,0x212f	,0xdcb2	,0x0000	), // U+1D4B2; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL W
/*M_SCRIPT           */	DEADTRANS(	L'w'	,0x212f	,0xdccc	,0x0000	), // U+1D4CC; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL W
/*M_SCRIPT           */	DEADTRANS(	L'X'	,0x212f	,0xdcb3	,0x0000	), // U+1D4B3; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL X
/*M_SCRIPT           */	DEADTRANS(	L'x'	,0x212f	,0xdccd	,0x0000	), // U+1D4CD; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL X
/*M_SCRIPT           */	DEADTRANS(	L'Y'	,0x212f	,0xdcb4	,0x0000	), // U+1D4B4; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL Y
/*M_SCRIPT           */	DEADTRANS(	L'y'	,0x212f	,0xdcce	,0x0000	), // U+1D4CE; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL Y
/*M_SCRIPT           */	DEADTRANS(	L'Z'	,0x212f	,0xdcb5	,0x0000	), // U+1D4B5; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL Z
/*M_SCRIPT           */	DEADTRANS(	L'z'	,0x212f	,0xdccf	,0x0000	), // U+1D4CF; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL Z
/*M_SCRIPT           */	DEADTRANS(	0x002a	,0x212f	,0x2131	,0x0001	), // SCRIPT CAPITAL F
/*MACRON             */	DEADTRANS(	0x0020	,0x02cd	,0x0331	,0x0000	), // COMBINING MACRON BELOW
/*MACRON             */	DEADTRANS(	0x0020	,0x0101	,0x0304	,0x0000	), // COMBINING MACRON
/*MACRON             */	DEADTRANS(	0x0028	,0x0101	,0x1dcc	,0x0000	), // COMBINING MACRON-BREVE
/*MACRON             */	DEADTRANS(	0x005f	,0x0101	,0x0332	,0x0000	), // COMBINING LOW LINE
/*MACRON             */	DEADTRANS(	0x0020	,0x1e53	,0x1dc4	,0x0000	), // COMBINING MACRON-ACUTE
/*MACRON             */	DEADTRANS(	0x0020	,0x1e51	,0x1dc6	,0x0000	), // COMBINING MACRON-GRAVE
/*MACRON             */	DEADTRANS(	0x002a	,0x0101	,0x02c9	,0x0000	), // MODIFIER LETTER MACRON
/*MACRON             */	DEADTRANS(	0x202f	,0x02cd	,0x02cd	,0x0000	), // MODIFIER LETTER LOW MACRON
/*MACRON             */	DEADTRANS(	0x00a0	,0x0101	,0x00af	,0x0000	), // MACRON
/*MACRON             */	DEADTRANS(	L'A'	,0x0101	,0x0100	,0x0000	), // LATIN CAPITAL LETTER A WITH MACRON
/*MACRON             */	DEADTRANS(	L'a'	,0x0101	,0x0101	,0x0000	), // LATIN SMALL LETTER A WITH MACRON
/*MACRON             */	DEADTRANS(	L'B'	,0x0101	,0x1e06	,0x0000	), // LATIN CAPITAL LETTER B WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'b'	,0x0101	,0x1e07	,0x0000	), // LATIN SMALL LETTER B WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'D'	,0x0101	,0x1e0e	,0x0000	), // LATIN CAPITAL LETTER D WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'd'	,0x0101	,0x1e0f	,0x0000	), // LATIN SMALL LETTER D WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'E'	,0x0101	,0x0112	,0x0000	), // LATIN CAPITAL LETTER E WITH MACRON
/*MACRON             */	DEADTRANS(	L'e'	,0x0101	,0x0113	,0x0000	), // LATIN SMALL LETTER E WITH MACRON
/*MACRON             */	DEADTRANS(	L'G'	,0x0101	,0x1e20	,0x0000	), // LATIN CAPITAL LETTER G WITH MACRON
/*MACRON             */	DEADTRANS(	L'g'	,0x0101	,0x1e21	,0x0000	), // LATIN SMALL LETTER G WITH MACRON
/*MACRON             */	DEADTRANS(	L'h'	,0x0101	,0x1e96	,0x0000	), // LATIN SMALL LETTER H WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'I'	,0x0101	,0x012a	,0x0000	), // LATIN CAPITAL LETTER I WITH MACRON
/*MACRON             */	DEADTRANS(	L'i'	,0x0101	,0x012b	,0x0000	), // LATIN SMALL LETTER I WITH MACRON
/*MACRON             */	DEADTRANS(	L'K'	,0x0101	,0x1e34	,0x0000	), // LATIN CAPITAL LETTER K WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'k'	,0x0101	,0x1e35	,0x0000	), // LATIN SMALL LETTER K WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'L'	,0x0101	,0x1e3a	,0x0000	), // LATIN CAPITAL LETTER L WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'l'	,0x0101	,0x1e3b	,0x0000	), // LATIN SMALL LETTER L WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'N'	,0x0101	,0x1e48	,0x0000	), // LATIN CAPITAL LETTER N WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'n'	,0x0101	,0x1e49	,0x0000	), // LATIN SMALL LETTER N WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'O'	,0x0101	,0x014c	,0x0000	), // LATIN CAPITAL LETTER O WITH MACRON
/*MACRON             */	DEADTRANS(	L'o'	,0x0101	,0x014d	,0x0000	), // LATIN SMALL LETTER O WITH MACRON
/*MACRON             */	DEADTRANS(	L'R'	,0x0101	,0x1e5e	,0x0000	), // LATIN CAPITAL LETTER R WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'r'	,0x0101	,0x1e5f	,0x0000	), // LATIN SMALL LETTER R WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L's'	,0x0101	,0x017f	,0x0000	), // LATIN SMALL LETTER LONG S
/*MACRON             */	DEADTRANS(	L'T'	,0x0101	,0x1e6e	,0x0000	), // LATIN CAPITAL LETTER T WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L't'	,0x0101	,0x1e6f	,0x0000	), // LATIN SMALL LETTER T WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'U'	,0x0101	,0x016a	,0x0000	), // LATIN CAPITAL LETTER U WITH MACRON
/*MACRON             */	DEADTRANS(	L'u'	,0x0101	,0x016b	,0x0000	), // LATIN SMALL LETTER U WITH MACRON
/*MACRON             */	DEADTRANS(	L'V'	,0x0101	,0x0332	,0x0000	), // COMBINING LOW LINE
/*MACRON             */	DEADTRANS(	L'v'	,0x0101	,0x0332	,0x0000	), // COMBINING LOW LINE
/*MACRON             */	DEADTRANS(	L'W'	,0x0101	,0x0333	,0x0000	), // COMBINING DOUBLE LOW LINE
/*MACRON             */	DEADTRANS(	L'w'	,0x0101	,0x0333	,0x0000	), // COMBINING DOUBLE LOW LINE
/*MACRON             */	DEADTRANS(	L'Y'	,0x0101	,0x0232	,0x0000	), // LATIN CAPITAL LETTER Y WITH MACRON
/*MACRON             */	DEADTRANS(	L'y'	,0x0101	,0x0233	,0x0000	), // LATIN SMALL LETTER Y WITH MACRON
/*MACRON             */	DEADTRANS(	L'Z'	,0x0101	,0x1e94	,0x0000	), // LATIN CAPITAL LETTER Z WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'z'	,0x0101	,0x1e95	,0x0000	), // LATIN SMALL LETTER Z WITH LINE BELOW
/*MACRON             */	DEADTRANS(	0x00c6	,0x0101	,0x01e2	,0x0000	), // LATIN CAPITAL LETTER AE WITH MACRON
/*MACRON             */	DEADTRANS(	0x00e6	,0x0101	,0x01e3	,0x0000	), // LATIN SMALL LETTER AE WITH MACRON
/*MACRON             */	DEADTRANS(	0x00a3	,0x0101	,0x02cd	,0x0001	), // MODIFIER LETTER LOW MACRON
/*MACRON             */	DEADTRANS(	0x0152	,0x0101	,0x01e2	,0x0000	), // LATIN CAPITAL LETTER AE WITH MACRON
/*MACRON             */	DEADTRANS(	0x0153	,0x0101	,0x01e3	,0x0000	), // LATIN SMALL LETTER AE WITH MACRON
/*MACRON             */	DEADTRANS(	0x0021	,0x0101	,0x1e5d	,0x0001	), // LATIN SMALL LETTER R WITH DOT BELOW AND MACRON
/*MACRON             */	DEADTRANS(	0x0025	,0x0101	,0x246b	,0x0000	), // CIRCLED NUMBER TWELVE
/*MACRON             */	DEADTRANS(	0x0027	,0x0101	,0x1e53	,0x0001	), // LATIN SMALL LETTER O WITH MACRON AND ACUTE
/*MACRON             */	DEADTRANS(	0x002e	,0x0101	,0x0231	,0x0001	), // LATIN SMALL LETTER O WITH DOT ABOVE AND MACRON
/*MACRON             */	DEADTRANS(	L'0'	,0x0101	,0x2469	,0x0000	), // CIRCLED NUMBER TEN
/*MACRON             */	DEADTRANS(	L'1'	,0x0101	,0x2460	,0x0000	), // CIRCLED DIGIT ONE
/*MACRON             */	DEADTRANS(	L'2'	,0x0101	,0x2461	,0x0000	), // CIRCLED DIGIT TWO
/*MACRON             */	DEADTRANS(	L'3'	,0x0101	,0x2462	,0x0000	), // CIRCLED DIGIT THREE
/*MACRON             */	DEADTRANS(	L'4'	,0x0101	,0x2463	,0x0000	), // CIRCLED DIGIT FOUR
/*MACRON             */	DEADTRANS(	L'5'	,0x0101	,0x2464	,0x0000	), // CIRCLED DIGIT FIVE
/*MACRON             */	DEADTRANS(	L'6'	,0x0101	,0x2465	,0x0000	), // CIRCLED DIGIT SIX
/*MACRON             */	DEADTRANS(	L'7'	,0x0101	,0x2466	,0x0000	), // CIRCLED DIGIT SEVEN
/*MACRON             */	DEADTRANS(	L'8'	,0x0101	,0x2467	,0x0000	), // CIRCLED DIGIT EIGHT
/*MACRON             */	DEADTRANS(	L'9'	,0x0101	,0x2468	,0x0000	), // CIRCLED DIGIT NINE
/*MACRON             */	DEADTRANS(	0x003a	,0x0101	,0x1e7b	,0x0001	), // LATIN SMALL LETTER U WITH MACRON AND DIAERESIS
/*MACRON             */	DEADTRANS(	0x003d	,0x0101	,0x2261	,0x0000	), // IDENTICAL TO
/*MACRON             */	DEADTRANS(	0x005b	,0x0101	,0x01ed	,0x0001	), // LATIN SMALL LETTER O WITH OGONEK AND MACRON
/*MACRON             */	DEADTRANS(	0x0060	,0x0101	,0x1e51	,0x0001	), // LATIN SMALL LETTER O WITH MACRON AND GRAVE
/*MACRON             */	DEADTRANS(	0x007e	,0x0101	,0x022d	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND MACRON
/*MACRON             */	DEADTRANS(	0x00a9	,0x0101	,0x01e3	,0x0001	), // LATIN SMALL LETTER AE WITH MACRON
/*MACRON             */	DEADTRANS(	L'A'	,0x01e3	,0x01e2	,0x0000	), // LATIN CAPITAL LETTER AE WITH MACRON
/*MACRON             */	DEADTRANS(	L'a'	,0x01e3	,0x01e3	,0x0000	), // LATIN SMALL LETTER AE WITH MACRON
/*MACRON             */	DEADTRANS(	0x00b0	,0x0101	,0x246a	,0x0000	), // CIRCLED NUMBER ELEVEN
/*MACRON             */	DEADTRANS(	0x00e1	,0x0101	,0x1e53	,0x0001	), // LATIN SMALL LETTER O WITH MACRON AND ACUTE
/*MACRON             */	DEADTRANS(	0x00eb	,0x0101	,0x1e7b	,0x0001	), // LATIN SMALL LETTER U WITH MACRON AND DIAERESIS
/*MACRON             */	DEADTRANS(	0x00f2	,0x0101	,0x1e51	,0x0001	), // LATIN SMALL LETTER O WITH MACRON AND GRAVE
/*MACRON             */	DEADTRANS(	0x00f5	,0x0101	,0x022d	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND MACRON
/*MACRON             */	DEADTRANS(	0x022f	,0x0101	,0x0231	,0x0001	), // LATIN SMALL LETTER O WITH DOT ABOVE AND MACRON
/*MACRON             */	DEADTRANS(	0x0101	,0x0101	,0x1e07	,0x0001	), // LATIN SMALL LETTER B WITH LINE BELOW
/*MACRON             */	DEADTRANS(	0x01eb	,0x0101	,0x01ed	,0x0001	), // LATIN SMALL LETTER O WITH OGONEK AND MACRON
/*MACRON             */	DEADTRANS(	0x1ee5	,0x0101	,0x1e5d	,0x0001	), // LATIN SMALL LETTER R WITH DOT BELOW AND MACRON
/*MACRON&ACUTE_ACCENT*/	DEADTRANS(	L'E'	,0x1e53	,0x1e16	,0x0000	), // LATIN CAPITAL LETTER E WITH MACRON AND ACUTE
/*MACRON&ACUTE_ACCENT*/	DEADTRANS(	L'e'	,0x1e53	,0x1e17	,0x0000	), // LATIN SMALL LETTER E WITH MACRON AND ACUTE
/*MACRON&ACUTE_ACCENT*/	DEADTRANS(	L'O'	,0x1e53	,0x1e52	,0x0000	), // LATIN CAPITAL LETTER O WITH MACRON AND ACUTE
/*MACRON&ACUTE_ACCENT*/	DEADTRANS(	L'o'	,0x1e53	,0x1e53	,0x0000	), // LATIN SMALL LETTER O WITH MACRON AND ACUTE
/*MACRON&DIAERESIS   */	DEADTRANS(	L'U'	,0x1e7b	,0x1e7a	,0x0000	), // LATIN CAPITAL LETTER U WITH MACRON AND DIAERESIS
/*MACRON&DIAERESIS   */	DEADTRANS(	L'u'	,0x1e7b	,0x1e7b	,0x0000	), // LATIN SMALL LETTER U WITH MACRON AND DIAERESIS
/*MACRON&GRAVE_ACCENT*/	DEADTRANS(	L'E'	,0x1e51	,0x1e14	,0x0000	), // LATIN CAPITAL LETTER E WITH MACRON AND GRAVE
/*MACRON&GRAVE_ACCENT*/	DEADTRANS(	L'e'	,0x1e51	,0x1e15	,0x0000	), // LATIN SMALL LETTER E WITH MACRON AND GRAVE
/*MACRON&GRAVE_ACCENT*/	DEADTRANS(	L'O'	,0x1e51	,0x1e50	,0x0000	), // LATIN CAPITAL LETTER O WITH MACRON AND GRAVE
/*MACRON&GRAVE_ACCENT*/	DEADTRANS(	L'o'	,0x1e51	,0x1e51	,0x0000	), // LATIN SMALL LETTER O WITH MACRON AND GRAVE
/*MACRON_BELOW       */	DEADTRANS(	0x0020	,0x1e07	,0x0331	,0x0000	), // COMBINING MACRON BELOW
/*MACRON_BELOW       */	DEADTRANS(	0x00a0	,0x1e07	,0x005f	,0x0000	), // LOW LINE
/*MACRON_BELOW       */	DEADTRANS(	0x202f	,0x1e07	,0x02cd	,0x0000	), // MODIFIER LETTER LOW MACRON
/*MACRON_BELOW       */	DEADTRANS(	L'B'	,0x1e07	,0x1e06	,0x0000	), // LATIN CAPITAL LETTER B WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'b'	,0x1e07	,0x1e07	,0x0000	), // LATIN SMALL LETTER B WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'D'	,0x1e07	,0x1e0e	,0x0000	), // LATIN CAPITAL LETTER D WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'd'	,0x1e07	,0x1e0f	,0x0000	), // LATIN SMALL LETTER D WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'h'	,0x1e07	,0x1e96	,0x0000	), // LATIN SMALL LETTER H WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'K'	,0x1e07	,0x1e34	,0x0000	), // LATIN CAPITAL LETTER K WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'k'	,0x1e07	,0x1e35	,0x0000	), // LATIN SMALL LETTER K WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'L'	,0x1e07	,0x1e3a	,0x0000	), // LATIN CAPITAL LETTER L WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'l'	,0x1e07	,0x1e3b	,0x0000	), // LATIN SMALL LETTER L WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'N'	,0x1e07	,0x1e48	,0x0000	), // LATIN CAPITAL LETTER N WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'n'	,0x1e07	,0x1e49	,0x0000	), // LATIN SMALL LETTER N WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'R'	,0x1e07	,0x1e5e	,0x0000	), // LATIN CAPITAL LETTER R WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'r'	,0x1e07	,0x1e5f	,0x0000	), // LATIN SMALL LETTER R WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'T'	,0x1e07	,0x1e6e	,0x0000	), // LATIN CAPITAL LETTER T WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L't'	,0x1e07	,0x1e6f	,0x0000	), // LATIN SMALL LETTER T WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'Z'	,0x1e07	,0x1e94	,0x0000	), // LATIN CAPITAL LETTER Z WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'z'	,0x1e07	,0x1e95	,0x0000	), // LATIN SMALL LETTER Z WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	0x007c	,0x1e07	,0x007c	,0x0001	), // VERTICAL LINE
/*MATHEMATICAL       */	DEADTRANS(	L'A'	,0x2133	,0x2115	,0x0001	), // DOUBLE-STRUCK CAPITAL N
/*MATHEMATICAL       */	DEADTRANS(	L'a'	,0x2133	,0x2115	,0x0001	), // DOUBLE-STRUCK CAPITAL N
/*MATHEMATICAL       */	DEADTRANS(	L'B'	,0x2133	,0x212c	,0x0001	), // SCRIPT CAPITAL B
/*MATHEMATICAL       */	DEADTRANS(	L'b'	,0x2133	,0x212c	,0x0001	), // SCRIPT CAPITAL B
/*MATHEMATICAL       */	DEADTRANS(	L'C'	,0x2133	,0x212f	,0x0001	), // SCRIPT SMALL E
/*MATHEMATICAL       */	DEADTRANS(	L'c'	,0x2133	,0x212f	,0x0001	), // SCRIPT SMALL E
/*MATHEMATICAL       */	DEADTRANS(	L'D'	,0x2133	,0x2131	,0x0001	), // SCRIPT CAPITAL F
/*MATHEMATICAL       */	DEADTRANS(	L'd'	,0x2133	,0x2131	,0x0001	), // SCRIPT CAPITAL F
/*MATHEMATICAL       */	DEADTRANS(	L'F'	,0x2133	,0x212d	,0x0001	), // BLACK-LETTER CAPITAL C
/*MATHEMATICAL       */	DEADTRANS(	L'f'	,0x2133	,0x212d	,0x0001	), // BLACK-LETTER CAPITAL C
/*MATHEMATICAL       */	DEADTRANS(	L'G'	,0x2133	,0x210a	,0x0001	), // SCRIPT SMALL G
/*MATHEMATICAL       */	DEADTRANS(	L'g'	,0x2133	,0x210a	,0x0001	), // SCRIPT SMALL G
/*MATHEMATICAL       */	DEADTRANS(	L'H'	,0x2133	,0x211c	,0x0001	), // BLACK-LETTER CAPITAL R
/*MATHEMATICAL       */	DEADTRANS(	L'h'	,0x2133	,0x211c	,0x0001	), // BLACK-LETTER CAPITAL R
/*MATHEMATICAL       */	DEADTRANS(	L'I'	,0x2133	,0x210e	,0x0001	), // PLANCK CONSTANT
/*MATHEMATICAL       */	DEADTRANS(	L'i'	,0x2133	,0x210e	,0x0001	), // PLANCK CONSTANT
/*MATHEMATICAL       */	DEADTRANS(	L'J'	,0x2133	,0x2110	,0x0001	), // SCRIPT CAPITAL I
/*MATHEMATICAL       */	DEADTRANS(	L'j'	,0x2133	,0x2110	,0x0001	), // SCRIPT CAPITAL I
/*MATHEMATICAL       */	DEADTRANS(	L'M'	,0x2133	,0x2102	,0x0001	), // DOUBLE-STRUCK CAPITAL C
/*MATHEMATICAL       */	DEADTRANS(	L'm'	,0x2133	,0x2102	,0x0001	), // DOUBLE-STRUCK CAPITAL C
/*MATHEMATICAL       */	DEADTRANS(	L'S'	,0x2133	,0x210b	,0x0001	), // SCRIPT CAPITAL H
/*MATHEMATICAL       */	DEADTRANS(	L's'	,0x2133	,0x210b	,0x0001	), // SCRIPT CAPITAL H
/*MATHEMATICAL       */	DEADTRANS(	L'T'	,0x2133	,0x2112	,0x0001	), // SCRIPT CAPITAL L
/*MATHEMATICAL       */	DEADTRANS(	L't'	,0x2133	,0x2112	,0x0001	), // SCRIPT CAPITAL L
/*MATHEMATICAL       */	DEADTRANS(	L'U'	,0x2133	,0x211b	,0x0001	), // SCRIPT CAPITAL R
/*MATHEMATICAL       */	DEADTRANS(	L'u'	,0x2133	,0x211b	,0x0001	), // SCRIPT CAPITAL R
/*MATHEMATICAL       */	DEADTRANS(	L'V'	,0x2133	,0x2130	,0x0001	), // SCRIPT CAPITAL E
/*MATHEMATICAL       */	DEADTRANS(	L'v'	,0x2133	,0x2130	,0x0001	), // SCRIPT CAPITAL E
/*MATHEMATICAL       */	DEADTRANS(	0x0023	,0x2133	,0x2115	,0x0001	), // DOUBLE-STRUCK CAPITAL N
/*MATHEMATICAL       */	DEADTRANS(	0x0024	,0x2133	,0x210b	,0x0001	), // SCRIPT CAPITAL H
/*MATHEMATICAL       */	DEADTRANS(	0x0025	,0x2133	,0x212d	,0x0001	), // BLACK-LETTER CAPITAL C
/*MATHEMATICAL       */	DEADTRANS(	0x0026	,0x2133	,0x212f	,0x0001	), // SCRIPT SMALL E
/*MATHEMATICAL       */	DEADTRANS(	0x002a	,0x2133	,0x212c	,0x0001	), // SCRIPT CAPITAL B
/*MATHEMATICAL       */	DEADTRANS(	0x002f	,0x2133	,0x210e	,0x0001	), // PLANCK CONSTANT
/*MATHEMATICAL       */	DEADTRANS(	0x003d	,0x2133	,0x2102	,0x0001	), // DOUBLE-STRUCK CAPITAL C
/*OGONEK&MACRON      */	DEADTRANS(	L'O'	,0x01ed	,0x01ec	,0x0000	), // LATIN CAPITAL LETTER O WITH OGONEK AND MACRON
/*OGONEK&MACRON      */	DEADTRANS(	L'o'	,0x01ed	,0x01ed	,0x0000	), // LATIN SMALL LETTER O WITH OGONEK AND MACRON
/*OGONEK/CROOK       */	DEADTRANS(	0x0020	,0x01eb	,0x0328	,0x0000	), // COMBINING OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	0x00a0	,0x01eb	,0x02db	,0x0000	), // OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	0x202f	,0x01eb	,0x02db	,0x0000	), // OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'A'	,0x01eb	,0x0104	,0x0000	), // LATIN CAPITAL LETTER A WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'a'	,0x01eb	,0x0105	,0x0000	), // LATIN SMALL LETTER A WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'B'	,0x01eb	,0x0181	,0x0000	), // LATIN CAPITAL LETTER B WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'b'	,0x01eb	,0x0253	,0x0000	), // LATIN SMALL LETTER B WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'C'	,0x01eb	,0x0187	,0x0000	), // LATIN CAPITAL LETTER C WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'c'	,0x01eb	,0x0188	,0x0000	), // LATIN SMALL LETTER C WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'D'	,0x01eb	,0x018a	,0x0000	), // LATIN CAPITAL LETTER D WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'd'	,0x01eb	,0x0257	,0x0000	), // LATIN SMALL LETTER D WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'E'	,0x01eb	,0x0118	,0x0000	), // LATIN CAPITAL LETTER E WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'e'	,0x01eb	,0x0119	,0x0000	), // LATIN SMALL LETTER E WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'F'	,0x01eb	,0x0191	,0x0000	), // LATIN CAPITAL LETTER F WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'f'	,0x01eb	,0x0192	,0x0000	), // LATIN SMALL LETTER F WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'G'	,0x01eb	,0x0193	,0x0000	), // LATIN CAPITAL LETTER G WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'g'	,0x01eb	,0x0260	,0x0000	), // LATIN SMALL LETTER G WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'H'	,0x01eb	,0xa7aa	,0x0000	), // LATIN CAPITAL LETTER H WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'h'	,0x01eb	,0x0266	,0x0000	), // LATIN SMALL LETTER H WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'I'	,0x01eb	,0x012e	,0x0000	), // LATIN CAPITAL LETTER I WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'i'	,0x01eb	,0x012f	,0x0000	), // LATIN SMALL LETTER I WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'K'	,0x01eb	,0x0198	,0x0000	), // LATIN CAPITAL LETTER K WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'k'	,0x01eb	,0x0199	,0x0000	), // LATIN SMALL LETTER K WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'O'	,0x01eb	,0x01ea	,0x0000	), // LATIN CAPITAL LETTER O WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'o'	,0x01eb	,0x01eb	,0x0000	), // LATIN SMALL LETTER O WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'P'	,0x01eb	,0x01a4	,0x0000	), // LATIN CAPITAL LETTER P WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'p'	,0x01eb	,0x01a5	,0x0000	), // LATIN SMALL LETTER P WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'q'	,0x01eb	,0x02a0	,0x0000	), // LATIN SMALL LETTER Q WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'r'	,0x01eb	,0x027e	,0x0000	), // LATIN SMALL LETTER R WITH FISHHOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'T'	,0x01eb	,0x01ac	,0x0000	), // LATIN CAPITAL LETTER T WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L't'	,0x01eb	,0x01ad	,0x0000	), // LATIN SMALL LETTER T WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'U'	,0x01eb	,0x0172	,0x0000	), // LATIN CAPITAL LETTER U WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'u'	,0x01eb	,0x0173	,0x0000	), // LATIN SMALL LETTER U WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'V'	,0x01eb	,0x01b2	,0x0000	), // LATIN CAPITAL LETTER V WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'v'	,0x01eb	,0x028b	,0x0000	), // LATIN SMALL LETTER V WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'W'	,0x01eb	,0x2c72	,0x0000	), // LATIN CAPITAL LETTER W WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'w'	,0x01eb	,0x2c73	,0x0000	), // LATIN SMALL LETTER W WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'Y'	,0x01eb	,0x01b3	,0x0000	), // LATIN CAPITAL LETTER Y WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'y'	,0x01eb	,0x01b4	,0x0000	), // LATIN SMALL LETTER Y WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'Z'	,0x01eb	,0x0224	,0x0000	), // LATIN CAPITAL LETTER Z WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'z'	,0x01eb	,0x0225	,0x0000	), // LATIN SMALL LETTER Z WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	0x005b	,0x01eb	,0x02ad	,0x0000	), // LATIN LETTER BIDENTAL PERCUSSIVE
/*OGONEK/CROOK       */	DEADTRANS(	L'e'	,0x02ad	,0x029a	,0x0000	), // LATIN SMALL LETTER CLOSED OPEN E
/*OGONEK/CROOK       */	DEADTRANS(	L'o'	,0x02ad	,0x0277	,0x0000	), // LATIN SMALL LETTER CLOSED OMEGA
/*OGONEK/CROOK       */	DEADTRANS(	0x005c	,0x02ad	,0x025e	,0x0000	), // LATIN SMALL LETTER CLOSED REVERSED OPEN E
/*OGONEK/CROOK       */	DEADTRANS(	0x005f	,0x01eb	,0x01ed	,0x0001	), // LATIN SMALL LETTER O WITH OGONEK AND MACRON
/*OGONEK/CROOK       */	DEADTRANS(	0x007b	,0x01eb	,0x1d91	,0x0000	), // LATIN SMALL LETTER D WITH HOOK AND TAIL
/*OGONEK/CROOK       */	DEADTRANS(	0x007e	,0x01eb	,0x1d73	,0x0000	), // LATIN SMALL LETTER R WITH FISHHOOK AND MIDDLE TILDE
/*OGONEK/CROOK       */	DEADTRANS(	0x00a9	,0x01eb	,0x025a	,0x0001	), // LATIN SMALL LETTER SCHWA WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'e'	,0x025a	,0x025a	,0x0000	), // LATIN SMALL LETTER SCHWA WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	0x00f5	,0x01eb	,0x1d73	,0x0000	), // LATIN SMALL LETTER R WITH FISHHOOK AND MIDDLE TILDE
/*OGONEK/CROOK       */	DEADTRANS(	0x014d	,0x01eb	,0x01ed	,0x0001	), // LATIN SMALL LETTER O WITH OGONEK AND MACRON
/*PALATAL_HOOK       */	DEADTRANS(	L'B'	,0x0192	,0xa796	,0x0000	), // LATIN CAPITAL LETTER B WITH FLOURISH
/*PALATAL_HOOK       */	DEADTRANS(	L'b'	,0x0192	,0xa797	,0x0000	), // LATIN SMALL LETTER B WITH FLOURISH
/*PALATAL_HOOK       */	DEADTRANS(	L'e'	,0x0192	,0xab34	,0x0000	), // LATIN SMALL LETTER E WITH FLOURISH
/*PALATAL_HOOK       */	DEADTRANS(	L'F'	,0x0192	,0x0191	,0x0000	), // LATIN CAPITAL LETTER F WITH HOOK
/*PALATAL_HOOK       */	DEADTRANS(	L'f'	,0x0192	,0x0192	,0x0000	), // LATIN SMALL LETTER F WITH HOOK
/*PALATAL_HOOK       */	DEADTRANS(	L'M'	,0x0192	,0x2c6e	,0x0000	), // LATIN CAPITAL LETTER M WITH HOOK
/*PALATAL_HOOK       */	DEADTRANS(	L'm'	,0x0192	,0x0271	,0x0000	), // LATIN SMALL LETTER M WITH HOOK
/*PALATAL_HOOK       */	DEADTRANS(	L'N'	,0x0192	,0x019d	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*PALATAL_HOOK       */	DEADTRANS(	L'n'	,0x0192	,0x0272	,0x0000	), // LATIN SMALL LETTER N WITH LEFT HOOK
/*PALATAL_HOOK       */	DEADTRANS(	L'P'	,0x0192	,0xa752	,0x0000	), // LATIN CAPITAL LETTER P WITH FLOURISH
/*PALATAL_HOOK       */	DEADTRANS(	L'p'	,0x0192	,0xa753	,0x0000	), // LATIN SMALL LETTER P WITH FLOURISH
/*PALATAL_HOOK       */	DEADTRANS(	L'Q'	,0x0192	,0x024a	,0x0000	), // LATIN CAPITAL LETTER SMALL Q WITH HOOK TAIL
/*PALATAL_HOOK       */	DEADTRANS(	L'q'	,0x0192	,0x024b	,0x0000	), // LATIN SMALL LETTER Q WITH HOOK TAIL
/*PALATAL_HOOK       */	DEADTRANS(	L'S'	,0x0192	,0x2c7e	,0x0000	), // LATIN CAPITAL LETTER S WITH SWASH TAIL
/*PALATAL_HOOK       */	DEADTRANS(	L's'	,0x0192	,0x023f	,0x0000	), // LATIN SMALL LETTER S WITH SWASH TAIL
/*PALATAL_HOOK       */	DEADTRANS(	L'u'	,0x0192	,0xab52	,0x0000	), // LATIN SMALL LETTER U WITH LEFT HOOK
/*PALATAL_HOOK       */	DEADTRANS(	L'Z'	,0x0192	,0x2c7f	,0x0000	), // LATIN CAPITAL LETTER Z WITH SWASH TAIL
/*PALATAL_HOOK       */	DEADTRANS(	L'z'	,0x0192	,0x0240	,0x0000	), // LATIN SMALL LETTER Z WITH SWASH TAIL
/*PALATAL_HOOK       */	DEADTRANS(	0x007d	,0x0192	,0xa755	,0x0001	), // LATIN SMALL LETTER P WITH SQUIRREL TAIL
/*PALATAL_HOOK       */	DEADTRANS(	L'P'	,0xa755	,0xa754	,0x0000	), // LATIN CAPITAL LETTER P WITH SQUIRREL TAIL
/*PALATAL_HOOK       */	DEADTRANS(	L'p'	,0xa755	,0xa755	,0x0000	), // LATIN SMALL LETTER P WITH SQUIRREL TAIL
/*PALATAL_HOOK       */	DEADTRANS(	0x00a9	,0x0192	,0x01ba	,0x0000	), // LATIN SMALL LETTER EZH WITH TAIL
/*PARENTHESIZED      */	DEADTRANS(	L'a'	,0x24aa	,0x249c	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER A
/*PARENTHESIZED      */	DEADTRANS(	L'b'	,0x24aa	,0x249d	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER B
/*PARENTHESIZED      */	DEADTRANS(	L'c'	,0x24aa	,0x249e	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER C
/*PARENTHESIZED      */	DEADTRANS(	L'd'	,0x24aa	,0x249f	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER D
/*PARENTHESIZED      */	DEADTRANS(	L'e'	,0x24aa	,0x24a0	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER E
/*PARENTHESIZED      */	DEADTRANS(	L'f'	,0x24aa	,0x24a1	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER F
/*PARENTHESIZED      */	DEADTRANS(	L'g'	,0x24aa	,0x24a2	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER G
/*PARENTHESIZED      */	DEADTRANS(	L'h'	,0x24aa	,0x24a3	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER H
/*PARENTHESIZED      */	DEADTRANS(	L'i'	,0x24aa	,0x24a4	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER I
/*PARENTHESIZED      */	DEADTRANS(	L'j'	,0x24aa	,0x24a5	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER J
/*PARENTHESIZED      */	DEADTRANS(	L'k'	,0x24aa	,0x24a6	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER K
/*PARENTHESIZED      */	DEADTRANS(	L'l'	,0x24aa	,0x24a7	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER L
/*PARENTHESIZED      */	DEADTRANS(	L'm'	,0x24aa	,0x24a8	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER M
/*PARENTHESIZED      */	DEADTRANS(	L'n'	,0x24aa	,0x24a9	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER N
/*PARENTHESIZED      */	DEADTRANS(	L'o'	,0x24aa	,0x24aa	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER O
/*PARENTHESIZED      */	DEADTRANS(	L'p'	,0x24aa	,0x24ab	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER P
/*PARENTHESIZED      */	DEADTRANS(	L'q'	,0x24aa	,0x24ac	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER Q
/*PARENTHESIZED      */	DEADTRANS(	L'r'	,0x24aa	,0x24ad	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER R
/*PARENTHESIZED      */	DEADTRANS(	L's'	,0x24aa	,0x24ae	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER S
/*PARENTHESIZED      */	DEADTRANS(	L't'	,0x24aa	,0x24af	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER T
/*PARENTHESIZED      */	DEADTRANS(	L'u'	,0x24aa	,0x24b0	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER U
/*PARENTHESIZED      */	DEADTRANS(	L'v'	,0x24aa	,0x24b1	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER V
/*PARENTHESIZED      */	DEADTRANS(	L'w'	,0x24aa	,0x24b2	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER W
/*PARENTHESIZED      */	DEADTRANS(	L'x'	,0x24aa	,0x24b3	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER X
/*PARENTHESIZED      */	DEADTRANS(	L'y'	,0x24aa	,0x24b4	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER Y
/*PARENTHESIZED      */	DEADTRANS(	L'z'	,0x24aa	,0x24b5	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER Z
/*PARENTHESIZED      */	DEADTRANS(	L'1'	,0x24aa	,0x2474	,0x0001	), // PARENTHESIZED DIGIT ONE
/*PARENTHESIZED      */	DEADTRANS(	L'2'	,0x24aa	,0x2475	,0x0001	), // PARENTHESIZED DIGIT TWO
/*PARENTHESIZED      */	DEADTRANS(	L'3'	,0x24aa	,0x2476	,0x0000	), // PARENTHESIZED DIGIT THREE
/*PARENTHESIZED      */	DEADTRANS(	L'4'	,0x24aa	,0x2477	,0x0000	), // PARENTHESIZED DIGIT FOUR
/*PARENTHESIZED      */	DEADTRANS(	L'5'	,0x24aa	,0x2478	,0x0000	), // PARENTHESIZED DIGIT FIVE
/*PARENTHESIZED      */	DEADTRANS(	L'6'	,0x24aa	,0x2479	,0x0000	), // PARENTHESIZED DIGIT SIX
/*PARENTHESIZED      */	DEADTRANS(	L'7'	,0x24aa	,0x247a	,0x0000	), // PARENTHESIZED DIGIT SEVEN
/*PARENTHESIZED      */	DEADTRANS(	L'8'	,0x24aa	,0x247b	,0x0000	), // PARENTHESIZED DIGIT EIGHT
/*PARENTHESIZED      */	DEADTRANS(	L'9'	,0x24aa	,0x247c	,0x0000	), // PARENTHESIZED DIGIT NINE
/*PARENTHESIZED_1#   */	DEADTRANS(	L'0'	,0x2474	,0x247d	,0x0000	), // PARENTHESIZED NUMBER TEN
/*PARENTHESIZED_1#   */	DEADTRANS(	L'1'	,0x2474	,0x247e	,0x0000	), // PARENTHESIZED NUMBER ELEVEN
/*PARENTHESIZED_1#   */	DEADTRANS(	L'2'	,0x2474	,0x247f	,0x0000	), // PARENTHESIZED NUMBER TWELVE
/*PARENTHESIZED_1#   */	DEADTRANS(	L'3'	,0x2474	,0x2480	,0x0000	), // PARENTHESIZED NUMBER THIRTEEN
/*PARENTHESIZED_1#   */	DEADTRANS(	L'4'	,0x2474	,0x2481	,0x0000	), // PARENTHESIZED NUMBER FOURTEEN
/*PARENTHESIZED_1#   */	DEADTRANS(	L'5'	,0x2474	,0x2482	,0x0000	), // PARENTHESIZED NUMBER FIFTEEN
/*PARENTHESIZED_1#   */	DEADTRANS(	L'6'	,0x2474	,0x2483	,0x0000	), // PARENTHESIZED NUMBER SIXTEEN
/*PARENTHESIZED_1#   */	DEADTRANS(	L'7'	,0x2474	,0x2484	,0x0000	), // PARENTHESIZED NUMBER SEVENTEEN
/*PARENTHESIZED_1#   */	DEADTRANS(	L'8'	,0x2474	,0x2485	,0x0000	), // PARENTHESIZED NUMBER EIGHTEEN
/*PARENTHESIZED_1#   */	DEADTRANS(	L'9'	,0x2474	,0x2486	,0x0000	), // PARENTHESIZED NUMBER NINETEEN
/*PARENTHESIZED_1#   */	DEADTRANS(	0x0029	,0x2474	,0x2474	,0x0000	), // PARENTHESIZED DIGIT ONE
/*PARENTHESIZED_2#   */	DEADTRANS(	L'0'	,0x2475	,0x2487	,0x0000	), // PARENTHESIZED NUMBER TWENTY
/*PARENTHESIZED_2#   */	DEADTRANS(	0x0029	,0x2475	,0x2475	,0x0000	), // PARENTHESIZED DIGIT TWO
/*RECOMPOSE          */	DEADTRANS(	0x00e9	,0x00ae	,0x1def	,0x0001	), // COMBINING LATIN SMALL LETTER ESH
/*RECOMPOSE          */	DEADTRANS(	L'c'	,0x1def	,0x1def	,0x0000	), // COMBINING LATIN SMALL LETTER ESH
/*RECOMPOSE          */	DEADTRANS(	L'd'	,0x1def	,0x1dd9	,0x0000	), // COMBINING LATIN SMALL LETTER ETH
/*RECOMPOSE          */	DEADTRANS(	L'e'	,0x1def	,0x1dea	,0x0000	), // COMBINING LATIN SMALL LETTER SCHWA
/*RECOMPOSE          */	DEADTRANS(	L's'	,0x1def	,0x1de5	,0x0000	), // COMBINING LATIN SMALL LETTER LONG S
/*RECOMPOSE          */	DEADTRANS(	L'w'	,0x1def	,0x035b	,0x0000	), // COMBINING ZIGZAG ABOVE
/*RECOMPOSE          */	DEADTRANS(	L'x'	,0x1def	,0x033d	,0x0000	), // COMBINING X ABOVE
/*RECOMPOSE          */	DEADTRANS(	L'z'	,0x1def	,0x035b	,0x0000	), // COMBINING ZIGZAG ABOVE
/*RECOMPOSE          */	DEADTRANS(	L'd'	,0x00ae	,0x02a4	,0x0000	), // LATIN SMALL LETTER DEZH DIGRAPH
/*RECOMPOSE          */	DEADTRANS(	L's'	,0x00ae	,0xab4d	,0x0000	), // LATIN SMALL LETTER BASELINE ESH
/*RECOMPOSE          */	DEADTRANS(	0x00a7	,0x00ae	,0xab51	,0x0000	), // LATIN SMALL LETTER TURNED UI
/*RECOMPOSE          */	DEADTRANS(	0x0024	,0x00ae	,0x00a4	,0x0001	), // CURRENCY SIGN
/*RECOMPOSE          */	DEADTRANS(	0x0026	,0x00ae	,0x2113	,0x0001	), // SCRIPT SMALL L
/*RECOMPOSE          */	DEADTRANS(	0x002d	,0x00ae	,0x0284	,0x0001	), // LATIN SMALL LETTER DOTLESS J WITH STROKE AND HOOK
/*RECOMPOSE          */	DEADTRANS(	L'c'	,0x0284	,0x0284	,0x0000	), // LATIN SMALL LETTER DOTLESS J WITH STROKE AND HOOK
/*RECOMPOSE          */	DEADTRANS(	L's'	,0x0284	,0x1e9d	,0x0000	), // LATIN SMALL LETTER LONG S WITH HIGH STROKE
/*RECOMPOSE          */	DEADTRANS(	L'T'	,0x0284	,0xa764	,0x0000	), // LATIN CAPITAL LETTER THORN WITH STROKE
/*RECOMPOSE          */	DEADTRANS(	L't'	,0x0284	,0xa765	,0x0000	), // LATIN SMALL LETTER THORN WITH STROKE
/*RECOMPOSE          */	DEADTRANS(	0x002f	,0x00ae	,0x1e9c	,0x0001	), // LATIN SMALL LETTER LONG S WITH DIAGONAL STROKE
/*RECOMPOSE          */	DEADTRANS(	0x00a6	,0x00ae	,0x00a6	,0x0001	), // BROKEN BAR
/*RECOMPOSE          */	DEADTRANS(	0x003c	,0x00ae	,0x01ef	,0x0001	), // LATIN SMALL LETTER EZH WITH CARON
/*RECOMPOSE          */	DEADTRANS(	L'D'	,0x01ef	,0x01c4	,0x0001	), // LATIN CAPITAL LETTER DZ WITH CARON
/*RECOMPOSE          */	DEADTRANS(	L'Z'	,0x01c4	,0x01c4	,0x0000	), // LATIN CAPITAL LETTER DZ WITH CARON
/*RECOMPOSE          */	DEADTRANS(	L'z'	,0x01c4	,0x01c5	,0x0000	), // LATIN CAPITAL LETTER D WITH SMALL LETTER Z WITH CARON
/*RECOMPOSE          */	DEADTRANS(	L'd'	,0x01ef	,0x01c6	,0x0000	), // LATIN SMALL LETTER DZ WITH CARON
/*RECOMPOSE          */	DEADTRANS(	L'Z'	,0x01ef	,0x01ee	,0x0000	), // LATIN CAPITAL LETTER EZH WITH CARON
/*RECOMPOSE          */	DEADTRANS(	L'z'	,0x01ef	,0x01ef	,0x0000	), // LATIN SMALL LETTER EZH WITH CARON
/*RECOMPOSE          */	DEADTRANS(	0x005b	,0x00ae	,0x0267	,0x0001	), // LATIN SMALL LETTER HENG WITH HOOK
/*RECOMPOSE          */	DEADTRANS(	L'e'	,0x0267	,0x025a	,0x0000	), // LATIN SMALL LETTER SCHWA WITH HOOK
/*RECOMPOSE          */	DEADTRANS(	L'h'	,0x0267	,0x0267	,0x0000	), // LATIN SMALL LETTER HENG WITH HOOK
/*RECOMPOSE          */	DEADTRANS(	L'Z'	,0x0267	,0xa762	,0x0000	), // LATIN CAPITAL LETTER VISIGOTHIC Z
/*RECOMPOSE          */	DEADTRANS(	L'z'	,0x0267	,0xa763	,0x0000	), // LATIN SMALL LETTER VISIGOTHIC Z
/*RECOMPOSE          */	DEADTRANS(	0x005d	,0x00ae	,0x1d8b	,0x0000	), // LATIN SMALL LETTER ESH WITH PALATAL HOOK
/*RECOMPOSE          */	DEADTRANS(	0x005e	,0x00ae	,0x1d9e	,0x0001	), // MODIFIER LETTER SMALL ETH
/*RECOMPOSE          */	DEADTRANS(	0x005f	,0x00ae	,0x01e2	,0x0001	), // LATIN CAPITAL LETTER AE WITH MACRON
/*RECOMPOSE          */	DEADTRANS(	L'A'	,0x01e2	,0x01e2	,0x0000	), // LATIN CAPITAL LETTER AE WITH MACRON
/*RECOMPOSE          */	DEADTRANS(	L'a'	,0x01e2	,0x01e3	,0x0000	), // LATIN SMALL LETTER AE WITH MACRON
/*RECOMPOSE          */	DEADTRANS(	0x0060	,0x00ae	,0x00a4	,0x0001	), // CURRENCY SIGN
/*RECOMPOSE          */	DEADTRANS(	0x007b	,0x00ae	,0x1d98	,0x0001	), // LATIN SMALL LETTER ESH WITH RETROFLEX HOOK
/*RECOMPOSE          */	DEADTRANS(	L'c'	,0x1d98	,0x1d98	,0x0000	), // LATIN SMALL LETTER ESH WITH RETROFLEX HOOK
/*RECOMPOSE          */	DEADTRANS(	L'e'	,0x1d98	,0x1d95	,0x0000	), // LATIN SMALL LETTER SCHWA WITH RETROFLEX HOOK
/*RECOMPOSE          */	DEADTRANS(	L's'	,0x1d98	,0x1d98	,0x0000	), // LATIN SMALL LETTER ESH WITH RETROFLEX HOOK
/*RECOMPOSE          */	DEADTRANS(	L'z'	,0x1d98	,0x1d9a	,0x0000	), // LATIN SMALL LETTER EZH WITH RETROFLEX HOOK
/*RECOMPOSE          */	DEADTRANS(	0x00b0	,0x00ae	,0xa75c	,0x0000	), // LATIN CAPITAL LETTER RUM ROTUNDA
/*RECOMPOSE          */	DEADTRANS(	L'R'	,0xa75c	,0xa75c	,0x0000	), // LATIN CAPITAL LETTER RUM ROTUNDA
/*RECOMPOSE          */	DEADTRANS(	L'r'	,0xa75c	,0xa75d	,0x0000	), // LATIN SMALL LETTER RUM ROTUNDA
/*RECOMPOSE          */	DEADTRANS(	0x00ea	,0x00ae	,0x1d9e	,0x0001	), // MODIFIER LETTER SMALL ETH
/*RECOMPOSE          */	DEADTRANS(	L'c'	,0x1d9e	,0x1d9d	,0x0000	), // MODIFIER LETTER SMALL C WITH CURL
/*RECOMPOSE          */	DEADTRANS(	L'd'	,0x1d9e	,0x1d9e	,0x0000	), // MODIFIER LETTER SMALL ETH
/*RECOMPOSE          */	DEADTRANS(	0x0259	,0x1d9e	,0x1d4a	,0x0000	), // MODIFIER LETTER SMALL SCHWA
/*RECOMPOSE          */	DEADTRANS(	L'h'	,0x1d9e	,0xab5c	,0x0000	), // MODIFIER LETTER SMALL HENG
/*RECOMPOSE          */	DEADTRANS(	L'j'	,0x1d9e	,0x1da8	,0x0000	), // MODIFIER LETTER SMALL J WITH CROSSED-TAIL
/*RECOMPOSE          */	DEADTRANS(	0x014b	,0x1d9e	,0x1d51	,0x0000	), // MODIFIER LETTER SMALL ENG
/*RECOMPOSE          */	DEADTRANS(	L'O'	,0x1d9e	,0x1d3d	,0x0000	), // MODIFIER LETTER CAPITAL OU
/*RECOMPOSE          */	DEADTRANS(	L'o'	,0x1d9e	,0x1d54	,0x0001	), // MODIFIER LETTER SMALL TOP HALF O
/*RECOMPOSE          */	DEADTRANS(	0x0028	,0x1d54	,0x1d54	,0x0000	), // MODIFIER LETTER SMALL TOP HALF O
/*RECOMPOSE          */	DEADTRANS(	0x0029	,0x1d54	,0x1d55	,0x0000	), // MODIFIER LETTER SMALL BOTTOM HALF O
/*RECOMPOSE          */	DEADTRANS(	0x0283	,0x1d9e	,0x1db4	,0x0000	), // MODIFIER LETTER SMALL ESH
/*RECOMPOSE          */	DEADTRANS(	0x0292	,0x1d9e	,0x1dbe	,0x0000	), // MODIFIER LETTER SMALL EZH
/*RECOMPOSE          */	DEADTRANS(	0x0153	,0x1d9e	,0x1da8	,0x0001	), // MODIFIER LETTER SMALL J WITH CROSSED-TAIL
/*RECOMPOSE          */	DEADTRANS(	L'c'	,0x1da8	,0x1d9d	,0x0000	), // MODIFIER LETTER SMALL C WITH CURL
/*RECOMPOSE          */	DEADTRANS(	L'j'	,0x1da8	,0x1da8	,0x0000	), // MODIFIER LETTER SMALL J WITH CROSSED-TAIL
/*RECOMPOSE          */	DEADTRANS(	L'z'	,0x1da8	,0x1dbd	,0x0000	), // MODIFIER LETTER SMALL Z WITH CURL
/*RECOMPOSE          */	DEADTRANS(	0x0153	,0x1da8	,0x1da8	,0x0000	), // MODIFIER LETTER SMALL J WITH CROSSED-TAIL
/*RECOMPOSE          */	DEADTRANS(	0x0026	,0x1d9e	,0x1dbd	,0x0000	), // MODIFIER LETTER SMALL Z WITH CURL
/*RECOMPOSE          */	DEADTRANS(	0x002d	,0x1d9e	,0x1d2f	,0x0000	), // MODIFIER LETTER CAPITAL BARRED B
/*RECOMPOSE          */	DEADTRANS(	0x00a9	,0x2193	,0x2094	,0x0001	), // LATIN SUBSCRIPT SMALL LETTER SCHWA
/*RECOMPOSE          */	DEADTRANS(	L'A'	,0x2094	,0x1d01	,0x0000	), // LATIN LETTER SMALL CAPITAL AE
/*RECOMPOSE          */	DEADTRANS(	L'e'	,0x2094	,0x2094	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER SCHWA
/*RECOMPOSE          */	DEADTRANS(	L'O'	,0x2094	,0x1d15	,0x0001	), // LATIN LETTER SMALL CAPITAL OU
/*RECOMPOSE          */	DEADTRANS(	L'E'	,0x1d15	,0x0276	,0x0000	), // LATIN LETTER SMALL CAPITAL OE
/*RECOMPOSE          */	DEADTRANS(	L'U'	,0x1d15	,0x1d15	,0x0000	), // LATIN LETTER SMALL CAPITAL OU
/*RECOMPOSE          */	DEADTRANS(	L'R'	,0x2094	,0xa776	,0x0000	), // LATIN LETTER SMALL CAPITAL RUM
/*RECOMPOSE          */	DEADTRANS(	L'Z'	,0x2094	,0x1d23	,0x0000	), // LATIN LETTER SMALL CAPITAL EZH
/*RECOMPOSE          */	DEADTRANS(	L'z'	,0x2094	,0x1d23	,0x0000	), // LATIN LETTER SMALL CAPITAL EZH
/*RECOMPOSE          */	DEADTRANS(	0x002d	,0x2094	,0x1d03	,0x0001	), // LATIN LETTER SMALL CAPITAL BARRED B
/*RECOMPOSE          */	DEADTRANS(	L'B'	,0x1d03	,0x1d03	,0x0000	), // LATIN LETTER SMALL CAPITAL BARRED B
/*RECOMPOSE          */	DEADTRANS(	L'I'	,0x1d03	,0x1d7b	,0x0000	), // LATIN SMALL CAPITAL LETTER I WITH STROKE
/*RECOMPOSE          */	DEADTRANS(	L'L'	,0x1d03	,0x1d0c	,0x0000	), // LATIN LETTER SMALL CAPITAL L WITH STROKE
/*RECOMPOSE          */	DEADTRANS(	L'U'	,0x1d03	,0x1d7e	,0x0000	), // LATIN SMALL CAPITAL LETTER U WITH STROKE
/*RECOMPOSE          */	DEADTRANS(	0x2191	,0x00ae	,0x1d9e	,0x0001	), // MODIFIER LETTER SMALL ETH
/*RETROFLEX_HOOK     */	DEADTRANS(	0x0020	,0x0273	,0x0322	,0x0000	), // COMBINING RETROFLEX HOOK BELOW
/*RETROFLEX_HOOK     */	DEADTRANS(	L'a'	,0x0273	,0x1d8f	,0x0000	), // LATIN SMALL LETTER A WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'D'	,0x0273	,0x0189	,0x0000	), // LATIN CAPITAL LETTER AFRICAN D
/*RETROFLEX_HOOK     */	DEADTRANS(	L'd'	,0x0273	,0x0256	,0x0000	), // LATIN SMALL LETTER D WITH TAIL
/*RETROFLEX_HOOK     */	DEADTRANS(	L'e'	,0x0273	,0x1d92	,0x0000	), // LATIN SMALL LETTER E WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'i'	,0x0273	,0x1d96	,0x0000	), // LATIN SMALL LETTER I WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'l'	,0x0273	,0x026d	,0x0000	), // LATIN SMALL LETTER L WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'n'	,0x0273	,0x0273	,0x0000	), // LATIN SMALL LETTER N WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'Q'	,0x0273	,0x024a	,0x0000	), // LATIN CAPITAL LETTER SMALL Q WITH HOOK TAIL
/*RETROFLEX_HOOK     */	DEADTRANS(	L'q'	,0x0273	,0x024b	,0x0000	), // LATIN SMALL LETTER Q WITH HOOK TAIL
/*RETROFLEX_HOOK     */	DEADTRANS(	L'R'	,0x0273	,0x2c64	,0x0000	), // LATIN CAPITAL LETTER R WITH TAIL
/*RETROFLEX_HOOK     */	DEADTRANS(	L'r'	,0x0273	,0x027d	,0x0000	), // LATIN SMALL LETTER R WITH TAIL
/*RETROFLEX_HOOK     */	DEADTRANS(	L's'	,0x0273	,0x0282	,0x0000	), // LATIN SMALL LETTER S WITH HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'T'	,0x0273	,0x01ae	,0x0000	), // LATIN CAPITAL LETTER T WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L't'	,0x0273	,0x0288	,0x0000	), // LATIN SMALL LETTER T WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'u'	,0x0273	,0x1d99	,0x0000	), // LATIN SMALL LETTER U WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'v'	,0x0273	,0x2c71	,0x0000	), // LATIN SMALL LETTER V WITH RIGHT HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'z'	,0x0273	,0x0290	,0x0000	), // LATIN SMALL LETTER Z WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	0x00f9	,0x0273	,0x0282	,0x0001	), // LATIN SMALL LETTER S WITH HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'a'	,0x0282	,0x1d90	,0x0000	), // LATIN SMALL LETTER ALPHA WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'e'	,0x0282	,0x1d93	,0x0000	), // LATIN SMALL LETTER OPEN E WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	0x0024	,0x0273	,0xa78e	,0x0000	), // LATIN SMALL LETTER L WITH RETROFLEX HOOK AND BELT
/*RETROFLEX_HOOK     */	DEADTRANS(	0x005c	,0x0273	,0x0285	,0x0000	), // LATIN SMALL LETTER SQUAT REVERSED ESH
/*RETROFLEX_HOOK     */	DEADTRANS(	0x00a9	,0x1d97	,0x1d95	,0x0001	), // LATIN SMALL LETTER SCHWA WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'c'	,0x1d95	,0x1d98	,0x0000	), // LATIN SMALL LETTER ESH WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'e'	,0x1d95	,0x1d95	,0x0000	), // LATIN SMALL LETTER SCHWA WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L's'	,0x1d95	,0x1d98	,0x0000	), // LATIN SMALL LETTER ESH WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'z'	,0x1d95	,0x1d9a	,0x0000	), // LATIN SMALL LETTER EZH WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	0x00a7	,0x0273	,0x1d97	,0x0001	), // LATIN SMALL LETTER OPEN O WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'c'	,0x1d97	,0x1d97	,0x0000	), // LATIN SMALL LETTER OPEN O WITH RETROFLEX HOOK
/*REVERSED           */	DEADTRANS(	L'C'	,0x1d19	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*REVERSED           */	DEADTRANS(	L'c'	,0x1d19	,0x0254	,0x0000	), // LATIN SMALL LETTER OPEN O
/*REVERSED           */	DEADTRANS(	L'E'	,0x1d19	,0x018e	,0x0000	), // LATIN CAPITAL LETTER REVERSED E
/*REVERSED           */	DEADTRANS(	L'e'	,0x1d19	,0x0258	,0x0000	), // LATIN SMALL LETTER REVERSED E
/*REVERSED           */	DEADTRANS(	L'F'	,0x1d19	,0xa7fb	,0x0000	), // LATIN EPIGRAPHIC LETTER REVERSED F
/*REVERSED           */	DEADTRANS(	L'o'	,0x1d19	,0xab43	,0x0000	), // LATIN SMALL LETTER TURNED O OPEN-O
/*REVERSED           */	DEADTRANS(	L'P'	,0x1d19	,0xa7fc	,0x0000	), // LATIN EPIGRAPHIC LETTER REVERSED P
/*REVERSED           */	DEADTRANS(	L'S'	,0x1d19	,0x01aa	,0x0000	), // LATIN LETTER REVERSED ESH LOOP
/*REVERSED           */	DEADTRANS(	L's'	,0x1d19	,0x01aa	,0x0000	), // LATIN LETTER REVERSED ESH LOOP
/*REVERSED           */	DEADTRANS(	L'Z'	,0x1d19	,0x01b8	,0x0000	), // LATIN CAPITAL LETTER EZH REVERSED
/*REVERSED           */	DEADTRANS(	L'z'	,0x1d19	,0x01b9	,0x0000	), // LATIN SMALL LETTER EZH REVERSED
/*REVERSED           */	DEADTRANS(	0x00f9	,0x1d19	,0x0295	,0x0000	), // LATIN LETTER PHARYNGEAL VOICED FRICATIVE
/*REVERSED           */	DEADTRANS(	0x0027	,0x1d19	,0x0295	,0x0000	), // LATIN LETTER PHARYNGEAL VOICED FRICATIVE
/*REVERSED           */	DEADTRANS(	0x002d	,0x1d19	,0x02a2	,0x0000	), // LATIN LETTER REVERSED GLOTTAL STOP WITH STROKE
/*REVERSED           */	DEADTRANS(	0x002e	,0x1d19	,0xa73f	,0x0001	), // LATIN SMALL LETTER REVERSED C WITH DOT
/*REVERSED           */	DEADTRANS(	L'C'	,0xa73f	,0xa73e	,0x0000	), // LATIN CAPITAL LETTER REVERSED C WITH DOT
/*REVERSED           */	DEADTRANS(	L'c'	,0xa73f	,0xa73f	,0x0000	), // LATIN SMALL LETTER REVERSED C WITH DOT
/*REVERSED           */	DEADTRANS(	0x003b	,0x1d19	,0x204f	,0x0000	), // REVERSED SEMICOLON
/*REVERSED           */	DEADTRANS(	0x005b	,0x1d19	,0x027f	,0x0000	), // LATIN SMALL LETTER REVERSED R WITH FISHHOOK
/*REVERSED           */	DEADTRANS(	0x005d	,0x1d19	,0x025d	,0x0000	), // LATIN SMALL LETTER REVERSED OPEN E WITH HOOK
/*REVERSED           */	DEADTRANS(	0x007b	,0x1d19	,0x1d94	,0x0000	), // LATIN SMALL LETTER REVERSED OPEN E WITH RETROFLEX HOOK
/*REVERSED           */	DEADTRANS(	0x007c	,0x1d19	,0x204b	,0x0000	), // REVERSED PILCROW SIGN
/*REVERSED           */	DEADTRANS(	0x00b5	,0x1d19	,0x025c	,0x0001	), // LATIN SMALL LETTER REVERSED OPEN E
/*REVERSED           */	DEADTRANS(	L'E'	,0x025c	,0xa7ab	,0x0000	), // LATIN CAPITAL LETTER REVERSED OPEN E
/*REVERSED           */	DEADTRANS(	L'e'	,0x025c	,0x025c	,0x0000	), // LATIN SMALL LETTER REVERSED OPEN E
/*REVERSED           */	DEADTRANS(	0x2019	,0x1d19	,0x0295	,0x0000	), // LATIN LETTER PHARYNGEAL VOICED FRICATIVE
/*RING_ABOVE         */	DEADTRANS(	0x0020	,0x00e5	,0x030a	,0x0000	), // COMBINING RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	0x00eb	,0x00e5	,0x1ab1	,0x0000	), // COMBINING DIAERESIS-RING
/*RING_ABOVE         */	DEADTRANS(	0x00a0	,0x00e5	,0x02da	,0x0000	), // RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	0x202f	,0x00e5	,0x02da	,0x0000	), // RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	L'A'	,0x00e5	,0x00c5	,0x0000	), // LATIN CAPITAL LETTER A WITH RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	L'a'	,0x00e5	,0x00e5	,0x0000	), // LATIN SMALL LETTER A WITH RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	L'C'	,0x00e5	,0x2103	,0x0000	), // DEGREE CELSIUS
/*RING_ABOVE         */	DEADTRANS(	L'c'	,0x00e5	,0x2103	,0x0000	), // DEGREE CELSIUS
/*RING_ABOVE         */	DEADTRANS(	L'F'	,0x00e5	,0x2109	,0x0000	), // DEGREE FAHRENHEIT
/*RING_ABOVE         */	DEADTRANS(	L'f'	,0x00e5	,0x2109	,0x0000	), // DEGREE FAHRENHEIT
/*RING_ABOVE         */	DEADTRANS(	L'l'	,0x00e5	,0xab39	,0x0000	), // LATIN SMALL LETTER L WITH MIDDLE RING
/*RING_ABOVE         */	DEADTRANS(	L'o'	,0x00e5	,0x2c7a	,0x0000	), // LATIN SMALL LETTER O WITH LOW RING INSIDE
/*RING_ABOVE         */	DEADTRANS(	L'R'	,0x00e5	,0xa75a	,0x0000	), // LATIN CAPITAL LETTER R ROTUNDA
/*RING_ABOVE         */	DEADTRANS(	L'r'	,0x00e5	,0xa75b	,0x0000	), // LATIN SMALL LETTER R ROTUNDA
/*RING_ABOVE         */	DEADTRANS(	L'U'	,0x00e5	,0x016e	,0x0000	), // LATIN CAPITAL LETTER U WITH RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	L'u'	,0x00e5	,0x016f	,0x0000	), // LATIN SMALL LETTER U WITH RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	L'V'	,0x00e5	,0x1efc	,0x0000	), // LATIN CAPITAL LETTER MIDDLE-WELSH V
/*RING_ABOVE         */	DEADTRANS(	L'v'	,0x00e5	,0x1efd	,0x0000	), // LATIN SMALL LETTER MIDDLE-WELSH V
/*RING_ABOVE         */	DEADTRANS(	L'w'	,0x00e5	,0x1e98	,0x0000	), // LATIN SMALL LETTER W WITH RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	L'x'	,0x00e5	,0xab56	,0x0000	), // LATIN SMALL LETTER X WITH LOW RIGHT RING
/*RING_ABOVE         */	DEADTRANS(	L'y'	,0x00e5	,0x1e99	,0x0000	), // LATIN SMALL LETTER Y WITH RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	0x00f9	,0x00e5	,0xab54	,0x0000	), // LATIN SMALL LETTER CHI WITH LOW RIGHT RING
/*RING_ABOVE         */	DEADTRANS(	0x0026	,0x00e5	,0xab4c	,0x0000	), // LATIN SMALL LETTER SCRIPT R WITH RING
/*RING_ABOVE         */	DEADTRANS(	0x0027	,0x00e5	,0x01fb	,0x0001	), // LATIN SMALL LETTER A WITH RING ABOVE AND ACUTE
/*RING_ABOVE         */	DEADTRANS(	0x00a9	,0x00e5	,0xa75d	,0x0000	), // LATIN SMALL LETTER RUM ROTUNDA
/*RING_ABOVE         */	DEADTRANS(	L'R'	,0xa75d	,0xa75c	,0x0000	), // LATIN CAPITAL LETTER RUM ROTUNDA
/*RING_ABOVE         */	DEADTRANS(	L'r'	,0xa75d	,0xa75d	,0x0000	), // LATIN SMALL LETTER RUM ROTUNDA
/*RING_ABOVE         */	DEADTRANS(	0x00b0	,0x00e5	,0x1e01	,0x0001	), // LATIN SMALL LETTER A WITH RING BELOW
/*RING_ABOVE         */	DEADTRANS(	0x00e5	,0x00e5	,0x1e01	,0x0001	), // LATIN SMALL LETTER A WITH RING BELOW
/*RING_ABOVE         */	DEADTRANS(	0x00b5	,0x00e5	,0xab54	,0x0000	), // LATIN SMALL LETTER CHI WITH LOW RIGHT RING
/*RING_ABOVE         */	DEADTRANS(	0x00e1	,0x00e5	,0x01fb	,0x0001	), // LATIN SMALL LETTER A WITH RING ABOVE AND ACUTE
/*RING_ABOVE         */	DEADTRANS(	0x2610	,0x00e5	,0x274d	,0x0000	), // SHADOWED WHITE CIRCLE
/*RING_ABOVE&ACUTE   */	DEADTRANS(	L'A'	,0x01fb	,0x01fa	,0x0000	), // LATIN CAPITAL LETTER A WITH RING ABOVE AND ACUTE
/*RING_ABOVE&ACUTE   */	DEADTRANS(	L'a'	,0x01fb	,0x01fb	,0x0000	), // LATIN SMALL LETTER A WITH RING ABOVE AND ACUTE
/*RING_BELOW         */	DEADTRANS(	0x0020	,0x1e01	,0x0325	,0x0000	), // COMBINING RING BELOW
/*RING_BELOW         */	DEADTRANS(	0x00a0	,0x1e01	,0x02f3	,0x0000	), // MODIFIER LETTER LOW RING
/*RING_BELOW         */	DEADTRANS(	0x202f	,0x1e01	,0x02f3	,0x0000	), // MODIFIER LETTER LOW RING
/*RING_BELOW         */	DEADTRANS(	L'A'	,0x1e01	,0x1e00	,0x0000	), // LATIN CAPITAL LETTER A WITH RING BELOW
/*RING_BELOW         */	DEADTRANS(	L'a'	,0x1e01	,0x1e01	,0x0000	), // LATIN SMALL LETTER A WITH RING BELOW
/*RING_BELOW         */	DEADTRANS(	L'L'	,0x1e01	,0xa7ad	,0x0000	), // LATIN CAPITAL LETTER L WITH BELT
/*RING_BELOW         */	DEADTRANS(	L'l'	,0x1e01	,0x026c	,0x0000	), // LATIN SMALL LETTER L WITH BELT
/*RING_BELOW         */	DEADTRANS(	L'X'	,0x1e01	,0xab54	,0x0000	), // LATIN SMALL LETTER CHI WITH LOW RIGHT RING
/*RING_BELOW         */	DEADTRANS(	L'x'	,0x1e01	,0xab56	,0x0000	), // LATIN SMALL LETTER X WITH LOW RIGHT RING
/*SCRIPT             */	DEADTRANS(	L'G'	,0x2113	,0xa7ac	,0x0000	), // LATIN CAPITAL LETTER SCRIPT G
/*SCRIPT             */	DEADTRANS(	L'g'	,0x2113	,0x0261	,0x0000	), // LATIN SMALL LETTER SCRIPT G
/*SCRIPT             */	DEADTRANS(	L'L'	,0x2113	,0x2112	,0x0000	), // SCRIPT CAPITAL L
/*SCRIPT             */	DEADTRANS(	L'l'	,0x2113	,0x2113	,0x0000	), // SCRIPT SMALL L
/*SCRIPT             */	DEADTRANS(	L'r'	,0x2113	,0xab4b	,0x0000	), // LATIN SMALL LETTER SCRIPT R
/*SCRIPT             */	DEADTRANS(	L't'	,0x2113	,0x204a	,0x0000	), // TIRONIAN SIGN ET
/*SHORTENED          */	DEADTRANS(	L'r'	,0xab4e	,0xab47	,0x0000	), // LATIN SMALL LETTER R WITHOUT HANDLE
/*SHORTENED          */	DEADTRANS(	L'u'	,0xab4e	,0xab4e	,0x0000	), // LATIN SMALL LETTER U WITH SHORT RIGHT LEG
/*SHORTENED          */	DEADTRANS(	L'y'	,0xab4e	,0xab5a	,0x0000	), // LATIN SMALL LETTER Y WITH SHORT RIGHT LEG
/*SHORTENED          */	DEADTRANS(	0x0020	,0xab4e	,0x1dd3	,0x0000	), // COMBINING LATIN SMALL LETTER FLATTENED OPEN A ABOVE
/*SHORTENED          */	DEADTRANS(	0x002d	,0xab4e	,0xab4f	,0x0000	), // LATIN SMALL LETTER U BAR WITH SHORT RIGHT LEG
/*SPACE/FORMAT       */	DEADTRANS(	0x0020	,0x005f	,0x2423	,0x0000	), // OPEN BOX
/*SPACE/FORMAT       */	DEADTRANS(	0x00a0	,0x005f	,0x237d	,0x0000	), // SHOULDERED OPEN BOX
/*SPACE/FORMAT       */	DEADTRANS(	0x202f	,0x005f	,0x2422	,0x0000	), // BLANK SYMBOL
/*SPACE/FORMAT       */	DEADTRANS(	L'a'	,0x005f	,0x200c	,0x0000	), // ZERO WIDTH NON-JOINER
/*SPACE/FORMAT       */	DEADTRANS(	L'b'	,0x005f	,0x034f	,0x0000	), // COMBINING GRAPHEME JOINER
/*SPACE/FORMAT       */	DEADTRANS(	L'C'	,0x005f	,0x2001	,0x0000	), // EM QUAD
/*SPACE/FORMAT       */	DEADTRANS(	L'c'	,0x005f	,0x2003	,0x0000	), // EM SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'D'	,0x005f	,0x2000	,0x0000	), // EN QUAD
/*SPACE/FORMAT       */	DEADTRANS(	L'd'	,0x005f	,0x2002	,0x0000	), // EN SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'E'	,0x005f	,0x202a	,0x0001	), // LEFT-TO-RIGHT EMBEDDING
/*SPACE/FORMAT       */	DEADTRANS(	0x003c	,0x202a	,0x202b	,0x0000	), // RIGHT-TO-LEFT EMBEDDING
/*SPACE/FORMAT       */	DEADTRANS(	0x003e	,0x202a	,0x202a	,0x0000	), // LEFT-TO-RIGHT EMBEDDING
/*SPACE/FORMAT       */	DEADTRANS(	L'F'	,0x005f	,0x202d	,0x0001	), // LEFT-TO-RIGHT OVERRIDE
/*SPACE/FORMAT       */	DEADTRANS(	0x003c	,0x202d	,0x202e	,0x0000	), // RIGHT-TO-LEFT OVERRIDE
/*SPACE/FORMAT       */	DEADTRANS(	0x003e	,0x202d	,0x202d	,0x0000	), // LEFT-TO-RIGHT OVERRIDE
/*SPACE/FORMAT       */	DEADTRANS(	L'f'	,0x005f	,0x2009	,0x0000	), // THIN SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'G'	,0x005f	,0xfeff	,0x0000	), // ZERO WIDTH NO-BREAK SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'g'	,0x005f	,0x2060	,0x0000	), // WORD JOINER
/*SPACE/FORMAT       */	DEADTRANS(	L'I'	,0x005f	,0x2066	,0x0001	), // LEFT-TO-RIGHT ISOLATE
/*SPACE/FORMAT       */	DEADTRANS(	L'a'	,0x2066	,0x2068	,0x0000	), // FIRST STRONG ISOLATE
/*SPACE/FORMAT       */	DEADTRANS(	0x003c	,0x2066	,0x2067	,0x0000	), // RIGHT-TO-LEFT ISOLATE
/*SPACE/FORMAT       */	DEADTRANS(	0x003d	,0x2066	,0x2069	,0x0000	), // POP DIRECTIONAL ISOLATE
/*SPACE/FORMAT       */	DEADTRANS(	0x003e	,0x2066	,0x2066	,0x0000	), // LEFT-TO-RIGHT ISOLATE
/*SPACE/FORMAT       */	DEADTRANS(	L'i'	,0x005f	,0x00a0	,0x0000	), // NO-BREAK SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'j'	,0x005f	,0x202f	,0x0000	), // NARROW NO-BREAK SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'k'	,0x005f	,0x202f	,0x0000	), // NARROW NO-BREAK SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'l'	,0x005f	,0x200d	,0x0000	), // ZERO WIDTH JOINER
/*SPACE/FORMAT       */	DEADTRANS(	L'm'	,0x005f	,0x205f	,0x0000	), // MEDIUM MATHEMATICAL SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'p'	,0x005f	,0x2008	,0x0000	), // PUNCTUATION SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'q'	,0x005f	,0x2005	,0x0000	), // FOUR-PER-EM SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'S'	,0x005f	,0x3000	,0x0000	), // IDEOGRAPHIC SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L's'	,0x005f	,0x2006	,0x0000	), // SIX-PER-EM SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L't'	,0x005f	,0x2007	,0x0000	), // FIGURE SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'u'	,0x005f	,0x200a	,0x0000	), // HAIR SPACE
/*SPACE/FORMAT       */	DEADTRANS(	0x00c9	,0x005f	,0x202f	,0x0000	), // NARROW NO-BREAK SPACE
/*SPACE/FORMAT       */	DEADTRANS(	0x00e9	,0x005f	,0x202f	,0x0000	), // NARROW NO-BREAK SPACE
/*SPACE/FORMAT       */	DEADTRANS(	0x002f	,0x005f	,0x2028	,0x0000	), // LINE SEPARATOR
/*SPACE/FORMAT       */	DEADTRANS(	L'0'	,0x005f	,0x200b	,0x0000	), // ZERO WIDTH SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'1'	,0x005f	,0x2003	,0x0000	), // EM SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'2'	,0x005f	,0x2002	,0x0000	), // EN SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'3'	,0x005f	,0x2004	,0x0000	), // THREE-PER-EM SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'4'	,0x005f	,0x2005	,0x0000	), // FOUR-PER-EM SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'6'	,0x005f	,0x2006	,0x0000	), // SIX-PER-EM SPACE
/*SPACE/FORMAT       */	DEADTRANS(	0x003c	,0x005f	,0x200f	,0x0000	), // RIGHT-TO-LEFT MARK
/*SPACE/FORMAT       */	DEADTRANS(	0x003d	,0x005f	,0x202c	,0x0000	), // POP DIRECTIONAL FORMATTING
/*SPACE/FORMAT       */	DEADTRANS(	0x003e	,0x005f	,0x200e	,0x0000	), // LEFT-TO-RIGHT MARK
/*SPACE/FORMAT       */	DEADTRANS(	0x007c	,0x005f	,0x2029	,0x0000	), // PARAGRAPH SEPARATOR
/*STROKE&ACUTE       */	DEADTRANS(	L'O'	,0x01ff	,0x01fe	,0x0000	), // LATIN CAPITAL LETTER O WITH STROKE AND ACUTE
/*STROKE&ACUTE       */	DEADTRANS(	L'o'	,0x01ff	,0x01ff	,0x0000	), // LATIN SMALL LETTER O WITH STROKE AND ACUTE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x0020	,0x00f8	,0x0338	,0x0000	), // COMBINING LONG SOLIDUS OVERLAY
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'A'	,0x00f8	,0x023a	,0x0000	), // LATIN CAPITAL LETTER A WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'a'	,0x00f8	,0x2c65	,0x0000	), // LATIN SMALL LETTER A WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'C'	,0x00f8	,0x023b	,0x0000	), // LATIN CAPITAL LETTER C WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'c'	,0x00f8	,0x023c	,0x0000	), // LATIN SMALL LETTER C WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'd'	,0x00f8	,0xab3f	,0x0000	), // LATIN SMALL LETTER OPEN O WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'E'	,0x00f8	,0x0246	,0x0000	), // LATIN CAPITAL LETTER E WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'e'	,0x00f8	,0x0247	,0x0000	), // LATIN SMALL LETTER E WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'F'	,0x00f8	,0xa798	,0x0000	), // LATIN CAPITAL LETTER F WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'f'	,0x00f8	,0xa799	,0x0000	), // LATIN SMALL LETTER F WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'G'	,0x00f8	,0xa7a0	,0x0000	), // LATIN CAPITAL LETTER G WITH OBLIQUE STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'g'	,0x00f8	,0xa7a1	,0x0000	), // LATIN SMALL LETTER G WITH OBLIQUE STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'K'	,0x00f8	,0xa742	,0x0000	), // LATIN CAPITAL LETTER K WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'k'	,0x00f8	,0xa743	,0x0000	), // LATIN SMALL LETTER K WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'L'	,0x00f8	,0x0141	,0x0000	), // LATIN CAPITAL LETTER L WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'l'	,0x00f8	,0x0142	,0x0000	), // LATIN SMALL LETTER L WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'm'	,0x00f8	,0x20a5	,0x0000	), // MILL SIGN
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'N'	,0x00f8	,0xa7a4	,0x0000	), // LATIN CAPITAL LETTER N WITH OBLIQUE STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'n'	,0x00f8	,0xa7a5	,0x0000	), // LATIN SMALL LETTER N WITH OBLIQUE STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'O'	,0x00f8	,0x00d8	,0x0000	), // LATIN CAPITAL LETTER O WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'o'	,0x00f8	,0x00f8	,0x0000	), // LATIN SMALL LETTER O WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'Q'	,0x00f8	,0xa758	,0x0000	), // LATIN CAPITAL LETTER Q WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'q'	,0x00f8	,0xa759	,0x0000	), // LATIN SMALL LETTER Q WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'R'	,0x00f8	,0xa7a6	,0x0000	), // LATIN CAPITAL LETTER R WITH OBLIQUE STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'r'	,0x00f8	,0xa7a7	,0x0000	), // LATIN SMALL LETTER R WITH OBLIQUE STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'S'	,0x00f8	,0xa7a8	,0x0000	), // LATIN CAPITAL LETTER S WITH OBLIQUE STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L's'	,0x00f8	,0xa7a9	,0x0000	), // LATIN SMALL LETTER S WITH OBLIQUE STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'T'	,0x00f8	,0x023e	,0x0000	), // LATIN CAPITAL LETTER T WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L't'	,0x00f8	,0x2c66	,0x0000	), // LATIN SMALL LETTER T WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'U'	,0x00f8	,0xa7b8	,0x0000	), // LATIN CAPITAL LETTER U WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'u'	,0x00f8	,0xa7b9	,0x0000	), // LATIN SMALL LETTER U WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'V'	,0x00f8	,0xa75e	,0x0000	), // LATIN CAPITAL LETTER V WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'v'	,0x00f8	,0xa75f	,0x0000	), // LATIN SMALL LETTER V WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x0027	,0x00f8	,0x01ff	,0x0001	), // LATIN SMALL LETTER O WITH STROKE AND ACUTE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x002f	,0x00f8	,0xa743	,0x0001	), // LATIN SMALL LETTER K WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'0'	,0x00f8	,0x2205	,0x0000	), // EMPTY SET
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x003a	,0x00f8	,0x2e4a	,0x0000	), // DOTTED SOLIDUS
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x003d	,0x00f8	,0x2260	,0x0000	), // NOT EQUAL TO
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x005d	,0x00f8	,0xab3e	,0x0000	), // LATIN SMALL LETTER BLACKLETTER O WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x007c	,0x00f8	,0x1e9c	,0x0001	), // LATIN SMALL LETTER LONG S WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L's'	,0x1e9c	,0x1e9c	,0x0000	), // LATIN SMALL LETTER LONG S WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L't'	,0x1e9c	,0x1d7a	,0x0000	), // LATIN SMALL LETTER TH WITH STRIKETHROUGH
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x00a9	,0x00f8	,0x023c	,0x0001	), // LATIN SMALL LETTER C WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'o'	,0x023c	,0xab3f	,0x0000	), // LATIN SMALL LETTER OPEN O WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L's'	,0x023c	,0x1e9c	,0x0000	), // LATIN SMALL LETTER LONG S WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L't'	,0x023c	,0x1d7a	,0x0000	), // LATIN SMALL LETTER TH WITH STRIKETHROUGH
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x00a7	,0x00f8	,0xab3f	,0x0000	), // LATIN SMALL LETTER OPEN O WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x00e1	,0x00f8	,0x01ff	,0x0001	), // LATIN SMALL LETTER O WITH STROKE AND ACUTE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x00f5	,0x00f8	,0x034a	,0x0000	), // COMBINING NOT TILDE ABOVE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x00f8	,0x00f8	,0xa743	,0x0001	), // LATIN SMALL LETTER K WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x0254	,0x00f8	,0xab3f	,0x0000	), // LATIN SMALL LETTER OPEN O WITH STROKE
/*STROKE_SHORT       */	DEADTRANS(	0x0020	,0xa743	,0x0337	,0x0000	), // COMBINING SHORT SOLIDUS OVERLAY
/*STROKE_SHORT       */	DEADTRANS(	L'K'	,0xa743	,0xa7a2	,0x0000	), // LATIN CAPITAL LETTER K WITH OBLIQUE STROKE
/*STROKE_SHORT       */	DEADTRANS(	L'k'	,0xa743	,0xa7a3	,0x0000	), // LATIN SMALL LETTER K WITH OBLIQUE STROKE
/*SUBSCRIPT          */	DEADTRANS(	L'A'	,0x005f	,0x1d00	,0x0000	), // LATIN LETTER SMALL CAPITAL A
/*SUBSCRIPT          */	DEADTRANS(	L'B'	,0x005f	,0x0299	,0x0000	), // LATIN LETTER SMALL CAPITAL B
/*SUBSCRIPT          */	DEADTRANS(	L'e'	,0x005f	,0x2091	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER E
/*SUBSCRIPT          */	DEADTRANS(	L'H'	,0x005f	,0x029c	,0x0000	), // LATIN LETTER SMALL CAPITAL H
/*SUBSCRIPT          */	DEADTRANS(	L'h'	,0x005f	,0x2095	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER H
/*SUBSCRIPT          */	DEADTRANS(	L'J'	,0x005f	,0x1d0a	,0x0000	), // LATIN LETTER SMALL CAPITAL J
/*SUBSCRIPT          */	DEADTRANS(	L'K'	,0x005f	,0x1d0b	,0x0000	), // LATIN LETTER SMALL CAPITAL K
/*SUBSCRIPT          */	DEADTRANS(	L'L'	,0x005f	,0x029f	,0x0000	), // LATIN LETTER SMALL CAPITAL L
/*SUBSCRIPT          */	DEADTRANS(	L'M'	,0x005f	,0x1d0d	,0x0000	), // LATIN LETTER SMALL CAPITAL M
/*SUBSCRIPT          */	DEADTRANS(	L'N'	,0x005f	,0x0274	,0x0000	), // LATIN LETTER SMALL CAPITAL N
/*SUBSCRIPT          */	DEADTRANS(	L'n'	,0x005f	,0x2099	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER N
/*SUBSCRIPT          */	DEADTRANS(	L'O'	,0x005f	,0x1d0f	,0x0000	), // LATIN LETTER SMALL CAPITAL O
/*SUBSCRIPT          */	DEADTRANS(	L'o'	,0x005f	,0x2092	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER O
/*SUBSCRIPT          */	DEADTRANS(	L'P'	,0x005f	,0x1d18	,0x0000	), // LATIN LETTER SMALL CAPITAL P
/*SUBSCRIPT          */	DEADTRANS(	L'Q'	,0x005f	,0xa7af	,0x0000	), // LATIN LETTER SMALL CAPITAL Q
/*SUBSCRIPT          */	DEADTRANS(	L'R'	,0x005f	,0x0280	,0x0000	), // LATIN LETTER SMALL CAPITAL R
/*SUBSCRIPT          */	DEADTRANS(	L'r'	,0x005f	,0x1d63	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER R
/*SUBSCRIPT          */	DEADTRANS(	L'T'	,0x005f	,0x1d1b	,0x0000	), // LATIN LETTER SMALL CAPITAL T
/*SUBSCRIPT          */	DEADTRANS(	L'U'	,0x005f	,0x1d1c	,0x0000	), // LATIN LETTER SMALL CAPITAL U
/*SUBSCRIPT          */	DEADTRANS(	L'V'	,0x005f	,0x1d20	,0x0000	), // LATIN LETTER SMALL CAPITAL V
/*SUBSCRIPT          */	DEADTRANS(	L'v'	,0x005f	,0x1d65	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER V
/*SUBSCRIPT          */	DEADTRANS(	L'W'	,0x005f	,0x1d21	,0x0000	), // LATIN LETTER SMALL CAPITAL W
/*SUBSCRIPT          */	DEADTRANS(	L'x'	,0x005f	,0x2093	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER X
/*SUBSCRIPT          */	DEADTRANS(	L'Y'	,0x005f	,0x028f	,0x0000	), // LATIN LETTER SMALL CAPITAL Y
/*SUBSCRIPT          */	DEADTRANS(	L'Z'	,0x005f	,0x1d22	,0x0000	), // LATIN LETTER SMALL CAPITAL Z
/*SUBSCRIPT          */	DEADTRANS(	0x0152	,0x005f	,0x0276	,0x0000	), // LATIN LETTER SMALL CAPITAL OE
/*SUBSCRIPT          */	DEADTRANS(	0x0153	,0x005f	,0x0276	,0x0000	), // LATIN LETTER SMALL CAPITAL OE
/*SUBSCRIPT          */	DEADTRANS(	0x0023	,0x005f	,0x203f	,0x0001	), // UNDERTIE
/*SUBSCRIPT          */	DEADTRANS(	0x0021	,0x203f	,0xa71f	,0x0000	), // MODIFIER LETTER LOW INVERTED EXCLAMATION MARK
/*SUBSCRIPT          */	DEADTRANS(	0x0028	,0x203f	,0x2054	,0x0000	), // INVERTED UNDERTIE
/*SUBSCRIPT          */	DEADTRANS(	0x0029	,0x203f	,0x203f	,0x0000	), // UNDERTIE
/*SUBSCRIPT          */	DEADTRANS(	0x0025	,0x005f	,0xa71f	,0x0000	), // MODIFIER LETTER LOW INVERTED EXCLAMATION MARK
/*SUBSCRIPT          */	DEADTRANS(	0x0027	,0x005f	,0x02cf	,0x0001	), // MODIFIER LETTER LOW ACUTE ACCENT
/*SUBSCRIPT          */	DEADTRANS(	0x0028	,0x1e2b	,0x1d10	,0x0000	), // LATIN LETTER SMALL CAPITAL OPEN O
/*SUBSCRIPT          */	DEADTRANS(	0x002a	,0x005f	,0x204e	,0x0000	), // LOW ASTERISK
/*SUBSCRIPT          */	DEADTRANS(	0x002b	,0x005f	,0x208a	,0x0000	), // SUBSCRIPT PLUS SIGN
/*SUBSCRIPT          */	DEADTRANS(	0x002c	,0x005f	,0x0219	,0x0001	), // LATIN SMALL LETTER S WITH COMMA BELOW
/*SUBSCRIPT          */	DEADTRANS(	0x002d	,0x005f	,0xa751	,0x0001	), // LATIN SMALL LETTER P WITH STROKE THROUGH DESCENDER
/*SUBSCRIPT          */	DEADTRANS(	0x2190	,0x005f	,0x02ff	,0x0000	), // MODIFIER LETTER LOW LEFT ARROW
/*SUBSCRIPT          */	DEADTRANS(	0x002e	,0x005f	,0x1ecd	,0x0001	), // LATIN SMALL LETTER O WITH DOT BELOW
/*SUBSCRIPT          */	DEADTRANS(	L'5'	,0x005f	,0x2085	,0x0000	), // SUBSCRIPT FIVE
/*SUBSCRIPT          */	DEADTRANS(	L'7'	,0x005f	,0x2087	,0x0000	), // SUBSCRIPT SEVEN
/*SUBSCRIPT          */	DEADTRANS(	L'8'	,0x005f	,0x2088	,0x0000	), // SUBSCRIPT EIGHT
/*SUBSCRIPT          */	DEADTRANS(	L'9'	,0x005f	,0x2089	,0x0000	), // SUBSCRIPT NINE
/*SUBSCRIPT          */	DEADTRANS(	0x003a	,0x005f	,0x1e73	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS BELOW
/*SUBSCRIPT          */	DEADTRANS(	0x005b	,0x005f	,0x029b	,0x0000	), // LATIN LETTER SMALL CAPITAL G WITH HOOK
/*SUBSCRIPT          */	DEADTRANS(	0x005c	,0x005f	,0x1d0e	,0x0000	), // LATIN LETTER SMALL CAPITAL REVERSED N
/*SUBSCRIPT          */	DEADTRANS(	0x005d	,0x005f	,0x02fd	,0x0000	), // MODIFIER LETTER SHELF
/*SUBSCRIPT          */	DEADTRANS(	0x005e	,0x005f	,0x2038	,0x0000	), // CARET
/*SUBSCRIPT          */	DEADTRANS(	0x005f	,0x005f	,0x2038	,0x0001	), // CARET
/*SUBSCRIPT          */	DEADTRANS(	0x0060	,0x005f	,0x02ce	,0x0001	), // MODIFIER LETTER LOW GRAVE ACCENT
/*SUBSCRIPT          */	DEADTRANS(	L'v'	,0x02cc	,0x02ef	,0x0000	), // MODIFIER LETTER LOW DOWN ARROWHEAD
/*SUBSCRIPT          */	DEADTRANS(	0x003c	,0x02cc	,0x02f1	,0x0000	), // MODIFIER LETTER LOW LEFT ARROWHEAD
/*SUBSCRIPT          */	DEADTRANS(	0x003e	,0x02cc	,0x02f2	,0x0000	), // MODIFIER LETTER LOW RIGHT ARROWHEAD
/*SUBSCRIPT          */	DEADTRANS(	0x005e	,0x02cc	,0x02f0	,0x0000	), // MODIFIER LETTER LOW UP ARROWHEAD
/*SUBSCRIPT          */	DEADTRANS(	0x202f	,0x02cc	,0x02cc	,0x0000	), // MODIFIER LETTER LOW VERTICAL LINE
/*SUBSCRIPT          */	DEADTRANS(	0x007e	,0x005f	,0x1e75	,0x0001	), // LATIN SMALL LETTER U WITH TILDE BELOW
/*SUBSCRIPT          */	DEADTRANS(	0x00a9	,0x005f	,0x1d01	,0x0001	), // LATIN LETTER SMALL CAPITAL AE
/*SUBSCRIPT          */	DEADTRANS(	L'A'	,0x1d01	,0x1d01	,0x0000	), // LATIN LETTER SMALL CAPITAL AE
/*SUBSCRIPT          */	DEADTRANS(	L'e'	,0x1d01	,0x2094	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER SCHWA
/*SUBSCRIPT          */	DEADTRANS(	L'O'	,0x1d01	,0x0276	,0x0001	), // LATIN LETTER SMALL CAPITAL OE
/*SUBSCRIPT          */	DEADTRANS(	L'E'	,0x0276	,0x0276	,0x0000	), // LATIN LETTER SMALL CAPITAL OE
/*SUBSCRIPT          */	DEADTRANS(	L'U'	,0x0276	,0x1d15	,0x0000	), // LATIN LETTER SMALL CAPITAL OU
/*SUBSCRIPT          */	DEADTRANS(	L'R'	,0x1d01	,0xa776	,0x0000	), // LATIN LETTER SMALL CAPITAL RUM
/*SUBSCRIPT          */	DEADTRANS(	L'Z'	,0x1d01	,0x1d23	,0x0000	), // LATIN LETTER SMALL CAPITAL EZH
/*SUBSCRIPT          */	DEADTRANS(	L'z'	,0x1d01	,0x1d23	,0x0000	), // LATIN LETTER SMALL CAPITAL EZH
/*SUBSCRIPT          */	DEADTRANS(	0x002d	,0x1d01	,0x1d7b	,0x0001	), // LATIN SMALL CAPITAL LETTER I WITH STROKE
/*SUBSCRIPT          */	DEADTRANS(	L'B'	,0x1d7b	,0x1d03	,0x0000	), // LATIN LETTER SMALL CAPITAL BARRED B
/*SUBSCRIPT          */	DEADTRANS(	L'I'	,0x1d7b	,0x1d7b	,0x0000	), // LATIN SMALL CAPITAL LETTER I WITH STROKE
/*SUBSCRIPT          */	DEADTRANS(	L'L'	,0x1d7b	,0x1d0c	,0x0000	), // LATIN LETTER SMALL CAPITAL L WITH STROKE
/*SUBSCRIPT          */	DEADTRANS(	L'U'	,0x1d7b	,0x1d7e	,0x0000	), // LATIN SMALL CAPITAL LETTER U WITH STROKE
/*SUBSCRIPT          */	DEADTRANS(	0x00b0	,0x005f	,0x1e01	,0x0001	), // LATIN SMALL LETTER A WITH RING BELOW
/*SUBSCRIPT          */	DEADTRANS(	0x00d0	,0x005f	,0x1d06	,0x0000	), // LATIN LETTER SMALL CAPITAL ETH
/*SUBSCRIPT          */	DEADTRANS(	0x00e1	,0x005f	,0x02cf	,0x0001	), // MODIFIER LETTER LOW ACUTE ACCENT
/*SUBSCRIPT          */	DEADTRANS(	0x00eb	,0x005f	,0x1e73	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS BELOW
/*SUBSCRIPT          */	DEADTRANS(	0x00f2	,0x005f	,0x02ce	,0x0001	), // MODIFIER LETTER LOW GRAVE ACCENT
/*SUBSCRIPT          */	DEADTRANS(	0x00f5	,0x005f	,0x1e75	,0x0001	), // LATIN SMALL LETTER U WITH TILDE BELOW
/*SUBSCRIPT          */	DEADTRANS(	0x2212	,0x005f	,0x208b	,0x0000	), // SUBSCRIPT MINUS
/*SUBSCRIPT          */	DEADTRANS(	0x022f	,0x005f	,0x1ecd	,0x0001	), // LATIN SMALL LETTER O WITH DOT BELOW
/*SUBSCRIPT          */	DEADTRANS(	0x014d	,0x005f	,0x1e07	,0x0001	), // LATIN SMALL LETTER B WITH LINE BELOW
/*SUPERSCRIPT        */	DEADTRANS(	0x202f	,0x005e	,0x2191	,0x0000	), // UPWARDS ARROW
/*SUPERSCRIPT        */	DEADTRANS(	L'A'	,0x005e	,0x1d2c	,0x0000	), // MODIFIER LETTER CAPITAL A
/*SUPERSCRIPT        */	DEADTRANS(	L'a'	,0x005e	,0x1d43	,0x0000	), // MODIFIER LETTER SMALL A
/*SUPERSCRIPT        */	DEADTRANS(	L'B'	,0x005e	,0x1d2e	,0x0000	), // MODIFIER LETTER CAPITAL B
/*SUPERSCRIPT        */	DEADTRANS(	L'b'	,0x005e	,0x1d47	,0x0000	), // MODIFIER LETTER SMALL B
/*SUPERSCRIPT        */	DEADTRANS(	L'c'	,0x005e	,0x1d9c	,0x0000	), // MODIFIER LETTER SMALL C
/*SUPERSCRIPT        */	DEADTRANS(	L'D'	,0x005e	,0x1d30	,0x0000	), // MODIFIER LETTER CAPITAL D
/*SUPERSCRIPT        */	DEADTRANS(	L'd'	,0x005e	,0x1d48	,0x0000	), // MODIFIER LETTER SMALL D
/*SUPERSCRIPT        */	DEADTRANS(	L'E'	,0x005e	,0x1d31	,0x0000	), // MODIFIER LETTER CAPITAL E
/*SUPERSCRIPT        */	DEADTRANS(	L'e'	,0x005e	,0x1d49	,0x0000	), // MODIFIER LETTER SMALL E
/*SUPERSCRIPT        */	DEADTRANS(	L'f'	,0x005e	,0x1da0	,0x0000	), // MODIFIER LETTER SMALL F
/*SUPERSCRIPT        */	DEADTRANS(	L'G'	,0x005e	,0x1d33	,0x0000	), // MODIFIER LETTER CAPITAL G
/*SUPERSCRIPT        */	DEADTRANS(	L'g'	,0x005e	,0x1d4d	,0x0000	), // MODIFIER LETTER SMALL G
/*SUPERSCRIPT        */	DEADTRANS(	L'H'	,0x005e	,0x1d34	,0x0000	), // MODIFIER LETTER CAPITAL H
/*SUPERSCRIPT        */	DEADTRANS(	L'h'	,0x005e	,0x02b0	,0x0000	), // MODIFIER LETTER SMALL H
/*SUPERSCRIPT        */	DEADTRANS(	L'I'	,0x005e	,0x1d35	,0x0000	), // MODIFIER LETTER CAPITAL I
/*SUPERSCRIPT        */	DEADTRANS(	L'i'	,0x005e	,0x2071	,0x0000	), // SUPERSCRIPT LATIN SMALL LETTER I
/*SUPERSCRIPT        */	DEADTRANS(	L'J'	,0x005e	,0x1d36	,0x0000	), // MODIFIER LETTER CAPITAL J
/*SUPERSCRIPT        */	DEADTRANS(	L'j'	,0x005e	,0x02b2	,0x0000	), // MODIFIER LETTER SMALL J
/*SUPERSCRIPT        */	DEADTRANS(	L'K'	,0x005e	,0x1d37	,0x0000	), // MODIFIER LETTER CAPITAL K
/*SUPERSCRIPT        */	DEADTRANS(	L'k'	,0x005e	,0x1d4f	,0x0000	), // MODIFIER LETTER SMALL K
/*SUPERSCRIPT        */	DEADTRANS(	L'L'	,0x005e	,0x1d38	,0x0000	), // MODIFIER LETTER CAPITAL L
/*SUPERSCRIPT        */	DEADTRANS(	L'l'	,0x005e	,0x02e1	,0x0000	), // MODIFIER LETTER SMALL L
/*SUPERSCRIPT        */	DEADTRANS(	L'M'	,0x005e	,0x1d39	,0x0000	), // MODIFIER LETTER CAPITAL M
/*SUPERSCRIPT        */	DEADTRANS(	L'm'	,0x005e	,0x1d50	,0x0000	), // MODIFIER LETTER SMALL M
/*SUPERSCRIPT        */	DEADTRANS(	L'N'	,0x005e	,0x1d3a	,0x0000	), // MODIFIER LETTER CAPITAL N
/*SUPERSCRIPT        */	DEADTRANS(	L'n'	,0x005e	,0x207f	,0x0000	), // SUPERSCRIPT LATIN SMALL LETTER N
/*SUPERSCRIPT        */	DEADTRANS(	L'O'	,0x005e	,0x1d3c	,0x0000	), // MODIFIER LETTER CAPITAL O
/*SUPERSCRIPT        */	DEADTRANS(	L'o'	,0x005e	,0x1d52	,0x0000	), // MODIFIER LETTER SMALL O
/*SUPERSCRIPT        */	DEADTRANS(	L'P'	,0x005e	,0x1d3e	,0x0000	), // MODIFIER LETTER CAPITAL P
/*SUPERSCRIPT        */	DEADTRANS(	L'p'	,0x005e	,0x1d56	,0x0000	), // MODIFIER LETTER SMALL P
/*SUPERSCRIPT        */	DEADTRANS(	L'R'	,0x005e	,0x1d3f	,0x0000	), // MODIFIER LETTER CAPITAL R
/*SUPERSCRIPT        */	DEADTRANS(	L'r'	,0x005e	,0x02b3	,0x0000	), // MODIFIER LETTER SMALL R
/*SUPERSCRIPT        */	DEADTRANS(	L's'	,0x005e	,0x02e2	,0x0000	), // MODIFIER LETTER SMALL S
/*SUPERSCRIPT        */	DEADTRANS(	L'T'	,0x005e	,0x1d40	,0x0000	), // MODIFIER LETTER CAPITAL T
/*SUPERSCRIPT        */	DEADTRANS(	L't'	,0x005e	,0x1d57	,0x0000	), // MODIFIER LETTER SMALL T
/*SUPERSCRIPT        */	DEADTRANS(	L'U'	,0x005e	,0x1d41	,0x0000	), // MODIFIER LETTER CAPITAL U
/*SUPERSCRIPT        */	DEADTRANS(	L'u'	,0x005e	,0x1d58	,0x0000	), // MODIFIER LETTER SMALL U
/*SUPERSCRIPT        */	DEADTRANS(	L'V'	,0x005e	,0x2c7d	,0x0000	), // MODIFIER LETTER CAPITAL V
/*SUPERSCRIPT        */	DEADTRANS(	L'v'	,0x005e	,0x1d5b	,0x0000	), // MODIFIER LETTER SMALL V
/*SUPERSCRIPT        */	DEADTRANS(	L'W'	,0x005e	,0x1d42	,0x0000	), // MODIFIER LETTER CAPITAL W
/*SUPERSCRIPT        */	DEADTRANS(	L'w'	,0x005e	,0x02b7	,0x0000	), // MODIFIER LETTER SMALL W
/*SUPERSCRIPT        */	DEADTRANS(	L'x'	,0x005e	,0x02e3	,0x0000	), // MODIFIER LETTER SMALL X
/*SUPERSCRIPT        */	DEADTRANS(	L'y'	,0x005e	,0x02b8	,0x0000	), // MODIFIER LETTER SMALL Y
/*SUPERSCRIPT        */	DEADTRANS(	L'z'	,0x005e	,0x1dbb	,0x0000	), // MODIFIER LETTER SMALL Z
/*SUPERSCRIPT        */	DEADTRANS(	0x00c6	,0x005e	,0x1d2d	,0x0000	), // MODIFIER LETTER CAPITAL AE
/*SUPERSCRIPT        */	DEADTRANS(	0x00e8	,0x005e	,0x02c0	,0x0000	), // MODIFIER LETTER GLOTTAL STOP
/*SUPERSCRIPT        */	DEADTRANS(	0x0153	,0x005e	,0xa7f9	,0x0000	), // MODIFIER LETTER SMALL LIGATURE OE
/*SUPERSCRIPT        */	DEADTRANS(	L'a'	,0x02e0	,0x1d45	,0x0000	), // MODIFIER LETTER SMALL ALPHA
/*SUPERSCRIPT        */	DEADTRANS(	L'b'	,0x02e0	,0x1d5d	,0x0000	), // MODIFIER LETTER SMALL BETA
/*SUPERSCRIPT        */	DEADTRANS(	L'd'	,0x02e0	,0x1d5f	,0x0000	), // MODIFIER LETTER SMALL DELTA
/*SUPERSCRIPT        */	DEADTRANS(	L'e'	,0x02e0	,0x1d4b	,0x0000	), // MODIFIER LETTER SMALL OPEN E
/*SUPERSCRIPT        */	DEADTRANS(	L'f'	,0x02e0	,0x1d60	,0x0000	), // MODIFIER LETTER SMALL GREEK PHI
/*SUPERSCRIPT        */	DEADTRANS(	L'g'	,0x02e0	,0x02e0	,0x0000	), // MODIFIER LETTER SMALL GAMMA
/*SUPERSCRIPT        */	DEADTRANS(	L'i'	,0x02e0	,0x1da5	,0x0000	), // MODIFIER LETTER SMALL IOTA
/*SUPERSCRIPT        */	DEADTRANS(	L't'	,0x02e0	,0x1dbf	,0x0000	), // MODIFIER LETTER SMALL THETA
/*SUPERSCRIPT        */	DEADTRANS(	L'u'	,0x02e0	,0x1db7	,0x0000	), // MODIFIER LETTER SMALL UPSILON
/*SUPERSCRIPT        */	DEADTRANS(	L'x'	,0x02e0	,0x1d61	,0x0000	), // MODIFIER LETTER SMALL CHI
/*SUPERSCRIPT        */	DEADTRANS(	0x0021	,0x005e	,0xa71d	,0x0000	), // MODIFIER LETTER RAISED EXCLAMATION MARK
/*SUPERSCRIPT        */	DEADTRANS(	0x0023	,0x005e	,0x02b4	,0x0001	), // MODIFIER LETTER SMALL TURNED R
/*SUPERSCRIPT        */	DEADTRANS(	L'a'	,0x02b4	,0x1d44	,0x0000	), // MODIFIER LETTER SMALL TURNED A
/*SUPERSCRIPT        */	DEADTRANS(	L'c'	,0x02b4	,0x1d53	,0x0000	), // MODIFIER LETTER SMALL OPEN O
/*SUPERSCRIPT        */	DEADTRANS(	L'f'	,0x02b4	,0x1da1	,0x0000	), // MODIFIER LETTER SMALL DOTLESS J WITH STROKE
/*SUPERSCRIPT        */	DEADTRANS(	L'h'	,0x02b4	,0x1da3	,0x0000	), // MODIFIER LETTER SMALL TURNED H
/*SUPERSCRIPT        */	DEADTRANS(	L'i'	,0x02b4	,0x1d4e	,0x0000	), // MODIFIER LETTER SMALL TURNED I
/*SUPERSCRIPT        */	DEADTRANS(	L'l'	,0x02b4	,0x1dad	,0x0000	), // MODIFIER LETTER SMALL TURNED M WITH LONG LEG
/*SUPERSCRIPT        */	DEADTRANS(	L'm'	,0x02b4	,0x1d5a	,0x0000	), // MODIFIER LETTER SMALL TURNED M
/*SUPERSCRIPT        */	DEADTRANS(	L'r'	,0x02b4	,0x02b4	,0x0000	), // MODIFIER LETTER SMALL TURNED R
/*SUPERSCRIPT        */	DEADTRANS(	L's'	,0x02b4	,0xab5d	,0x0000	), // MODIFIER LETTER SMALL L WITH INVERTED LAZY S
/*SUPERSCRIPT        */	DEADTRANS(	L'v'	,0x02b4	,0x1dba	,0x0000	), // MODIFIER LETTER SMALL TURNED V
/*SUPERSCRIPT        */	DEADTRANS(	0x0153	,0x02b4	,0x1d46	,0x0000	), // MODIFIER LETTER SMALL TURNED AE
/*SUPERSCRIPT        */	DEADTRANS(	0x00f9	,0x02b4	,0x1d4c	,0x0001	), // MODIFIER LETTER SMALL TURNED OPEN E
/*SUPERSCRIPT        */	DEADTRANS(	L'a'	,0x1d4c	,0x1d9b	,0x0000	), // MODIFIER LETTER SMALL TURNED ALPHA
/*SUPERSCRIPT        */	DEADTRANS(	L'e'	,0x1d4c	,0x1d4c	,0x0000	), // MODIFIER LETTER SMALL TURNED OPEN E
/*SUPERSCRIPT        */	DEADTRANS(	0x0021	,0x02b4	,0xa71e	,0x0000	), // MODIFIER LETTER RAISED INVERTED EXCLAMATION MARK
/*SUPERSCRIPT        */	DEADTRANS(	0x0023	,0x02b4	,0x1d59	,0x0001	), // MODIFIER LETTER SMALL SIDEWAYS U
/*SUPERSCRIPT        */	DEADTRANS(	L'F'	,0x1d59	,0xa720	,0x0000	), // MODIFIER LETTER STRESS AND HIGH TONE
/*SUPERSCRIPT        */	DEADTRANS(	L'L'	,0x1d59	,0xa71a	,0x0000	), // MODIFIER LETTER LOWER RIGHT CORNER ANGLE
/*SUPERSCRIPT        */	DEADTRANS(	L'u'	,0x1d59	,0x1d59	,0x0000	), // MODIFIER LETTER SMALL SIDEWAYS U
/*SUPERSCRIPT        */	DEADTRANS(	0x005b	,0x02b4	,0x02b5	,0x0000	), // MODIFIER LETTER SMALL TURNED R WITH HOOK
/*SUPERSCRIPT        */	DEADTRANS(	0x00a9	,0x02b4	,0x1d46	,0x0000	), // MODIFIER LETTER SMALL TURNED AE
/*SUPERSCRIPT        */	DEADTRANS(	0x00b5	,0x02b4	,0x1d4c	,0x0001	), // MODIFIER LETTER SMALL TURNED OPEN E
/*SUPERSCRIPT        */	DEADTRANS(	0x00f2	,0x02b4	,0x1d46	,0x0000	), // MODIFIER LETTER SMALL TURNED AE
/*SUPERSCRIPT        */	DEADTRANS(	0x0024	,0x005e	,0x017f	,0x0000	), // LATIN SMALL LETTER LONG S
/*SUPERSCRIPT        */	DEADTRANS(	0x0025	,0x005e	,0xa71e	,0x0000	), // MODIFIER LETTER RAISED INVERTED EXCLAMATION MARK
/*SUPERSCRIPT        */	DEADTRANS(	0x0026	,0x005e	,0x1da2	,0x0000	), // MODIFIER LETTER SMALL SCRIPT G
/*SUPERSCRIPT        */	DEADTRANS(	0x0027	,0x005e	,0x02cf	,0x0001	), // MODIFIER LETTER LOW ACUTE ACCENT
/*SUPERSCRIPT        */	DEADTRANS(	0x0028	,0x005e	,0x207d	,0x0000	), // SUPERSCRIPT LEFT PARENTHESIS
/*SUPERSCRIPT        */	DEADTRANS(	0x0029	,0x005e	,0x207e	,0x0000	), // SUPERSCRIPT RIGHT PARENTHESIS
/*SUPERSCRIPT        */	DEADTRANS(	0x002a	,0x005e	,0x1d5c	,0x0000	), // MODIFIER LETTER SMALL AIN
/*SUPERSCRIPT        */	DEADTRANS(	0x002b	,0x005e	,0x207a	,0x0000	), // SUPERSCRIPT PLUS SIGN
/*SUPERSCRIPT        */	DEADTRANS(	0x002c	,0x005e	,0x0219	,0x0001	), // LATIN SMALL LETTER S WITH COMMA BELOW
/*SUPERSCRIPT        */	DEADTRANS(	0x002d	,0x005e	,0x0183	,0x0001	), // LATIN SMALL LETTER B WITH TOPBAR
/*SUPERSCRIPT        */	DEADTRANS(	0x002e	,0x005e	,0x02d9	,0x0001	), // DOT ABOVE
/*SUPERSCRIPT        */	DEADTRANS(	0x002f	,0x005e	,0x2044	,0x0000	), // FRACTION SLASH
/*SUPERSCRIPT        */	DEADTRANS(	L'0'	,0x005e	,0x2070	,0x0000	), // SUPERSCRIPT ZERO
/*SUPERSCRIPT        */	DEADTRANS(	L'1'	,0x005e	,0x00b9	,0x0000	), // SUPERSCRIPT ONE
/*SUPERSCRIPT        */	DEADTRANS(	L'2'	,0x005e	,0x00b2	,0x0000	), // SUPERSCRIPT TWO
/*SUPERSCRIPT        */	DEADTRANS(	L'3'	,0x005e	,0x00b3	,0x0000	), // SUPERSCRIPT THREE
/*SUPERSCRIPT        */	DEADTRANS(	L'4'	,0x005e	,0x2074	,0x0000	), // SUPERSCRIPT FOUR
/*SUPERSCRIPT        */	DEADTRANS(	L'5'	,0x005e	,0x2075	,0x0000	), // SUPERSCRIPT FIVE
/*SUPERSCRIPT        */	DEADTRANS(	L'6'	,0x005e	,0x2076	,0x0000	), // SUPERSCRIPT SIX
/*SUPERSCRIPT        */	DEADTRANS(	L'7'	,0x005e	,0x2077	,0x0000	), // SUPERSCRIPT SEVEN
/*SUPERSCRIPT        */	DEADTRANS(	L'8'	,0x005e	,0x2078	,0x0000	), // SUPERSCRIPT EIGHT
/*SUPERSCRIPT        */	DEADTRANS(	L'9'	,0x005e	,0x2079	,0x0000	), // SUPERSCRIPT NINE
/*SUPERSCRIPT        */	DEADTRANS(	0x003a	,0x005e	,0x02f8	,0x0000	), // MODIFIER LETTER RAISED COLON
/*SUPERSCRIPT        */	DEADTRANS(	0x003d	,0x005e	,0x207c	,0x0000	), // SUPERSCRIPT EQUALS SIGN
/*SUPERSCRIPT        */	DEADTRANS(	0x005b	,0x005e	,0x02b1	,0x0001	), // MODIFIER LETTER SMALL H WITH HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'h'	,0x02b1	,0x02b1	,0x0000	), // MODIFIER LETTER SMALL H WITH HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'v'	,0x02b1	,0x1db9	,0x0000	), // MODIFIER LETTER SMALL V WITH HOOK
/*SUPERSCRIPT        */	DEADTRANS(	0x005c	,0x005e	,0x1d32	,0x0001	), // MODIFIER LETTER CAPITAL REVERSED E
/*SUPERSCRIPT        */	DEADTRANS(	L'E'	,0x1d32	,0x1d32	,0x0000	), // MODIFIER LETTER CAPITAL REVERSED E
/*SUPERSCRIPT        */	DEADTRANS(	L'N'	,0x1d32	,0x1d3b	,0x0000	), // MODIFIER LETTER CAPITAL REVERSED N
/*SUPERSCRIPT        */	DEADTRANS(	0x00f2	,0x1d32	,0x02e4	,0x0000	), // MODIFIER LETTER SMALL REVERSED GLOTTAL STOP
/*SUPERSCRIPT        */	DEADTRANS(	0x00f9	,0x1d32	,0x02c1	,0x0000	), // MODIFIER LETTER REVERSED GLOTTAL STOP
/*SUPERSCRIPT        */	DEADTRANS(	0x0027	,0x1d32	,0x02c1	,0x0000	), // MODIFIER LETTER REVERSED GLOTTAL STOP
/*SUPERSCRIPT        */	DEADTRANS(	0x00b5	,0x1d32	,0x1d9f	,0x0000	), // MODIFIER LETTER SMALL REVERSED OPEN E
/*SUPERSCRIPT        */	DEADTRANS(	0x2019	,0x1d32	,0x02c1	,0x0000	), // MODIFIER LETTER REVERSED GLOTTAL STOP
/*SUPERSCRIPT        */	DEADTRANS(	0x005d	,0x005e	,0x1db5	,0x0001	), // MODIFIER LETTER SMALL T WITH PALATAL HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'l'	,0x1db5	,0x1daa	,0x0000	), // MODIFIER LETTER SMALL L WITH PALATAL HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L't'	,0x1db5	,0x1db5	,0x0000	), // MODIFIER LETTER SMALL T WITH PALATAL HOOK
/*SUPERSCRIPT        */	DEADTRANS(	0x005e	,0x005e	,0x2193	,0x0001	), // DOWNWARDS ARROW
/*SUPERSCRIPT        */	DEADTRANS(	0x005f	,0x005e	,0x203e	,0x0000	), // OVERLINE
/*SUPERSCRIPT        */	DEADTRANS(	0x0060	,0x005e	,0x02ce	,0x0001	), // MODIFIER LETTER LOW GRAVE ACCENT
/*SUPERSCRIPT        */	DEADTRANS(	0x007b	,0x005e	,0x1dbc	,0x0001	), // MODIFIER LETTER SMALL Z WITH RETROFLEX HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'l'	,0x1dbc	,0x1da9	,0x0000	), // MODIFIER LETTER SMALL L WITH RETROFLEX HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'n'	,0x1dbc	,0x1daf	,0x0000	), // MODIFIER LETTER SMALL N WITH RETROFLEX HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L's'	,0x1dbc	,0x1db3	,0x0000	), // MODIFIER LETTER SMALL S WITH HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'z'	,0x1dbc	,0x1dbc	,0x0000	), // MODIFIER LETTER SMALL Z WITH RETROFLEX HOOK
/*SUPERSCRIPT        */	DEADTRANS(	0x007d	,0x005e	,0xab5f	,0x0001	), // MODIFIER LETTER SMALL U WITH LEFT HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'm'	,0xab5f	,0x1dac	,0x0000	), // MODIFIER LETTER SMALL M WITH HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'n'	,0xab5f	,0x1dae	,0x0000	), // MODIFIER LETTER SMALL N WITH LEFT HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'u'	,0xab5f	,0xab5f	,0x0000	), // MODIFIER LETTER SMALL U WITH LEFT HOOK
/*SUPERSCRIPT        */	DEADTRANS(	0x007e	,0x005e	,0xab5e	,0x0001	), // MODIFIER LETTER SMALL L WITH MIDDLE TILDE
/*SUPERSCRIPT        */	DEADTRANS(	L'l'	,0xab5e	,0xab5e	,0x0000	), // MODIFIER LETTER SMALL L WITH MIDDLE TILDE
/*SUPERSCRIPT        */	DEADTRANS(	0x00a9	,0x005e	,0xa7f9	,0x0001	), // MODIFIER LETTER SMALL LIGATURE OE
/*SUPERSCRIPT        */	DEADTRANS(	L'c'	,0xa7f9	,0x1d9d	,0x0000	), // MODIFIER LETTER SMALL C WITH CURL
/*SUPERSCRIPT        */	DEADTRANS(	L'd'	,0xa7f9	,0x1d9e	,0x0000	), // MODIFIER LETTER SMALL ETH
/*SUPERSCRIPT        */	DEADTRANS(	0x0259	,0xa7f9	,0x1d4a	,0x0000	), // MODIFIER LETTER SMALL SCHWA
/*SUPERSCRIPT        */	DEADTRANS(	L'h'	,0xa7f9	,0xab5c	,0x0000	), // MODIFIER LETTER SMALL HENG
/*SUPERSCRIPT        */	DEADTRANS(	L'j'	,0xa7f9	,0x1da8	,0x0000	), // MODIFIER LETTER SMALL J WITH CROSSED-TAIL
/*SUPERSCRIPT        */	DEADTRANS(	0x014b	,0xa7f9	,0x1d51	,0x0000	), // MODIFIER LETTER SMALL ENG
/*SUPERSCRIPT        */	DEADTRANS(	L'O'	,0xa7f9	,0x1d3d	,0x0000	), // MODIFIER LETTER CAPITAL OU
/*SUPERSCRIPT        */	DEADTRANS(	L'o'	,0xa7f9	,0x1d55	,0x0001	), // MODIFIER LETTER SMALL BOTTOM HALF O
/*SUPERSCRIPT        */	DEADTRANS(	0x0028	,0x1d55	,0x1d54	,0x0000	), // MODIFIER LETTER SMALL TOP HALF O
/*SUPERSCRIPT        */	DEADTRANS(	0x0029	,0x1d55	,0x1d55	,0x0000	), // MODIFIER LETTER SMALL BOTTOM HALF O
/*SUPERSCRIPT        */	DEADTRANS(	0x0283	,0xa7f9	,0x1db4	,0x0000	), // MODIFIER LETTER SMALL ESH
/*SUPERSCRIPT        */	DEADTRANS(	0x0292	,0xa7f9	,0x1dbe	,0x0000	), // MODIFIER LETTER SMALL EZH
/*SUPERSCRIPT        */	DEADTRANS(	0x0153	,0xa7f9	,0x1d9d	,0x0001	), // MODIFIER LETTER SMALL C WITH CURL
/*SUPERSCRIPT        */	DEADTRANS(	L'c'	,0x1d9d	,0x1d9d	,0x0000	), // MODIFIER LETTER SMALL C WITH CURL
/*SUPERSCRIPT        */	DEADTRANS(	L'j'	,0x1d9d	,0x1da8	,0x0000	), // MODIFIER LETTER SMALL J WITH CROSSED-TAIL
/*SUPERSCRIPT        */	DEADTRANS(	L'z'	,0x1d9d	,0x1dbd	,0x0000	), // MODIFIER LETTER SMALL Z WITH CURL
/*SUPERSCRIPT        */	DEADTRANS(	0x0153	,0x1d9d	,0x1da8	,0x0000	), // MODIFIER LETTER SMALL J WITH CROSSED-TAIL
/*SUPERSCRIPT        */	DEADTRANS(	0x0026	,0xa7f9	,0x1dbd	,0x0000	), // MODIFIER LETTER SMALL Z WITH CURL
/*SUPERSCRIPT        */	DEADTRANS(	0x002d	,0xa7f9	,0x1d2f	,0x0000	), // MODIFIER LETTER CAPITAL BARRED B
/*SUPERSCRIPT        */	DEADTRANS(	0x00a7	,0x005e	,0x2040	,0x0000	), // CHARACTER TIE
/*SUPERSCRIPT        */	DEADTRANS(	0x00b0	,0x005e	,0x1e01	,0x0001	), // LATIN SMALL LETTER A WITH RING BELOW
/*SUPERSCRIPT        */	DEADTRANS(	0x00b5	,0x005e	,0x02e0	,0x0001	), // MODIFIER LETTER SMALL GAMMA
/*SUPERSCRIPT        */	DEADTRANS(	0x00ea	,0x005e	,0x02df	,0x0001	), // MODIFIER LETTER CROSS ACCENT
/*SUPERSCRIPT        */	DEADTRANS(	L'x'	,0x02df	,0x02df	,0x0000	), // MODIFIER LETTER CROSS ACCENT
/*SUPERSCRIPT        */	DEADTRANS(	0x00f9	,0x005e	,0x02c8	,0x0000	), // MODIFIER LETTER VERTICAL LINE
/*SUPERSCRIPT        */	DEADTRANS(	0x0028	,0x02df	,0x02bf	,0x0000	), // MODIFIER LETTER LEFT HALF RING
/*SUPERSCRIPT        */	DEADTRANS(	0x0029	,0x02df	,0x02be	,0x0000	), // MODIFIER LETTER RIGHT HALF RING
/*SUPERSCRIPT        */	DEADTRANS(	0x002b	,0x02df	,0x02d6	,0x0000	), // MODIFIER LETTER PLUS SIGN
/*SUPERSCRIPT        */	DEADTRANS(	0x002d	,0x02df	,0x02d7	,0x0000	), // MODIFIER LETTER MINUS SIGN
/*SUPERSCRIPT        */	DEADTRANS(	0x003d	,0x02df	,0x02ed	,0x0000	), // MODIFIER LETTER UNASPIRATED
/*SUPERSCRIPT        */	DEADTRANS(	0x005b	,0x02df	,0x02de	,0x0000	), // MODIFIER LETTER RHOTIC HOOK
/*SUPERSCRIPT        */	DEADTRANS(	0x2019	,0x005e	,0x02c8	,0x0000	), // MODIFIER LETTER VERTICAL LINE
/*SUPERSCRIPT        */	DEADTRANS(	0x00eb	,0x005e	,0x02b6	,0x0001	), // MODIFIER LETTER SMALL CAPITAL INVERTED R
/*SUPERSCRIPT        */	DEADTRANS(	L'H'	,0x02b6	,0x1d78	,0x0000	), // MODIFIER LETTER CYRILLIC EN
/*SUPERSCRIPT        */	DEADTRANS(	L'I'	,0x02b6	,0x1da6	,0x0000	), // MODIFIER LETTER SMALL CAPITAL I
/*SUPERSCRIPT        */	DEADTRANS(	L'L'	,0x02b6	,0x1dab	,0x0000	), // MODIFIER LETTER SMALL CAPITAL L
/*SUPERSCRIPT        */	DEADTRANS(	L'N'	,0x02b6	,0x1db0	,0x0000	), // MODIFIER LETTER SMALL CAPITAL N
/*SUPERSCRIPT        */	DEADTRANS(	L'U'	,0x02b6	,0x1db8	,0x0000	), // MODIFIER LETTER SMALL CAPITAL U
/*SUPERSCRIPT        */	DEADTRANS(	0x0025	,0x02b6	,0x02b6	,0x0000	), // MODIFIER LETTER SMALL CAPITAL INVERTED R
/*SUPERSCRIPT        */	DEADTRANS(	0x0028	,0x02d5	,0x02d3	,0x0000	), // MODIFIER LETTER CENTRED LEFT HALF RING
/*SUPERSCRIPT        */	DEADTRANS(	0x0029	,0x02d5	,0x02d2	,0x0000	), // MODIFIER LETTER CENTRED RIGHT HALF RING
/*SUPERSCRIPT        */	DEADTRANS(	0x002d	,0x02b6	,0x1da7	,0x0000	), // MODIFIER LETTER SMALL CAPITAL I WITH STROKE
/*SUPERSCRIPT        */	DEADTRANS(	0x00f5	,0x005e	,0x1e75	,0x0001	), // LATIN SMALL LETTER U WITH TILDE BELOW
/*SUPERSCRIPT        */	DEADTRANS(	0x2212	,0x005e	,0x207b	,0x0000	), // SUPERSCRIPT MINUS
/*SUPERSCRIPT        */	DEADTRANS(	0x2191	,0x005e	,0x2193	,0x0001	), // DOWNWARDS ARROW
/*SUPERSCRIPT        */	DEADTRANS(	0x022f	,0x005e	,0x1ecd	,0x0001	), // LATIN SMALL LETTER O WITH DOT BELOW
/*SUPERSCRIPT        */	DEADTRANS(	0x014d	,0x005e	,0x1e07	,0x0001	), // LATIN SMALL LETTER B WITH LINE BELOW
/*SUPERSCRIPT        */	DEADTRANS(	0x024d	,0x005e	,0x0183	,0x0001	), // LATIN SMALL LETTER B WITH TOPBAR
/*TILDE              */	DEADTRANS(	0x0020	,0x00f5	,0x0303	,0x0000	), // COMBINING TILDE
/*TILDE              */	DEADTRANS(	0x0020	,0x1d6f	,0x0334	,0x0000	), // COMBINING TILDE OVERLAY
/*TILDE              */	DEADTRANS(	0x0020	,0x00d5	,0x034c	,0x0000	), // COMBINING ALMOST EQUAL TO ABOVE
/*TILDE              */	DEADTRANS(	0x202f	,0x00f5	,0x02dc	,0x0000	), // SMALL TILDE
/*TILDE              */	DEADTRANS(	0x00a0	,0x00f5	,0x007e	,0x0000	), // TILDE
/*TILDE              */	DEADTRANS(	L'A'	,0x00f5	,0x00c3	,0x0000	), // LATIN CAPITAL LETTER A WITH TILDE
/*TILDE              */	DEADTRANS(	L'a'	,0x00f5	,0x00e3	,0x0000	), // LATIN SMALL LETTER A WITH TILDE
/*TILDE              */	DEADTRANS(	L'b'	,0x00f5	,0x1d6c	,0x0000	), // LATIN SMALL LETTER B WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L'd'	,0x00f5	,0x1d6d	,0x0000	), // LATIN SMALL LETTER D WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L'E'	,0x00f5	,0x1ebc	,0x0000	), // LATIN CAPITAL LETTER E WITH TILDE
/*TILDE              */	DEADTRANS(	L'e'	,0x00f5	,0x1ebd	,0x0000	), // LATIN SMALL LETTER E WITH TILDE
/*TILDE              */	DEADTRANS(	L'F'	,0x00f5	,0x00aa	,0x0000	), // FEMININE ORDINAL INDICATOR
/*TILDE              */	DEADTRANS(	L'f'	,0x00f5	,0x1d6e	,0x0000	), // LATIN SMALL LETTER F WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L'I'	,0x00f5	,0x0128	,0x0000	), // LATIN CAPITAL LETTER I WITH TILDE
/*TILDE              */	DEADTRANS(	L'i'	,0x00f5	,0x0129	,0x0000	), // LATIN SMALL LETTER I WITH TILDE
/*TILDE              */	DEADTRANS(	L'J'	,0x00f5	,0xa7ae	,0x0000	), // LATIN CAPITAL LETTER SMALL CAPITAL I
/*TILDE              */	DEADTRANS(	L'j'	,0x00f5	,0x026a	,0x0000	), // LATIN LETTER SMALL CAPITAL I
/*TILDE              */	DEADTRANS(	L'L'	,0x00f5	,0x2c62	,0x0000	), // LATIN CAPITAL LETTER L WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L'l'	,0x00f5	,0x026b	,0x0000	), // LATIN SMALL LETTER L WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L'M'	,0x00f5	,0x00ba	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*TILDE              */	DEADTRANS(	L'm'	,0x00f5	,0x1d6f	,0x0000	), // LATIN SMALL LETTER M WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L'N'	,0x00f5	,0x00d1	,0x0000	), // LATIN CAPITAL LETTER N WITH TILDE
/*TILDE              */	DEADTRANS(	L'n'	,0x00f5	,0x00f1	,0x0000	), // LATIN SMALL LETTER N WITH TILDE
/*TILDE              */	DEADTRANS(	L'O'	,0x00f5	,0x00d5	,0x0000	), // LATIN CAPITAL LETTER O WITH TILDE
/*TILDE              */	DEADTRANS(	L'o'	,0x00f5	,0x00f5	,0x0000	), // LATIN SMALL LETTER O WITH TILDE
/*TILDE              */	DEADTRANS(	L'p'	,0x00f5	,0x1d71	,0x0000	), // LATIN SMALL LETTER P WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L'r'	,0x00f5	,0x1d72	,0x0000	), // LATIN SMALL LETTER R WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L's'	,0x00f5	,0x1d74	,0x0000	), // LATIN SMALL LETTER S WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L't'	,0x00f5	,0x1d75	,0x0000	), // LATIN SMALL LETTER T WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L'U'	,0x00f5	,0x0168	,0x0000	), // LATIN CAPITAL LETTER U WITH TILDE
/*TILDE              */	DEADTRANS(	L'u'	,0x00f5	,0x0169	,0x0000	), // LATIN SMALL LETTER U WITH TILDE
/*TILDE              */	DEADTRANS(	L'V'	,0x00f5	,0x1e7c	,0x0000	), // LATIN CAPITAL LETTER V WITH TILDE
/*TILDE              */	DEADTRANS(	L'v'	,0x00f5	,0x1e7d	,0x0000	), // LATIN SMALL LETTER V WITH TILDE
/*TILDE              */	DEADTRANS(	L'Y'	,0x00f5	,0x1ef8	,0x0000	), // LATIN CAPITAL LETTER Y WITH TILDE
/*TILDE              */	DEADTRANS(	L'y'	,0x00f5	,0x1ef9	,0x0000	), // LATIN SMALL LETTER Y WITH TILDE
/*TILDE              */	DEADTRANS(	L'z'	,0x00f5	,0x1d76	,0x0000	), // LATIN SMALL LETTER Z WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	0x0021	,0x00f5	,0x00a1	,0x0000	), // INVERTED EXCLAMATION MARK
/*TILDE              */	DEADTRANS(	0x0022	,0x00f5	,0x201f	,0x0000	), // DOUBLE HIGH-REVERSED-9 QUOTATION MARK
/*TILDE              */	DEADTRANS(	0x0023	,0x00f5	,0x201f	,0x0000	), // DOUBLE HIGH-REVERSED-9 QUOTATION MARK
/*TILDE              */	DEADTRANS(	0x0027	,0x00f5	,0x201b	,0x0000	), // SINGLE HIGH-REVERSED-9 QUOTATION MARK
/*TILDE              */	DEADTRANS(	0x0029	,0x00f5	,0x1eb5	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND TILDE
/*TILDE              */	DEADTRANS(	0x002a	,0x00f5	,0x02dc	,0x0000	), // SMALL TILDE
/*TILDE              */	DEADTRANS(	0x002b	,0x00f5	,0x1d6f	,0x0001	), // LATIN SMALL LETTER M WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	0x002c	,0x00f5	,0x1ee1	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND TILDE
/*TILDE              */	DEADTRANS(	0x002d	,0x00f5	,0x2053	,0x0000	), // SWUNG DASH
/*TILDE              */	DEADTRANS(	0x003d	,0x00f5	,0x2243	,0x0000	), // ASYMPTOTICALLY EQUAL TO
/*TILDE              */	DEADTRANS(	0x003f	,0x00f5	,0x00bf	,0x0000	), // INVERTED QUESTION MARK
/*TILDE              */	DEADTRANS(	0x005b	,0x00f5	,0x1d73	,0x0000	), // LATIN SMALL LETTER R WITH FISHHOOK AND MIDDLE TILDE
/*TILDE              */	DEADTRANS(	0x005f	,0x00f5	,0x022d	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND MACRON
/*TILDE              */	DEADTRANS(	0x007e	,0x00f5	,0x00d5	,0x0001	), // LATIN CAPITAL LETTER O WITH TILDE
/*TILDE              */	DEADTRANS(	0x00a3	,0x00f5	,0x1e75	,0x0001	), // LATIN SMALL LETTER U WITH TILDE BELOW
/*TILDE              */	DEADTRANS(	0x00a9	,0x00f5	,0x00f1	,0x0001	), // LATIN SMALL LETTER N WITH TILDE
/*TILDE              */	DEADTRANS(	0x0022	,0x00f1	,0x1e4f	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND DIAERESIS
/*TILDE              */	DEADTRANS(	0x0027	,0x00f1	,0x1e4d	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND ACUTE
/*TILDE              */	DEADTRANS(	0x00e1	,0x00f5	,0x1e4d	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND ACUTE
/*TILDE              */	DEADTRANS(	0x00ea	,0x00f5	,0x1ed7	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND TILDE
/*TILDE              */	DEADTRANS(	0x00eb	,0x00f5	,0x1e4f	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND DIAERESIS
/*TILDE              */	DEADTRANS(	0x00f5	,0x00f5	,0x00d5	,0x0001	), // LATIN CAPITAL LETTER O WITH TILDE
/*TILDE              */	DEADTRANS(	0x2019	,0x00f5	,0x201b	,0x0000	), // SINGLE HIGH-REVERSED-9 QUOTATION MARK
/*TILDE              */	DEADTRANS(	0x2610	,0x00f5	,0x274d	,0x0000	), // SHADOWED WHITE CIRCLE
/*TILDE              */	DEADTRANS(	0x0229	,0x00f5	,0x1ee1	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND TILDE
/*TILDE              */	DEADTRANS(	0x014f	,0x00f5	,0x1eb5	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND TILDE
/*TILDE              */	DEADTRANS(	0x014d	,0x00f5	,0x022d	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND MACRON
/*TILDE              */	DEADTRANS(	0x01a1	,0x00f5	,0x1ee1	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND TILDE
/*TILDE&ACUTE_ACCENT */	DEADTRANS(	L'O'	,0x1e4d	,0x1e4c	,0x0000	), // LATIN CAPITAL LETTER O WITH TILDE AND ACUTE
/*TILDE&ACUTE_ACCENT */	DEADTRANS(	L'o'	,0x1e4d	,0x1e4d	,0x0000	), // LATIN SMALL LETTER O WITH TILDE AND ACUTE
/*TILDE&ACUTE_ACCENT */	DEADTRANS(	L'U'	,0x1e4d	,0x1e78	,0x0000	), // LATIN CAPITAL LETTER U WITH TILDE AND ACUTE
/*TILDE&ACUTE_ACCENT */	DEADTRANS(	L'u'	,0x1e4d	,0x1e79	,0x0000	), // LATIN SMALL LETTER U WITH TILDE AND ACUTE
/*TILDE&DIAERESIS    */	DEADTRANS(	L'O'	,0x1e4f	,0x1e4e	,0x0000	), // LATIN CAPITAL LETTER O WITH TILDE AND DIAERESIS
/*TILDE&DIAERESIS    */	DEADTRANS(	L'o'	,0x1e4f	,0x1e4f	,0x0000	), // LATIN SMALL LETTER O WITH TILDE AND DIAERESIS
/*TILDE&MACRON       */	DEADTRANS(	L'O'	,0x022d	,0x022c	,0x0000	), // LATIN CAPITAL LETTER O WITH TILDE AND MACRON
/*TILDE&MACRON       */	DEADTRANS(	L'o'	,0x022d	,0x022d	,0x0000	), // LATIN SMALL LETTER O WITH TILDE AND MACRON
/*TILDE_BELOW        */	DEADTRANS(	0x0020	,0x1e75	,0x0330	,0x0000	), // COMBINING TILDE BELOW
/*TILDE_BELOW        */	DEADTRANS(	0x00a3	,0x1e75	,0x1dfd	,0x0000	), // COMBINING ALMOST EQUAL TO BELOW
/*TILDE_BELOW        */	DEADTRANS(	0x00a0	,0x1e75	,0x02f7	,0x0000	), // MODIFIER LETTER LOW TILDE
/*TILDE_BELOW        */	DEADTRANS(	0x202f	,0x1e75	,0x02f7	,0x0000	), // MODIFIER LETTER LOW TILDE
/*TILDE_BELOW        */	DEADTRANS(	L'E'	,0x1e75	,0x1e1a	,0x0000	), // LATIN CAPITAL LETTER E WITH TILDE BELOW
/*TILDE_BELOW        */	DEADTRANS(	L'e'	,0x1e75	,0x1e1b	,0x0000	), // LATIN SMALL LETTER E WITH TILDE BELOW
/*TILDE_BELOW        */	DEADTRANS(	L'I'	,0x1e75	,0x1e2c	,0x0000	), // LATIN CAPITAL LETTER I WITH TILDE BELOW
/*TILDE_BELOW        */	DEADTRANS(	L'i'	,0x1e75	,0x1e2d	,0x0000	), // LATIN SMALL LETTER I WITH TILDE BELOW
/*TILDE_BELOW        */	DEADTRANS(	L'l'	,0x1e75	,0xab38	,0x0000	), // LATIN SMALL LETTER L WITH DOUBLE MIDDLE TILDE
/*TILDE_BELOW        */	DEADTRANS(	L'U'	,0x1e75	,0x1e74	,0x0000	), // LATIN CAPITAL LETTER U WITH TILDE BELOW
/*TILDE_BELOW        */	DEADTRANS(	L'u'	,0x1e75	,0x1e75	,0x0000	), // LATIN SMALL LETTER U WITH TILDE BELOW
/*TILDE_BELOW        */	DEADTRANS(	0x0022	,0x1e75	,0x2e42	,0x0000	), // DOUBLE LOW-REVERSED-9 QUOTATION MARK
/*TILDE_BELOW        */	DEADTRANS(	0x0027	,0x1e75	,0x02bd	,0x0000	), // MODIFIER LETTER REVERSED COMMA
/*TILDE_BELOW        */	DEADTRANS(	0x003d	,0x1e75	,0x2248	,0x0000	), // ALMOST EQUAL TO
/*TILDE_BELOW        */	DEADTRANS(	0x00f9	,0x1e75	,0x02bd	,0x0000	), // MODIFIER LETTER REVERSED COMMA
/*TILDE_BELOW        */	DEADTRANS(	0x2019	,0x1e75	,0x02bd	,0x0000	), // MODIFIER LETTER REVERSED COMMA
/*TILDE_MIDDLE       */	DEADTRANS(	L'l'	,0x1d6f	,0x026b	,0x0000	), // LATIN SMALL LETTER L WITH MIDDLE TILDE
/*TILDE_MIDDLE       */	DEADTRANS(	L'm'	,0x1d6f	,0x1d6f	,0x0000	), // LATIN SMALL LETTER M WITH MIDDLE TILDE
/*TILDE_MIDDLE       */	DEADTRANS(	L'n'	,0x1d6f	,0x1d70	,0x0000	), // LATIN SMALL LETTER N WITH MIDDLE TILDE
/*TILDE_MIDDLE       */	DEADTRANS(	L'O'	,0x1d6f	,0x019f	,0x0000	), // LATIN CAPITAL LETTER O WITH MIDDLE TILDE
/*TILDE_MIDDLE       */	DEADTRANS(	0x007e	,0x1d6f	,0xab38	,0x0001	), // LATIN SMALL LETTER L WITH DOUBLE MIDDLE TILDE
/*TILDE_MIDDLE       */	DEADTRANS(	0x00f5	,0x1d6f	,0xab38	,0x0001	), // LATIN SMALL LETTER L WITH DOUBLE MIDDLE TILDE
/*TURNED             */	DEADTRANS(	L'A'	,0x0250	,0x2c6f	,0x0000	), // LATIN CAPITAL LETTER TURNED A
/*TURNED             */	DEADTRANS(	L'a'	,0x0250	,0x0250	,0x0000	), // LATIN SMALL LETTER TURNED A
/*TURNED             */	DEADTRANS(	L'C'	,0x0250	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*TURNED             */	DEADTRANS(	L'c'	,0x0250	,0x0254	,0x0000	), // LATIN SMALL LETTER OPEN O
/*TURNED             */	DEADTRANS(	L'E'	,0x0250	,0x018e	,0x0000	), // LATIN CAPITAL LETTER REVERSED E
/*TURNED             */	DEADTRANS(	L'e'	,0x0250	,0x01dd	,0x0000	), // LATIN SMALL LETTER TURNED E
/*TURNED             */	DEADTRANS(	L'f'	,0x0250	,0x025f	,0x0000	), // LATIN SMALL LETTER DOTLESS J WITH STROKE
/*TURNED             */	DEADTRANS(	L'g'	,0x0250	,0x1d77	,0x0000	), // LATIN SMALL LETTER TURNED G
/*TURNED             */	DEADTRANS(	L'H'	,0x0250	,0xa78d	,0x0000	), // LATIN CAPITAL LETTER TURNED H
/*TURNED             */	DEADTRANS(	L'h'	,0x0250	,0x0265	,0x0000	), // LATIN SMALL LETTER TURNED H
/*TURNED             */	DEADTRANS(	L'i'	,0x0250	,0x1d09	,0x0000	), // LATIN SMALL LETTER TURNED I
/*TURNED             */	DEADTRANS(	L'K'	,0x0250	,0xa7b0	,0x0000	), // LATIN CAPITAL LETTER TURNED K
/*TURNED             */	DEADTRANS(	L'k'	,0x0250	,0x029e	,0x0000	), // LATIN SMALL LETTER TURNED K
/*TURNED             */	DEADTRANS(	L'L'	,0x0250	,0xa780	,0x0000	), // LATIN CAPITAL LETTER TURNED L
/*TURNED             */	DEADTRANS(	L'l'	,0x0250	,0xa781	,0x0000	), // LATIN SMALL LETTER TURNED L
/*TURNED             */	DEADTRANS(	L'M'	,0x0250	,0x019c	,0x0000	), // LATIN CAPITAL LETTER TURNED M
/*TURNED             */	DEADTRANS(	L'm'	,0x0250	,0x026f	,0x0000	), // LATIN SMALL LETTER TURNED M
/*TURNED             */	DEADTRANS(	L'o'	,0x0250	,0xab43	,0x0000	), // LATIN SMALL LETTER TURNED O OPEN-O
/*TURNED             */	DEADTRANS(	L'r'	,0x0250	,0x0279	,0x0000	), // LATIN SMALL LETTER TURNED R
/*TURNED             */	DEADTRANS(	L'T'	,0x0250	,0xa7b1	,0x0000	), // LATIN CAPITAL LETTER TURNED T
/*TURNED             */	DEADTRANS(	L't'	,0x0250	,0x0287	,0x0000	), // LATIN SMALL LETTER TURNED T
/*TURNED             */	DEADTRANS(	L'u'	,0x0250	,0xab51	,0x0000	), // LATIN SMALL LETTER TURNED UI
/*TURNED             */	DEADTRANS(	L'V'	,0x0250	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*TURNED             */	DEADTRANS(	L'v'	,0x0250	,0x028c	,0x0000	), // LATIN SMALL LETTER TURNED V
/*TURNED             */	DEADTRANS(	L'w'	,0x0250	,0x028d	,0x0000	), // LATIN SMALL LETTER TURNED W
/*TURNED             */	DEADTRANS(	L'y'	,0x0250	,0x028e	,0x0000	), // LATIN SMALL LETTER TURNED Y
/*TURNED             */	DEADTRANS(	0x00e6	,0x0250	,0x1d02	,0x0000	), // LATIN SMALL LETTER TURNED AE
/*TURNED             */	DEADTRANS(	0x00f9	,0x0250	,0x0252	,0x0001	), // LATIN SMALL LETTER TURNED ALPHA
/*TURNED             */	DEADTRANS(	L'A'	,0x0252	,0x2c70	,0x0000	), // LATIN CAPITAL LETTER TURNED ALPHA
/*TURNED             */	DEADTRANS(	L'a'	,0x0252	,0x0252	,0x0000	), // LATIN SMALL LETTER TURNED ALPHA
/*TURNED             */	DEADTRANS(	L'd'	,0x0252	,0x018d	,0x0000	), // LATIN SMALL LETTER TURNED DELTA
/*TURNED             */	DEADTRANS(	L'e'	,0x0252	,0x1d08	,0x0000	), // LATIN SMALL LETTER TURNED OPEN E
/*TURNED             */	DEADTRANS(	0x0021	,0x0250	,0x00a1	,0x0000	), // INVERTED EXCLAMATION MARK
/*TURNED             */	DEADTRANS(	0x0023	,0x0250	,0x1d1f	,0x0001	), // LATIN SMALL LETTER SIDEWAYS TURNED M
/*TURNED             */	DEADTRANS(	L'c'	,0x1d1f	,0x1d12	,0x0000	), // LATIN SMALL LETTER SIDEWAYS OPEN O
/*TURNED             */	DEADTRANS(	L'I'	,0x1d1f	,0xa7f7	,0x0000	), // LATIN EPIGRAPHIC LETTER SIDEWAYS I
/*TURNED             */	DEADTRANS(	L'm'	,0x1d1f	,0x1d1f	,0x0000	), // LATIN SMALL LETTER SIDEWAYS TURNED M
/*TURNED             */	DEADTRANS(	L'o'	,0x1d1f	,0x1d11	,0x0000	), // LATIN SMALL LETTER SIDEWAYS O
/*TURNED             */	DEADTRANS(	L'u'	,0x1d1f	,0x1d1d	,0x0000	), // LATIN SMALL LETTER SIDEWAYS U
/*TURNED             */	DEADTRANS(	0x00eb	,0x1d1f	,0x1d1e	,0x0000	), // LATIN SMALL LETTER SIDEWAYS DIAERESIZED U
/*TURNED             */	DEADTRANS(	0x002d	,0x0250	,0xab42	,0x0001	), // LATIN SMALL LETTER TURNED OE WITH HORIZONTAL STROKE
/*TURNED             */	DEADTRANS(	0x0153	,0xab42	,0xab42	,0x0000	), // LATIN SMALL LETTER TURNED OE WITH HORIZONTAL STROKE
/*TURNED             */	DEADTRANS(	0x002f	,0x0250	,0xab41	,0x0001	), // LATIN SMALL LETTER TURNED OE WITH STROKE
/*TURNED             */	DEADTRANS(	L'o'	,0xab41	,0xab44	,0x0000	), // LATIN SMALL LETTER TURNED O OPEN-O WITH STROKE
/*TURNED             */	DEADTRANS(	0x0153	,0xab41	,0xab41	,0x0000	), // LATIN SMALL LETTER TURNED OE WITH STROKE
/*TURNED             */	DEADTRANS(	L'2'	,0x0250	,0x218a	,0x0000	), // TURNED DIGIT TWO
/*TURNED             */	DEADTRANS(	L'3'	,0x0250	,0x218b	,0x0000	), // TURNED DIGIT THREE
/*TURNED             */	DEADTRANS(	L'8'	,0x0250	,0x221e	,0x0000	), // INFINITY
/*TURNED             */	DEADTRANS(	0x003c	,0x0250	,0x1d1a	,0x0001	), // LATIN LETTER SMALL CAPITAL TURNED R
/*TURNED             */	DEADTRANS(	L'E'	,0x1d1a	,0x2c7b	,0x0000	), // LATIN LETTER SMALL CAPITAL TURNED E
/*TURNED             */	DEADTRANS(	L'M'	,0x1d1a	,0xa7fa	,0x0000	), // LATIN LETTER SMALL CAPITAL TURNED M
/*TURNED             */	DEADTRANS(	L'R'	,0x1d1a	,0x1d1a	,0x0000	), // LATIN LETTER SMALL CAPITAL TURNED R
/*TURNED             */	DEADTRANS(	0x003f	,0x0250	,0x00bf	,0x0000	), // INVERTED QUESTION MARK
/*TURNED             */	DEADTRANS(	L'h'	,0x027b	,0x02ae	,0x0000	), // LATIN SMALL LETTER TURNED H WITH FISHHOOK
/*TURNED             */	DEADTRANS(	0x007b	,0x027b	,0x02af	,0x0000	), // LATIN SMALL LETTER TURNED H WITH FISHHOOK AND TAIL
/*TURNED             */	DEADTRANS(	0x007b	,0x0250	,0x027b	,0x0000	), // LATIN SMALL LETTER TURNED R WITH HOOK
/*TURNED             */	DEADTRANS(	0x007c	,0x0250	,0x0270	,0x0001	), // LATIN SMALL LETTER TURNED M WITH LONG LEG
/*TURNED             */	DEADTRANS(	L'm'	,0x0270	,0x0270	,0x0000	), // LATIN SMALL LETTER TURNED M WITH LONG LEG
/*TURNED             */	DEADTRANS(	L'r'	,0x0270	,0x027a	,0x0000	), // LATIN SMALL LETTER TURNED R WITH LONG LEG
/*TURNED             */	DEADTRANS(	0x007d	,0x0250	,0x0284	,0x0001	), // LATIN SMALL LETTER DOTLESS J WITH STROKE AND HOOK
/*TURNED             */	DEADTRANS(	L'f'	,0x0284	,0x0284	,0x0000	), // LATIN SMALL LETTER DOTLESS J WITH STROKE AND HOOK
/*TURNED             */	DEADTRANS(	L'r'	,0x0284	,0x2c79	,0x0000	), // LATIN SMALL LETTER TURNED R WITH TAIL
/*TURNED             */	DEADTRANS(	0x00a4	,0x0250	,0xa77f	,0x0001	), // LATIN SMALL LETTER TURNED INSULAR G
/*TURNED             */	DEADTRANS(	L'G'	,0xa77f	,0xa77e	,0x0000	), // LATIN CAPITAL LETTER TURNED INSULAR G
/*TURNED             */	DEADTRANS(	L'g'	,0xa77f	,0xa77f	,0x0000	), // LATIN SMALL LETTER TURNED INSULAR G
/*TURNED             */	DEADTRANS(	0x00a9	,0x0250	,0xab51	,0x0000	), // LATIN SMALL LETTER TURNED UI
/*TURNED             */	DEADTRANS(	0x00b5	,0x0250	,0x0252	,0x0001	), // LATIN SMALL LETTER TURNED ALPHA

    0, 0
};

/*****************************************************************************\
* Ligature array.
*
* Modification # 17 and 18 are also grouped below.
*
* 16 is the maximum number of code units supported by ligatures on Windows, and
* 14 code units are required for subdivision flags.
*
* The 3 subdivision flags supported by Unicode (after projecting to support all
* subdivision flags and devising a scheme to do so) are supported as all-in-one
* sequences, in lieu of the tag small letters, given the absence of other flags
* in this category. Their level-10 map, using the AltFl modifier (alliteration
* with "AltFr", based on "flag") added on top of the Caps Lock toggle key
* (using it requires resetting the toggle in the wake), is stacked, on key C12
* for Wales, D12 for England, and E12 for Scotland, with geospatial mnemonics
# using the stacked layout of these keys, with respect to the requirement of
# duplicate mappings of C02 on C11, D02 on D11, and E02 on E11 due to the
# column-02 bug affecting level 10, i.e. Shift + AltFl (decimal 65, 0x41), and
# with keycap mnemonics using "£" printed in Shift position on D12 of French
# AZERTY, on C12 of Belgian AZERTY.
* https://unicode.org/emoji/charts/emoji-list.html#subdivision-flag
* See * Known bugs
\*****************************************************************************/

static ALLOC_SECTION_LDATA LIGATURE16 aLigature[] = {
  {'1'          ,6      ,'1'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,7      ,'1'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,16     ,'1'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,17     ,'1'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,6      ,'2'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,7      ,'2'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,16     ,'2'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,17     ,'2'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,6      ,'3'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,7      ,'3'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,16     ,'3'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,17     ,'3'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,6      ,'4'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,7      ,'4'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,16     ,'4'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,17     ,'4'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,6      ,'5'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,7      ,'5'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,16     ,'5'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,17     ,'5'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,6      ,'6'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,7      ,'6'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,16     ,'6'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,17     ,'6'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,6      ,'7'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,7      ,'7'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,16     ,'7'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,17     ,'7'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,6      ,'8'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,7      ,'8'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,16     ,'8'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,17     ,'8'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,6      ,'9'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,7      ,'9'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,16     ,'9'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,17     ,'9'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'0'          ,6      ,'0'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'0'          ,7      ,0xd83d   ,0xdd1f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'0'          ,16     ,'0'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'0'          ,17     ,'0'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,6      ,'*'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,7      ,'*'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,16     ,'*'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,17     ,'*'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,18     ,'2'      ,0xfe0f   ,0x20e3   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,6      ,'#'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,7      ,'#'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,16     ,'#'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,17     ,0xd83d   ,0xdff0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,18     ,0xd83c   ,0xdff4   ,0xdb40   ,0xDC67   ,0xdb40   ,0xDC62   ,0xdb40   ,0xDC73   ,0xdb40   ,0xDC63   ,0xdb40   ,0xDC74   ,0xdb40   ,0xDC7F   ,WCH_NONE ,WCH_NONE }, // Scotland.
  {'A'          ,6      ,'c'      ,0x02bc   ,'h'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,7      ,'C'      ,0x02bc   ,'h'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Z'          ,7      ,0xd83d   ,0xde27   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,7      ,'&'      ,'q'      ,'u'      ,'o'      ,'t'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,7      ,0xd83e   ,0xdd14   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,7      ,0xd83d   ,0xde0a   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,7      ,0xd83d   ,0xde0d   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'U'          ,6      ,'U'      ,'+'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'U'          ,7      ,'&'      ,'a'      ,'p'      ,'o'      ,'s'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,6      ,'\\'     ,'u'      ,'{'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,7      ,0xd83d   ,0xde4f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,7      ,0xd83d   ,0xde01   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,7      ,'&'      ,'a'      ,'m'      ,'p'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,1      ,0x2039   ,0x202f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,17     ,0x0000   ,0x0000   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,18     ,0xd83c   ,0xDDFF   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,1      ,0x202f   ,0x203a   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,17     ,0xd83d   ,0xdcb2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,18     ,0xd83c   ,0xdff4   ,0xdb40   ,0xDC67   ,0xdb40   ,0xDC62   ,0xdb40   ,0xDC65   ,0xdb40   ,0xDC6E   ,0xdb40   ,0xDC67   ,0xdb40   ,0xDC7F   ,WCH_NONE ,WCH_NONE }, // England.
  {'Q'          ,5      ,0xd801   ,0xdfa5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,7      ,0xd83d   ,0xdc4f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,6      ,0xd83d   ,0xde42   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,7      ,0xd83d   ,0xde14   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,7      ,0xd83d   ,0xde06   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,7      ,0xd83d   ,0xdd25   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,7      ,0xd83d   ,0xdc4d   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,7      ,0xd83d   ,0xde02   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,6      ,'&'      ,'#'      ,'x'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,7      ,0xd83d   ,0xde05   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,7      ,0xd83e   ,0xdd23   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,7      ,0xd83d   ,0xde37   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,1      ,0x00ab   ,0x202f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,17     ,'#'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,18     ,0xd83c   ,0xDDF8   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,1      ,0x202f   ,0x00bb   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,17     ,'*'      ,0xfe0f   ,0x20e3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,18     ,0xd83c   ,0xdff4   ,0xdb40   ,0xDC67   ,0xdb40   ,0xDC62   ,0xdb40   ,0xDC77   ,0xdb40   ,0xDC6C   ,0xdb40   ,0xDC73   ,0xdb40   ,0xDC7F   ,WCH_NONE ,WCH_NONE }, // Wales.
  {'W'          ,7      ,0xd83d   ,0xde22   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,7      ,0xd83c   ,0xdf1f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,6      ,'&'      ,'l'      ,'t'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,7      ,0xd83d   ,0xde2d   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,6      ,'&'      ,'g'      ,'t'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,7      ,0xd83d   ,0xdc96   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,4      ,'0'      ,'0'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,6      ,0xd83d   ,0xde18   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,7      ,0xd83e   ,0xdd70   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,6      ,'n'      ,0x1d52   ,0x202f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,7      ,'N'      ,0x1d52   ,0x202f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,1      ,0x202f   ,'?'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,7      ,0xd83d   ,0xdc99   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,14     ,'&'      ,'#'      ,'x'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,16     ,0xd83d   ,0xdc9a   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,17     ,0x0000   ,0x0000   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,18     ,0xd83c   ,0xDDFD   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,1      ,0x202f   ,'!'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,6      ,0xd83d   ,0xde31   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,7      ,0xd83d   ,0xdce3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,14     ,'&'      ,'#'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,16     ,0xd83d   ,0xdce2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,17     ,0x0000   ,0x0000   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,18     ,0xd83c   ,0xDDFD   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,1      ,0x202f   ,':'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,7      ,0xd83d   ,0xde15   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,16     ,0xd83d   ,0xde12   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,17     ,0xd83c   ,0xdff3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,18     ,0xd83c   ,0xDDFD   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,1      ,0x202f   ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,7      ,0xd83d   ,0xdc94   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,16     ,0xd83d   ,0xde09   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,17     ,0xd83c   ,0xdff4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,18     ,0xd83c   ,0xDDFD   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_SPACE     ,5      ,' '      ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_SPACE     ,12     ,'&'      ,'n'      ,'b'      ,'s'      ,'p'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_SPACE     ,14     ,'&'      ,'#'      ,'x'      ,'2'      ,'0'      ,'2'      ,'F'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_SPACE     ,15     ,'&'      ,'#'      ,'x'      ,'2'      ,'0'      ,'2'      ,'F'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_SPACE     ,16     ,'&'      ,'n'      ,'b'      ,'s'      ,'p'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  /*****************************************************************************\
  * Regional indicator symbol letters.
  *
  * Standalone regional indicator symbol letters as a country flag input method.
  \*****************************************************************************/

  {'A'          ,17     ,0xd83c   ,0xDDE6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,17     ,0xd83c   ,0xDDE7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,17     ,0xd83c   ,0xDDE8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,17     ,0xd83c   ,0xDDE9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,17     ,0xd83c   ,0xDDEA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,17     ,0xd83c   ,0xDDEB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,17     ,0xd83c   ,0xDDEC   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,17     ,0xd83c   ,0xDDED   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,17     ,0xd83c   ,0xDDEE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,17     ,0xd83c   ,0xDDEF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,17     ,0xd83c   ,0xDDF0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,17     ,0xd83c   ,0xDDF1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,17     ,0xd83c   ,0xDDF2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,17     ,0xd83c   ,0xDDF3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,17     ,0xd83c   ,0xDDF4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,17     ,0xd83c   ,0xDDF5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,17     ,0xd83c   ,0xDDF6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,17     ,0xd83c   ,0xDDF7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,17     ,0xd83c   ,0xDDF8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,17     ,0xd83c   ,0xDDF9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'U'          ,17     ,0xd83c   ,0xDDFA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,17     ,0xd83c   ,0xDDFB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,17     ,0xd83c   ,0xDDFC   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,17     ,0xd83c   ,0xDDFD   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,17     ,0xd83c   ,0xDDFE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Z'          ,17     ,0xd83c   ,0xDDFF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  /*****************************************************************************\
  * Letter emoji along with digit emoji.
  *
  * Writing in letter emoji requires U+2060 WORD JOINER, since the cursive
  * non-joiner U+200C is not a break preventer, and letter emoji just like most
  * emoji are word boundaries, so that contiguous runs break apart at line end.
  *
  * Digit emoji, by contrast, inherit the word boundary rules applied to digits,
  * and when digits are followed by letter emoji, these are exposed to breaking
  * off, unless a word joiner is inserted. This needs to be built-in when digits
  * are input at level 10, modification # 18, so as to get the expected behavior
  * without screwing things up. Word joiner on the space bar is at level 9, # 17.
  \*****************************************************************************/

  {'0'          ,18     ,'0'      ,0xfe0f   ,0x20e3   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,18     ,'1'      ,0xfe0f   ,0x20e3   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,18     ,'2'      ,0xfe0f   ,0x20e3   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,18     ,'3'      ,0xfe0f   ,0x20e3   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,18     ,'4'      ,0xfe0f   ,0x20e3   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,18     ,'5'      ,0xfe0f   ,0x20e3   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,18     ,'6'      ,0xfe0f   ,0x20e3   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,18     ,'7'      ,0xfe0f   ,0x20e3   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,18     ,'8'      ,0xfe0f   ,0x20e3   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,18     ,'9'      ,0xfe0f   ,0x20e3   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,18     ,0xd83c   ,0xDDE6   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,18     ,0xd83c   ,0xDDE7   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,18     ,0xd83c   ,0xDDE8   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,18     ,0xd83c   ,0xDDE9   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,18     ,0xd83c   ,0xDDEA   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,18     ,0xd83c   ,0xDDEB   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,18     ,0xd83c   ,0xDDEC   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,18     ,0xd83c   ,0xDDED   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,18     ,0xd83c   ,0xDDEE   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,18     ,0xd83c   ,0xDDEF   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,18     ,0xd83c   ,0xDDF0   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,18     ,0xd83c   ,0xDDF1   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,18     ,0xd83c   ,0xDDF2   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,18     ,0xd83c   ,0xDDF3   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,18     ,0xd83c   ,0xDDF4   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,18     ,0xd83c   ,0xDDF5   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,18     ,0xd83c   ,0xDDF6   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,18     ,0xd83c   ,0xDDF7   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,18     ,0xd83c   ,0xDDF8   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,18     ,0xd83c   ,0xDDF9   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'U'          ,18     ,0xd83c   ,0xDDFA   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,18     ,0xd83c   ,0xDDFB   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,18     ,0xd83c   ,0xDDFC   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,18     ,0xd83c   ,0xDDFD   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,18     ,0xd83c   ,0xDDFE   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Z'          ,18     ,0xd83c   ,0xDDFF   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {0            ,0      ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        }
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

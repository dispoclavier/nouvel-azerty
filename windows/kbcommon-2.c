/*****************************************************************************\
* Module Name: kbcommon-2.c
*
* Common keyboard layout data
*
* Copyright (c) 1985-2001, Microsoft Corporation
* Copyright (c) 2014-2025, Marcel Schneider dev[arobase]dispoclavier.com
*
* History:
* Move KbdTables to kbcommon-3.c         6.0.8.00.03 Thu 2025-09-25T1127+0200
* Move here the code from numpad on      6.0.8.00.02 Thu 2025-09-25T1121+0200
* Add partial file kbcommon-2.c          6.0.8.00.01 Thu 2025-09-25T0613+0200
*
* This file needs to be included after all the allocation tables, due to the
* static ALLOC_SECTION_LDATA VK_TO_WCHAR_TABLE aVkToWcharTable[].
*
* This file includes the file containing the dead key content.
* See #include "kbdeadtrans.c"
*
\*****************************************************************************/

/*****************************************************************************\
* Numeric keypad
*
* The Keyboard Table Generation Tool (Unicode) built-in transpiler advises to
// Put this last so that VkKeyScan interprets number characters
// as coming from the main section of the kbd [aVkToWch33 for instance]
// before considering the numpad [aVkToWch17 for instance].
*
* Numpad specials are deactivated as redundant and detrimentally affecting the
* user experience while the numlock toggle is repurposed for the integrated or
* overlay numpad on compact keyboards.
* See kbcommon.h subsection 6.1
*
* While on digit keys, all 8 levels are used for the sake of arrows, depending
* on the KanaLock toggle state, the decimal separator and operator keys offer
* only minimal functionality, as AltGr is unfit for the numpad. However, so as
* to prevent these keys from seeming broken, level 5 is replicated at levels 3
* and 7, and so is level 6 at levels 4 and 8.
*
\*****************************************************************************/

static ALLOC_SECTION_LDATA VK_TO_WCHARS17 aVkToWch17[] = {
  // Modification #     |    0    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |   10    |   11    |   12    |   13    |   14    |   15    |   16    |
  // UX Level           |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |  Ctrl   |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |
  //                    |=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|
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
  {  (PVK_TO_WCHARS1)aVkToWch9 ,  9, sizeof(aVkToWch9[0]) },
  {  (PVK_TO_WCHARS1)aVkToWch17, 17, sizeof(aVkToWch17[0]) },
  {  (PVK_TO_WCHARS1)aVkToWch40, 40, sizeof(aVkToWch40[0]) },
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

/*****************************************************************************\
* Dead key content.
*
* The array of DEADTRANS macro calls comes after the dead key names above, and
* immediately before the ligatures.
* See ### Dead key bug
*
\*****************************************************************************/
#include "kbdeadtrans.c"

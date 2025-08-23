/*****************************************************************************\
* Module Name: kbfrFRs.C
*
* Row E of keyboard layout
*
* Copyright (c) 1985-2001, Microsoft Corporation
* Copyright (c) 2014-2025, Marcel Schneider dev[arobase]dispoclavier.com
*
* History:
* Try to debug allocation table          6.0.3.04.00 Sat 2025-08-23T2210+0200
* Support Breton variant on Windows      6.0.3.03.01 Fri 2025-08-22T2255+0200
* Debug keys E07, E08 wrt caps lock      6.0.3.03.00 Thu 2025-08-21T2015+0200
* Move rows A..D to kbcomazerty.c        6.0.3.02.00 Thu 2025-08-21T1652+0200
* Edit annotations                       6.0.3.01.01 Thu 2025-08-21T0341+0200
* Move common remainder to kbcommon.c    6.0.3.01.00 Wed 2025-08-20T2203+0200
* Move MCUs to kbligatures.c & others    6.0.3.00.02 Wed 2025-08-20T1930+0200
* Sync ligatures with kbfrFRsr.c         6.0.3.00.01
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

#include "kbazerty.h"
#include "kbcommon.h"

#if defined(_M_IA64)
#pragma section(".data")
#define ALLOC_SECTION_LDATA __declspec(allocate(".data"))
#else
#pragma data_seg(".data")
#define ALLOC_SECTION_LDATA
#endif

// See #include "kbcommon.c" at file end.
// See #include "kbcomazerty.c" at allocation table end.
#include "kbdeadtrans.c"

static ALLOC_SECTION_LDATA LIGATURE16 aLigature[] = {

  #include "kbligazerty.c"

  {VK_ESCAPE    ,4      ,' '      ,'f'      ,'r'      ,'_'      ,'F'      ,'R'      ,'_'      ,'s'      ,'e'      ,'m'      ,'i'      ,'_'      ,'a'      ,'u'      ,'t'      ,'o'      },

  #include "kbligatures.c"

  {0            ,0      ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        }
};

/*****************************************************************************\
* aVkToWch33[]  - Virtual Key to WCHAR translation for 33 shift states
*
* See the full description in kbcommon.c.
\*****************************************************************************/
static ALLOC_SECTION_LDATA VK_TO_WCHARS33 aVkToWch33[] = {
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
  {'7'          ,KBD    ,0x00e8   ,0x00c8   ,'7'      ,WCH_DEAD ,'7'      ,0x2077   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'7'      ,'7'      ,'7'      ,0x2087   ,'7'      ,0x2077   ,0x2087   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'`'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,ALTGR  ,'_'      ,0x2015   ,'8'      ,'\\'     ,'8'      ,0x2078   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'8'      ,'8'      ,'8'      ,0x2088   ,'8'      ,0x2078   ,0x2088   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {'9'          ,KBD    ,0x00e7   ,0x00c7   ,'9'      ,'('      ,'9'      ,0x2079   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'9'      ,'9'      ,'9'      ,0x2089   ,'9'      ,0x2079   ,0x2089   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {'0'          ,KBD    ,0x00e0   ,0x00c0   ,'0'      ,')'      ,'0'      ,0x2070   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'0'      ,'0'      ,'0'      ,0x2080   ,'0'      ,0x2070   ,0x2080   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {VK_OEM_MINUS ,ALTGR  ,'@'      ,0x00b0   ,0x1d49   ,']'      ,0x00b0   ,0x207b   ,'E'      ,WCH_LGTR ,WCH_NONE ,'@'      ,0x00b0   ,'-'      ,0x208b   ,'E'      ,0x207b   ,0x208b   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {VK_OEM_PLUS  ,ALTGR  ,'\''     ,'+'      ,WCH_DEAD ,'}'      ,'='      ,0x207a   ,'F'      ,WCH_LGTR ,WCH_NONE ,'='      ,'+'      ,WCH_DEAD ,0x208a   ,'F'      ,0x207a   ,0x208a   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,0x00a6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00a6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  //                    |=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|
  //                    |    0    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |   10    |   11    |   12    |   13    |   14    |   15    |   16    |   17    |   18    |   19    |   20    |   21    |   22    |   23    |   24    |   25    |   26    |   27    |   28    |   29    |   30    |   31    |   32    |

  // Rows A..D are common to the main layout and all AZERTY variants.
  #include "kbcomazerty.c"

  {0            ,0      ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        }
};

/*****************************************************************************\
* Final include
*
* The file kbcommon.c needs to be included last because it contains the
* static ALLOC_SECTION_LDATA VK_TO_WCHAR_TABLE aVkToWcharTable[], that
* comes after all the static ALLOC_SECTION_LDATA VK_TO_WCHARS* aVkToWch*[].
\*****************************************************************************/
#include "kbcommon.c"

/*****************************************************************************\
* Note on kbfrFRs.DEF
*
* The .def file is not provided. The Keyboard Table Generation Tool (Unicode)
* generates a .def file on the fly while transpiling kbfrFRs.klc right before
* giving the sources to the compiler. So, no need to support the .def file as
* a part of the source code. In the process, 25% less files.
*
* For reference, this is the content of kbfrFRs.DEF:

LIBRARY kbfrFRs
 
 EXPORTS 
    KbdLayerDescriptor @1


\*****************************************************************************/

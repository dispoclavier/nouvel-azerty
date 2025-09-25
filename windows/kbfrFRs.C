/*****************************************************************************\
* Module Name: kbfrFRs.C
*
* Keyboard layout C source
*
* Copyright (c) 1985-2001, Microsoft Corporation
* Copyright (c) 2014-2025, Marcel Schneider dev[arobase]dispoclavier.com
*
* History:
* Move alloc table to kbfrFRs-allo.c     6.0.8.00.00 Thu 2025-09-25T1836+0200
* Move variant ID to UX level 4          6.0.7.03.00 Sun 2025-09-21T1332+0200
* Move kbdeadtrans.c #inc to kbcommon.c  6.0.7.02.00 Tue 2025-09-16T0311+0200
* Add 6 spare modification numbers       6.0.5.00.00 Sat 2025-08-30T2006+0200
* Udpdate to Unicode 17.0                6.0.4.02.00 Wed 2025-08-27T2007+0200
* Add okay emoji for broken key combos   6.0.4.01.00 Wed 2025-08-27T1840+0200
* Move <windows.h> back to C sources     6.0.4.00.00 Wed 2025-08-27T1304+0200
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
*
\*****************************************************************************/

#include <windows.h>
#include "kbazerty.h"
#include "kbcommon.h"

#if defined(_M_IA64)
#pragma section(".data")
#define ALLOC_SECTION_LDATA __declspec(allocate(".data"))
#else
#pragma data_seg(".data")
#define ALLOC_SECTION_LDATA
#endif

#include "kbfrFRs-allo.c"

static ALLOC_SECTION_LDATA LIGATURE16 aLigature[] = {

  {VK_ESCAPE ,3 ,' ' ,'f' ,'r' ,'_' ,'F' ,'R' ,'_' ,'s' ,'e' ,'m' ,'i' ,'_' ,'a' ,'u' ,'t' ,'o' },
	// The first code unit of long multiunit ligatures may not be output, hence the leading space.

  #include "kbligazerty.c"
  #include "kbligatures.c"

  {0         ,0 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   }
};

/*****************************************************************************\
* Final include
*
* The file kbcommon-3.c needs to be included last because it contains the
* return statement.
*
\*****************************************************************************/
#include "kbcommon-3.c"

/*****************************************************************************\
* Note on kbfrFRs.DEF
*
* The .DEF file is not provided. The Keyboard Table Generation Tool (Unicode)
* generates a .DEF file on the fly while transpiling kbfrFRs.klc right before
* giving the sources to the compiler. So, no need to support the .DEF file as
* a part of the source code.
*
* For reference, this is the content of kbfrFRs.DEF:

LIBRARY kbfrFRs
 
 EXPORTS 
    KbdLayerDescriptor @1


\*****************************************************************************/

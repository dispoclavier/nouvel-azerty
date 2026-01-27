/*****************************************************************************\
* Module Name: kbfrFRr1.C
*
* Keyboard layout C source
*
* Copyright:
* 1985..2001 Microsoft Corporation (pro parte)
* 2014..2026 Marcel Schneider dev[arobase]dispoclavier.com (pro parte)
*
* History:
* Rename kbfrFRsr.C to kbfrFRr1.C          6.0.9.8.0 Thu 2025-10-02T1439+0200
* Move alloc table to kbfrFRsr-allo.c      6.0.8.0.0 Thu 2025-09-25T1836+0200
* Move variant ID to UX level 4            6.0.7.3.0 Sun 2025-09-21T1332+0200
* Move kbdeadtrans.c #inc to kbcommon.c    6.0.7.2.0 Tue 2025-09-16T0311+0200
* Add 6 spare modification numbers         6.0.5.0.0 Sat 2025-08-30T2006+0200
* Udpdate to Unicode 17.0                  6.0.4.2.0 Wed 2025-08-27T2007+0200
* Add okay emoji for broken key combos     6.0.4.1.0 Wed 2025-08-27T1840+0200
* Move <windows.h> back to C sources       6.0.4.0.0 Wed 2025-08-27T1303+0200
* Genericize file names and paths          6.0.3.4.0 Sat 2025-08-23T2211+0200
* Support Breton variant on Windows        6.0.3.3.0 Fri 2025-08-22T2258+0200
* Move rows A..D to kbcomqzjfgy.c          6.0.3.2.0 Thu 2025-08-21T1653+0200
* Edit annotations                         6.0.3.1.1 Thu 2025-08-21T0342+0200
* Move common remainder to kbcommon.c      6.0.3.1.0 Wed 2025-08-20T2203+0200
* Move MCUs to kbligatures.c & others      6.0.3.0.2 Wed 2025-08-20T1930+0200
* Streamline ligatures at mod# 29..32      6.0.3.0.1
* U2060 on spacebar at mod# 29..32         6.0.3.0.0
* Move DEADTRANS calls to kbdeadtrans.c    6.0.2.1.0 Tue 2025-08-19T1952+0200
* Replace duplicate with SEAL U1F9AD       6.0.2.0.0 Tue 2025-08-19T1710+0200
* Debug Shift + CAPITAL + KANA             6.0.1.0.0 Wed 2025-08-13T1934+0200
* Use Shift + CAPITAL + KANA fwiw          6.0.0.6.0 Sun 2025-08-10T1736+0200
* Swap bold and monospace digits           6.0.0.5.0 Sun 2025-08-10T1547+0200
* Update dead key content                  6.0.0.4.0 Sat 2025-08-09T2027+0200
* Move ligatures to the top                6.0.0.3.0 Fri 2025-08-08T1855+0200
* Update dead key content                  6.0.0.2.0 Fri 2025-08-08T0942+0200
* Update dead key content "group"          6.0.0.1.0 Thu 2025-08-07T1823+0200
* Partially swap B08 and B10               6.0.0.0.0 Mon 2025-07-28T1434+0200
* Update dead key content "reversed"      5.3.0.34.0 Sat 2025-07-26T2136+0200
* Restore initial dead char U+1D19        5.3.0.33.0 Sat 2025-07-26T1723+0200
* Readd (move) currency sign              5.3.0.32.0 Fri 2025-07-25T2358+0200
* Add support for bracketed ellipsis      5.3.0.31.0 Fri 2025-07-25T2120+0200
* Swap ':', '#' on ADD, NP4 in ASCII      5.3.0.30.0 Tue 2025-07-22T0704+0200
* Swap colon, NBTSP on ADD, NUMPAD4       5.3.0.29.0 Tue 2025-07-22T0451+0200
* NBTSP U+202F on Shift + VK_NUMPAD4      5.3.0.28.0 Tue 2025-07-22T0353+0200
* Add all-in-one FR, EU, UN flags         5.3.0.27.0 Sun 2025-07-20T0233+0200
* Rename file to kbfrFRsr.C               5.3.0.26.0 Wed 2025-07-16T0046+0200
* Debug variant name output               5.3.0.25.0 Sat 2025-07-05T1742+0200
* Debug variant name output               5.3.0.24.0 Sat 2025-07-05T1706+0200
* Debug BACK, add variant&version         5.3.0.23.0 Sat 2025-07-05T1619+0200
* Fill unused levels of numpad keys       5.3.0.22.0 Thu 2025-07-03T2048+0200
* Upgrade numpad as designed              5.3.0.21.0 Wed 2025-07-02T1314+0200
* Test numpad Shift level                 5.3.0.20.0 Tue 2025-07-01T1714+0200
* Test numpad extension                   5.3.0.19.0 Tue 2025-07-01T1604+0200
* Add script math alpha, more emoji       5.3.0.18.0 Mon 2025-06-30T1402+0200
* Prep support more live key emoji        5.3.0.17.0 Sun 2025-06-29T1634+0200
* Debug math alphabets on live keys       5.3.0.16.0 Sun 2025-06-29T0044+0200
* Add 4 math alphabets on live keys       5.3.0.15.0 Sat 2025-06-28T1958+0200
* Test alloc table emoji extension        5.3.0.14.0 Sat 2025-06-28T0833+0200
* Allocate 3 empty level-9 positions      5.3.0.13.0 Fri 2025-06-27T2327+0200
* Move ligatures below alloc tables       5.3.0.12.3 Thu 2025-06-26T1755+0200
* Improve dead key content layout         5.3.0.12.2 Thu 2025-06-26T1743+0200
* Debug dead key content sort order       5.3.0.12.1 Thu 2025-06-26T0819+0200
* Test KANA modifier on KanaLock key      5.3.0.12.0 Tue 2025-06-24T0450+0200
* Debug level-10 digit emoji              5.3.0.11.0 Sun 2025-06-22T0640+0200
* Append WJ to level-10 digit emoji       5.3.0.10.0 Sun 2025-06-22T0520+0200
* Replace cursive non-joiner with WJ      5.3.0.9.0  Sat 2025-06-21T0826+0200
* Debug level-10 letter emoji             5.3.0.8.0  Fri 2025-06-20T0934+0200
* Level 10 letter emoji, subdiv flags     5.3.0.7.0  Fri 2025-06-20T0717+0200
* Work around the column-02 bug           5.3.0.6.0  Thu 2025-06-19T0817+0200
* Debug level-10 tag characters           5.3.0.5.0  Thu 2025-06-19T0641+0200
* Level 10 for tag characters             5.3.0.4.0  Thu 2025-06-19T0504+0200
* Debug level-9 infrastructure            5.3.0.3.0  Wed 2025-06-18T0317+0200
* Complete level-9 infrastructure         5.3.0.2.0  Tue 2025-06-17T1656+0200
* Replicate row-E emoji on level 9        5.3.0.1.0  Mon 2025-06-16T2153+0200
* Support regional indicator letters      5.3.0.0.0  Mon 2025-06-16T1643+0200
* Debug circumflex in legacy code         5.2.0.5.0  Sun 2025-06-15T1249+0200
* Add U+1F642 emoji, debug cedilla        5.2.0.4.0  Fri 2025-06-13T0645+0200
* Change cedilla dead character           5.2.0.3.12 Thu 2025-06-12T2329+0200
* Debug DEADTRANS macro                   5.2.0.3.11 Thu 2025-06-12T0556+0200
* Debug DEADTRANS macro                   5.2.0.3.10 Thu 2025-06-12T0514+0200
* Debug DEADTRANS macro                   5.2.0.3.9  Thu 2025-06-12T0426+0200
* Update typedefs of DEADTRANS macro      5.2.0.3.8  Thu 2025-06-12T0038+0200
* Extend DEADTRANS macro                  5.2.0.3.7  Wed 2025-06-11T2337+0200
* Test 16-bit literals                    5.2.0.3.6  Tue 2025-06-10T0707+0200
* Test multicharacter array               5.2.0.3.5  Tue 2025-06-10T0503+0200
* Test UTF-32 character code              5.2.0.3.4  Tue 2025-06-10T0413+0200
* Debug SMP emoji literal                 5.2.0.3.3  Tue 2025-06-10T0321+0200
* Test SMP emoji literal                  5.2.0.3.2  Tue 2025-06-10T0252+0200
* Debug string output                     5.2.0.3.1  Mon 2025-06-09T1448+0200
* Test string output                      5.2.0.3.0  Mon 2025-06-09T0744+0200
* Correct high surrogates                 5.2.0.2    Sat Jun 07 00:42 2025
* Add 0xD83D                                         Fri Jun 06 08:45 2025
* Support high surrogates                            Thu Jun 05 02:55 2025
* Test high surr.                         5.2.0.1    Wed Jun 04 19:08 2025
* Test dead keys v5.2                     5.2.0.0    Tue Jun 03 23:09 2025
* Update group char v5.2                             Mon Jun 02 04:03 2025
* Sync key D07, v5.1                                 Mon Apr 28 09:20 2025
* Upgrade to v5.1                                    Fri Apr 18 02:32 2025
* Upgrade to v5 complete                             Sun Apr 13 18:42 2025
* Upgrade to v5                                      Tue Apr 01 13:31 2025
* Update layout to 4.16                              Fri Dec 27 03:24 2024
* Debug layout                                       Fri Dec 20 23:56 2024
* Streamline SGCaps                                  Thu Dec 19 08:44 2024
* Fix ligatures, 4.15                                Wed Dec 18 19:51 2024
* Fix KbdUTool transpiler                            Mon Dec 16 01:19 2024
* KBDTOOL v3.40 - Created                            Sun Dec 15 20:52:48 2024
*
\*****************************************************************************/

#include <windows.h>
#include "kbredispo.h"
#include "kbcommon.h"

#if defined(_M_IA64)
#pragma section(".data")
#define ALLOC_SECTION_LDATA __declspec(allocate(".data"))
#else
#pragma data_seg(".data")
#define ALLOC_SECTION_LDATA
#endif

#include "kbfrFRr-allo.c"

static ALLOC_SECTION_LDATA LIGATURE16 aLigature[] = {

  {VK_ESCAPE ,3 ,' ' ,'f' ,'r' ,'_' ,'F' ,'R' ,'_' ,'r' ,'e' ,'d' ,'i' ,'s' ,'p' ,'o' ,'s' ,0x00e9 },
	// The first code unit of long multiunit ligatures may not be output, hence the leading space.

  #include "kbligredispo.c"
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
* Note on kbfrFRr1.DEF
*
* The .DEF file is not provided. The Keyboard Table Generation Tool (Unicode)
* generates a .DEF file on the fly while transpiling kbfrFRr1.klc right before
* giving the sources to the compiler. So, no need to support the .DEF file as
* a part of the source code.
*
* For reference, this is the content of kbfrFRr1.DEF:

LIBRARY kbfrFRr1
 
 EXPORTS 
    KbdLayerDescriptor @1


\*****************************************************************************/

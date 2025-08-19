/*****************************************************************************\
* Module Name: kbfrFRs.C
*
* keyboard layout
*
* Copyright (c) 1985-2001, Microsoft Corporation
* Copyright (c) 2014-2025, Marcel Schneider dev[arobase]dispoclavier.com
*
* History:
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

  {VK_ESCAPE    ,5      ,' '      ,'6'      ,'.'      ,'0'      ,'.'      ,'2'      ,'.'      ,'0'      ,'1'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_ESCAPE    ,4      ,' '      ,'f'      ,'r'      ,'_'      ,'F'      ,'R'      ,'_'      ,'s'      ,'e'      ,'m'      ,'i'      ,'_'      ,'a'      ,'u'      ,'t'      ,'o'      },

  /*****************************************************************************\
  * Ligature array.
  *
  * Windows crashed when a multiunit string with five or more code units was at
  * the Shift + Ctrl + Alt level in the default keyboard layout.
  *
  * MSKLC developer M. S. Kaplan was asked about the topic and responded.
  * https://archives.miloush.net/michkap/archive/2015/08/07/8770668856267196989.html
  *
  * Multiunit strings for live keys are transpiled by KbdUTool only if their
  * length does not exceed five UTF-16 code units, as ligatures are defined in
  * kbd.h:473 only up to a length of 5 units. Consistently, KbdUTool returns a
	* warning.
  *
  * Supporting ligatures up to the architectural limit of 16 code units only
  * takes defining them accordingly, as done in kbcommon.h, section 7.2, and
  * synching static ALLOC_SECTION_LDATA LIGATURE5 aLigature[], where
  * LIGATURE5 is now LIGATURE16; as well as setting sizeof(aLigature[0]) to
	* 16, while ruling out the Control + Alt level-3 modifier in favor of
	* another modifier.
  *
  * Ligatures of 14 code units are required to support subdivision flags.
  *
  * The 3 subdivision flags supported by Unicode are supported as all-in-one
  * sequences, in lieu of the tag small letters, given the absence of other
  * flags in this category. Their level-10 map is stacked, on key C12 for
	* Wales, D12 for England, and E12 for Scotland, with geospatial mnemonics
  # using the stacked layout of these keys, with respect to the requirement of
  # duplicate mappings of C02 on C11, D02 on D11, and E02 on E11 due to the
  # column-02 bug affecting level 10, i.e. Shift + AltLe (decimal 65, 0x41),
  # and with keycap mnemonics using "£" printed in Shift position on D12 of
  # French AZERTY, on C12 of Belgian AZERTY.
  * https://unicode.org/emoji/charts/emoji-list.html#subdivision-flag
  * See * Known bugs
  *
  * Modification # 17 and 18 are also grouped below.
  \*****************************************************************************/

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
  {VK_OEM_MINUS ,17     ,0xD83E   ,0xDDAD   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // SEAL emoji U1F9AD
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
  {VK_OEM_6     ,17     ,0x26a0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
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
  {VK_OEM_3     ,3      ,0x005b   ,0x2026   ,0x005d   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
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
  {VK_OEM_COMMA ,17     ,0x2753   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,18     ,0xd83c   ,0xDDFD   ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,1      ,0x202f   ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,6      ,0xd83d   ,0xde31   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,7      ,0xd83d   ,0xdce3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,14     ,'&'      ,'#'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,16     ,0xd83d   ,0xdce2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,17     ,0x2757   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,18     ,0xd83c   ,0xDDEB   ,0xd83c   ,0xDDF7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,1      ,0x202f   ,':'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,7      ,0xd83d   ,0xde15   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,16     ,0xd83d   ,0xde12   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,17     ,0xd83c   ,0xdff3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,18     ,0xd83c   ,0xDDEA   ,0xd83c   ,0xDDFA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,1      ,0x202f   ,'!'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,7      ,0xd83d   ,0xdc94   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,16     ,0xd83d   ,0xde09   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,17     ,0xd83c   ,0xdff4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,18     ,0xd83c   ,0xDDFA   ,0xd83c   ,0xDDF3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_SPACE     ,5      ,' '      ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_SPACE     ,12     ,'&'      ,'n'      ,'b'      ,'s'      ,'p'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_SPACE     ,14     ,'&'      ,'#'      ,'x'      ,'2'      ,'0'      ,'2'      ,'F'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_SPACE     ,15     ,'&'      ,'#'      ,'x'      ,'2'      ,'0'      ,'2'      ,'F'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_SPACE     ,16     ,'&'      ,'n'      ,'b'      ,'s'      ,'p'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_NUMPAD0   ,1      ,'0'      ,'0'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_NUMPAD0   ,10     ,'0'      ,'0'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_NUMPAD1   ,1      ,'0'      ,'0'      ,'0'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_NUMPAD1   ,10     ,'0'      ,'0'      ,'0'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_DIVIDE    ,12     ,'\\'     ,'u'      ,'{'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_DIVIDE    ,14     ,'\\'     ,'u'      ,'{'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_DIVIDE    ,16     ,'\\'     ,'u'      ,'{'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_MULTIPLY  ,12     ,'\\'     ,'x'      ,'{'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_MULTIPLY  ,14     ,'\\'     ,'x'      ,'{'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_MULTIPLY  ,16     ,'\\'     ,'x'      ,'{'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_ADD       ,12     ,'0'      ,'x'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_ADD       ,14     ,'0'      ,'x'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_ADD       ,16     ,'0'      ,'x'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

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

  /*****************************************************************************\
  * Mathematical alphabetic symbols.
  *
  * Unicode warns that “[t]he characters in this block are intended for use
  * only in mathematical or technical notation, and not in nontechnical text.”
  * https://www.unicode.org/versions/Unicode16.0.0/core-spec/chapter-22/#G15993
  *
  * However, in search engines, these characters are fully equivalent to the
  * Latin base alphabet, even when entered in double quotes, to account for the
  * fact that these alphabets are used/repurposed to write formatted text in
  * fields accepting only plain text, the better as combining diacritics are
  * supported.
  *
  * While the full set of 13 Latin alphabets and 5 Greek alphabets is supported
  * in the dead key source Compose.yml, only 5 alphabets can be supported on
  * Windows live keys due to the bugs affecting the CAPITAL modifier with Shift
  * or with OEM_102.
  * See * aModification[]
  *
  * The current selection encompasses italic with sans-serif digits (as there
  * are no italic digits), double-struck, bold script or bold calligraphic with
  * bold digits, sans-serif bold, and script with monospace digits.
	*
	* As a result, all 5 sets of preformatted Western Arabic digits are supported
	* along the set of supported alphabets, that should meet presumed user
  * expectations in a context preferring sans-serif fonts, in which the four
	* sans-serif alphabets are redundant, while the scheme assumes serif default,
	* and consistently skips the normal-style normal-weight serif alphabet.
	*
	* As of the 2 Fraktur alphabets, they are politically connotated and thus
	* disqualify for support on keyboard layouts.
	*
	* If considering that monospace is vintage except in programming and related
	* environments, there are only six alphabets left, of which bold-italic may
	* be discarded as being too much formatted for support on keyboard layouts.
  *
  *
  /*****************************************************************************\
  * Italic "𝐴" U1D434.."𝑧" U1D467 with sans-serif digits "𝟢" U1D7E2.."𝟫" U1D7EB.
  *
  * These are the user-perceived (Shift +) AltQr levels.
  \*****************************************************************************/

  {'0'          ,19     ,0xd835   ,0xDFE2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,19     ,0xd835   ,0xDFE3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,19     ,0xd835   ,0xDFE4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,19     ,0xd835   ,0xDFE5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,19     ,0xd835   ,0xDFE6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,19     ,0xd835   ,0xDFE7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,19     ,0xd835   ,0xDFE8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,19     ,0xd835   ,0xDFE9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,19     ,0xd835   ,0xDFEA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,19     ,0xd835   ,0xDFEB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,19     ,0xd835   ,0xDC4E   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,19     ,0xd835   ,0xDC4F   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,19     ,0xd835   ,0xDC50   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,19     ,0xd835   ,0xDC51   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,19     ,0xd835   ,0xDC52   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,19     ,0xd835   ,0xDC53   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,19     ,0xd835   ,0xDC54   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,19     ,0x210E   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,19     ,0xd835   ,0xDC56   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,19     ,0xd835   ,0xDC57   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,19     ,0xd835   ,0xDC58   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,19     ,0xd835   ,0xDC59   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,19     ,0xd835   ,0xDC5A   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,19     ,0xd835   ,0xDC5B   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,19     ,0xd835   ,0xDC5C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,19     ,0xd835   ,0xDC5D   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,19     ,0xd835   ,0xDC5E   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,19     ,0xd835   ,0xDC5F   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,19     ,0xd835   ,0xDC60   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,19     ,0xd835   ,0xDC61   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'U'          ,19     ,0xd835   ,0xDC62   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,19     ,0xd835   ,0xDC63   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,19     ,0xd835   ,0xDC64   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,19     ,0xd835   ,0xDC65   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,19     ,0xd835   ,0xDC66   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Z'          ,19     ,0xd835   ,0xDC67   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  {'0'          ,20     ,0xd835   ,0xDFE2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,20     ,0xd835   ,0xDFE3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,20     ,0xd835   ,0xDFE4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,20     ,0xd835   ,0xDFE5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,20     ,0xd835   ,0xDFE6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,20     ,0xd835   ,0xDFE7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,20     ,0xd835   ,0xDFE8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,20     ,0xd835   ,0xDFE9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,20     ,0xd835   ,0xDFEA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,20     ,0xd835   ,0xDFEB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,20     ,0xd835   ,0xDC34   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,20     ,0xd835   ,0xDC35   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,20     ,0xd835   ,0xDC36   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,20     ,0xd835   ,0xDC37   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,20     ,0xd835   ,0xDC38   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,20     ,0xd835   ,0xDC39   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,20     ,0xd835   ,0xDC3A   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,20     ,0xd835   ,0xDC3B   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,20     ,0xd835   ,0xDC3C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,20     ,0xd835   ,0xDC3D   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,20     ,0xd835   ,0xDC3E   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,20     ,0xd835   ,0xDC3F   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,20     ,0xd835   ,0xDC40   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,20     ,0xd835   ,0xDC41   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,20     ,0xd835   ,0xDC42   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,20     ,0xd835   ,0xDC43   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,20     ,0xd835   ,0xDC44   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,20     ,0xd835   ,0xDC45   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,20     ,0xd835   ,0xDC46   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,20     ,0xd835   ,0xDC47   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'U'          ,20     ,0xd835   ,0xDC48   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,20     ,0xd835   ,0xDC49   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,20     ,0xd835   ,0xDC4A   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,20     ,0xd835   ,0xDC4B   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,20     ,0xd835   ,0xDC4C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Z'          ,20     ,0xd835   ,0xDC4D   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  /*****************************************************************************\
  * Double-struck "𝔸" U1D538.."𝕫" U1D56B, "𝟘" U1D7D8.."𝟡" U1D7E1.
  *
  * These are the user-perceived (Shift +) AltGr + AltQr levels.
  \*****************************************************************************/

  {'0'          ,21     ,0xd835   ,0xDFD8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,21     ,0xd835   ,0xDFD9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,21     ,0xd835   ,0xDFDA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,21     ,0xd835   ,0xDFDB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,21     ,0xd835   ,0xDFDC   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,21     ,0xd835   ,0xDFDD   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,21     ,0xd835   ,0xDFDE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,21     ,0xd835   ,0xDFDF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,21     ,0xd835   ,0xDFE0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,21     ,0xd835   ,0xDFE1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,21     ,0xd835   ,0xDD52   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,21     ,0xd835   ,0xDD53   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,21     ,0xd835   ,0xDD54   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,21     ,0xd835   ,0xDD55   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,21     ,0xd835   ,0xDD56   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,21     ,0xd835   ,0xDD57   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,21     ,0xd835   ,0xDD58   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,21     ,0xd835   ,0xDD59   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,21     ,0xd835   ,0xDD5A   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,21     ,0xd835   ,0xDD5B   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,21     ,0xd835   ,0xDD5C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,21     ,0xd835   ,0xDD5D   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,21     ,0xd835   ,0xDD5E   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,21     ,0xd835   ,0xDD5F   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,21     ,0xd835   ,0xDD60   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,21     ,0xd835   ,0xDD61   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,21     ,0xd835   ,0xDD62   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,21     ,0xd835   ,0xDD63   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,21     ,0xd835   ,0xDD64   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,21     ,0xd835   ,0xDD65   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'U'          ,21     ,0xd835   ,0xDD66   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,21     ,0xd835   ,0xDD67   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,21     ,0xd835   ,0xDD68   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,21     ,0xd835   ,0xDD69   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,21     ,0xd835   ,0xDD6A   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Z'          ,21     ,0xd835   ,0xDD6B   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  {'0'          ,22     ,0xd835   ,0xDFD8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,22     ,0xd835   ,0xDFD9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,22     ,0xd835   ,0xDFDA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,22     ,0xd835   ,0xDFDB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,22     ,0xd835   ,0xDFDC   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,22     ,0xd835   ,0xDFDD   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,22     ,0xd835   ,0xDFDE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,22     ,0xd835   ,0xDFDF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,22     ,0xd835   ,0xDFE0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,22     ,0xd835   ,0xDFE1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,22     ,0xd835   ,0xDD38   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,22     ,0xd835   ,0xDD39   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,22     ,0x2102   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,22     ,0xd835   ,0xDD3B   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,22     ,0xd835   ,0xDD3C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,22     ,0xd835   ,0xDD3D   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,22     ,0xd835   ,0xDD3E   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,22     ,0x210D   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,22     ,0xd835   ,0xDD40   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,22     ,0xd835   ,0xDD41   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,22     ,0xd835   ,0xDD42   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,22     ,0xd835   ,0xDD43   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,22     ,0xd835   ,0xDD44   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,22     ,0x2115   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,22     ,0xd835   ,0xDD46   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,22     ,0x2119   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,22     ,0x211A   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,22     ,0x211D   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,22     ,0xd835   ,0xDD4A   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,22     ,0xd835   ,0xDD4B   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'U'          ,22     ,0xd835   ,0xDD4C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,22     ,0xd835   ,0xDD4D   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,22     ,0xd835   ,0xDD4E   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,22     ,0xd835   ,0xDD4F   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,22     ,0xd835   ,0xDD50   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Z'          ,22     ,0x2124   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  /*****************************************************************************\
  * Bold Script, Bold Roundhand; Bold Calligraphic, Bold Chancery
	* "𝓐" U1D4D0.."𝔃" U1D503 with bold "𝟎" U1D7CE.."𝟗" U1D7D7.
  *
  * These are the user-perceived (Shift +) AltFr + AltQr levels.
  \*****************************************************************************/

  {'0'          ,23     ,0xd835   ,0xDFCE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,23     ,0xd835   ,0xDFCF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,23     ,0xd835   ,0xDFD0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,23     ,0xd835   ,0xDFD1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,23     ,0xd835   ,0xDFD2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,23     ,0xd835   ,0xDFD3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,23     ,0xd835   ,0xDFD4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,23     ,0xd835   ,0xDFD5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,23     ,0xd835   ,0xDFD6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,23     ,0xd835   ,0xDFD7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,23     ,0xd835   ,0xDCEA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,23     ,0xd835   ,0xDCEB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,23     ,0xd835   ,0xDCEC   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,23     ,0xd835   ,0xDCED   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,23     ,0xd835   ,0xDCEE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,23     ,0xd835   ,0xDCEF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,23     ,0xd835   ,0xDCF0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,23     ,0xd835   ,0xDCF1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,23     ,0xd835   ,0xDCF2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,23     ,0xd835   ,0xDCF3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,23     ,0xd835   ,0xDCF4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,23     ,0xd835   ,0xDCF5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,23     ,0xd835   ,0xDCF6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,23     ,0xd835   ,0xDCF7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,23     ,0xd835   ,0xDCF8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,23     ,0xd835   ,0xDCF9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,23     ,0xd835   ,0xDCFA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,23     ,0xd835   ,0xDCFB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,23     ,0xd835   ,0xDCFC   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,23     ,0xd835   ,0xDCFD   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'U'          ,23     ,0xd835   ,0xDCFE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,23     ,0xd835   ,0xDCFF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,23     ,0xd835   ,0xDD00   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,23     ,0xd835   ,0xDD01   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,23     ,0xd835   ,0xDD02   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Z'          ,23     ,0xd835   ,0xDD03   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  {'0'          ,24     ,0xd835   ,0xDFCE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,24     ,0xd835   ,0xDFCF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,24     ,0xd835   ,0xDFD0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,24     ,0xd835   ,0xDFD1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,24     ,0xd835   ,0xDFD2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,24     ,0xd835   ,0xDFD3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,24     ,0xd835   ,0xDFD4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,24     ,0xd835   ,0xDFD5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,24     ,0xd835   ,0xDFD6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,24     ,0xd835   ,0xDFD7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,24     ,0xd835   ,0xDCD0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,24     ,0xd835   ,0xDCD1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,24     ,0xd835   ,0xDCD2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,24     ,0xd835   ,0xDCD3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,24     ,0xd835   ,0xDCD4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,24     ,0xd835   ,0xDCD5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,24     ,0xd835   ,0xDCD6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,24     ,0xd835   ,0xDCD7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,24     ,0xd835   ,0xDCD8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,24     ,0xd835   ,0xDCD9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,24     ,0xd835   ,0xDCDA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,24     ,0xd835   ,0xDCDB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,24     ,0xd835   ,0xDCDC   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,24     ,0xd835   ,0xDCDD   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,24     ,0xd835   ,0xDCDE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,24     ,0xd835   ,0xDCDF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,24     ,0xd835   ,0xDCE0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,24     ,0xd835   ,0xDCE1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,24     ,0xd835   ,0xDCE2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,24     ,0xd835   ,0xDCE3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'U'          ,24     ,0xd835   ,0xDCE4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,24     ,0xd835   ,0xDCE5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,24     ,0xd835   ,0xDCE6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,24     ,0xd835   ,0xDCE7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,24     ,0xd835   ,0xDCE8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Z'          ,24     ,0xd835   ,0xDCE9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  /*****************************************************************************\
  * Sans-serif bold "𝗔" U1D5D4.."𝘇" U1D607, "𝟬" U1D7EC.."𝟵" U1D7F5.
  *
  * These are the user-perceived (Shift +) AltGr + AltFr + AltQr levels.
  \*****************************************************************************/

  {'0'          ,25     ,0xd835   ,0xDFEC   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,25     ,0xd835   ,0xDFED   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,25     ,0xd835   ,0xDFEE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,25     ,0xd835   ,0xDFEF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,25     ,0xd835   ,0xDFF0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,25     ,0xd835   ,0xDFF1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,25     ,0xd835   ,0xDFF2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,25     ,0xd835   ,0xDFF3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,25     ,0xd835   ,0xDFF4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,25     ,0xd835   ,0xDFF5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,25     ,0xd835   ,0xDDEE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,25     ,0xd835   ,0xDDEF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,25     ,0xd835   ,0xDDF0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,25     ,0xd835   ,0xDDF1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,25     ,0xd835   ,0xDDF2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,25     ,0xd835   ,0xDDF3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,25     ,0xd835   ,0xDDF4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,25     ,0xd835   ,0xDDF5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,25     ,0xd835   ,0xDDF6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,25     ,0xd835   ,0xDDF7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,25     ,0xd835   ,0xDDF8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,25     ,0xd835   ,0xDDF9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,25     ,0xd835   ,0xDDFA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,25     ,0xd835   ,0xDDFB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,25     ,0xd835   ,0xDDFC   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,25     ,0xd835   ,0xDDFD   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,25     ,0xd835   ,0xDDFE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,25     ,0xd835   ,0xDDFF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,25     ,0xd835   ,0xDE00   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,25     ,0xd835   ,0xDE01   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'U'          ,25     ,0xd835   ,0xDE02   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,25     ,0xd835   ,0xDE03   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,25     ,0xd835   ,0xDE04   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,25     ,0xd835   ,0xDE05   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,25     ,0xd835   ,0xDE06   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Z'          ,25     ,0xd835   ,0xDE07   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  {'0'          ,26     ,0xd835   ,0xDFEC   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,26     ,0xd835   ,0xDFED   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,26     ,0xd835   ,0xDFEE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,26     ,0xd835   ,0xDFEF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,26     ,0xd835   ,0xDFF0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,26     ,0xd835   ,0xDFF1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,26     ,0xd835   ,0xDFF2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,26     ,0xd835   ,0xDFF3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,26     ,0xd835   ,0xDFF4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,26     ,0xd835   ,0xDFF5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,26     ,0xd835   ,0xDDD4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,26     ,0xd835   ,0xDDD5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,26     ,0xd835   ,0xDDD6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,26     ,0xd835   ,0xDDD7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,26     ,0xd835   ,0xDDD8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,26     ,0xd835   ,0xDDD9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,26     ,0xd835   ,0xDDDA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,26     ,0xd835   ,0xDDDB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,26     ,0xd835   ,0xDDDC   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,26     ,0xd835   ,0xDDDD   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,26     ,0xd835   ,0xDDDE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,26     ,0xd835   ,0xDDDF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,26     ,0xd835   ,0xDDE0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,26     ,0xd835   ,0xDDE1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,26     ,0xd835   ,0xDDE2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,26     ,0xd835   ,0xDDE3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,26     ,0xd835   ,0xDDE4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,26     ,0xd835   ,0xDDE5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,26     ,0xd835   ,0xDDE6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,26     ,0xd835   ,0xDDE7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'U'          ,26     ,0xd835   ,0xDDE8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,26     ,0xd835   ,0xDDE9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,26     ,0xd835   ,0xDDEA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,26     ,0xd835   ,0xDDEB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,26     ,0xd835   ,0xDDEC   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Z'          ,26     ,0xd835   ,0xDDED   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  /*****************************************************************************\
  * Script, Roundhand; Calligraphic, Chancery "𝒜" U1D49C.."𝓏" U1D4CF
	* with monospace "𝟶" U1D7F6.."𝟿" U1D7FF.
  *
  * These are the user-perceived (AltGr +) AltLe + AltQr levels, as
  * Shift + AltLe does not work in column 02. But Shift + AltLe + AltQr is
	* supported regardless, with colum 02 duplicated in columns 11 or 07.
  *
  * Depending on the font, this may be the most inconsistent alphabet encoded
  * in two blocks. Consistently, it is the worst supported, at a level with a
  * buggy Shift level, replaced with AltGr not affected by the column-02 bug.
  \*****************************************************************************/

  {'0'          ,27     ,0xd835   ,0xDFF6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,27     ,0xd835   ,0xDFF7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,27     ,0xd835   ,0xDFF8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,27     ,0xd835   ,0xDFF9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,27     ,0xd835   ,0xDFFA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,27     ,0xd835   ,0xDFFB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,27     ,0xd835   ,0xDFFC   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,27     ,0xd835   ,0xDFFD   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,27     ,0xd835   ,0xDFFE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,27     ,0xd835   ,0xDFFF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,27     ,0xd835   ,0xDCB6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,27     ,0xd835   ,0xDCB7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,27     ,0xd835   ,0xDCB8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,27     ,0xd835   ,0xDCB9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,27     ,0x212F   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,27     ,0xd835   ,0xDCBB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,27     ,0x210A   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,27     ,0xd835   ,0xDCBD   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,27     ,0xd835   ,0xDCBE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,27     ,0xd835   ,0xDCBF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,27     ,0xd835   ,0xDCC0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,27     ,0xd835   ,0xDCC1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,27     ,0xd835   ,0xDCC2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,27     ,0xd835   ,0xDCC3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,27     ,0x2134   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,27     ,0xd835   ,0xDCC5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,27     ,0xd835   ,0xDCC6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,27     ,0xd835   ,0xDCC7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,27     ,0xd835   ,0xDCC8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,27     ,0xd835   ,0xDCC9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'U'          ,27     ,0xd835   ,0xDCCA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,27     ,0xd835   ,0xDCCB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,27     ,0xd835   ,0xDCCC   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,27     ,0xd835   ,0xDCCD   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,27     ,0xd835   ,0xDCCE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Z'          ,27     ,0xd835   ,0xDCCF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  {'0'          ,28     ,0xd835   ,0xDFF6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,28     ,0xd835   ,0xDFF7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,28     ,0xd835   ,0xDFF8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,28     ,0xd835   ,0xDFF8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,28     ,0xd835   ,0xDFF9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,28     ,0xd835   ,0xDFFA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,28     ,0xd835   ,0xDFFB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,28     ,0xd835   ,0xDFFC   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,28     ,0xd835   ,0xDFFD   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,28     ,0xd835   ,0xDFFE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,28     ,0xd835   ,0xDFFF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,28     ,0xd835   ,0xDC9C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,28     ,0x212C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,28     ,0xd835   ,0xDC9E   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,28     ,0xd835   ,0xDC9F   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,28     ,0x2130   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,28     ,0x2131   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,28     ,0xd835   ,0xDCA2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,28     ,0x210B   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,28     ,0x2110   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,28     ,0xd835   ,0xDCA5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,28     ,0xd835   ,0xDCA6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,28     ,0x2112   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,28     ,0x2133   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,28     ,0xd835   ,0xDCA9   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,28     ,0xd835   ,0xDCAA   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,28     ,0xd835   ,0xDCAB   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,28     ,0xd835   ,0xDCAC   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,28     ,0x211B   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,28     ,0xd835   ,0xDCAE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,28     ,0xd835   ,0xDCAE   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,28     ,0xd835   ,0xDCAF   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'U'          ,28     ,0xd835   ,0xDCB0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,28     ,0xd835   ,0xDCB1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,28     ,0xd835   ,0xDCB2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,28     ,0xd835   ,0xDCB3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,28     ,0xd835   ,0xDCB3   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,28     ,0xd835   ,0xDCB4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Z'          ,28     ,0xd835   ,0xDCB5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,28     ,0xd835   ,0xDCB5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  /*****************************************************************************\
  * Emoji (oncoming).
  *
  * Non-alphanumeric keys at the levels of the math alphabets, except the space
  * bar used for ordinary interword space in synergy with math alphabets, are
  * used for emoji, with an expected mnemonic benefit.
  *
  * Additionally, 4 partially working levels without and with KanaLock are used
  * for emoji too. The blackout affects keys C05, C06, C11, D05, D06, D11, D12.
  * Depending on the layout, the affected alphabetic keys are "G", "H", "T" and
  * "Y", or "G", "T", "U" and "Y".
  *
  * The placeholder emoji is "🔜" U1F51C SOON WITH RIGHTWARDS ARROW ABOVE.
  \*****************************************************************************/

  {VK_OEM_MINUS ,19     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,20     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,21     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,22     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,23     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,24     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,25     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,26     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,27     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,19     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,20     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,21     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,22     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,23     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,24     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,25     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,26     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,27     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,28     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,19     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,20     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,21     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,22     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,23     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,24     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,25     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,26     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,27     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,29     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,30     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,31     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,32     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,19     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,20     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,21     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,22     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,23     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,24     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,25     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,26     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,27     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,28     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,29     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,30     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,31     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,32     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,19     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,20     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,21     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,22     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,23     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,24     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,25     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,26     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,27     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,29     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,30     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,31     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,32     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,19     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,20     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,21     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,22     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,23     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,24     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,25     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,26     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,27     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,28     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,19     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,20     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,21     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,22     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,23     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,24     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,25     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,26     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,27     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,19     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,20     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,21     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,22     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,23     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,24     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,25     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,26     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,27     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,28     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,19     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,20     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,21     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,22     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,23     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,24     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,25     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,26     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,27     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,28     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,19     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,20     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,21     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,22     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,23     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,24     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,25     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,26     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,27     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,28     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  {'0'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,29     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {'H'          ,29     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {'I'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,29     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {'U'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,29     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {'Z'          ,29     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_SPACE     ,29     ,' '      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  {'0'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,30     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {'H'          ,30     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {'I'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,30     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {'U'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,30     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {'Z'          ,30     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_SPACE     ,30     ,' '      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  {'0'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,31     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {'H'          ,31     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {'I'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,31     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {'U'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,31     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {'Z'          ,31     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_SPACE     ,31     ,' '      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  {'0'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,32     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {'H'          ,32     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {'I'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,32     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {'U'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,32     ,' '      ,'n'      ,'e'      ,' '      ,'m'      ,'a'      ,'r'      ,'c'      ,'h'      ,'e'      ,' '      ,'p'      ,'a'      ,'s'      ,WCH_NONE ,WCH_NONE },
  {'Z'          ,32     ,0xD83D   ,0xDD1C   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_SPACE     ,32     ,' '      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

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
* Special values for wch[*] (column 3 & 4)
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
  {VK_SPACE     ,ALTGR  ,' '      ,' '      ,0x00a0   ,0x200b   ,0x202f   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,' '      ,' '      ,' '      ,' '      ,WCH_LGTR ,' '      ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,0x2060   ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
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

/*****************************************************************************\
* Module Name: kbfrAFs.C
*
* Row E of keyboard layout
*
* Copyright (c) 1985-2001, Microsoft Corporation
* Copyright (c) 2014-2025, Marcel Schneider dev[arobase]dispoclavier.com
*
* History:
* Improve Polynesian French variant      6.0.6.00.00 Tue 2025-09-02T1427+0200
* Support Francophone African variant    6.0.5.01.00 Sat 2025-08-30T2309+0200
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

// See #include "kbcommon.c" at file end.
#include "kbdeadtrans.c"

static ALLOC_SECTION_LDATA LIGATURE16 aLigature[] = {

  #include "kbligazerty.c"

  {VK_ESCAPE    ,4      ,' '      ,'f'      ,'r'      ,'_'      ,'A'      ,'F'      ,'_'      ,'s'      ,'e'      ,'m'      ,'i'      ,'_'      ,'a'      ,'u'      ,'t'      ,'o'      },

  #include "kbligatures.c"

  {0            ,0      ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        }
};

/*****************************************************************************\
* aVkToWch40[]  - Virtual Key to WCHAR translation for 40 shift states
*
* See kbcommon.c ### Caps Lock bug
* See kbcommon.c ### Level 7 bug
* See kbcommon.c ### Level 10 bug
*
\*****************************************************************************/
static ALLOC_SECTION_LDATA VK_TO_WCHARS40 aVkToWch40[] = {

  // Rows A..D are common to the main layout and all AZERTY variants.
  #include "kbcomazerty.c"

  //                    |         |  Shift  |  AltGr  | S+AltGr |  AltFr  | S+AltFr |AltGr+Fr | S+Gr+Fr |  Ctrl   | KanaLock| KL+Shift| KL+AltGr|KL+S+AlGr| KL+AltFr|KL+S+AlFr|KL+AGr+Fr|KL+S+Gr+F| CAPITAL |S+CAPITAL|
  //                    |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |AlFr+AlQr|S+AFr+AQr|         |AGr+CAPIT|
  // Modification #     |    0    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |   10    |   11    |   12    |   13    |   14    |   15    |   16    |   17    |   18    |   19    |   20    |   21    |   22    |   23    |   24    |   25    |   26    |   27    |   28    |   29    |   30    |   31    |   32    |   33    |   34    |   35    |   36    |   37    |   38    |   39    |
  //                    |=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|
  {'1'          ,KBD    ,0x025b   ,0x0190   ,'1'      ,'&'      ,'1'      ,0x00b9   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'1'      ,'1'      ,'1'      ,0x2081   ,'1'      ,0x00b9   ,0x2081   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'2'          ,KBD    ,0x00e9   ,0x00c9   ,'2'      ,WCH_DEAD ,'2'      ,0x00b2   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'2'      ,'2'      ,'2'      ,0x2082   ,'2'      ,0x00b2   ,0x2082   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'~'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,ALTGR  ,'\"'     ,0x2013   ,'3'      ,'#'      ,'3'      ,0x00b3   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'3'      ,'3'      ,'3'      ,0x2083   ,'3'      ,0x00b3   ,0x2083   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'4'          ,ALTGR  ,0x2019   ,0x2014   ,'4'      ,'{'      ,'4'      ,0x2074   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'4'      ,'4'      ,'4'      ,0x2084   ,'4'      ,0x2074   ,0x2084   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'5'          ,ALTGR  ,WCH_DEAD ,0x00ad   ,'5'      ,'['      ,'5'      ,0x2075   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'5'      ,'5'      ,'5'      ,0x2085   ,'5'      ,0x2075   ,0x2085   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,0x00eb   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,ALTGR  ,'-'      ,0x2011   ,'6'      ,'|'      ,'6'      ,0x2076   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'6'      ,'6'      ,'6'      ,0x2086   ,'6'      ,0x2076   ,0x2086   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,KBD    ,0x00e8   ,0x00c8   ,'7'      ,WCH_DEAD ,'7'      ,0x2077   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'7'      ,'7'      ,'7'      ,0x2087   ,'7'      ,0x2077   ,0x2087   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'`'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,KBD    ,0x0254   ,0x0186   ,'8'      ,'\\'     ,'8'      ,0x2078   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'8'      ,'8'      ,'8'      ,0x2088   ,'8'      ,0x2078   ,0x2088   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'9'          ,KBD    ,0x00e7   ,0x00c7   ,'9'      ,'('      ,'9'      ,0x2079   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'9'      ,'9'      ,'9'      ,0x2089   ,'9'      ,0x2079   ,0x2089   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'0'          ,KBD    ,0x00e0   ,0x00c0   ,'0'      ,')'      ,'0'      ,0x2070   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'0'      ,'0'      ,'0'      ,0x2080   ,'0'      ,0x2070   ,0x2080   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_MINUS ,ALTGR  ,'@'      ,0x00b0   ,0x1d49   ,']'      ,0x00b0   ,0x207b   ,'E'      ,WCH_LGTR ,WCH_NONE ,'@'      ,0x00b0   ,'-'      ,0x208b   ,'E'      ,0x207b   ,0x208b   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PLUS  ,ALTGR  ,'\''     ,'+'      ,WCH_DEAD ,'}'      ,'='      ,0x207a   ,'F'      ,WCH_LGTR ,WCH_NONE ,'='      ,'+'      ,WCH_DEAD ,0x208a   ,'F'      ,0x207a   ,0x208a   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,0x00a6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00a6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  //                    |=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|
  // Modification #     |    0    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |   10    |   11    |   12    |   13    |   14    |   15    |   16    |   17    |   18    |   19    |   20    |   21    |   22    |   23    |   24    |   25    |   26    |   27    |   28    |   29    |   30    |   31    |   32    |   33    |   34    |   35    |   36    |   37    |   38    |   39    |
  {0            ,0      ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        }
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
* Note on kbfrAFs.DEF
*
* The .def file is not provided. The Keyboard Table Generation Tool (Unicode)
* generates a .def file on the fly while transpiling kbfrAFs.klc right before
* giving the sources to the compiler. So, no need to support the .def file as
* a part of the source code. In the process, 25% less files.
*
* For reference, this is the content of kbfrAFs.DEF:

LIBRARY kbfrAFs
 
 EXPORTS 
    KbdLayerDescriptor @1


\*****************************************************************************/

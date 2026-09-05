/*****************************************************************************\
* Module Name: kbligredispo.c
*
* Remapped subset of ligatures
*
* Copyright:
* 1985..2001 Microsoft Corporation (pro parte)
* 2014..2026 Marcel Schneider dev[arobase]dispoclavier.com (pro parte)
*
* History:
* Update levels 7 and 8                    7.0.0.0.6 Sat 2026-09-05T1035+0200
* Permutate D07 and D08, level 8           7.0.0.0.4 Sat 2026-08-01T1740+0200
* Move U1F642 and U1F614 on C02 and C05    7.0.0.0.3 Tue 2026-07-21T0642+0200
* Rename kbligqzjfgy.c to kbligredispo.c   6.0.3.4.0 Sat 2025-08-23T1637+0200
* Move remapped MCUs to kbligqzjfgy.c      6.0.3.0.0 Wed 2025-08-20T1930+0200
* Add partial file kbligqzjfgy.c           6.0.3.0.0 Wed 2025-08-20T1748+0200
*
* This file only contains ligatures particular to QZJFGY. Keys that do not
* change across layouts are commented out, and only one sample is provided.
* Ligatures that do not change across layouts are configured in kbligatures.c.
*
\*****************************************************************************/

// static ALLOC_SECTION_LDATA LIGATURE16 aLigature[] = {

  // […]

  {'Q'          ,5      ,0xd801   ,0xdfa5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "𐞥" U107A5
  {'Q'          ,6      ,'c'      ,0x02bc   ,'h'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,7      ,'C'      ,0x02bc   ,'h'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  // {'Z'          ,7      ,0xd83d   ,0xde27   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "😧" U1F627
  {'J'          ,6      ,'&'      ,'q'      ,'u'      ,'o'      ,'t'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,7      ,0xd83e   ,0xdd14   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "🤔" U1F914
  {'G'          ,7      ,0xd83d   ,0xde0a   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "😊" U1F60A
  // {'Y'          ,7      ,0xd83d   ,0xde0d   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "😍" U1F60D
  {'M'          ,6      ,'U'      ,'+'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,7      ,'\\'     ,'u'      ,'{'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,6      ,'&'      ,'a'      ,'m'      ,'p'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,7      ,0xd83d   ,0xde05   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "😅" U1F605
  {'D'          ,7      ,0xd83d   ,0xde01   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "😁" U1F601
  {'K'          ,7      ,0xd83d   ,0xde4f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "🙏" U1F64F
  // {VK_OEM_6     ,1      ,0x2039   ,0x202f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  // {VK_OEM_1     ,1      ,0x202f   ,0x203a   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,7      ,0xd83d   ,0xdc4f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "👏" U1F44F
  // {'S'          ,7      ,0xd83d   ,0xde42   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "🙂" U1F642
  {'E'          ,7      ,0xd83d   ,0xde06   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "😆" U1F606
  {'R'          ,7      ,0xd83d   ,0xdd25   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "🔥" U1F525
  {'T'          ,7      ,0xd83d   ,0xde14   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "😔" U1F614
  {'U'          ,7      ,0xd83d   ,0xdc4d   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "👍" U1F44D
  {'N'          ,7      ,0xd83d   ,0xde02   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "😂" U1F602
  {'O'          ,7      ,'&'      ,'a'      ,'p'      ,'o'      ,'s'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,7      ,0xd83e   ,0xdd23   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "🤣" U1F923
  {'P'          ,7      ,0xd83d   ,0xde37   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "😷" U1F637
  // {VK_OEM_3     ,1      ,0x00ab   ,0x202f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  // {VK_OEM_5     ,1      ,0x202f   ,0x00bb   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  // {'W'          ,7      ,0xd83d   ,0xde22   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "😢" U1F622
  // {'X'          ,7      ,0xd83c   ,0xdf1f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE }, // "🌟" U1F31F
  // {'C'          ,6      ,'&'      ,'l'      ,'t'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  // {'V'          ,6      ,'&'      ,'g'      ,'t'      ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  // {'B'          ,4      ,'0'      ,'0'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,6      ,'n'      ,0x1d52   ,0x202f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,7      ,'N'      ,0x1d52   ,0x202f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  // {VK_OEM_COMMA ,1      ,0x202f   ,'?'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  // {VK_OEM_PERIOD,1      ,0x202f   ,';'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  // {VK_OEM_2     ,1      ,0x202f   ,':'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  // {VK_OEM_8     ,1      ,0x202f   ,'!'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  // {VK_SPACE     ,5      ,' '      ,0x2060   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },

  // […]

  // {0            ,0      ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        }
// };

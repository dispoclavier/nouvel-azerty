/*****************************************************************************\
* Module Name: kbbrFRs1.C
*
* Keyboard layout C source
*
* Copyright:
* 1985..2001 Microsoft Corporation (pro parte)
* 2014..2026 Marcel Schneider dev[arobase]dispoclavier.com (pro parte)
*
* History:
* Rename kbbrFRs.C to kbbrFRs1.C           6.0.9.8.0 Thu 2025-10-02T1446+0200
* Move alloc table to kbbrFRs-allo.c       6.0.8.0.0 Thu 2025-09-25T1835+0200
* Move variant ID to UX level 4            6.0.7.3.0 Sun 2025-09-21T1332+0200
* Move kbdeadtrans.c #inc to kbcommon.c    6.0.7.2.0 Tue 2025-09-16T0311+0200
* Add 6 spare modification numbers         6.0.5.0.0 Sat 2025-08-30T2006+0200
* Udpdate to Unicode 17.0                  6.0.4.2.0 Wed 2025-08-27T2007+0200
* Add okay emoji for broken key combos     6.0.4.1.0 Wed 2025-08-27T1840+0200
* Move <windows.h> back to C sources       6.0.4.0.0 Wed 2025-08-27T1304+0200
* Try to debug allocation table            6.0.3.4.0 Sat 2025-08-23T1704+0200
* Support Breton variant on Windows        6.0.3.3.0 Fri 2025-08-22T2248+0200
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

#include "kbbrFRs-allo.c"

static ALLOC_SECTION_LDATA LIGATURE16 aLigature[] = {

  {VK_ESCAPE ,3 ,' ' ,'b' ,'r' ,'_' ,'F' ,'R' ,'_' ,'s' ,'e' ,'m' ,'i' ,'_' ,'a' ,'u' ,'t' ,'o' },
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
* Note on kbbrFRs1.DEF
*
* The .DEF file is not provided. The Keyboard Table Generation Tool (Unicode)
* generates a .DEF file on the fly while transpiling kbbrFRs1.klc right before
* giving the sources to the compiler. So, no need to support the .DEF file as
* a part of the source code.
*
* For reference, this is the content of kbbrFRs1.DEF:

LIBRARY kbbrFRs1
 
 EXPORTS 
    KbdLayerDescriptor @1


\*****************************************************************************/

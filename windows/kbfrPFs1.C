/*****************************************************************************\
* Module Name: kbfrPFs1.C
*
* Keyboard layout C source.
*
* Copyright:
* 1985..2001 Microsoft Corporation (pro parte)
* 2014..2026 Marcel Schneider dev[arobase]dispoclavier.com (pro parte)
*
* History:
* Rename kbfrPFs.C to kbfrPFs1.C           6.0.9.8.0 Thu 2025-10-02T1515+0200
* Move alloc table to kbfrPFs-allo.c       6.0.8.0.0 Thu 2025-09-25T1835+0200
* Move variant ID to UX level 4            6.0.7.3.0 Sun 2025-09-21T1332+0200
* Move kbdeadtrans.c #inc to kbcommon.c    6.0.7.2.0 Tue 2025-09-16T0311+0200
* Improve Polynesian French variant        6.0.6.0.0 Tue 2025-09-02T1427+0200
* Support Polynesian French variant        6.0.5.1.0 Sat 2025-08-30T2300+0200
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

#include "kbfrPFs-allo.c"

static ALLOC_SECTION_LDATA LIGATURE16 aLigature[] = {

  {VK_ESCAPE ,3 ,' ' ,'f' ,'r' ,'_' ,'P' ,'F' ,'_' ,'s' ,'e' ,'m' ,'i' ,'_' ,'a' ,'u' ,'t' ,'o' },
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
* Note on kbfrPFs1.DEF
*
* The .DEF file is not provided. The Keyboard Table Generation Tool (Unicode)
* generates a .DEF file on the fly while transpiling kbfrPFs1.klc right before
* giving the sources to the compiler. So, no need to support the .DEF file as
* a part of the source code.
*
* For reference, this is the content of kbfrPFs1.DEF:

LIBRARY kbfrPFs1
 
 EXPORTS 
    KbdLayerDescriptor @1


\*****************************************************************************/

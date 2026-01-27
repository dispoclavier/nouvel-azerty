/*****************************************************************************\
* Module Name: kbfrFRr2.C
*
* Keyboard layout C source
*
* Copyright:
* 1985..2001 Microsoft Corporation (pro parte)
* 2014..2026 Marcel Schneider dev[arobase]dispoclavier.com (pro parte)
*
* History:
* Update variant descriptor string output  6.0.9.0.1 Mon 2025-09-29T1503+0200
* Copy from kbfrFRsr.C                     6.0.9.0.0 Mon 2025-09-29T1429+0200
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

#include "kbfrFRsr-allo.c"

static ALLOC_SECTION_LDATA LIGATURE16 aLigature[] = {

  {VK_ESCAPE ,3 ,' ' ,'f' ,'r' ,'_' ,'F' ,'R' ,'_' ,'r' ,'e' ,'d' ,'i' ,'s' ,'_' ,'b' ,'i' ,'s' },
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
* Note on kbfrFRr2.DEF
*
* The .DEF file is not provided. The Keyboard Table Generation Tool (Unicode)
* generates a .DEF file on the fly while transpiling kbfrFRr2.klc right before
* giving the sources to the compiler. So, no need to support the .DEF file as
* a part of the source code.
*
* For reference, this is the content of kbfrFRr2.DEF:

LIBRARY kbfrFRr2
 
 EXPORTS 
    KbdLayerDescriptor @1


\*****************************************************************************/

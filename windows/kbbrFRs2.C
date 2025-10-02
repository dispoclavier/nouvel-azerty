/*****************************************************************************\
* Module Name: kbbrFRs2.C
*
* Keyboard layout C source.
*
* Copyright (c) 1985-2001, Microsoft Corporation
* Copyright (c) 2014-2025, Marcel Schneider dev[arobase]dispoclavier.com
*
* History:
* Update variant descriptor string output  6.0.9.9.0 Thu 2025-10-02T1916+0200
* Copy from kbbrFRs1.C                     6.0.9.9.0 Thu 2025-10-02T1857+0200
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

  {VK_ESCAPE ,3 ,' ' ,'b' ,'r' ,'_' ,'F' ,'R' ,'_' ,'s' ,'e' ,'m' ,'i' ,'_' ,'_' ,'b' ,'i' ,'s' },
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
* Note on kbbrFRs2.DEF
*
* The .DEF file is not provided. The Keyboard Table Generation Tool (Unicode)
* generates a .DEF file on the fly while transpiling kbbrFRs2.klc right before
* giving the sources to the compiler. So, no need to support the .DEF file as
* a part of the source code.
*
* For reference, this is the content of kbbrFRs2.DEF:

LIBRARY kbbrFRs2
 
 EXPORTS 
    KbdLayerDescriptor @1


\*****************************************************************************/

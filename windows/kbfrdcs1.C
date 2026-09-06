/*****************************************************************************\
* Module Name: kbfrdcs1.C
*
* Keyboard layout C source.
*
* Copyright:
* 1985..2001 Microsoft Corporation (pro parte)
* 2014..2026 Marcel Schneider dev[arobase]dispoclavier.com (pro parte)
*
* History:
* Edit ID string output                    7.0.0.2.0 Sun 2026-09-06T0908+0200
* Adapt to kbfrdcs1.C                      7.0.0.0.0 Tue 2026-08-25T1954+0200
* Copy from kbfrFRs1.C                     7.0.0.0.0 Tue 2026-08-25T1816+0200
*
\*****************************************************************************/

#include <windows.h>
#include "kbcommon.h"
#include "kbfrdcs.h"

#if defined(_M_IA64)
#pragma section(".data")
#define ALLOC_SECTION_LDATA __declspec(allocate(".data"))
#else
#pragma data_seg(".data")
#define ALLOC_SECTION_LDATA
#endif

#include "kbfrdcs-allo.c"

static ALLOC_SECTION_LDATA LIGATURE16 aLigature[] = {

  {VK_ESCAPE ,3 ,' ' ,'f' ,'r' ,'_' ,'r' ,0x00e9 ,'t' ,'r' ,'o' ,'c' ,'o' ,'m' ,'_' ,'D' ,'C' ,'S' },
                 // The first code unit of long multiunit ligatures may not be output, hence the leading space.

  #include "kbfrdcs-ligatures.c"
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
* Note on kbfrdcs1.DEF
*
* The .DEF file is not provided. The Keyboard Table Generation Tool (Unicode)
* generates a .DEF file on the fly while transpiling kbfrdcs1.klc right before
* giving the sources to the compiler. So, no need to support the .DEF file as
* a part of the source code.
*
* For reference, this is the content of kbfrdcs1.DEF:

LIBRARY kbfrdcs1
 
 EXPORTS 
    KbdLayerDescriptor @1


\*****************************************************************************/

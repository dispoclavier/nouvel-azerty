/*****************************************************************************\
* Module Name: kbqzjfgy.h
*
* Generic locale keyboard layout header
*
* Copyright (c) 1985-2001, Microsoft Corporation
* Copyright (c) 2014-2025, Marcel Schneider dev[arobase]dispoclavier.com
*
* Various defines for use by keyboard input on French QZJFGY.
*
* History:
*
* Rename from kbfrFRsr.H to kbqzjfgy.h   Fri 2025-08-22T1135+0200
* Fix non-transpilation of KANA          Sun 2025-07-20T0355+0200
* Rename to kbfrFRsr.H                   Wed 2025-07-16T1322+0200
* created by KBDTOOL v3.40               Tue Jun 03 20:53:25 2025
*
\*****************************************************************************/

/*
 * kbd type should be controlled by cl command-line argument
 */
#define KBD_TYPE 4

#include <windows.h>

/*
 * Include the basis of all keyboard table values
 */
#include "kbd.h"

/**********************************************************************************\
* The table below defines the virtual keys for various keyboard types where
* the keyboard differ from the US keyboard.
*
* _EQ() : all keyboard types have the same virtual key for this scancode
* _NE() : different virtual keys for this scancode, depending on kbd type
*
*     +------+ +----------+----------+----------+----------+----------+----------+
*     | Scan | |    kbd   |    kbd   |    kbd   |    kbd   |    kbd   |    kbd   |
*     | code | |   type 1 |   type 2 |   type 3 |   type 4 |   type 5 |   type 6 |
\****+-------+_+----------+----------+----------+----------+----------+----------+*/

#undef  T29
 #define T29 _EQ(                                       KANA                      )
#undef  T11
 #define T11 _EQ(                                        'Z'                      )
#undef  T12
 #define T12 _EQ(                                        'J'                      )
#undef  T13
 #define T13 _EQ(                                        'F'                      )
#undef  T14
 #define T14 _EQ(                                        'G'                      )
#undef  T16
 #define T16 _EQ(                                        'M'                      )
#undef  T17
 #define T17 _EQ(                                        'L'                      )
#undef  T18
 #define T18 _EQ(                                        'D'                      )
#undef  T19
 #define T19 _EQ(                                        'K'                      )
#undef  T1A
 #define T1A _EQ(                                      OEM_6                      )
#undef  T1B
 #define T1B _EQ(                                      OEM_1                      )
#undef  T20
 #define T20 _EQ(                                        'E'                      )
#undef  T21
 #define T21 _EQ(                                        'R'                      )
#undef  T22
 #define T22 _EQ(                                        'T'                      )
#undef  T23
 #define T23 _EQ(                                        'U'                      )
#undef  T24
 #define T24 _EQ(                                        'N'                      )
#undef  T25
 #define T25 _EQ(                                        'O'                      )
#undef  T26
 #define T26 _EQ(                                        'I'                      )
#undef  T27
 #define T27 _EQ(                                        'P'                      )
#undef  T28
 #define T28 _EQ(                                      OEM_3                      )
#undef  T2C
 #define T2C _EQ(                                        'W'                      )
#undef  T31
 #define T31 _EQ(                                        'H'                      )
#undef  T32
 #define T32 _EQ(                                  OEM_COMMA                      )
#undef  T33
 #define T33 _EQ(                                 OEM_PERIOD                      )
#undef  T34
 #define T34 _EQ(                                      OEM_2                      )
#undef  T35
 #define T35 _EQ(                                      OEM_8                      )


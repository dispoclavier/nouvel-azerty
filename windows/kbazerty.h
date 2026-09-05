/*****************************************************************************\
* Module Name: kbazerty.h
*
* Virtual key defines for AZERTY keyboard layouts
*
* Copyright:
* 1985..2001 Microsoft Corporation (pro parte)
* 2014..2026 Marcel Schneider dev[arobase]dispoclavier.com (pro parte)
*
* History:
* Include kbd.h in kbcommon.h, not here    7.0.0.0.7 Sat 2026-09-05T1429+0200
* Remove redundant T29 _EQ( KANA ) define  7.0.0.0.0 Mon 2026-08-24T1702+0200
* Move #include <windows.h> back to C sources        Wed 2025-08-27T1300+0200
* Rename from kbfrFRs.H to kbazerty.h                Fri 2025-08-22T1127+0200
* Fix non-transpilation of KANA                      Sun 2025-07-20T0354+0200
* created by KBDTOOL v3.40                           Tue Jun 03 20:53:21 2025
*
\*****************************************************************************/

/*
 * kbd type should be controlled by cl command-line argument
 */
#define KBD_TYPE 4

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

#undef  T10
 #define T10 _EQ(                                        'A'                      )
#undef  T11
 #define T11 _EQ(                                        'Z'                      )
#undef  T1A
 #define T1A _EQ(                                      OEM_6                      )
#undef  T1B
 #define T1B _EQ(                                      OEM_1                      )
#undef  T1E
 #define T1E _EQ(                                        'Q'                      )
#undef  T27
 #define T27 _EQ(                                        'M'                      )
#undef  T28
 #define T28 _EQ(                                      OEM_3                      )
#undef  T2C
 #define T2C _EQ(                                        'W'                      )
#undef  T32
 #define T32 _EQ(                                  OEM_COMMA                      )
#undef  T33
 #define T33 _EQ(                                 OEM_PERIOD                      )
#undef  T34
 #define T34 _EQ(                                      OEM_2                      )
#undef  T35
 #define T35 _EQ(                                      OEM_8                      )


/*****************************************************************************\
* Module Name: kbcommon-3.c
*
* Common keyboard layout data, part 3.
*
* Copyright (c) 1985-2001, Microsoft Corporation
* Copyright (c) 2014-2025, Marcel Schneider dev[arobase]dispoclavier.com
*
* History:
* Move KbdTables and return here           6.0.8.0.3 Thu 2025-09-25T1133+0200
* Add partial file kbcommon-3.c            6.0.8.0.1 Thu 2025-09-25T0613+0200
*
* This file needs to be included last because it contains the return statement.
*
\*****************************************************************************/

/*****************************************************************************\
* Keyboard tables.
*
\*****************************************************************************/

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

/*****************************************************************************\
* Return statement.
*
\*****************************************************************************/

PKBDTABLES KbdLayerDescriptor(VOID)
{
    return &KbdTables;
}

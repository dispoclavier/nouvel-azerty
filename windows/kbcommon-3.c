/*****************************************************************************\
* Module Name: kbcommon-3.c
*
* Common keyboard layout data, part 3
*
* Copyright:
* 1985..2001 Microsoft Corporation (pro parte)
* 2014..2026 Marcel Schneider dev[arobase]dispoclavier.com (pro parte)
*
* History:
* Reinstate the KLLF_ALTGR flag            6.2.9.1.0 Wed 2026-04-08T2101+0200
* Set KLLF_ALTGR flag to 0                 6.2.9.0.0 Wed 2026-04-08T0921+0200
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
		 *
		 * KLLF_ALTGR is required for VK_RMENU to be distinct from VK_MENU. If this
		 * flag is not set, the AltGr key has the same effect as the Alt key.
		 *
		 * Other flags can also be set and can be combined. Set 0 for no flag.
		 *
		 *     KLLF_ALTGR = 1
		 *     KLLF_SHIFTLOCK = 2
		 *     KLLF_LRM_RLM = 4
		 *
		 * https://kbdlayout.info/features/flags
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

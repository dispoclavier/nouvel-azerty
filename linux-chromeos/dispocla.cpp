//                       Date: 2023-07-13T1710+0200
//                    Version: 1.0.0
//        Operating file name: dispocla
//                   Encoding: UTF-8
//                       Type: text/XKB configuration
//                   Language: C-like
//                Description: XKB character key allocation tables
//                   Platform: XKB with XCompose using OSes Linux and ChromeOS*
//
//               Project name: Dispoclavier
//                Project URL: https://dispoclavier.com
//                      Maxim: Simplify typewriting, not French.
//                    Maxime : Simplifier la dactylographie, pas le français.
//        English description: keyboard layouts adapted to national, regional and neighbor languages of Francophonie
//     Description française : dispositions de clavier adaptées aux langues nationales, régionales et voisines de la Francophonie
//              Target public: General public and developers, journalists, scientists, secretaries, translators, typographers and writers
//             Destinataires : Grand public et développeurs, écrivains, journalistes, scientifiques, secrétaires, traducteurs et typographes
//              Regular names: kb(brFRs|fr(AFs|BEs|CA(ms|s)|CHs|FR(h(w|z|y)|r|s)|PFs))
//   Full names, descriptions: kbbrFRs  Breton and French France semiautomatic keyboard layout
//                             kbfrAFs  Francophone Africa semiautomatic keyboard layout
//                             kbfrBEs  French Belgium semiautomatic keyboard layout
//                 (oncoming)  kbfrCAms French Canada multilingual semiautomatic keyboard layout
//                 (oncoming)  kbfrCAs  French Canada semiautomatic keyboard layout
//                 (oncoming)  kbfrCHs  French Switzerland semiautomatic keyboard layout
//                             kbfrFRhw French France hybrid AZERTY semiautomatic keyboard layout
//                             kbfrFRhy French France hybrid QWERTZ semiautomatic keyboard layout
//                             kbfrFRhz French France hybrid QWERTY semiautomatic keyboard layout
//                             kbfrFRr  French France remapped semiautomatic keyboard layout
//                             kbfrFRs  French France semiautomatic keyboard layout
//                             kbfrPFs  French Polynesia semiautomatic keyboard layout
//               Code licence: Apache 2.0
//           Code licence URL: https://www.apache.org/licenses/LICENSE-2.0
//           Non-code licence: CC-BY 4.0
//       Non-code licence URL: https://creativecommons.org/licenses/by/4.0/deed.fr
//              Email address: dev@dispoclavier.net
//
//   * In Unicode CLDR, this platform is labeled ChromeOS, and it is explained that
//     in the CLDR, *Linux* is supported alongside *ChromeOS*, or through ChromeOS.
//
//               Installation: 1. Add this file in /usr/share/X11/xkb/symbols/
//                             2. In /usr/share/X11/xkb/rules/evdev.xml
//                                add the lines contained in the file
//                                    evdev-additions.xml
//                                before the `</layoutList>` closing tag.
//                             The change takes effect when reopening a session.
//
//             Uninstallation: Delete those lines prior to removing the file.
//
//
// Note: C-style XKB configuration files don’t allow block comments.
//
//
// ##  French-style punctuation spacing semi-automation
//
// These layouts support output of polygrams after single keystrokes.
//
//
// ### Requirements
//
// The requirements about spacing out big punctuation marks in French text depend on
// the sublocale, the typesetting school and, for some sublocales, software support.
//
// In France, the new-school rules require a no-break thin space before ? ! : ; » ›,
// and after « ‹. They are followed in print editions of high-end newspapers, namely
// Le Monde, without being well documented, so as to prevent conflicts with the old
// school whose specification is the verbatim text of the National Printing Office’s
// style guide “Lexique des règles en usage à l’Imprimerie nationale”, stipulating a
// justifying no-break space before a colon, and inside the “guillemet” double angle
// quotation marks. In its eighth edition, of March 2017, a reprint of its July 2002
// edition, the colon is indeed spaced out as specified, whereas the angle quotation
// marks are spaced out the new-school way, with the same thin space used before the
// other three big punctuation marks question mark, exclamation mark, and semicolon.
// The verbatim text was not synced with the evolving usage, supposedly with respect
// to the strong user community tracking changes and possibly frowning upon this one
// because equally spaced-out guillemets are an outstanding feature in old printing.
// The new usage of the Imprimerie Nationale as of spacing out guillemets using thin
// space may be considered as intermediate typesetting school. About new school, see
// https://forums.macg.co/threads/typo-caracteres-capitales-accentues.25739/page-5#post-3151119
//
// Belgium applies either the French Imprimerie Nationale style guide or NBN Z01-002
// specifying that the punctuation marks ? ! : ; must not be spaced out. Guillemets
// as angle quotes are not mentioned in https://cuy.be/orthotypo/NORMES_D.pdf#page=12
//
// Canada has peculiar rules applying old school typesetting but suppressing the thin
// space if it is unavailable, in that the software does not insert it automatically.
// https://vitrinelinguistique.oqlf.gouv.qc.ca/index.php?id=22039
// https://vitrinelinguistique.oqlf.gouv.qc.ca/22039/la-typographie/espacement/espacement-avant-et-apres-les-signes-de-ponctuation-et-les-symboles
//
// Francophone Switzerland changed in 2015 from not spacing out to following France,
// but the reference is missing.
// And Franck Pastor reported on 2009-05-19 in http://www.cuk.ch/articles/4116/ that
// no-break thin space was already used also before colon and inside anqle quotation
// marks. In 2020, the University of Geneva has a rule about not spacing out ?!:;«»,
// but this rule is restricted to electronic usage, as which were considered website
// publishing, and email text body. Thus the spacing prohibition targets plain text,
// where NO-BREAK SPACE is unstable and may be replaced with SPACE in mail composers
// affected by a common bug, and HTML, where NO-BREAK SPACE is justifying, unlike it
// is in word processors other than Word 2013. As of NARROW NO-BREAK SPACE, it isn’t
// mentioned in the rule, but print and PDF are not mentioned either in the document
// https://www.unige.ch/communication/files/7815/9180/2109/ReglesTypographiques-UNIGE-2020.pdf#page=6
//
//
// ###  Technical note about French Old School typesetting
//
// Spacing colon and guillemets out with NO-BREAK SPACE does not work well because:
//
// 1  NO-BREAK SPACE (NBSP) is defined as justifying in Unicode, followed by HTML,
//    while in word processors (except MS Word 2013) it is tailored as fixed-width.
//    As a result, the colon is not spaced out the Old School way in word processors,
//    while on the web, question and exclamation mark and semicolon are neither.
// 2  MS Word replaces NBSP with SPACE when copy-pasting to plain text, resulting
//    in typesetting destruction. Web browsers like Chrome and Firefox do the same.
// 3  NBSP behaves like (or is replaced with) normal space in e-mail composers and
//    in web forms in many browsers.
//
//
// ###  French New School typesetting
//
// French new-school typesetting spaces out all big punctuation characters using the
// same non-breaking thin space both for ASCII ?!; and even colon, and for double angle
// quotation marks. The moderate old-school typesetting exemplified in the style guide
// of the French National Printing Office makes a special case for the colon, preceded
// by the justifying NO-BREAK SPACE, while the hard-core old school, described therein,
// sets apart the angle quotation marks too.
//
// The International System of Measures and Units (SI) from the BIPM recommends using
// a non-breaking thin space as a group separator in numbers, and it is followed by
// many locales including fr_FR. Also TeX supports it by the means of the '\,' command.
// Known for its consistency with legacy typographic craftmanship, Donald Knuth’s TeX
// maintained the thin space’s non-breaking behavior, and as a pre-Unicode environment
// it presumably informed the seminal Unicode Standard known for carefully maintaining
// full backwards compatibility.
//
// All layouts in this configuration file support mainstream practice used
// in the French graphic industry, also referred to as French New School.
// https://forums.macg.co/threads/typo-caracteres-capitales-accentues.25739/page-5#post-3151119
//
// The interoperable representation of French New School typesetting uses
// NARROW NO-BREAK SPACE with all punctuation characters that use to be spaced out,
// i.e. not only semicolon, exclamation mark and question mark as explicitly stated
// in the verbatim text of the Imprimerie nationale style guide, 2002 edition:
// _Lexique des règles typographiques en usage à l’Imprimerie nationale_
// but also the guillemets the way they are actually typeset in the 2002 edition,
// March 2017 reprint, ISBN 9782743304829, plus the colon.
//
// Single angle quotation marks are spaced out like double angle quotation marks.
// https://vitrinelinguistique.oqlf.gouv.qc.ca/index.php?id=22039
//
//
// ###  Unicode support for interoperable French
//
// In Unicode, a non-breaking thin space is encoded only since version 3.0, released in
// 1999, when U+202F NARROW NO-BREAK SPACE was encoded for Mongol script, but with the
// Script property Common and in the General Punctuation block. It was not so earlier,
// because U+2009 THIN SPACE was not assigned line breaking class GL. Another suitable
// space character, U+2008 PUNCTUATION SPACE, was not either, unlike U+2007 FIGURE SPACE.
// That flaw was introduced in the Unicode Standard on purpose, and in this case it is
// relatively easy to assess intentionality thanks to the typographic space range keeping
// original code points. Originally the typographic space range U+2000..U+200A was set up
// to include the two widest spaces both in a breaking variant (U+2000, U+2001) and in
// a non-breaking variant (U+2002, U+2003), making a clever use of aliases provided in
// Unicode’s template, the Xerox Character Code Standard, whereas all narrower spaces
// (U+2004..U+200A) would be non-breaking throughout. The initial design is lacking its
// official documentation because it was altered in an early stage, so the widest spaces
// ended up as two pairs of duplicates, defeating the point in encoding them in both a
// breaking and a non-breaking variant as supported by Donald Knuth’s TeX consistently
// with TeX’s design goal of supporting the full range of features used in traditional
// typesetting. Despite Unicode shared this goal, only the digit-wide FIGURE SPACE was
// given the non-breaking property. However, this space is designed for use as a leading
// space before numbers, for indentation, not as a group separator space, unlike claimed
// in the Core Specification 1.0. Likewise, U+2008 PUNCTUATION SPACE was intended to be
// used for decimal or group separator wide indentation before numbers. Regardless, since
// the XCCS is lacking the thin space in Character set 0xEE as documented on Wikipedia
// https://en.wikipedia.org/wiki/Xerox_Character_Code_Standard#Character_set_0xEE
// — indeed the Unicode Standard outperforms the XCCS by disambiguating SIX-PER-EM SPACE,
// THIN SPACE and PUNCTUATION SPACE, all of which the XCCS only includes the very last —
// the PUNCTUATION SPACE would as well be used as a group separator. For that purpose,
// PUNCTUATION SPACE should be non-breaking. Another reason why it should be so, is
// consistency with FIGURE SPACE. So there is multiple evidence that the originally
// intended line breaking class was GL, and only an intentionally destructive move
// away from the original design prevented PUNCTUATION SPACE and THIN SPACE from being
// non-breaking right away. That is how French and 57 other locales using space as a 
// group separator were unsupported by the Unicode Standard for almost a decade, and
// if Mongol script had been encoded back then, it would have been equally unsupported
// since it spaces punctuation marks out, much like French does, except that fonts use
// to be designed for Mongol script with built-in spacing next to punctuation characters.
//
// But even after encoding NARROW NO-BREAK SPACE, the need of non-breaking thin space in
// representing French remained unaddressed until UAX #14 Unicode Line Breaking Algorithm
// started mentioning it in 2007, and the Core Specification in 2014. Both do now declare
// U+202F NARROW NO-BREAK SPACE as representing “the space next to certain punctuation
// characters in French text.” That delay was useful to account for lagging font support.
// A competing workaround used THIN SPACE followed by then-standard line break preventer
// U+FEFF ZERO WIDTH NO-BREAK SPACE, or since 2002, U+2060 WORD JOINER. Still in practice,
// NARROW NO-BREAK SPACE was quickly adopted by the French typesetting industry because it
// caters for a longstanding demand.
//
// The Common Locale Data Repository (CLDR) has started migrating the group separator space
// from U+00A0 NO-BREAK SPACE to U+202F NARROW NO-BREAK SPACE in version 34 released in 2018.
// This migration first benefitted the French main locale fr-FR and its heirs, but not fr-CA.
// It is likely to be extended soon as per comment on 2021-03-12:
// https://unicode-org.atlassian.net/browse/CLDR-11423?focusedCommentId=160553
// https://unicode-org.atlassian.net/browse/CLDR-11217
//
// In 2019, Unicode had assigned NNBSP the Script_Extensions property value {Latn Mong}
// tending to discourage other scripts from using the correct group separator space.
//
// More information may be found in the following proposals:
// https://www.unicode.org/L2/L2019/19112-group-separator-space.pdf
// https://www.unicode.org/L2/L2019/19116-clarify-nnbsp.pdf
// https://www.unicode.org/L2/L2019/19169-nnbsp-thin-space.pdf
//
//
// ###  Punctuation spacing input methods
//
// Since computerized typewriting and typesetting have made horizontal spacing
// a question of inserting characters, both users and implementers are tempted
// to shift solid punctuation spacing out of the keyboard layout by relying on
// postprocessing or on hybrid input methods involving word processors, except
// where mapping a non-breaking space on Shift + Space is accepted to create a
// synergy with spacing-prone punctuation characters mapped on the Shift level
// and pressed almost simultaneously with the space bar.
//
// Users are divided over whether it is acceptable to input spaces separately.
// While spacing out punctuation is generally considered mandatory in French,
// doing so manually is seen as wasteful and inefficient by part of the users.
//
// These keyboard layouts support semiautomatic punctuation spacing, where the
// spaced-out punctuation characters and the unspaced-out ones are on the same
// key with different modifiers: Shift for unspaced-out, AltFr for spaced-out.
// Additionally, Shift + AltFr yields unspaced-out punctuation marks ? ! : ;.
//
// Advantages of AltFr over Shift for spaced-out punctuation characters:
//
//   1  No inadvertent insertion of NNBSP while typing unspaced punctuation;
//   2  Consistency with the key name 'AltFr' as 'Alternate French' modifier;
//   3  Shift is often considered too far left, while AltFr is better placed;
//   4  Stability of the question mark as the only unmoved big punctuation;
//   5  Minimal cross-mode user experience inconsistency, as Shift is stable;
//   6  All strings involving no-break thin space have the same modifier key;
//   7  New consistency frees up three key positions and improves the layout.
//
// Note: Points 4 and 7 are true only when ModLock is off.
//       When ModLock is on, the colon too is on its legacy position
//       next to the semicolon, moved from B08 to B10.
//
//
// ###  Synergistic vs semiautomatic punctuation spacing
//
// Spacing out certain punctuation characters is required in standard French and
// in Canadian French, where a non-breaking thin space is used with ?!; if it is
// available on the system, and certainly also with «» (and with ‹›) as inferred
// from the table below the rules on this page:
// https://vitrinelinguistique.oqlf.gouv.qc.ca/22039/la-typographie/espacement/espacement-avant-et-apres-les-signes-de-ponctuation-et-les-symboles
//
// Word processing software is catering for punctuation spacing by automatically
// inserting NBSP when a colon, a semicolon, a question mark or exclamation mark
// is typed with/without a preceding space, which in the former case is deleted,
// and by replacing U+0022 QUOTATION MARK with the appropriate, spaced-out angle
// quotation mark. But the NBSP used is not preferred, because it is justifying.
// Therefore NBSP is tailored as fixed-width as long as the text is displayed in
// the software or exported in PDF, but not after copy-pasting in a blog editor.
//
// According to mainstream demand fostered by word processing autocorrection,
// users should not be required to input more than a normal space inside eligible
// punctuation characters, ideally less. This requirement can be met in 2 ways:
//
// a. Synergistic punctuation spacing.
//    Punctuation characters and non-breaking space are mapped on the same level.
//    That can be either level 2 or level 3. Some layouts feature angle quotation
//    marks and NBSP on level 3, while double ASCII punctuation (?!:;) is mostly
//    on level 2 or even level 1, where the space bar yields breaking space
//    except on the French BÉPO layout https://bepo.fr where they are on
//    level 2 along with NNBSP on the space bar (v1.1; NBSP in v1.0).
//
// b. Semi-automatic punctuation spacing.
//    Punctuation characters are mapped with NNBSP as polygrams on single key
//    positions along with the same punctuation characters mapped in isolation
//    on the same keys on other positions. Requirements:
//
//    1. Spaced-out and unspaced punctuation has the same ease of access.
//    2. The ModLock toggle, now mapped on key E00 instead of superscript 2,
//       toggles the spaced-out punctuation character positions to unspaced.
//    3. Question and exclamation mark used in repetition, first spaced out,
//       then unspaced, require spacing inhibition by additionally holding
//       down the usual punctuation modifier: Shift in addition to AltFr.
//
// A. Advantages of synergistic over semiautomatic punctuation spacing:
//
//    1. Transparency. The knowledge about whether a punctuation mark is
//       being spaced out is intuitive: no spacebar press, no spacing.
//    3. Flexibility. The user decides in every instance whether a character
//       is spaced out or not, without significant change in gestures.
//    2. Simplicity. No multiple mapping of the same character with and without
//       semiautomatic spacing, no additional levels implied and required.
//
// https://www.inpact-hardware.com/article/1666/clavier-azerty-ldlc-notre-bilan-apres-mois-dutilisation#comment/45501
//
// B. Advantages of semiautomatic over synergistic punctuation spacing:
//
//    1. Speed: Only one single keystroke required instead of two.
//    2. Intuitivity: In French, the user focuses on punctuation, forgetting
//       about the space inside, notably not needing to remember that when
//       opening a quotation, it goes the other way around.
//    3. Continuity: Habits of letting the word processor manage punctuation
//       spacing when writing in French can be maintained.
//
// Synergistic variants started being added on 2020-02-08, and were intended
// for users writing primarily in other languages than French, and for users
// having an aversion against layouts yielding polygrams.
// They were removed on 2021-01-27.
//
//
// ###  Standard typographic number input
//
// The NARROW NO-BREAK SPACE is used mainly as a group separator, for SI/BIPM
// conformant representation of numeric values with more than 3 digits before
// the comma. That brings the need to map NNBSP and digits on the same level.
// The first possible level is level 3 (when row E has diacriticized letters)
// and the next possible level is level 5. The digits on level 3 are used for
// short numbers followed by a word, where the justifying NO-BREAK SPACE must
// be used between the number and word. The digits on level 5 are mapped both
// the traditional way on row E, and in a pad below 7 8 9 with 0 on N, and 00
// on B, for easy input of numbers grouped into triads by the group separator
// NARROW NO-BREAK SPACE, which is a no-break thin space and as such is fixed
// width. The level 5 layout is useful too for number input with interspersed
// typographic operators. These require padding, where NNBSP can be used too.
//
//
// ## Note about EURO SIGN
//
// The euro sign is attached to the preceding numeric value using NNBSP, also
// used before abbreviated measurement units. As a consequence, the euro sign
// needs to be mapped on level 5. Level 3 doesn’t have any usefulness nor any
// available key position for a duplicate mapping of the euro sign, although
// maintaining its legacy mapping and keycap engraving would be convenient.
//
// As an alternative, the Euro sign is also in group 1 of E. In group 1, with
// key rollover supported, the group selector can be used like a modifier key
// by keeping the group selector pressed while already hitting the E key.
//
//
// ##  Name and mapping of the level-5 modifier key
//
// The XKB level-5 modifier key is used in Jan James’ implementation of the
// governmental version (by federal Government and industry representatives)
// of the Canadian multilingual standard keyboard layout, initially designed
// by Alain LaBonté. Jan James worked for Windows. The group selector is like
// the level-5 modifier instead of being a dead key specified in the standard
// ISO/IEC 9995-2, that CAN/CSA Z243.200-92 complies with.
//
// The repurposed level-5 modifier is called AltFr by analogy with AltGr and
// to account for its origin on French keyboard layouts, like Microsoft also
// called the peculiar Caps Lock mappings 'SGCaps', an abbreviation standing
// for 'Swiss-German Capitals'.
//
// This level-5 modifier is repurposed and moved to the left on the “ISO key”
// B00. On ANSI keyboards with ISO compatibility, where the ISO key takes the
// place of the Right Control key, Caps Lock and ISO key are swapped, so that
// AltFr is on the Caps Lock key whereas the latter is then on Right Control.
// On plain ANSI keyboards, the AltFr key can still be remapped to Caps Lock,
// and Caps Lock to Right Control.
//
//
// ### Keyboard levels and groups
//
// While “keyboard level” refers to user-perceived modifier key combinations,
// the 1-based array indices used in the allocation tables are named “Level1”
// through “Level8” in the key type definitions. The numerous key types help
// cope with the limitation to 8 indices in XKB allocation tables. The number
// of keyboard levels in user experience may be up to 8 using three modifiers
// (Shift, AltGr, AltFr). Since the ModLock toggle is a group toggle, it does
// not require any additional indices, but Caps Lock and Control may.
//
// The term “group” should be dedicated to dead-key-accessed groups, the most
// prominent of which are accessed through the “group selector” dead key that
// also supports multiple presses. As a consequence, the group number matches
// the number of group selector key presses, at least up to 4, and the groups
// are a 0-based array of 13 groups: 0 for the default state, 1 and 2 for the
// single and double press, 3 through 9 for the group selector press followed
// by a digit 3..9, and groups 10 through 12 with digits 0..2.
//
// Given access to uppercase must be intuitive, digits are mapped on level 3.
// Caps Lock is required for uppercase. As a consequence, the digits require
// an extra toggle, that is called “ModLock”, short for Mode Lock, and it is
// implemented as a group toggle. Other non-alphabetic keys are also affected
// by ModLock, making up for what may be called a “Programmer mode”.
//

default partial alphanumeric_keys
xkb_symbols "kbfrFRs" {

	name[Group1] = "French France semiautomatic";
	name[Group2] = "French France semiautomatic";
	// "Français France semi-automatique"

	// Includes files from the symbols/ directory.
	include "pc(pc105)"   // Basic functionality.
	include "inet(evdev)" // Easy access and internet keys.

	// Correct LSGT key behavior after inclusion of symbols/pc(105)
	modifier_map Mod3 { <MDSW> };
	// See also the complete modifier map list at the bottom of this section "kbfrFRs".
	include "level5(lsgt_switch)"  // New 'AltFr' modifier key defaulting to LSGT key
	key.type[Group1]= "FOUR_LEVEL";
	key.type[Group2]= "FOUR_LEVEL";
	key <LSGT> {
		[ ISO_Level5_Shift, ISO_Level5_Shift, ISO_Level5_Shift, ISO_Level5_Shift ],
		[ ISO_Level5_Shift, ISO_Level5_Shift, ISO_Level5_Shift, ISO_Level5_Shift ]
	};
	key <MDSW> {
		[ ISO_Level5_Shift, ISO_Level5_Shift, ISO_Level5_Shift, ISO_Level5_Shift ],
		[ ISO_Level5_Shift, ISO_Level5_Shift, ISO_Level5_Shift, ISO_Level5_Shift ]
	};

	// Regular legacy AltGr key
	include "level3(ralt_switch)"
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <RALT> {
		[ ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift ],
		[ ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift ]
	};

	// New Numeric mode lock, ModLock for short
	//
	// Key TLDE becomes a Group Lock as an additional graphic toggle
	// affecting both the alphanumeric block and the numeric keypad.
	// ISO_First_Group is interpreted as: action= LockGroup(group=1)
	// ISO_Last_Group  is interpreted as: action= LockGroup(group=2)
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[           ISO_Last_Group,           ISO_Last_Group,           ISO_Last_Group,           ISO_Last_Group,                    UEFA1,                    UEFA0 ],
		[          ISO_First_Group,          ISO_First_Group,          ISO_First_Group,          ISO_First_Group,                    UEFA1,                    UEFA0 ]
	}; // Level5 yields <variant>; Level6 yields <version>

	key.type[Group1] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_SUPERSUB_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_SUPERSUB_GROUP2";
	key <AE01> {
		[                        1,              twosuperior,            threesuperior,              onesuperior,                    U2083,                    U2082,                    UEFC1,                ampersand ],
		[                        1,              twosuperior,            threesuperior,              onesuperior,                    U2081,                    U2082,                    UEFC1,                ampersand ]
	}; // U2081 ₁ SUBSCRIPT ONE; U2082 ₂ SUBSCRIPT TWO; U2083 ₃ SUBSCRIPT THREE; UEFC1  1️⃣ keycap 1 emoji

	key.type[Group1] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP2";
	key <AE02> {
		[                        2,                   eacute,                   Eacute,              twosuperior,                    U2082,                        2,                    UEFC2,                    UEFD8 ],
		[                        2,                   eacute,                   Eacute,              twosuperior,                    U2082,                        2,                    UEFC2,                    UEFD8 ]
	}; // U2082 ₂ SUBSCRIPT TWO; UEFC2  2️⃣ keycap 2 emoji; UEFD8 *dead_legacytilde

	key.type[Group1] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_GROUP2";
	key <AE03> {
		[                        3,                 quotedbl,                   endash,            threesuperior,                    U2083,                        3,                    UEFC3,               numbersign ],
		[                        3,                 quotedbl,                   endash,            threesuperior,                    U2083,                        3,                    UEFC3,               numbersign ]
	}; // U2083 ₃ SUBSCRIPT THREE; UEFC3  3️⃣ keycap 3 emoji

	key <AE04> {
		[                        4,     rightsinglequotemark,                   emdash,                    U2074,                    U2084,                        4,                    UEFC4,                braceleft ],
		[                        4,     rightsinglequotemark,                   emdash,                    U2074,                    U2084,                        4,                    UEFC4,                braceleft ]
	}; // U2074 ⁴ SUPERSCRIPT FOUR; U2084 ₄ SUBSCRIPT FOUR; UEFC4  4️⃣ keycap 4 emoji

	key <AE05> {
		[                        5,           dead_diaeresis,                    U00AD,                    U2075,                    U2085,                        5,                    UEFC5,              bracketleft ],
		[                        5,           dead_diaeresis,                    U00AD,                    U2075,                    U2085,                        5,                    UEFC5,              bracketleft ]
	}; // U00AD SOFT HYPHEN; U2075 ⁵ SUPERSCRIPT FIVE; U2085 ₅ SUBSCRIPT FIVE; UEFC5  5️⃣ keycap 5 emoji

	key <AE06> {
		[                        6,                    minus,                    U2011,                    U2076,                    U2086,                        6,                    UEFC6,                      bar ],
		[                        6,                    minus,                    U2011,                    U2076,                    U2086,                        6,                    UEFC6,                      bar ]
	}; // U2011 ‑ NON-BREAKING HYPHEN; U2076 ⁶ SUPERSCRIPT SIX; U2086 ₆ SUBSCRIPT SIX; UEFC6  6️⃣ keycap 6 emoji

	key.type[Group1] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP2";
	key <AE07> {
		[                        7,                   egrave,                   Egrave,                    U2077,                    U2087,                        7,                    UEFC7,                    UEFD9 ],
		[                        7,                   egrave,                   Egrave,                    U2077,                    U2087,                        7,                    UEFC7,                    UEFD9 ]
	}; // U2077 ⁷ SUPERSCRIPT SEVEN; U2087 ₇ SUBSCRIPT SEVEN; UEFC7  7️⃣ keycap 7 emoji; UEFD9 *dead_legacygrave

	key.type[Group1] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_GROUP2";
	key <AE08> {
		[                        8,               underscore,           Greek_horizbar,                    U2078,                    U2088,                        8,                    UEFC8,                backslash ],
		[                        8,               underscore,           Greek_horizbar,                    U2078,                    U2088,                        8,                    UEFC8,                backslash ]
	}; // Greek_horizbar ― U2015 HORIZONTAL BAR (not “Greek”); U2078 ⁸ SUPERSCRIPT EIGHT; U2088 ₈ SUBSCRIPT EIGHT; UEFC8  8️⃣ keycap 8 emoji

	key.type[Group1] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP2";
	key <AE09> {
		[                        9,                 ccedilla,                 Ccedilla,                    U2079,                    U2089,                        9,                    UEFC9,                parenleft ],
		[                        9,                 ccedilla,                 Ccedilla,                    U2079,                    U2089,                        9,                    UEFC9,                parenleft ]
	}; // U2079 ⁹ SUPERSCRIPT NINE; U2089 ₉ SUBSCRIPT NINE; UEFC9  9️⃣ keycap 9 emoji

	key.type[Group1] = "EIGHT_LEVELS_AE10_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AE10_FIRSTALPHABETIC_GROUP2";
	key <AE10> {
		[                        0,                   agrave,                   Agrave,                    U2070,                    U2080,                   U1F51F,                    UEFC0,               parenright ],
		[                        0,                   agrave,                   Agrave,                    U2070,                    U2080,                   U1F51F,                    UEFC0,               parenright ]
	}; // U2070 ⁰ SUPERSCRIPT ZERO; U2080 ₀ SUBSCRIPT ZERO; U1F51F 🔟 KEYCAP TEN emoji; UEFC0  0️⃣ keycap 0

	key.type[Group1] = "EIGHT_LEVELS_MINUS_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_MINUS_GROUP2";
	key <AE11> {
		[                       at,                   degree,                    U1D49,                    U207B,                        E,                    minus,                    UEFCA,             bracketright ],
		[                       at,                   degree,                    U208B,                    U207B,                        E,                    minus,                    UEFCA,             bracketright ]
	}; // U1D49 ᵉ superscript small e; U208B ₋ SUBSCRIPT MINUS; U207B ⁻ SUPERSCRIPT MINUS; UEFCA  *️⃣ keycap star emoji

	key.type[Group1] = "EIGHT_LEVELS_PLUS_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PLUS_GROUP2";
	key <AE12> {
		[               dead_grave,                     plus,                    U02B3,                    U207A,                        F,                    equal,                    UEFCB,               braceright ],
		[               dead_grave,                     plus,                    U208A,                    U207A,                        F,                    equal,                    UEFCB,               braceright ]
	}; // U02B3 ʳ superscript small r; U208A ₊ SUBSCRIPT PLUS; U207A ⁺ SUPERSCRIPT PLUS; UEFCB  #️⃣ keycap hash emoji

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SIX_TITLECASE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SIX_TITLECASE_GROUP2";
	key <AD01> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                        a,                        A,                    U1D43,              asciicircum,                    UEFD1,                      C_H,                      c_h,                      C_h ],
		[                        a,                        A,                    U1D43,              asciicircum,                    UEFD1,                      C_H,                      c_h,                      C_h ]
	}; // U1D43 ᵃ superscript small a; UEFD1 *dead_superscript; Breton trigraph: lowercase, titlecase, uppercase with CapsLock only on supporting systems

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP2";
	key <AD02> {
		[                        z,                        Z,                    U1DBB,                  percent,                    UEFD5,                  percent,                 permille,                  U1F627 ],
		[                        z,                        Z,                    U1DBB,                  percent,                    UEFD5,                  percent,                 permille,                  U1F627 ]
	}; // U1DBB ᶻ superscript small z; UEFD5 *dead_turned (*dead_inverted on double press); 😧 U1F627 ANGUISHED FACE emoji

	key <AD03> {
		[                        e,                        E,                    U1D49,                braceleft,                dead_hook,                 EuroSign,                    UEFAF,                   U1F601 ],
		[                        e,                        E,                    U1D49,                braceleft,                dead_hook,                 EuroSign,                    UEFAF,                   U1F601 ]
	}; // U1D49 ᵉ superscript small e; Unicode prefix U+; 😁 U1F601 GRINNING FACE WITH SMILING EYES 13th-ranking emoji

	key <AD04> {
		[                        r,                        R,                    U02B3,               braceright,                    UEFD4,                 sterling,                  radical,                   U1F914 ],
		[                        r,                        R,                    U02B3,               braceright,                    UEFD4,                 sterling,                  radical,                   U1F914 ]
	}; // U02B3 ʳ superscript small r; UEFD4 *dead_retroflexhook; √ U221A SQUARE ROOT; 🤔 U1F914 THINKING FACE 20th-ranking emoji [🤣 U1F923 ROLLING ON THE FLOOR LAUGHING fourth-most used emoji is not supported; 🙄 U1F644 FACE WITH ROLLING EYES 23rd-ranking emoji is not supported]

	key <AD05> {
		[                        t,                        T,                    U1D57,               asciitilde,               dead_tilde,                    U2212,                  figdash,                   U1F60A ],
		[                        t,                        T,                    U1D57,               asciitilde,               dead_tilde,                    U2212,                  figdash,                   U1F60A ]
	}; // U1D57 ᵗ superscript small t; U2212 − MINUS SIGN; ‒ U2012 FIGURE DASH; 😊 U1F60A SMILING FACE WITH SMILING EYES (worldwide fifth-most used emoji, fourth-most used smiling emoji in France)

	key <AD06> {
		[                        y,                        Y,                    U02B8,                       at,               dead_greek,                    U00A5,              Greek_OMEGA,                   U1F60D ],
		[                        y,                        Y,                    U02B8,                       at,               dead_greek,                    U00A5,              Greek_OMEGA,                   U1F60D ]
	}; // U02B8 ʸ superscript small y; U00A5 ¥ YEN SIGN; Ω U03A9 (preferred for Ohm sign); 😍 U1F60D SMILING FACE WITH HEART-SHAPED EYES (third-most used smiling emoji in France, third-most overall worldwide)

	key <AD07> {
		[                        u,                        U,                    U1D58,                    grave,               dead_grave,                        4,                    U2126,                   U1F64F ],
		[                        u,                        U,                    U1D58,                    grave,               dead_grave,                        4,                    U2126,                   U1F64F ]
	}; // U1D58 ᵘ superscript small u; U2126 Ω OHM SIGN (some fonts support this but no Greek); 🙏 U1F64F PERSON WITH FOLDED HANDS worldwide sixth-most used emoji

	key <AD08> {
		[                        i,                        I,                    U2071,               apostrophe,               dead_acute,                        5,                  minutes,                    UEF8C ],
		[                        i,                        I,                    U2071,               apostrophe,               dead_acute,                        5,                  minutes,                    UEF8C ]
	}; // U2071 ⁱ superscript small i; UEF8C '&apos;'

	key <AD09> {
		[                        o,                        O,                    U1D52,                 quotedbl,         dead_doubleacute,                        6,                  seconds,                    UEF8D ],
		[                        o,                        O,                    U1D52,                 quotedbl,         dead_doubleacute,                        6,                  seconds,                    UEF8D ]
	}; // U1D52 ᵒ superscript small o; UEF8D '&quot;'

	key <AD10> {
		[                        p,                        P,                    U1D56,                ampersand,            dead_abovedot,                   period,                paragraph,                    UEF8B ],
		[                        p,                        P,                    U1D56,                ampersand,            dead_abovedot,                   period,                paragraph,                    UEF8B ]
	}; // U1D56 ᵖ superscript small p; UEF8B '&amp;'

	key.type[Group1] = "EIGHT_LEVELS_AD11_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AD11_GROUP2";
	key <AD11> {
		[          dead_circumflex,                    UEF66,               dead_tilde,                    U2039,                        C,              asciicircum,           dead_diaeresis,              bracketleft ],
		[                 quotedbl,                    UEF66,               dead_tilde,                    U2039,                        C,              asciicircum,           dead_diaeresis,              bracketleft ]
	}; // UEF66 '‹ ' spaced out with NNBSP; U2039 ‹ SINGLE LEFT-POINTING ANGLE QUOTATION MARK

	key.type[Group1] = "EIGHT_LEVELS_AD12_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AD12_GROUP2";
	key <AD12> {
		[               dead_acute,                    UEF67,                Multi_key,                    U203A,                        D,                   dollar,                 sterling,             bracketright ],
		[               underscore,                    UEF67,                Multi_key,                    U203A,                        D,                   dollar,                 sterling,             bracketright ]
	}; // UEF67 ' ›' spaced out with NNBSP; U203A › SINGLE RIGHT-POINTING ANGLE QUOTATION MARK

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP2";
	key <AC01> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                        q,                        Q,                   U107A5,               numbersign,                    UEFD0,               numbersign,                   U1F610,                   U1F611 ],
		[                        q,                        Q,                   U107A5,               numbersign,                    UEFD0,               numbersign,                   U1F610,                   U1F611 ]
	}; // U107A5 𐞥 superscript small q; UEFD0 *dead_group; U1F610 😐 NEUTRAL FACE emoji; U1F611 😑 EXPRESSIONLESS FACE emoji

	key <AC02> {
		[                        s,                        S,                    U02E2,                   dollar,            dead_currency,                   dollar,                   U1F612,                   U1F614 ],
		[                        s,                        S,                    U02E2,                   dollar,            dead_currency,                   dollar,                   U1F612,                   U1F614 ]
	}; // U02E2 ˢ superscript small s; U1F612 😒 UNAMUSED FACE 3rd-top sad face emoji [2021-07-20T2206+0200]; U1F614 😔 PENSIVE FACE 4th-top sad face emoji

	key <AC03> {
		[                        d,                        D,                    U1D48,                parenleft,       dead_invertedbreve,                parenleft,                    U2300,                   U1F606 ],
		[                        d,                        D,                    U1D48,                parenleft,       dead_invertedbreve,                parenleft,                    U2300,                   U1F606 ]
	}; // U1D48 ᵈ superscript small d; U2300 ⌀ DIAMETER SIGN; U1F606 😆 SMILING FACE WITH OPEN MOUTH AND TIGHTLY-CLOSED EYES 16th-ranking emoji

	key <AC04> {
		[                        f,                        F,                    U1DA0,               parenright,               dead_breve,               parenright,                       mu,                   U1F525 ],
		[                        f,                        F,                    U1DA0,               parenright,               dead_breve,               parenright,                       mu,                   U1F525 ]
	}; // U1DA0 ᶠ superscript small f; U00B5 µ MICRO SIGN; U1F525 🔥 FIRE 15th-ranking emoji

	key <AC05> {
		[                        g,                        G,                    U1D4D,                    minus,              dead_stroke,                    minus,                   endash,                   U1F44F ],
		[                        g,                        G,                    U1D4D,                    minus,              dead_stroke,                    minus,                   endash,                   U1F44F ]
	}; // U1D4D ᵍ superscript small g; U2013 – EN DASH (Unicode-recommended for noting intervals); U1F44F 👏 CLAPPING HANDS SIGN worldwide twelvth-most used emoji

	key <AC06> {
		[                        h,                        H,                    U02B0,                     plus,                dead_horn,                     plus,                plusminus,                   U1F44D ],
		[                        h,                        H,                    U02B0,                     plus,                dead_horn,                     plus,                plusminus,                   U1F44D ]
	}; // U02B0 ʰ superscript small h; U1F44D 👍 THUMBS UP SIGN worldwide tenth-most used emoji

	key <AC07> {
		[                        j,                        J,                    U02B2,              bracketleft,              dead_ogonek,                        1,                    U27E8,                   U1F602 ],
		[                        j,                        J,                    U02B2,              bracketleft,              dead_ogonek,                        1,                    U27E8,                   U1F602 ]
	}; // U02B2 ʲ superscript small j; U27E8 ⟨ MATHEMATICAL LEFT ANGLE BRACKET; U1F602 😂 FACE WITH TEARS OF JOY worldwide most used emoji, second-most used in France after ❤ U2764

	key <AC08> {
		[                        k,                        K,                    U1D4F,             bracketright,                    UEFD3,                        2,                    U27E9,                   U1F605 ],
		[                        k,                        K,                    U1D4F,             bracketright,                    UEFD3,                        2,                    U27E9,                   U1F605 ]
	}; // U1D4F ᵏ superscript small k; UEFD3 *dead_abovehook; U27E9 ⟩ MATHEMATICAL RIGHT ANGLE BRACKET; U1F605 😅 SMILING FACE WITH OPEN MOUTH AND COLD SWEAT worldwide eleventh-most used emoji

	key <AC09> {
		[                        l,                        L,                    U02E1,               underscore,                    UEFD2,                        3,                 sterling,                    U203E ],
		[                        l,                        L,                    U02E1,               underscore,                    UEFD2,                        3,                 sterling,                    U203E ]
	}; // U02E1 ˡ superscript small l; UEFD2 *dead_subscript; U203E ‾ OVERLINE as underline in fixed-width plain text

	key <AC10> {
		[                        m,                        M,                    U1D50,                      bar,              dead_macron,                    comma,                       mu,                   U1F637 ],
		[                        m,                        M,                    U1D50,                      bar,              dead_macron,                    comma,                       mu,                   U1F637 ]
	}; // U1D50 ᵐ superscript small m; U00B5 µ MICRO SIGN; U1F637 😷 FACE WITH MEDICAL MASK emoji

	key.type[Group1] = "EIGHT_LEVELS_AC11_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AC11_GROUP2";
	key <AC11> {
		[                   ugrave,                    UEF64,                 ellipsis,            guillemotleft,                        A,                    grave,                  percent,               apostrophe ],
		[                   ugrave,                    UEF64,                 ellipsis,            guillemotleft,                        A,                    grave,                  percent,               apostrophe ]
	}; // UEF64 '« ' spaced out with NNBSP; APOSTROPHE for application shortcut mapping

	key.type[Group1] = "EIGHT_LEVELS_BKSL_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_BKSL_GROUP2";
	key <BKSL> {
		[                    UEFD0,                    UEF65,                 asterisk,           guillemotright,                        B,                    minus,                       mu,                semicolon ],
		[                    UEFD0,                    UEF65,                 asterisk,           guillemotright,                        B,                    minus,                       mu,                semicolon ]
	}; // UEFD0 *dead_group; UEF65 ' »' spaced out with NNBSP; SEMICOLON for application shortcut mapping

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP2";
	key <AB01> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                        w,                        W,                    U02B7,                    slash,  dead_longsolidusoverlay,                    slash,                   U1F622,                   U1F62D ],
		[                        w,                        W,                    U02B7,                    slash,  dead_longsolidusoverlay,                    slash,                   U1F622,                   U1F62D ]
	}; // U02B7 ʷ superscript small w; U1F622 😢 CRYING FACE 19th-ranking emoji; U1F62D 😭 LOUDLY CRYING FACE worldwide eighth-most used emoji

	key <AB02> {
		[                        x,                        X,                    U02E3,                 asterisk,           dead_abovering,                 asterisk,                    colon,                   U1F31F ],
		[                        x,                        X,                    U02E3,                 asterisk,           dead_abovering,                 asterisk,                    colon,                   U1F31F ]
	}; // U02E3 ˣ superscript small x; U1F31F 🌟 GLOWING STAR emoji

	key <AB03> {
		[                        c,                        C,                    U1D9C,                     less,          dead_circumflex,                 multiply,                    UEF8E,                   U1F631 ],
		[                        c,                        C,                    U1D9C,                     less,          dead_circumflex,                 multiply,                    UEF8E,                   U1F631 ]
	}; // U1D9C ᶜ superscript small c; UEF8E '&lt;'; U1F631 😱 FACE SCREAMING IN FEAR 2nd-top sad face emoji

	key <AB04> {
		[                        v,                        V,                    U1D5B,                  greater,               dead_caron,                 division,                    UEF8F,                   U1F496 ],
		[                        v,                        V,                    U1D5B,                  greater,               dead_caron,                 division,                    UEF8F,                   U1F496 ]
	}; // U1D5B ᵛ superscript small v; UEF8F '&gt;'; U1F496 💖	SPARKLING HEART 17th-ranking emoji

	key <AB05> {
		[                        b,                        B,                    U1D47,                    equal,                    UEFD7,                    UEF6D,                   U1F618,                   U1F495 ],
		[                        b,                        B,                    U1D47,                    equal,                    UEFD7,                    UEF6D,                   U1F618,                   U1F495 ]
	}; // U1D47 ᵇ superscript small b; UEFD7 *dead_equal regional indicator letters; UEF6D '00'; U1F618 😘 FACE THROWING A KISS sixth-most [smiling second-most] used emoji in France, ninth-most worldwide; U1F495 💕 TWO HEARTS seventh-most used emoji

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SEVEN_ALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SEVEN_ALPHABETIC_GROUP2";
	key <AB06> {
		[                        n,                        N,                    U207F,                backslash,                    UEFD6,                        0,                    UEF68,                    UEF69 ],
		[                        n,                        N,                    U207F,                backslash,                    UEFD6,                        0,                    UEF68,                    UEF69 ]
	}; // U207F ⁿ superscript small n; UEFD6 *dead_reversed; UEF68 'nᵒ ' with U1D52 and NNBSP; UEF69 'Nᵒ '

	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_ONE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_ONE_GROUP2";
	key <AB07> {
		[                    comma,                    UEF63,                 question,             dead_cedilla,                    UEF7B,               digitspace,                   U1F499,                   U1F49A ],
		[                    comma,                    UEF63,                 question,             dead_cedilla,                    UEF7B,               digitspace,                   U1F499,                   U1F49A ]
	}; // UEF63 ' ?' spaced out with NNBSP; UEF7B '&#x'; U2007   FIGURE SPACE; U1F499 💙 BLUE HEART 18th-ranking emoji; U1F49A 💚 GREEN HEART emoji

	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_TWO_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_TWO_GROUP2";
	key <AB08> {
		[                   period,                    UEF60,                   exclam,            dead_belowdot,                    UEF7A,               punctspace,                   U1F4E2,                   U1F4E3 ],
		[                   period,                    UEF60,                   exclam,            dead_belowdot,                    UEF7A,               punctspace,                   U1F4E2,                   U1F4E3 ]
	}; // UEF60 ' !' spaced out with NNBSP; UEF7A '&#'; U2008   PUNCTUATION SPACE; U1F4E2 📢 PUBLIC ADDRESS LOUDSPEAKER emoji; U1F4E3 📣 CHEERING MEGAPHONE emoji

	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_THREE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_THREE_GROUP2";
	key <AB09> {
		[                    slash,                    UEF61,                    colon,           dead_diaeresis,                    slash,                    U2044,                   U1F615,                   U1F603 ],
		[                    slash,                    UEF61,                    colon,           dead_diaeresis,                    slash,                    U2044,                   U1F615,                   U1F603 ]
	}; // UEF61 ' :' spaced out with NNBSP; U2044 ⁄ FRACTION SLASH; U1F615 😕 CONFUSED FACE emoji; U1F603 😃 SMILING FACE WITH OPEN MOUTH emoji

	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_FOUR_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_FOUR_GROUP2";
	key <AB10> {
		[                backslash,                    UEF62,                semicolon,          dead_belowcomma,                backslash,                  section,                   U1F494,                   U1F609 ],
		[                backslash,                    UEF62,                semicolon,          dead_belowcomma,                backslash,                  section,                   U1F494,                   U1F609 ]
	}; // UEF62 ' ;' spaced out with NNBSP; U1F494 💔 BROKEN HEART 16th-ranking emoji; U1F609 😉 WINKING FACE 24th-ranking emoji

	// Index:                  1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
	key.type[Group1] = "EIGHT_LEVELS_SPACEBAR_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_SPACEBAR_GROUP2";
	key <SPCE> {
		[                    space,             nobreakspace,                    U202F,                    U200B,                    UEF6E,                    UEF6F,                    UEF9B,                    UEF9F ],
		[                    space,             nobreakspace,                    U202F,                    U200B,                    UEF6E,                    UEF6F,                    UEF9B,                    UEF9F ]
	}; // U202F   NARROW NO-BREAK SPACE; U200B ​ ZERO WIDTH SPACE; UEF6E U0020 U2060 ' ⁠' justifying non-breaking space using WORD JOINER; UEF6F U0020 UFEFF ' ﻿' justifying non-breaking space using ZERO WIDTH NO-BREAK SPACE; UEF9B '&nbsp;'; UEF9F '&#x202F;' NNBSP
	// The actual mapping of the spacebar is defined in xkb/types/dispotypes like for all other keys. Please refer to that file, since the 8 columns here are indices, not levels.

	//
	// Numeric keypad (numpad)
	//
	// The cursor key feature on the numpad is deactivated as outdated, redundant, and wasting positions.
	//
	// For this to work on an overlay numpad with Fn held down, the AltFr modifier must be pressed before the Fn key.
	//
	key.type[Group1]= "ONE_LEVEL";
	key.type[Group2]= "ONE_LEVEL";
	key <KPEQ> {
		[                 KP_Equal ],
		[                 KP_Equal ]
	};

	// Index:                             1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_OPERATOR_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_OPERATOR_GROUP2";
	key <KPDV> {
		[                KP_Divide,                 division,                  radical,                parenleft,                KP_Divide,                parenleft,              bracketleft,                    U2044 ],
		[                KP_Divide,                 division,                  radical,                parenleft,                KP_Divide,                parenleft,              bracketleft,                    U2044 ]
	}; // U2044 ⁄ FRACTION SLASH

	key <KPMU> {
		[              KP_Multiply,                 multiply,              asciicircum,               parenright,              KP_Multiply,               parenright,             bracketright,                 NoSymbol ],
		[              KP_Multiply,                 multiply,              asciicircum,               parenright,              KP_Multiply,               parenright,             bracketright,                 NoSymbol ]
	};

	key <KPSU> {
		[              KP_Subtract,                    U2212,                    equal,                    U2243,              KP_Subtract,              asciicircum,               numbersign,                 NoSymbol ],
		[              KP_Subtract,                    U2212,                    equal,                    U2243,              KP_Subtract,              asciicircum,               numbersign,                 NoSymbol ]
	}; // U2212 − MINUS SIGN; U2243 ≃ ASYMPTOTICALLY EQUAL

	key <KPAD> {
		[                   KP_Add,                     plus,                plusminus,                    U2248,                   KP_Add,               braceright,                    equal,                 NoSymbol ],
		[                   KP_Add,                     plus,                plusminus,                    U2248,                   KP_Add,               braceright,                    equal,                 NoSymbol ]
	}; // U2248 ≈ ALMOST EQUAL

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DECIMAL_SEPARATOR_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DECIMAL_SEPARATOR_GROUP2";
	key <KPDL> {
		[               KP_Decimal,                    comma,                    U202F,             nobreakspace,               KP_Decimal,                    comma,                    space,             nobreakspace ],
		[               KP_Decimal,                    comma,                    U202F,             nobreakspace,               KP_Decimal,                    comma,                    space,             nobreakspace ]
	}; // U202F   NARROW NO-BREAK SPACE

	key <KPPT> {
		[               KP_Decimal,                    comma,                    U202F,             nobreakspace,               KP_Decimal,                    comma,                    space,             nobreakspace ],
		[               KP_Decimal,                    comma,                    U202F,             nobreakspace,               KP_Decimal,                    comma,                    space,             nobreakspace ]
	}; // U202F   NARROW NO-BREAK SPACE

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP2";
	key <KP0>  {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		// Category or state:                    ModLock off,               ModLock on, single arrows (emoji pp),    double (white) arrows,  black arrows (emoji pp),   triangle-headed arrows,     white (empty) arrows
		[                     KP_0,                    UEF6D,                    UEF6D,                    U2195,                    U21D5,                    U2B0D,                    U2B65,                    U21F3 ],
		[                     KP_0,                    UEF6D,                    UEF6D,                    U2195,                    U21D5,                    U2B0D,                    U2B65,                    U21F3 ]
	}; // UEF6D '00'; UEF6D '00'; ↕; ⇕; ⬍; ⭥; ⇳

	key <KP1>  {
		[                     KP_1,                    UEF7D,                    UEF7C,                    U2199,                    U21D9,                    U2B0B,                    U2B69,                    U2B03 ],
		[                     KP_1,                    UEF7D,                    UEF7C,                    U2199,                    U21D9,                    U2B0B,                    U2B69,                    U2B03 ]
	}; // UEF7D '000'; UEF7C '0x'; ↙; ⇙; ⬋; ⭩; ⬃

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP2";
	key <KP2>  {
		[                     KP_2,                        A,                        a,                    U2193,                    U21D3,                    U2B07,                    U2B63,                    U21E9 ],
		[                     KP_2,                        A,                        a,                    U2193,                    U21D3,                    U2B07,                    U2B63,                    U21E9 ]
	}; // ↓; ⇓; ⬇; ⭣; ⇩

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP2";
	key <KP3>  {
		[                     KP_3,                        B,                        b,                    U2198,                    U21D8,                    U2B0A,                    U2B68,                    U2B02 ],
		[                     KP_3,                        B,                        b,                    U2198,                    U21D8,                    U2B0A,                    U2B68,                    U2B02 ]
	}; // ↘; ⇘; ⬊; ⭨; ⬂

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP2";
	key <KP4>  {
		[                     KP_4,                        U,                    UEF7E,                    U2190,                    U21D0,                    U2B05,                    U2B60,                    U21E6 ],
		[                     KP_4,                        U,                    UEF7E,                    U2190,                    U21D0,                    U2B05,                    U2B60,                    U21E6 ]
	}; // Unicode; '\u{'; ←; ⇐; ⬅; ⭠; ⇦

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP2";
	key <KP5>  {
		[                     KP_5,                        C,                        c,                    U2194,                    U21D4,                    U2B0C,                    U2B64,                    U2B04 ],
		[                     KP_5,                        C,                        c,                    U2194,                    U21D4,                    U2B0C,                    U2B64,                    U2B04 ]
	}; // ↔; ⇔; ⬌; ⭤; ⬄

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP2";
	key <KP6>  {
		[                     KP_6,                        D,                        d,                    U2192,                    U21D2,                    U27A1,                    U2B62,                    U21E8 ],
		[                     KP_6,                        D,                        d,                    U2192,                    U21D2,                    U27A1,                    U2B62,                    U21E8 ]
	}; // →; ⇒; ➡; ⭢; ⇨

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP2";
	key <KP7>  {
		[                     KP_7,                    U202F,                    UEF7F,                    U2196,                    U21D6,                    U2B09,                    U2B66,                    U2B01 ],
		[                     KP_7,                    U202F,                    UEF7F,                    U2196,                    U21D6,                    U2B09,                    U2B66,                    U2B01 ]
	}; // NNBSP; '\x{'; ↖; ⇖; ⬉; ⭦; ⬁

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP2";
	key <KP8>  {
		[                     KP_8,                        E,                        e,                    U2191,                    U21D1,                    U2B06,                    U2B61,                    U21E7 ],
		[                     KP_8,                        E,                        e,                    U2191,                    U21D1,                    U2B06,                    U2B61,                    U21E7 ]
	}; // ↑; ⇑; ⬆; ⭡; ⇧

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP2";
	key <KP9>  {
		[                     KP_9,                        F,                        f,                    U2197,                    U21D7,                    U2B08,                    U2B67,                    U2B00 ],
		[                     KP_9,                        F,                        f,                    U2197,                    U21D7,                    U2B08,                    U2B67,                    U2B00 ]
	}; // ↗; ⇗; ⬈; ⭧; ⬀

	// Edit keys. Inverted T: Here, the index numbers are consistent with UX levels.
	key.type[Group1] = "EIGHT_LEVELS_EDIT_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_EDIT_GROUP2";
	key <UP>   {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		//                                                                black arrows,             white arrows,         preferred arrows,            legacy arrows,
		[                       Up,                 NoSymbol,                    U2B06,                    U21E7,                    U2B61,                    U2191,                 NoSymbol,                 NoSymbol ],
		[                       Up,                 NoSymbol,                    U2B06,                    U21E7,                    U2B61,                    U2191,                 NoSymbol,                 NoSymbol ]
	}; // ⬆; ⇧; ⭡; ↑

	key <LEFT> {
		[                     Left,                 NoSymbol,                    U2B05,                    U21E6,                    U2B60,                    U2190,                 NoSymbol,                 NoSymbol ],
		[                     Left,                 NoSymbol,                    U2B05,                    U21E6,                    U2B60,                    U2190,                 NoSymbol,                 NoSymbol ]
	}; // ⬅; ⇦; ⭠; ←

	key <DOWN> {
		[                     Down,                 NoSymbol,                    U2B07,                    U21E9,                    U2B63,                    U2193,                 NoSymbol,                 NoSymbol ],
		[                     Down,                 NoSymbol,                    U2B07,                    U21E9,                    U2B63,                    U2193,                 NoSymbol,                 NoSymbol ]
	}; // ⬇; ⇩; ⭣; ↓

	key <RGHT> {
		[                    Right,                 NoSymbol,                    U27A1,                    U21E8,                    U2B62,                    U2192,                 NoSymbol,                 NoSymbol ],
		[                    Right,                 NoSymbol,                    U27A1,                    U21E8,                    U2B62,                    U2192,                 NoSymbol,                 NoSymbol ]
	}; // ➡; ⇨; ⭢; →

	// Six-key cluster:
	key <INS>  {
		//                                                           preferred symbols,            other symbols,   preferred alternatives,      legacy alternatives,
		[                   Insert,                 NoSymbol,                    U2380,                    U2038,                    U2380,                    U2041,                 NoSymbol,                 NoSymbol ],
		[                   Insert,                 NoSymbol,                    U2380,                    U2038,                    U2380,                    U2041,                 NoSymbol,                 NoSymbol ]
	}; // ⎀; ‸; ⎀; ⁁

	key <DELE> {
		[                   Delete,                 NoSymbol,                    U2326,                    U2425,                    U239A,                    U2327,                 NoSymbol,                 NoSymbol ],
		[                   Delete,                 NoSymbol,                    U2326,                    U2425,                    U239A,                    U2327,                 NoSymbol,                 NoSymbol ]
	}; // ⌦; ␥; ⎚; ⌧

	key <HOME> {
		[                     Home,                 NoSymbol,                    U21F1,                    U21B8,                    U2912,                    U2B76,                 NoSymbol,                 NoSymbol ],
		[                     Home,                 NoSymbol,                    U21F1,                    U21B8,                    U2912,                    U2B76,                 NoSymbol,                 NoSymbol ]
	}; // ⇱; ↸; ⤒; ⭶

	key <END>  {
		[                      End,                 NoSymbol,                    U21F2,                    U2B78,                    U2913,                    U2B78,                 NoSymbol,                 NoSymbol ],
		[                      End,                 NoSymbol,                    U21F2,                    U2B78,                    U2913,                    U2B78,                 NoSymbol,                 NoSymbol ]
	}; // ⇲; ⭸; ⤓; ⭸

	key <PGUP> {
		[                    Prior,                 NoSymbol,                    U21DE,                    U2397,                    U2B7B,                    U25B3,                 NoSymbol,                 NoSymbol ],
		[                    Prior,                 NoSymbol,                    U21DE,                    U2397,                    U2B7B,                    U25B3,                 NoSymbol,                 NoSymbol ]
	}; // ⭻; ⇞; ⎗; △

	key <PGDN> {
		[                     Next,                 NoSymbol,                    U21DF,                    U2398,                    U2B7D,                    U25BD,                 NoSymbol,                 NoSymbol ],
		[                     Next,                 NoSymbol,                    U21DF,                    U2398,                    U2B7D,                    U25BD,                 NoSymbol,                 NoSymbol ]
	}; // ⭽; ⇟; ⎘; ▽
	//                         1,                        2,                        3,                        4,                        5,                        6,                        7,                        8

	// Modifier maps:
	modifier_map Control { <LCTL> };
	modifier_map Mod2    { <NMLK> };
	modifier_map Shift   { <LFSH> };
	modifier_map Shift   { <RTSH> };
	modifier_map Mod1    { <LALT> };
	modifier_map Lock    { <CAPS> };
	modifier_map Mod5    { <LVL3> }; // Mod5 is ISO_Level3_Shift
	modifier_map Control { <RCTL> };
	modifier_map Mod4    { <LWIN> };
	modifier_map Mod4    { <RWIN> };
	modifier_map Mod3    { <MDSW> }; // Mod3 is ISO_Level5_Shift
	modifier_map Mod1    { <META> };
	modifier_map Mod4    { <SUPR> };
	modifier_map Mod4    { <HYPR> };

};

partial alphanumeric_keys
xkb_symbols "kbbrFRs" {

	name[Group1] = "Breton and French semiautomatic";
	name[Group2] = "Breton and French semiautomatic";
	// "Breton et français semi-automatique"

	include "dispocla(kbfrFRs)"

	key.type[Group1] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_SUPERSUB_FIRSTALPHABETIC_TITLECASE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_SUPERSUB_FIRSTALPHABETIC_TITLECASE_GROUP2";
	key <AE01> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                 NoSymbol,                      c_h,                      C_h,                      C_H ],
		[                 NoSymbol,                      c_h,                      C_h,                      C_H ]
	}; // cʼh, Cʼh, CʼH

	key.type[Group1] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP2";
	key <AE08> {
		[                 NoSymbol,                    U00F1,                    U00D1 ],
		[                 NoSymbol,                    U00F1,                    U00D1 ]
	}; // ñ, Ñ

	// Variant name:
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFA2 ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFA2 ]
	};

};

partial alphanumeric_keys
xkb_symbols "kbfrPFs" {

	name[Group1] = "French Polynesia semiautomatic";
	name[Group2] = "French Polynesia semiautomatic";
	// "Polynésie française semi-automatique"

	include "dispocla(kbfrFRs)"

	key.type[Group1] = "EIGHT_LEVELS_PLUS_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PLUS_GROUP2";
	key <AE12> {
		[              dead_macron ],
		[              dead_macron ]
	};// Used in Polynesian.

	key.type[Group1] = "EIGHT_LEVELS_AD11_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AD11_GROUP2";
	key <AD11> {
		[                 NoSymbol,                 NoSymbol,               dead_grave ],
		[                 NoSymbol,                 NoSymbol,               dead_grave ]
	};// Used in Polynesian.

	// Variant name:
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFA3 ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFA3 ]
	};

};

partial alphanumeric_keys
xkb_symbols "kbfrAFs" {

	name[Group1] = "Francophone Africa semiautomatic";
	name[Group2] = "Francophone Africa semiautomatic";
	// "Afrique francophone semi-automatique"

	include "dispocla(kbfrFRs)"

	key.type[Group1] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_SUPERSUB_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_SUPERSUB_FIRSTALPHABETIC_GROUP2";
	key <AE01> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                 NoSymbol,                    U025B,                    U0190 ],
		[                 NoSymbol,                    U025B,                    U0190 ]
	}; // ɛ, Ɛ

	key.type[Group1] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP2";
	key <AE08> {
		[                 NoSymbol,                    U0254,                    U0186 ],
		[                 NoSymbol,                    U0254,                    U0186 ]
	}; // ɔ, Ɔ

	// Variant name:
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFA4 ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFA4 ]
	};

};

partial alphanumeric_keys
xkb_symbols "kbfrBEs" {

	name[Group1] = "French Belgium semiautomatic";
	name[Group2] = "French Belgium semiautomatic";
	// "Français Belgique semi-automatique"
	//
	// The other divergent keys are equalized with France’s AZERTY because
	// the downside of keeping them the Belgian way is detrimental to consistency
	// and would heavily impact user experience far beyond the small benefit of
	// staying a bit more familiar.

	include "dispocla(kbfrFRs)"

	key.type[Group1] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_GROUP2";
	key <AE06> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                 NoSymbol,                  section ],
		[                 NoSymbol,                  section ]
	};// Leave NON-BREAKING HYPHEN here. Greek_horizbar is in group 1 of en and em dashes.

	key <AE08> {
		[                 NoSymbol,                    minus,               underscore ],
		[                 NoSymbol,                    minus,               underscore ]
	};// Rather than NON-BREAKING HYPHEN.

	// Variant name:
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFA5 ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFA5 ]
	};

};

partial alphanumeric_keys
xkb_symbols "kbfrCAs" {

	name[Group1] = "French Canada semiautomatic";
	name[Group2] = "French Canada semiautomatic";
	// "Français Canada semi-automatique"
	//
	// CAUTION: This partial is outdated and is maintained only to document that
	//          there is an ongoing effort to optimally support Canadian French.
	//
	// This is based on the French (Canada) keyboard layout widely used on Linux and on Windows.
	// The reference layout is shipped with Linux in symbols/ca(fr).
	//
	// Due to competing new requirements related to the support of Canadian French language’s
	// interoperable digital representation, only part of the features of the French (Canada)
	// layout could be maintained.

	include "dispocla(kbfrFRs)"

	key.type[Group1] = "EIGHT_LEVELS_DIGIT_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_DIGIT_GROUP2";
	key <AE01> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                 NoSymbol,                    UEF60,                   exclam ],
		[                 NoSymbol,                    UEF60,                   exclam ]
	}; // EXCLAMATION MARK preceded by NNBSP

	key <AE02> {
		[                 NoSymbol,                   endash,                 quotedbl ],
		[                 NoSymbol,                   endash,                 quotedbl ]
	}; // Other indices included from kbfrFRs

	key <AE03> {
		[                 NoSymbol,           Greek_horizbar,                    U2010 ],
		[                 NoSymbol,           Greek_horizbar,                    U2010 ]
	}; // HYPHEN (NOT soft hyphen)

	key <AE04> {
		[                 NoSymbol,                   emdash,                    U00AD ],
		[                 NoSymbol,                   emdash,                    U00AD ]
	}; // SOFT HYPHEN (SHY) (keysym <hyphen>)

	key <AE05> {
		[                 NoSymbol,                  figdash,                    U2011 ],
		[                 NoSymbol,                  figdash,                    U2011 ]
	}; // NON-BREAKING HYPHEN

	key <AE06> {
		[                 NoSymbol,                    UEF63,                 question ],
		[                 NoSymbol,                    UEF63,                 question ]
	}; // QUESTION MARK preceded by NNBSP

	key <AE07> {
		[                 NoSymbol,                    UEF66,                    U2039 ],
		[                 NoSymbol,                    UEF66,                    U2039 ]
	}; // LEFT-POINTING SINGLE ANGLE QUOTATION MARK (W/ and w/o NNBSP)

	key <AE08> {
		[                 NoSymbol,                    UEF67,                    U203A ],
		[                 NoSymbol,                    UEF67,                    U203A ]
	}; // RIGHT-POINTING SINGLE ANGLE QUOTATION MARK (W/ and w/o NNBSP)

	key <AE09> {
		[                 NoSymbol,                    UEF64,            guillemotleft ],
		[                 NoSymbol,                    UEF64,            guillemotleft ]
	};

	key.type[Group1] = "EIGHT_LEVELS_AE10_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AE10_GROUP2";
	key <AE10> {
		[                 NoSymbol,                    UEF65,           guillemotright ],
		[                 NoSymbol,                    UEF65,           guillemotright ]
	}; // COMBINING ENCLOSING KEYCAP; KEYCAP TEN

	key.type[Group1] = "EIGHT_LEVELS_MINUS_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_MINUS_GROUP2";
	key <AE11> {
		[                    minus,                 NoSymbol,                 NoSymbol,                    minus ],
		[                    minus,                 NoSymbol,                 NoSymbol,                    minus ]
	}; // Other indices included from kbfrFRs

	key.type[Group1] = "EIGHT_LEVELS_PLUS_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PLUS_GROUP2";
	key <AE12> {
		[                 quotedbl ],
		[                 quotedbl ]
	};

	key.type[Group1] = "EIGHT_LEVELS_SEMIALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_SEMIALPHABETIC_GROUP2";
	key <AD01> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                        q,                        Q,               numbersign,                    UEFD7,                    UEF68,                    UEF69,               numbersign,               numerosign ],
		[                        q,                        Q,               numbersign,                    UEFD7,                    UEF68,                    UEF69,               numbersign,               numerosign ]
	}; // *dead_equal regional indicator letters; 'nᵒ '; 'Nᵒ ' (with NNBSP); '#' (duplicate for ease of access when AltFr is down); U2116 NUMERO SIGN

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP2";
	key <AD02> {
		[                        w,                        W,                    equal,               dead_greek,                    UEF6D,                    U02B7,                    U2126,                    U2550 ],
		[                        w,                        W,                    equal,               dead_greek,                    UEF6D,                    U02B7,                    U2126,                    U2550 ]
	}; // '00'; superscript small w; OHM SIGN; BOX DRAWINGS DOUBLE HORIZONTAL

	// 8 keys included from kbfrFRs
	key.type[Group1] = "EIGHT_LEVELS_AD11_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AD11_GROUP2";
	key <AD11> {
		[                 NoSymbol,                 NoSymbol,           dead_diaeresis,                 NoSymbol,                 NoSymbol,                 quotedbl ],
		[                 NoSymbol,                 NoSymbol,           dead_diaeresis,                 NoSymbol,                 NoSymbol,                 quotedbl ]
	};

	key.type[Group1] = "EIGHT_LEVELS_AD12_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AD12_GROUP2";
	key <AD12> {
		[             dead_cedilla ],
		[             dead_cedilla ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP2";
	key <AC01> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                        a,                        A,                       at,                    U25CC,                  section,                    U1D43,                    U00AA,       enfilledcircbullet ],
		[                        a,                        A,                       at,                    U25CC,                  section,                    U1D43,                    U00AA,       enfilledcircbullet ]
	}; // DOTTED CIRCLE; superscript small a; U00A7 SECTION SIGN; FEMININE ORDINAL INDICATOR (ordfeminine); U2022 BULLET

	// 8 keys included from kbfrFRs
	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_CA_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_CA_GROUP2";
	key <AC10> {
		[     rightsinglequotemark,                    UEF71,                 ellipsis,                    U02BC,                 NoSymbol,                    U2044,                    colon,                semicolon ],
		[     rightsinglequotemark,                    UEF71,                 ellipsis,                    U02BC,                 NoSymbol,                    U2044,                    colon,                semicolon ]
	}; // spaced colon with NBSP for Canadian old school French additionally to new school on B08; FRACTION SLASH

	key.type[Group1] = "EIGHT_LEVELS_AC11_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AC11_GROUP2";
	key <AC11> {
		[               dead_grave,                 NoSymbol,           periodcentered,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 quotedbl ],
		[               dead_grave,                 NoSymbol,           periodcentered,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 quotedbl ]
	};

	key.type[Group1] = "EIGHT_LEVELS_BKSL_CA_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_BKSL_CA_GROUP2";
	key <BKSL> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                      bar,                       mu,                backslash ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                      bar,                       mu,                backslash ]
	}; // group selector dead key; double angle quote with NNBSP and unspaced; U00B5 MICRO SIGN

	// Index:                             1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SIX_TITLECASE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SIX_TITLECASE_GROUP2";
	key <AB01> {
		[                        z,                        Z,                  percent,                      C_H,                  percent,                    U1DBB,                      c_h,                      C_h ],
		[                        z,                        Z,                  percent,                      C_H,                  percent,                    U1DBB,                      c_h,                      C_h ]
	}; // Breton trigraph; superscript small z

	// 6 keys included from kbfrFRs
	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP2";
	key <AB07> {
		[                        m,                        M,                      bar,              dead_macron,                    colon,                    U1D50,                   endash,                    U2014 ],
		[                        m,                        M,                      bar,              dead_macron,                    colon,                    U1D50,                   endash,                    U2014 ]
	}; // superscript small m; U2013 EN DASH (Unicode-recommended for noting intervals); EM DASH

	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_ONE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_ONE_GROUP2";
	key <AB08> {
		[                    comma,                    UEF62,                semicolon,             dead_cedilla,                    comma,                 question,               digitspace,                    U2753 ],
		[                    comma,                    UEF62,                semicolon,             dead_cedilla,                    comma,                 question,               digitspace,                    U2753 ]
	}; // spaced question mark; dead_abovehook; U2007 FIGURE SPACE; BLACK QUESTION MARK ORNAMENT

	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_TWO_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_TWO_GROUP2";
	key <AB09> {
		[                   period,                    UEF61,                    colon,            dead_belowdot,                   period,                   exclam,               punctspace,                    U26A0 ],
		[                   period,                    UEF61,                    colon,            dead_belowdot,                   period,                   exclam,               punctspace,                    U26A0 ]
	}; // spaced semicolon; U2008 PUNCTUATION SPACE; WARNING SIGN

	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_FIRSTALPHABETIC_GROUP2";
	key <AB10> {
		[                   eacute,                   Eacute,               dead_acute,          dead_belowcomma,                semicolon,                      bar,                backslash,                    slash ],
		[                   eacute,                   Eacute,               dead_acute,          dead_belowcomma,                semicolon,                      bar,                backslash,                    slash ]
	}; // spaced exclamation mark; U00A7 SECTION SIGN; U00B6 PILCROW SIGN

	// <SPCE>, numpad and edit keys included from kbfrFRs
	// Variant name:
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFA7 ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFA7 ]
	};

};

partial alphanumeric_keys
xkb_symbols "kbfrCAms" {

	name[Group1] = "Canadian Multilingual semiautomatic";
	name[Group2] = "Canadian Multilingual semiautomatic";
	// "Canadien multilingue semi-automatique"
	//
	// CAUTION: This partial is outdated and is maintained only to document that
	//          there is an ongoing effort to optimally support Canadian French.
	//
	// The design of this layout is based on Alain LaBonté’s Canadian Multilingual Standard keyboard,
	// also called Clavier Québecois, CAN/CSA Z243.200-92, shipped with Linux: symbols/ca(multix)
	//
	// Due to competing new requirements related to the support of Canadian French language’s
	// interoperable digital representation, only part of the features of the Canadian Multilingual
	// Standard keyboard layout could be maintained.

	include "dispocla(kbfrCAs)"

	// 11 keys included from kbfrCAs
	key.type[Group1] = "EIGHT_LEVELS_PLUS_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PLUS_FIRSTALPHABETIC_GROUP2";
	key <AE12> {
		[                   ugrave,                   Ugrave ],
		[                   ugrave,                   Ugrave ]
	};

	// 10 keys included from kbfrCAs
	key.type[Group1] = "EIGHT_LEVELS_AD11_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AD11_GROUP2";
	key <AD11> {
		[          dead_circumflex,           dead_diaeresis ],
		[          dead_circumflex,           dead_diaeresis ]
	};

	key.type[Group1] = "EIGHT_LEVELS_AD12_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AD12_FIRSTALPHABETIC_GROUP2";
	key <AD12> {
		[                 ccedilla,                 Ccedilla ],
		[                 ccedilla,                 Ccedilla ]
	};

	// 10 keys included from kbfrCAs
	key.type[Group1] = "EIGHT_LEVELS_AC11_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AC11_FIRSTALPHABETIC_GROUP2";
	key <AC11> {
		[                   egrave,                   Egrave ],
		[                   egrave,                   Egrave ]
	};

	key.type[Group1] = "EIGHT_LEVELS_BKSL_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_BKSL_FIRSTALPHABETIC_GROUP2";
	key <BKSL> {
		[                   agrave,                   Agrave ],
		[                   agrave,                   Agrave ]
	};

	// rest included from kbfrCAs
	// Variant name:
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFA6 ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFA6 ]
	};

};

partial alphanumeric_keys
xkb_symbols "kbfrCHs" {

	name[Group1] = "French Switzerland semiautomatic";
	name[Group2] = "French Switzerland semiautomatic";
	// "Français Suisse semi-automatique"
	//
	// CAUTION: This partial is outdated and is maintained only to document that
	//          there is an ongoing effort to optimally support Swiss French.
	//
	// Since 2015, Swiss French uses fully diacriticized titlecase, hence German umlauts
	// are accessed only with the diaeresis dead key, so as to make room for French
	// diacriticized uppercase letters. C with cedilla is moved to E12 in default mode.
	// Also punctuation marks are now spaced out, exactly like in fr_FR.
	// The Canadian multilingual layout is the starting point.

	include "dispocla(kbfrCAms)"

	key.type[Group1] = "EIGHT_LEVELS_MINUS_CH_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_MINUS_CH_GROUP2";
	key <AE11> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[     rightsinglequotemark,                 question,                   degree,               apostrophe ],
		[     rightsinglequotemark,                 question,                   degree,               apostrophe ]
	};

	key.type[Group1] = "EIGHT_LEVELS_PLUS_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PLUS_FIRSTALPHABETIC_GROUP2";
	key <AE12> {
		[                 ccedilla,                 Ccedilla ],
		[                 ccedilla,                 Ccedilla ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SIX_TITLECASE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SIX_TITLECASE_GROUP2";
	key <AD06> {
		[                        z,                        Z,               apostrophe,                      C_H,                  percent,                    U1DBB,                      c_h,                      C_h ],
		[                        z,                        Z,               apostrophe,                      C_H,                  percent,                    U1DBB,                      c_h,                      C_h ]
	}; // Breton trigraph; superscript small z

	key.type[Group1] = "EIGHT_LEVELS_AD11_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AD11_FIRSTALPHABETIC_GROUP2";
	key <AD11> {
		[                   egrave,                   Egrave ],
		[                   egrave,                   Egrave ]
	};

	key.type[Group1] = "EIGHT_LEVELS_AD12_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AD12_GROUP2";
	key <AD12> {
		[           dead_diaeresis,                   exclam,                 NoSymbol,                 NoSymbol,                 NoSymbol,                backslash ],
		[           dead_diaeresis,                   exclam,                 NoSymbol,                 NoSymbol,                 NoSymbol,                backslash ]
	};

	key.type[Group1] = "EIGHT_LEVELS_AC11_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AC11_FIRSTALPHABETIC_GROUP2";
	key <AC10> {
		[                   eacute,                   Eacute ],
		[                   eacute,                   Eacute ]
	};

	key <AC11> {
		[                   agrave,                   Agrave ],
		[                   agrave,                   Agrave ]
	};

	key.type[Group1] = "EIGHT_LEVELS_BKSL_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_BKSL_GROUP2";
	key <BKSL> {
		[          dead_circumflex,                 question,                 NoSymbol,                 NoSymbol,                 NoSymbol,                   dollar ],
		[          dead_circumflex,                 question,                 NoSymbol,                 NoSymbol,                 NoSymbol,                   dollar ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP2";
	key <AB01> {
		[                        y,                        Y,                  percent,               dead_acute,               numbersign,                    U02B8,                      yen,                    U200C ],
		[                        y,                        Y,                  percent,               dead_acute,               numbersign,                    U02B8,                      yen,                    U200C ]
	}; // superscript small y; duplicate # for ease of access when AltFr is down; ¥ instead of '&apos;' (not needed); ZERO WIDTH NON-JOINER (for mnemonics; easier on B10)

	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_THREE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_THREE_GROUP2";
	key <AB10> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                    minus,               underscore ],
		[                    minus,               underscore ]
	};

	// Variant name:
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFA8 ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFA8 ]
	};

};

//
// ##  Layouts with some characters (mainly letters) remapped for a better typing experience
//
// These 4 layouts are designed for users interested both in alphabetic ergonomics and in
// support for spacing out guillemets, i.e. both double and single angle quotation marks.
//
// The remapped layout comes with variants featuring unremapped shortcuts in
// the Control layers, either in AZERTY, QWERTY or QWERTZ
//

partial alphanumeric_keys
xkb_symbols "kbfrFRr" {
// As the code name max length is 8 for portability, the ‘s’ is skipped for consistency.

	name[Group1] = "French remapped semiautomatic";
	name[Group2] = "French remapped semiautomatic";
	// "Français redisposé semi-automatique"

	include "dispocla(kbfrFRs)"

	// I and O are switched alongside D and L to improve the -élé- trigram, and
	// because 5.754 words contain 'ion', in official French;
	// 121 words contain 'noi', in official French (total: 5.875)
	// 280 words contain 'oin', in official French (total: 6.155)
	// 110 words contain 'nio', in official French (total: 6.265)
	// Courtesy La Fée des Lettres https://www.motsavec.com/

	// Alphanumeric block
	// Key <AE01> is included from kbfrFRs.
	key.type[Group1] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP2";
	key <AE02> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                 NoSymbol,                   agrave,                   Agrave ],
		[                 NoSymbol,                   agrave,                   Agrave ]
	}; // Levels 4..8 are included from kbfrFRs.

	key.type[Group1] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_GROUP2";
	// Key <AE03> is included from kbfrFRs.
	key <AE04> {
		[                 NoSymbol,               dead_acute ],
		[                 NoSymbol,               dead_acute ]
	}; // Levels 2..8 are included from kbfrFRs.

	// Key <AE05> is included from kbfrFRs.
	key.type[Group1] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP2";
	key <AE06> {
		[                 NoSymbol,                   ugrave,                   Ugrave ],
		[                 NoSymbol,                   ugrave,                   Ugrave ]
	}; // Ugrave for consistency since U2011 is on E07 for accessibility while underscore is on D12 when ModLock is on.

	key.type[Group1] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_GROUP2";
	key <AE07> {
		[                 NoSymbol,                    U2011,           Greek_horizbar ],
		[                 NoSymbol,                    U2011,           Greek_horizbar ]
	}; // Levels 4..8 are included from kbfrFRs.

	key.type[Group1] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP2";
	key <AE08> {
		[                 NoSymbol,                   egrave,                   Egrave ],
		[                 NoSymbol,                   egrave,                   Egrave ]
	}; // Levels 4..8 are included from kbfrFRs.

	// Key <AE09> is included from kbfrFRs.
	key.type[Group1] = "EIGHT_LEVELS_AE10_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AE10_FIRSTALPHABETIC_GROUP2";
	key <AE10> {
		[                 NoSymbol,                   eacute,                   Eacute ],
		[                 NoSymbol,                   eacute,                   Eacute ]
	}; // Levels 4..8 are included from kbfrFRs.

	// Key <AE11> is included from kbfrFRs.
	// Key <AE12> is included from kbfrFRs.
	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SIX_TITLECASE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SIX_TITLECASE_GROUP2";
	key <AD01> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                        q,                        Q,                   U107A5 ],
		[                        q,                        Q,                   U107A5 ]
	}; // superscript small q

	// Key <AD02> is included from kbfrFRs.
	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP2";
	key <AD03> {
		[                        j,                        J,                    U02B2 ],
		[                        j,                        J,                    U02B2 ]
	}; // superscript small j

	key <AD04> {
		[                        f,                        F,                    U1DA0 ],
		[                        f,                        F,                    U1DA0 ]
	}; // superscript small f

	key <AD05> {
		[                        g,                        G,                    U1D4D ],
		[                        g,                        G,                    U1D4D ]
	}; // superscript small g

	// Key <AD06> is included from kbfrFRs.
	key <AD07> {
		[                        m,                        M,                    U1D50 ],
		[                        m,                        M,                    U1D50 ]
	}; // superscript small m

	key <AD08> {
		[                        l,                        L,                    U02E1 ],
		[                        l,                        L,                    U02E1 ]
	}; // superscript small l

	key <AD09> {
		[                        d,                        D,                    U1D48 ],
		[                        d,                        D,                    U1D48 ]
	}; // superscript small d

	key <AD10> {
		[                        k,                        K,                    U1D4F ],
		[                        k,                        K,                    U1D4F ]
	}; // superscript small k

	// Key <AD11> is included from kbfrFRs.
	key.type[Group1] = "EIGHT_LEVELS_AD12_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AD12_GROUP2";
	key <AD12> {
		[                    UEFD0,                 NoSymbol,                    UEFD0 ],
		[               underscore,                 NoSymbol,                    UEFD0 ]
	}; // Other indices included from kbfrFRs.

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_GROUP2";
	key <AC01> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                        a,                        A,                    U1D43 ],
		[                        a,                        A,                    U1D43 ]
	}; // superscript small a

	// Key <AC02> is included from kbfrFRs.
	key <AC03> {
		[                        e,                        E,                    U1D49 ],
		[                        e,                        E,                    U1D49 ]
	}; // superscript small e

	key <AC04> {
		[                        r,                        R,                    U02B3 ],
		[                        r,                        R,                    U02B3 ]
	}; // superscript small r

	key <AC05> {
		[                        t,                        T,                    U1D57 ],
		[                        t,                        T,                    U1D57 ]
	}; // superscript small t

	key <AC06> {
		[                        u,                        U,                    U1D58 ],
		[                        u,                        U,                    U1D58 ]
	}; // superscript small u

	key <AC07> {
		[                        n,                        N,                    U207F ],
		[                        n,                        N,                    U207F ]
	}; // superscript small n

	key <AC08> {
		[                        o,                        O,                    U1D52 ],
		[                        o,                        O,                    U1D52 ]
	}; // superscript small o

	key <AC09> {
		[                        i,                        I,                    U2071 ],
		[                        i,                        I,                    U2071 ]
	}; // superscript small i

	key <AC10> {
		[                        p,                        P,                    U1D56 ],
		[                        p,                        P,                    U1D56 ]
	}; // superscript small p

	key.type[Group1] = "EIGHT_LEVELS_AC11_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_AC11_GROUP2";
	key <AC11> {
		[     rightsinglequotemark ],
		[     rightsinglequotemark ]
	}; // Other indices included from kbfrFRs.

	key.type[Group1] = "EIGHT_LEVELS_BKSL_REMAP_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_BKSL_REMAP_GROUP2";
	key <BKSL> {
		[                Multi_key ],
		[                Multi_key ]
	}; // Other indices included from kbfrFRs.

	// Row B is included from kbfrFRs, except:
	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SEVEN_ALPHABETIC_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SEVEN_ALPHABETIC_GROUP2";
	key <AB06> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                        h,                        H,                     U02B0 ],
		[                        h,                        H,                     U02B0 ]
	}; // superscript small h

	// Key <SPCE> is included from kbfrFRs.
	// Numeric keypad (numpad) is included from kbfrFRs.
	// Variant name:
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFAA ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFAA ]
	};

};

partial alphanumeric_keys
xkb_symbols "kbfrFRhw" {

	name[Group1] = "French hybrid AZERTY semiautomatic";
	name[Group2] = "French hybrid AZERTY semiautomatic";
	// "Français hybride AZERTY semi-automatique"
	//
	// The following layouts are remapped but have legacy shortcuts, hence they are called hybrid.
	// The code names of hybrid variants end in the shortcut letter on B01:
	//     w for azerty shortcuts
	//     z for qwerty shortcuts
	//     y for qwertz shortcuts
	//
	// The limitation of XKB supporting only 8 characters per key and per group brings
	// the need to affect index 8 to shortcuts instead of output. As a consequence, no
	// emoji are available on level 8, nor the `&quot;` and `&apos;` sequences on O/I.

	include "dispocla(kbfrFRr)"

	// Row E is included from kbfrFRr.
	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SIX_TITLECASE_HYBRID_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SIX_TITLECASE_HYBRID_GROUP2";
	key <AD01> {
		// Index:                1,                        2,                        3,                        4,                         5,                        6,                        7,                        8
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        a ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        a ]
	};

	// Key <AD02> is included from kbfrFRr.
	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_HYBRID_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_HYBRID_GROUP2";
	key <AD03> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        e ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        e ]
	};

	key <AD04> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        r ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        r ]
	};

	key <AD05> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        t ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        t ]
	};

	// Key <AD06> is included from kbfrFRr.
	key <AD07> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        u ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        u ]
	};

	key <AD08> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        i ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        i ]
	};

	key <AD09> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        o ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        o ]
	};

	key <AD10> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        p ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        p ]
	};

	// Keys <AD11> and <AD12> are included from kbfrFRr.
	key <AC01> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        q ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        q ]
	};

	// Key <AC02> is included from kbfrFRr.
	key <AC03> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        d ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        d ]
	};

	key <AC04> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        f ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        f ]
	};

	key <AC05> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        g ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        g ]
	};

	key <AC06> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        h ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        h ]
	};

	key <AC07> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        j ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        j ]
	};

	key <AC08> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        k ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        k ]
	};

	key <AC09> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        l ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        l ]
	};

	key <AC10> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        m ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        m ]
	};

	// The rest is included from kbfrFRr, except:
	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SEVEN_ALPHABETIC_HYBRID_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SEVEN_ALPHABETIC_HYBRID_GROUP2";
	key <AB06> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        n ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        n ]
	};

	// Variant name:
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFAB ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFAB ]
	};

};

partial alphanumeric_keys
xkb_symbols "kbfrFRhz" {

	name[Group1] = "French hybrid QWERTY semiautomatic";
	name[Group2] = "French hybrid QWERTY semiautomatic";
	// "Français hybride QWERTY semi-automatique"
	//
	// This layout is remapped but has QWERTY shortcuts.

	include "dispocla(kbfrFRhw)"

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SIX_TITLECASE_HYBRID_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SIX_TITLECASE_HYBRID_GROUP2";
	key <AD01> {
		// Index:                1,                        2,                        3,                        4,                         5,                        6,                        7,                        8
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        q ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        q ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_HYBRID_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_HYBRID_GROUP2";
	key <AD02> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        w ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        w ]
	};

	key <AC01> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        a ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        a ]
	};

	key <AC10> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                semicolon ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                semicolon ]
	};

	// Key <AC11> is already <apostrophe>
	key.type[Group1] = "EIGHT_LEVELS_BKSL_REMAP_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_BKSL_REMAP_GROUP2";
	key <BKSL> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                backslash ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                backslash ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_HYBRID_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_HYBRID_GROUP2";
	key <AB01> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        z ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        z ]
	};

	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_ONE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_ONE_GROUP2";
	key <AB07> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        m ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        m ]
	};

	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_TWO_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_TWO_GROUP2";
	key <AB08> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    comma ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    comma ]
	};

	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_THREE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_THREE_GROUP2";
	key <AB09> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                   period ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                   period ]
	};

	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_FOUR_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_FOUR_GROUP2";
	key <AB10> {
		// Index:                1,                        2,                        3,                        4,                        5,                        6,                        7,                        8
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    slash ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    slash ]
	};

	// Variant name:
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFAC ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFAC ]
	};

};

partial alphanumeric_keys
xkb_symbols "kbfrFRhy" {

	name[Group1] = "French hybrid QWERTZ semiautomatic";
	name[Group2] = "French hybrid QWERTZ semiautomatic";
	// "Français hybride QWERTZ semi-automatique"
	//
	// This layout is remapped but has QWERTZ shortcuts, for Swiss French usage.
	// It is based on the hybrid qwerty layout.

	include "dispocla(kbfrFRhz)"

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_HYBRID_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_HYBRID_GROUP2";
	key <AD06> {
		// Index:                1,                        2,                        3,                        4,                         5,                        6,                        7,                        8
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        z ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        z ]
	};

	key <AB01> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        y ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                        y ]
	};

	// Variant name:
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFAD ],
		[                 NoSymbol,                 NoSymbol,                 NoSymbol,                 NoSymbol,                    UEFAD ]
	};

};

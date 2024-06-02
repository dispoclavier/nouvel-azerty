//                       Date: 2024-06-02T0334+0200
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
//        English description: Keyboard layouts fit for national, regional and neighbor languages of Francophonie.
//     Description française : Dispositions de clavier adaptées aux langues nationales, régionales et voisines de la Francophonie.
//              Target public: General public and developers, journalists, scientists, secretaries, translators, typographers and writers
//             Destinataires : Grand public et développeurs, écrivains, journalistes, scientifiques, secrétaires, traducteurs et typographes
//               Code licence: Apache 2.0
//           Code licence URL: https://www.apache.org/licenses/LICENSE-2.0
//           Non-code licence: CC-BY 4.0
//       Non-code licence URL: https://creativecommons.org/licenses/by/4.0/deed.fr
//              Email address: dev@dispoclavier.net
//
//   * In Unicode CLDR, this platform is labeled ChromeOS, and it is explained that
//     in the CLDR, *Linux* is supported alongside *ChromeOS*, or through ChromeOS.
//
//               Installation: 1. Add this file in /usr/share/X11/xkb/symbols/dispocla
//                             2. In /usr/share/X11/xkb/rules/evdev
//                                comment out the rule:
//                                    *		*		=	+%l[2]%(v[2]):2
//                                That line causes to override the second group with
//                                the default, en_US in case of fr_FR.
//                                This behavior is deactivated by commenting out that
//                                line, fixing the second group for all locales.
//                                Courtesy @Salim on unix.stackexchange.com
//                                https://unix.stackexchange.com/a/420126
//                             3. In /usr/share/X11/xkb/rules/evdev.xml
//                                add the lines enclosed in the file
//                                    evdev-additions.xml
//                                before the `</layoutList>` closing tag.
//
//                             The changes take effect when reopening a session.
//
//             Uninstallation: Delete those lines, uncomment the rule, remove the file.
//
//      Login keyboard layout: The keyboard layout used to log in is configured in
//                             `/etc/default/keyboard`.
//                             https://manpages.debian.org/jessie/keyboard-configuration/keyboard.5.en.html
//
//                             # KEYBOARD CONFIGURATION FILE
//                             
//                             # Consult the keyboard(5) manual page.
//                             
//                             XKBMODEL="pc105"
//                             XKBLAYOUT="dispocla"
//                             XKBVARIANT="kbfrFRs"
//                             XKBOPTIONS=""
//
//
// Block comments are not supported in XKB configuration files.
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
// ##  Name and mapping of the level 5 modifier key
//
// The XKB level 5 modifier key is used in Jan James’ implementation of the
// governmental version (by federal Government and industry representatives)
// of the Canadian multilingual standard keyboard layout, initially designed
// by Alain LaBonté. Jan James worked out Microsoft’s Windows implementation
// of the Canadian multilingual standard keyboard layout. There, what should
// be the group selector is like the level 5 modifier key instead of being a
// dead key as specified in ISO/IEC 9995-2 that CAN/CSA Z243.200-92 complies
// with. But that is not how things are expected to work.
//
// Instead, keyboard layouts using a scheme like in this file have a level 5
// modifier located lefthand so as to be usable for an extended numpad below
// the 7 8 9 0 keys where embedded numpads on compact keyboards are located,
// too.
//
// The repurposed level 5 modifier is called AltFr by analogy with AltGr and
// to account for its origin on French keyboard layouts, like Microsoft also
// called the peculiar Caps Lock mappings 'SGCaps', an abbreviation standing
// for 'Swiss-German Capitals'.
//
// This level 5 modifier is repurposed and moved to the left on the “ISO key”
// B00. On ANSI keyboards with ISO compatibility, where the ISO key takes the
// place of the Right Control key, Caps Lock and ISO key are swapped, so that
// AltFr is on the Caps Lock key whereas the latter is then on Right Control.
// On plain ANSI keyboards, the AltFr key can still be remapped to Caps Lock,
// and Caps Lock to Right Control.
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
// Additionally, Shift + AltFr yields unspaced-out punctuation marks `?!:;`.
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
// The EuroSign is required on key E, level 3 following a recommendation from
// the European Commission. While carfully avoiding any interference with the
// national keyboard standards, the EC has issued a recommendation to assign
// the euro sign the AltGr + e key position. Current hardware and keyboard
// layout drivers are consistent with this recommendation, and users largely
// adhere to it and have strong expectations accordingly.
// https://www.open-std.org/cen/tc304/Euro/Euroreport.html
//
// To achieve this, quotedbl is mapped on that key in order to be replaced by
// the euro sign due to being redundant, since quotedbl is on the base level,
// in French mode and in ASCII mode alike, keys E03 and D11, respectively.
//
// Additionally, EuroSign is tied to quotedbl by obvious mnemonics based on the
// double bar in the round (C-like) E, that the double acute accent on key E,
// level 4, also resonates with. Its Multi_key equivalent is quotedbl.
//
// The apparent isolation of quotedbl, away from apostrophe / single quote,
// benefits ergonomics of backslash in synergy with digits, while apostrophe is
// in the benefit of base level mappings both in French mode and in ASCII mode,
// much like quotedbl, on E05 and C11, respectively, and ASCII grave has easy,
// one-handed access on B06 in both modes, plus level 3 access on C11 in ASCII
// mode only. This practical, respectful ASCII map was sadly unknown across the
// 1.0 release, and when it came up, it triggered a 2.0 upgrade due to backward
// incompatibility. The truth is, the 1.0 map was a wild guess, unlike the next
// map, now 2.0, for which I finally prayed to God to help me and advise me.
//
// The euro sign is attached to the preceding numeric value using NNBSP, also
// used before abbreviated measurement units. As a consequence, the euro sign
// needs to be mapped on level 5 alongside, in synergy with NNBSP, and so are
// the dollar, pound, and yen signs, the latter two not on level 3 though.
//
// The linked page (https://www.open-std.org/cen/tc304/Euro/Euroreport.html)
// is from 1998 when the only “hard space” was NBSP, Since 1999 we have a NNBSP
// that is actually recommended before measurement unit abbreviations as well
// as currency short forms, because it is fixed-width, as opposed to NBSP that
// is justifying on the web and in MS Word 2013.
// https://answers.microsoft.com/en-us/msoffice/forum/msoffice_word-mso_windows8/nonbreakable-space-justification-in-word-2016/4fa1ad30-004c-454f-9775-a3beaa91c88b
//
// The fact that quotedbl is on the E key, and apostrophe is on the U key based
// on AZERTY-QWERTY-QWERTZ, builds up some extra mnemonics, referring to the EU
// initialism. Also, both quotedbl and apostrophe have their HTML named entity,
// frequent `&quot;` and rare `&apos;`, on level 8 (Shift + AltGr + AltFr) like
// ampersand, less and greater, the latter two on level 6 (Shift + AltFr).
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
// the number of group selector key presses, and the digit entered after. The
// multiple key press support goes at least up to 4. That is why groups are a
// 0-based array of 13 groups, where index 0 is the default layout. The first
// three digits are used for groups 10 through 12.
//
// Given access to uppercase must be intuitive, digits are mapped on level 3.
// Caps Lock is required for uppercase. As a consequence, the digits require
// an extra toggle, that is called “ModLock”, short for Mode Lock, and it is
// implemented as a group toggle. Other non-alphabetic keys are also affected
// by ModLock, making up for what may be referred to as an ASCII mode.
//

default partial alphanumeric_keys
xkb_symbols "kbfrFRs" {

	name[Group1] = "French France semiautomatic keyboard layout";
	name[Group2] = "French France semiautomatic keyboard layout";
	// "Français France disposition de clavier semi-automatique"

	// Includes files from the symbols/ directory.
	include "pc(pc105)"   // Basic functionality.
	include "inet(evdev)" // Easy access and internet keys.

	//
	// New 'AltFr' modifier key
	//
	// The level 5 modifier defaults to the LSGT key but may need to be placed on
	// CapsLock depending on the hardware. Keyboards for the European market with
	// key LSGT on right Control need to have LSGT and CAPS swapped, so as to get
	// CapsLock on right Control, and the level 5 modifier on the CapsLock key.
	//
	// Correct LSGT key behavior after inclusion of symbols/pc(105):
	modifier_map Mod3 { <MDSW> };
	// See also the complete modifier map list at the bottom of this section.
	include "level5(lsgt_switch)"

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

	// Regular level 3 (AltGr) modifier key

	include "level3(ralt_switch)"

	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <RALT> {
		[ ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift ],
		[ ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift ]
	};

	//
	// ASCII mode lock toggle key
	//
	// The second graphic toggle changes between default mode, that is called the
	// French mode for instance, and the ASCII mode. It is implemented as a group
	// toggle between first group and last group, i.e. group 1 and group 2, while
	// repurposing NumLock is not an option, due to its use on compact keyboards.
	// Key TLDE is used for this additional graphic toggle and becomes Group Lock
	// or ModLock for short, affecting both the alphanumeric block and the numpad
	// graphic extensions.
	//
	// ISO_First_Group is interpreted as: action= LockGroup(group=1)
	// ISO_Last_Group  is interpreted as: action= LockGroup(group=2)
	//

	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[      ISO_Last_Group,      ISO_Last_Group,      ISO_Last_Group,      ISO_Last_Group,               UEFA1,               UEFA0 ],
		[     ISO_First_Group,     ISO_First_Group,     ISO_First_Group,     ISO_First_Group,               UEFA1,               UEFA0 ]
	}; // Level5 yields <variant>; Level6 yields <version>

	//
	// Level inconsistency
	//
	// CAUTION: Index 4 is mostly level 5, and conversely.
	//
	// On indices 1 through 4, the keysyms are ordered only with respect to the
	// keyboard view, where the traditional four levels are filled in by parsing
	// indices 1 through 4 regardless of key types.
	//
	// Since dead key syms may be rendered as an ellipsis, because dead_greek and
	// Multi_key seem to be excluded from the representation tweak applied so far
	// as spacing clones of diacritics are available, and 9 of the dead key syms
	// are PUA characters by lack of appropriate keysyms in keysymdef.h, the dead
	// keys should not show up in the level 4 slot, the less as the dead keys on
	// level 4 are consistent with the level 3 ASCII symbol map.
	//
	// Instead, the level 4 position on the layout views is used for level 5,
	// except on key D01, where the level 3 - level 5 redundancy when both have
	// the same symbol is not possible, to cater for the Breton trigram because
	// this is written with a letter apostrophe U02BC and so makes a good point
	// for being mapped, beyond the Breton CʼHWERTY, as an all-in-one sequence.
	//
	//
	// Column width
	//
	// After the removal of dead_longsolidusoverlay in libxkbcommon 1.6.0 (2023),
	// keysyms are expected to be no longer than rightsinglequotemark, making for
	// a compacter layout with a column width shrinking from 25 to 20 characters.
	// https://lists.freedesktop.org/archives/wayland-devel/2023-October/043121.html
	//

	key.type[Group1] = "EIGHT_LEVELS_SUPERSCRIPT_SUBSCRIPT_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[         twosuperior,       threesuperior,                   1,           ampersand,         onesuperior,               U2082,               U2083,               UEFC1 ],
		[                   1,                   1,                   1,         onesuperior,                   1,               U2081,         onesuperior,               UEFC1 ]
	}; // U2081 ₁ SUBSCRIPT ONE; U2082 ₂ SUBSCRIPT TWO; U2083 ₃ SUBSCRIPT THREE; UEFC1 1️⃣ keycap 1 emoji

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE02> {
		[              eacute,              Eacute,                   2,               UEFD9,                   2,               UEFC2,         twosuperior,               UEFC2 ],
		[                   2,                   2,                   2,         twosuperior,                   2,               U2082,         twosuperior,               UEFC2 ]
	}; // U2082 ₂ SUBSCRIPT TWO; UEFC2 2️⃣ keycap 2 emoji; UEFD9 *dead_legacytilde

	key.type[Group1] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE03> {
		[            quotedbl,              endash,                   3,          numbersign,                   3,               UEFC3,       threesuperior,               UEFC3 ],
		[                   3,                   3,                   3,       threesuperior,                   3,               U2083,       threesuperior,               UEFC3 ]
	}; // U2083 ₃ SUBSCRIPT THREE; UEFC3 3️⃣ keycap 3 emoji

	key <AE04> {
		[rightsinglequotemark,              emdash,                   4,           braceleft,                   4,               UEFC4,               U2074,               UEFC4 ],
		[                   4,                   4,                   4,               U2074,                   4,               U2084,               U2074,               UEFC4 ]
	}; // U2074 ⁴ SUPERSCRIPT FOUR; U2084 ₄ SUBSCRIPT FOUR; UEFC4 4️⃣ keycap 4 emoji

	key <AE05> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[          apostrophe,               U00AD,                   5,         bracketleft,                   5,               UEFC5,               U2075,               UEFC5 ],
		[                   5,                   5,                   5,               U2075,                   5,               U2085,               U2075,               UEFC5 ]
	}; // U00AD SOFT HYPHEN; U2075 ⁵ SUPERSCRIPT FIVE; U2085 ₅ SUBSCRIPT FIVE; UEFC5 5️⃣ keycap 5 emoji

	key <AE06> {
		[               minus,               U2011,                   6,                 bar,                   6,               UEFC6,               U2076,               UEFC6 ],
		[                   6,                   6,                   6,               U2076,                   6,               U2086,               U2076,               UEFC6 ]
	}; // U2011 ‑ NON-BREAKING HYPHEN; U2076 ⁶ SUPERSCRIPT SIX; U2086 ₆ SUBSCRIPT SIX; UEFC6 6️⃣ keycap 6 emoji

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE07> {
		[              egrave,              Egrave,                   7,               UEFDA,                   7,               UEFC7,               U2077,               UEFC7 ],
		[                   7,                   7,                   7,               U2077,                   7,               U2087,               U2077,               UEFC7 ]
	}; // U2077 ⁷ SUPERSCRIPT SEVEN; U2087 ₇ SUBSCRIPT SEVEN; UEFC7 7️⃣ keycap 7 emoji; UEFDA *dead_legacygrave

	key.type[Group1] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE08> {
		[          underscore,      Greek_horizbar,                   8,           backslash,                   8,               UEFC8,               U2078,               UEFC8 ],
		[                   8,                   8,                   8,               U2078,                   8,               U2088,               U2078,               UEFC8 ]
	}; // Greek_horizbar ― U2015 HORIZONTAL BAR (not “Greek”); U2078 ⁸ SUPERSCRIPT EIGHT; U2088 ₈ SUBSCRIPT EIGHT; UEFC8 8️⃣ keycap 8 emoji

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE09> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            ccedilla,            Ccedilla,                   9,           parenleft,                   9,               UEFC9,               U2079,               UEFC9 ],
		[                   9,                   9,                   9,               U2079,                   9,               U2089,               U2079,               UEFC9 ]
	}; // U2079 ⁹ SUPERSCRIPT NINE; U2089 ₉ SUBSCRIPT NINE; UEFC9 9️⃣ keycap 9 emoji

	key.type[Group1] = "EIGHT_LEVELS_AE10_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE10> {
		[              agrave,              Agrave,                   0,          parenright,               U2070,               U2080,              U1F51F,               UEFC0 ],
		[                   0,                   0,                   0,               U2070,                   0,               U2080,               U2070,               UEFC0 ]
	}; // U2070 ⁰ SUPERSCRIPT ZERO; U2080 ₀ SUBSCRIPT ZERO; U1F51F 🔟 KEYCAP TEN emoji; UEFC0 0️⃣ keycap 0 emoji

	key.type[Group1] = "EIGHT_LEVELS_MINUS_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_MINUS_GROUP2";
	key <AE11> {
		[                  at,              degree,               U1D49,        bracketright,               U207B,                   E,               minus,               UEFCA ],
		[                  at,              degree,               minus,               U208B,               U207B,                   E,               minus,               UEFCA ]
	}; // U1D49 ᵉ superscript small e; U208B ₋ SUBSCRIPT MINUS; U207B ⁻ SUPERSCRIPT MINUS; UEFCA  *️⃣ keycap star emoji

	key.type[Group1] = "EIGHT_LEVELS_PLUS_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PLUS_GROUP2";
	key <AE12> {
		[      dead_diaeresis,                plus,           Multi_key,          braceright,               U207A,                   F,               equal,               UEFCB ],
		[               equal,                plus,           Multi_key,               U208A,               U207A,                   F,               equal,               UEFCB ]
	}; // U208A ₊ SUBSCRIPT PLUS; U207A ⁺ SUPERSCRIPT PLUS; UEFCB  #️⃣ keycap hash emoji

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC_TITLECASE";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC_TITLECASE";
	key <AD01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   a,                   A,         asciicircum,                 c_h,               UEFD1,               U1D43,                 C_H,                 C_h ],
		[                   a,                   A,         asciicircum,                 c_h,               UEFD1,               U1D43,                 C_H,                 C_h ]
	}; // U1D43 ᵃ superscript small a; UEFD1 *dead_superscript; Breton trigraph: lowercase and titlecase; on supporting systems: uppercase when CapsLock is on

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key <AD02> {
		[                   z,                   Z,             percent,             percent,               UEFD5,               U1DBB,             minutes,              U1F627 ],
		[                   z,                   Z,             percent,             percent,               UEFD5,               U1DBB,             minutes,              U1F627 ]
	}; // U1DBB ᶻ superscript small z; UEFD5 *dead_turned; 😧 U1F627 ANGUISHED FACE emoji

	key <AD03> {
		[                   e,                   E,            EuroSign,            EuroSign,    dead_doubleacute,               U1D49,             seconds,               UEF8D ],
		[                   e,                   E,            EuroSign,            EuroSign,    dead_doubleacute,               U1D49,             seconds,               UEF8D ]
	}; // U1D49 ᵉ superscript small e; UEF8D '&quot;'

	key <AD04> {
		[                   r,                   R,           backslash,            sterling,               UEFD6,               U02B3,             radical,              U1F914 ],
		[                   r,                   R,           backslash,            sterling,               UEFD6,               U02B3,             radical,              U1F914 ]
	}; // U02B3 ʳ superscript small r; UEFD6 *dead_reversed; 🤔 U1F914 THINKING FACE 20th-ranking emoji [🙄 U1F644 FACE WITH ROLLING EYES 23rd-ranking emoji is not supported]

	key <AD05> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   t,                   T,          asciitilde,               U2212,          dead_tilde,               U1D57,             figdash,              U1F60A ],
		[                   t,                   T,          asciitilde,               U2212,          dead_tilde,               U1D57,             figdash,              U1F60A ]
	}; // U1D57 ᵗ superscript small t; U2212 − MINUS SIGN; figdash is the tabular minus sign; 😊 U1F60A SMILING FACE WITH SMILING EYES (worldwide fifth-most used emoji, fourth-most used smiling emoji in France)

	key <AD06> {
		[                   y,                   Y,          dead_greek,                 yen,          dead_greek,               U02B8,         Greek_OMEGA,              U1F60D ],
		[                   y,                   Y,          dead_greek,                 yen,          dead_greek,               U02B8,         Greek_OMEGA,              U1F60D ]
	}; // U02B8 ʸ superscript small y; Greek_OMEGA is preferred for Ohm sign; 😍 U1F60D SMILING FACE WITH HEART-SHAPED EYES (third-most used smiling emoji in France, third-most overall worldwide)

	key <AD07> {
		[                   u,                   U,          apostrophe,                   4,          dead_acute,               U1D58,               UEF9F,               UEF8C ],
		[                   u,                   U,          apostrophe,                   4,          dead_acute,               U1D58,               UEF9F,               UEF8C ]
	}; // U1D58 ᵘ superscript small u; UEF9F Unicode prefix 'U+'; UEF8C '&apos;'

	key <AD08> {
		[                   i,                   I,           braceleft,                   5,           dead_hook,               U2071,               UEF7E,              U1F64F ],
		[                   i,                   I,           braceleft,                   5,           dead_hook,               U2071,               UEF7E,              U1F64F ]
	}; // U2071 ⁱ superscript small i; UEF7E '\\u{'; 🙏 U1F64F PERSON WITH FOLDED HANDS worldwide sixth-most used emoji

	key <AD09> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   o,                   O,          braceright,                   6,               UEFD4,               U1D52,               U2126,              U1F601 ],
		[                   o,                   O,          braceright,                   6,               UEFD4,               U1D52,               U2126,              U1F601 ]
	}; // U1D52 ᵒ superscript small o; UEFD4 *dead_retroflexhook; U2126 Ω OHM SIGN (some fonts support this but no Greek); 😁 U1F601 GRINNING FACE WITH SMILING EYES 13th-ranking emoji

	key <AD10> {
		[                   p,                   P,           ampersand,              period,       dead_abovedot,               U1D56,           paragraph,               UEF8B ],
		[                   p,                   P,           ampersand,              period,       dead_abovedot,               U1D56,           paragraph,               UEF8B ]
	}; // U1D56 ᵖ superscript small p; UEF8B '&amp;'

	key.type[Group1] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key <AD11> {
		[     dead_circumflex,               U2039,          dead_tilde,               UEF66,         asciicircum,      dead_diaeresis,                   C,         bracketleft ],
		[            quotedbl,         bracketleft,         asciicircum,                   C,         asciicircum,      dead_diaeresis,         asciicircum,         bracketleft ]
	}; // UEF66 '‹ ' spaced out with NNBSP; U2039 ‹ SINGLE LEFT-POINTING ANGLE QUOTATION MARK

	key <AD12> {
		[          dead_acute,               U203A,          dead_grave,               UEF67,              dollar,            sterling,                   D,        bracketright ],
		[          underscore,        bracketright,           Multi_key,                   D,              dollar,            sterling,              dollar,        bracketright ]
	}; // UEF67 ' ›' spaced out with NNBSP; U203A › SINGLE RIGHT-POINTING ANGLE QUOTATION MARK

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key <AC01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   q,                   Q,          numbersign,          numbersign,               UEFD0,              U107A5,               U2044,              U1F610 ],
		[                   q,                   Q,          numbersign,          numbersign,               UEFD0,              U107A5,               U2044,              U1F610 ]
	}; // U107A5 𐞥 superscript small q; UEFD0 *dead_group; U2044 ⁄ FRACTION SLASH; U1F610 😐 NEUTRAL FACE emoji

	key <AC02> {
		[                   s,                   S,              dollar,              dollar,       dead_currency,               U02E2,             section,              U1F614 ],
		[                   s,                   S,              dollar,              dollar,       dead_currency,               U02E2,             section,              U1F614 ]
	}; // U02E2 ˢ superscript small s; U1F614 😔 PENSIVE FACE 4th-top sad face emoji

	key <AC03> {
		[                   d,                   D,           parenleft,           parenleft,  dead_invertedbreve,               U1D48,               U2300,              U1F606 ],
		[                   d,                   D,           parenleft,           parenleft,  dead_invertedbreve,               U1D48,               U2300,              U1F606 ]
	}; // U1D48 ᵈ superscript small d; U2300 ⌀ DIAMETER SIGN; U1F606 😆 SMILING FACE WITH OPEN MOUTH AND TIGHTLY-CLOSED EYES 16th-ranking emoji

	key <AC04> {
		[                   f,                   F,          parenright,          parenright,          dead_breve,               U1DA0,                  mu,              U1F525 ],
		[                   f,                   F,          parenright,          parenright,          dead_breve,               U1DA0,                  mu,              U1F525 ]
	}; // U1DA0 ᶠ superscript small f; U00B5 µ MICRO SIGN; U1F525 🔥 FIRE 15th-ranking emoji

	key <AC05> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   g,                   G,               minus,               minus,               UEFD8,               U1D4D,              endash,              U1F44F ],
		[                   g,                   G,               minus,               minus,               UEFD8,               U1D4D,              endash,              U1F44F ]
	}; // U1D4D ᵍ superscript small g; UEFD8 *dead_bar; U2013 – EN DASH (Unicode-recommended for noting intervals); U1F44F 👏 CLAPPING HANDS SIGN worldwide twelvth-most used emoji

	key <AC06> {
		[                   h,                   H,                plus,                plus,           dead_horn,               U02B0,           plusminus,              U1F44D ],
		[                   h,                   H,                plus,                plus,           dead_horn,               U02B0,           plusminus,              U1F44D ]
	}; // U02B0 ʰ superscript small h; U1F44D 👍 THUMBS UP SIGN worldwide tenth-most used emoji

	key <AC07> {
		[                   j,                   J,          underscore,                   1,               UEFD2,               U02B2,               U203E,              U1F602 ],
		[                   j,                   J,          underscore,                   1,               UEFD2,               U02B2,               U203E,              U1F602 ]
	}; // U02B2 ʲ superscript small j; UEFD2 *dead_subscript; U203E ‾ OVERLINE as underline in fixed-width plain text; U1F602 😂 FACE WITH TEARS OF JOY worldwide most used emoji, second-most used in France after ❤ U2764

	key <AC08> {
		[                   k,                   K,         bracketleft,                   2,         dead_ogonek,               U1D4F,               UEF7B,              U1F605 ],
		[                   k,                   K,         bracketleft,                   2,         dead_ogonek,               U1D4F,               UEF7B,              U1F605 ]
	}; // U1D4F ᵏ superscript small k; UEF7B '&#x'; U1F605 😅 SMILING FACE WITH OPEN MOUTH AND COLD SWEAT worldwide eleventh-most used emoji

	key <AC09> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   l,                   L,        bracketright,                   3,               UEFD3,               U02E1,            sterling,              U1F923 ],
		[                   l,                   L,        bracketright,                   3,               UEFD3,               U02E1,            sterling,              U1F923 ]
	}; // U02E1 ˡ superscript small l; UEFD3 *dead_abovehook; U1F923 🤣 ROLLING ON THE FLOOR LAUGHING fourth-most used emoji

	key <AC10> {
		[                   m,                   M,                 bar,               comma,         dead_macron,               U1D50,                  mu,              U1F637 ],
		[                   m,                   M,                 bar,               comma,         dead_macron,               U1D50,                  mu,              U1F637 ]
	}; // U1D50 ᵐ superscript small m; U00B5 µ MICRO SIGN; U1F637 😷 FACE WITH MEDICAL MASK emoji

	key.type[Group1] = "EIGHT_LEVELS_CAPITAL_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_CAPITAL_LEVEL8_CONTROL";
	key <AC11> {
		[              ugrave,       guillemotleft,            ellipsis,               UEF64,             percent,             percent,                   A,          apostrophe ],
		[          apostrophe,             percent,               grave,                   A,             percent,             percent,             percent,          apostrophe ]
	}; // UEF64 '« ' spaced out with NNBSP; APOSTROPHE for application shortcut mapping

	key.type[Group1] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key <BKSL> {
		[               UEFD0,      guillemotright,               UEFD0,               UEF65,            asterisk,                  mu,                   B,           semicolon ],
		[               minus,            asterisk,               UEFD0,                   B,            asterisk,                  mu,            asterisk,           semicolon ]
	}; // UEFD0 *dead_group; UEF65 ' »' spaced out with NNBSP; SEMICOLON for application shortcut mapping

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key <AB01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   w,                   W,               slash,               slash,         dead_stroke,               U02B7,               colon,              U1F622 ],
		[                   w,                   W,               slash,               slash,         dead_stroke,               U02B7,               colon,              U1F622 ]
	}; // U02B7 ʷ superscript small w; U1F622 😢 CRYING FACE 19th-ranking emoji

	key <AB02> {
		[                   x,                   X,            asterisk,            asterisk,      dead_abovering,               U02E3,               U200C,              U1F31F ],
		[                   x,                   X,            asterisk,            asterisk,      dead_abovering,               U02E3,               U200C,              U1F31F ]
	}; // U02E3 ˣ superscript small x; U200C "‌" ZERO WIDTH NON-JOINER; U1F31F 🌟 GLOWING STAR emoji

	key <AB03> {
		[                   c,                   C,                less,            multiply,     dead_circumflex,               U1D9C,               UEF8E,              U1F631 ],
		[                   c,                   C,                less,            multiply,     dead_circumflex,               U1D9C,               UEF8E,              U1F631 ]
	}; // U1D9C ᶜ superscript small c; UEF8E '&lt;'; U1F631 😱 FACE SCREAMING IN FEAR 2nd-top sad face emoji

	key <AB04> {
		[                   v,                   V,             greater,            division,          dead_caron,               U1D5B,               UEF8F,              U1F496 ],
		[                   v,                   V,             greater,            division,          dead_caron,               U1D5B,               UEF8F,              U1F496 ]
	}; // U1D5B ᵛ superscript small v; UEF8F '&gt;'; U1F496 💖	SPARKLING HEART 17th-ranking emoji

	key <AB05> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   b,                   B,               equal,               UEF6D,               UEFD7,               U1D47,              U1F618,              U1F495 ],
		[                   b,                   B,               equal,               UEF6D,               UEFD7,               U1D47,              U1F618,              U1F495 ]
	}; // U1D47 ᵇ superscript small b; UEFD7 *dead_flag regional indicator letters; UEF6D '00'; U1F618 😘 FACE THROWING A KISS sixth-most [smiling second-most] used emoji in France, ninth-most worldwide; U1F495 💕 TWO HEARTS seventh-most used emoji

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC";
	key <AB06> {
		[                   n,                   N,               grave,                   0,          dead_grave,               U207F,               UEF68,               UEF69 ],
		[                   n,                   N,               grave,                   0,          dead_grave,               U207F,               UEF68,               UEF69 ]
	}; // U207F ⁿ SUPERSCRIPT LATIN SMALL LETTER N; UEF68 'nᵒ ' with U1D52 and NNBSP; UEF69 'Nᵒ ' with U1D52 and NNBSP

	key.type[Group1] = "EIGHT_LEVELS_LEVEL1_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL1_CONTROL";
	key <AB07> {
		[               comma,            question,            question,               UEF63,        dead_cedilla,            question,              U1F612,              U1F499 ],
		[               comma,            question,            question,               comma,        dead_cedilla,               UEF7B,          digitspace,              U1F49A ]
	}; // UEF63 ' ?' spaced out with NNBSP; UEF7B '&#x;' U2007 ' ' FIGURE SPACE; U1F612 😒 UNAMUSED FACE 3rd-top sad face emoji [2021-07-20T2206+0200]; U1F499 💙 BLUE HEART 18th-ranking emoji; U1F49A 💚 GREEN HEART emoji

	key <AB08> {
		[              period,              exclam,              exclam,               UEF60,       dead_belowdot,              exclam,              U1F62D,              U1F4E3 ],
		[              period,              exclam,              exclam,              period,       dead_belowdot,               UEF7A,          punctspace,              U1F4E2 ]
	}; // UEF60 ' !' spaced out with NNBSP; UEF7A '&#;' U2008 ' ' PUNCTUATION SPACE; U1F62D 😭 LOUDLY CRYING FACE worldwide eighth-most used emoji; U1F4E3 📣 CHEERING MEGAPHONE emoji; U1F4E2 📢 PUBLIC ADDRESS LOUDSPEAKER emoji

	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_GROUP2";
	key <AB09> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[               slash,               colon,               colon,               UEF61,      dead_diaeresis,               U2044,              U1F615,               slash ],
		[               colon,               slash,               colon,               colon,      dead_diaeresis,               U2044,              U1F603,               slash ]
	}; // UEF61 ' :' spaced out with NNBSP; U2044 ⁄ FRACTION SLASH; U1F615 😕 CONFUSED FACE emoji; U1F603 😃 SMILING FACE WITH OPEN MOUTH emoji

	key <AB10> {
		[           backslash,           semicolon,             section,               UEF62,     dead_belowcomma,             section,              U1F494,           backslash ],
		[           semicolon,           backslash,           semicolon,           semicolon,     dead_belowcomma,             section,              U1F609,           backslash ]
	}; // UEF62 ' ;' spaced out with NNBSP; U1F494 💔 BROKEN HEART 16th-ranking emoji; U1F609 😉 WINKING FACE 24th-ranking emoji

	key.type[Group1] = "EIGHT_LEVELS_LEVEL1_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL1_CONTROL";
	key <SPCE> {
		[               space,               space,        nobreakspace,               U202F,               U200B,               UEF6E,               UEF6F,               UEF9B ],
		[               space,               space,               space,               space,               UEF9B,               UEF9F,               UEF9F,               UEF9B ]
	}; // U202F ' ' NARROW NO-BREAK SPACE; U200B '​' ZERO WIDTH SPACE; UEF6E ' ⁠' U0020 U2060 justifying no-break space using WORD JOINER; UEF6F ' ﻿' U0020 UFEFF justifying no-break space using ZERO WIDTH NO-BREAK SPACE; UEF9B '&nbsp;'; UEF9F '&#x202F;' NNBSP

	//
	// Numpad
	//
	// The edit key feature on the numpad is deactivated as outdated, redundant,
	// and wasting positions.
	//
	// On an overlay numpad with Fn held down, the AltFr modifier must be pressed
	// before the Fn key.
	//
	key.type[Group1]= "ONE_LEVEL";
	key.type[Group2]= "ONE_LEVEL";
	key <KPEQ> {
		[            KP_Equal ],
		[            KP_Equal ]
	};

	//                    1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_OPERATOR_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_OPERATOR_GROUP2";
	key <KPDV> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[           KP_Divide,            division,             radical,           parenleft,           KP_Divide,           parenleft,         bracketleft,               U2044 ],
		[           KP_Divide,            division,             radical,           parenleft,           KP_Divide,           parenleft,         bracketleft,               U2044 ]
	}; // U2044 ⁄ FRACTION SLASH

	key <KPMU> {
		[         KP_Multiply,            multiply,         asciicircum,          parenright,         KP_Multiply,          parenright,        bracketright,            NoSymbol ],
		[         KP_Multiply,            multiply,         asciicircum,          parenright,         KP_Multiply,          parenright,        bracketright,            NoSymbol ]
	};

	key <KPSU> {
		[         KP_Subtract,               U2212,               equal,               U2243,         KP_Subtract,         asciicircum,          numbersign,            NoSymbol ],
		[         KP_Subtract,               U2212,               equal,               U2243,         KP_Subtract,         asciicircum,          numbersign,            NoSymbol ]
	}; // U2212 − MINUS SIGN; U2243 ≃ ASYMPTOTICALLY EQUAL

	key <KPAD> {
		[              KP_Add,                plus,           plusminus,               U2248,              KP_Add,          braceright,               equal,            NoSymbol ],
		[              KP_Add,                plus,           plusminus,               U2248,              KP_Add,          braceright,               equal,            NoSymbol ]
	}; // U2248 ≈ ALMOST EQUAL

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DECIMAL_SEPARATOR_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DECIMAL_SEPARATOR_GROUP2";
	key <KPDL> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[          KP_Decimal,               comma,               U202F,        nobreakspace,          KP_Decimal,               comma,               space,        nobreakspace ],
		[          KP_Decimal,               comma,               U202F,        nobreakspace,          KP_Decimal,               comma,               space,        nobreakspace ]
	}; // U202F   NARROW NO-BREAK SPACE

	key <KPPT> {
		[          KP_Decimal,               comma,               U202F,        nobreakspace,          KP_Decimal,               comma,               space,        nobreakspace ],
		[          KP_Decimal,               comma,               U202F,        nobreakspace,          KP_Decimal,               comma,               space,        nobreakspace ]
	}; // U202F   NARROW NO-BREAK SPACE

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP2";
	key <KP0>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		// Category or state:          ModLock off,          ModLock on,       single arrows,       double arrows, black/filled arrows,     triangle-headed,  white/empty arrows
		[                KP_0,               UEF6D,               UEF6D,               U2195,               U21D5,               U2B0D,               U2B65,               U21F3 ],
		[                KP_0,               UEF6D,               UEF6D,               U2195,               U21D5,               U2B0D,               U2B65,               U21F3 ]
	}; // UEF6D '00'; UEF6D '00'; ↕; ⇕; ⬍; ⭥; ⇳

	key <KP1>  {
		[                KP_1,               UEF7D,               UEF7C,               U2199,               U21D9,               U2B0B,               U2B69,               U2B03 ],
		[                KP_1,               UEF7D,               UEF7C,               U2199,               U21D9,               U2B0B,               U2B69,               U2B03 ]
	}; // UEF7D '000'; UEF7C '0x'; ↙; ⇙; ⬋; ⭩; ⬃

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP2";
	key <KP2>  {
		[                KP_2,                   A,                   a,               U2193,               U21D3,               U2B07,               U2B63,               U21E9 ],
		[                KP_2,                   A,                   a,               U2193,               U21D3,               U2B07,               U2B63,               U21E9 ]
	}; // ↓; ⇓; ⬇; ⭣; ⇩

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP2";
	key <KP3>  {
		[                KP_3,                   B,                   b,               U2198,               U21D8,               U2B0A,               U2B68,               U2B02 ],
		[                KP_3,                   B,                   b,               U2198,               U21D8,               U2B0A,               U2B68,               U2B02 ]
	}; // ↘; ⇘; ⬊; ⭨; ⬂

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP2";
	key <KP4>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                KP_4,                   U,               UEF7E,               U2190,               U21D0,               U2B05,               U2B60,               U21E6 ],
		[                KP_4,                   U,               UEF7E,               U2190,               U21D0,               U2B05,               U2B60,               U21E6 ]
	}; // Unicode; '\u{'; ←; ⇐; ⬅; ⭠; ⇦

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP2";
	key <KP5>  {
		[                KP_5,                   C,                   c,               U2194,               U21D4,               U2B0C,               U2B64,               U2B04 ],
		[                KP_5,                   C,                   c,               U2194,               U21D4,               U2B0C,               U2B64,               U2B04 ]
	}; // ↔; ⇔; ⬌; ⭤; ⬄

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP2";
	key <KP6>  {
		[                KP_6,                   D,                   d,               U2192,               U21D2,               U27A1,               U2B62,               U21E8 ],
		[                KP_6,                   D,                   d,               U2192,               U21D2,               U27A1,               U2B62,               U21E8 ]
	}; // →; ⇒; ➡; ⭢; ⇨

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP2";
	key <KP7>  {
		[                KP_7,               U202F,               UEF7F,               U2196,               U21D6,               U2B09,               U2B66,               U2B01 ],
		[                KP_7,               U202F,               UEF7F,               U2196,               U21D6,               U2B09,               U2B66,               U2B01 ]
	}; // NNBSP; '\x{'; ↖; ⇖; ⬉; ⭦; ⬁

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP2";
	key <KP8>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                KP_8,                   E,                   e,               U2191,               U21D1,               U2B06,               U2B61,               U21E7 ],
		[                KP_8,                   E,                   e,               U2191,               U21D1,               U2B06,               U2B61,               U21E7 ]
	}; // ↑; ⇑; ⬆; ⭡; ⇧

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP2";
	key <KP9>  {
		[                KP_9,                   F,                   f,               U2197,               U21D7,               U2B08,               U2B67,               U2B00 ],
		[                KP_9,                   F,                   f,               U2197,               U21D7,               U2B08,               U2B67,               U2B00 ]
	}; // ↗; ⇗; ⬈; ⭧; ⬀

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

	name[Group1] = "Breton and French semiautomatic keyboard layout";
	name[Group2] = "Breton and French semiautomatic keyboard layout";
	// "Breton et français disposition de clavier semi-automatique"
	//
	// The Breton trigraph “cʼh” is particular in that its Unicode conformant
	// representation uses a letter apostrophe.
	// https://github.com/unicode-org/cldr/blob/release-42/common/main/br.xml#L1265
	//
	// "_" U005F and "―" U2015 HORIZONTAL BAR on E08 required as Ñ key have other
	// input methods. Underscore is on level 3 of C09, and in ASCII mode it is on
	// unshifted D12. "―" U2015 is also in group 1 of Ññ, for Breton variants.

	include "dispocla(kbfrFRs)"

	// Variant name.
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFA2 ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFA2 ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_TITLECASE_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                 c_h,                 C_h,            NoSymbol,            NoSymbol,            NoSymbol,                 C_H ],
		[            NoSymbol ]
	}; // cʼh, Cʼh, CʼH

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE08> {
		[              ntilde,              Ntilde ],
		[            NoSymbol ]
	};

};

partial alphanumeric_keys
xkb_symbols "kbbrFRsr" {

	name[Group1] = "Breton and French remapped semiautomatic keyboard layout";
	name[Group2] = "Breton and French remapped semiautomatic keyboard layout";
	// "Breton et français disposition de clavier semi-automatique redisposée"
	//
	// "‑" U2011 NON-BREAKING HYPHEN and "―" U2015 HORIZONTAL BAR on E07 required
	// as Ñ key may be input using group 1 of equal or underscore. "―" U2015 also
	// in group 1 of Ññ, and "‑" U2011 by dead_diaeresis followed by ASCII hyphen.

	include "dispocla(kbfrFRsr)"

	// Variant name.
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFAA ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFAA ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_TITLECASE_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                 c_h,                 C_h,            NoSymbol,            NoSymbol,            NoSymbol,                 C_H ],
		[            NoSymbol ]
	}; // cʼh, Cʼh, CʼH

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE07> {
		[              ntilde,              Ntilde ],
		[            NoSymbol ]
	};

};

partial alphanumeric_keys
xkb_symbols "kbfrPFs" {

	name[Group1] = "French Polynesia semiautomatic keyboard layout";
	name[Group2] = "French Polynesia semiautomatic keyboard layout";
	// "Polynésie française disposition de clavier semi-automatique"
	//
	// The grave accent is used in Polynesia alongside the macron, but while the
	// acute accent is not, it is part of the quotation mark input method and so
	// cannot be replaced with the macron dead key either. As a consequence, E08
	// is repurposed like on African and Breton variants, the better as this has
	// the upside of freeing up a live key position for Polynesian ʻeta.
	//
	// "―" U2015 HORIZONTAL BAR on shifted E08 is in group 1 of U02BB ʻeta, while
	// group 1 of dead_macron has U2011 NON-BREAKING HYPHEN with respect to the
	// Polynesian remapped variant.

	include "dispocla(kbfrFRs)"

	// Variant name.
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFA3 ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFA3 ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE08> {
		[         dead_macron,               U02BB ],
		[            NoSymbol ]
	};// Tārava, tāumi; U02BB ʻeta

};

partial alphanumeric_keys
xkb_symbols "kbfrPFsr" {

	name[Group1] = "French Polynesia remapped semiautomatic keyboard layout";
	name[Group2] = "French Polynesia remapped semiautomatic keyboard layout";
	// "Polynésie française disposition de clavier semi-automatique redisposée"
	//
	// "‑" U2011 NON-BREAKING HYPHEN and "―" U2015 HORIZONTAL BAR on E07 required
	// as Ñ key may be input using group 1 of equal or underscore. "―" U2015 also
	// in group 1 of Ññ, and "‑" U2011 by dead_diaeresis followed by ASCII hyphen.

	include "dispocla(kbfrFRsr)"

	// Variant name.
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFAB ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFAB ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE07> {
		[         dead_macron,               U02BB ],
		[            NoSymbol ]
	};// Tārava, tāumi; U02BB ʻeta

};

partial alphanumeric_keys
xkb_symbols "kbfrAFs" {

	name[Group1] = "Francophone Africa semiautomatic keyboard layout";
	name[Group2] = "Francophone Africa semiautomatic keyboard layout";
	// "Afrique francophone disposition de clavier semi-automatique"
	//
	// "_" U005F and "―" U2015 HORIZONTAL BAR on E08 required as Ɔ key have other
	// input methods. Underscore is on level 3 of C09, and in ASCII mode it is on
	// unshifted D12. "―" U2015 is also in group 1 of Ɔɔ, for African variants.

	include "dispocla(kbfrFRs)"

	// Variant name.
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFA4 ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFA4 ]
	};

	key.type[Group1] = "EIGHT_LEVELS_AE01_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[               U025B,               U0190 ],
		[            NoSymbol ]
	}; // ɛ, Ɛ

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE08> {
		[               U0254,               U0186 ],
		[            NoSymbol ]
	}; // ɔ, Ɔ

};

partial alphanumeric_keys
xkb_symbols "kbfrAFsr" {

	name[Group1] = "Francophone Africa remapped semiautomatic keyboard layout";
	name[Group2] = "Francophone Africa remapped semiautomatic keyboard layout";
	// "Afrique francophone disposition de clavier semi-automatique redisposée"
	//
	// "‑" U2011 NON-BREAKING HYPHEN and "―" U2015 HORIZONTAL BAR on E07 required
	// as Ɔ key may be input using group 1 of equal or underscore. "―" U2015 also
	// in group 1 of Ɔɔ, and "‑" U2011 by dead_diaeresis followed by ASCII hyphen.

	include "dispocla(kbfrFRsr)"

	// Variant name.
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFAC ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFAC ]
	};

	key.type[Group1] = "EIGHT_LEVELS_AE01_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[               U025B,               U0190 ],
		[            NoSymbol ]
	}; // ɛ, Ɛ

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE07> {
		[               U0254,               U0186 ],
		[            NoSymbol ]
	}; // ɔ, Ɔ

};

partial alphanumeric_keys
xkb_symbols "kbfrBEs" {

	name[Group1] = "French Belgium semiautomatic keyboard layout";
	name[Group2] = "French Belgium semiautomatic keyboard layout";
	// "Français Belgique disposition de clavier semi-automatique"
	//
	// The other divergent keys are equalized with France’s AZERTY because
	// the downside of keeping them the Belgian way is detrimental to consistency
	// and would heavily impact user experience far beyond the small benefit of
	// staying a bit more familiar.
	//
	// The Belgian layout variant comes without its remapped variant because
	// the point in having a Belgian variant is a reasonable amount of backwards
	// compatibility with the Belgian AZERTY, and remapping defeats this point.

	include "dispocla(kbfrFRs)"

	// Variant name.
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFA5 ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFA5 ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE06> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[             section ],
		[            NoSymbol ]
	};// Leave NON-BREAKING HYPHEN here. Greek_horizbar is in group 1 of en and em dashes.

	key <AE08> {
		[               minus,          underscore ],
		[            NoSymbol ]
	};// Rather than NON-BREAKING HYPHEN.

};

partial alphanumeric_keys
xkb_symbols "kbfrFRsr" {

	name[Group1] = "French France remapped semiautomatic keyboard layout";
	name[Group2] = "French France remapped semiautomatic keyboard layout";
	// "Français France disposition de clavier semi-automatique redisposée"

	include "dispocla(kbfrFRs)"

	// This layout is remapped as of letter input, to extend ergonomy, already
	// encompassing symbols and punctuation as a baseline service.
	//
	// I and O are switched alongside D and L to improve the -élé- trigram, and
	// because 5.754 French words contain 'ion', and
	// 121 French words contain 'noi' (total: 5.875).
	// But only 280 French words contain 'oin', and
	// 110 French words contain 'nio' (total: 390).
	// Courtesy La Fée des Lettres https://www.motsavec.com/
	//
	// Hybrid variants were also included until 2023-08-18 but were dropped as
	// pointless since keys W, X, C, V, B and even Z, Y, S are unremapped, for
	// the sake of frequent keyboard shortcuts, without substantially cutting
	// back on letter ergonomy. Moreover, the hybrid variants were truncated,
	// since the layout uses the full set of 8 indices, and shortcut remapping
	// requires one out of them.

	// Variant name.
	key.type[Group1]= "EIGHT_LEVEL";
	key.type[Group2]= "EIGHT_LEVEL";
	key <TLDE> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFA9 ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFA9 ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key <AE02> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[              agrave,              Agrave ],
		[            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";

	key <AE04> {
		[          dead_acute ],
		[            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key <AE06> {
		[              ugrave,              Ugrave ],
		[            NoSymbol ]
	}; // Ugrave for consistency since U2011 is on E07 for accessibility while underscore is on D12 when ModLock is on.

	key.type[Group1] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE07> {
		[               U2011,      Greek_horizbar ],
		[            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key <AE08> {
		[              egrave,              Egrave ],
		[            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_AE10_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE10> {
		[              eacute,              Eacute ],
		[            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC_TITLECASE";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC_TITLECASE";
	key <AD01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   q,                   Q,            NoSymbol,            NoSymbol,            NoSymbol,              U107A5 ],
		[                   q,                   Q,            NoSymbol,            NoSymbol,            NoSymbol,              U107A5 ]
	}; // superscript small q

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key <AD03> {
		[                   j,                   J,            NoSymbol,            NoSymbol,            NoSymbol,               U02B2 ],
		[                   j,                   J,            NoSymbol,            NoSymbol,            NoSymbol,               U02B2 ]
	}; // superscript small j

	key <AD04> {
		[                   f,                   F,            NoSymbol,            NoSymbol,            NoSymbol,               U1DA0 ],
		[                   f,                   F,            NoSymbol,            NoSymbol,            NoSymbol,               U1DA0 ]
	}; // superscript small f

	key <AD05> {
		[                   g,                   G,            NoSymbol,            NoSymbol,            NoSymbol,               U1D4D ],
		[                   g,                   G,            NoSymbol,            NoSymbol,            NoSymbol,               U1D4D ]
	}; // superscript small g

	key <AD07> {
		[                   m,                   M,            NoSymbol,            NoSymbol,            NoSymbol,               U1D50 ],
		[                   m,                   M,            NoSymbol,            NoSymbol,            NoSymbol,               U1D50 ]
	}; // superscript small m

	key <AD08> {
		[                   l,                   L,            NoSymbol,            NoSymbol,            NoSymbol,               U02E1 ],
		[                   l,                   L,            NoSymbol,            NoSymbol,            NoSymbol,               U02E1 ]
	}; // superscript small l

	key <AD09> {
		[                   d,                   D,            NoSymbol,            NoSymbol,            NoSymbol,               U1D48 ],
		[                   d,                   D,            NoSymbol,            NoSymbol,            NoSymbol,               U1D48 ]
	}; // superscript small d

	key <AD10> {
		[                   k,                   K,            NoSymbol,            NoSymbol,            NoSymbol,               U1D4F ],
		[                   k,                   K,            NoSymbol,            NoSymbol,            NoSymbol,               U1D4F ]
	}; // superscript small k

	key.type[Group1] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key <AD12> {
		[               UEFD0,            NoSymbol,               UEFD0 ],
		[          underscore,            NoSymbol,               UEFD0 ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key <AC01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   a,                   A,            NoSymbol,            NoSymbol,            NoSymbol,               U1D43 ],
		[                   a,                   A,            NoSymbol,            NoSymbol,            NoSymbol,               U1D43 ]
	}; // superscript small a

	key <AC03> {
		[                   e,                   E,            NoSymbol,            NoSymbol,            NoSymbol,               U1D49 ],
		[                   e,                   E,            NoSymbol,            NoSymbol,            NoSymbol,               U1D49 ]
	}; // superscript small e

	key <AC04> {
		[                   r,                   R,            NoSymbol,            NoSymbol,            NoSymbol,               U02B3 ],
		[                   r,                   R,            NoSymbol,            NoSymbol,            NoSymbol,               U02B3 ]
	}; // superscript small r

	key <AC05> {
		[                   t,                   T,            NoSymbol,            NoSymbol,            NoSymbol,               U1D57 ],
		[                   t,                   T,            NoSymbol,            NoSymbol,            NoSymbol,               U1D57 ]
	}; // superscript small t

	key <AC06> {
		[                   u,                   U,            NoSymbol,            NoSymbol,            NoSymbol,               U1D58 ],
		[                   u,                   U,            NoSymbol,            NoSymbol,            NoSymbol,               U1D58 ]
	}; // superscript small u

	key <AC07> {
		[                   n,                   N,            NoSymbol,            NoSymbol,            NoSymbol,               U207F ],
		[                   n,                   N,            NoSymbol,            NoSymbol,            NoSymbol,               U207F ]
	}; // superscript small n

	key <AC08> {
		[                   o,                   O,            NoSymbol,            NoSymbol,            NoSymbol,               U1D52 ],
		[                   o,                   O,            NoSymbol,            NoSymbol,            NoSymbol,               U1D52 ]
	}; // superscript small o

	key <AC09> {
		[                   i,                   I,            NoSymbol,            NoSymbol,            NoSymbol,               U2071 ],
		[                   i,                   I,            NoSymbol,            NoSymbol,            NoSymbol,               U2071 ]
	}; // superscript small i

	key <AC10> {
		[                   p,                   P,            NoSymbol,            NoSymbol,            NoSymbol,               U1D56 ],
		[                   p,                   P,            NoSymbol,            NoSymbol,            NoSymbol,               U1D56 ]
	}; // superscript small p

	key.type[Group1] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key <AC11> {
		[rightsinglequotemark ],
		[            NoSymbol ]
	};

	key <BKSL> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[               minus,            NoSymbol,           Multi_key ],
		[               minus,            NoSymbol,           Multi_key ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC";
	key <AB06> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   h,                   H,            NoSymbol,            NoSymbol,            NoSymbol,                U02B0 ],
		[                   h,                   H,            NoSymbol,            NoSymbol,            NoSymbol,                U02B0 ]
	}; // U02B0 ʰ MODIFIER LETTER SMALL H

};

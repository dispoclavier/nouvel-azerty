//                       Date: 2024-10-24T2306+0200
//        Operating file name: dispocla
//                   Encoding: UTF-8
//                       Type: text/XKB configuration
//                   Language: C-like
//                Description: XKB key allocation tables
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
//
//                             2. In /usr/share/X11/xkb/rules/evdev
//                                comment out the rule:
//                                    *		*		=	+%l[2]%(v[2]):2
//                                See ## XKB layout group 2
//
//                             3. In /usr/share/X11/xkb/rules/evdev.xml
//                                add the lines enclosed in the file
//                                    evdev-additions.xml
//                                before the `</layoutList>` closing tag.
//
//                             4. In the locale and language settings make sure
//                                that the input method is XIM, or use the command
//                                    im-config -n xim
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
// # Standards compliance
//
// This file configures a level 5 modifier key called "AltFr", located lefthand
// either on B00 or on C00 (CapsLock), and a group 2 toggle called "ModLock" on
// E00. This file also allocates full sets of eight levels on each graphic key.
// Neither of these are covered by ISO/IEC 9995. Despite being international by
// design, this standard does not cover Japanese keyboards either. In fact, the
// ISO/IEC keyboard standard only covers low-end Western keyboard layouts.
//
// Software tools like keyboard layouts do not need to be standardized prior to
// deployment, and features are not necessarily printed on keycaps. The role of
// standards is to serve the users, not to dominate users by curtailing the use
// and compromising the usability of work tools.
//
//
// # Configuration
//
// ## XKB layout group 2
//
// Caps Lock is dedicated to uppercase. The extra toggle required for digits,
// as a consequence, is called "ModLock", short for "Mode Lock". This second,
// or additional, graphic toggle, as ModLock may be referred to, switches the
// keyboard between default mode or French mode for instance, and ASCII mode.
// It affects non-alphabetic keys only, because alphabetic keys should not be
// affected by ModLock, with respect to cross-platform compatibility, since a
// similar functionality on Windows is Caps Lock insensitive.
//
// A second graphic toggle is required to toggle the row E keys between letters
// and digits, independently of the CapsLock toggle, that is set to also affect
// the diacriticized letters, most of which are on row E too. The second toggle
// also maintains level 1 access for the ASCII single and double quotes and the
// ASCII hyphen and underscore, all of which are on row E level 1 of the French
// AZERTY. Additionally, ASCII mode has level 2 positions for one set of paired
// punctuation, used for one out of the two level-3 right-hand pairs. Frequency
// is the criterion for picking the braces rather than the brackets. Plus, this
// matches US-QWERTY.
// http://xahlee.info/comp/computer_language_char_distribution.html
//
// ASCII mode is not limited to ASCII, as row E and keys D12, C11, C12 output
// subscript digits, signs and punctuation not there in default mode, where
// keypad emoji are easier accessed instead. ASCII symbols printed on these
// keys are also accessible in default mode on level 4 as a fallback commodity,
// but not in ASCII mode.
//
// The key used for this additional graphic toggle is TLDE, consistently with
// Japanese keyboards, where E00 is the full-width/half-width toggle.
// https://web.stanford.edu/class/cs140/projects/pintos/specs/kbd/scancodes-7.html
// https://w3c.github.io/uievents-code/#code-Backquote
//
// This digit toggle cannot be implemented by repurposing the NumLock toggle as
// in types EIGHT_LEVEL_LEVEL_FIVE_LOCK, EIGHT_LEVEL_ALPHABETIC_LEVEL_FIVE_LOCK
// commented out in xkb/types/level5(56, 118) back in 2016 consistently, later
// causing a bug in xkbcomp when these were uncommented again. Repurposing the
// NumLock toggle is prone to causing issues on compact keyboards with overlay
// numpad turned on and off by Num Lock.
//
// The working solution relies on ISO_First_Group and ISO_Last_Group for the
// purpose of switching between two layout groups. ModLock is implemented as
// a group toggle between live key layout group 1 and live key layout group 2.
//
// This however is compromised by a rule in /usr/share/X11/xkb/rules/evdev:
//
//       *		*		=	+%l[2]%(v[2]):2
//
// This rule causes the second group to get overridden by a default layout. The
// fix is to comment this rule out, although another fix seems to be working as
// well, according to a thread on Unix & Linux StackExchange, where this issue
// has been discussed and solved in 2018.
// https://unix.stackexchange.com/questions/419042/xkb-modify-layout-to-multi-group-with-mode-switch/420126
// https://unix.stackexchange.com/a/420126
//
// However, so far, none of the following rules works:
//
//     As solved on the forum:  `*		dispocla	=	+dispocla`
//     Inferred from context:   `*		dispocla	=	+dispocla%(v[2]):2`
//     As in other context:     `*		kbfrFRsr	=	+dispocla(kbfrFRsr):2`
//
//
// ## X Window Input Method
//
// Multi character output, including composed letters as required for output by
// dead keys, requires XIM. These semi-automatic keyboard layouts output multi-
// character sequences, such as spaced punctuation and the Breton trigraph, on
// live keys too and can only work when XIM has been activated, given that iBus
// may still be set as the default.
// See Compose.yml ### Multicharacter strings for live keys
//
// The X Window Input Method may be activated by command line:
//
//         im-config -n xim
//
//
// # Documentation
//
// ## Level 5 modifier
//
// The ISO/IEC 9995 standard does not support the level 5 modifier, because it
// is limited to low-performance Western keyboard layouts and excludes all the
// features found on Japanese keyboards such as the halfwidth/fullwidth toggle
// (hankaku/zenkaku kanji) on B00, the left and the right Thumb Shift modifiers
// (Oyayubi Shifuto). ISO does not even provide numbers for these, calling the
// spacebar A03
// https://web.stanford.edu/class/cs140/projects/pintos/specs/kbd/scancodes-7.html
//
// A Windows equivalent of the XKB level 5 modifier key is used in Jan James’
// implementation of a governmental avatar (by federal Government and industry
// representatives) of the Canadian multilingual standard keyboard layout by
// Alain LaBonté (initial design). Jan James was tasked with implementing the
// Canadian multilingual standard keyboard layout for Microsoft, transforming
// the group selector into a level 5 modifier key, although initially,
// CAN/CSA Z243.200-92 was meant to comply with ISO/IEC 9995-2. But that is not
// how things are expected to work on properly designed keyboard layouts.
//
// Instead, keyboard layouts using a scheme like in this file have a level 5
// modifier located lefthand so as to be usable for an extended numpad below
// the 7 8 9 0 keys, where embedded numpads on compact keyboards are located,
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
// The proposed symbol is "⟰" U27F0 UPWARDS QUADRUPLE ARROW, by lack of a
// quintuple arrow and with the rationale that this key increments the level
// index by 4, on the background of the lack of a dedicated level-5 modifier
// key symbol in ISO/IEC 9995-7, due to ISO/IEC 9995 being limited to Western
// keyboards without support for Japanese modifiers and toggles. A limitation
// that subsequently backfired by impairing keyboard layout design efforts in
// Canada, France and other countries.
//
//
// ## French-style punctuation spacing
//
// These layouts support output of polygrams after single keystrokes, as needed
// when spacing out punctuation marks in one go, rather than typing the space
// separately, while supporting the same punctuation marks unspaced too, and
// facilitating spacing inhibition as required in runs of exclamation marks and
// question marks. The user is always in control, as opposed to full automation
// where runs of question/exclamation marks are unspaced, but turning spacing
// off entirely requires switching keyboard layouts. Semi-automation makes for
// all-in-one keyboard layouts, ideally with a level-5 modifier like AltFr.
//
//
// ### Requirements
//
// The requirements about spacing out big punctuation marks in French text
// depend on the sublocale, the typesetting school and, for some sublocales,
// software support.
//
// French new-school rules require a no-break thin space before ? ! : ; » ›,
// and after « ‹. These rules are followed in print editions of newspapers,
// namely Le Monde, without being well documented, so as to prevent conflicts
// with the old school whose specification is the verbatim text of the National
// Printing Office’s style guide “Lexique des règles typographiques en usage à
// l’Imprimerie nationale”, stipulating a justifying no-break space before the
// colon and inside the “guillemet” double angle quotation marks. In its eighth
// edition published in March 2017, that is a reprint of its July 2002 edition,
// the colon is indeed spaced out as specified, while the angle quotation marks
// are spaced out the new-school way, with the same thin space used before the
// other three big punctuation marks question mark, exclamation mark, and semi-
// colon. The verbatim text was not synced with the evolving usage, supposedly
// with respect to the user community, tracking changes, and possibly frowning
// upon this one, because guillemets spaced-out equally on both sides are often
// seen in old prints. The new usage of the Imprimerie Nationale as of spacing
// out guillemets using thin space may be considered as pertaining to a yet to
// be defined intermediate typesetting school. French new school typesetting is
// documented on the Mac Generation forum.
// https://forums.macg.co/threads/typo-caracteres-capitales-accentues.25739/page-5#post-3151119
//
// Belgium applies the French Imprimerie Nationale style guide, or NBN Z01-002,
// specifying that the punctuation marks ? ! : ; must not be spaced out, while
// not mentioning guillemets or angle quotation marks.
// https://cuy.be/orthotypo/NORMES_D.pdf#page=12
//
// Francophone Canada applies French old school typesetting, but suppresses the
// thin space if it is unavailable, in that the software does not support it by
// inserting the no-break thin space automatically, since the Canadian keyboard
// layout standard was designed and released in 1992, before the required space
// character U202F NBTSP was encoded.
// https://vitrinelinguistique.oqlf.gouv.qc.ca/index.php?id=22039
// https://vitrinelinguistique.oqlf.gouv.qc.ca/22039/la-typographie/espacement/espacement-avant-et-apres-les-signes-de-ponctuation-et-les-symboles
// https://web.archive.org/web/20230326022601/https://www.tresor.gouv.qc.ca/ressources-informationnelles/architecture-dentreprise-gouvernementale/standards-et-normes/standard-sur-le-clavier-quebecois-sgqri-001/standard-sur-le-clavier-quebecois-sgqri-001-foire-aux-questions/
// https://web.archive.org/web/20230325043926/http://www.tresor.gouv.qc.ca:80/ressources-informationnelles/architecture-dentreprise-gouvernementale/standards-et-normes/standard-sur-le-clavier-quebecois-sgqri-001/standard-sur-le-clavier-quebecois-sgqri-001-le-clavier-quebecois/
// https://web.archive.org/web/20230326022601/https://www.tresor.gouv.qc.ca/ressources-informationnelles/architecture-dentreprise-gouvernementale/standards-et-normes/standard-sur-le-clavier-quebecois-sgqri-001/standard-sur-le-clavier-quebecois-sgqri-001-foire-aux-questions/
// https://web.archive.org/web/20230220160241/https://www.tresor.gouv.qc.ca/fileadmin/PDF/ressources_informationnelles/standard_clavier_quebecois/sgqri001.pdf
// https://web.archive.org/web/20230903200943/https://www.tresor.gouv.qc.ca/ressources-informationnelles/architecture-dentreprise-gouvernementale/standards-et-normes/standard-sur-le-clavier-quebecois-sgqri-001/standard-sur-le-clavier-quebecois-sgqri-001-caracteres/
// https://web.archive.org/web/20220520225412/https://www.tresor.gouv.qc.ca/fileadmin/PDF/ressources_informationnelles/illustrations_claviers/clavier_labonte_1.jpg
// https://web.archive.org/web/20190403184009/https://www.tresor.gouv.qc.ca/fileadmin/PDF/ressources_informationnelles/illustrations_claviers/clavier_labonte_2_noir_blanc.jpg
// https://web.archive.org/web/20190404014311/https://www.tresor.gouv.qc.ca/fileadmin/PDF/ressources_informationnelles/illustrations_claviers/clavier_labonte_3_Macintosh.jpg
// https://web.archive.org/web/20190403184112/https://www.tresor.gouv.qc.ca/fileadmin/PDF/ressources_informationnelles/illustrations_claviers/module_alphanumerique_4.jpg
// https://kbdlayout.info/KBDCAN/
// https://kbdlayout.info/KBDCAN/download/klc
//
// Francophone Switzerland changed in 2015 from not spacing punctuation out to
// following France (reference missing). Franck Pastor reported on 2009-05-19
// that no-break thin space was already used also before colon and inside anqle
// quotation marks.
// http://www.cuk.ch/articles/4116/
//
// In 2020, the University of Geneva has a rule about not spacing out ?!:;«»,
// but this rule is restricted to electronic usage, as which were considered
// website publishing and email text body. Thus the spacing prohibition targets
// plain text, where NO-BREAK SPACE is unstable and may be replaced with SPACE
// in mail composers affected by a common bug, and HTML, where NO-BREAK SPACE
// is justifying, unlike it is in word processors other than Word 2013. As of
// NARROW NO-BREAK SPACE, it is not mentioned in this rule, but print and PDF
// are not mentioned either.
// https://www.unige.ch/communication/files/7815/9180/2109/ReglesTypographiques-UNIGE-2020.pdf#page=6
//
//
// ###  Issues affecting French Old School typesetting
//
// Spacing out colon and guillemets with NO-BREAK SPACE does not work well
// because:
//
// 1  NO-BREAK SPACE (NBSP) is defined as justifying in Unicode, followed by
//    HTML, while in word processors (except MS Word 2013) it is tailored as
//    fixed-width. As a result, the colon is not spaced out the Old School way
//    in word processors, while on the web, question and exclamation mark and
//    semicolon are neither.
// 2  MS Word replaces NBSP with SPACE when copy-pasting to plain text. Web
//    browsers like Chrome and Firefox do the same.
// 3  NBSP behaves like (or is replaced with) normal space in e-mail composers
//    and in web forms in many browsers.
//
//
// ###  French New School typesetting
//
// French new-school typesetting spaces out all big punctuation characters with
// the same no-break thin space both for ASCII ?!; and even for colon, and for
// double angle quotation marks, as well as for single angle quotation marks.
// Spacing out colon the same way is particular to new-school, while making an
// exception for colon and spacing out guillemets the new-school way makes for
// a moderate old-school as exemplified in the French National Printing Office
// style guide, where colon is preceded by a justifying NO-BREAK SPACE. This is
// about the practice, while the rules set apart the angle quotation marks too.
//
// The International System of Measures and Units (SI) from the BIPM recommends
// using a no-break thin space as a group separator in numbers. It is followed
// by many locales including fr_FR. Also, TeX supports it by the means of the
// `\,` command. Consistently with legacy typographic craftmanship, TeX is well
// aware that the thin space is no-break, and as a pre-Unicode environment, TeX
// presumably informed the seminal Unicode Standard, designed to maintain full
// backwards compatibility.
//
// All layouts in this configuration file support mainstream practice, as used
// in the French graphic industry, also referred to as French New School.
// https://forums.macg.co/threads/typo-caracteres-capitales-accentues.25739/page-5#post-3151119
//
// The interoperable representation of French New School typesetting uses
// NARROW NO-BREAK SPACE with all punctuation characters that use to be spaced
// out, not only semicolon, exclamation mark and question mark as explicitly
// stated in the verbatim text of the 2002 edition, March 2017 reprint, of the
// Imprimerie nationale style guide _Lexique des règles typographiques en usage
// à l’Imprimerie nationale_, ISBN 9782743304829, but also the guillemets the
// way they are actually typeset, plus the colon.
//
// Single angle quotation marks are spaced out like double angle quotation
// marks.
// https://vitrinelinguistique.oqlf.gouv.qc.ca/index.php?id=22039
//
//
// ###  Unicode support for interoperable French
//
// In Unicode, a no-break thin space is encoded only since version 3.0 released
// in 1999, when U+202F NARROW NO-BREAK SPACE was encoded for Mongol script but
// with the Script property Common and in the General Punctuation block. It was
// not so earlier, because U+2009 THIN SPACE was not assigned the line breaking
// class GL. Another halfways suitable space character, that could have been an
// acceptable workaround to be repurposed for spacing out the eight punctuation
// marks, U+2008 PUNCTUATION SPACE, was not declared GL either, despite it is a
// counterpart of U+2007 FIGURE SPACE for comma and period, and as such, should
// have been assigned the same line breaking class, if any, although it did not
// matter, since both are meant to be used in leading position, before numbers,
// for indentation when typesetting old-style tables, not at line end where the
// FIGURE SPACE’s line breaking class GL would make sense. Instead, the Unicode
// Core Specification (1.0 and) 2.0 claims: “U+2007 FIGURE SPACE is intended to
// be used as a thousands separator in cases where countries use space to
// separate groups of digits. Typically it has a fixed width the same size as a
// digit in a particular font.”
// https://www.unicode.org/L2/L2020/20008-core-text.pdf#page=7
//
// This flaw was introduced in the Unicode Standard on purpose. Intentionality
// is easy to assess in this case thanks to the typographic space range keeping
// original code points as designed. The typographic space range U+2000..U+200A
// was set up to include the two widest spaces both in breaking and in no-break
// variants: U+2000, U+2001 versus U+2002, U+2003, making a clever use of a set
// of aliases provided in Unicode’s template, the Xerox Character Code Standard
// XCCS, while narrower spaces (U+2004..U+200A) were to be no-break throughout,
// consistently with Donald Knuth’s TeX, designed to support most features used
// in traditional typesetting. Instead only FIGURE SPACE was given the no-break
// property, and the widest spaces ended up as two pairs of duplicates, finally
// declared to be canonically equivalent.
//
// The initial design lacks official documentation because it was altered in an
// early stage.
//
// That is how French and 50+ other locales using space to separate groups were
// unsupported by the Unicode Standard for almost one decade.
//
// Ultimately, a no-break thin space has been encoded for Mongol script in 1999
// for Unicode version 3.0. In Mongol script, punctuation marks are spaced out,
// much like in French, except that fonts for Mongol have built-in spacing next
// to punctuation characters.
//
// Even after encoding NARROW NO-BREAK SPACE, the need of no-break thin space
// in representing French remained unaddressed until UAX #14 Unicode Line
// Breaking Algorithm started mentioning it in 2007, and the Core Specification
// in 2014 declaring U+202F NARROW NO-BREAK SPACE as representing “the space
// next to certain punctuation characters in French text.” The delay was useful
// to account for lagging font support.
// https://www.unicode.org/L2/L2007/07209-whistler-uax14.txt
//
// A competing workaround used THIN SPACE followed by then-standard line break
// preventer U+FEFF ZERO WIDTH NO-BREAK SPACE; since 2002, U+2060 WORD JOINER.
// Still in practice, NARROW NO-BREAK SPACE was quickly adopted by the French
// typesetting industry because it caters for a longstanding demand.
//
// The Common Locale Data Repository (CLDR) migrated the group separator space
// from U+00A0 NO-BREAK SPACE to U+202F NARROW NO-BREAK SPACE in version 34,
// released in 2018. This migration first benefitted the French main locale and
// its heirs, but not fr-CA. It is likely to be extended soon, as suggested on
// 2019-01-11 and on 2021-03-12.
// https://unicode-org.atlassian.net/browse/CLDR-11217
// https://unicode-org.atlassian.net/browse/CLDR-11423?focusedCommentId=160553
//
// In 2019, Unicode had assigned NNBSP the Script_Extensions property value
// {Latn Mong} tending to discourage other scripts from using the correct group
// separator space.
//
// Further reading:
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
// postprocessing or on hybrid input methods involving word processors.
//
// Word processing software caters for punctuation spacing by automatically
// inserting NBSP when a colon, a semicolon, a question or exclamation mark
// is typed, with or without a preceding breaking space, and by replacing U0022
// QUOTATION MARK with the appropriate, spaced-out angle quotation mark.
// But the NBSP used is not preferred, because it is justifying (and too wide).
// Therefore NBSP is tailored as fixed-width as long as the text is displayed
// in the software or exported to PDF, but not after copy-pasting in a browser.
//
// Users are divided over whether it is acceptable to input spaces separately.
// While spacing out punctuation is generally considered mandatory in French,
// doing so manually is seen as wasteful and inefficient by part of the users.
// According to mainstream demand fostered by word processing autocorrection,
// users should not be required to input more than a normal space around
// punctuation characters, ideally less. This requirement can be met in 2 ways:
//
// a. Synergistic punctuation spacing.
//    Punctuation characters and no-break space are mapped on the same level.
//    That can be level 2, level 3 or level 5. Some layouts feature angle
//    quotation marks and NBSP on level 3, while 2-parts ASCII punctuation
//    (?!:;) is mostly on level 1 or on level 2, where the space bar yields
//    breaking space except on the French BÉPO layout where 2-parts punctuation
//    is on level 2 along with no-break thin space NNBSP on the space bar as of
//    v1.1; NBSP in v1.0.
//    https://bepo.fr/wiki/Version_1.1rc1/Touches_vives/Espaces
//
// b. Semi-automatic punctuation spacing.
//    Punctuation characters are mapped with NNBSP as polygrams on single key
//    positions along with the same punctuation characters mapped in isolation
//    on the same keys on another level. Requirements:
//
//    1. Spaced-out and unspaced punctuation has the same ease of access.
//    2. The ModLock toggle, now mapped on key E00 instead of superscript 2,
//       toggles the spaced-out punctuation character positions to unspaced.
//    3. Question and exclamation mark used in repetition, first spaced out,
//       then unspaced, require spacing inhibition by additionally pressing
//       down a second modifier (AltFr).
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
// https://next.ink/3020/clavier-azerty-ldlc-notre-bilan-apres-mois-dutilisation/#comment-67038
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
// opposed to polygram output. They have been discontinued on 2021-01-27.
// But ultimately, since version 4.0.0 (2024-08-11), unspaced punctuation is
// in synergy with the no-break thin space without requiring extra variants.
//
// These keyboard layouts support both manual and semiautomatic punctuation
// spacing, where the spaced-out punctuation characters and the unspaced-out
// ones are on the same key with different modifiers: Shift for spaced-out,
// AltFr for unspaced-out while the spacebar yields the no-break thin space.
// Additionally, Shift + AltFr yields unspaced-out punctuation marks `?!:;`,
// with the rationale that after typing a spaced-out punctuation and while the
// little finger is still on Shift, the ring finger can easily press AltFr, so
// as to inhibit spacing before an additional question or exclamation mark.
//
// Advantages of Shift over AltFr for spaced-out punctuation characters:
//
//   1  Synergy between spaced-out punctuation and normal space;
//   2  Synergy between unspaced punctuation and no-break thin space;
//   3  Synergy between unspaced punctuation and extended numpad digits;
//   4  UX consistency between legacy and new as of the question mark;
//   5  Cross-mode UX consistency between writing French and programming;
//   6  Consistency between spacing and modifier key accessibility.
//
// Advantages of AltFr over Shift for spaced-out punctuation characters:
//
//   1  No inadvertent insertion of NNBSP while typing unspaced punctuation;
//   2  Consistency with the key name 'AltFr' as 'Alternate French' modifier;
//   3  Shift is often considered too far left, while AltFr is better placed;
//   4  Stability of the question mark as the only unmoved big punctuation;
//   5  Minimal cross-mode user experience inconsistency, as Shift is stable;
//   6  All strings involving no-break thin space have the same modifier key;
//
// The latter set of “advantages” fueled a design error, fixed only in v4.0.0.
// See Compose.yml  Acknowledgements
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
// much like quotedbl, on E05 and C11, respectively, and ASCII grave has easy
// level 3 access on B06 in both modes, plus level 3 access on C11 in ASCII
// mode only.
// See Compose.yml  Acknowledgements
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
// ampersand, less and greater, the latter two on level 7 (AltGr + AltFr).
//
//
// ## Keyboard levels and groups
//
// While “keyboard level” refers to user-perceived modifier key combinations,
// the 1-based array indices used in the allocation tables are named "Level1"
// through "Level8" in the key type definitions. The numerous key types help
// cope with the limitation to 8 indices in XKB allocation tables. The number
// of keyboard levels in user experience may be up to 8 using three modifiers
// (Shift, AltGr, AltFr). Since the ModLock toggle is a group toggle, it does
// not require any additional indices, but Caps Lock and Control may do so.
//
// The keysyms enclosed in brackets inside the braces define a group as used
// in XKB. In this file, each key has 2 groups. The first group is the default
// mode layout, and the second group is the ASCII mode layout. Each group has
// two names. The name in brackets may be called the identifier, and the name
// in double quotes is likely the descriptor, without any constraint as of
// uniqueness, although choosing unique descriptors makes for a better UX.
// https://www.charvolant.org/doug/xkb/html/node5.html#Sec:Symbols
//
//     The name[Group1]= "US/ASCII"; statement gives a name to one of the
//     keyboard groups. Other groups can be specified by using the same syntax
//     but with a different group name.
//
//     […]
//
//     Inside the braces, it is possible to use the syntax
//     group[groupname] = [ symbol, symbol] instead, with the various
//     statements being separated by commas.
//
// The term "group" is also used for dead-key-accessed groups, the most
// prominent of which are accessed through the "group dead key", that also
// supports multiple presses. As a consequence, the group number matches the
// number of group dead key presses, or the digit entered after one
// group dead key press. Support for multiple group dead key presses
// goes at least up to 4. That is why groups are a 0-based array of 13 groups,
// where index 0 is the default layout. Digits 0..2 are used for groups 10..12.
//
// Given access to uppercase must be intuitive, digits are mapped on level 3.
//

default partial alphanumeric_keys modifier_keys keypad_keys
xkb_symbols "kbfrFRs" {

	name[Group1] = "French France semiautomatic keyboard layout";
	name[Group2] = "French France semiautomatic keyboard layout, ASCII mode";
	// "Français France disposition de clavier semi-automatique"

	// Includes files from the symbols/ directory.
	include "pc(pc105)"   // Basic functionality.
	include "inet(evdev)" // Easy access and internet keys.

	//
	// ## New 'AltFr' modifier key
	//
	// See ## Level 5 modifier
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

	// ## Regular level 3 (AltGr) modifier key

	include "level3(ralt_switch)"

	key.type[Group1]= "EIGHT_LEVELS_BASIC";
	key.type[Group2]= "EIGHT_LEVELS_BASIC";
	key <RALT> {
		[ ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift ],
		[ ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift, ISO_Level3_Shift ]
	};

	//
	// ## ASCII mode lock toggle key
	//
	// See ## XKB layout group 2
	//
	// ISO_First_Group is interpreted as: action= LockGroup(group=1)
	// ISO_Last_Group  is interpreted as: action= LockGroup(group=2)
	//

	key.type[Group1]= "EIGHT_LEVELS_BASIC";
	key.type[Group2]= "EIGHT_LEVELS_BASIC";
	key <TLDE> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[      ISO_Last_Group,      ISO_Last_Group,      ISO_Last_Group,      ISO_Last_Group,               UEFA1,               UEFA0 ],
		[     ISO_First_Group,     ISO_First_Group,     ISO_First_Group,     ISO_First_Group,               UEFA1,               UEFA0 ]
	}; // Level5 yields <variant>; Level6 yields <version>

	//
	// ## Superscript letters
	//
	// Level 6 superscript letters are related to indices 1 and 2 but cannot be
	// mapped on index 3, for the above reasons.
	//
	// Latin superscript letters are called MODIFIER LETTER except the first few,
	// despite their use goes far beyond phonetics, given that ᵈ, ᵉ, ʳ, and ˢ are
	// used as regular ordinal indicators in French, and ᵃ, ᵒ, and ˢ in Italian,
	// Portuguese and Spanish. The scheme extends to support other abbreviations,
	// with accented letters composed using combining diacritics.
	//
	// As ordinal indicators, ᵈ, ᵉ, ʳ, and ˢ are in Unicode CLDR since v34 (2018)
	// for the French locale, waiting for the other locales to follow up.
	// https://github.com/unicode-org/cldr/blob/release-34/common/main/fr.xml#L1421
	// https://github.com/unicode-org/cldr/blob/release-45/common/main/fr.xml#L1528
	//
	//
	// ## Apostrophes
	//
	// Both the preferred punctuation apostrophe "’" U2019 <rightsinglequotemark>
	// and the ASCII single quote "'" U0027 <apostrophe> are featured on two base
	// level live key positions: E04, because this is the traditional apostrophe
	// key, or remapped on C11, and E05 because this is traditionally the opening
	// parenthesis, that has its closing counterpart on E11 repurposed for the at
	// sign required on base level, and that becomes available thanks to moving
	// both opening and closing parentheses together on C03 and C04, level 3; or
	// C11, when the keyboard is in ASCII mode.
	//
	// The letter apostrophe "ʼ" U02BC, used in Breton as part of the trigraph
	// "cʼh", is used in the Breton trigraph <c_h> and is featured in group 1 of
	// the ASCII apostrophe as well as in group 1 of the punctuation apostrophe.
	//
	// Mapping both the punctuation apostrophe and the ASCII apostrophe on two
	// base level positions is usually frowned upon, but this is the only way
	// to reconcile two competing requirements that are equally advocated, due to
	// the frequency and usefulness of both punctuation and ASCII apostrophes.
	// https://listengine.tuxfamily.org/ergodis.org/discussions/2016/11/msg00152.html
	//
	//
	// ## Format controls
	//
	// "⁄" U2044 FRACTION SLASH is mapped on level 7 of the F key, because it is
	// designed to get ASCII digits formatted as numerators and denominators and
	// is supported by HarfBuzz and OpenType fonts used in Chromium and Firefox.
	// In case of mixed numbers, using the fraction slash as intended requires an
	// invisible character to separate the whole part and the fractional part, as
	// in that case there is no space in front of the fraction. Typically this is
	// U2064 INVISIBLE PLUS or the cursive non-joiner U200C or U2060 WORD JOINER.
	// https://stackoverflow.com/questions/55033436/how-to-display-the-fraction-15-16-nicely-in-unicode
	//
	// U200C ZERO WIDTH NON-JOINER is the cursive non-joiner, abundantly used to
	// prevent wrong ligatures and therefore on level 7 of the AZERTY W key B01,
	// next to the AltFr key B00.
	// https://github.com/unicode-org/cldr/blob/c7e39f13da2bfbaf58c1447d610627511c7a6549/tools/cldr-code/src/main/java/org/unicode/cldr/util/CodePointEscaper.java#L40
	// https://github.com/unicode-org/cldr/blob/main/tools/cldr-code/src/main/java/org/unicode/cldr/util/CodePointEscaper.java#L40
	//
	// U200D ZERO WIDTH JOINER is the cursive joiner on level 7 of AZERTY key Q,
	// ISO C01, right above the cursive non-joiner.
	//
	// U2060 WORD JOINER makes no-break characters out of breaking ones and is on
	// level 7 of the G key with mnemonics based on French "gluon". It happens to
	// be next to the fraction slash that it can help bracket the numerators, the
	// other way around. Previously, the byte order mark UFEFF was used instead.
 	//
	//
	// ## Overscore
	//    ‾‾‾‾‾‾‾‾‾
	// "‾" U203E OVERLINE is on level 7 of the underscore key C07 for the purpose
	// of typing sequences displaying as unbroken lines, that can be used e.g. in
	// fixed-width plain text to underline headings like above.
	// https://www.unicode.org/versions/Unicode15.0.0/UnicodeStandard-15.0.pdf#page=302&zoom=100,0,600
	//
	//
	// ## Emoji
	//
	// A number of Supplemental Multilingual Plane emoji are mapped on live keys.
	// Due to cross-platform compatibility issues, SMP emoji are not supported by
	// dead keys, while all emoji in the Basic Multilingual Plane are supported
	// by the group dead key. Conversely, available live key positions
	// are used for SMP emoji. The selection is based on frequency and additional
	// criteria.
	//
	// The resulting availability bias is a consequence of Microsoft’s failed TSF
	// design, that also impacts natural languages, as it unsupports all composed
	// letters expected to be input by dead keys.
	//
	// The two emoji-related variation selectors are in group 10 on key E, D03,
	// for emoji style, VS16 UFE0F, and on key T, D05, for text style, VS15 UFE0E.
	//
	// Emoji full list:
	// https://unicode.org/emoji/charts/full-emoji-list.html
	//
	// Source list:
	// https://unicode.org/Public/emoji/13.0/emoji-sequences.txt
	//
	// Specification:
	// https://unicode.org/reports/tr51/
	//
	// Emoji frequency figures are based on:
	// https://home.unicode.org/emoji/emoji-frequency/
	// https://www.futurity.org/emoji-countries-1328712-2-2/
	//
	//
	// ## Level inconsistency
	//
	// CAUTION: Index 4 is mostly level 5, and conversely.
	//
	// On indices 1 through 4, the keysyms are ordered only with respect to the
	// keyboard view, where the traditional four levels are filled in by parsing
	// indices 1 through 4 regardless of key types.
	//
	// Since dead key syms may be rendered as an ellipsis, because dead_greek (on
	// older systems also Multi_key) do not have representation tweaks applied so
	// far as spacing clones of diacritics are available, and 9 of the dead keys
	// use PUA characters by lack of appropriate keysyms in keysymdef.h, the dead
	// keys should not show up in the level 4 slot, the less as the dead keys on
	// level 4 are consistent with the level 3 ASCII symbol map by the means of a
	// Multi_key equivalent (or two) associated with each dead key.
	//
	// Instead, the level 4 position of the layout views is used for level 5,
	// except on key D01, where the level 3 - level 5 redundancy when both have
	// the same symbol is not possible, to cater for the Breton trigram because
	// this is written with a letter apostrophe U02BC and so makes a good point
	// for being mapped on keyboard layouts beyond the Breton CʼHWERTY, as an
	// all-in-one sequence with uppercase and titlecase.
	//
	// Level: 1        2        3        5        4        6        7        8
	// Index: 1        2        3        4        5        6        7        8
	//
	//                                   Graphic numpad
	//                          ASCII symbol .... Dead key
	//        Latin letter ............................... Abbreviation indicator
	//
	//
	// ## Column width
	//
	// After the removal of dead_longsolidusoverlay in libxkbcommon 1.6.0 (2023),
	// keysyms are expected to be no longer than rightsinglequotemark, making for
	// a compacter layout with a column width shrinking from 25 to 20 characters,
	// although keysyms are up to 27 characters long (Greek_upsilonaccentdieresis
	// and ISO_Discontinuous_Underline), and even Greek_finalsmallsigma is longer
	// than 20 characters.
	// https://lists.freedesktop.org/archives/wayland-devel/2023-October/043121.html
	//

	key.type[Group1] = "EIGHT_LEVELS_SUPERSCRIPT_SUBSCRIPT_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[         twosuperior,       threesuperior,                   1,           ampersand,         onesuperior,               U2082,               U2083,               UEFC1 ],
		[                   1,                   1,                   1,         onesuperior,                   1,         onesuperior,               U2081,               UEFC1 ]
	}; // U2081 ₁ SUBSCRIPT ONE; U2082 ₂ SUBSCRIPT TWO; U2083 ₃ SUBSCRIPT THREE; UEFC1 1️⃣ keycap 1 emoji

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE02> {
		[              eacute,              Eacute,                   2,               UEFD9,                   2,         twosuperior,               UEFC2,               UEFC2 ],
		[                   2,                   2,                   2,         twosuperior,                   2,         twosuperior,               U2082,               UEFC2 ]
	}; // U2082 ₂ SUBSCRIPT TWO; UEFC2 2️⃣ keycap 2 emoji; UEFD9 *dead_legacytilde

	key.type[Group1] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE03> {
		[            quotedbl,              endash,                   3,          numbersign,                   3,       threesuperior,               UEFC3,               UEFC3 ],
		[                   3,                   3,                   3,       threesuperior,                   3,       threesuperior,               U2083,               UEFC3 ]
	}; // U2083 ₃ SUBSCRIPT THREE; UEFC3 3️⃣ keycap 3 emoji

	key <AE04> {
		[rightsinglequotemark,              emdash,                   4,           braceleft,                   4,               U2074,               UEFC4,               UEFC4 ],
		[                   4,                   4,                   4,               U2074,                   4,               U2074,               U2084,               UEFC4 ]
	}; // rightsinglequotemark: see Apostrophes; U2074 ⁴ SUPERSCRIPT FOUR; U2084 ₄ SUBSCRIPT FOUR; UEFC4 4️⃣ keycap 4 emoji

	key <AE05> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[          apostrophe,               U00AD,                   5,         bracketleft,                   5,               U2075,               UEFC5,               UEFC5 ],
		[                   5,                   5,                   5,               U2075,                   5,               U2075,               U2085,               UEFC5 ]
	}; // apostrophe: see Apostrophes; U00AD SOFT HYPHEN; U2075 ⁵ SUPERSCRIPT FIVE; U2085 ₅ SUBSCRIPT FIVE; UEFC5 5️⃣ keycap 5 emoji

	key <AE06> {
		[               minus,               U2011,                   6,                 bar,                   6,               U2076,               UEFC6,               UEFC6 ],
		[                   6,                   6,                   6,               U2076,                   6,               U2076,               U2086,               UEFC6 ]
	}; // U2011 ‑ NON-BREAKING HYPHEN; U2076 ⁶ SUPERSCRIPT SIX; U2086 ₆ SUBSCRIPT SIX; UEFC6 6️⃣ keycap 6 emoji

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE07> {
		[              egrave,              Egrave,                   7,               UEFDA,                   7,               U2077,               UEFC7,               UEFC7 ],
		[                   7,                   7,                   7,               U2077,                   7,               U2077,               U2087,               UEFC7 ]
	}; // U2077 ⁷ SUPERSCRIPT SEVEN; U2087 ₇ SUBSCRIPT SEVEN; UEFC7 7️⃣ keycap 7 emoji; UEFDA *dead_legacygrave

	key.type[Group1] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE08> {
		[          underscore,      Greek_horizbar,                   8,           backslash,                   8,               U2078,               UEFC8,               UEFC8 ],
		[                   8,                   8,                   8,               U2078,                   8,               U2078,               U2088,               UEFC8 ]
	}; // Greek_horizbar ― U2015 HORIZONTAL BAR; U2078 ⁸ SUPERSCRIPT EIGHT; U2088 ₈ SUBSCRIPT EIGHT; UEFC8 8️⃣ keycap 8 emoji

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE09> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            ccedilla,            Ccedilla,                   9,           parenleft,                   9,               U2079,               UEFC9,               UEFC9 ],
		[                   9,                   9,                   9,               U2079,                   9,               U2079,               U2089,               UEFC9 ]
	}; // U2079 ⁹ SUPERSCRIPT NINE; U2089 ₉ SUBSCRIPT NINE; UEFC9 9️⃣ keycap 9 emoji

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE10> {
		[              agrave,              Agrave,                   0,          parenright,                   0,               U2070,               UEFC0,              U1F51F ],
		[                   0,                   0,                   0,               U2070,                   0,               U2070,               U2080,               UEFC0 ]
	}; // U2070 ⁰ SUPERSCRIPT ZERO; U2080 ₀ SUBSCRIPT ZERO; UEFC0 0️⃣ keycap 0 emoji; U1F51F 🔟 KEYCAP TEN emoji

	key.type[Group1] = "EIGHT_LEVELS_MINUS_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_MINUS_GROUP2";
	key <AE11> {
		[                  at,              degree,               U1D49,        bracketright,              degree,                   E,               UEFCA,               minus ],
		[                  at,              degree,               minus,               U207B,                   E,               U208B,               UEFCA,               minus ]
	}; // U1D49 ᵉ MODIFIER LETTER SMALL E; U207B ⁻ SUPERSCRIPT MINUS; U208B ₋ SUBSCRIPT MINUS; UEFCA *️⃣ keycap star emoji

	key.type[Group1] = "EIGHT_LEVELS_PLUS_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PLUS_GROUP2";
	key <AE12> {
		[      dead_diaeresis,                plus,           Multi_key,          braceright,               equal,                   F,               UEFCB,               equal ],
		[               equal,                plus,           Multi_key,               U207A,                   F,               U208A,               UEFCB,               equal ]
	}; // U207A ⁺ SUPERSCRIPT PLUS; U208A ₊ SUBSCRIPT PLUS; UEFCB #️⃣ keycap hash emoji

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC_TITLECASE";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC_TITLECASE";
	key <AD01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   a,                   A,         asciicircum,                 c_h,               UEFD1,               U1D43,                 C_H,                 C_h ],
		[                   a,                   A,         asciicircum,                 c_h,               UEFD1,               U1D43,                 C_H,                 C_h ]
	}; // U1D43 ᵃ MODIFIER LETTER SMALL A; UEFD1 *dead_superscript; Breton trigraph: lowercase and titlecase; on supporting systems: uppercase when CapsLock is on

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key <AD02> {
		[                   z,                   Z,             percent,             percent,               UEFD5,               U1DBB,             minutes,              U1F627 ],
		[                   z,                   Z,             percent,             percent,               UEFD5,               U1DBB,             minutes,              U1F627 ]
	}; // U1DBB ᶻ MODIFIER LETTER SMALL Z; UEFD5 *dead_turned; 😧 U1F627 ANGUISHED FACE emoji

	key <AD03> {
		[                   e,                   E,            EuroSign,            EuroSign,    dead_doubleacute,               U1D49,             seconds,               UEF8D ],
		[                   e,                   E,            EuroSign,            EuroSign,    dead_doubleacute,               U1D49,             seconds,               UEF8D ]
	}; // U1D49 ᵉ MODIFIER LETTER SMALL E; UEF8D '&quot;'

	key <AD04> {
		[                   r,                   R,           backslash,            sterling,               UEFD6,               U02B3,               U2236,              U1F914 ],
		[                   r,                   R,           backslash,            sterling,               UEFD6,               U02B3,               U2236,              U1F914 ]
	}; // U02B3 ʳ MODIFIER LETTER SMALL R; UEFD6 *dead_reversed; U2236 ∶ RATIO; 🤔 U1F914 THINKING FACE 20th-ranking emoji [🙄 U1F644 FACE WITH ROLLING EYES 23rd-ranking emoji is not supported]

	key <AD05> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   t,                   T,          asciitilde,               U2212,          dead_tilde,               U1D57,              endash,              U1F60A ],
		[                   t,                   T,          asciitilde,               U2212,          dead_tilde,               U1D57,              endash,              U1F60A ]
	}; // U1D57 ᵗ MODIFIER LETTER SMALL T; U2212 − MINUS SIGN; endash U2013 – EN DASH recommended for noting intervals; 😊 U1F60A SMILING FACE WITH SMILING EYES worldwide fifth-most used emoji, fourth-most used smiling emoji in France

	key <AD06> {
		[                   y,                   Y,          dead_greek,                  mu,          dead_greek,               U02B8,                 yen,              U1F60D ],
		[                   y,                   Y,          dead_greek,                  mu,          dead_greek,               U02B8,                 yen,              U1F60D ]
	}; // U02B8 ʸ MODIFIER LETTER SMALL Y; 😍 U1F60D SMILING FACE WITH HEART-SHAPED EYES third-most used smiling emoji in France, third-most overall worldwide

	key <AD07> {
		[                   u,                   U,          apostrophe,                   4,          dead_acute,               U1D58,               UEF9F,               UEF8C ],
		[                   u,                   U,          apostrophe,                   4,          dead_acute,               U1D58,               UEF9F,               UEF8C ]
	}; // U1D58 ᵘ MODIFIER LETTER SMALL U; UEF9F Unicode prefix 'U+'; UEF8C '&apos;'

	key <AD08> {
		[                   i,                   I,           braceleft,                   5,           dead_hook,               U2071,               UEF7E,              U1F64F ],
		[                   i,                   I,           braceleft,                   5,           dead_hook,               U2071,               UEF7E,              U1F64F ]
	}; // U2071 ⁱ SUPERSCRIPT LATIN SMALL LETTER I; UEF7E '\\u{'; 🙏 U1F64F PERSON WITH FOLDED HANDS worldwide sixth-most used emoji

	key <AD09> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   o,                   O,          braceright,                   6,               UEFD4,               U1D52,         Greek_OMEGA,              U1F601 ],
		[                   o,                   O,          braceright,                   6,               UEFD4,               U1D52,         Greek_OMEGA,              U1F601 ]
	}; // U1D52 ᵒ MODIFIER LETTER SMALL O; UEFD4 *dead_retroflexhook; Greek_OMEGA is preferred over U2126 Ω OHM SIGN; 😁 U1F601 GRINNING FACE WITH SMILING EYES 13th-ranking emoji

	key <AD10> {
		[                   p,                   P,           ampersand,              period,       dead_abovedot,               U1D56,           paragraph,               UEF8B ],
		[                   p,                   P,           ampersand,              period,       dead_abovedot,               U1D56,           paragraph,               UEF8B ]
	}; // U1D56 ᵖ MODIFIER LETTER SMALL P; UEF8B '&amp;'

	key.type[Group1] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key <AD11> {
		[     dead_circumflex,               UEF66,          dead_tilde,               U2039,         asciicircum,                   C,      dead_diaeresis,         bracketleft ],
		[            quotedbl,           braceleft,         asciicircum,                   C,         asciicircum,         asciicircum,          underscore,         bracketleft ]
	}; // UEF66 '‹ ' spaced out with NNBSP; U2039 ‹ SINGLE LEFT-POINTING ANGLE QUOTATION MARK; LEFT BRACKET for application shortcut mapping

	key <AD12> {
		[          dead_acute,               UEF67,          dead_grave,               U203A,              dollar,                   D,            sterling,        bracketright ],
		[          underscore,          braceright,           Multi_key,                   D,               U207C,               U207C,               U208C,        bracketright ]
	}; // UEF67 ' ›' spaced out with NNBSP; U203A › SINGLE RIGHT-POINTING ANGLE QUOTATION MARK; U207C ⁼ SUPERSCRIPT EQUALS SIGN; U208C ₌ SUBSCRIPT EQUALS SIGN; RIGHT BRACKET for application shortcut mapping

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key <AC01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   q,                   Q,          numbersign,          numbersign,               UEFD0,              U107A5,               U200D,              U1F610 ],
		[                   q,                   Q,          numbersign,          numbersign,               UEFD0,              U107A5,               U200D,              U1F610 ]
	}; // U107A5 𐞥 MODIFIER LETTER SMALL Q; UEFD0 *dead_group; U200D ZERO WIDTH JOINER, cursive joiner; U1F610 😐 NEUTRAL FACE emoji

	key <AC02> {
		[                   s,                   S,              dollar,              dollar,       dead_currency,               U02E2,             section,              U1F614 ],
		[                   s,                   S,              dollar,              dollar,       dead_currency,               U02E2,             section,              U1F614 ]
	}; // U02E2 ˢ MODIFIER LETTER SMALL S; U1F614 😔 PENSIVE FACE 4th-top sad face emoji

	key <AC03> {
		[                   d,                   D,           parenleft,           parenleft,  dead_invertedbreve,               U1D48,               U2300,              U1F606 ],
		[                   d,                   D,           parenleft,           parenleft,  dead_invertedbreve,               U1D48,               U2300,              U1F606 ]
	}; // U1D48 ᵈ MODIFIER LETTER SMALL D; U2300 ⌀ DIAMETER SIGN; U1F606 😆 SMILING FACE WITH OPEN MOUTH AND TIGHTLY-CLOSED EYES 16th-ranking emoji

	key <AC04> {
		[                   f,                   F,          parenright,          parenright,          dead_breve,               U1DA0,               U2044,              U1F525 ],
		[                   f,                   F,          parenright,          parenright,          dead_breve,               U1DA0,               U2044,              U1F525 ]
	}; // U1DA0 ᶠ MODIFIER LETTER SMALL F; U2044 ⁄ FRACTION SLASH; U1F525 🔥 FIRE 15th-ranking emoji

	key <AC05> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   g,                   G,               minus,               minus,               UEFD8,               U1D4D,               U2060,              U1F44F ],
		[                   g,                   G,               minus,               minus,               UEFD8,               U1D4D,               U2060,              U1F44F ]
	}; // U1D4D ᵍ MODIFIER LETTER SMALL G; UEFD8 *dead_bar; U2060 WORD JOINER; U1F44F 👏 CLAPPING HANDS SIGN worldwide twelvth-most used emoji

	key <AC06> {
		[                   h,                   H,                plus,                plus,           dead_horn,               U02B0,           plusminus,              U1F44D ],
		[                   h,                   H,                plus,                plus,           dead_horn,               U02B0,           plusminus,              U1F44D ]
	}; // U02B0 ʰ MODIFIER LETTER SMALL H; U1F44D 👍 THUMBS UP SIGN worldwide tenth-most used emoji

	key <AC07> {
		[                   j,                   J,          underscore,                   1,               UEFD2,               U02B2,               U203E,              U1F602 ],
		[                   j,                   J,          underscore,                   1,               UEFD2,               U02B2,               U203E,              U1F602 ]
	}; // U02B2 ʲ MODIFIER LETTER SMALL J; UEFD2 *dead_subscript; U203E ‾ OVERLINE; U1F602 😂 FACE WITH TEARS OF JOY worldwide most used emoji, second-most used in France after ❤ U2764

	key <AC08> {
		[                   k,                   K,         bracketleft,                   2,         dead_ogonek,               U1D4F,               UEF7B,              U1F605 ],
		[                   k,                   K,         bracketleft,                   2,         dead_ogonek,               U1D4F,               UEF7B,              U1F605 ]
	}; // U1D4F ᵏ MODIFIER LETTER SMALL K; UEF7B '&#x'; U1F605 😅 SMILING FACE WITH OPEN MOUTH AND COLD SWEAT worldwide eleventh-most used emoji

	key <AC09> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   l,                   L,        bracketright,                   3,               UEFD3,               U02E1,            sterling,              U1F923 ],
		[                   l,                   L,        bracketright,                   3,               UEFD3,               U02E1,            sterling,              U1F923 ]
	}; // U02E1 ˡ MODIFIER LETTER SMALL L; UEFD3 *dead_abovehook; U1F923 🤣 ROLLING ON THE FLOOR LAUGHING fourth-most used emoji

	key <AC10> {
		[                   m,                   M,                 bar,               comma,         dead_macron,               U1D50,                  mu,              U1F637 ],
		[                   m,                   M,                 bar,               comma,         dead_macron,               U1D50,                  mu,              U1F637 ]
	}; // U1D50 ᵐ MODIFIER LETTER SMALL M; U1F637 😷 FACE WITH MEDICAL MASK emoji

	key.type[Group1] = "EIGHT_LEVELS_CAPITAL_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_CAPITAL_LEVEL8_CONTROL";
	key <AC11> {
		[              ugrave,               UEF64,            ellipsis,       guillemotleft,             percent,                   A,             percent,          apostrophe ],
		[          apostrophe,             percent,               grave,                   A,               U207D,               U207D,               U208D,          apostrophe ]
	}; // UEF64 '« ' spaced out with NNBSP; U207D ⁽ SUPERSCRIPT LEFT PARENTHESIS; U208D ₍ SUBSCRIPT LEFT PARENTHESIS; APOSTROPHE for application shortcut mapping

	key.type[Group1] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key <BKSL> {
		[               UEFD0,               UEF65,               UEFD0,      guillemotright,            asterisk,                   B,                  mu,           semicolon ],
		[               minus,            asterisk,               UEFD0,                   B,               U207E,               U207E,               U208E,           semicolon ]
	}; // UEFD0 *dead_group; UEF65 ' »' spaced out with NNBSP; U207E ⁾ SUPERSCRIPT RIGHT PARENTHESIS; U208E ₎ SUBSCRIPT RIGHT PARENTHESIS; SEMICOLON for application shortcut mapping

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key <AB01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   w,                   W,               slash,               slash,         dead_stroke,               U02B7,               U200C,              U1F622 ],
		[                   w,                   W,               slash,               slash,         dead_stroke,               U02B7,               U200C,              U1F622 ]
	}; // U02B7 ʷ MODIFIER LETTER SMALL W; U200C ZERO WIDTH NON-JOINER, cursive non-joiner; U1F622 😢 CRYING FACE 19th-ranking emoji

	key <AB02> {
		[                   x,                   X,            asterisk,            asterisk,      dead_abovering,               U02E3,               U22C5,              U1F31F ],
		[                   x,                   X,            asterisk,            asterisk,      dead_abovering,               U02E3,               U22C5,              U1F31F ]
	}; // U02E3 ˣ MODIFIER LETTER SMALL X; U22C5 ⋅ DOT OPERATOR; U1F31F 🌟 GLOWING STAR emoji

	key <AB03> {
		[                   c,                   C,                less,            multiply,     dead_circumflex,               U1D9C,               UEF8E,              U1F62D ],
		[                   c,                   C,                less,            multiply,     dead_circumflex,               U1D9C,               UEF8E,              U1F62D ]
	}; // U1D9C ᶜ MODIFIER LETTER SMALL C; UEF8E '&lt;'; U1F62D 😭 LOUDLY CRYING FACE worldwide eighth-most used emoji

	key <AB04> {
		[                   v,                   V,             greater,            division,          dead_caron,               U1D5B,               UEF8F,              U1F496 ],
		[                   v,                   V,             greater,            division,          dead_caron,               U1D5B,               UEF8F,              U1F496 ]
	}; // U1D5B ᵛ MODIFIER LETTER SMALL V; UEF8F '&gt;'; U1F496 💖	SPARKLING HEART 17th-ranking emoji

	key <AB05> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   b,                   B,               equal,               UEF6D,               UEFD7,               U1D47,              U1F618,              U1F495 ],
		[                   b,                   B,               equal,               UEF6D,               UEFD7,               U1D47,              U1F618,              U1F495 ]
	}; // U1D47 ᵇ MODIFIER LETTER SMALL B; UEFD7 *dead_flag regional indicator letters; UEF6D '00'; U1F618 😘 FACE THROWING A KISS sixth-most [smiling second-most] used emoji in France, ninth-most worldwide; U1F495 💕 TWO HEARTS seventh-most used emoji

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC";
	key <AB06> {
		[                   n,                   N,               grave,                   0,          dead_grave,               U207F,               UEF68,               UEF69 ],
		[                   n,                   N,               grave,                   0,          dead_grave,               U207F,               UEF68,               UEF69 ]
	}; // U207F ⁿ SUPERSCRIPT LATIN SMALL LETTER N; UEF68 'nᵒ ' with U1D52 and U202F; UEF69 'Nᵒ ' with U1D52 and U202F

	key.type[Group1] = "EIGHT_LEVELS_LEVEL1_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL1_CONTROL";
	key <AB07> {
		[               comma,               UEF63,            question,            question,        dead_cedilla,            question,              U1F612,              U1F499 ],
		[               comma,            question,            question,               comma,        dead_cedilla,               UEF7B,          digitspace,              U1F49A ]
	}; // UEF63 ' ?' spaced out with NNBSP; UEF7B '&#x;' U2007 ' ' FIGURE SPACE; U1F612 😒 UNAMUSED FACE 3rd-top sad face emoji [2021-07-20T2206+0200]; U1F499 💙 BLUE HEART 18th-ranking emoji; U1F49A 💚 GREEN HEART emoji

	key <AB08> {
		[              period,               UEF60,              exclam,              exclam,       dead_belowdot,              exclam,              U1F631,              U1F4E3 ],
		[              period,              exclam,              exclam,              period,       dead_belowdot,               UEF7A,          punctspace,              U1F4E2 ]
	}; // UEF60 ' !' spaced out with NNBSP; UEF7A '&#;' U2008 ' ' PUNCTUATION SPACE; U1F631 😱 FACE SCREAMING IN FEAR 2nd-top sad face emoji; U1F4E3 📣 CHEERING MEGAPHONE emoji; U1F4E2 📢 PUBLIC ADDRESS LOUDSPEAKER emoji

	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_GROUP2";
	key <AB09> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[               slash,               UEF61,               colon,               colon,      dead_diaeresis,               U2044,              U1F615,               slash ],
		[               colon,               slash,               colon,               colon,      dead_diaeresis,               U2044,              U1F603,               slash ]
	}; // UEF61 ' :' spaced out with NNBSP; U2044 ⁄ FRACTION SLASH; U1F615 😕 CONFUSED FACE emoji; U1F603 😃 SMILING FACE WITH OPEN MOUTH emoji

	key <AB10> {
		[           backslash,               UEF62,             section,           semicolon,     dead_belowcomma,             section,              U1F494,           backslash ],
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
	// On an overlay numpad with Fn held down, the AltFr modifier must be pressed
	// before the Fn key.
	//

	key.type[Group1]= "ONE_LEVEL";
	key.type[Group2]= "ONE_LEVEL";
	key <KPEQ> {
		[            KP_Equal ],
		[            KP_Equal ]
	};

	//
	// Operator keys
	//
	// Typographic basic arithmetic symbols are featured on the `Keypad math area
	// with non-CS operators` keypad(ossmath), © Nicolas Mailhot
	// <nicolas.mailhot @ laposte.net>, whose keypad(legacynumber_wang) and
	// keypad(ossnumber_wang) also feature the asciicircum, while the colon and
	// the equals as well as parentheses are featured on the `Hexadecimal Numpad`
	// keypad(hex) by Roland Kaufmann <rlndkfmn at gmail dot com>.
	//
	// Additionally, plusminus and radical are also included, and two symbols for
	// approximations. Numeric character reference prefixes and the closing brace
	// fill up the remaining positions in ASCII mode.
	//
	// LevelThree (impractical) and LevelFive (recommended) have same effect.
	//

	key.type[Group1] = "EIGHT_LEVELS_BASIC";
	key.type[Group2] = "EIGHT_LEVELS_BASIC";
	key <KPDV> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[           KP_Divide,            division,             radical,           parenleft,             radical,           parenleft ],
		[           KP_Divide,           parenleft,         bracketleft,               UEF7E,         bracketleft,               UEF7E ]
	}; // UEF7E '\u{'

	key <KPMU> {
		[         KP_Multiply,            multiply,         asciicircum,          parenright,         asciicircum,          parenright ],
		[         KP_Multiply,          parenright,        bracketright,               UEF7F,        bracketright,               UEF7F ]
	}; // UEF7F '\x{'

	key <KPSU> {
		[         KP_Subtract,               U2212,               equal,               U2243,               equal,               U2243 ],
		[         KP_Subtract,         asciicircum,               equal,          braceright,               equal,          braceright ]
	}; // U2212 − MINUS SIGN; U2243 ≃ ASYMPTOTICALLY EQUAL

	key <KPAD> {
		[              KP_Add,               colon,           plusminus,               U2248,           plusminus,               U2248 ],
		[              KP_Add,               colon,           plusminus,               UEF7C,           plusminus,               UEF7C ]
	}; // U2248 ≈ ALMOST EQUAL; UEF7C '0x'

	//
	// Digit keys
	//
	// The edit key feature on the numpad is deactivated as outdated, redundant,
	// and wasting positions. Instead, level 2 is repurposed for double zero and
	// triple zero as found on electronic calculators, and for hexadecimal letter
	// digits in a layout consistent with the hexadecimal letter digits that are
	// part of the graphic numpad on the alphanumeric block, with digits 1..9 on
	// the same keys as the overlay numpad on compact keyboards. The use of E10
	// for an additional 0 ensuring an AltFr-AltGr symmetry with respect to the
	// row E digits, and both decimal separators dot and comma on D10 and C10 due
	// to using B07..B10 for unspaced punctuation marks, constrain the hex letter
	// digits to keys (C..E)(11..12). As a consequence, the numpad features A..F
	// on level 2 of keys 2, 3, 5, 6, 8 and 9, with a downside of not featuring
	// the E in the center on key 5 like on the `Hexadecimal Numpad` keypad(hex)
	// by Roland Kaufmann <rlndkfmn at gmail dot com>.
	//
	// In default mode, these level 2 hex digits are uppercase, but lowercase in
	// ASCII mode, where also backslash is output rather than the fraction slash,
	// filling up the shifted position on shape-mnemonic key 7, while key 4 on U
	// has room for the full Unicode prefix in default mode, a `#` in ASCII mode.
	//
	// Arrows on digit keys are based on the simple and double arrows featured in
	// the `Keypad number area with arrow symbols` keypad(ossnumber), included in
	// fr(oss), © Nicolas Mailhot <nicolas.mailhot @ laposte.net>. As a feature-
	// rich layout, fr(oss) is found in libraries running Linux on public PCs.
	//
	// Keycap engravings for the deactivated cursor key functionality are used as
	// hints for the positions of a set of 10 graphic basic arrows. This feature
	// is extended to support also basic emoji arrows as well as black, white and
	// triangle-headed arrows. Black arrows are more appropriately called filled
	// arrows, and white arrows, outline arrows.
	//
	// Simple             U2190..U2199                       ↕↙↓↘←↔→↖↑↗
	// Double             U21D0..U21D9                       ⇕⇙⇓⇘⇐⇔⇒⇖⇑⇗
	// Filled             U27A1, U2B05..U2B0D                ⬍⬋⬇⬊⬅⬌➡⬉⬆⬈
	// Outline            U21E6..U21E9, U21F3, U2B00..U2B04  ⇳⬃⇩⬂⇦⬄⇨⬁⇧⬀
	// Triangle-headed    U2B60..U2B69                       ⭥⭩⭣⭨⭠⭤⭢⭦⭡⭧
	//
	// Basic arrow emoji are a mix of simple and filled arrows. For emojification
	// the four main arrows had been picked from black arrows, due to the use of
	// the simple arrows to represent keyboard arrows. On the other hand, oblique
	// or double-headed arrows are inconsistently picked from the simple arrows.
	// https://unicode-org.atlassian.net/browse/CLDR-11748
	//
	// Basic arrow emoji  U27A1, U2B05..U2B07, U2194..U2199  ↕↙⬇↘⬅↔➡↖⬆↗
	//
	// For a consistent user experience, the basic arrow emoji are mapped on a
	// dedicated level, additionally to the sets of simple and filled arrows.
	//
	// On desktop keyboards, the combos involving both LevelThree and LevelFive
	// are almost unusable, so initially, the AltGr + AltFr modifier combination
	// was not used, as these are hard to hold down simultaneously while using
	// the numpad. However, the overlay numpads on laptops can actually be used
	// that way. Therefore, two extra sets of arrows have been added, 2021-07-01.
	//
	// The effect on user experience of the key combination AltFr + AltGr/Option
	// plus a numpad digit is mitigated by making the level depend on the state
	// of the ModLock toggle. In this table, the keyboard levels are ordered by
	// UX quality, from best to worst. LevelThree is AltGr, LevelFive is AltFr.
	//
	//                                    Default mode      ASCII mode
	//
	//                       LevelFive    emoji arrows      simple arrows
	//  Shift +              LevelFive    filled arrows     double arrows
	//          LevelThree                simple arrows     triangle-headed
	//  Shift + LevelThree                double arrows     outline arrows
	//          LevelThree + LevelFive    triangle-headed   emoji arrows
	//  Shift + LevelThree + LevelFive    outline arrows    filled arrows
	//

	key.type[Group1] = "EIGHT_LEVELS_BASIC";
	key.type[Group2] = "EIGHT_LEVELS_BASIC";
	key <KP0>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		// Category:    digit,            sequence,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow,     triangle-headed,       outline arrow
		[                KP_0,               UEF6D,               U2195,               U21D5,               U2195,               U2B0D,               U2B65,               U21F3 ],
		// Category:    digit,            sequence,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow
		[                KP_0,               UEF6D,               U2B65,               U21F3,               U2195,               U21D5,               U2195,               U2B0D ]
	}; // UEF6D '00'

	key <KP1>  {
		// Category:    digit,            sequence,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow,     triangle-headed,       outline arrow
		[                KP_1,               UEF7D,               U2199,               U21D9,               U2199,               U2B0B,               U2B69,               U2B03 ],
		// Category:    digit,            sequence,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow
		[                KP_1,               UEF7D,               U2B69,               U2B03,               U2199,               U21D9,               U2199,               U2B0B ]
	}; // UEF7D '000'

	key <KP2>  {
		// Category:    digit, uppercase hex digit,        simple arrow,        double arrow,  emoji filled arrow,        filled arrow,     triangle-headed,       outline arrow
		[                KP_2,                   A,               U2193,               U21D3,               U2B07,               U2B07,               U2B63,               U21E9 ],
		// Category:    digit, lowercase hex digit,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji filled arrow,        filled arrow
		[                KP_2,                   a,               U2B63,               U21E9,               U2193,               U21D3,               U2B07,               U2B07 ]
	};

	key <KP3>  {
		// Category:    digit, uppercase hex digit,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow,     triangle-headed,       outline arrow
		[                KP_3,                   B,               U2198,               U21D8,               U2198,               U2B0A,               U2B68,               U2B02 ],
		// Category:    digit, lowercase hex digit,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow
		[                KP_3,                   b,               U2B68,               U2B02,               U2198,               U21D8,               U2198,               U2B0A ]
	};

	key <KP4>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		// Category:    digit,              prefix,        simple arrow,        double arrow,  emoji filled arrow,        filled arrow,     triangle-headed,       outline arrow
		[                KP_4,               UEF9F,               U2190,               U21D0,               U2B05,               U2B05,               U2B60,               U21E6 ],
		// Category:    digit,              prefix,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji filled arrow,        filled arrow
		[                KP_4,          numbersign,               U2B60,               U21E6,               U2190,               U21D0,               U2B05,               U2B05 ]
	}; // UEF9F 'U+'

	key <KP5>  {
		// Category:    digit, uppercase hex digit,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow,     triangle-headed,       outline arrow
		[                KP_5,                   C,               U2194,               U21D4,               U2194,               U2B0C,               U2B64,               U2B04 ],
		// Category:    digit, lowercase hex digit,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow
		[                KP_5,                   c,               U2B64,               U2B04,               U2194,               U21D4,               U2194,               U2B0C ]
	};

	key <KP6>  {
		// Category:    digit, uppercase hex digit,        simple arrow,        double arrow,  emoji filled arrow,        filled arrow,     triangle-headed,       outline arrow
		[                KP_6,                   D,               U2192,               U21D2,               U27A1,               U27A1,               U2B62,               U21E8 ],
		// Category:    digit, lowercase hex digit,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji filled arrow,        filled arrow
		[                KP_6,                   d,               U2B62,               U21E8,               U2192,               U21D2,               U27A1,               U27A1 ]
	};

	key <KP7>  {
		// Category:    digit,      fraction slash,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow,     triangle-headed,       outline arrow
		[                KP_7,               U2044,               U2196,               U21D6,               U2196,               U2B09,               U2B66,               U2B01 ],
		// Category:    digit,    escape character,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow
		[                KP_7,           backslash,               U2B66,               U2B01,               U2196,               U21D6,               U2196,               U2B09 ]
	}; // U2044 ⁄ FRACTION SLASH

	key <KP8>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		// Category:    digit, uppercase hex digit,        simple arrow,        double arrow,  emoji filled arrow,        filled arrow,     triangle-headed,       outline arrow
		[                KP_8,                   E,               U2191,               U21D1,               U2B06,               U2B06,               U2B61,               U21E7 ],
		// Category:    digit, lowercase hex digit,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji filled arrow,        filled arrow
		[                KP_8,                   e,               U2B61,               U21E7,               U2191,               U21D1,               U2B06,               U2B06 ]
	};

	key <KP9>  {
		// Category:    digit, uppercase hex digit,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow,     triangle-headed,       outline arrow
		[                KP_9,                   F,               U2197,               U21D7,               U2197,               U2B08,               U2B67,               U2B00 ],
		// Category:    digit, lowercase hex digit,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow
		[                KP_9,                   f,               U2B67,               U2B00,               U2197,               U21D7,               U2197,               U2B08 ]
	};

	//
	// Decimal separator key
	//
	// The numpad dot key can deliver all 3 separators used as decimal separator
	// or as group separator, also called thousands separator. Both dot and comma
	// as well as the no-break thin space U202F NARROW NO-BREAK SPACE are output
	// when pressing this key alone or with Shift or AltFr (or AltGr), similarly
	// to kbdl(kposs) © 2007 Nicolas Mailhot <nicolas.mailhot @ laposte.net>.
	//
	// The legacy U00A0 NO-BREAK SPACE is less easily input but still supported,
	// although it is dysfunctional in this usage, except on old systems where it
	// prevents worse issues, while paving the way of false confidence that fools
	// users into sticking with them, compromising cyber security.
	//
	// LevelThree (impractical) and LevelFive (recommended) have same effect.
	//
	// CapsLock affects levels 1 and 2 for toggling dot and comma.
	//
	// ABNT-2 keyboards feature a dot key above Enter, KPPT, while the widespread
	// decimal separator key besides Enter, KPDL, outputs a comma.
	// https://bugzilla.redhat.com/show_bug.cgi?id=470153
	// https://bugs.launchpad.net/ubuntu/+source/xkeyboard-config/+bug/272606
	//
	// KP_Decimal translates to period, KP_Separator to comma. But there is no
	// guarantee that this mapping works out as expected, Nicolas Mailhot warns
	// in symbols/kpdl. This soft-coded map is picked here rather than one of the
	// hard-coded alternatives, considering that this setup might be expected to
	// be modifiable depending on regional preferences.
	//
	// The map below does not match the Brazilian locale, where KPDL is mapped to
	// KP_Separator, KPPT to KP_Decimal; it only ensures that there is a key for
	// comma and a key for period on numpads with two separator keys, and both
	// have NARROW NO-BREAK SPACE on level 3 and on level 5, although in
	// Brazilian Portuguese, the group separator is period, as opposed to
	// European Portuguese, where the decimal separator is comma.
	// https://bugzilla.redhat.com/show_bug.cgi?id=470153#c27
	// https://bugs.launchpad.net/ubuntu/+source/xkeyboard-config/+bug/272606/comments/54
	//

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_SEPARATOR";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_SEPARATOR";
	key <KPDL> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[          KP_Decimal,        KP_Separator,               U202F,        nobreakspace,               U202F,        nobreakspace,            NoSymbol,            NoSymbol ],
		[          KP_Decimal,        KP_Separator,               U202F,        nobreakspace,               U202F,        nobreakspace,            NoSymbol,            NoSymbol ]
	}; // U202F ' ' NARROW NO-BREAK SPACE

	key <KPPT> {
		[        KP_Separator,          KP_Decimal,               U202F,        nobreakspace,               U202F,        nobreakspace,            NoSymbol,            NoSymbol ],
		[        KP_Separator,          KP_Decimal,               U202F,        nobreakspace,               U202F,        nobreakspace,            NoSymbol,            NoSymbol ]
	}; // U202F ' ' NARROW NO-BREAK SPACE

	//
	// Key AB11 for ABNT-2 keyboards
	//
	// For completeness, alongside KPPT, as in br(abnt2).
	//

	key.type[Group1] = "EIGHT_LEVELS_BASIC";
	key.type[Group2] = "EIGHT_LEVELS_BASIC";
	key <AB11> {
		[               slash,            question,              degree,        questiondown,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[               slash,            question,              degree,        questiondown,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	//
	// Modifier maps
	//

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
	name[Group2] = "Breton and French semiautomatic keyboard layout, ASCII mode";
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
	key.type[Group1]= "EIGHT_LEVELS_BASIC";
	key.type[Group2]= "EIGHT_LEVELS_BASIC";
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
	name[Group2] = "Breton and French remapped semiautomatic keyboard layout, ASCII mode";
	// "Breton et français disposition de clavier semi-automatique redisposée"
	//
	// "‑" U2011 NON-BREAKING HYPHEN and "―" U2015 HORIZONTAL BAR on E07 required
	// as Ñ key may be input using group 1 of equal or underscore. "―" U2015 also
	// in group 1 of Ññ, and "‑" U2011 by dead_diaeresis followed by ASCII hyphen.

	include "dispocla(kbfrFRsr)"

	// Variant name.
	key.type[Group1]= "EIGHT_LEVELS_BASIC";
	key.type[Group2]= "EIGHT_LEVELS_BASIC";
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
	name[Group2] = "French Polynesia semiautomatic keyboard layout, ASCII mode";
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
	key.type[Group1]= "EIGHT_LEVELS_BASIC";
	key.type[Group2]= "EIGHT_LEVELS_BASIC";
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
	name[Group2] = "French Polynesia remapped semiautomatic keyboard layout, ASCII mode";
	// "Polynésie française disposition de clavier semi-automatique redisposée"
	//
	// "‑" U2011 NON-BREAKING HYPHEN and "―" U2015 HORIZONTAL BAR on E07 required
	// as Ñ key may be input using group 1 of equal or underscore. "―" U2015 also
	// in group 1 of Ññ, and "‑" U2011 by dead_diaeresis followed by ASCII hyphen.

	include "dispocla(kbfrFRsr)"

	// Variant name.
	key.type[Group1]= "EIGHT_LEVELS_BASIC";
	key.type[Group2]= "EIGHT_LEVELS_BASIC";
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
	name[Group2] = "Francophone Africa semiautomatic keyboard layout, ASCII mode";
	// "Afrique francophone disposition de clavier semi-automatique"
	//
	// "_" U005F and "―" U2015 HORIZONTAL BAR on E08 required as Ɔ key have other
	// input methods. Underscore is on level 3 of C09, and in ASCII mode it is on
	// unshifted D12. "―" U2015 is also in group 1 of Ɔɔ, for African variants.

	include "dispocla(kbfrFRs)"

	// Variant name.
	key.type[Group1]= "EIGHT_LEVELS_BASIC";
	key.type[Group2]= "EIGHT_LEVELS_BASIC";
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
	name[Group2] = "Francophone Africa remapped semiautomatic keyboard layout, ASCII mode";
	// "Afrique francophone disposition de clavier semi-automatique redisposée"
	//
	// "‑" U2011 NON-BREAKING HYPHEN and "―" U2015 HORIZONTAL BAR on E07 required
	// as Ɔ key may be input using group 1 of equal or underscore. "―" U2015 also
	// in group 1 of Ɔɔ, and "‑" U2011 by dead_diaeresis followed by ASCII hyphen.

	include "dispocla(kbfrFRsr)"

	// Variant name.
	key.type[Group1]= "EIGHT_LEVELS_BASIC";
	key.type[Group2]= "EIGHT_LEVELS_BASIC";
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
	name[Group2] = "French Belgium semiautomatic keyboard layout, ASCII mode";
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
	key.type[Group1]= "EIGHT_LEVELS_BASIC";
	key.type[Group2]= "EIGHT_LEVELS_BASIC";
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
	name[Group2] = "French France remapped semiautomatic keyboard layout, ASCII mode";
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
	key.type[Group1]= "EIGHT_LEVELS_BASIC";
	key.type[Group2]= "EIGHT_LEVELS_BASIC";
	key <TLDE> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFA9 ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               UEFA9 ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
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

	key <AE05> {
		[      dead_diaeresis ],
		[            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_CAPITAL_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE06> {
		[              ugrave ],
		[            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE07> {
		[          dead_grave,      Greek_horizbar ],
		[            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE08> {
		[              egrave,              Egrave ],
		[            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE10> {
		[              eacute,              Eacute ],
		[            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_PLUS_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PLUS_GROUP2";
	key <AE12> {
		[          underscore ],
		[            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC_TITLECASE";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC_TITLECASE";
	key <AD01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   q,                   Q,            NoSymbol,            NoSymbol,            NoSymbol,              U107A5 ],
		[                   q,                   Q,            NoSymbol,            NoSymbol,            NoSymbol,              U107A5 ]
	}; // U107A5 𐞥 MODIFIER LETTER SMALL Q

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key <AD03> {
		[                   j,                   J,            NoSymbol,            NoSymbol,            NoSymbol,               U02B2 ],
		[                   j,                   J,            NoSymbol,            NoSymbol,            NoSymbol,               U02B2 ]
	}; // U02B2 ʲ MODIFIER LETTER SMALL J

	key <AD04> {
		[                   f,                   F,            NoSymbol,            NoSymbol,            NoSymbol,               U1DA0 ],
		[                   f,                   F,            NoSymbol,            NoSymbol,            NoSymbol,               U1DA0 ]
	}; // U1DA0 ᶠ MODIFIER LETTER SMALL F

	key <AD05> {
		[                   g,                   G,            NoSymbol,            NoSymbol,            NoSymbol,               U1D4D ],
		[                   g,                   G,            NoSymbol,            NoSymbol,            NoSymbol,               U1D4D ]
	}; // U1D4D ᵍ MODIFIER LETTER SMALL G

	key <AD07> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   m,                   M,            NoSymbol,            NoSymbol,            NoSymbol,               U1D50 ],
		[                   m,                   M,            NoSymbol,            NoSymbol,            NoSymbol,               U1D50 ]
	}; // U1D50 ᵐ MODIFIER LETTER SMALL M

	key <AD08> {
		[                   l,                   L,            NoSymbol,            NoSymbol,            NoSymbol,               U02E1 ],
		[                   l,                   L,            NoSymbol,            NoSymbol,            NoSymbol,               U02E1 ]
	}; // U02E1 ˡ MODIFIER LETTER SMALL L

	key <AD09> {
		[                   d,                   D,            NoSymbol,            NoSymbol,            NoSymbol,               U1D48 ],
		[                   d,                   D,            NoSymbol,            NoSymbol,            NoSymbol,               U1D48 ]
	}; // U1D48 ᵈ MODIFIER LETTER SMALL D

	key <AD10> {
		[                   k,                   K,            NoSymbol,            NoSymbol,            NoSymbol,               U1D4F ],
		[                   k,                   K,            NoSymbol,            NoSymbol,            NoSymbol,               U1D4F ]
	}; // U1D4F ᵏ MODIFIER LETTER SMALL K

	key.type[Group1] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key <AD12> {
		[               UEFD0,            NoSymbol,               UEFD0 ],
		[            NoSymbol,            NoSymbol,               UEFD0 ]
	}; // UEFD0 *dead_group

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key <AC01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   a,                   A,            NoSymbol,            NoSymbol,            NoSymbol,               U1D43 ],
		[                   a,                   A,            NoSymbol,            NoSymbol,            NoSymbol,               U1D43 ]
	}; // U1D43 ᵃ MODIFIER LETTER SMALL A

	key <AC03> {
		[                   e,                   E,            NoSymbol,            NoSymbol,            NoSymbol,               U1D49 ],
		[                   e,                   E,            NoSymbol,            NoSymbol,            NoSymbol,               U1D49 ]
	}; // U1D49 ᵉ MODIFIER LETTER SMALL E

	key <AC04> {
		[                   r,                   R,            NoSymbol,            NoSymbol,            NoSymbol,               U02B3 ],
		[                   r,                   R,            NoSymbol,            NoSymbol,            NoSymbol,               U02B3 ]
	}; // U02B3 ʳ MODIFIER LETTER SMALL R

	key <AC05> {
		[                   t,                   T,            NoSymbol,            NoSymbol,            NoSymbol,               U1D57 ],
		[                   t,                   T,            NoSymbol,            NoSymbol,            NoSymbol,               U1D57 ]
	}; // U1D57 ᵗ MODIFIER LETTER SMALL T

	key <AC06> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[                   u,                   U,            NoSymbol,            NoSymbol,            NoSymbol,               U1D58 ],
		[                   u,                   U,            NoSymbol,            NoSymbol,            NoSymbol,               U1D58 ]
	}; // U1D58 ᵘ MODIFIER LETTER SMALL U

	key <AC07> {
		[                   n,                   N,            NoSymbol,            NoSymbol,            NoSymbol,               U207F ],
		[                   n,                   N,            NoSymbol,            NoSymbol,            NoSymbol,               U207F ]
	}; // U207F ⁿ SUPERSCRIPT SMALL N

	key <AC08> {
		[                   o,                   O,            NoSymbol,            NoSymbol,            NoSymbol,               U1D52 ],
		[                   o,                   O,            NoSymbol,            NoSymbol,            NoSymbol,               U1D52 ]
	}; // U1D52 ᵒ MODIFIER LETTER SMALL O

	key <AC09> {
		[                   i,                   I,            NoSymbol,            NoSymbol,            NoSymbol,               U2071 ],
		[                   i,                   I,            NoSymbol,            NoSymbol,            NoSymbol,               U2071 ]
	}; // U2071 ⁱ MODIFIER LETTER SMALL I

	key <AC10> {
		[                   p,                   P,            NoSymbol,            NoSymbol,            NoSymbol,               U1D56 ],
		[                   p,                   P,            NoSymbol,            NoSymbol,            NoSymbol,               U1D56 ]
	}; // U1D56 ᵖ MODIFIER LETTER SMALL P

	key.type[Group1] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key <AC11> {
		[rightsinglequotemark,            NoSymbol,          apostrophe ],
		[            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <BKSL> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[               minus,            NoSymbol,            ellipsis ],
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

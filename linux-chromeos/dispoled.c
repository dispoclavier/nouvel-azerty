//                       Date: 2023-12-02T2049+0100
//        Operating file name: dispoled
//                   Encoding: UTF-8
//                       Type: text/XKB configuration
//                   Language: C-like
//                Description: Binding Scroll Lock indicator to Group 2
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
//               Installation: 1. Add this file in /usr/share/X11/xkb/compat/
//                             2. In /usr/share/X11/xkb/compat/complete
//                                add the line
//                                    include "dispoled"
//                                before the closing brace.
//                             The change takes effect when reopening a session.
//
//             Uninstallation: Delete that line prior to removing the file.
//

default xkb_compatibility "dispoled" {
	indicator "Scroll Lock" {
		groups = group2;
	};
};

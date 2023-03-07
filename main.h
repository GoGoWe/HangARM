/**
 * @file
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * @author Thomas Vogt, thomas@thomas-vogt.de
 *
 * @brief C Main.
 **/

#ifndef MAIN_H
#define MAIN_H
#include "string.h"

#define ASCIIWIDTH 40
#define ASCIIHEIGHT 20
#define ASCIISIZE (ASCIIHEIGHT * ASCIIWIDTH + 1)
void main(void);

static string128 asciiArt[ASCIIHEIGHT], asciiBuffer[ASCIIHEIGHT];
char asciiart[ASCIISIZE] =
"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
"MMMMMMMMMMKXKXXNNWMMMMMMMMMMMMMMMMMMMMMM"
"MMMMMMMWXd....',:coxk0XXNNWMMMMMMMMMMMMM"
"MMMMMMMXk'..............,;:ldk0KXXWMMMMM"
"MMMMMMWOl........................';0MMMM"
"MMMMMMNO'.....................   ..kXMMM"
"MMMMMM0o......................  ..:OXMMM"
"MMMMMXk'......l;.,'...............xONMMM"
"MMMMM0o.....'kxk.KO,xl,l.''......,kKMMMM"
"MMMMNO,........;,:ll:Kdk:oo:.....oONMMMM"
"MMMM0o.................''','....,O0WMMMM"
"MMMNk'..........................l0XMMMMM"
"MMM0d... .......................x0WMMMMM"
"MMMXk..........................cOXMMMMMM"
"MMMMMXxolc;,'..................kOWMMMMMM"
"MMMMMWNXXKK00OOkdol:;'........;OKMMMMMMM"
"MMMMMMMMMMMMMWWNNXKK00OOkdolc:ONWMMMMMMM"
"MMMMMMMMMMMMMMMMMMMMMMWWNNXXXMMMMMMMMMMM"
"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM";
#endif

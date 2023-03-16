#ifndef TUIUTIL_H
#define TUIUTIL_H
#include <stdint.h>
#include "string.h"
#define ASCII_NUM_DIS 48
#define ASCIIWIDTH 17
#define ASCIIHEIGHT 10
#define TUIHIGHT 24
#define ASCIISIZE (ASCIIHEIGHT * ASCIIWIDTH + 1)

static string128 asciiContainer[ASCIIHEIGHT], asciiBuffer[ASCIIHEIGHT];

static char asciiArt[ASCIISIZE] =
".      ARM       "
".    IS DEAD     "
".    _______     "
".   |.-----.|    "
".   ||x . x||    "
".   ||_.-._||    "
".   `--)-(--`    "
".  __[=== o]___  "
". |:::::::::::|\\ "
". `-=========-`()";

static char asciiArt2[801] =
"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
"MMMMMMMMMMKXKXXNNWMMMMMMMMMMMMMMMMMMMMMM"
"MMMMMMMWXd....',:coxk0XXNNWMMMMMMMMMMMMM"
"MMMMMMMXk'..............,;:ldk0KXXWMMMMM"
"MMMMMMWOl........................';0MMMM"
"MMMMMMNO'.....................   ..kXMMM"
"MMMMMM0o......................  ..:OXMMM"
"MMMMMXk'......l;.,'...............xONMMM"
"MMMMM0o.....'kxk.ARM.l,l.''......,kKMMMM"
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

static char asciiTitle[800] =
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
"dP                              MMP\"\"\"\"\"\"\"MMMM\"\"\"\"\"\"\"`MMM\"\"\"\"\"`\'\"\"\"`YM   "
"88                              M' .mmmm  MMMM  mmmm,  MM  mm.  mm.  M   "
"88d888b..d8888b.88d888b..d8888b.M         `MM'        .MM  MMM  MMM  M   "
"88'  `8888'  `8888'  `8888'  `88M  MMMMM  MMMM  MMMb. \"MM  MMM  MMM  M   "
"88    8888.  .8888    8888.  .88M  MMMMM  MMMM  MMMMM  MM  MMM  MMM  M   "
"dP    dP`88888P8dP    dP`8888P88M  MMMMM  MMMM  MMMMM  MM  MMM  MMM  M   "
"                             .88MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   "
"                         d8888P                                          "
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";


void clearTUI(void);
void asciiToString(string128 asciiCon[ASCIIHEIGHT], string128 buffer[ASCIIHEIGHT], const char *asciiArt);
void expandAsciArt(const string128 art[ASCIIHEIGHT], int p);


// Converts a char {c} NUMBER to an valid integer
// unhandeld output if {c} is not a number from 0-9
int charDigitToInt(const char c);

// Converts a string {s} NUMBER to an valid integer
// the should only have digits or the result will be inaccurat
int stringDigitsToInt(const string128 *s);


// Converts a ONE DIGIT int {n} to an valid char number
// unhandled output if {n} is not a number from 0-9
void intToString(int n, string128 *s);

int getDigitsCount(int n);

// {base} power of {exp}
int power(int base, int exp);
#endif

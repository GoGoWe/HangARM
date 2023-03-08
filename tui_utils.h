#ifndef TUIUTIL
#define TUIUTIL
#include <stdint.h>
#include "string.h"
#define ASCII_NUM_DIS 48
#define ASCIIWIDTH 40
#define ASCIIHEIGHT 20
#define ASCIISIZE (ASCIIHEIGHT * ASCIIWIDTH + 1)

static string128 asciiArt[ASCIIHEIGHT], asciiBuffer[ASCIIHEIGHT];

void clearTUI(void);
void asciiToString(string128 art[ASCIIHEIGHT], string128 buffer[ASCIIHEIGHT], const char *asciiart);
void expandAsciArt(const string128 art[ASCIIHEIGHT], string128 buffer[ASCIIHEIGHT], int p);

// Converts a char {c} NUMBER to an valid integer
// unhandeld output if {c} is not a number from 0-9
int charDigitToInt(const char c);

// Converts a string {s} NUMBER to an valid integer
// the should only have digits or the result will be inaccurat
int stringDigitsToInt(const string128 *s);


// Converts a ONE DIGIT int {n} to an valid char number
// unhandeld output if {n} is not a number from 0-9

// TODO: There is an equevilant function needed like stringDigitsToInt
// The same principle only dividing by 10 / modulu by 10
void intToString(int n, string128 *s);

int getDigiCount(int n);

// {base} power of {exp}
int power(int base, int exp);
#endif

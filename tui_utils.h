#ifdef TUIUTIL
#define TUIUTIL
#include <stdint.h>
#include "string.h"

void clearTUI(void);

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

/**
 * @file
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * @author Gabriel Wuwer, Lennart Schuster
 *
 * @brief Important functions to use the terminal as HMI.
 **/

#ifndef TUIUTIL_H
#define TUIUTIL_H

#include "string.h"

#define TUIHIGHT 24
#define ASCII_NUM_DIS 48
#define ASCIIWIDTH 17
#define ASCIIHEIGHT 10
#define ASCIISIZE (ASCIIHEIGHT * ASCIIWIDTH + 1)

/**
 * string128 Array used as container for ASCII Art 
*/
static string128 asciiContainer[ASCIIHEIGHT];

/**
 * ASCII Art that is printed when failing a guess
*/
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


/**
 * @brief pushes the current content out of frame
 * 
 */
void clearTUI(void);

/**
 * @brief converts an asciiart to a string128 array for usage with string library
 * 
 * @param asciiCon A string128 array in which the art should be stored
 * @param buffer 
 * @param asciiArt 
 */
void asciiToString(string128 asciiCon[ASCIIHEIGHT], const char *asciiArt);

/**
 * @brief Prints asci art from the bottom
 * 
 * @param asciiCon A string128 array which contains the art line by line
 * @param p The value (in lines) up to which the art should be drawn
 */
void expandAsciiArt(const string128 art[ASCIIHEIGHT], int p);

/**
 * @brief Like pow()
 * 
 * @param base 
 * @param exp 
 * @return int 
 */
int power(int base, int exp);

/**
 * @brief returns the numeric representation of a number char
 *        unhandled output if c in not a number from 0-9
 * @param c char to convert
 * @return int 
 */
int charDigitToInt(const char c);

/**
 * @brief return the number of digits needed to represent an int as a string
 * 
 * @param n int to check
 * @return int 
 */
int getDigitsCount(int n);

/**
 * @brief converts a string to a numeric representation
 *        unhandled output if the string does not only contain digits
 * @param s string128 pointer which contains the numbers
 * @return int 
 */
int stringDigitsToInt(const string128 *s);

/**
 * @brief converts an int to its string representation
 * 
 * @param n number as integer which should be converted
 * @param s string128 pointer to store the characters
 */
void intToString(int n, string128 *s);

/**
 * @brief handles all lowercase latin ascii letters the user inputs into the terminal until he/she presses enter.
 * 
 * @param input string128 pointer to store all user inputted characters
 * @param useTimeout bool if true (1) the input will be 'esc' after 10sec 
 */
void userInput(string128 *input, int useTimeout);

#endif

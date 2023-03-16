/**
 * @file
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * @author Lennart Schuster, Gabriel Wuwer
 *
 * @brief A String128 library implemented for low level C on ARM CPUs
 **/
#ifndef STRING128
#define STRING128

typedef char buf[16];

typedef struct {
	int length;
	char content[128];
} string128;

enum strqal {
	EQUAL = 1,
	UNEQUAL = 0,
	LENGTH_UNEQUAL = -1
};

/**
 * @brief add a cstring to a string128
 * 
 * @param base 
 * @param c
 */
void stradd(string128 *s, const char *c);

/**
 * @brief add a single character to a string128
 * 
 * @param base 
 * @param c 
 */
void straddChar(string128 *s, const char c);

/**
 * @brief Combines two string128 into the first. Does not check for overflow.
 * 
 * @param base 
 * @param extend 
 */
void strcomb(string128 *base, const string128 *extend);

/**
 * @brief copies a cstring to the first cstring, char by char
 * 
 * @param base 
 * @param target 
 */
void cstrcopy(const char *base, char *target);

/**
 * @brief initialize a string128 from a cstring
 * 
 * @param base 
 * @param s 
 */
void strinit(char* base, string128 *s);

/**
 * @brief returns the index of a character, from the given position
 * 
 * @param s 
 * @param c character to find
 * @param p position to search from
 * @return signed int 
 */
int strfind(const string128 *s, const char c, int p);

/**
 * @brief replaces a char at a given position
 * 
 * @param s 
 * @param c replacement character
 * @param p replacement position
 */  
void strrepc(string128 *s, const char c, const int p);

/**
 * @brief clears an string, fails if string is not initialized
 * 
 * @param s 
 */
void strclear(string128 *s);

/**
 * @brief compares two string128 char by char
 * 
 * @param s1 
 * @param s2 
 * @return int 
 */
int strqal (const string128 *s1, const string128 *s2);
#endif

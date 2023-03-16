// author: Lennart Schuster, Gabriel Wuwer
#include "string.h"

/**
 * @brief returns the length of a cstring 
 * 
 * @param base 
 * @return int 
 */
static int getLength(const char* base) {
    int i = 0;
    while(1) {
        if (base[i] == 0) {
            break;
        }
        else {
            i++;
        }
    }
    return i + 1;
}

/**
 * @brief add a cstring to a string128
 * 
 * @param base 
 * @param c
 */
void stradd(string128 *base, const char *c) {
    for (int i = 0; i < getLength(c); i++) {
        base->content[base->length] = c[i];
        base->length++;
    }
}

/**
 * @brief add a single character to a string128
 * 
 * @param base 
 * @param c 
 */
void straddChar(string128 *base, const char c) {
    base->content[base->length] = c;
    base->length++;
}

/**
 * @brief Combines two string128 into the first. Does not check for overflow.
 * 
 * @param base 
 * @param extend 
 */
void strcomb(string128 *base, const string128 *extend) {
    for (int i = 0; i < extend->length; i++) {
        base->content[base->length] = extend->content[i];
        base->length++;
    }
}

/**
 * @brief copies a cstring to the first cstring, char by char
 * 
 * @param base 
 * @param target 
 */
void cstrcopy(const char *base, char *target) {
    int i = 0;
    while(base[i] != '\0') {
        target[i] = base[i];
        i++;
    }
}

/**
 * @brief initialize a string128 from a cstring
 * 
 * @param base 
 * @param s 
 */
void strinit(char *base, string128 *s) {
    int l = getLength(base);
    s->length = l - 1;
    cstrcopy(base, s->content);
    for (int i = l; i < 127; i++) {
        s->content[i] = 0;
    }
}

/**
 * @brief returns the index of a character, from the given position
 * 
 * @param s 
 * @param c character to find
 * @param p position to search from
 * @return signed int 
 */
signed int strfind(const string128 *s, const char c, const int p) {
    signed int index = -1;
    for (int i = p; i < s->length; i++) {
        if (s->content[i] == c) {
            index = i;
            break;
        }
    }
    return index;
}

/**
 * @brief replaces a char at a given position
 * 
 * @param s 
 * @param c replacement character
 * @param p replacement position
 */
void strrepc(string128 *s, const char c, const int p) {
    s->content[p] = c;
}

/**
 * @brief compares two string128 char by char
 * 
 * @param s1 
 * @param s2 
 * @return int 
 */
int strqal(const string128 *s1, const string128 *s2) {
    if (s1->length != s2->length) {
        return LENGTH_UNEQUAL;
    }
    for (int i = 0; i < s1->length ; i++) {
        if (s1->content[i] == s2->content[i]) {
            return EQUAL;
        }
    }
    return UNEQUAL;
}

/**
 * @brief clears an string, fails if string is not initialized
 * 
 * @param s 
 */
void strclear(string128 *s) {
    for (int i = 0; i < s->length; i++) {
        s->content[i] = 0;
    }
    s->length = 0;
}


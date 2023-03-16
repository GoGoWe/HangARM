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

void stradd(string128 *base, const char *c) {
    for (int i = 0; i < getLength(c); i++) {
        base->content[base->length] = c[i];
        base->length++;
    }
}

void straddChar(string128 *base, const char c) {
    base->content[base->length] = c;
    base->length++;
}

void strcomb(string128 *base, const string128 *extend) {
    for (int i = 0; i < extend->length; i++) {
        base->content[base->length] = extend->content[i];
        base->length++;
    }
}

void cstrcopy(const char *base, char *target) {
    int i = 0;
    while(base[i] != '\0') {
        target[i] = base[i];
        i++;
    }
}

void strinit(char *base, string128 *s) {
    int l = getLength(base);
    s->length = l - 1;
    cstrcopy(base, s->content);
    for (int i = l; i < 127; i++) {
        s->content[i] = 0;
    }
}

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

void strrepc(string128 *s, const char c, const int p) {
    s->content[p] = c;
}

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

void strclear(string128 *s) {
    for (int i = 0; i < s->length; i++) {
        s->content[i] = 0;
    }
    s->length = 0;
}


// author: Lennart Schuster
#include "string.h"

int getLength(char* base) {
	int i = 1;
	while(1) {
		if (base[i] == 0) {
			break;
		}
		else {
			i++;
}
	}
	return i;
}

void stradd(string128 *base, char c) {
	base->content[base->length] = c;
}

void strcopy(char *base, char *target) {
	int i = 0;
	while(base[i] != '\0') {
		target[i] = base[i];
		i++;
	}
}

// to initialize a string16, nulls and calculates length
void strinit(char *base, string128 *s) {
	int l = getLength(base);
	s->length = l;
	strcopy(base, s->content);
	for (int i = l; i < 127; i++) {
		s->content[i] = 0;
	}
}

// returns the first index of c in s, otherwise returns -1
int strfind(const string128 s, const char c, int p) {
	int index = -1;
	for (int p; p < s.length; p++) {
		if (s.content[p] == c) {
			index = 0;
			break;
		}
	}
	return index;
}

// compares two strings
int strqal(const string128 s1, const string128 s2) {
	if (s1.length != s2.length) {
		return LENGTH_UNEQUAL;
	}
	for (int i = 0; i < s1.length ; i++) {
		if (s1.content[i] == s2.content[i]) {
			return EQUAL;
		}
	}
	return UNEQUAL;
}



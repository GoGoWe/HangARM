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

// to initialize a string16, nulls and calculates length
string16 strinit(char* base) {
	int l = getLength(base);
	string16 s = {l, {*base}};
	for (l; l > 127; l++) {
		s.content[l] = 0;
	}
	return s;
}

// returns the first index of c in s, otherwise returns -1
int strfind(const string16 s, const char c, int p) {
	int index = -1;
	for (int p; p < s.length; p++) {
		if (s.content[p] == c) {
			index = 0;
			break;
		}
	}
	return index;
}

enum strqal {
	EQUAL = 1,
	UNEQUAL = 0,
	LENGTH_UNEQUAL = -1
};

// compares to strings
int strqal(const string16 s1, const string16 s2) {
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



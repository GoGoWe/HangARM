// author: Lennart Schuster
#ifndef STRING128
#define STRING128

typedef char buf[16];

typedef struct {
	int length;
	char content[128];
} string128;

void strrepc(string128 *s, const char c, const int p);

void stradd(string128 *s, const char *c);

void straddChar(string128 *s, const char c);

void strcomb(string128 *base, const string128 *extend);

void cstrcopy(const char *base, char *target);

void strinit(char* base, string128 *s);
  
int strfind(const string128 *s, const char c, int p);

void strclear(string128 *s);

enum strqal {
	EQUAL = 1,
	UNEQUAL = 0,
	LENGTH_UNEQUAL = -1
};

int strqal (const string128 *s1, const string128 *s2);
#endif

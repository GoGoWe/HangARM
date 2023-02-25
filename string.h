// author: Lennart Schuster

typedef char buf[16];

typedef struct {
	int length;
	char content[128];
} string128;

int find(const string128 s, const char c, int p);

void strcopy(char *base, char *target);

void strinit(char* base, string128 *s);

int strfind(const string128 s, const char c, int p);

enum strqal {
	EQUAL = 1,
	UNEQUAL = 0,
	LENGTH_UNEQUAL = -1
};

int strqal (const string128 s1, const string128 s2);

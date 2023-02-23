// author: Lennart Schuster

typedef char buf[16];

typedef struct string16 {
	int length;
	char content[128];
} string16;
int find(const string16 s, const char c, int p);


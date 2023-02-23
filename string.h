// author: Lennart Schuster

typedef char buf[16];

typedef struct string16 {
	int length;
	char content[128] = {0};
} string16;

int find(string16 s, int *p);
int find_all(string16 s);


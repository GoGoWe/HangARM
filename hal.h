#include <stdint.h>

typedef uint32_t address;
// for Init the UART:
void uartInit(void);

// Outtput Routines:
void printInt( const int);
void printChar( const char );
void printString(const char *text);
void printStringWithLen(const char *text, int len);

// Input Routines:
char readInput(void);

// Generic Register-Access:
void WriteToRegister( uint32_t address, uint32_t value);

uint32_t ReadFromRegister(uint32_t address);

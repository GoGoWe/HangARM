#include <stdint.h>

typedef uint32_t address;
const uint32_t DR = 0x4000C000;
// for Init the UART:
void uartInit(void);

// Outtput Routines:
void printString(const char *text);
void printStringWithLen(const char *text, int len);

// Input Routines:
char read_input(void);

// Generic Register-Access:
void writeToRegister( address a, uint32_t value);

uint32_t readFromRegister(address a);

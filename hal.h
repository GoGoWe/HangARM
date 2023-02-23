#include <stdint.h>

typedef uint32_t address;
// for Init the UART:
void uartInit(void);

// Outtput Routines:
void printString(const char *text);
void printStringWithLen(const char *text, int len);

// Input Routines:
char read_input(void);

// Generic Register-Access:
void WriteToRegister( uint32_t address, uint32_t value);

uint32_t ReadFromRegister(uint32_t address);

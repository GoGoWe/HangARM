#include <stdint.h>
#include "string.h"

static const uint32_t UARTDR = 0x4000C000;

typedef uint32_t address;

// for Init the UART:
void uartInit(void);

// Outtput Routines:
void sendInt( const int);
void sendChar( const char );
void sendString(const string128 *s);

// Input Routines:
char readChar(void);

// Generic Register-Access:
void writeToRegister(address a, uint32_t value);

uint32_t readFromRegister(address a);

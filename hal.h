#include <stdint.h>
#include "string.h"

#define USERTIMEOUTMS10 1000
static const uint32_t UARTDR = 0x4000C000;

typedef uint32_t address;
typedef int ms10;

// for Init the UART:
void uartInit(void);

// Outtput Routines:
void sendInt( const int);
void sendChar( const char );
void sendString(const string128 *s);

// Input Routines:
char readChar(int useTimeout);

// Generic Register-Access:
void writeToRegister(address a, uint32_t value);
uint32_t readFromRegister(address a);

// for INIT the clock:
void timerInit();
void setupTimer(const ms10 target_timeout);

// timer usage
void sleep(ms10 s);
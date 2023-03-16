#ifndef HAL_H
#define HAL_H

#include <stdint.h>
#include "string.h"

#define USERTIMEOUTMS10 1000
typedef uint32_t address;
/**
 * @brief 10ms unit as abstraction for systicks
 * 
 */
typedef int ms10;

static const uint32_t UARTDR = 0x4000C000;

static ms10 ticks;
static ms10 targetTicks;
static ms10 currentTimeout;
static int timeoutHit; // 1 if timeout

// for Init the UART:
void uartInit(void);

// Output Routines:
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

#endif
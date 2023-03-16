/**
 * @file
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * @author Thomas Vogt, thomas@thomas-vogt.de, Lennart Schuster, Gabriel Wuwer
 *
 * @brief The main logic of the game with some mandatory functions.
 **/
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
static int timeoutHit; // 1 if timeout reached

// for Init the UART:
void uartInit(void);

// Output Routines:
void sendInt( const int);
void sendChar( const char );
void sendString(const string128 *s);

/**
 * @brief reads one character from the terminal.
 * 
 * @param useTimeout bool value, if 1 the return value will be 'esc' if there is no input for 10 seconds
 * 
 */
char readChar(int useTimeout);

// Generic Register-Access:
void writeToRegister(address a, uint32_t value);
uint32_t readFromRegister(address a);

/**
 * @brief to initialize the sysclock
 * 
 */
void timerInit();

/**
 * @brief Setup a timer. Only one timer can be active at the same time. In case of a tick overflow, this should still work.
 * 
 * @param targetTimeout 
 */
void setupTimer(const ms10 target_timeout);

/**
 * @brief resets the current timer to its initial value
 * 
 */
void resetTimer();

/**
 * @brief holds programm for given time
 * 
 * @param s 
 */
void sleep(ms10 s);

#endif
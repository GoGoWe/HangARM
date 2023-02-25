/**
 * @file
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * @author Lennart Schuster, Gabriel Wuwer, Georg Philip,
 *
 * @brief C Main.
 **/

#include "main.h"
#include "hal.h"
#include "tui_utils.h"

#include <stdint.h>

void main( void )
{
  uartInit();
  string128 welcome;
  strinit("Welcome to HangARM!\n\r", &welcome);
  sendString(&welcome);

  string128 input;
  strinit("", &input);
  char userInput;
  char *inputString;
  
  do{
    userInput = readChar();
    sendChar(userInput);

    /*
    int inputLen = getDigiCount(userInput);
    char AsciiValue[inputLen];
    intToText((int)userInput, AsciiValue);
    printStringWithLen(AsciiValue, inputLen);
    */

  }while(userInput != '\r'); // Could also be solved with 10
  sendChar('\n');

}
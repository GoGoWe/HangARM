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
#include "string.h"
#include <stdint.h>

		
void userInput(string128 *input) {
	char currentInput;
	strclear(input);

  do {
    currentInput = readChar();
	if (currentInput < 65 || currentInput > 122 || (currentInput > 90 && currentInput < 97)) {
		#ifdef WITHBELL
    	sendChar('\b');
		#endif
	}
	else if (currentInput < 91) {
		currentInput += 32;	
    	sendChar(currentInput);
		stradd(input, &currentInput);
	}
	else {
		sendChar(currentInput);
		stradd(input, &currentInput);
	}
	stradd(input, &currentInput);
  } while(input->length != 0 && currentInput != '\r' && input->length < 128);
  sendChar('\n');
}

void main(void)
{
  static string128 *output, *word;
  string128 *input, *digits;
  char userInput;
  char *inputString;
  int round = 1;

  uartInit();
  strinit("Welcome to HangARM!\n\r", output);
  strinit("", input);
  sendString(output);
  strinit("Round ", output);
  intToString(round, digits);
  strcomb(output, digits);
  stradd(output, ":\n\r");
}

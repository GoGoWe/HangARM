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

#define NUMBEROFROUNDS 10
#define MINWORDLENGTH 5

void userInput(string128 *input)
{
	char currentInput;
	strclear(input);

	do
	{
		currentInput = readChar();
		if (currentInput < 65 || currentInput > 122 || (currentInput > 90 && currentInput < 97))
		{
#ifdef WITHBELL
			sendChar('\b');
#endif
		}
		else if (currentInput < 91)
		{
			currentInput += 32;
			sendChar(currentInput);
			straddChar(input, currentInput);
		}
		else
		{
			sendChar(currentInput);
			straddChar(input, currentInput);
		}
	} while (input->length != 0 && currentInput != '\r' && input->length < 128);
	sendChar('\n');
	sendChar('\r');
}

void startWord(string128 *word, string128 *guess, string128 *output)
{
	userInput(word);
	while (word->length < MINWORDLENGTH)
	{
		strinit("Word to short! Input a new one:\n\r", output);
		sendString(output);
		userInput(word);
	}

	char c = '_';
	for (int i = 0; i < word->length; i++)
	{
		straddChar(guess, c);
	}
}

// returns 1 on won game, 0 on lost game
int guessWord(const string128 *word, string128 *guess, string128 *output)
{
	string128 digits, input;
	strnull(&input);
	strnull(&digits);

	for (int round = 0; round < NUMBEROFROUNDS; round++)
	{
		// optimize with an insert/replace function
		strinit("Round ", output);
		intToString(round+1, &digits);
		strcomb(output, &digits);
		stradd(output, ":\n\r");
		sendString(output);
		// insert
		userInput(&input);
		if (input.length == 1)
		{
			signed int pos = strfind(word, input.content[0], 0);
			while (pos != -1)
			{
				strrepc(guess, input.content[0], pos);
				pos = strfind(word, input.content[0], pos + 1);
			}
			if (pos != -1 && strfind(guess, '_', 0) == -1)
			{
				return 1;
			}
		}
		else
		{
			if (strqal(word, &input))
			{
				return 1;
			}
		}
		sendString(guess);

	}
	return 0;
}

void main(void)
{
	static string128 output, word, guess;
	uartInit();
	strnull(&word);
	strnull(&guess);
	strinit("Welcome to HangARM!\n\r", &output);
	sendString(&output);

	strinit("Please enter your Word:\r\n", &output);
	sendString(&output);
	startWord(&word, &guess, &output);
	if (guessWord(&word, &guess, &output))
	{
		strinit("You won! Word was:\r\n", &output);
		stradd(&output, word.content);
	}
	else
	{
		strinit("Lol, fuqing Pleb kekw, obviously the word was:\r\n", &output);
		stradd(&output, word.content);
	}
}

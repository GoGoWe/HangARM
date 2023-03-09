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
#define MAXWORDLENGHT 5

static void userInput(string128 *input, int useTimeout)
{
	char currentInput;
	strclear(input);

	do
	{
		currentInput = readChar(useTimeout);
		if (currentInput == 18) {
			straddChar(input, '\e');
			break;
		}
		else if (currentInput < 65 || currentInput > 122 || (currentInput > 90 && currentInput < 97))
		{
			sendChar('\b');
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

static void startWord(string128 *word, string128 *guess, string128 *output)
{
	strinit("Please enter your Word: \n\r", output);
	sendString(output);
	userInput(word, 0);

	while (MINWORDLENGTH > word->length > MAXWORDLENGHT)
	{
		strinit("Word size is not in the range! Input a new one:\n\r", output);
		sendString(output);
		userInput(word, 0);
	}
	clearTUI();

	char c = '_';
	for (int i = 0; i < word->length; i++)
	{
		straddChar(guess, c);
	}
}

void statistics(const int fails, string128 *digits, string128 *output){

	clearTUI();
	strinit("\n\rNumber of tries: ", output);
	strcomb(output, digits);
	sendString(output);
	strclear(digits);

	strinit("\n\rNumber of fails: ", output);
	intToString(fails, digits);
	strcomb(output, digits);
	sendString(output);

	strclear(output);
}

// returns 1 on won game, 0 on lost game
int guessWord(const string128 *word, string128 *guess, string128 *output)
{
	string128 digits, input, pastInputs;
	int guessFailed = 0; // Bool to determinate if input was wrong
	int asciiLines = 0; 
	int round = 1;

	for (int fails = 0; fails < NUMBEROFROUNDS;)
	{
		guessFailed = 1; 

		strinit("\n\rRound Number ", output);
		strclear(&digits);
		intToString(round, &digits);
		strcomb(output, &digits);
		stradd(output, "\n\rInput your guess:");
		sendString(output);
		strclear(output);

		// insert
		userInput(&input, 1);
		if(input.content[input.length-1] == '\e'){
			strinit("\n\rTimes up!\n\r", output);
		}
		else if(input.length == 1)
		{
			if(strfind(&pastInputs, input.content[0], 0) != -1){
				strinit("\n\rYou already typed this letter in!\n\r", output);
			}
			else
			{
				strinit("\n\rNop, that was wrong.\n\r", output);
				straddChar(&pastInputs, input.content[0]);
				signed int pos = strfind(word, input.content[0], 0);
				while (pos != -1)
				{
					guessFailed = 0;
					strinit("\n\rThat was a match!\n\r", output);

					strrepc(guess, input.content[0], pos);
					pos = strfind(word, input.content[0], pos + 1);
				}
				if (pos == -1 && strfind(guess, '_', 0) == -1)
				{
					statistics(fails, &digits, output);
					return 1;
				}
			}
		}
		else if(input.length == word->length)
		{
			if (strqal(word, &input))
			{
				statistics(fails, &digits, output);
				return 1;
			}
		}
		else{
			strinit("\n\rAhh, guessed to early, this word was wrong!\n\r", output);
		}

		if(guessFailed){
			asciiLines = asciiLines + (ASCIIHEIGHT - asciiLines) / (NUMBEROFROUNDS - fails);
			fails++;
		}
		round++;
		// Output ASCII Art and current guessed word e.g H _ _ g m _ _ 
		clearTUI();
		expandAsciArt(asciiContainer, asciiLines);
		stradd(output, guess->content);
		sendString(output);
	}
	expandAsciArt(asciiContainer, ASCIIHEIGHT);
	statistics(10, &digits, output);
	return 0;
}

void main(void)
{
	static string128 output, word, guess;

	// First time Initialization 
	asciiToString(asciiContainer, asciiBuffer, asciiArt);
	timerInit();
	uartInit();

	//expandAsciArt(asciiContainer, asciiTitle);


	do{
		startWord(&word, &guess, &output);
		
		if (guessWord(&word, &guess, &output))
		{
			strinit("\n\rYou won! Word was: ", &output);
			stradd(&output, word.content);
		}
		else
		{
			strinit("\n\rYou Lost! The word was: ", &output);
			stradd(&output, word.content);
		}
		sendString(&output);

		strinit("\n\rPress a key if you want to play again\n\r", &output);
		sendString(&output);
		userInput(&output, 0);
	}while(1);
}

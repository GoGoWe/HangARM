/**
 * @file
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * @author Lennart Schuster, Gabriel Wuwer, Georg Philip,
 *
 * @brief The main logic of the game with some mandatory functions.
 **/


#include "main.h"
#include "hal.h"
#include "tui_utils.h"
#include "string.h"
#include "random.h"
#include <stdint.h>

#define NUMBEROFROUNDS 10
#define MINWORDLENGTH 5
#define MAXWORDLENGHT 18

static string128* wordList[5];
static string128 s1,s2,s3,s4,s5;

/**
 * @brief prints user statistic
 * 
 * @param fails integer of wrong user inputs
 * @param digits string128 pointer to contain digits
 * @param output string128 pointer to contain terminal outputs
 */
static void statistics(const int fails, string128 *digits, string128 *output){

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

/**
 * @brief Initializes an array of predefined string128 words to guess and pics one random
 * 		  by taking the time during the input, a char from the input and the length of the input.
 * 		  Nevertheless the inputs a, b, c can be all sort of integer values to generate the seed.
 * 
 * @param a timestamp e.g time passed when user typed a word in
 * @param b character e.g a character of the word the user typed in
 * @param c integer number e.g length of inputted word
 */
static void getRandomWord(string128 *input, ms10 a, char b, int c){
	strinit("schifffahrt", &s1);
	strinit("hausbauverein", &s2);
	strinit("sternpunkt", &s3);
	strinit("dreiecksschaltung", &s4);
	strinit("kernspintomograph", &s5);
	wordList[0] = &s1;
	wordList[1] = &s2;
	wordList[2] = &s3;
	wordList[3] = &s4;
	wordList[4] = &s5;

	strclear(input);
	srandByThreeValues(a, b, c);
	int r = random(0,4);
	strinit(wordList[r]->content, input);
}

/**
 * @brief game logic to choose a start word by the user or randomly
 * 
 * @param word string128 pointer to store the word to guess
 * @param guess string128 pointer to store the characters or string that was guessed
 * @param output string128 pointer to store the output to the terminal
 */
static void startWord(string128 *word, string128 *guess, string128 *output){
	strinit("\n\rDo you want to take a random word? Type \'n\' if not or something else if yes. \n\r", output);
	sendString(output);
	userInput(word, 1);

	if((word->length == 1 && word->content[0] == 'n') || word->content[0] == '\e'){
		strinit("Please enter your Word: \n\r", output);
		sendString(output);
		userInput(word, 0);
	}else{
		int l = word->length;
		getRandomWord(word, ticks, word->content[l/2], l);
	}


	while (MINWORDLENGTH > word->length || word->length > MAXWORDLENGHT)
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

/**
 * @brief main game logic when guessing the word asks the player as long as he did not failed 10 times what his/her guess is
 * 
 * @param word string128 pointer to store the word to guess
 * @param guess string128 pointer to store the characters or string that was guessed
 * @param output string128 pointer to store the output to the terminal
 * @return int 1 if won and 0 if lost
 */
int guessWord(const string128 *word, string128 *guess, string128 *output)
{
	string128 digits, input, pastInputs;
	strclear(&digits);
	strclear(&input);
	strclear(&pastInputs);
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
		expandAsciiArt(asciiContainer, asciiLines);
		stradd(output, guess->content);
		sendString(output);
	}
	statistics(10, &digits, output);
	expandAsciiArt(asciiContainer, ASCIIHEIGHT);
	return 0;
}

void main(void)
{
	// First time Initialization 
	static string128 output, word, guess;
	asciiToString(asciiContainer, asciiArt);
	timerInit();
	uartInit();

	// Welcome Message
	strinit("Welcome to HangARM!", &output);
	sendString(&output);

	// Infinity Game Loop
	do{
		strclear(&output);
		strclear(&word);
		strclear(&guess);

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

		strinit("\n\rPress enter if you want to play again\n\r", &output);
		sendString(&output);
		readChar(0);
		clearTUI();
	}while(1);
}

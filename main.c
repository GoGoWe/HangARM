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

void startWord(string128 *word, string128 *guess) {
    userInput(word);
	string128 *output;
    while (word->length < MINWORDLENGTH) {
        strinit("Word to short!", output);
		sendString(output);
        userInput(word);
        strinit("", guess);
        char c = '_';
        for (int i = 0; i < word->length; i++) {
            stradd(guess, &c);
        }
    }
}

// returns 1 on won game, 0 on lost game
int guessWord(const string128 *word, string128 *guess) {
    string128 *digits, *input, *output;
    int p;

    for(int round = 1; round < NUMBEROFROUNDS; round++) {
        // optimize with an insert/replace function
        strinit("Round ", output);
        intToString(round, digits);
        strcomb(output, digits);
        stradd(output, ":\n\r");
		sendString(output);
        // insert
        userInput(input);
        if (word->length == 1) {
            p = strfind(word, input->content[0], 0);
            while (p != -1) {
                p = strfind(word, input->content[0], 0);
                strrepc(guess, input->content[0], p);
            }
            if (p != -1 && strfind(guess, '_', 0) == -1) {
            return 1;
			}
        }
        else {
            if (strqal(word, input)) {
                    return 1;
                }
            }
        }
		return 0;
    }


void main(void) {
    static string128 *output, *word, *guess;
    uartInit();
    strinit("Welcome to HangARM!\n\r", output);
    sendString(output);
    // sleep
    strinit("Please enter your Word:\r\n", output);
    sendString(output);
    startWord(word, guess);
    if (guessWord(word, guess)) {
		strinit("You won! Word was:\r\n", output);
		stradd(output, word->content);
    }
    else {
		strinit("Lol, fuqing Pleb kekw, obviously the word was:\r\n", output);
		stradd(output, word->content);
    }
}

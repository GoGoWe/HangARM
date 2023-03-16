/**
 * @file
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * @author Lennart Schuster
 *
 * @brief Random functionality implemented like in the C standard described
 **/

#ifndef RANDOM_H
#define RANDOM_H

#include "hal.h"

#define RAND_MAX 32767

static unsigned long int next = 1; 

/**
 * @brief Generates a random number between min and max. 
 * This is done by using a seed and large prime number multiplication.
 * 
 * @param min 
 * @param max 
 * @return int 
 */
int random(signed int min, signed int max);

/**
 * @brief seed generation by three values. 
 * The seed can be generated for example by an user input, 
 * by taking the time during the input, a char from the input and the length of the input.
 * 
 * @param a timestamp
 * @param b character 
 * @param c integer number
 */
void srandByThreeValues(ms10 a, char b, int c);

#endif
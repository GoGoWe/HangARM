#include "random.h"
#include "hal.h"

/**
 * @brief Generates a random number between min and max. 
 * This is done by using a seed and large prime number multiplication.
 * 
 * @param min 
 * @param max 
 * @return int 
 */
int random(signed int min, signed int max)
{ 
    next = next * 1103515245 + 12345; 
    return (unsigned int)(next/65536) % (max + 1) + min; 
} 

/**
 * @brief seed generation by three values. 
 * The seed can be generated for example by an user input, 
 * by taking the time during the input, a char from the input and the length of the input.
 * 
 * @param a timestamp
 * @param b character 
 * @param c integer number
 */
void srandByThreeValues(ms10 a, char b, int c)
{ 
    next = a * b % (a + b) + c;
}
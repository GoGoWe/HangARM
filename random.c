#include "random.h"

/**
 * @brief Generates a random number between min and max. This is done by using a seed and large prime number multiplikation.
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
 * @brief seed generation by three values
 * 
 * @param a timestamp
 * @param b 
 * @param c 
 */
void srandByThreeTimestamp(ms10 a, ms10 b, ms10 c)
{ 
    next = a * b % (a + b) + c;
}
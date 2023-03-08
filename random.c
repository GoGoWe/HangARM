#include "random.h"

int random(signed int min, signed int max)
{ 
    next = next * 1103515245 + 12345; 
    return (unsigned int)(next/65536) % (max + 1) + min; 
} 

void srandByThreeTimestamp(ms10 a, ms10 b, ms10 c)
{ 
    next = a * b % (a + b) + c;
}
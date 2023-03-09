#include "random.h"

int random(signed int min, signed int max)
{ 
    next = next * 1103515245 + 12345; 
    return (unsigned int)(next/65536) % (max + 1) + min; 
} 

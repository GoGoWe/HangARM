#ifndef RANDOM_H
#define RANDOM_H

#include "hal.h"
#define RAND_MAX 32767

static unsigned long int next = 1; 

int random(int min, int max);
void srandByThreeTimestamp(ms10 a, ms10 b, ms10 c);

#endif
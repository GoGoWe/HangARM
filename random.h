#ifndef RANDOM_H
#define RANDOM_H

#include "hal.h"
#define RAND_MAX 32767

static unsigned long int next = 1; 

int random(signed int min, signed int max);
void srandByThreeValues(ms10 a, char b, int c);

#endif
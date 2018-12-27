/*
Generate random float array in IEEE754
normalized, denormalized, NaN/INF mode
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "producer_standard.h"

#define RAND_RANGE_MAX 100000
#define RAND_RANGE_MIN 1
#define DE2NOR_RANGE_MAX 0x7FFFFF
#define DE2NOR_RANGE_MIN 0x400000

#define NORMAL_LOWER_BIT 0.01

int produce_item(size_t item_size, enum TYPE ItemType,
                 unsigned *float_item, unsigned *fixed_item);
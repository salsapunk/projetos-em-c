#include "../include/memory.h"
#include <stdlib.h>

short int** allocGroupsThree(short int groups, Num num) {
	short int** g = (short int**)malloc((num.length / 3) * sizeof(short int*));
	for (short int i = 0; i < groups; i++) {
	    g[i] = (short int*)malloc(3 * sizeof(short int));
	}

	return g;
}

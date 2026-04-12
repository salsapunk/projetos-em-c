#include "../include/memory.h"
// #include <math.h>

int b_to_o(Num num)
{
    int bin;
    // agrupar partes do numero em trios
    // + tratamento pra números sozinhos à esquerda
    // tradução dos dígitos e do grupo
    
    if (num.length % 3 == 0) {
	short int groups = (num.length / 3);
	
	short int** g = allocGroupsThree(groups, num);
    
	short int p = 0;
	for (short int i = 0; i < groups; i++) {
	    for (short int j = 0; j < 3; j++) {
		g[j + p][groups] = num.content[j + p];
	    }
	    p += 3;
	}
    } else {
	if (num.length % 3 == 1) {
	    // loop pra dividir os digitos em trios, tratando dos dois primeiros
	} else {
	    // loop pra dividir os digitos em trios, tratando do primeiro
	}
    }

    return bin;
}

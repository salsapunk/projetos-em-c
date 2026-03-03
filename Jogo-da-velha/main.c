#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "player.h"
#include "matrix.h"

Player chooseOponent(Player* jogador);
void showMatrix(char** matrix);
char showCharMatrix(char** matrix, int x, int y);

int main()
{
    Player jogador;
    initPlayer(&jogador);

    Player oponent = chooseOponent(&jogador);

    char** matrix = initMatrix();

    if(jogador.charactere == 'X') {
	while(true) {
	    chooseSpace(matrix, &jogador);
	    showMatrix(matrix);
	    if(getWinner(checkWinner(matrix), &jogador)) break;

	    if(checkPC(&oponent)) printf("\nNow it's my turn! \n");

	    chooseSpace(matrix, &oponent);
	    showMatrix(matrix);
	    if(getWinner(checkWinner(matrix), &oponent)) break;

	    printf("\n");
	}
    } else {
	while(true) {
	    if(checkPC(&oponent)) printf("\nNow it's my turn! \n");

	    chooseSpace(matrix, &oponent);
	    showMatrix(matrix);
	    if(getWinner(checkWinner(matrix), &oponent)) break;

	    printf("\n");		

	    chooseSpace(matrix, &jogador);
	    showMatrix(matrix);
	    if(getWinner(checkWinner(matrix), &jogador)) break;
	}
    }

    if(jogador.win) printf("");
    else if(oponent.win) printf("");
    else printf("");

    return 0;
}

Player chooseOponent(Player* jogador)
{
    int p;
    printf("Would you like to play with another local player? (y/n)");
    p = fgetc(stdin);
    p = toupper(p);

    if(p != 'Y') {
	Player pc;
	initPC(&pc, jogador->charactere);
	return pc;
    } else {
	Player jogador2;
	initPlayer2(&jogador2, jogador->charactere);
	return jogador2;
    }
}

void showMatrix(char** matrix)
{
  printf("[%c %c %c]\n", showCharMatrix(matrix, 0, 0), showCharMatrix(matrix, 0, 1), showCharMatrix(matrix, 0, 2));
  printf("[%c %c %c]\n", showCharMatrix(matrix, 1, 0), showCharMatrix(matrix, 1, 1), showCharMatrix(matrix, 1, 2));
  printf("[%c %c %c]\n", showCharMatrix(matrix, 2, 0), showCharMatrix(matrix, 2, 1), showCharMatrix(matrix, 2, 2));
}

char showCharMatrix(char** matrix, int x, int y)
{
  if(matrix[x][y]) return matrix[x][y];
  else return '.';
}

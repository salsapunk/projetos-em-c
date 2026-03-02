#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "matrix.h"

void showMatrix(char** matrix);
char showCharMatrix(char** matrix, int x, int y);

int main()
{
    Player jogador;
    initPlayer(&jogador);

    Player pc;
    initPC(&pc, jogador.charactere);

    char** matrix = initMatrix();

    if(jogador.charactere == 'X') {
	do {
	    chooseSpace(matrix, &jogador);
	    showMatrix(matrix);
	    if(getWinner(checkWinner(matrix), &jogador, &pc)) break;
	    printf("\nNow it's my turn! \n");
	    chooseSpace(matrix, &pc);
	    showMatrix(matrix);
	    printf("\n");
	    if(getWinner(checkWinner(matrix), &jogador, &pc)) break;
	} while (!jogador.win && !pc.win);
    } else {
	do {
	    printf("\nNow it's my turn! \n");
	    chooseSpace(matrix, &pc);
	    showMatrix(matrix);
	    if(getWinner(checkWinner(matrix), &jogador, &pc)) break;
	    printf("\n");
	    chooseSpace(matrix, &jogador);
	    showMatrix(matrix);
	    if(getWinner(checkWinner(matrix), &jogador, &pc)) break;
	} while(!jogador.win && !pc.win);
    }

    if(jogador.win) printf("Parabéns! Você venceu!\n");
    else if(pc.win) printf("Que pena, você perdeu!\n");

    return 0;
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

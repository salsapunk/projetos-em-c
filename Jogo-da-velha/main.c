#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "matrix.h"

void showMatrix(char** matrix);

int main()
{
	Player jogador;
  initPlayer(&jogador);

  Player pc;
  initPC(&pc, jogador.charactere);

  char** matrix = initMatrix();
  //showMatrix(matrix);

  if(jogador.charactere == 'X') {
    while (!jogador.win && !pc.win) {
      chooseSpace(matrix, &jogador);
      //randomSpace(&pc);
      //chooseSpace(matrix, &pc);
      showMatrix(matrix);
      getWinner(checkWinner(matrix), &jogador, &pc);
    }
  } else {
    while(!jogador.win && !pc.win) {
      //randomSpace(&pc);
      //chooseSpace(matrix, &pc);
      chooseSpace(matrix, &jogador);
      showMatrix(matrix);
      getWinner(checkWinner(matrix), &jogador, &pc);
    }
  }
  
  if(jogador.win) printf("Parabéns! Você venceu!\n");
  else if(pc.win) printf("Que pena, você perdeu!\n");

  return 0;
}

void showMatrix(char** matrix)
{
  printf("[%c %c %c]\n", matrix[0][0], matrix[0][1], matrix[0][2]);
  printf("[%c %c %c]\n", matrix[1][0], matrix[1][1], matrix[1][2]);
  printf("[%c %c %c]\n", matrix[2][0], matrix[2][1], matrix[2][2]);
}

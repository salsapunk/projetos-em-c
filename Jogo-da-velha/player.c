#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "player.h"

void initPlayer(Player* player)
{
  if(player == NULL) {
    printf("Invalid player pointer!\n");
    return;
  }

  printf("Type here your nickname: ");
	fgets(player->name, MAX_VALUE, stdin);
  player->charactere = getCharactere();
  player->win = false;
}

int getCharactere() {
  printf("Choose a char to play with (X/O): ");
  while(true) {
    int c = fgetc(stdin);
    c = toupper(c);

    if(c != 'X' && c != 'O') {
      printf("Invalid char! Try again.");
      continue;
    }

    return c;
  }
}

void initPC(Player* pc, int pCharactere)
{
  if(pc == NULL) {
    printf("Invalid PC pointer!\n");
    return;
  }

  char foo[] = "PC";
  strcpy(pc->name, foo);
  if(pCharactere == 'X') pc->charactere = 'O';
  else pc->charactere = 'X';
  pc->win = false;
}



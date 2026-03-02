#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "player.h"

//Player
void initPlayer(Player* player)
{
    if(player == NULL) {
	printf("Invalid player pointer!\n");
	return;
    }

    printf("Type here your nickname: ");
    fgets(player->name, MAX_VALUE, stdin);
    
    cleaningNewLine(player);
    
    player->charactere = getCharactere();
    player->win = false;
}

void cleaningNewLine(Player* p)
{
    int len = strlen(p->name);
    if(len > 0 && p->name[len - 1] == '\n') p->name[len - 1] = '\0';
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

//PC
void initPC(Player* pc, int pCharactere)
{
    if(pc == NULL) {
	printf("Invalid PC pointer!\n");
	return;
    }

    char foo[2] = "PC";
    strcpy(pc->name, foo);

    cleaningNewLine(pc);

    if(pCharactere == 'X') pc->charactere = 'O';
    else pc->charactere = 'X';
    pc->win = false;
}

int getSpacePC()
{
    srand(time(NULL));
    return ((rand() % 8) + 1);
}

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

void clearInputBuffer()
{
    int dummy;
    while((dummy = getchar()) != '\n' && dummy != EOF);
}

char** initMatrix()
{
    char** matrix = (char**)malloc(3 * sizeof(char*));
    for(int i = 0; i < 3; i++) {
	matrix[i] = (char*)malloc(3*sizeof(char));
    }
    return matrix;
}

bool checkSpace(char** matrix, int x, int y)
{
    if(!matrix[x][y]) return true;
    else return false;
}

void printMessage(Player* p, char message[])
{
    if(strcmp(p->name, "PC")) {
	printf("%s", message);
    }
}

void chooseSpace(char** matrix, Player* p)
{
    printMessage(p, "(1, 2, 3)\n(4, 5, 6)\n(7, 8, 9)\nWhere do you want to put your char? ");

    while(true){
	int num;

	if(strcmp(p->name, "PC")) {
	    num = 0;
	    clearInputBuffer();
	    int c = getc(stdin);
	    num = c - '0';
	} else {
	    num = getSpacePC();
	}

	switch (num) {
	    case 1:
		if(checkSpace(matrix, 0, 0)) matrix[0][0] = p->charactere;
		else {
		    printMessage(p, "This space is already filled! Try again.\n");
		    continue;
		}
		break;
	    case 2:
		if(checkSpace(matrix, 0, 1)) matrix[0][1] = p->charactere;
		else {
		    printMessage(p, "This space is already filled! Try again.\n");
		    continue;
		}
		break;
	    case 3:
		if(checkSpace(matrix, 0, 2)) matrix[0][2] = p->charactere;
		else {
		    printMessage(p, "This space is already filled! Try again.\n");
		    continue;
		}
		break;
	    case 4:
		if(checkSpace(matrix, 1, 0)) matrix[1][0] = p->charactere;
		else {
		    printMessage(p, "This space is already filled! Try again.\n");
		    continue;
		}
		break;
	    case 5:
		if(checkSpace(matrix, 1, 1)) matrix[1][1] = p->charactere;
		else {
		    printMessage(p, "This space is already filled! Try again.\n");
		    continue;
		}
		break;
	    case 6:
		if(checkSpace(matrix, 1, 2)) matrix[1][2] = p->charactere;
		else {
		    printMessage(p, "This space is already filled! Try again.\n");
		    continue;
		}
		break;
	    case 7:
		if(checkSpace(matrix, 2, 0)) matrix[2][0] = p->charactere;
		else {
		    printMessage(p, "This space is already filled! Try again.\n");
		    continue;
		}
		break;
	    case 8:
		if(checkSpace(matrix, 2, 1)) matrix[2][1] = p->charactere;
		else {
		    printMessage(p, "This space is already filled! Try again.\n");
		    continue;
		}
		break;
	    case 9:
		if(checkSpace(matrix, 2, 2)) matrix[2][2] = p->charactere;
		else {
		    printMessage(p, "This space is already filled! Try again.\n");
		    continue;
		}
		break;
	    default:
		printMessage(p, "Invalid number! Try again!\n");
		break;
	}
	break;
    }
}

char checkWinner(char** matrix)
{
    for(int i = 0; i < 3; i++) {
	if(matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][0] && matrix[i][1] && matrix[i][2]) return matrix[i][1];
	if(matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[0][i] && matrix[1][i] && matrix[2][i]) return matrix[0][i];
    }

    if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] && matrix[1][1] && matrix[2][2]) return matrix[1][1];
    if(matrix[2][0] == matrix[1][1] && matrix[1][1] == matrix[0][2] && matrix[2][0] && matrix[1][1] && matrix[0][2]) return matrix[1][1];
    return 'w';
}

bool getWinner(char charactere, Player* jogador, Player* pc)
{
    if(charactere == jogador->charactere) {
	jogador->win = true;
	return true;
    }
    else if(charactere == pc->charactere) {
	pc->win = true;
	return true;
    }

    return false;
}

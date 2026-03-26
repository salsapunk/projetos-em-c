#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "player.h"

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
    if(!checkPC(p)) {
	printf("%s", message);
    }
}

void chooseSpace(char** matrix, Player* p)
{
    if(!checkPC(p)) {
	printf("(%c, %c, %c)\n"
		"(%c, %c, %c)\n"
		"(%c, %c, %c)\n"
		"%s, where do you want to put your char? ",
		matrix[0][0] ? matrix[0][0] : '1', matrix[0][1] ? matrix[0][1] : '2', matrix[0][2] ? matrix[0][2] : '3',
		matrix[1][0] ? matrix[1][0] : '4', matrix[1][1] ? matrix[1][1] : '5', matrix[1][2] ? matrix[1][2] : '6',
		matrix[2][0] ? matrix[2][0] : '7', matrix[2][1] ? matrix[2][1] : '8', matrix[2][2] ? matrix[2][2] : '9',
		p->name);
    }

    while(true){
	int num = 0;

	if(checkPC(p)) {
	    num = getSpacePC();
	} else {
	    int c = getc(stdin);
	    clearInputBuffer();
	    num = c - '0';
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
		continue;
	}
	break;
    }
}

bool checkFull(char** matrix)
{
    int full = 0;
    for(int i = 0; i < 3; i++) {
	for(int j = 0; j < 3; j++) {
	    if(matrix[i][j]) full++;
	}
    }
    if(full == 9) return true;
    else return false;
}

char checkWinner(char** matrix)
{
    for(int i = 0; i < 3; i++) {
	if(matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][0] && matrix[i][1] && matrix[i][2]) return matrix[i][1];
	if(matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[0][i] && matrix[1][i] && matrix[2][i]) return matrix[0][i];
    }

    if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] && matrix[1][1] && matrix[2][2]) return matrix[1][1];
    if(matrix[2][0] == matrix[1][1] && matrix[1][1] == matrix[0][2] && matrix[2][0] && matrix[1][1] && matrix[0][2]) return matrix[1][1];

    if(checkFull(matrix)) return 'f';

    return 'w';
}

bool getWinner(char charactere, Player* p)
{
    if(charactere == p->charactere) {
	p->win = true;
	return true;
    }
    else if(charactere == 'f') {
	return true;
    }

    return false;
}

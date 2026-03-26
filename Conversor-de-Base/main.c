#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 11

int main(int argc, char *argv[])
{
    //converte só decimal
    int base = 10;

    if(!strcmp(argv[2], "decimal"))
	base = 10;
    if(!strcmp(argv[2], "octal"))
	base = 8;
    if(!strcmp(argv[2], "hexadecimal"))
	base = 16;
    if(!strcmp(argv[2], "binario"))
	base = 2;
 
    printf("%d\n", (int)strtol(argv[1], NULL, base));
}

#include <stdio.h>
#include "../include/num.h"
#include "../include/input.h"

int menuSelection()
{
    printf("Conversor de Bases\nSelecione a conversão a ser feita:");
    printf("1. Octal -> Binário\n2. Octal -> Decimal\n3. Octal -> Hexadecimal\n");
    printf("4. Binário -> Octal\n5. Binário -> Decimal\n6. Binário -> Hexadecimal\n");
    printf("7. Decimal -> Binário\n8. Decimal -> Octal\n9. Decimal -> Hexadecimal\n");
    printf("10. Hexadecimal -> Binário\n11. Hexadecimal -> Octal\n12. Hexadecimal -> Decimal\n");

    int choice = fgetc(stdin);
    return choice;
}


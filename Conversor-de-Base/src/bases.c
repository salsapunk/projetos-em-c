#include <stdbool.h>
#include <string.h>
#include "../include/bases.h"

Bases read_base(char* base)
{
    if (strcmp(base, "-b")) return binario;
    else if (strcmp(base, "-o")) return octal;
    else if (strcmp(base, "-d")) return decimal;
    else if (strcmp(base, "-h")) return hexadecimal;
    
    return NULL;
}

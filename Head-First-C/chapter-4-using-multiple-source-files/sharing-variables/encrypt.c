/*
 * Head First C
 * Chapter 4: Using multiple source files
 */

#include "encrypt.h"

void encrypt(char *message)
{
    while (*message) {
        *message = *message ^ 42;
        message++;
    }
}

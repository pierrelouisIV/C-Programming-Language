/*
 * Head First C
 * Chapter 8: Static and Dynamic libraries
 */

#include "encrypt.h"

void encrypt(char *message)
{
    while (*message) {
        *message = *message ^ 31;
        message++;
    }
}

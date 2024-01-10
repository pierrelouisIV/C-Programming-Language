/*
 * Head First C
 * Chapter 4: Using multiple source files
 */
#include <stdio.h>
#include "encrypt.h"

#define LENGTH_MAX 80

int main()
{
    char msg[LENGTH_MAX];
    while (fgets(msg, LENGTH_MAX, stdin)) {
        encrypt(msg);
        printf("%s", msg);
    }
    return 0;
}

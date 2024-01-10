/*
 * Head First C
 * Chapter 8: static and dynamic libraries
 */

#include "checksum.h"

int checksum(char *message)
{
    int c = 0;
    while (*message) {
        c += c ^ (int) (*message);
        message++;
    }
    return c;
}

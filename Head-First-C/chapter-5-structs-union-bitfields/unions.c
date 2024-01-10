/*
 * Head First C
 * Chapter 5: structs, unions and bitfields
 */

#include <stdio.h>

typedef union {
    short count;
    float weight;
    float volume;
} quantity;

int main()
{
    // few ways to setting an union value:
    quantity q = {4};               // C89 style for the first field
    quantity qq = {.weight=1.5};    // Designated initializaters set other walues
    quantity qqq;                   // Set the value with dot notation
    qqq.volume = 3.7;

    // Unions are often used with structs
    // example: create a fruits struct that contains the quantity union.
    return 0;
}

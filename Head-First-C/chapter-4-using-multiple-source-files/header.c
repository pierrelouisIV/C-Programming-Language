/*
 * Head First C
 * Chapter 4: Using multiple source files
 */

#include <stdio.h>
#include "header.h"

int main()
{
    //
    float n = 25.6;
    printf("Call my superbe function: %.2f\n", superbe_function(n));
    return 0;
}


float superbe_function(float x)
{
    return x*x;
}

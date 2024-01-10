/*
 * Head First C
 * Chapter 4: Using multiple source files
 */
#include <stdio.h>

#include <limits.h> // contains the values for the integer type like int and char
#include <float.h>  // contains the values for floats and doubles

int main(int argc, char **argv)
{
    printf("The value of INT_MAX is %i\n", INT_MAX);
    printf("The value of INT_MIN is %i\n", INT_MIN);
    printf("An int takes %li bytes\n", sizeof(int));

    printf("The value of FLT_MAX is %f\n", FLT_MAX);
    printf("The value of FLT_MIN is %.50f\n", FLT_MIN);
    printf("An float takes %li bytes\n", sizeof(float));

    printf("The value of DBL_MAX is %f\n", DBL_MAX);
    printf("The value of DBL_MIN is %.100f\n", DBL_MIN);
    printf("An DBL takes %li bytes\n", sizeof(double));
    return 0;
}

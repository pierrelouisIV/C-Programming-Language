/*
 * Head First C
 * Chapter 7: Advanced Functions
 *
 * Variadic functions to take a variable number of arguments
 */

#include <stdio.h>
#include <stdarg.h>         // Need this C standard library


void print_ints(int args, ...) // int args is a normal, ordnary argument that will always be passed
{
    va_list ap;
    va_start (ap, args);    // va_start says where the variable arguments start
    int i;
    for(i = 0; i < args; ++i) {                         // loop through all the other arguments
        printf("argument: %i\n", va_arg(ap, int));      // args contains a count of how many vars
        // Warning: you will always need to know the data type of every parameters you read !
    }
    va_end(ap);
}


// Exercice:
enum drink {
    MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE
};

double price(enum drink d) {
    switch (d) {
        case MUDSLIDE:
            return 6.76;
        case FUZZY_NAVEL:
            return 5.31;
        case MONKEY_GLAND:
            return 4.82;
        case ZOMBIE:
            return 5.89;
    }
    return 0;
}

double total(int args, ...) {
    double total = 0.0;
    va_list ap;
    va_start(ap, args);
    int i;
    for(i = 0; i < args; ++i) {
        total += price(va_arg(ap, enum drink));
    }
    va_end(ap);
    return total;
}

int main()
{
    // Test
    print_ints(3, 79, 101, 32);
    // Exercice
    printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
    return 0;
}

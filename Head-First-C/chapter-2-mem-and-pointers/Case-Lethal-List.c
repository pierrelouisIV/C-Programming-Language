/*
 * Head First C
 * Chapter 2 : Pointer and memory
 *
 *  Potential solution : 3[doses] <=> *(doses+3)
 *  Solution : *(doses + 3) <=> *(3 + doses) <=> 3[doses]
 */

#include <stdio.h>

int main() {
    int doses[] = {1, 3, 2, 1000};
    printf("Issue does %i \n", 3[doses]);
    return 0;
}

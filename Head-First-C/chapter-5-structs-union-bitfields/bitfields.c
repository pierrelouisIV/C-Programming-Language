/*
 * Head First C
 * Chapter 5: structs, unions and bitfields
 */

#include <stdio.h>


// Enum to store symbols:
typedef enum {
    R,
    G,
    B
} RGB;


// Bitfield lets you specify how many bits an individual field will store:
typedef struct {
    unsigned int low_pass_vcf:1;    // this field will only use 1 bit of storage
    unsigned int filter_coupler:1;
} synth;
// Bitfield are usually grouped together to gain space

int main()
{
    //
    return 0;
}

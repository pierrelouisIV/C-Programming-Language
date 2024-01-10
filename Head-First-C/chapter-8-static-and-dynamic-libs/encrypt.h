/*
 * Head First C
 * Chapter 8: Static and Dynamic libraries
 */

#ifndef H_ENCRYPT
#define H_ENCRYPT

// sharing variables with extern keyword:
extern int passcode;

void encrypt(char *message);

#endif

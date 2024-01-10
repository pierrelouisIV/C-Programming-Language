/*
 * Head First C
 * Chapter 4: Using multiple source files
 */

#ifndef H_ENCRYPT
#define H_ENCRYPT

// sharing variables with extern keyword:
extern int passcode;

void encrypt(char *message);

#endif

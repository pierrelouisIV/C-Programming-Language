/*
 * Head First C
 * Chapter 8: static and dynamic libraries
 */
#include <stdio.h>
#include <encrypt.h>
#include <checksum.h>

// #include "encrypt.h"  // encrypted.h and checksum.h are in the same directory as the main
// #include "checksum.h"   // program then we use the angle brackets !

   
/*  Sharing .h header file
 *  1) Store them in a standard directory: copy your header files in (usr/local/include or
 *  usr/include), then write #include <encrypt.h>
 *
 *  2) Put hte full pathname in your include statement: if the header files are in another
 *  directory, add the directory name in the include statement: #include "folder_name/encrypt.h"
 *
 *  3) Tell the compiler where to find them:
 *   gcc -I/folder_name test_code.c -o test_code
 *   this tell the compiler to look in /folder_name as well as the standard directory
 */


//
int main()
{
    char s[] = "Speak friend and enter";
    encrypt(s);
    printf("Encrypted to '%s' \n", s);
    printf("Checksum is %i\n", checksum(s));
    encrypt(s);
    printf("Decrypted back to '%s' \n", s);
    printf("Checksum is %i\n", checksum(s));
    return 0;
}

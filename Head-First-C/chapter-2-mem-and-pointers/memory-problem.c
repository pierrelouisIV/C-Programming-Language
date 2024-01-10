/*
 *  Head First C
 *  Chapter 2 : Memory and pointers
 */

#include <stdio.h>

int main() {
    // char *cards = "JQK";
    char cards[] = "JQK";
    /* We can modify cards[] but not *cards
     * because a variable that point to a string literal can't be used
     * to change the content of the string.
     * 
     * But if you create an array from a string literal, then you can modify it.
     */
    *cards     = *(cards+2);
    *(cards+1) = *(cards+2);
    printf("Cards : %s \n", cards);
    
    /* If cards is being declared as a function argument, it means that cards is a pointer
     * then void my_function(char cards[]) <==> void my_function(char *cards)
     * theses two functions are equivalent.
     */

    /* Then never write code that sets a simple char pointer to a string literal value like:
     *      char *s = "Some string";
     *  But if you want to setting a pointer to a string literal write this :
     *      const char *s = "some string";
     *  To remember that is a constant and you can't modify it.
     */
    return 0;
}

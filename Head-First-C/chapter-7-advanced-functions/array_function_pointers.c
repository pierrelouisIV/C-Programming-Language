/*
 * Head First C
 * Chapter 7: Advanced Functions
 *
 * Array of function pointers
 */
#include <stdio.h>
#include <string.h>

//
enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};
typedef struct {
    char *name;
    enum response_type type;
} response;

//
void dump(response r)
{
    printf("Dear %s, \n", r.name);
    puts("Unfortunately your last date contacted us to");
    puts("say that they will not be seeing you again");
}
void second_chance(response r)
{
    printf("Dear %s, \n", r.name);
    puts("Good news: your last date has asked us to");
    puts("arrange another meeting. Please call ASAP.");
}
void marriage(response r)
{
    printf("Dear %s, \n", r.name);
    puts("Congratulation! Your last date has contacted");
    puts("us with a proposal of marriage.");
}

// ----- The array of function pointers ---------- //
// Return type (*Pointer var) (param types) = {...};
void (*replies[]) (response) = {dump, second_chance, marriage};
// Each symbol of the enum has a number then:
// replies[DUMP] <=> replies[0] <=> dump


//
int main()
{
    response r[] = {
        {"Mike", DUMP}, {"Luis", SECOND_CHANCE},
        {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
    };
    int i;
    for(i = 0; i < 4; ++i)
        (replies[r[i].type])(r[i]);     // <=> (function name) (param);
    return 0;
}

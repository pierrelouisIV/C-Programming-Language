/*
 * Head First C
 * Chapter 7: Advanced Functions
 */

#include <stdio.h>
#include <string.h>

#define NUM_ADS 7

char *ADS[] = {
    "William: SBM GSOH likes sports, TV, dining",
    "Matt: SWM NS likes art, movies, theater",
    "Luis: SLM ND likes books, theater, art",
    "Mike: DWM DS likes trucks, sports and bieber",
    "Peter: SAM likes cess, working out and art",
    "Josh: SJM likes sports, movies and theater",
    "Jed: DBM likes theater, books and dining"
};

//
int sports_no_bieber(char *s)
{
    return strstr(s, "sport") && !strstr(s, "bieber");
}

int sports_or_workout(char *s)
{
    return strstr(s, "sports") || strstr(s, "working out");
}

//
void find(int (*match) (char*))
{
    int i;
    puts("Search resultst:");
    puts("-------------------------------------------");

    for(i=0; i < NUM_ADS; ++i)
    {
        if (match(ADS[i])) {
                printf("%s\n", ADS[i]);
            }
    }
    puts("-------------------------------------------");
}

int main()
{
    /* Function Pointers:
     * Return type (* Pointer variable)(Param types)
     * for example, int (*match) (char*)
     * then, just assign the name of the function:
     * 
     * match = sports_no_bieber;
     * match("...");
     */

    //
    find(sports_no_bieber);
    find(sports_or_workout);
    return 0;
}

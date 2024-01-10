/*
 * Head First C
 * Chapter 2.5 : String theory
 *
 */
#include <stdio.h>
#include <string.h>

//
char tracks[][80] = {
    "I left my heart in Harvard Med School",
    "Newark, Newark - a wonderful town",
    "Dancing here to maternity",
    "From here to maternity",
    "The girl from Iwo Jima"
};


void find_track(char search_for[])
{
    for(int i = 0; i < 5; ++i)
    {
        if (strstr(tracks[i], search_for))
            printf("Track %i: %s\n", i, tracks[i]);
    }
}


int main() {
    char search_for[80];
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    // Need to add theses lines because fgets() add the new line character
    // and it fails in the strstr() function !
    search_for[strlen(search_for)-1] = '\0';
    //
    find_track(search_for);
    return 0;
}

/*
 * Head First C
 * Chapter 6: Data structure and dynamic storage
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
typedef struct island {
    char *name;
    struct island *next;
} island;

//
island* create(char *name)
{
    island *new = malloc(sizeof(island));
    new->name = strdup(name);    // need to allocate memory for new string
    new->next = NULL;
    return new;
}

void display(island *start)
{
    island *i = start;
    for(; i != NULL; i = i->next)
        printf("Island: %s\n", i->name);
}

void release(island *start)
{
    island *i = start;
    island *tmp = NULL;
    for(; i != NULL; i = tmp)
    {
        tmp = i->next;
        free(i->name);
        free(i);
    }
}

int main()
{
    //
    char name[80];
    fgets(name, 80, stdin);
    island *p_island1 = create(name);
    display(p_island1);
    fgets(name, 80, stdin);
    island *p_island2 = create(name);
    p_island1->next = p_island2;
    display(p_island1);

    //
    release(p_island1);
    return 0;
}

/*
 * Head First C
 * Chapter 7: Advanced Functions
 *
 * Sorting function in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global vars:
int scores[] = {543, 323, 32, 554, 11, 3, 112};

typedef struct {
    int height;
    int width;
} rectangle;


// Sort integer scores, the smallest first
int compare_scores(const void* score_a, const void* score_b)
{
    int a = *(int*)score_a;     // You need to cast the void pointer to an integer pointer
    int b = *(int*)score_b;     // This first * then gets the int stored at address score_b
    return a - b;       // if a>b, this is positive. If a < b this is negative and 0 if equals
}

// Sort integer scores, with the largest first
int compare_scores_desc(const void* score_a, const void* score_b)
{
     int a = *(int*)score_a;  
     int b = *(int*)score_b;
     return b - a;
}


// Sort the rectangles in area order, smallest first
int compare_areas(const void* a, const void* b)
{
    rectangle *rec_a = (rectangle*) a;
    rectangle *rec_b = (rectangle*) b;
    return (rec_a->height * rec_a->width) - (rec_b->height * rec_b->width);
}
// Sort the rectangles in area order, largest first
int compare_areas_desc(const void* a, const void* b)
{
    return compare_areas(b, a);
}


// Sort a list of names in alphabetical order. case-sensitive
int compare_names(const void* a, const void* b)
{
    char **name_a = (char**)a;
    char **name_b = (char**)b;
    return strcmp(*name_a, *name_b);
}

//
void display(int *tab, int length)
{
    int i = 0;
    for(; i < length; ++i)
        printf("%i ", *(tab+i));
    puts("\n");

}

int main()
{
    // qsort(void *array, 
    //       size_t length,
    //       size_t item_size,
    //       int (*compar) (const void *, const void *))
    //
    display(scores, 7);
    qsort(scores, 7, sizeof(int), compare_scores);
    display(scores, 7);
    return 0;
}

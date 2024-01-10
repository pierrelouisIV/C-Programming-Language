/*
 * Head First C
 * Chapter 5: structs, unions and bitfields
 */

#include <stdio.h>

typedef struct {
    float x;
    float y;
    char *name;
} Point;

// Here no need to modify the structure then we can copy the structure
void display_point(Point p)
{
    printf(" Point %s: (%f, %f) \n",p.name, p.x, p.y);
}

// Here we need to modify the structure then the function takes an pointer
void translation(Point *p, float k)
{
    (*p).x += k;
    p->y   += k;
}

int main()
{
    Point p1 = {10.0, 10.0, .name="point a"};
    display_point(p1);
    translation(&p1, 5.5);
    display_point(p1);
    return 0;
}

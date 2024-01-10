/* 
 * Head First C
 * Chapter 2.5 : String theory
 */

#include <stdio.h>
#include <string.h>

void print_reverse(char *s)
{
    size_t len = strlen(s);
    char *t = s + len - 1;
    while (t >= s) {
        printf("%c", *t);
        t = t - 1;
    }
    puts("\n");
}

int main() {
    print_reverse("Hello World !");
    return 0;
}

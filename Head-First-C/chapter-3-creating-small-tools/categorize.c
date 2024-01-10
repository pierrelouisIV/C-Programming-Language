/*
 * Head First C
 * Chapter 3 : Creating small tools
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char line[80];

    if (argc != 3) {
        fprintf(stderr, "Error you need to give 3 args ! \n");
        return 1;
    }
    FILE *in;
    FILE *out;

    if(!(in = fopen("spooky.csv", "r"))) {
        fprintf(stderr, "Error: cannot open the file spooky.csv\n");
        return 1;
    }
    if(!(out = fopen(argv[2], "w"))) {
        fprintf(stderr, "Error: cannot open the file %s\n", argv[2]);
        return 1;
    }


    while (fscanf(in, "%79[^\n]\n", line) == 1) {
        if (strstr(line, argv[1]))
            fprintf(out, "%s\n", line);
    }

    fclose(in);
    fclose(out);
    return 0;
}

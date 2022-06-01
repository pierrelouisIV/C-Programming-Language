#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//
clock_t start, end;

//
typedef unsigned long u32;
typedef unsigned long long u64;


//
double **init_matrix(u64 n)
{
    //
    double **data = malloc(sizeof(double*) * n);

    //
    for(u64 i = 0; i < n; ++i)
    {
        data[i] = malloc(sizeof(double) * n);
    }

    //
    return data;
}


//
void free_matrix(double **data, u64 n)
{
    //
    for(u64 i = 0; i < n; ++i)
    {
        free(data[i]);
    }

    //
    free(data);
}


// load matrix from file
double **load_matrix(char *fname, u64 *n)
{
    //
    if (fname)
    {
        //
        FILE * file = fopen(fname, "rb");
        if (file)
        {
            //
            fscanf(file, "%llu \n", n);

            // Allocate 
            double **T = malloc(sizeof(double*) * (*n));
            //
            for(u64 i = 0; i < (*n); ++i)
            {
                // allocate
                T[i] = malloc(sizeof(double) * (*n));

                // load the data
                for(u64 j = 0; j < (*n); ++j)
                {
                    fscanf(file, "%lf ", &T[i][j]);
                }
            }

            //
            return T;
        }
        else
        {
            //
            fprintf(stderr, "Error : FILE pointer NULL !\n");
            exit(-1);
        }
    }
    else
    {
        fprintf(stderr, "Error : file name pointer NULL !\n");
        exit(-1);
    }
}


//
void display_matrix(double **T, u64 n)
{
    //
    printf("(%llu %llu)\n", n, n);

    //
    for(u64 i = 0; i < n; ++i)
    {
        for(u64 j = 0; j < n; ++j)
        {
            printf("%lf ", T[i][j]);
        }
        printf("\n");
    }
}


//
double **dot_matrix(double **a, double **b, u64 n, u64 m)
{
    //
    if (a && b)
    {
        // Allocate for the dot result
        double **c = malloc(sizeof(double*) * n);
        for(u64 i = 0; i < n; ++i)
        {
            c[i] = malloc(sizeof(double) * n);
        }

        //
        start = clock();
        //
        for(u64 i = 0; i < n; ++i)
            for(u64 j = 0; j < n; ++j)
                for(u64 k = j; k < n; ++k)
                    c[i][j] += a[i][k]*b[k][j];
        //
        end = clock();
        printf("Exec time of the dot : %lf s \n", (double)(end-start)/CLOCKS_PER_SEC);

        //
        return c;
    }
    else
    {
        //
        fprintf(stderr, "Error: matrix pointer NULL !\n");
        exit(-1);
    }
}



//
int main(int argc, char **argv)
{
    //
    if (argc == 3)
    {
        u64 n, m;
        double **A = load_matrix(argv[1], &n);
        double **B = load_matrix(argv[2], &m);

        //
        display_matrix(A, n);
        display_matrix(B, m);

        //
        double **C = dot_matrix(A, B, n, m);
        display_matrix(C, n);


        //
        free_matrix(C, n);
        free_matrix(A, n);
        free_matrix(B, m);

    }
    else
    {
        //
        printf("Usage: %s [matrixA] [matrixB] \n", argv[0]);
    }

    return 0;
}

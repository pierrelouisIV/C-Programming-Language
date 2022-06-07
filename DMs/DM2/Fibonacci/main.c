#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//
clock_t start, end;


//
typedef unsigned long long u64;


// Display the Nth of the fibonacci serie
u64 fibo_recursif(u64 n)
{
    if (n < 2)
        return n;
    else
        return fibo_recursif(n - 1) + fibo_recursif(n - 2);
}


// Display the numbers of the fibonacci serie
u64 fibo_dynamic(u64 n)
{
    // allocate mem
    u64 u0 = 0;
    u64 u1 = 1;
    u64 res;

    // algorithm
    for(u64 i = 0; i < n; ++i)
    {
        //
        res = u0 + u1;

        //
        // printf("%llu ", res);
        
        //
        u0 = u1;
        u1 = res;
    }

    //
    return u0;
}


int main(int argc, char **argv)
{
    //
    if (argc == 2)
    {
        //
        u64 n = atoi(argv[1]);

        // recursive
        start = clock();
        printf("Nth number of the Fibo serie (recursive methode) :\n %llu \n", fibo_recursif(n));
        end = clock();
        printf("Exec time : %lf \n\n", (double)(end - start)/CLOCKS_PER_SEC);

        //
        start = clock();
        printf("The N numbers of the Fibo (dynamic method) :\n %llu \n", fibo_dynamic(n));
        end = clock();
        printf("Exec time : %lf \n", (double)(end - start)/CLOCKS_PER_SEC);
        
    }
    else
    {
        //
        printf("Usage: %s [N] \n", argv[0]);
    }

    //
    return 0;
}

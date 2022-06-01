#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "matrix.h"

#define I 1000
#define MAX 13
int lines = 0;
int columns = 0;
int cpt = 0;

// checking function 
int check_data();
// pascal functions
void pascal_triangle();
void calcul_pascal_triangle(Matrix* M);
// point-col functions
void calcul_point_col(Matrix* mM);


int main(int argc, char ** argv)
{
    time_t t;
    srand((unsigned) time(&t));

    Matrix A, minMax;
    init_matrix(&A, 5, 5, 'A');
    init_matrix(&minMax, 5, 5, 'M');

    
    for(int i=1; i<=I; ++i)
    {
        alea_matrix(&A, 100);
        find_maxL_minC(&A, &minMax);
        calcul_point_col(&minMax);
        display_matrix(&A);
        display_matrix(&minMax);
    }

    printf("\n Sur %d boucles, il y a eu %d point-col \n", I, cpt);
    printf("\n Rapport = %f \n", (float)(cpt)/(float)(I));

    free_matrix(A);
    free_matrix(minMax);
    return 0;
}


int check_data()
{
    printf("Saisir les dimensions de la matrice \n");
    printf("Lignes : ");
    scanf("%d", &lines);
    printf("\n Colonnes : ");
    scanf("%d", &columns);

    if(lines <= MAX && lines >= 0 && columns <= MAX && columns >= 0)
        return 1;
    else 
        return 0;
}


// compteur de pointCol d'une matrice A
void calcul_point_col(Matrix* mM)
{
    for(int i=0; i<mM->L; ++i)
    {
        for(int j=0; j<mM->C; ++j)
        {
            if(mM->tab[i][j] == 1) cpt++;
        }
    }
}



/******     Exercice triangle de Pascal   *****/
void pascal_triangle()
{
    Matrix pascal;
    init_matrix(&pascal, lines, columns, 'A');
    for(int i=0; i<pascal.L; ++i)
    {
        pascal.tab[i][0] = 1;

    }
    diagonal_to_zero(&pascal, 1);
    calcul_pascal_triangle(&pascal);
    
    // show the matrix on the consol
    display_matrix(&pascal);

    // free the allocate memories
    free_matrix(pascal);
}


//
void calcul_pascal_triangle(Matrix* M)
{
    for(int i=2; i<M->L; ++i)
    {
        for(int j=1; j<i; ++j)
        {
            M->tab[i][j] = M->tab[i-1][j] + M->tab[i-1][j-1];
        }
    }
}

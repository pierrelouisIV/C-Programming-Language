#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

// initialisation d'une matrice carrée
void init_matrix(Matrix* m, int lignes, int colonnes, char name)
{
    m->L = lignes;
    m->C = colonnes;
    m->c = name;
    m->tab = malloc(sizeof(int*) * m->L);
    for(int i=0; i<m->L; ++i)
        m->tab[i] = malloc(sizeof(int) * m->C);

    for(int i=0; i<m->L; ++i)
    {
        for(int j=0; j<m->C; ++j)
        {
            m->tab[i][j] = 0;
        }
    }
}

// remplit la matrice de façon aléatoire
void alea_matrix(Matrix* m, int n)
{
    int a = 0;
    for(int i=0; i<m->L; ++i)
    {
        for(int j=0; j<m->C; ++j)
        {
            a = rand() % n;
            m->tab[i][j] = a;
        }
    }
}

// affichage d'une matrice carrée
void display_matrix(Matrix* m)
{
    printf("la matrice %c : \n", m->c);
    for(int i=0; i<m->L; ++i)
    {
        for(int j=0; j<m->C; ++j)
        {
            printf("%d ", m->tab[i][j]);
        }
        printf("\n");
    }
}

// Libération de la mémoire 
void free_matrix(Matrix m)
{
    for(int i=0; i<m.L; ++i)
    {
        free(m.tab[i]);
    }
    free(m.tab);
}


// Remplit la diagonale principale de zéros
void diagonal_to_zero(Matrix* m, int number)
{
    for(int i=0; i<m->L; ++i)
    {
        for(int j=0; j<m->C; ++j)
        {
            if(i==j) m->tab[i][j] = number;
        }
    }
}

// produit d'une matrice et d'un scalaire
void mult_scalar(Matrix* m, int lambda)
{
    for(int i=0; i<m->L; ++i)
    {
        for(int j=0; j<m->C; ++j)
        {
            m->tab[i][j] *= lambda;
        }
    }
}

// addition de deux matrices 
void add_matrix(Matrix* A, Matrix *B)
{
    if(A->C == B->C && A->L == B->L)
    {
        printf(" %c += %c : \n", A->c, B->c);
        for(int i=0; i<A->L; ++i)
        {
            for(int j=0; j<A->C; ++j)
            {
                A->tab[i][j] += B->tab[i][j];
            }
        }
    }
    else
    {
        printf("\n probleme de dimension \n");
    }
}

// multiplication de deux matrices
Matrix mult_matrix(Matrix* A, Matrix* B, char name)
{
    if (A->C == B->L)
    {
        Matrix M;
        init_matrix(&M, A->L, B->C, name);
        printf("Multiplication des matrices %c et %c : \n", A->c, B->c);
        for(int i=0; i<A->L; ++i)
        {
            for(int j=0; j<A->C; ++j)
            {
                M.tab[i][j] = somme(A->tab, B->tab, i, j, A->C);
            }
        }
        return M;
    }
    else
    {
        printf("Erreur de dimension \n");
        Matrix M;
        init_matrix(&M, 1, 1, name);
        return M;
    }
}
int somme(int ** t1, int ** t2, int i, int j, int l)
{
    int res = 0;
    for(int k=0; k<l; ++k)
        res += (t1[i][k] * t2[k][j]);
    return res;
}


// MIN and MAX
void find_maxL_minC(Matrix* A, Matrix* mM)
{
    // Initialisation 
    Matrix min, max;
    min = min_column(A);
    max = max_line(A);

    for(int i=0; i<A->L; ++i)
    {
        for(int j=0; j<A->C; ++j)
        {
            if(min.tab[i][j] == 1 && max.tab[i][j] == 1)
            {
                mM->tab[i][j] = 1;
            }
            else mM->tab[i][j] = 0;
        }
    }

    // free the allocate memory
    free_matrix(min);
    free_matrix(max);
}

Matrix max_line(Matrix* A)
{
    int INF = 0;
    int posI, posJ;
    Matrix Max;
    init_matrix(&Max, A->L, A->C, 'G');

    for(int i=0; i<A->L; ++i)
    {
        for(int j=0; j<A->C; ++j)
        {
            if(A->tab[i][j] >= INF)
            {
                posI = i;
                posJ = j;
                INF = A->tab[i][j];
            }
        }
        Max.tab[posI][posJ] = 1;
        INF = 0;
    }

    //printf("Matrice des max de chaque lignes de la matrice %c : \n", A->c);
    //display_matrix(&Max);

    return Max;
}

Matrix min_column(Matrix* A)
{
    int INF = 999999;
    int posI, posJ;
    Matrix Min;
    init_matrix(&Min, A->L, A->C, 'S');

    for(int i=0; i<A->L; ++i)
    {
        for(int j=0; j<A->C; ++j)
        {
            if(A->tab[j][i] <= INF)
            {
                posI = j;
                posJ = i;
                INF = A->tab[j][i];
            }
        }
        Min.tab[posI][posJ] = 1;
        INF = 999999;
    }

    //printf("Matrice des min de chaque colonnes de la matrice %c : \n", A->c);
    //display_matrix(&Min);

    return Min;
}
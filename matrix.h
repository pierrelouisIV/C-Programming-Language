#ifndef H_MATRIX
#define H_MATRIX

// structure d'une matrice

typedef struct {
    int ** tab;
    int L;      // lignes
    int C;      // colonnes
    char c;     // nom
} Matrix;


// Les fonctions 
void init_matrix(Matrix* m, int lignes, int colonnes, char name);

void alea_matrix(Matrix* m, int n);

void display_matrix(Matrix* m);

void free_matrix(Matrix m);


// fonctions calculs matriciels

void diagonal_to_zero(Matrix* m, int number);

void mult_scalar(Matrix* m, int lambda);

void add_matrix(Matrix* A, Matrix *B);

Matrix mult_matrix(Matrix* A, Matrix* B, char name);
int somme(int ** t1, int ** t2, int i, int j, int l);

void find_maxL_minC(Matrix* A, Matrix* mM);
Matrix max_line(Matrix* A);
Matrix min_column(Matrix* A);

#endif
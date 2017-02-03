#include <stdio.h>

#define MATRIX_DIM 4

void fill_matrix(int[][MATRIX_DIM]);
void print_matrix(int[][MATRIX_DIM]);
void swap_values(int*, int*);
void transponse(int[][MATRIX_DIM]);

int main() {
    int matrix[MATRIX_DIM][MATRIX_DIM];

    fill_matrix(matrix);

    printf("Original matrix: \n");
    print_matrix(matrix);

    transponse(matrix);

    printf("Transponsed matrix: \n");
    print_matrix(matrix);

    return 0;
}

void fill_matrix(int matrix[][MATRIX_DIM]) {
    for(size_t i = 0; i < MATRIX_DIM; i++) {
        for(size_t j = 0; j < MATRIX_DIM; j++) {
            printf("(%lu; %lu): ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(int matrix[][MATRIX_DIM]) {
    for(size_t i = 0; i < MATRIX_DIM; i++) {
        for(size_t j = 0; j < MATRIX_DIM; j++) {
            int current = matrix[i][j];
            int padding = (current < 10) ? 3 : 2;

            printf("%d%*s", current, padding, "");
        }
        printf("\n");
    }
}

void swap_values(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void transponse(int matrix[][MATRIX_DIM]) {
    for(size_t i = 0; i < MATRIX_DIM; i++) {
        for(size_t j = i; j < MATRIX_DIM; j++) {
            if(i != j) {
                swap_values(&matrix[i][j], &matrix[j][i]);
            }
        }
    }
}

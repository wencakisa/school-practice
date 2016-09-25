#include <stdio.h>

static const int MATRIX_DIMENSION = 4;

void enter_matrix(int[][MATRIX_DIMENSION]);
void display_matrix(int[][MATRIX_DIMENSION]);
void swap_values(int*, int*);
void transponse_matrix(int[][MATRIX_DIMENSION]);


int main() {
    int matrix[MATRIX_DIMENSION][MATRIX_DIMENSION];
    enter_matrix(matrix);

    printf("Original matrix: \n");
    display_matrix(matrix);

    transponse_matrix(matrix);

    printf("Transponsed matrix: \n");
    display_matrix(matrix);

    return 0;
}

void enter_matrix(int matrix[][MATRIX_DIMENSION]) {
    for(int row = 0; row < MATRIX_DIMENSION; row++) {
        for(int col = 0; col < MATRIX_DIMENSION; col++) {
            printf("Enter element %dx%d: ", row, col);
            scanf("%d", &matrix[row][col]);
        }
    }
}

void display_matrix(int matrix[][MATRIX_DIMENSION]) {
    for(int row = 0; row < MATRIX_DIMENSION; row++) {
        for(int col = 0; col < MATRIX_DIMENSION; col++) {
            printf("%d\t", matrix[row][col]);
        }
        printf("\n");
    }
}

void swap_values(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void transponse_matrix(int matrix[][MATRIX_DIMENSION]) {
    for(int row = 0; row < MATRIX_DIMENSION; row++) {
        for(int col = row + 1; col < MATRIX_DIMENSION; col++) {
            swap_values(&matrix[row][col], &matrix[col][row]);
        }
    }
}

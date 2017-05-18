#include <stdio.h>

#define DIMENSION 4

void swap(int*, int*);
void transponse(int[][DIMENSION]);
char *get_padding(int);
void print_matrix(int[][DIMENSION]);
void print_number_indexes(int[][DIMENSION], int);

int main(int argc, char *argv[]) {
    int arr[DIMENSION][DIMENSION];
    
    int x = 0;
    for(size_t i = 0; i < DIMENSION; i++) {
        for(size_t j = 0; j < DIMENSION; j++) {
            arr[i][j] = x++;
        }
    }

    print_matrix(arr);
    
    printf("\nTransposing...\n\n");
    transponse(arr);

    print_matrix(arr);
    
    printf("\n");
    print_number_indexes(arr, 0);

    return 0;
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void transponse(int arr[][DIMENSION]) {
    for(size_t i = 0; i < DIMENSION; i++) {
        for(size_t j = i; j < DIMENSION; j++) {
            if(i != j) {
                swap(&arr[i][j], &arr[j][i]);
            }
        }
    }
}

char *get_padding(int num) {
    return (num < 10) ? "  " : " ";
}

void print_matrix(int arr[][DIMENSION]) { 
    for(size_t i = 0; i < DIMENSION; i++) {
        for(size_t j = 0; j < DIMENSION; j++) {
            int current = arr[i][j];

            printf("%d%s", current, get_padding(current));
        }
        printf("\n");
    }
}

void print_number_indexes(int arr[][DIMENSION], int num) {
    for(size_t i = 0; i < DIMENSION; i++) {
        for(size_t j = 0; j < DIMENSION; j++) {
            if(arr[i][j] == num) {
                printf("%d: (%ld; %ld)\n", num, i, j);
            }
        }
    }
}

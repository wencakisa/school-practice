#include <stdio.h>

#define DIM 3

int get_row_sum(int[][DIM], int);
int get_col_sum(int[][DIM], int);
int is_magical(int[][DIM]);

int main() {
    int arr[DIM][DIM] = {
        { 4, 9, 2 },
        { 3, 5, 7 },
        { 8, 1, 6 }
    };

    printf("%d\n", is_magical(arr));

    return 0;
}

int get_row_sum(int arr[DIM][DIM], int row_index) {
    int sum = 0;

    for(size_t i = 0; i < DIM; i++) {
        sum += arr[row_index][i];
    }

    return sum;
}

int get_col_sum(int arr[DIM][DIM], int col_index) {
    int sum = 0;
    
    for(size_t i = 0; i < DIM; i++) {
        sum += arr[i][col_index];
    }

    return sum;
}

int is_magical(int arr[DIM][DIM]) {
    for(size_t i = 0; i < DIM; i++) {
        if(get_row_sum(arr, i) != get_col_sum(arr, i)) {
            return 0;
        }
    }

    return 1;
}

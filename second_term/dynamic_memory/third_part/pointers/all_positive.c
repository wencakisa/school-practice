#include <stdio.h>

#define SIZE 10

int all_positive(int*, int);

int main() {
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = i;
    }
    
    printf("%d\n", all_positive(arr, SIZE));

    return 0;
}

int all_positive(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            return 0;
        }
    }
    
    return 1;
}

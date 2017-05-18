#include <stdio.h>

#define SIZE 10

void by_two(int*, int);

int main() {
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = i;
    }

    by_two(arr, SIZE);
    
    for (int i = 0; i < SIZE; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

void by_two(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

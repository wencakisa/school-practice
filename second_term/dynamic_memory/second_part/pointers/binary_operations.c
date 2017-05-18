#include <stdio.h>

#define SIZE 30

void not(int*, int);
void and(int*, int*, int);
void or(int*, int*, int);
void xor(int*, int*, int);
void print_array(int*, int);

int main() {
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = (i < SIZE / 2);
    }

    print_array(arr, SIZE);
    not(arr, SIZE);
    print_array(arr, SIZE);
    
    int and_array[SIZE / 2];
    and(and_array, arr, SIZE);
    print_array(and_array, SIZE / 2);

    int or_array[SIZE / 2];
    or(or_array, arr, SIZE);
    print_array(or_array, SIZE / 2);

    int xor_array[SIZE / 2];
    xor(xor_array, arr, SIZE);
    print_array(xor_array, SIZE / 2);
}

void not(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = !arr[i];
    }
}

void and(int *arr1, int *arr2, int size) {
    for (int i = 0, j = 0; i < size; i++, j += 2) {
        arr1[i] = (arr2[j] * arr2[j + 1]);
    }
}

void or(int *arr1, int *arr2, int size) {
    for (int i = 0, j = 0; i < size; i++, j += 2) {
        arr1[i] = !!(arr2[j] + arr2[j + 1]);
    }
}

void xor(int *arr1, int *arr2, int size) {
    for (int i = 0, j = 0; i < size; i++, j += 2) {
        arr1[i] = (arr2[j] != arr2[j + 1]);
    }
}

void print_array(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf((i < size - 1) ? "%d, " : "%d", arr[i]);
    }
    printf("]\n");
}

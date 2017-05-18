#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void fill_array_to_size(int*, int);
void print_array(int*, int);

int main() {
    int *arr = malloc(sizeof(int) * SIZE);

    fill_array_to_size(arr, SIZE);
    print_array(arr, SIZE);

    free(arr);

    return 0;
}

void fill_array_to_size(int *arr, int size) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

void print_array(int *arr, int size) {
    printf("[");
    for (size_t i = 0; i < size; i++) {
        printf((i < size - 1) ? "%d, " : "%d]\n", arr[i]);
    }
}

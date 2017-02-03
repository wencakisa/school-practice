#include <stdio.h>

void swap_values(int*, int*);
void sort(int*, int);
void sort_ascending(int*);
void sort_descending(int*);
void print_array(int*);

int main() {
    int numbers[] = {2, 3, 19, -3, 4, -10, -4, 12};

    printf("Original array: ");
    print_array(numbers);

    sort_ascending(numbers);
    printf("Ascending order: ");
    print_array(numbers);

    sort_descending(numbers);
    printf("Descending order: ");
    print_array(numbers);

    return 0;
}

void swap_values(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int* arr, int ascending) {
    int i, j;
    int array_len = sizeof(arr);

    for(i = 0; i < array_len; i++) {
        j = i;

        if(ascending) {
            while(j > 0 && arr[j - 1] > arr[j]) {
                swap_values(&arr[j - 1], &arr[j]);
                j--;
            }
        }
        else {
            while(j > 0 && arr[j - 1] < arr[j]) {
                swap_values(&arr[j - 1], &arr[j]);
                j--;
            }
        }
    }
}

void sort_ascending(int* arr) {
    sort(arr, 1);
}

void sort_descending(int* arr) {
    sort(arr, 0);
}

void print_array(int* arr) {
    int i;
    int array_len = sizeof(arr);

    printf("[");
    for(i = 0; i < array_len; i++) {
        (i < array_len - 1) ?
            printf("%d, ", arr[i]) :
            printf("%d", arr[i]);
    }
    printf("]\n");
}

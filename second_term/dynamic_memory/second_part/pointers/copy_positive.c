#include <stdio.h>

#define SIZE 20

int copy_only_positive(int*, int, int*);

int main() {
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = i - 10;
    }
    
    int positive[SIZE];
    int positive_count = copy_only_positive(arr, SIZE, positive);

    printf("Count: %d\n", positive_count);
    for (int i = 0; i < positive_count; i++) {
        printf("%d\n", positive[i]);
    }

    return 0;
}

int copy_only_positive(int *src, int count, int *positive_arr) {
    int positive_count = 0;

    for (int i = 0; i < count; i++) {
        int current_element = src[i];

        if (current_element > 0) {
            positive_arr[positive_count++] = current_element;
        }
    }

    return positive_count;
}

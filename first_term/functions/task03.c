#include <stdio.h>

#define MAX_SIZE 100

void fill_array(int*, size_t);
void print_elements_in_range(int*, size_t, size_t);

int main() {
    int arr[MAX_SIZE];
    fill_array(arr, MAX_SIZE);

    size_t a, b;
    printf("Enter a number: ");
    scanf("%lu", &a);

    printf("Enter another number: ");
    scanf("%lu", &b);

    print_elements_in_range(arr, a, b);

    return 0;
}

void fill_array(int *arr, size_t limit) {
    for(size_t i = 0; i < MAX_SIZE; i++) {
        arr[i] = i;
    }
}

void print_elements_in_range(int *arr, size_t left_index, size_t right_index) {
    for(; left_index <= right_index; left_index++) {
        printf("%d ", arr[left_index]);
    }
    printf("\n");
}

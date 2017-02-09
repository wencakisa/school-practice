#include <stdio.h>

void print_array(int*, size_t);
void swap_values(int*, int*);
void sort(int*, size_t);

int main() {
    size_t n;

    printf("Enter n: ");
    scanf("%ld", &n);
    
    int current, arr[n];
    for(size_t i = 0; i < n; i++) {
        printf("Enter element #%ld: ", i);
        scanf("%d", &current);

        arr[i] = current;
    }

    print_array(arr, n);

    printf("Sorting...\n");
    sort(arr, n);

    print_array(arr, n);

    return 0;
}

void print_array(int *arr, size_t len) {
    for(size_t i = 0; i < len; i++) {
        (i < len - 1) ?
            printf("%d, ", arr[i]) :
            printf("%d\n", arr[i]);
    }
}

void swap_values(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int *arr, size_t len) {
    for(size_t i = 1, j = i; i < len; i++) {
        while(j > 0 && arr[j - 1] > arr[j]) {
            swap_values(&arr[j - 1], &arr[j]);
            j--;
        }
    }
}

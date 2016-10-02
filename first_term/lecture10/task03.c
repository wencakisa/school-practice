#include <stdio.h>

void print_array(int*, size_t);
void swap(int*, int*);
void bubble_sort(int*, size_t);

int main() {
    size_t len;

    do {
        printf("Enter a length: ");
        scanf("%ld", &len);

        if(len < 0) {
            printf("Length can't be negative.\n");
        }
    } while(len < 0);

    int a[len];
    for(int i = 0; i < len; i++) {
        printf("Enter number #%d: ", i);
        scanf("%d", &a[i]);
    }

    print_array(a, len);
    bubble_sort(a, len);
    print_array(a, len);

    return 0;
}

void print_array(int* a, size_t a_len) {
    for(int i = 0; i < a_len; i++) {
        printf(i < a_len - 1 ? "%d, " : "%d\n", a[i]);
    }
}

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void bubble_sort(int* a, size_t a_len) {
    int sorted;

    for(int i = 0; i < a_len; i++) {
        sorted = 1;

        for(int j = 0; j < a_len - 1; j++) {
            if(a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
                sorted = 0;
            }
        }

        if(sorted) {
            break;
        }
    }
}

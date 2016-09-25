#include <stdio.h>

void swap(int*, int*);

int main() {
    int a, b;

    printf("Enter a number: ");
    scanf("%d", &a);

    printf("Enter another number: ");
    scanf("%d", &b);

    swap(&a, &b);

    printf("First number: %d\nSecond number: %d\n", a, b);

    return 0;
}

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

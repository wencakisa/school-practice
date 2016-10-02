#include <stdio.h>

void swap(int*, int*);
void rotr(int*, int*, int*);

int main() {
    int a, b, c, n, i;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        rotr(&a, &b, &c);
    }

    printf("%d %d %d\n", a, b, c);

    return 0;
}

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void rotr(int* a, int* b, int* c) {
    swap(a, c);
    swap(b, c);
}

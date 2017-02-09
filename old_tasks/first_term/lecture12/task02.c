#include <stdio.h>

int gcd(int, int);

int main() {
    int a, b;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    printf("%d\n", gcd(a, b) % 6);

    return 0;
}

int gcd(int a, int b) {
    if(a < 1 || b < 1) {
        printf("Numbers can't be less than 1.");
        return -1;
    }

    int c = 0;
    do {
        c = a % b;
        a = b;
        b = c;
    } while(b != 0);

    return a;
}

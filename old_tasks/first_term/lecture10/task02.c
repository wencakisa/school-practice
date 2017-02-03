#include <stdio.h>

int gcd(int, int);

int main() {
    int a, b;

    printf("Enter a number: ");
    scanf("%d", &a);

    printf("Enter another one: ");
    scanf("%d", &b);

    printf("GCD(%d; %d) = %d\n", a, b, gcd(a, b));

    return 0;
}

int gcd(int a, int b) {
    a = (a >= 0) ? a : -a;
    b = (b >= 0) ? b : -b;

    while(a != b) {
        if(a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }

    return a;
 }

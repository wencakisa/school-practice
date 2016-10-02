#include <stdio.h>

int math_pow(int, int);
int exact_square(int);

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", exact_square(n));

    return 0;
}

int math_pow(int a, int b) {
    if(b == 0) {
        return 1;
    }

    int c = a;
    for(int i = 1; i < b; i++) {
        c *= a;
    }

    return c;
}

int exact_square(int n) {
    for(int i = 1; i < n; i++) {
        if(math_pow(i, 2) == n) {
            return 1;
        }
    }

    return 0;
}

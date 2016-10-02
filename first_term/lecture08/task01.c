#include <stdio.h>

int is_prime(int);

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", is_prime(n));

    return 0;
}

int is_prime(int n) {
    if(n < 2) {
        return -1;
    }

    for(int i = 2; i <= n / 2; i++) {
        if(n % i == 0) {
            return 0;
        }
    }

    return 1;
}

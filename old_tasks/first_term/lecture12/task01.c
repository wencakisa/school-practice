#include <stdio.h>

size_t get_len(int);
int get_multiplier(size_t);
int reverse(int);

int main() {
    int n;
    
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Reversed: %d\n", reverse(n));

    return 0;
}

size_t get_len(int n) {
    size_t len = 0;
    
    for(; n > 0; len++, n /= 10);

    return len;
}

int get_multiplier(size_t len) {
    int multiplier = 1;

    for(size_t i = 0; i < len - 1; i++, multiplier *= 10);

    return multiplier;
}

int reverse(int n) {
    int result = 0;
    size_t len = get_len(n);
    int multiplier = get_multiplier(len);
    
    for(size_t i = 0; i < len; i++) {
        result += (n % 10) * multiplier;

        multiplier /= 10;
        n /= 10;
    }

    return result;
}

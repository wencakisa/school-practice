#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t get_len(int);
char int_to_char(int);
int char_to_int(char);
int get_multiplier(size_t);
int str_to_int(char*);
int reverse(int);

int main() {
    int n;
    
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Result: %d\n", reverse(n));

    return 0;
}

size_t get_len(int n) {
    size_t len = 0;

    while(n > 0) {
        len++;
        n /= 10;
    }

    return len;
}

char int_to_char(int n) {
    return n + '0';
}

int char_to_int(char c) {
    return c - '0';
}

int get_multiplier(size_t len) {
    int multiplier = 1;

    for(size_t i = 0; i < len - 1; i++, multiplier *= 10);

    return multiplier;
}

int str_to_int(char *str) {
    int result = 0;
    size_t len = strlen(str);
    
    int multiplier = get_multiplier(len);
    
    for(size_t i = 0; i < len; i++, multiplier /= 10)
        result += char_to_int(str[i]) * multiplier;

    return result;
}

int reverse(int n) {
    char *n_string = malloc(get_len(n));
    
    for(size_t i = 0; n > 0; i++, n /= 10)
        n_string[i] = int_to_char(n % 10);
    
    return str_to_int(n_string) * 3;
}

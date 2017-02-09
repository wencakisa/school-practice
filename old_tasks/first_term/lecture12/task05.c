#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t get_len(int);
char *dec_to_hex(int);
int is_palindrome(char*);

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("%s\n", is_palindrome(dec_to_hex(n)) ? "True." : "False.");
    
    return 0;
}

size_t get_len(int n) {
    size_t result = 0;
    
    for(; n > 0; result++, n /= 10)

    return result;
}

char *dec_to_hex(int n) {
    char *hex = malloc(get_len(n));
    
    sprintf(hex, "%x", n);

    return hex;
}

int is_palindrome(char *str) {
    for(size_t i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if(str[i] != str[j]) {
            return 0;
        }
    }

    return 1;
}

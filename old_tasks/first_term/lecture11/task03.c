#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* to_hex(int);
int is_hex_palindrome(char*);

static const size_t MAX_LEN = 20;

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    while(!is_hex_palindrome(to_hex(n))) {
        n++;
    }
    
    printf("%s\n", to_hex(n));

    return 0;
}

char* to_hex(int n) {
    char* hex = malloc(sizeof(char) * MAX_LEN);

    sprintf(hex, "%X", n);

    return hex;
}

int is_hex_palindrome(char* s) {
    size_t s_len = strlen(s);
    int j = s_len - 1;

    for(int i = 0; i < s_len; i++) {
        if(s[i] != s[j]) {
            return 0;
        }

        j--;
    }

    free(s);

    return 1;
}

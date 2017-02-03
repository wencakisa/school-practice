#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

int is_palindrome(char*);

int main() {
    char str[MAX_LEN];

    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);

    printf(is_palindrome(str) ? "Palindrome.\n" : "Not a palindrome.\n");

    return 0;
}

int is_palindrome(char *str) {
    size_t len = strlen(str) - 2;

    for(size_t i = 0, j = len; i <= len; i++, j--) {
        if(str[i] != str[j]) {
            return 0;
        }
    }

    return 1;
}

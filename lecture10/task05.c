#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* to_octal(int);
int is_octal_palindrome(char*);

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if(is_octal_palindrome(to_octal(n))) {
        printf("%d is an octal palindrome (%o)\n", n, n);
    }
    else {
        printf("%d is not an octal palindrome (%o)\n", n, n);
    }

    return 0;
}

char* to_octal(int n) {
    char* octal = malloc(sizeof(char) * 100);

    sprintf(octal, "%o", n);

    return octal;
}

int is_octal_palindrome(char* s) {
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 4096

char* to_binary(int);
int is_binary_palindrome(char*);

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Binary: %s\n", to_binary(n));

    return 0;
}

char* to_binary(int n) {
    char binary[MAX_LEN];

    return binary;
}

int is_binary_palindrome(char* s) {
    return 1;
}

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

int is_palindrome(char*);

int main() {
    char user_input[BUFFER_SIZE];
    printf("Enter a word: ");
    fgets(user_input, BUFFER_SIZE, stdin);

    printf("%d\n", is_palindrome(user_input));

    return 0;
}

int is_palindrome(char* s) {
    size_t len = strlen(s) - 2; // \n\0

    int i, j = len;
    for(i = 0; i < len; i++) {
        if(s[i] != s[j]) {
            return 0;
        }

        j--;
    }

    return 1;
}

#include <stdio.h>
#include <string.h>

int is_palindrome(char*);

int main() {
    char user_input[256];
    printf("Enter a string: ");
    fgets(user_input, sizeof(user_input), stdin);

    !is_palindrome(user_input) ?
        printf("%s is a palindrome.\n", strtok(user_input, "\n")) :
        printf("%s is not a palindrome.\n", strtok(user_input, "\n"));

    return 0;
}

int is_palindrome(char* s) {
    size_t len = strlen(s) - 2;
    int i, j = len;

    for(i = 0; i < len; i++) {
        if(s[i] != s[j]) {
            return 1;
        }

        j--;
    }

    return 0;
}

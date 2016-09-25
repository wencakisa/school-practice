#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reversed(char*);

int main() {
    char user_input[256];
    printf("Enter a string: ");
    fgets(user_input, sizeof(user_input), stdin);

    printf("Reversed: %s\n", reversed(user_input));

    return 0;
}

char* reversed(char* s) {
    size_t len = strlen(s) - 2;
    char* s_reversed = malloc(sizeof(char) * len);
    int i, j = 0;

    for(i = len; i >= 0; i--) {
        s_reversed[j] = s[i];
        j += 1;
    }

    return s_reversed;
}

#include <stdio.h>
#include <string.h>

#define MAX_LEN 30

void to_uppercase(char*);
void all_caps(char*);

int main() {
    char input[MAX_LEN];
    
    printf("Enter a string: ");
    fgets(input, MAX_LEN, stdin);

    all_caps(input);

    printf("Uppercased: %s", input);

    return 0;
}

int is_lowercase(char c) {
    return c >= 'a' && c <= 'z';
}

void to_uppercase(char *c) {
    if (is_lowercase(*c)) {
        *c -= ' ';
    }
}

void all_caps(char *s) {
    for (size_t i = 0; i < strlen(s); i++) {
        to_uppercase(&s[i]);   
    }
}

#include <stdio.h>

typedef struct occurance_t {
    int lowercase_count;
    int uppercase_count;
} occurance_t;

int is_lowercase(char);
int is_uppercase(char);

int main() {
    occurance_t occurance;
    occurance.lowercase_count = 0;
    occurance.uppercase_count = 0;

    char input;

    do {
        scanf("%c", &input);

        if (is_lowercase(input)) {
            printf("#\n");
            occurance.lowercase_count++;
        } else if (is_uppercase(input)) {
            printf("*\n");
            occurance.uppercase_count++;
        }
    } while(input != '.');

    printf("Lowercase letters: %d\n", occurance.lowercase_count);
    printf("Uppercase letters: %d\n", occurance.uppercase_count);

    return 0;
}

int is_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

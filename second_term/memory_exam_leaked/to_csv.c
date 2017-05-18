#include <stdio.h>
#include <string.h>

#define MAX_LEN 500
#define SPECIAL_CHAR '*'
#define COMMA ','

int is_alphabetic(char);
void words_to_csv(char*);
void reduce_special_chars(char*);

int main() {
    char str[MAX_LEN] = "This. Is, a, sample   with some%#words";

    words_to_csv(str);

    printf("%s\n", str);

    return 0;
}

int is_alphabetic(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void words_to_csv(char *s) {
    for (size_t i = 0; i < strlen(s); i++) {
        if (!is_alphabetic(s[i])) {
            s[i] = SPECIAL_CHAR;
        }
    }

    reduce_special_chars(s);
}

void reduce_special_chars(char *s) {
    for (size_t i = 0; i < strlen(s); i++) {
    }
}

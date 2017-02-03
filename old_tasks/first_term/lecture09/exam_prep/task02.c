#include <stdio.h>
#include <string.h>

#define BUF_SIZE 256

int is_letter(char);
int count_words(char*);

int main() {
    char user_input[BUF_SIZE];
    fgets(user_input, BUF_SIZE, stdin);

    printf("Count of words: %d\n", count_words(user_input));

    return 0;
}

int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int count_words(char* s) {
    int count = 0;
    char prev;

    for(int i = 0; i < strlen(s); i++) {
        char current = s[i];

        if(!is_letter(current) && is_letter(prev)) {
            count++;
        }

        prev = current;
    }

    return count;
}

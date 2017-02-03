#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int MAX_WORD_LENGTH = 20;
static const int MAX_ATTEMPTS = 10;

char* encrypt(char*);
int hangman(char*);

int main() {
    char word[MAX_WORD_LENGTH];
    printf("Enter a word: ");
    fgets(word, MAX_WORD_LENGTH, stdin);
    strtok(word, "\n");

    hangman(word) ?
        printf("Victory!\n") :
        printf("Defeat!\n");

    return 0;
}

char* encrypt(char* s) {
    size_t len = strlen(s);
    char* encrypted = malloc(sizeof(char) * len);

    for(int i = 0; i < len; i++) {
        encrypted[i] = '*';
    }

    return encrypted;
}

int hangman(char* word) {
    size_t word_length = strlen(word);
    char* encrypted_word = encrypt(word);
    printf("%s\n", encrypted_word);

    char letter;
    for(int i = 0; i < MAX_ATTEMPTS; i++) {
        printf("Enter a letter: ");
        scanf(" %c", &letter);

        for(int j = 0; j < word_length; j++) {
            if(word[j] == letter) {
                encrypted_word[j] = letter;
            }
        }

        printf("%s\n", encrypted_word);

        if(!strcmp(word, encrypted_word)) {
            return 1;
        }
    }

    free(encrypted_word);

    return 0;

}

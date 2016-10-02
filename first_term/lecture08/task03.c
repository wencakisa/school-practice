#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096
#define ALPHABET_LEN 26

typedef struct {
    char symbol;
    int occurrences;
} lowercase_letter;

int is_lowercase(char);
int is_uppercase(char);
int is_letter(char);
char lower(char);
lowercase_letter* get_lowercase_letters();
lowercase_letter* extract_letters_to_lowercase(char*);
int compare_letters(const void*, const void*);
void create_letter_distribution_diagram(char*);

int main() {
    char* user_input = malloc(sizeof(char) * BUF_SIZE);
    fgets(user_input, BUF_SIZE, stdin);
    strtok(user_input, "\n");

    create_letter_distribution_diagram(user_input);

    free(user_input);

    return 0;
}

int is_lowercase(char a) {
    return a >= 'a' && a <= 'z';
}

int is_uppercase(char a) {
    return a >= 'A' && a <= 'Z';
}

int is_letter(char a) {
    return is_lowercase(a) || is_uppercase(a);
}

char lower(char a) {
    if(is_uppercase(a)) {
        a += 'a' - 'A';
    }

    return a;
}

lowercase_letter* get_lowercase_letters() {
    size_t len = ALPHABET_LEN;
    lowercase_letter* lowercase = malloc(sizeof(lowercase_letter) * len);

    for(int i = 0; i < len; i++) {
        lowercase_letter l;
        l.symbol = 'a' + i;
        l.occurrences = 0;

        lowercase[i] = l;
    }

    return lowercase;
}

lowercase_letter* extract_letters_to_lowercase(char* s) {
    size_t len = strlen(s);
    lowercase_letter* letters = malloc(sizeof(lowercase_letter) * len);

    int j = 0;
    for(int i = 0; i < len; i++) {
        char current = s[i];
        if(is_letter(current)) {
            lowercase_letter l;
            l.symbol = lower(current);
            l.occurrences = 0;

            letters[j] = l;
            j++;
        }
    }

    return letters;
}

int compare_letters(const void* a, const void* b) {
    lowercase_letter* letter1 = (lowercase_letter*)a;
    lowercase_letter* letter2 = (lowercase_letter*)b;

    int diff = letter1->occurrences - letter2->occurrences;

    if(diff) {
        return -diff;
    }

    return letter1->symbol - letter2->symbol;
}

void create_letter_distribution_diagram(char* s) {
    lowercase_letter* letters = extract_letters_to_lowercase(s);
    lowercase_letter* lowercase_letters = get_lowercase_letters();

    for(int i = 0; i < ALPHABET_LEN; i++) {
        for(int j = 0; j < strlen(s); j++) {
            if(lowercase_letters[i].symbol == letters[j].symbol) {
                lowercase_letters[i].occurrences++;
            }
        }
    }

    qsort(lowercase_letters, ALPHABET_LEN, sizeof(lowercase_letter), compare_letters);

    for(int i = 0; i < ALPHABET_LEN; i++) {
        lowercase_letter current = lowercase_letters[i];
        printf("%c - %d\n", current.symbol, current.occurrences);
    }

    free(letters);
    free(lowercase_letters);
}

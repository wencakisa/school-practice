#include <stdio.h>
#include <string.h>

#define DECK_LEN 14
#define ACE 'A'
#define KING 'K'
#define QUEEN 'Q'
#define JACK 'J'
#define TEN 'T'

void swap_chars(char*, char*);
void convert_deck_alphabetics_to_consecutive(char*);
void convert_deck_alphabetics_to_original(char*);
void sort_deck(char*);

int main() {
    char deck[DECK_LEN];
    fgets(deck, DECK_LEN, stdin);

    sort_deck(deck);

    printf("%s\n", deck);

    return 0;
}

void swap_chars(char *a, char *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int is_numeric(char c) {
    return (c >= '2' && c <= '9');
}

void convert_deck_alphabetics_to_consecutive(char *deck) {
    for(int i = 0; i < strlen(deck); i++) {
        if(!is_numeric(deck[i])) {
            // JQKAT -> UVWXT
            deck[i] = (deck[i] == ACE) ? 'X' : (deck[i] == KING) ? 'W' : (deck[i] == QUEEN) ? 'V' : (deck[i] == JACK) ? 'U' : TEN;
        }
    }
}

void convert_deck_alphabetics_to_original(char *deck) {
    for(int i = 0; i < strlen(deck); i++) {
        if(!is_numeric(deck[i])) {
            // UVWXT -> JQKAT
            deck[i] = (deck[i] == 'X') ? ACE : (deck[i] == 'W') ? KING : (deck[i] == 'V') ? QUEEN : (deck[i] == 'U') ? JACK : TEN;
        }
    }
}

void sort_deck(char *deck) {
    convert_deck_alphabetics_to_consecutive(deck);

    for(int i = 1; i < strlen(deck); i++) {
        char next = deck[i];
        int j = i;

        while(j > 0 && deck[j - 1] > next) {
            swap_chars(&deck[j - 1], &deck[j]);
            j--;
        }

        next = deck[j];
    }

    convert_deck_alphabetics_to_original(deck);
}

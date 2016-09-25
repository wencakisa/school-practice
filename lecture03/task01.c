#include <stdio.h>
#include <string.h>

void swap_values(char*, char*);

int main() {
    char deck[13];
    fgets(deck, sizeof(deck), stdin);
    printf("%s\n", deck);

    size_t deck_length = strlen(deck);

    int i;
    for(i = 0; i < deck_length; i++) {
        char current = deck[i];

        if(current >= '2' && current <= '9') {

        }
        else if(current == 'T') {

        }
        else if(current == 'J') {

        }
        else if(current == 'Q') {

        }
        else if(current == 'K') {
            
        }
    }


    return 0;
}

void swap_values(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

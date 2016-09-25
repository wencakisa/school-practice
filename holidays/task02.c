#include <stdio.h>
#include <string.h>

#define MAX_LETTERS_PER_BUTTON 5
#define BUTTONS 9
#define MAX_MESSAGE_LENGTH 160

static char KEYBOARD[BUTTONS][MAX_LETTERS_PER_BUTTON] = {
    " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

int get_clicks_to_write(char*);

int main() {
    char user_input[MAX_MESSAGE_LENGTH];
    fgets(user_input, MAX_MESSAGE_LENGTH, stdin);
    strtok(user_input, "\n");

    printf("%d\n", get_clicks_to_write(user_input));

    return 0;
}

int get_clicks_to_write(char* s) {
    int clicks = 0;

    for(int i = 0; i < strlen(s); i++) {
        char current = s[i];

        for(int j = 0; j < BUTTONS; j++) {
            char* letters = KEYBOARD[j];

            for(int x = 0; x < strlen(letters); x++) {
                if(letters[x] == current) {
                    clicks += x + 1;
                    break;
                }
            }
        }
    }

    return clicks;
}

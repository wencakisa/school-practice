#include <stdio.h>
#include <string.h>

const char* EXIT_COMMAND = "exit";

char capitalize(char);
void print_capitalized(char*);

int main() {
    while(1) {
        char user_input[256];
        printf("> ");
        fgets(user_input, sizeof(user_input), stdin);
        strtok(user_input, "\n");

        if(!strcmp(user_input, EXIT_COMMAND)) {
            printf("Goodbye!\n");
            break;
        }

        print_capitalized(user_input);
        printf("\n");
    }

    return 0;
}

char capitalize(char ch) {
    char capital_char = ch - ('a' - 'A');

    if(capital_char >= 'A' && capital_char <= 'Z') {
        return capital_char;
    }

    return ch;
}

void print_capitalized(char* s) {
    int i;
    for(i = 0; i < strlen(s); i++) {
        printf("%c", capitalize(s[i]));
    }
}

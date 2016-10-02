#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int MAGIC_NUMBER = 42043951;
static const size_t MAGIC_NUMBER_SIZE = sizeof(MAGIC_NUMBER);
static const char* EXIT_COMMAND = "exit";

int main() {
    char user_input[MAGIC_NUMBER_SIZE];
    char magic_number_str[MAGIC_NUMBER_SIZE];
    sprintf(magic_number_str, "%d", MAGIC_NUMBER);

    while(1) {
        printf("Enter a number: ");
        scanf("%99s", user_input);

        if(!strcmp(user_input, EXIT_COMMAND)) {
            printf("Goodbye!\n");
            break;
        }

        size_t user_input_len = strlen(user_input);
        int bulls = 0, cows = 0;

        for(int i = 0; i < user_input_len; i++) {
            if(user_input[i] == magic_number_str[i]) {
                bulls++;
            }
            else {
                cows++;
            }
        }

        printf("Bulls: %d\nCows: %d\n", bulls, cows);
    }

    return 0;
}

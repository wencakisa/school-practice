#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_duplicates(char*);
void print_duplicates(char*, char*);

int main() {
    int user_input;
    scanf("%d", &user_input);

    char user_input_to_string[10];
    sprintf(user_input_to_string, "%d", user_input);

    char* duplicates = get_duplicates(user_input_to_string);

    if(strlen(duplicates)) {
        print_duplicates(user_input_to_string, duplicates);
    }
    else {
        printf("Sequence is unique.\n");
    }

    return 0;
}

char* get_duplicates(char* s) {
    int i, j, duplicates_index = 0, s_len = strlen(s);

    /*
        The local variables have a lifetime which extends only inside the block in which it is defined.
        The moment he control goes outside the block in which the local variable is defined,
        the storage for the variable is no more allocated (not guaranteed).
        Therefore using the memory address of the variable outside
        the lifetime area of the variable will be undefined behaviour.

         malloc(sizeof(char) * required_length);
    */
    char* duplicates = malloc(sizeof(char) * s_len);

    for(i = 0; i < s_len; i++) {
        char current = s[i];

        for(j = i + 1; j < s_len; j++) {
            if(s[j] == current) {
                duplicates[duplicates_index] = current;
                duplicates_index += 1;
                break;
            }
        }
    }

    return duplicates;
}

void print_duplicates(char* s, char* duplicates) {
    int i, j, duplicates_len = strlen(duplicates), s_len = strlen(s);

    printf("Duplicates: \n");

    for(i = 0; i < duplicates_len; i++) {
        char current = duplicates[i];
        int current_count = 0;

        for(j = 0; j < s_len; j++) {
            if(current == s[j]) {
                current_count += 1;
            }
        }

        current_count > 1 ?
            printf("%c - %d times\n", current, current_count) :
            printf("%c - %d time\n", current, current_count);
    }
}

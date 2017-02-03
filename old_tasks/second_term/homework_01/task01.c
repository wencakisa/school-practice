#include <stdio.h>

#include "hash.h"

static const int MAX_WORD_LEN = 200;

int main() {
    char user_input[MAX_WORD_LEN];
    fgets(user_input, MAX_WORD_LEN, stdin);
    strtok(user_input, "\n");

    printf("%ld\n", hash(user_input));

    return 0;
}

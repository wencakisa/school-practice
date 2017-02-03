#include <stdio.h>

#include "hash.h"

static const char* MAGIC_WORD = "vsmisal";
static const int MAX_WORD_LEN = 200;
static const int MAX_OCCURANCES = 2000;

typedef struct {
    int occurances;
    long hash;
} occurance_t;

occurance_t max_occurance(occurance_t*, int);

int main() {
    char user_input[MAX_WORD_LEN];

    int i = 0, is_there = 0;
    occurance_t occurances[MAX_OCCURANCES];

    while(strcmp(user_input, MAGIC_WORD)) {
        fgets(user_input, MAX_WORD_LEN, stdin);
        strtok(user_input, "\n");

        occurances[i].hash = hash(user_input);
        occurances[i].occurances = 0;

        i++;
    }

    int length = i;

    for(i = 0; i < length; i++) {
        for(int j = 1; j < length; j++) {
            if(occurances[i].hash == occurances[j].hash) {
                occurances[i].occurances++;
            }
        }
    }

    occurance_t max = max_occurance(occurances, length);

    printf("%d %ld\n", max.occurances, max.hash);

    return 0;
}

occurance_t max_occurance(occurance_t* occurances, int len) {
    occurance_t max;
    max.occurances = occurances[0].occurances;
    max.hash = occurances[0].hash;

    for(int i = 1; i < len; i++) {
        if(occurances[i].occurances > max.occurances) {
            max.occurances = occurances[i].occurances;
            max.hash = occurances[i].hash;
        }
    }

    return max;
}

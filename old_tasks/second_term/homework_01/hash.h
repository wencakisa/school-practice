#include <string.h>

long hash(char* word) {
    long result = 42;

    for(int i = 0; i < strlen(word); i++) {
        result += (int)word[i] * (i + 1);
    }

    return result;
}

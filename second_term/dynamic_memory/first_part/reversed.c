#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 5;
    int count = 0;
    
    char *str = calloc(size, sizeof(char));
    
    while (scanf("%c", &str[count++]) != EOF) {
        if (size == count) {
            size *= 2;

            str = (char*) realloc(str, size);
        }
    }
   
    for (size_t i = count - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    free(str);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const int MAX_LEN = 1024;

int reversed(int);

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("%d\n", reversed(n));

    return 0;
}

int reversed(int n) {
    char* reversed = malloc(sizeof(char) * MAX_LEN);
    char* current_value = malloc(sizeof(char) * 2);

    while(n > 0) {
        sprintf(current_value, "%d", n % 10);
        strcat(reversed, current_value);

        n /= 10;
    }

    free(current_value);

    return strtol(reversed, NULL, 10) * 7;
}

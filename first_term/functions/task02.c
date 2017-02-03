#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

int strcompare(char*, char*);

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];

    printf("Enter a string: ");
    fgets(str1, MAX_LEN, stdin);

    printf("Enter anoter string: ");
    fgets(str2, MAX_LEN, stdin);

    printf("%d\n", strcompare(str1, str2));

    return 0;
}

int strcompare(char *str1, char *str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    if(len1 != len2) {
        return 1;
    }

    size_t len = len1 - 1;

    for(size_t i = 0; i < len; i++) {
        if(str1[i] != str2[i]) {
            return 1;
        }
    }

    return 0;
}

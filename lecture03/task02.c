#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int i, j;
    char stars[1024] = "*";
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i; j++) {
            printf(" ");
        }

        printf("%s\n", stars);
        strcat(stars, "**");
    }

    return 0;
}

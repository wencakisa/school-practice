#include <stdio.h>

int main() {
    int n, v, p;

    printf("n: ");
    scanf("%d", &n);

    do {
        printf("v: ");
        scanf("%d", &v);

        if(v != 0 && v != 1) {
            printf("Required range: (0; 1)\n");
        }
    } while(v != 0 && v != 1);

    do {
        printf("p: ");
        scanf("%d", &p);

        if(p < 0 || p > 7) {
            printf("Required range: (0; 7);\n");
        }
    } while(p < 0 || p > 7);

    n ^= (-v ^ n) & (1 << p);

    printf("%d\n", n);

    return 0;
}

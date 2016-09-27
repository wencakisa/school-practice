#include <stdio.h>

unsigned int get_bit_at_position_a(int, int);

int main() {
    int a, b;

    do {
        printf("a: ");
        scanf("%d", &a);

        if(a < 0 || a > 7) {
            printf("Required range: (0; 7);\n");
        }
    } while(a < 0 || a > 7);

    do {
        printf("b: ");
        scanf("%d", &b);

        if(b < 0 || b > 200) {
            printf("Required range: (0; 200);\n");
        }
    } while(b < 0 || b > 200);

    printf("Bit #%d of %d is %d\n", a, b, get_bit_at_position_a(a, b));
    return 0;
}

unsigned int get_bit_at_position_a(int a, int b) {
    return (b & (1 << a)) >> a;
}

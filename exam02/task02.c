#include <stdio.h>

int bitswap(int, int, int);

int main() {
    int number, first_bit_index, second_bit_index;
    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Enter first bit index: ");
    scanf("%d", &first_bit_index);

    printf("Enter second bit index: ");
    scanf("%d", &second_bit_index);

    printf("%d\n", bitswap(number, first_bit_index, second_bit_index));

    return 0;
}

int bitswap(int n, int b1, int b2) {
    return ((n >> b1) & 1) | ((n >> b2) & 1);
}

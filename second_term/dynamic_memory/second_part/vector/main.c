#include <stdio.h>
#include "vector.h"

int main() {
    vector_t vector = init();

    for (size_t i = 0; i < SIZE; i++) {
        insert_at(&vector, i, i);
    }

    print_vector_info(vector);

    for (size_t i = SIZE; i <= SIZE * 2 - 1; i++) {
        insert_at(&vector, i, i);
    }

    print_vector_info(vector);

    add_last(&vector, SIZE * 2);

    print_vector_info(vector);

    for (size_t i = 0; i < SIZE; i++) {
        pop(&vector);
    }

    print_vector_info(vector);

    destroy(&vector);

    print_vector_info(vector);

    return 0;
}

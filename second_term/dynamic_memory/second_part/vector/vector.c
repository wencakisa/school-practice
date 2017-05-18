#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

vector_t init() {
    vector_t result = {
        .size = SIZE,
        .elements_count = 0
    };
    result.elements = calloc(result.size, sizeof(int));

    return result;
}

int at(vector_t vector, int index) {
    return vector.elements[index];
}

int first(vector_t vector) {
    return at(vector, 0);
}

int last(vector_t vector) {
    return at(vector, vector.elements_count - 1);
}

int count_equals(vector_t vector, int size) {
    return vector.elements_count == size;
}

int empty(vector_t vector) {
    return count_equals(vector, 0);
}

int full(vector_t vector) {
    return count_equals(vector, vector.size);
}

int can_reduce_size(vector_t vector) {
    return vector.size / 2 >= SIZE && vector.size > vector.elements_count * 2 + 1;
}

void insert_at(vector_t *vector, int index, int item) {
    if (full(*vector)) {
        vector->size *= 2;
        vector->elements = realloc(vector->elements, vector->size * sizeof(int));
    }

    vector->elements[index] = item;
    vector->elements_count++;
}

void add_first(vector_t *vector, int item) {
    insert_at(vector, 0, item);
}

void add_last(vector_t *vector, int item) {
    insert_at(vector, vector->elements_count, item);
}

void remove_at(vector_t *vector, int index) {
    vector->elements[index] = vector->elements[index + 1];
    vector->elements_count--;

    if (can_reduce_size(*vector)) {
        vector->size /= 2;
        vector->elements = realloc(vector->elements, vector->size * sizeof(int));
    }
}

int pop(vector_t *vector) {
    int last_element = last(*vector);

    if (!empty(*vector)) {
        remove_at(vector, vector->elements_count);
    }

    return last_element;
}

void destroy(vector_t *vector) {
    vector->size = 0;
    vector->elements_count = 0;
    free(vector->elements);
}

void print_array(int *arr, int size) {
    printf("[");
    for (size_t i = 0; i < size; i++) {
        if (i % 10 == 0) {
            printf("\n    ");
        }

        printf((i < size - 1) ? "%d, " : "%d\n", arr[i]);
    }
    printf("]\n");
}

void print_vector_info(vector_t vector) {
    printf("Size: %d\n", vector.size);
    printf("Current elements count: %d\n", vector.elements_count);
    printf("Elements: ");
    print_array(vector.elements, vector.elements_count);
    printf("Full: %s\n", full(vector) ? "yes" : "no");
    printf("Empty: %s\n", empty(vector) ? "yes" : "no");
    printf("First element: %d\n", first(vector));
    printf("Last element: %d\n", last(vector));
}

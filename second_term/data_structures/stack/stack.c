#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

stack_t create_stack(int *initial_data, int initial_size, int initial_capacity) {
    stack_t stack = {
        .data = initial_data,
        .size = initial_size,
        .capacity = initial_capacity
    };

    return stack;
}

stack_t init_stack(int initial_capacity) {
    return create_stack(calloc(initial_capacity, sizeof(int)), 0, initial_capacity);
}

void destroy_stack(stack_t *stack) {
    free(stack->data);
    stack->data = NULL;
    stack->size = 0;
    stack->capacity = 0;
}

int size(stack_t stack) {
    return stack.size;
}

int is_empty(stack_t stack) {
    return size(stack) == 0;
}

int is_full(stack_t stack) {
    return size(stack) == stack.capacity;
}

int top(stack_t stack) {
    return !is_empty(stack) ? stack.data[size(stack) - 1] : -1;
}

void push(stack_t *stack, int elem) {
    if (is_full(*stack)) {
        resize_stack(stack);
    }

    stack->data[stack->size++] = elem;
}

int pop(stack_t *stack) {
    int result = top(*stack);

    if (!is_empty(*stack)) {
        stack->data[stack->size--] = 0;
    }

    return result;
}

void resize_stack(stack_t *stack) {
    stack->capacity *= 2;
    stack->data = (int*) realloc(stack->data, stack->capacity * sizeof(int));
}

int* copy_array(int *array, int size) {
    int *result = calloc(size, sizeof(int));

    for (size_t i = 0; i < size; i++) {
        result[i] = array[i];
    }

    return result;
}

stack_t copy_stack(stack_t stack) {
    return create_stack(copy_array(stack.data, size(stack)), size(stack), stack.capacity);
}

void print_array(int *array, int size) {
    printf("[");
    for (size_t i = 0; i < size; i++) {
        printf((i < size - 1) ? "%d, " : "%d", array[i]);
    }
    printf("]\n");
}

void print_stack(stack_t stack) {
    printf("Data: ");
    print_array(stack.data, size(stack));
    printf("Count: %d\n", size(stack));
    printf("Size: %d\n", stack.capacity);
}

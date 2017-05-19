#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

stack_t init_stack(int initial_capacity) {
    stack_t result = {
        .data = calloc(initial_capacity, sizeof(int)),
        .size = 0,
        .capacity = initial_capacity
    };

    return result;
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

void copy_array(int *src, int *dest, int size) {
    for (size_t i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

stack_t copy_stack(stack_t stack) {
    stack_t result = {
        .size = size(stack),
        .capacity = stack.capacity
    };

    copy_array(stack.data, result.data, size(result));

    return result;
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

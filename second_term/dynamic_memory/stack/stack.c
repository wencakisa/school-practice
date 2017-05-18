#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

stack_t stack_init(int initial_capacity) {
	stack_t result = {
		.data = calloc(initial_capacity, sizeof(int)),
		.top = 0,
		.capacity = initial_capacity
	};

	return result;
}

void stack_destroy(stack_t *stack) {
	free(stack->data);
	stack->data = NULL;
	stack->top = 0;
	stack->capacity = 0;
}

int size(stack_t stack) {
	return stack.top;
}

int is_full(stack_t stack) {
	return size(stack) == stack.capacity;
}

int is_empty(stack_t stack) {
	return size(stack) == 0;
}

int top(stack_t stack) {
	return !is_empty(stack) ? stack.data[stack.top - 1] : -1;
}

void push(stack_t *stack, int elem) {
	if (is_full(*stack)) {
		stack_resize(stack);
	}

	stack->data[stack->top++] = elem;
}

int pop(stack_t *stack) {
	int result = stack->data[stack->top - 1];

	if (!is_empty(*stack)) {
		stack->data[stack->top--] = 0;
	}

	return result;
}

void stack_resize(stack_t *stack) {
	stack->capacity *= 2;
	stack->data = realloc(stack->data, stack->capacity * sizeof(int));
}

void array_copy(int *src, int *dest, int size) {
    for (size_t i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

stack_t stack_copy(stack_t stack) {
	stack_t result = {
		.data = calloc(stack.capacity, sizeof(int)),
		.top = stack.top,
		.capacity = stack.capacity
	};

    array_copy(stack.data, result.data, result.top);

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
	printf("Elements: ");
	print_array(stack.data, stack.top);
	printf("Top element: %d\n", top(stack));
	printf("Size: %d\n", size(stack));
	printf("Capacity: %d\n", stack.capacity);
}

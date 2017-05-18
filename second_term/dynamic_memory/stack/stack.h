#ifndef STACK_H_
#define STACK_H

typedef struct stack_t {
	int *data;
	int top;
	int capacity;
} stack_t;

stack_t stack_init(int);
void stack_destroy(stack_t*);
int size(stack_t);
int is_full(stack_t);
int is_empty(stack_t);
int top(stack_t);
void push(stack_t*, int);
int pop(stack_t*);
void stack_resize(stack_t*);
void array_copy(int*, int*, int);
stack_t stack_copy(stack_t);
void print_array(int*, int);
void print_stack(stack_t);

#endif

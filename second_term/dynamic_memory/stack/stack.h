#ifndef STACK_H_
#define STACK_H_

typedef struct stack_t {
    int *data;
    int size;
    int capacity;
} stack_t;

stack_t init_stack(int);
void destroy_stack(stack_t*);
int size(stack_t);
int is_empty(stack_t);
int is_full(stack_t);
int top(stack_t);
void push(stack_t*, int);
int pop(stack_t*);
void resize_stack(stack_t*);
void copy_array(int*, int*, int);
stack_t copy_stack(stack_t);
void print_array(int*, int);
void print_stack(stack_t);

#endif

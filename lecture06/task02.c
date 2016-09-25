#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

static const char* OPERATOR_ADD = "+";
static const char* OPERATOR_SUB = "-";
static const char* OPERATOR_MUL = "*";
static const char* OPERATOR_DIV = "/";

typedef struct {
    int elements[MAX_SIZE];
    int top;
} stack;

int pop(stack*);
void push(stack*, int);
void display(stack*);
void add(stack*);
void subtract(stack*);
void multiply(stack*);
void divide(stack*);


int main() {
    char user_input[MAX_SIZE];
    fgets(user_input, MAX_SIZE, stdin);

    stack s;
    s.top = -1;

    strtok(user_input, "\n");

    char* token = strtok(user_input, " ");
    int number_to_add;

    while(token != NULL) {
        if(!strcmp(token, OPERATOR_ADD)) {
            add(&s);
        }
        else if(!strcmp(token, OPERATOR_SUB)) {
            subtract(&s);
        }
        else if(!strcmp(token, OPERATOR_MUL)) {
            multiply(&s);
        }
        else if(!strcmp(token, OPERATOR_DIV)) {
            divide(&s);
        }
        else {
            sscanf(token, "%d", &number_to_add);
            push(&s, number_to_add);
        }

        token = strtok(NULL, " ");
    }

    display(&s);

    return 0;
}

int pop(stack* s) {
    if(s->top == -1) {
        printf("Stack is empty.\n");
    }

    int num = s->elements[s->top];
    s->top--;

    return num;
}

void push(stack* s, int i) {
    size_t max_len = sizeof(s->elements) / sizeof(s->elements[0]);

    if(s->top == max_len - 1) {
        printf("Stack is full.\n");
        return;
    }

    s->top++;
    s->elements[s->top] = i;
}

void display(stack* s) {
    int len = s->top;

    for(int i = 0; i <= len; i++) {
        printf("%d\n", pop(s));
    }
}

void add(stack* s) {
    int result = 0;

    while(s->top != -1) {
        result += pop(s);
    }

    push(s, result);
}

void subtract(stack* s) {
    int right_operand = pop(s);
    int left_operand = pop(s);

    push(s, left_operand - right_operand);
}

void multiply(stack* s) {
    push(s, pop(s) * pop(s));
}

void divide(stack* s) {
    int denominator = pop(s);

    if(denominator != 0) {
        int numerator = pop(s);

        push(s, numerator / denominator);
    }
    else {
        printf("Division by zero!\n");
        exit(1);
    }

}

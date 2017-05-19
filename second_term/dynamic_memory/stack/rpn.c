#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "stack.h"

#define SIZE 50
#define OPERANDS "0123456789"
#define OPERATORS "+-*/^%"
#define DELIMITER " "

int contains_all(char*, char*);
int is_operand(char*);
int is_operator(char*);
int do_operation(stack_t*, char);
int rpn_solve(char*);
void print_expression(char*);

int main() {
    char rpn_exp[SIZE] = "5 1 2 + 4 * + 3 -";

    print_expression(rpn_exp);

    strcpy(rpn_exp, "9 5 3 + 2 4 ^ - +");
    print_expression(rpn_exp);

    strcpy(rpn_exp, "162 2 1 + 4 ^ /");
    print_expression(rpn_exp);

    strcpy(rpn_exp, "thisisinvalid");
    print_expression(rpn_exp);

    return 0;
}

int contains_all(char *collection, char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (strchr(collection, str[i]) == NULL) {
            return 0;
        }
    }

    return 1;
}

int is_operand(char *s) {
    return contains_all(OPERANDS, s);
}

int is_operator(char *s) {
    return contains_all(OPERATORS, s);
}

int do_operation(stack_t *stack, char operator) {
    int second_operand = pop(stack);
    int first_operand = pop(stack);

    switch(operator) {
        case '+':
            return first_operand + second_operand;
        case '-':
            return first_operand - second_operand;
        case '*':
            return first_operand * second_operand;
        case '/':
            return first_operand / second_operand;
        case '^':
            return pow(first_operand, second_operand);
        case '%':
            return first_operand % second_operand;
    }

    return 0;
}

int rpn_solve(char *rpn_exp) {
    stack_t digits = init_stack(strlen(rpn_exp) / 2);

    char *token = strtok(rpn_exp, DELIMITER);
    while (token != NULL) {
        if (is_operand(token)) {
            push(&digits, strtol(token, NULL, 10));
        } else if (is_operator(token)) {
            push(&digits, do_operation(&digits, token[0]));
        }

        token = strtok(NULL, DELIMITER);
    }

    int result = top(digits);
    destroy_stack(&digits);

    return result;
}

void print_expression(char *expression) {
    char exp_copy[SIZE];
    strcpy(exp_copy, expression);
    printf("%s = %d\n", exp_copy, rpn_solve(expression));
}

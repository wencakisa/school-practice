#include <stdio.h>
#include <string.h>

#include "stack.h"

#define SIZE 50
#define DIGITS "0123456789"
#define OPERATIONS "+-*/"

int is_in_string(char, char*);
int is_digit(char);
int is_operator(char);
int to_integer(char);
float do_operation(int, int, char);
float rpn_solve(char*);

int main() {
    char rpn_exp[SIZE] = "5 1 2 + 4 * + 3 -";

    printf("RPN expression: %s\n", rpn_exp);
    printf("Solved: %.2f\n", rpn_solve(rpn_exp));

	return 0;
}

int is_in_string(char c, char *str) {
    return strchr(str, c) != NULL;
}

int is_digit(char c) {
    return is_in_string(c, DIGITS);
}

int is_operator(char c) {
    return is_in_string(c, OPERATIONS);
}

int to_integer(char c) {
    return c - '0';
}

float do_operation(int first_operand, int second_operand, char operator) {
    float result = 0.0f;

    switch(operator) {
        case '+':
            result = first_operand + second_operand;
            break;
        case '-':
            result = first_operand - second_operand;
            break;
        case '*':
            result = first_operand * second_operand;
            break;
        case '/':
            result = first_operand / second_operand;
            break;
    }

    return result;
}

float rpn_solve(char *rpn_exp) {
    // TODO: Make it work with numbers too, not only digits.
    // Hint: strtok() from <string.h>

    float result = 0.0f;
    size_t len = strlen(rpn_exp);
    stack_t digits = stack_init(len / 2);

    for (size_t i = 0; i < len; i++) {
        char current = rpn_exp[i];

        if (is_digit(current)) {
            push(&digits, to_integer(current));
        } else if (is_operator(current)) {
            int second_operand = pop(&digits);
            int first_operand = pop(&digits);

            result = do_operation(first_operand, second_operand, current);
            push(&digits, result);
        }
    }

    stack_destroy(&digits);

    return result;
}

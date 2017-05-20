#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "calculator.h"

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

int solve(char *rpn_exp) {
    size_t len = strlen(rpn_exp);

    char exp_copy[len];
    strcpy(exp_copy, rpn_exp);

    stack_t operands = init_stack(len / 2);
    int result = top(operands);

    char *token = strtok(exp_copy, DELIMITER);
    while (token != NULL) {
        if (is_operand(token)) {
            push(&operands, strtol(token, NULL, 10));
        } else if (is_operator(token)) {
            char operator = token[0];
            result = do_operation(&operands, operator);

            push(&operands, result);
        }

        token = strtok(NULL, DELIMITER);
    }

    destroy_stack(&operands);

    return result;
}

rpn_calculator_t init_calculator(char *expression) {
    rpn_calculator_t calculator = {
        .expression = expression,
        .result = solve(expression)
    };

    return calculator;
}

int get_result(rpn_calculator_t calculator) {
    return calculator.result;
}

void print_calculator(rpn_calculator_t calculator) {
    printf("%s = %d\n", calculator.expression, get_result(calculator));
}

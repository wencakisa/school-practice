#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "calculator.h"

int is_operand(char *str) {
    return !strcspn(str, OPERANDS);
}

int is_operator(char *str) {
    return !strcspn(str, OPERATORS);
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
    size_t exp_len = strlen(rpn_exp);

    char exp_copy[exp_len];
    strcpy(exp_copy, rpn_exp);

    stack_t operands = init_stack(exp_len / 2);
    int result = top(operands);

    char *token = strtok(exp_copy, DELIMITER);
    while (token != NULL) {
        if (is_operand(token)) {
            push(&operands, strtol(token, NULL, 10));
        } else if (is_operator(token)) {
            result = do_operation(&operands, token[0]);
            push(&operands, result);
        }

        token = strtok(NULL, DELIMITER);
    }

    destroy_stack(&operands);

    return result;
}

void set_expression(rpn_calculator_t *calculator, char *expression) {
    calculator->expression = expression;
    calculator->result = solve(calculator->expression);
}

rpn_calculator_t init_calculator(char *expression) {
    rpn_calculator_t calculator;
    set_expression(&calculator, expression);

    return calculator;
}

int get_result(rpn_calculator_t calculator) {
    return calculator.result;
}

void print_result(rpn_calculator_t calculator) {
    printf("Result: %d\n", get_result(calculator));
}

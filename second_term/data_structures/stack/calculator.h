#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "stack.h"

#define OPERANDS "0123456789"
#define OPERATORS "+-*/^%"
#define DELIMITER " "

typedef struct rpn_calculator_t {
    char *expression;
    int result;
} rpn_calculator_t;

int is_operand(char*);
int is_operator(char*);
int do_operation(stack_t*, char);
int solve(char*);
void set_expression(rpn_calculator_t*, char*);
rpn_calculator_t init_calculator(char*);
int get_result(rpn_calculator_t);
void print_result(rpn_calculator_t);

#endif

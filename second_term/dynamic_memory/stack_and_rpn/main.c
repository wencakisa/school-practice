#include <string.h>

#include "calculator.h"

#define SIZE 50

int main() {
    char rpn_exp[SIZE] = "5 1 2 + 4 * + 3 -";
    rpn_calculator_t calculator = init_calculator(rpn_exp);
    print_result(calculator);

    set_expression(&calculator, "6   5     3  + 2 4 ^ - +");
    print_result(calculator);

    set_expression(&calculator, "162  2  1 + 4  ^ /");
    print_result(calculator);

    set_expression(&calculator, "this 123 is 456  invalid");
    print_result(calculator);

    return 0;
}

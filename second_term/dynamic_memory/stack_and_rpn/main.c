#include "calculator.h"

int main() {
    rpn_calculator_t calculator = init_calculator("5 1 2 + 4 * 3 - +");
    print_result(calculator);

    set_expression(&calculator, "6   5     3  + 2 4 ^ - +");
    print_result(calculator);

    set_expression(&calculator, "162  2  1 + 4  ^ /");
    print_result(calculator);

    set_expression(&calculator, "this 123 is 456  invalid");
    print_result(calculator);

    return 0;
}

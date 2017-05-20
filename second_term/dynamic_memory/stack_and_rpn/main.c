#include <string.h>

#include "rpn/calculator.h"

#define SIZE 50

int main() {
    char rpn_exp[SIZE] = "5 1 2 + 4 * + 3 -";
    rpn_calculator_t calculator = init_calculator(rpn_exp);

    print_calculator(calculator);

    strcpy(rpn_exp, "9 5 3 + 2 4 ^ - +");
    calculator = init_calculator(rpn_exp);
    print_calculator(calculator);

    strcpy(rpn_exp, "162 2 1 + 4 ^ /");
    calculator = init_calculator(rpn_exp);
    print_calculator(calculator);

    strcpy(rpn_exp, "this 123 is 456 invalid");
    calculator = init_calculator(rpn_exp);
    print_calculator(calculator);

    return 0;
}

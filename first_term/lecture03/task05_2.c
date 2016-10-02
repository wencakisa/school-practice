#include <stdio.h>
#include <string.h>

#define OPERATION_ADD "add"
#define OPERATION_SUBTRACT "sub"
#define OPERATION_MULTIPLY "mul"
#define OPERATION_DIVIDE "div"
#define OPERATION_MODULO "mod"

int main() {
    int number1;
    printf("Enter a number: ");
    scanf("%d", &number1);

    char* operation;
    printf("Enter an operation: ");
    scanf("%s", operation);

    int number2;
    printf("Enter another number: ");
    scanf("%d", &number2);

    int result;

    if(!strcmp(operation, OPERATION_ADD)) {
        result = number1 + number2;
    }
    else if(!strcmp(operation, OPERATION_SUBTRACT)) {
        result = number1 - number2;
    }
    else if(!strcmp(operation, OPERATION_MULTIPLY)) {
        result = number1 * number2;
    }
    else if(!strcmp(operation, OPERATION_DIVIDE)) {
        result = number1 / number2;
    }
    else if(!strcmp(operation, OPERATION_MODULO)) {
        result = number1 % number2;
    }
    else {
        printf("Invalid operation!\n");
        return 1;
    }

    printf("Result: %d\n", result);

    return 0;
}

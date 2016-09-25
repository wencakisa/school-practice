#include <stdio.h>
#include <string.h>

#define OPERATION_ADD "add"
#define OPERATION_SUBTRACT "sub"
#define OPERATION_MULTIPLY "mul"
#define OPERATION_DIVIDE "div"
#define OPERATION_MODULO "mod"

int main() {
    char user_input[256];
    fgets(user_input, sizeof(user_input), stdin);

    strtok(user_input, "\n"); // get rid of '\n'
    char* number1_str = strtok(user_input, " "); // split user_input by " "
    char* operation = strtok(NULL, " "); // take the next tokens
    char* number2_str = strtok(NULL, " ");

    if(number1_str == NULL || operation == NULL || number2_str == NULL || strtok(NULL, " ") != NULL) {
        printf("Error!\n");
        return 1;
    }

    int number1 = number1_str[0] - '0', number2 = number2_str[0] - '0', result;

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

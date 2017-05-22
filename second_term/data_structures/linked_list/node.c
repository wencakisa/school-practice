#include <stdio.h>
#include <stdlib.h>

#include "node.h"

node_t* node_init(int value) {
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;

    return result;
}

int get_value(node_t *node) {
    return node->value;
}

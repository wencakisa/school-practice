#include <stdio.h>
#include <stdlib.h>

#include "node.h"

node_t* node_init(int value, node_t *next) {
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = next;

    return result;
}

node_t* head_init(int value) {
    return node_init(value, NULL);
}

int get_value(node_t *node) {
    return node->value;
}

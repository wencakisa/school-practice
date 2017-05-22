#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t list_init(int value) {
    list_t result = {
        .head = head_init(value),
        .size = 1
    };

    return result;
}

int get_size(list_t list) {
    return list.size;
}

int is_empty(list_t list) {
    return get_size(list) == 1;
}

node_t* get(list_t list, int index) {
    index = is_empty(list) ? 0 : index;
    node_t *result = list.head;

    for (size_t i = 0; i < index; i++) {
        result = result->next;
    }

    return result;
}

node_t* get_first(list_t list) {
    return get(list, 0);
}

node_t* get_last(list_t list) {
    return get(list, get_size(list));
}

void add(list_t *list, int value, int index) {
    node_t *current = list->head;

    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    current->next = head_init(value);
    list->size++;
}

void add_first(list_t *list, int value) {
    node_t *new_node = node_init(value, list->head);

    list->head = new_node;
    list->size++;
}

void add_last(list_t *list, int value) {
    add(list, value, get_size(*list) - 1);
}

int poll_first(list_t *list) {
    int result = -1;

    if (!is_empty(*list)) {
        node_t *next_node = list->head->next;

        result = list->head->value;
        free(list->head);
        list->head = next_node;
        list->size--;
    }

    return result;
}

void set(list_t *list, int index, int value) {
    if (!is_empty(*list)) {
        node_t *current = list->head;

        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }

        current->value = value;
    }
}

char* get_format_specifier(node_t *node) {
    return node->next == NULL ? "%d" : "%d, ";
}

void print_node(node_t *node) {
    printf(get_format_specifier(node), get_value(node));
}

void print_list(list_t list) {
    printf("[");
    for (size_t i = 0; i < get_size(list); i++) {
        print_node(get(list, i));
    }
    printf("]\n");
}

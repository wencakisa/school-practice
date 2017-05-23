#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t list_init(int value) {
    list_t result = {
        .head = NULL,
        .size = 0
    };

    return result;
}

void list_destroy(list_t *list) {
    node_t *current = list->head;

    while (!is_empty(*list)) {
        free(current);
        current = current->next;
        list->size--;
    }
}

int get_size(list_t list) {
    return list.size;
}

int is_empty(list_t list) {
    return get_size(list) == 0;
}

int is_valid_index(list_t list, int index) {
    return index >= 0 && index < get_size(list);
}

node_t* get(list_t list, int index) {
    node_t *result = list.head;

    if (is_valid_index(list, index)) {
        for (size_t i = 0; i < index; i++) {
            result = result->next;
        }
    }

    return result;
}

node_t* get_first(list_t list) {
    return get(list, 0);
}

node_t* get_last(list_t list) {
    return get(list, get_size(list) - 1);
}

void add_first(list_t *list, int value) {
    list->head = node_init(value, list->head);
    list->size++;
}

void add_last(list_t *list, int value) {
    node_t *last = get_last(*list);

    last->next = head_init(value);
    list->size++;
}

void set(list_t *list, int index, int value) {
    if (!is_empty(*list)) {
        get(*list, index)->value = value;
    }
}

int poll(list_t *list, node_t **to_poll, node_t **new_node) {
    int result = -1;

    if (!is_empty(*list)) {
        result = get_value(*to_poll);

        free(*to_poll);

        *to_poll = (new_node == NULL) ? NULL : *new_node;
        list->size--;
    }

    return result;
}

int poll_first(list_t *list) {
    return poll(list, &list->head, &list->head->next);
}

int poll_last(list_t *list) {
    node_t *node = get(*list, get_size(*list) - 2);

    return poll(list, &node->next, NULL);
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

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t list_init() {
    list_t result = { .head = NULL };

    return result;
}

void list_destroy(list_t *list) {
    node_t *current = list->head;
    node_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
}

list_t list_copy(list_t list) {
    list_t result = list_init();

    node_t *current = list.head;
    add_first(&result, get_value(current));

    while (current != NULL) {
        add_last(&result, get_value(current));
        current = current->next;
    }

    poll_first(&result);

    return result;
}

int get_size(list_t list) {
    int size = 0;
    node_t *current = list.head;

    while(current != NULL) {
        current = current->next;
        size++;
    }

    return size;
}

int is_empty(list_t list) {
    return list.head == NULL;
}

int is_valid_index(list_t list, int index) {
    return index >= 0 && index < get_size(list);
}

node_t* get_node(list_t list, int index) {
    node_t *result = list.head;

    if (!is_empty(list) && is_valid_index(list, index)) {
        for (size_t i = 0; i < index; i++) {
            result = result->next;
        }
    }

    return result;
}

node_t* get_first_node(list_t list) {
    return get_node(list, 0);
}

node_t* get_last_node(list_t list) {
    return get_node(list, get_size(list) - 1);
}

int get(list_t list, int index) {
    return get_value(get_node(list, index));
}

int get_first(list_t list) {
    return get_value(get_first_node(list));
}

int get_last(list_t list) {
    return get_value(get_last_node(list));
}

void add_first(list_t *list, int value) {
    list->head = node_init(value, list->head);
}

void add_last(list_t *list, int value) {
    node_t *last = get_last_node(*list);

    last->next = head_init(value);
}

void set(list_t *list, int index, int value) {
    if (!is_empty(*list)) {
        get_node(*list, index)->value = value;
    }
}

void set_first(list_t *list, int value) {
    set(list, 0, value);
}

void set_last(list_t *list, int value) {
    set(list, get_size(*list) - 1, value);
}

int poll_first(list_t *list) {
    int result = -1;

    if(!is_empty(*list)) {
        node_t *next_node = list->head->next;

        result = get_value(list->head);
        free(list->head);
        list->head = next_node;
    }

    return result;
}

int poll_last(list_t *list) {
    int result = -1;

    if(!is_empty(*list)) {
        node_t *last = get_last_node(*list);

        result = get_value(last);
        free(last);
        last->next = last;
    }

    return result;
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
        print_node(get_node(list, i));
    }
    printf("]\n");
}

#ifndef LIST_H_
#define LIST_H_

#include "node.h"

typedef struct list_t {
    node_t *head;
} list_t;

list_t list_init();
void list_destroy(list_t*);
list_t list_copy(list_t);

int get_size(list_t);
int is_empty(list_t);
int is_valid_index(list_t, int);

node_t* get_node(list_t, int);
node_t* get_first_node(list_t);
node_t* get_last_node(list_t);

int get(list_t, int);
int get_first(list_t);
int get_last(list_t);

void add_first(list_t*, int);
void add_last(list_t*, int);

void set(list_t*, int, int);
void set_first(list_t*, int);
void set_last(list_t*, int);

// int poll(list_t*, int);
int poll_first(list_t*);
int poll_last(list_t*);

char* get_format_specifier(node_t*);
void print_node(node_t*);
void print_list(list_t);

#endif

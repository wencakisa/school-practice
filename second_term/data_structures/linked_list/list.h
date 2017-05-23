#ifndef LIST_H_
#define LIST_H_

#include "node.h"

typedef struct list_t {
    node_t *head;
    int size;
} list_t;

list_t list_init();
void list_destroy(list_t*);

int get_size(list_t);
int is_empty(list_t);
int is_valid_index(list_t, int);

node_t* get(list_t, int);
node_t* get_first(list_t);
node_t* get_last(list_t);

void add_first(list_t*, int);
void add_last(list_t*, int);
void set(list_t*, int, int);

int poll(list_t*, node_t**, node_t**);
int poll_first(list_t*);
int poll_last(list_t*);

char* get_format_specifier(node_t*);
void print_node(node_t*);
void print_list(list_t);

#endif

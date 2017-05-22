#ifndef LIST_H_
#define LIST_H_

#include "node.h"

typedef struct list_t {
    node_t *head;
    int size;
} list_t;

list_t list_init(int);
int get_size(list_t);
node_t* get(list_t, int);
node_t* get_first(list_t);
node_t* get_last(list_t);
void add(list_t*, int, int);
void add_first(list_t*, int);
void add_last(list_t*, int);
// int poll(list_t*, int);
int poll_first(list_t*);
// int poll_last(list_t*);
void set(list_t*, int, int);
char* get_format_specifier(node_t*);
void print_node(node_t*);
void print_list(list_t);

#endif

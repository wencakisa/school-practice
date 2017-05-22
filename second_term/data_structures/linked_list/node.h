#ifndef NODE_H_
#define NODE_H_

typedef struct node_t {
    int value;
    struct node_t *next;
} node_t;

node_t* node_init(int, node_t*);
node_t* head_init(int);
int get_value(node_t*);

#endif

#ifndef VECTOR_H_

#define VECTOR_H_
#define SIZE 10

typedef struct vector_t {
    int size;
    int elements_count;
    int *elements;
} vector_t;

vector_t init();
int at(vector_t, int);
int first(vector_t);
int last(vector_t);
int count_equals(vector_t, int);
int empty(vector_t);
int full(vector_t);
int can_reduce_size(vector_t);
int at(vector_t, int);
void insert_at(vector_t*, int, int);
void add_first(vector_t*, int);
void add_last(vector_t*, int);
void remove_at(vector_t*, int);
int pop(vector_t*);
void destroy(vector_t*);
void print_array(int*, int);
void print_vector_info(vector_t);

#endif

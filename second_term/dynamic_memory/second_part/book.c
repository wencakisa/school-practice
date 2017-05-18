#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct phonebook_entry_t {
    char name[SIZE];
    char number[SIZE];
} phonebook_entry_t;

void print_phonebook(phonebook_entry_t*);

int main() {
    int size = 5;
    int count = 0;

    phonebook_entry_t *book = calloc(size, sizeof(phonebook_entry_t));

    char *result = "";
    while (result != NULL) {
        result = fgets((book + count)->name, SIZE, stdin);
        result = fgets((book + count)->number, SIZE, stdin);
        
        if (count == size) {
            size *= 2;
            book = (phonebook_entry_t*) realloc(book, size);
        }
        
        print_phonebook(book);
    }

    free(book);

    return 0;
}

void print_phonebook(phonebook_entry_t *book) {
    printf("%s - %s\n", book->name, book->number);
}

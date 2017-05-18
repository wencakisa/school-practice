#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

typedef struct person_t {
    char name[SIZE];
    int age;
    int postal_code;
} person_t;

typedef struct phonebook_entry_t {
    person_t *person;
    char number[SIZE];
} phonebook_entry_t;

void read_person(person_t*);
void read_book(phonebook_entry_t*);
void print_person(person_t*);
void print_book(phonebook_entry_t*);

int main() {
    phonebook_entry_t book;
    
    read_book(&book);
    print_book(&book);
    
    return 0;
}

void read_person(person_t *person) {
    printf("Name: ");
    fgets(person->name, SIZE, stdin);
    strtok(person->name, "\n");

    printf("Age: ");
    scanf("%d", &person->age);

    printf("Postal code: ");
    scanf("%d", &person->postal_code);
    
    getchar();
}

void read_book(phonebook_entry_t *book) {
    person_t *person = malloc(sizeof(person_t));

    read_person(person);
    book->person = person;

    printf("Number: ");
    fgets(book->number, SIZE, stdin);
}

void print_person(person_t *person) {
    printf("%s - (%dyo | Postal code: %d)\n", person->name, person->age, person->postal_code);
}

void print_book(phonebook_entry_t *book) {
    printf("Person: ");
    print_person(book->person);
    printf("Number: %s", book->number);
}

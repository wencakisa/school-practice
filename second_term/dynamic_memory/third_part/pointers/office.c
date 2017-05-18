#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct office_t {
    int rooms;
    float monthly_rent;
    int has_kitchen;
} office_t;

office_t *init_offices(int);
int is_appropriate(office_t);
office_t find_office(office_t*);
void print_office(office_t);

int main() {
    office_t *offices = init_offices(SIZE);

    print_office(find_office(offices));

    return 0;
}

office_t *init_offices(int size) {
    office_t *offices = calloc(size, sizeof(office_t));

    for (size_t i = 0; i < size; i++) {
        office_t current_office = {
            .rooms = i,
            .monthly_rent = i * 20,
            .has_kitchen = (i % 2)
        };

        offices[i] = current_office;
    }

    return offices;
}

int is_appropriate(office_t office) {
    return office.rooms > 3 &&
           office.monthly_rent < 500 &&
           office.has_kitchen;
}

office_t find_office(office_t *offices) {
    office_t result = { 0, 0.0f, 0 };

    for (size_t i = 0; i < SIZE; i++) {
        office_t current_office = offices[i];

        if(is_appropriate(current_office)) {
            result = current_office;
            break;
        }
    }

    return result;
}

void print_office(office_t office) {
    printf("Rooms: %d\n", office.rooms);
    printf("Monthly rent: %.2f\n", office.monthly_rent);
    printf((office.has_kitchen) ? "Has kitchen.\n" : "Has not kitchen.\n");
}

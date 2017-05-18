#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct house_t {
    int floors_count;
    float total_area;
    int has_furniture;
} house_t;

house_t* init_random_houses(int);
int can_buy_house(house_t);
house_t buy_house(house_t*);
void print_house(house_t);

int main() {
    house_t *houses = init_random_houses(SIZE);
    
    print_house(buy_house(houses));

    return 0;
}

house_t* init_random_houses(int size) {
    house_t *houses = calloc(size, sizeof(house_t));

    for (size_t i = 0; i < size; i++) {
        house_t current_house = {
            .floors_count = i,
            .total_area = i * 200,
            .has_furniture = (i % 2)
        };

        houses[i] = current_house;
    }

    return houses;
}

int can_buy_house(house_t house) {
    return house.floors_count > 2 &&
           house.total_area > 1000 &&
           house.has_furniture;
}

house_t buy_house(house_t *houses) {
    house_t result = { 0, 0.0f, 0 };
    
    for (size_t i = 0; i < SIZE; i++) {
        house_t current_house = houses[i];

        if (can_buy_house(current_house)) {
            result = current_house;
            break;
        }
    }

    return result;
}

void print_house(house_t house) {
    printf("Floors: %d\n", house.floors_count);
    printf("Total area: %.2fm^2\n", house.total_area);
    printf((house.has_furniture) ? "Has furniture.\n" : "Has not furniture.\n");
}

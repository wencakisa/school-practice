#include <stdio.h>

#define POSITIONS_LEN 6

const static char POSITIONS[POSITIONS_LEN] = {'C', 'c', 'B', 'S', 'P'};

typedef struct pirate_t {
    int gold_amount;
    int ships_amount;
    char position;
} pirate_t;

char get_position_index(char);
float split(pirate_t*, pirate_t*, int);

int main(int argc, char const *argv[]) {
    pirate_t pirate1;
    pirate1.gold_amount = 300;
    pirate1.ships_amount = 3;
    pirate1.position = 'C';

    pirate_t pirate2;
    pirate2.gold_amount = 100;
    pirate2.ships_amount = 1;
    pirate2.position = 'S';

    printf("%.2f\n", split(&pirate1, &pirate2, 1000));

    return 0;
}

char get_position_index(char position) {
    for (size_t i = 0; i < POSITIONS_LEN; i++) {
        if(POSITIONS[i] == position) {
            return i + 1;
        }
    }

    return -1;
}

float split(pirate_t *pirate1, pirate_t *pirate2, int gold) {
    int pirate1_position_index = get_position_index(pirate1->position);
    float pirate1_part = (
        pirate1->gold_amount * pirate1->ships_amount / pirate1_position_index
    ) / pirate1_position_index + 1;

    int pirate2_position_index = get_position_index(pirate2->position);
    float pirate2_part = (
        pirate2->gold_amount * pirate2->ships_amount / pirate2_position_index
    ) / pirate2_position_index + 1;

    // TODO: Finish.
    printf("%.2f\n", pirate1_part);
    printf("%.2f\n", pirate2_part);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

static const int ROWS = 32;
static const int SEATS_PER_ROW = 6;

void print_plane(char[ROWS][SEATS_PER_ROW]);
int get_latest_free_sit_index(char[ROWS][SEATS_PER_ROW]);
void accomodate_single(char[ROWS][SEATS_PER_ROW]);
void accomodate_couple(char[ROWS][SEATS_PER_ROW]);
void accomodate_threesome(char[ROWS][SEATS_PER_ROW]);

int main() {
    char plane[ROWS][SEATS_PER_ROW];

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < SEATS_PER_ROW; j++) {
            plane[i][j] = (i % 2 && i != 13) ? 'x' : ' ';
        }
    }

    print_plane(plane);
    printf("%d\n", get_latest_free_sit_index(plane));

    return 0;
}

void print_plane(char plane[ROWS][SEATS_PER_ROW]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < SEATS_PER_ROW; j++) {
            printf("%c", plane[i][j]);
        }
        printf("\n");
    }
}

int get_latest_free_sit_index(char plane[ROWS][SEATS_PER_ROW]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < SEATS_PER_ROW; j++) {
            if(plane[i][j] == 'x') {
                return j
            }
        }
    }
}

void accomodate_single(char plane[ROWS][SEATS_PER_ROW]) {

}

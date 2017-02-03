#include <stdio.h>

typedef struct point_t {
    int x;
    int y;
} point_t;

void swap_values(int*, int*);
void swap_points(point_t*, point_t*);

int main() {
    point_t p1, p2;

    p1.x = 5;
    p1.y = 12;

    p2.x = -6;
    p2.y = 7;

    printf("Point 1 coords: (%d; %d)\n", p1.x, p1.y);
    printf("Point 2 coords: (%d; %d)\n", p2.x, p2.y);

    printf("... Swapping coords ...\n");
    swap_points(&p1, &p2);

    printf("Point 1 coords: (%d; %d)\n", p1.x, p1.y);
    printf("Point 2 coords: (%d; %d)\n", p2.x, p2.y);

    return 0;
}

void swap_values(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void swap_points(point_t *p1, point_t *p2) {
    swap_values(&p1->x, &p2->x);
    swap_values(&p1->y, &p2->y);
}

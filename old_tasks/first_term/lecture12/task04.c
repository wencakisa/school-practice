#include <stdio.h>

typedef struct point_t {
    int x;
    int y;
} point_t;

int are_neighbouring(point_t, point_t);

int main() {
    point_t p1;
    p1.x = 5;
    p1.y = 3;

    point_t p2;
    p2.x = -2;
    p2.y = 3;
    
    printf("Points %s neighbouring.\n", are_neighbouring(p1, p2) ? "are" : "are not");

    return 0;
}

int are_neighbouring(point_t p1, point_t p2) {
    return ((p1.x == p2.x) || (p1.y == p2.y));
}

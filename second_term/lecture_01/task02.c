#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} point_t;

float distance(point_t, point_t);
point_t move(point_t, float, float);

int main() {
    point_t p1, p2;

    p1.x = 4;
    p1.y = 4;

    p2.x = 2;
    p2.y = -5;

    printf("%.2f\n", distance(p1, p2));

    p1 = move(p2, -5, 12);

    printf("%.2f\n", distance(p1, p2));

    return 0;
}

float distance(point_t p1, point_t p2) {
    return sqrt(pow(p1.x - p1.y, 2) + pow(p2.x - p2.y, 2));
}

point_t move(point_t p, float offset_x, float offset_y) {
    point_t result;

    result.x = p.x + offset_x;
    result.y = p.y + offset_y;

    return result;
}

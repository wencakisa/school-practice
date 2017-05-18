#include <stdio.h>
#include <math.h>

typedef struct point_t {
    float x;
    float y;
} point_t;

typedef struct line_t {
    point_t start;
    point_t end;
} line_t;

typedef struct rect_t {
    line_t small_side;
    line_t big_side;
} rect_t;

float get_len(line_t);
float get_area(rect_t);
float get_perimeter(rect_t);

int main() {
    point_t p1 = {0, 0};
    point_t p2 = {0, 5};
    point_t p3 = {10, 5};

    line_t l1 = {p1, p2};
    line_t l2 = {p2, p3};
    
    rect_t rect = {l1, l2};

    printf("Area: %.2f units\n", get_area(rect));
    printf("Perimeter: %.2f units\n", get_perimeter(rect));

    return 0;
}

float get_len(line_t line) {
    return sqrt(
        pow(line.end.x - line.start.x, 2) + pow(line.end.y - line.start.y, 2)
    );
}

float get_area(rect_t rect) {
    return get_len(rect.small_side) * get_len(rect.big_side);
}

float get_perimeter(rect_t rect) {
    return (get_len(rect.small_side) + get_len(rect.big_side)) * 2;
}

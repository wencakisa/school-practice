#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point start;
    point end;
} line;

typedef struct {
    line left;
    line bottom;
    line right;
    line top;
} rectangle;

int are_collinear(point, point, point);
float get_length(line);
int are_parallel(line, line);
int are_perpendicular(line, line);
int get_area(rectangle);
int get_perimeter(rectangle);

int main() {
    point p1, p2, p3;

    p1.x = 3;
    p1.y = 12;

    p2.x = 3;
    p2.y = 4;

    p3.x = 3;
    p3.y = -2;

    printf("%d\n", are_collinear(p1, p2, p3));

    point p4;

    p1.x = 0;
    p1.y = 15;

    p2.x = 0;
    p2.y = 30;

    p3.x = 30;
    p3.y = 0;

    p4.x = 60;
    p4.y = 0;

    line l1, l2;

    l1.start = p1;
    l1.end = p3;

    l2.start = p2;
    l2.end = p4;

    printf("%d\n", are_parallel(l1, l2));

    p1.x = 5;
    p1.y = 5;

    p2.x = 25;
    p2.y = 40;

    p3.x = 65;
    p3.y = 35;

    p4.x = 45;
    p4.y = 0;

    l1.start = p1;
    l1.end = p3;

    l2.start = p2;
    l2.end = p4;

    printf("%d\n", are_perpendicular(l1, l2));

    p1.x = 0;
    p1.y = 0;

    p2.x = 10;
    p2.y = 0;

    p3.x = 10;
    p3.y = 5;

    p4.x = 0;
    p4.y = 5;

    l1.start = p1;
    l1.end = p2;

    l2.start = p2;
    l2.end = p3;

    line l3, l4;

    l3.start = p3;
    l3.end = p4;

    l4.start = p4;
    l4.end = p1;

    rectangle r;

    r.left = l4;
    r.bottom = l1;
    r.right = l2;
    r.top = l3;

    printf("%d\n", get_area(r));
    printf("%d\n", get_perimeter(r));

    return 0;
}

int are_collinear(point p1, point p2, point p3) {
    return (p1.x == p2.x && p2.x == p3.x && p3.x == p1.x) ||
            (p1.y == p2.y && p2.y == p3.y && p3.y == p1.y);
}

float get_length(line l) {
    return sqrt(pow(l.start.x - l.start.y, 2) + pow(l.end.x - l.end.y, 2));
}

int are_parallel(line l1, line l2) {
    float l1_slope = (l1.start.y - l1.end.y) / (l1.start.x - l1.end.x);
    float l2_slope = (l2.start.y - l2.end.y) / (l2.start.x - l2.end.x);

    return l1_slope == l2_slope;
}

int are_perpendicular(line l1, line l2) {
    float l1_slope = (l1.start.y - l1.end.y) / (l1.start.x - l1.end.x);
    float l2_slope = (l2.start.y - l2.end.y) / (l2.start.x - l2.end.x);

    return (-1 / l1_slope) == l2_slope;
}

int get_area(rectangle r) {
    return get_length(r.left) * get_length(r.bottom);
}

int get_perimeter(rectangle r) {
    return (get_length(r.left) * 2) + (get_length(r.bottom) * 2);
}

#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

void print_point(Point);
Point add_points(Point, Point);
int are_contiguous(Point, Point);

int main() {
    Point p1, p2, p3;

    p1.x = 5;
    p1.y = 12;

    p2.x = 7;
    p2.y = 12;

    p3 = add_points(p1, p2);

    print_point(p1);
    printf(" and ");
    print_point(p2);
    printf(are_contiguous(p1, p2) ?
        " are contiguous.\n" :
        " are not contiguous.\n"
    );

    print_point(p1);
    printf(" + ");
    print_point(p2);
    printf(" = ");
    print_point(p3);

    printf("\n");

    return 0;
}

void print_point(Point p) {
    printf("Point(%d; %d)", p.x, p.y);
}

Point add_points(Point p1, Point p2) {
    Point p;

    p.x = p1.x + p2.x;
    p.y = p1.y + p2.y;

    return p;
}

int are_contiguous(Point p1, Point p2) {
    if(p1.x == p2.x || p1.y == p2.y) {
        return 1;
    }

    return 0;
}

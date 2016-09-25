#include <stdio.h>

struct Point {
    int x;
    int y;
    void (*increment_coords)(struct Point*);
    void (*print_coords)(struct Point*);
};

void increment_coords(struct Point* p) {
    p->x += 1;
    p->y += 1;
}

void print_coords(struct Point* p) {
    printf("(%d; %d)\n", p->x, p->y);
}

int main() {
    struct Point p = {0, 0, increment_coords, print_coords};

    p.increment_coords(&p);
    p.print_coords(&p);

    return 0;
}

#include <stdio.h>

#define LEN 10

typedef struct planet_t {
    float x;
    float y;
    float radius;
} planet_t;

typedef struct universe_t {
    planet_t planets[LEN];
} universe_t;

void spawn_planet(planet_t, universe_t*);

int main() {
    planet_t p1 = { 3.4, 5.2, 5.12 };
    planet_t p2 = { 0, 0, 0 };

    universe_t u = {
        .planets = { p1, p2 }
    };

    planet_t p3 = { 1, 2, 3 };

    spawn_planet(p3, &u);

    return 0;
}

void spawn_planet(planet_t planet, universe_t *universe) {
    universe->planets[0] = planet;
}

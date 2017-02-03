#include <stdio.h>

typedef struct {
    int x;
    int y;
    float radius;
} planet_t;

typedef struct {
    planet_t planets[1024];
    int planets_count;
} universe_t;

void spawn_planet(planet_t, universe_t*);
void print_universe(universe_t universe);

int main() {
    universe_t universe;
    universe.planets_count = 0;

    print_universe(universe);

    planet_t planet;

    planet.x = 2;
    planet.y = 2;

    spawn_planet(planet, &universe);

    print_universe(universe);

    planet.x = 5;
    planet.y = 12;

    spawn_planet(planet, &universe);

    print_universe(universe);

    return 0;
}

void spawn_planet(planet_t planet, universe_t* universe) {
    if(universe->planets_count == 0) {
        universe->planets[universe->planets_count] = planet;
        universe->planets_count++;
    }
    else {
        for(int i = 0; i < universe->planets_count; i++) {
            planet_t current_planet = universe->planets[i];

            if(planet.x != current_planet.x && planet.y != current_planet.y) {
                universe->planets[universe->planets_count] = planet;
                universe->planets_count++;
            }
        }
    }
}

void print_universe(universe_t universe) {
    if(universe.planets_count == 0) {
        printf("No planets yet.\n");
    }
    else {
        printf("Planets: ");

        for(int i = 0; i < universe.planets_count; i++) {
            planet_t planet = universe.planets[i];

            i < universe.planets_count - 1 ?
                printf("(%d; %d), ", planet.x, planet.y) :
                printf("(%d; %d)\n", planet.x, planet.y);
        }
    }
}

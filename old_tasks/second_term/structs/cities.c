#include <stdio.h>
#include <stdlib.h>

#define TOP_CITIES 5
#define MAX_COUNTRIES 5

typedef struct city_t {
    char *name;
    int residents;
} city_t;

typedef struct country_t country_t;
typedef struct country_t {
    char *name;
    char *continent_name;

    city_t biggest_cities[TOP_CITIES];
    int added_cities;
    
    int neighbouring_countries_count;
    country_t *neighbouring_countries;
} country_t;

void add_city(country_t*, city_t);
void add_country(country_t*, country_t);
int count_population(country_t);
int count_neighbours_population(country_t);
int count_total_population(country_t);
char *biggest_avg_population_country(country_t);
void print_country_info(country_t);

int main() {
    city_t kostinbrod;
    kostinbrod.name = "Kostinbrod";
    kostinbrod.residents = 50000;

    country_t bulgaria;
    bulgaria.name = "Bulgaria";
    bulgaria.continent_name = "Europe";
    bulgaria.added_cities = 0;
    bulgaria.neighbouring_countries_count = 0;
    bulgaria.neighbouring_countries = (country_t*)malloc(sizeof(country_t) * MAX_COUNTRIES);
    
    add_city(&bulgaria, kostinbrod);
    print_country_info(bulgaria);
    
    city_t sofia;
    sofia.name = "Sofia";
    sofia.residents = 1000000;

    add_city(&bulgaria, sofia);
    print_country_info(bulgaria);
    
    country_t serbia;
    serbia.name = "Serbia";
    serbia.continent_name = "Europe";
    serbia.added_cities = 0;
    serbia.neighbouring_countries_count = 0;

    city_t belgrad;
    belgrad.name = "Belgrad";
    belgrad.residents = 1300000;

    add_city(&serbia, belgrad);
    add_country(&bulgaria, serbia);
    print_country_info(bulgaria);
    
    printf("Country with biggest average population: %s\n", biggest_avg_population_country(bulgaria));

    return 0;
}

void add_city(country_t *country, city_t city) {
    country->biggest_cities[country->added_cities++] = city;
}

void add_country(country_t *country, country_t neighbour) {
    country->neighbouring_countries[country->neighbouring_countries_count++] = neighbour;
}

int count_population(country_t country) {
    int population = 0;
    
    for(size_t i = 0; i < country.added_cities; i++) {
        population += country.biggest_cities[i].residents;
    }

    return population;
}

int count_neighbours_population(country_t country) {
    int population = 0;
    
    for(size_t i = 0; i < country.neighbouring_countries_count; i++) {
        population += count_population(country.neighbouring_countries[i]);
    }

    return population;
}

int count_total_population(country_t country) {
    return count_population(country) + count_neighbours_population(country);
}

char *biggest_avg_population_country(country_t country) {
    country_t biggest_country = country;
    int biggest_population = count_population(country);

    for(size_t i = 0; i < country.neighbouring_countries_count; i++) {
        country_t current_country = country.neighbouring_countries[i];
        int current_population = count_population(current_country);

        if(current_population > biggest_population) {
            biggest_country = current_country;
        }
    }
    
    return biggest_country.name;
}

void print_country_info(country_t country) {
    printf("***********************************************\n");
    printf("Country name: %s\n", country.name);
    printf("Continent name: %s\n", country.continent_name);
    printf("Population: %d\n", count_population(country));
    printf("Neighbouring countries: %d\n", country.neighbouring_countries_count);
    printf("Neighbouring countries population: %d\n", count_neighbours_population(country));
    printf("Total population: %d\n", count_total_population(country));
    printf("***********************************************\n");
}

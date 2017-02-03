#include <stdio.h>

typedef struct liver_t {
    int vodka_amount;
    int water_amount;
} liver_t;

void drink_vodka(liver_t*, int);
void drink_water(liver_t*, int);
float sleep_somewhere(liver_t);
int sleep_more(float);

int main() {
    liver_t liver;
    liver.vodka_amount = 0;
    liver.water_amount = 0;

    int vodka_amount, water_amount;
    printf("Колко милилитра водКа изпихте (ама честно): ");
    scanf("%d", &vodka_amount);
    printf("Ами колко милилитра вода изпихте: ");
    scanf("%d", &water_amount);

    printf("\n... Я да видим колко сте пиян ...\n\n");
    drink_vodka(&liver, vodka_amount);
    drink_water(&liver, water_amount);

    float drunk_level = sleep_somewhere(liver);
    printf(
        "Имате %.1f промила алкохол в кръвта.\n",
        drunk_level
    );
    printf(
        "Поспете поне още %dч. за да изтрезнеете напълно.\n",
        sleep_more(drunk_level)
    );

    return 0;
}

void drink_vodka(liver_t *liver, int vodka_amount) {
    liver->vodka_amount += vodka_amount;
}

void drink_water(liver_t *liver, int water_amount) {
    liver->water_amount += water_amount;
}

float sleep_somewhere(liver_t liver) {
    int vodka_amount = liver.vodka_amount;
    int water_amount = liver.water_amount;

    return (vodka_amount * 100 - water_amount * 40 - 2000 * 8) / 1000;
}

int sleep_more(float drunk_level) {
    int hours = 0;

    while (drunk_level > 0) {
        drunk_level -= 0.4;
        hours++;
    }

    return hours;
}

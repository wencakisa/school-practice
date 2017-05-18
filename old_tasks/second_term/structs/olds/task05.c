#include <stdio.h>

#define LEN 3

typedef struct battery_t {
    float voltage;
} battery_t;

typedef struct battery_pack_t {
    battery_t batteries[LEN];
} battery_pack_t;

float total_voltage(battery_pack_t);

int main() {
    battery_t b1 = { 12.4 };
    battery_t b2 = { 32.1 };
    battery_t b3 = { 3.5 };

    battery_pack_t pack = {
        .batteries = { b1, b2, b3 }
    };

    printf("%.2f\n", total_voltage(pack));

    return 0;
}

float total_voltage(battery_pack_t pack) {
    float result = 0;

    for(size_t i = 0; i < LEN; i++) {
        result += pack.batteries[i].voltage;
    }

    return result / LEN;
}

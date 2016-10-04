#include <stdio.h>

typedef struct {
    float voltage;
} battery_t;

typedef struct {
    battery_t pack[3];
} battery_pack_t;

float total_voltage(battery_pack_t);

int main() {
    battery_t b1, b2, b3;

    b1.voltage = 35.2;
    b2.voltage = 12.37;
    b3.voltage = 10.96;

    battery_pack_t batteries;

    batteries.pack[0] = b1;
    batteries.pack[1] = b2;
    batteries.pack[2] = b3;

    printf("%.2fV\n", total_voltage(batteries));

    return 0;
}

float total_voltage(battery_pack_t batteries) {
    return batteries.pack[0].voltage +
            batteries.pack[1].voltage +
            batteries.pack[2].voltage;
}

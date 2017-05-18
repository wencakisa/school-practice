#include <stdio.h>

#define SIZE 10

typedef struct time_t {
    int hours;
    int minutes;
    float seconds;
} time_t;

float floatmod(float, float);
time_t convert_to_time(float);
float get_min(float*);
time_t get_fastest_time(float*);
void print_time(time_t);

int main() {
    float times[SIZE] = { 100.24, 243.54, 3971.66, 5000, 5000, 5000, 5000, 5000, 5000, 5000 };

    print_time(get_fastest_time(times));

    return 0;
}

float floatmod(float a, float b) {
    return (a - b * (int)(a / b));
}

time_t convert_to_time(float seconds) {
    int minutes = seconds / 60;
    int hours = minutes / 60;

    time_t result = {
        .hours = (int)hours,
        .minutes = (int)minutes % 60,
        .seconds = floatmod(seconds, 60)
    };

    return result;
}

float get_min(float *arr) {
    float result = arr[0];

    for (size_t i = 1; i < SIZE; i++) {
        float current_element = arr[i];

        if (current_element < result) {
            result = current_element;
        }
    }

    return result;
}

time_t get_fastest_time(float *times) {
    return convert_to_time(get_min(times));
}

void print_time(time_t time) {
    printf("%dh %dmin %.2fsec\n", time.hours, time.minutes, time.seconds);
}

#include <stdio.h>
#include <math.h>

#define DEFAULT_SIZE 5

float calc_dist(float, float);
float shortest_distance(float*, float*);

int main() {
    float x[DEFAULT_SIZE], y[DEFAULT_SIZE];

    for (size_t i = 0; i < DEFAULT_SIZE; i++) {
        x[i] = i;
        y[i] = i + 1;
    }

    printf("%.2f\n", shortest_distance(x, y));

    return 0;
}

float calc_dist(float a, float b) {
    return sqrt(pow(a, 2) + pow(b, 2));
}

float shortest_distance(float *x, float *y) {
    float result = calc_dist(x[0], y[0]);

    for (size_t i = 1; i < DEFAULT_SIZE; i++) {
        float current_dist = calc_dist(x[i], y[i]);

        if(current_dist < result) {
            result = current_dist;
        }
    }

    return result;
}

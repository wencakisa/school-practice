#include <stdio.h>

typedef struct result_t {
    int sum;
    float avg;
} result_t;

void set_sum(result_t*, int);
void set_avg(result_t*, int);

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    result_t result;
    set_sum(&result, n);
    set_avg(&result, n);

    printf("Sum from 1 to %d: %d\n", n, result.sum);
    printf("Average: %.2f\n", result.avg);

    return 0;
}

void set_sum(result_t *result, int n) {
    result->sum = 0;

    for (size_t i = 1; i < n; i++) {
        result->sum += i;
    }
}

void set_avg(result_t *result, int n) {
    result->avg = (float)result->sum / n;
}

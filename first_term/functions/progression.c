#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 30

int has_progression(int*, int);

int main() {
    int arr[MAX_SIZE];

    int current, i = 0;
    while(scanf("%d", &current) != EOF) {
        arr[i] = current;
        i++;
    }

    printf("%d\n", has_progression(arr, i));

    return 0;
}

int has_progression(int* arr, int len) {
    int current_diff, last_diff = 0;

    for (size_t i = 0; i < len - 1; i++) {
        current_diff = abs(arr[i] - arr[i + 1]);

        if(last_diff && current_diff != last_diff) {
            return 0;
        }

        last_diff = current_diff;
    }

    return last_diff;
}

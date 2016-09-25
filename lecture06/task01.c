#include <stdio.h>
#include <string.h>

#define SIZE 100

void swap(int*, int*);
void sort(int*, int);
void print_histogram(int*, int);

int main() {
    char user_input[SIZE];
    fgets(user_input, SIZE, stdin);

    int numbers[SIZE], number_to_add, i = 0;

    char* token = strtok(user_input, " ");
    while(token != NULL) {
        sscanf(token, "%d", &number_to_add);
        numbers[i++] = number_to_add;

        token = strtok(NULL, " ");
    }

    sort(numbers, i);
    print_histogram(numbers, i);

    return 0;
}

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int* array, int len) {
    int i, j;

    for(i = 1; i < len; i++) {
        j = i;
        while(j > 0 && array[j - 1] > array[j]) {
            swap(&array[j - 1], &array[j]);
            j--;
        }
    }
}

void print_histogram(int* array, int len) {
    int prev;

    for(int i = 0; i < len; i++) {
        int current = array[i], current_count = 1;

        // To avoid iterating over duplicates.
        if(current == prev) {
            continue;
        }

        for(int j = i + 1; j < len; j++) {
            if(current == array[j]) {
                current_count++;
            }
        }

        printf("%d: ", current);
        for(int j = 0; j < current_count; j++) {
            printf("*");
        }
        printf("\n");

        prev = current;
    }
}

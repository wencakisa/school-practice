#include <stdio.h>
#include <stdlib.h>

#define MAGIC_NUM 11

typedef struct dynamic_arr_t {
	int *array;
	int size;
} dynamic_arr_t;

dynamic_arr_t generate(int);
dynamic_arr_t filter_even(dynamic_arr_t);
dynamic_arr_t map_sqr(dynamic_arr_t);
dynamic_arr_t sqr_of_odds(dynamic_arr_t);
int reduce_sum(dynamic_arr_t);
void free_dynamic_arr(dynamic_arr_t*);
void print_arr(dynamic_arr_t);

int main() {
	dynamic_arr_t arr = generate(MAGIC_NUM);
	
	print_arr(arr);
	printf("Sum: %d\n", reduce_sum(arr));	

	printf("\nOdds\n");
	print_arr(filter_even(arr));

	printf("\nSquares\n");
	print_arr(map_sqr(arr));
	
	printf("\nOdd squares\n");
	arr = sqr_of_odds(arr);
    print_arr(arr);
    printf("Sum: %d\n", reduce_sum(arr));

	printf("\nFreeing...\n");
	free_dynamic_arr(&arr);
	print_arr(arr);
    
    printf("\nPowers of 2\n");
    for (size_t i = 1; i <= MAGIC_NUM; i += 2) {
        dynamic_arr_t array = generate(i);
    
        printf("%d\n", reduce_sum(filter_even(array)));
    }

	return 0;
}

dynamic_arr_t generate(int num) {
	dynamic_arr_t result = {
        .size = num,
        .array = calloc(num, sizeof(int))
    };
	
	for (size_t i = 0; i < result.size; i++) {
		result.array[i] = i + 1;
	}

	return result;
}

dynamic_arr_t filter_even(dynamic_arr_t arr) {
	int size = arr.size, j = 0;
	int *odds = calloc(size, sizeof(int));	

	for (size_t i = 0; i < size; i++) {
		int current_element = arr.array[i];

		if (current_element % 2 == 1) {
			odds[j++] = current_element;
		}
	}

	dynamic_arr_t result = {
		.size = j,
		.array = odds
	};

	return result;
}

dynamic_arr_t map_sqr(dynamic_arr_t arr) {
	int size = arr.size;
	int *mapped = calloc(size, sizeof(int));
	
	for (size_t i = 0; i < size; i++) {
		int current_element = arr.array[i];

		mapped[i] = current_element * current_element;
	}

	dynamic_arr_t result = {
		.size = size,
		.array = mapped
	};

	return result;
}

dynamic_arr_t sqr_of_odds(dynamic_arr_t arr) {
	return map_sqr(filter_even(arr));
}

int reduce_sum(dynamic_arr_t arr) {
	int result = 0;

	for (size_t i = 0; i < arr.size; i++) {
		result += arr.array[i];
	}

	return result;
}

void free_dynamic_arr(dynamic_arr_t *arr) {
	free(arr->array);
	arr->array = NULL;
	arr->size = 0;
}

void print_arr(dynamic_arr_t arr) {
	int size = arr.size;
	printf("Size: %d\n", size);
	
	printf("[");
	for (size_t i = 0; i < size; i++) {
		printf((i < size - 1) ? "%d, " : "%d", arr.array[i]);
	}
	printf("]\n");
}


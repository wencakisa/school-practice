#include <stdio.h>

void swap(int*, int*);
void sort(int*, int);
int get_rudoplhs_number(int*, int);

int main() {
    int deers_count;
    do {
        scanf("%d", &deers_count);

        if(deers_count % 2 == 0) {
            printf("Deers count must be an odd number.\n");
        }
        if(deers_count > 200) {
            printf("Deers count must be less than 200.\n");
        }
    } while(deers_count % 2 == 0 || deers_count > 200);

    int deers[deers_count];
    for(int i = 0; i < deers_count; i++) {
        do {
            scanf("%d", &deers[i]);

            if(deers[i] < 1 || deers[i] > 100) {
                printf("Deers' number must be in the range (1; 100).\n");
            }
        } while(deers[i] < 1 || deers[i] > 100);
    }

    printf("%d\n", get_rudoplhs_number(deers, deers_count));

    return 0;
}

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int* a, int len) {
    int j;
    for(int i = 1; i < len; i++) {
        j = i;
        while(j > 0 && a[j - 1] > a[j]) {
            swap(&a[j - 1], &a[j]);
            j--;
        }
    }
}

int get_rudoplhs_number(int* deers, int deers_count) {
    sort(deers, deers_count);

    for(int i = 0; i < deers_count; i += 2) {
        int has_mate = 0;

        for(int j = i + 1; j < deers_count && !has_mate; j++) {
            if(deers[i] == deers[j]) {
                has_mate = 1;
            }
        }

        if(!has_mate) {
            return deers[i];
        }
    }
}

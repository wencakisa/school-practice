#include <stdio.h>

#define MAX_LEGS_LEN 6

typedef struct leg_t {
    int is_fried;
    int is_hot;
} leg_t;

typedef struct bucket_t {
    leg_t legs[MAX_LEGS_LEN];
} bucket_t;

bucket_t make_it_burn(leg_t*);
int hot(bucket_t);

int main() {
    leg_t legs[MAX_LEGS_LEN];

    for (size_t i = 0; i < MAX_LEGS_LEN; i++) {
        leg_t leg;
        leg.is_fried = 0;
        leg.is_hot = (i % 2) ? 0 : 1;

        legs[i] = leg;
    }

    bucket_t bucket = make_it_burn(legs);

    printf("Hot legs in the bucket: %d\n", hot(bucket));

    return 0;
}

bucket_t make_it_burn(leg_t *legs) {
    bucket_t bucket;

    for (size_t i = 0; i < MAX_LEGS_LEN; i++) {
        legs[i].is_fried = 1;
        bucket.legs[i] = legs[i];
    }

    return bucket;
}

int hot(bucket_t bucket) {
    int count = 0;
    leg_t* legs = bucket.legs;

    for (size_t i = 0; i < MAX_LEGS_LEN; i++) {
        if(legs[i].is_hot) {
            count++;
        }
    }

    return count;
}

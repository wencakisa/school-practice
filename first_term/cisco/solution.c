#include <stdio.h>
#include <stdlib.h>

#define MAGIC_NUM 42

int get_days_to_buy(int, float, int, float);
char* get_place_to_buy(int);

int main() {
    int price, p;
    float money_saved_a_day, money_spent;

    printf("Price: ");
    scanf("%d", &price);

    printf("Money saved each day: ");
    scanf("%f", &money_saved_a_day);

    printf("P: ");
    scanf("%d", &p);

    printf("Money spent each P days: ");
    scanf("%f", &money_spent);

    int days_to_buy = get_days_to_buy(price, money_saved_a_day, p, money_spent);

    if(days_to_buy == -1) {
        printf("Not enough money.\n");
    } else {
        printf("%d%s\n", days_to_buy, get_place_to_buy(days_to_buy));
    }

    return 0;
}

int get_days_to_buy(int k, float n, int p, float m) {
    int days = 0;
    float total_money_saved = 0.0f;

    while(k > total_money_saved && days != -1) {
        days++;
        total_money_saved += n;

        if(!(days % p)) {
            total_money_saved -= m;

            if(total_money_saved <= 0)
                days = -1;
        }
    }

    return days;
}

char* get_place_to_buy(int days) {
    int days_difference = abs(MAGIC_NUM - days);
    
    if(!(days_difference)) {
        return " BED";
    } else if(days_difference <= 10) {
        return " DB";
    }

    return "";
}

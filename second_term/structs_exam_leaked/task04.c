#include <stdio.h>

#define DEFAULT_SIZE 8
#define DEFAULT_NAME_LEN 25

typedef struct curling_match_t {
    char first_team_name[DEFAULT_NAME_LEN];
    int first_team_stats[DEFAULT_SIZE];

    char second_team_name[DEFAULT_NAME_LEN];
    int second_team_stats[DEFAULT_SIZE];
} curling_match_t;

int get_min(float*);
int get_game_winner(curling_game_t);

int main() {
    /* code */
    return 0;
}

int get_min(float *arr) {
    float result = arr[0];

    for (size_t i = 1; i < DEFAULT_SIZE; i++) {
        float current_dist = arr[i];

        if(current_dist < result) {
            result = current_dist;
        }
    }

    return result;
}

int get_game_winner(curling_game_t game) {
    int first_team_points = 0;
    int second_team_points = 0;

    for (size_t i = 0; i < DEFAULT_SIZE; i++) {
        (game.first_team_dist[i] > game.second_team_dist[i]) ?
            first_team_points++ : second_team_points++;
    }

    if(first_team_points > second_team_points) {
        return -1;
    } else if(second_team_points > first_team_points) {
        return 1;
    }

    return 0;
}

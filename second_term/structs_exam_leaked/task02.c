#include <stdio.h>

#define DEFAULT_SIZE 5

typedef struct curling_game_t {
    float first_team_dist[DEFAULT_SIZE];
    float second_team_dist[DEFAULT_SIZE];
} curling_game_t;

int get_game_winner(curling_game_t);

int main() {
    curling_game_t game;

    for (size_t i = 0; i < DEFAULT_SIZE; i++) {
        game.first_team_dist[i] = i;
        game.second_team_dist[i] = i;
    }

    printf("%d\n", get_game_winner(game));

    return 0;
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

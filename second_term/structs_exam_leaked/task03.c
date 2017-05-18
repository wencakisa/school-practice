#include <stdio.h>

#define DEFAULT_DISTANCES 5
#define DEFAULT_SIZE 8
#define DEFAULT_NAME_LEN 25

typedef struct curling_game_t {
    float first_team_dist[DEFAULT_DISTANCES];
    float second_team_dist[DEFAULT_DISTANCES];
} curling_game_t;

typedef struct curling_match_t {
    char first_team_name[DEFAULT_NAME_LEN];
    char second_team_name[DEFAULT_NAME_LEN];
    curling_game_t games[DEFAULT_SIZE];
} curling_match_t;

void print_game_stats(curling_match_t);

int main() {
    curling_game_t game1, game2;
    for (size_t i = 0; i < DEFAULT_DISTANCES; i++) {
        game1.first_team_dist[i] = i;
        game1.first_team_dist[i] = i + 1;

        game2.first_team_dist[i] = i + 2;
        game2.second_team_dist[i] = i;
    }

    curling_match_t match = {
        .first_team_name = "SiskoFC",
        .second_team_name = "Barbiturati",
        .games = { game1, game2 }
    };

    print_game_stats(match);

    return 0;
}

void print_game_stats(curling_match_t match) {
    int first_team_total_stats = 0;
    int second_team_total_stats = 0;

    for (size_t i = 0; i < DEFAULT_SIZE; i++) {
        int first_team_current_stats = match.games[i].first_team_points;
        int second_team_current_stats = match.games[i].second_team_points;

        printf(
            "%s %d : %s %d\n",
            match.first_team_name, first_team_current_stats,
            match.second_team_name, second_team_current_stats
        );

        first_team_total_stats += first_team_current_stats;
        second_team_total_stats += second_team_current_stats;
    }

    printf("%d %d\n", first_team_total_stats, second_team_total_stats);
}

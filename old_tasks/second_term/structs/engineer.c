#include <stdio.h>

typedef struct software_engineer_t {
    int solutions_count;
    int lines_of_code;
    int time_awake;
} software_engineer_t;

int main() {
    software_engineer_t se;
    se.lines_of_code = 0;

    int solutions_count, lines_of_code, time_awake;

    printf("Solutions count: ");
    scanf("%d", &solutions_count);
    se.solutions_count = solutions_count;

    for (size_t i = 0; i < solutions_count; i++) {
        printf("Solution #%ld lines of code: ", i);
        scanf("%d", &lines_of_code);
        se.lines_of_code += lines_of_code;
    }

    printf("Time awake: ");
    scanf("%d", &time_awake);
    se.time_awake = time_awake;

    float avg_solution_time = se.time_awake / se.solutions_count;
    float avg_time_in_mins = avg_solution_time * 60;
    float lines_of_code_per_min = avg_time_in_mins / se.lines_of_code;

    printf(
        "You've spent an average time of %.1f hours for each solution.\n",
        avg_solution_time
    );
    printf(
        "You've written an average of %.1f loc/min.\n",
        lines_of_code_per_min
    );
    printf(
        "You've written a total of %d lines of code.\n",
        se.lines_of_code
    );

    return 0;
}

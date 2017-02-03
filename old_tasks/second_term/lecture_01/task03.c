#include <stdio.h>
#include <string.h>

typedef struct {
    char name[30];
    char id[11];
    int grade;
    char grade_letter;
    float average_mark;
} student_t;

void print_student_row(student_t);

int main() {
    student_t s;

    strcpy(s.name, "Sisko Tashevich");
    strcpy(s.id, "0043120351");
    s.grade = 10;
    s.grade_letter = 'A';
    s.average_mark = 5.56;

    print_student_row(s);

    return 0;
}

void print_student_row(student_t s) {
    printf(
        "| %s | %s | %d%c | %.2f |\n",
        s.name, s.id, s.grade, s.grade_letter, s.average_mark
    );
}

#include <stdio.h>

#define NAME_MAX_LEN 20
#define ID_NUM_LEN 11

typedef struct student_t {
    char name[NAME_MAX_LEN];
    char id_num[ID_NUM_LEN];
    unsigned short class_num;
    char class_letter;
    float avg_grade;
} student_t;

void print_student_row(student_t);

int main() {
    student_t s = {
        .name = "Pesho",
        .id_num = "0042076405",
        .class_num = 10,
        .class_letter = 'A',
        .avg_grade = 5.67
    };

    print_student_row(s);

    return 0;
}

void print_student_row(student_t s) {
    printf("| %s | %s | %u%c | %.2f |\n",
        s.name,
        s.id_num,
        s.class_num,
        s.class_letter,
        s.avg_grade
    );
}

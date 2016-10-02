#include <stdio.h>
#include <stdlib.h>

static const size_t MAX_LINE_LENGTH = 1024;

void print_file_content(char*);

int main(int argc, char const *argv[]) {
    for(int i = 1; i < argc; i++) {
        print_file_content((char*)argv[i]);
    }

    return 0;
}

void print_file_content(char* filename) {
    FILE* f = fopen(filename, "r");

    if(f == NULL) {
        printf("Invalid or inaccessible file: %s\n", filename);
        exit(1);
    }

    char content[MAX_LINE_LENGTH];
    while(fgets(content, MAX_LINE_LENGTH, f) != NULL) {
        printf("%s", content);
    }

    fclose(f);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int BUF_SIZE = 15;
static const size_t HEX_VALUE_LEN = 2; // 4d
static const size_t HEX_COLOR_LEN = 7; // #4d00f8
static const int MIN_RGB_VALUE = 0;
static const int MAX_RGB_VALUE = 255;

void print_in_decimal(char*);
void print_in_hexademical(char*);

int main() {
    char format;
    do {
        scanf("%c ", &format);

        if(format != 'h' && format != 'd') {
            printf("Supported formats are [h]exademical and [d]ecimal.\n");
        }
    } while(format != 'h' && format != 'd');

    char color[BUF_SIZE];
    fgets(color, BUF_SIZE, stdin);
    strtok(color, "\n");

    format == 'd' ?
        print_in_hexademical(color) :
        print_in_decimal(color);

    return 0;
}

void print_in_decimal(char* color) {
    size_t color_len = strlen(color);

    // strlen("#fbff4d") -> HEX_COLOR_LEN (7)
    if(color_len != HEX_COLOR_LEN) {
        printf("%s is an invalid hexademical color.\n", color);
        exit(1);
    }

    int rgb[3], j = 0;
    char hex[HEX_VALUE_LEN];

    // "#fbff4d" -> start iterating after "#"
    for(int i = 1; i < color_len; i += 2) {
        sprintf(hex, "%c%c", color[i], color[i + 1]); // hex = "ff"

        rgb[j] = (int)strtol(hex, NULL, 16); // "ff" -> 255
        j++;
    }

    printf("rgb(%d, %d, %d)\n", rgb[0], rgb[1], rgb[2]);
}

void print_in_hexademical(char* color) {
    int rgb_value;
    char result[HEX_COLOR_LEN], hex[HEX_VALUE_LEN];

    char* token = strtok(color, ", "); // "251, 255, 77" -> "251"

    strcat(result, "#"); // #...

    while(token != NULL) {
        rgb_value = (int)strtol(token, NULL, 10); // "255" -> 255 [int]

        if(rgb_value < MIN_RGB_VALUE || rgb_value > MAX_RGB_VALUE) {
            printf("Invalid rgb value: %d\n", rgb_value);
            exit(1);
        }

        sprintf(hex, "%02x", rgb_value); // 255 -> "ff"
        strcat(result, hex); // #ff...

        token = strtok(NULL, ", "); // "255, 77" -> "255"...
    }

    printf("%s\n", result);
}

#include <stdio.h>

int is_whitespace(char c) {
    return (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\v' ||
            c == '\f');
}

/*
    Usage: wc <FILE_NAME>
    Output:
    <LINES> <WORDS> <BYTES>
*/
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: wc <FILE_NAME>\n");
        return 1;
    }

    FILE* f = fopen(argv[1], "r");
    if (!f) {
        printf("Error: unable to open file\n");
        return 1;
    }

    int ch;
    int lines = 0, words = 0;
    long bytes = 0;
    int in_word = 0;

    while ((ch = fgetc(f)) != EOF) {
        bytes++;

        char c = (char)ch;

        if (c == '\n') {
            lines++;
        }

        if (is_whitespace(c)) {
            in_word = 0;
        } else {
            if (!in_word) {
                words++;
                in_word = 1;
            }
        }
    }

    printf("%d\t%d\t%ld\t%s\n", lines, words, bytes, argv[1]);

    return 0;
}
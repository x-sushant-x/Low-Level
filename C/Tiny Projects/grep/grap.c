#include "grap.h"

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 128  // Bytes

// ./grap -f FILE -s Text
int main(int argc, char** argv) {
    if (argc != 5) {
        printf("Usage: ./grap -f <FILE_NAME> -s \"<SEARCH_TEXT>\"");
        return 1;
    }

    char* file_name = argv[2];
    char* search = argv[4];

    FILE* file = fopen(file_name, "r");
    if (!file) {
        printf("Error: Unable to open file. Does it exists?");
        return 1;
    }

    grap(file, search);
    return 0;
}

int substr_found(char* line, char* search) {
    for (size_t i = 0; line[i] != '\0'; i++) {
        size_t j = 0;

        while (line[i + j] == search[j] && search[j] != '\0') {
            j++;
        }

        if (search[j] == '\0') {
            return 1;
        }
    }

    return 0;
}

char* alloc_more_mem(size_t* size, char* line) {
    *size = *size * 2;

    char* temp = realloc(line, *size);
    if (!temp) {
        free(line);
        return NULL;
    }

    return temp;
}

void grap(FILE* file, char* search) {
    int i = 0;
    int ch;

    char* line = malloc(INITIAL_SIZE);
    size_t size = INITIAL_SIZE;
    size_t len = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (len + 1 >= size) {
            line = alloc_more_mem(&size, line);
            if (!line) {
                return;
            }
        }

        line[len++] = ch;

        if (ch == '\n') {
            line[len] = '\0';

            if (substr_found(line, search)) {
                printf("%s", line);
            }

            len = 0;
        }
    }

    if (len > 0) {
        line[len] = '\0';

        if (substr_found(line, search)) {
            printf("%s", line);
        }
    }

    fclose(file);
    free(line);
}
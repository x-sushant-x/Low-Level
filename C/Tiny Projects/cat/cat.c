#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"

void file_copy(FILE* ifp, FILE* ofp, const char* name) {
    int c;

    while ((c = getc(ifp)) != EOF) {
        if (putc(c, ofp) == EOF) {
            perror("write error");
            exit(EXIT_FAILURE);
        }
    }

    if (ferror(ifp)) {
        fprintf(stderr, "cat: read error on %s\n", name);
        perror("read");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char** argv) {
    log_initialize("cat.log");

    FILE* fp;
    char* prog = argv[0];

    if (argc == 1) {
        file_copy(stdin, stdout, "stdin");
    } else {
        while (--argc > 0) {
            const char* filename = *++argv;

            if ((fp = fopen(filename, "r")) == NULL) {
                // fprintf(stderr, "cat: can't open file %s\n", filename);
                log_error("cat: can't open file %s: %s", filename,
                          strerror(errno));
                perror("open");
                continue;
            } else {
                file_copy(fp, stdout, filename);

                if (fclose(fp) == EOF) {
                    perror("fclose");
                    exit(EXIT_FAILURE);
                }
            }
        }

        if (ferror(stdout)) {
            perror("stdout");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
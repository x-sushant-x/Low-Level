#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PERMISSION 0666
#define BUF_SIZE 128

void error(char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}

int main(int argc, char* argv[]) {
    int from, to, n;
    char buf[BUF_SIZE];

    if (argc != 3) {
        error("Usage: copy <SOURCE_FILE> <TARGET_FILE>");
    }

    from = open(argv[1], O_RDONLY, 0);
    if (from == -1) {
        error("copy: can't open file %s", argv[1]);
    }

    to = creat(argv[2], PERMISSION);
    if (to == -1) {
        error("copy: can't open file %s", argv[2]);
    }

    while ((n = read(from, buf, BUF_SIZE)) > 0) {
        if (write(to, buf, n) != n) {
            error("cp: write error on file %s", argv[2]);
        }
    }
    return 0;
}
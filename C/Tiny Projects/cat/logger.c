#include "logger.h"

#include <stdarg.h>
#include <stdlib.h>

static FILE* logfp = NULL;

void log_initialize(const char* file) {
    logfp = fopen(file, "a");
    if (!logfp) {
        perror("log");
        exit(EXIT_FAILURE);
    }
}

void log_error(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(logfp, fmt, args);
    fprintf(logfp, "\n");
    va_end(args);
}
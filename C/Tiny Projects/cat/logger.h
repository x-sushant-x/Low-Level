#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

void log_initialize(const char* file);
void log_error(const char* fmt, ...);

#endif
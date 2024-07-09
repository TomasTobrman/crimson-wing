#include "garrulus/logger.h"

#include <stdio.h>
#include <stdarg.h>

#define BUFFER_SIZE 512

void log_output(log_level level, const char* file, const int line, const char *format, ...) {
    const char *level_str[] = { "FATAL", "ERROR", "WARN", "INFO", "DEBUG", "TRACE" };
    char message[BUFFER_SIZE];

    va_list args;
    va_start(args, format);
    vsnprintf(message, BUFFER_SIZE, format, args);
    va_end(args);

    if (level > G_LOG_LEVEL_ERROR) {
        fprintf(stdout, "[%s]\t%s:%d - %s\n", level_str[level], file, line, message);
    } else {
        fprintf(stderr, "[%s]\t%s:%d - %s\n", level_str[level], file, line, message);
    }
}

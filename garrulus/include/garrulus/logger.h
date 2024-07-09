#ifndef _GARRULUS_LOGGER_H_
#define _GARRULUS_LOGGER_H_

#include "defines.h"

typedef enum log_level {
    G_LOG_LEVEL_FATAL = 0,
    G_LOG_LEVEL_ERROR = 1,
    G_LOG_LEVEL_WARN  = 2,
    G_LOG_LEVEL_INFO  = 3,
    G_LOG_LEVEL_DEBUG = 4,
    G_LOG_LEVEL_TRACE = 5,
} log_level;

#define G_ENABLE_LOG_ERROR 1
#define G_ENABLE_LOG_WARN  1
#define G_ENABLE_LOG_INFO  1

#ifdef _DEBUG
#define G_ENABLE_LOG_DEBUG 1
#define G_ENABLE_LOG_TRACE 1
#else
#define G_ENABLE_LOG_DEBUG 0
#define G_ENABLE_LOG_TRACE 0
#endif

#define G_FATAL(format, ...) log_output(G_LOG_LEVEL_FATAL, __FILE__, __LINE__, format, __VA_ARGS__);

#if G_ENABLE_LOG_ERROR
#define G_ERROR(format, ...) log_output(G_LOG_LEVEL_ERROR, __FILE__, __LINE__, format, __VA_ARGS__);
#else
#define G_ERROR(format, ...)
#endif

#if G_ENABLE_LOG_WARN
#define G_WARN(format, ...) log_output(G_LOG_LEVEL_WARN, __FILE__, __LINE__, format, __VA_ARGS__);
#else
#define G_WARN(format, ...)
#endif

#if G_ENABLE_LOG_INFO
#define G_INFO(format, ...) log_output(G_LOG_LEVEL_INFO, __FILE__, __LINE__, format, __VA_ARGS__);
#else
#define G_INFO(format, ...)
#endif

#if G_ENABLE_LOG_DEBUG
#define G_DEBUG(format, ...) log_output(G_LOG_LEVEL_DEBUG, __FILE__, __LINE__, format, __VA_ARGS__);
#else
#define G_DEBUG(format, ...)
#endif

#if G_ENABLE_LOG_TRACE
#define G_TRACE(format, ...) log_output(G_LOG_LEVEL_TRACE, __FILE__, __LINE__, format, __VA_ARGS__);
#else
#define G_TRACE(format, ...)
#endif

GAPI void log_output(log_level level, const char *file, const int line, const char *format, ...);

#endif /* ifndef _GARRULUS_LOGGER_H_ */

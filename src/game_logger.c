#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "game_logger.h"

char* get_current_time()
{
    time_t now;
    time(&now);

    char* buffer = malloc(32);

    if (buffer != 0)
    {
        strftime(buffer, 32, "%Y-%m-%dT%H:%M:%SZ", gmtime(&now));
    }

    return buffer;
}

void log_level(char* level, char* message)
{
    char* current_time = get_current_time();

    printf("%s [%s] %s\n", current_time, level, message);

    free(current_time);
}

void log_info(char* message)
{
    log_level("INFO", message);
}

void log_debug(char* message)
{
#ifdef DEBUG
    log_any("DEBUG", message);
#endif
}

void log_warn(char* message)
{
    log_level("WARN", message);
}

void log_error(char* message)
{
    log_level("ERROR", message);
}
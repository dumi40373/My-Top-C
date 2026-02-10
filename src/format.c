/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** Memory format utilities
*/

#include <stdlib.h>
#include <stdio.h>

char *format_memory(double bytes)
{
    char *str = malloc(sizeof(char) * 10);

    if (bytes >= 1024 * 1024 * 1024)
        snprintf(str, sizeof(str), "%.1fG", bytes / (1024 * 1024 * 1024));
    else
        snprintf(str, sizeof(str), "%.0f", bytes);
    return str;
}

char *format_time(long centiseconds)
{
    char *buffer = malloc(sizeof(char) * 12);
    long total_seconds = centiseconds / 100;
    long minutes = total_seconds / 60;
    long seconds = total_seconds % 60;
    long cents = centiseconds % 100;

    snprintf(buffer, 12, "%ld:%02ld.%02ld",
        minutes, seconds, cents);
    return buffer;
}

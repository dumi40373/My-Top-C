/*
** EPITECH PROJECT, 2025
** string_copy
** File description:
** String copy functions
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int n = my_strlen(src);

    for (int i = 0; i <= n; i++) {
        dest[i] = src[i];
    }
    return dest;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i <= n - 1; i++) {
        dest[i] = src[i];
    }
    return dest;
}

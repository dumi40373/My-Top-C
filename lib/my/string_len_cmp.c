/*
** EPITECH PROJECT, 2025
** string_len_cmp
** File description:
** String length and comparison functions
*/

#include <unistd.h>
#include "my.h"

int my_strlen(char const *str)
{
    int x = 0;

    for (int i = 0; str[i] != '\0'; i++){
        x++;
    }
    return x;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (my_strlen(s1) == my_strlen(s2)) {
        for (; s1[i] == s2[i] && s1[i] != '\0'; i++);
    }
    if (i == my_strlen(s1))
        return 1;
    return 0;
}

int my_strncmp2(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i < n && s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return ((int)s1[i] - (int)s2[i]);
        }
        i++;
    }
    if (i < n) {
        return ((int)s1[i] - (int)s2[i]);
    }
    return 0;
}

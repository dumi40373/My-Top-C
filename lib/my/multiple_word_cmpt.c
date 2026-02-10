/*
** EPITECH PROJECT, 2025
** multiple_word_cmpt
** File description:
** count occurrences of multiple delimiter characters in a string
*/

#include "my.h"

int my_multiple_word_cmpt(const char *str, const char *delim, int *lim)
{
    int cmpt = 0;

    for (int i = 0; i < my_strlen(str); i++){
        if (str[i] == delim[*lim]){
            cmpt += 1;
        }
    }
    *lim += 1;
    if (delim[*lim] == '\0')
        return cmpt;
    return cmpt + my_multiple_word_cmpt(str, delim, lim);
}

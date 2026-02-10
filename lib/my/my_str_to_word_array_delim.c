/*
** EPITECH PROJECT, 2025
** day08
** File description:
** day08
*/

#include <stdlib.h>
#include "my.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *allocate_by_word(const char *str, char delim, int *i)
{
    char *final;
    int len = 0;

    while (str[*i] != '\0' && str[*i] != delim) {
        len++;
        *i += 1;
    }
    final = malloc(sizeof(char) * (len + 1));
    if (!final)
        return NULL;
    final[len] = '\0';
    return final;
}

char **allocate2(int wrd_cmpt, const char *str, char delim)
{
    char **tab = malloc(sizeof(char *) * (wrd_cmpt + 1));
    int j = 0;

    for (int i = 0; i < wrd_cmpt; i++){
        tab[i] = allocate_by_word(str, delim, &j);
        j++;
    }
    tab[wrd_cmpt] = NULL;
    return tab;
}

int word_cmpt(const char *str, char delim)
{
    int cmpt = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == delim && str[i + 1] != '\0')
            cmpt++;
    }
    return cmpt + 1;
}

char **my_str_to_word_array_delim(char const *str, char delim)
{
    int wrd_cmpt = word_cmpt(str, delim);
    char **tab = allocate2(wrd_cmpt, str, delim);
    int j = 0;
    int letter = 0;

    for (int i = 0; i < wrd_cmpt; i++){
        for (; str[j] != delim && str[j] != '\0'; j++){
            tab[i][letter] = str[j];
            letter++;
        }
        if (str[j] == delim)
            j++;
        letter = 0;
    }
    return tab;
}

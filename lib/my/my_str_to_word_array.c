/*
** EPITECH PROJECT, 2025
** str_to word
** File description:
** epi
*/

#include <stdlib.h>
#include "my.h"

static int word_cmpt(char *str)
{
    int cmpt = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (my_isalpha(str[i]) != 1)
            cmpt++;
    return cmpt + 1;
}

static char *alloc_by_str(char *str, int *deca)
{
    char *tmp;
    int len = 0;

    for (; my_isalpha(str[*deca]) != 0; *deca += 1)
        len++;
    tmp = malloc(sizeof(char) * (len + 1));
    tmp[len] = '\0';
    *deca += 1;
    return tmp;
}

static char **allocate(char *str)
{
    int deca = 0;
    char **tab = malloc(sizeof(char *) * (word_cmpt(str) + 1));

    for (int i = 0; i < word_cmpt(str); i++)
        tab[i] = alloc_by_str(str, &deca);
    tab[word_cmpt(str)] = NULL;
    return tab;
}

static char **put_in_tab(char **tab, char *str, int *deca, int *pos)
{
    if (tab[*deca] == NULL)
        return tab;
    for (int i = 0; my_isalpha(str[*pos]) != 0; i++) {
        tab[*deca][i] = str[*pos];
        *pos += 1;
    }
    *pos += 1;
    *deca += 1;
    return put_in_tab(tab, str, deca, pos);
}

char **my_str_to_word_array(char const *str)
{
    int deca = 0;
    int pos = 0;
    char **tab = allocate((char *)str);

    tab = put_in_tab(tab, (char *)str, &deca, &pos);
    return tab;
}

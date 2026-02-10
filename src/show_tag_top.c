/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** show_tag_top
*/

#include "../include/my.h"
#include "../include/top.h"

struct arg_list_top
{
    char arg;
    int (*pf)(int i, char **argv, flags_t *data);
};

const struct arg_list_top s1[3] = {
    {'U', handle_u},
    {'d', handle_d},
    {'n', handle_n}
};

int top_option(char flag)
{
    for (int j = 0; j < 3; j++) {
        if (s1[j].arg == flag)
            return j;
    }
    return -1;
}

int show_tag_verif(int i, char **argv)
{
    int j = 0;
    char flag;
    int counter = 0;

    if (argv[i][0] == '-') {
        flag = argv[i][1];
        j = top_option(flag);
        if (j == -1)
            return 0;
        if (!argv[i + 1])
            return 0;
    }
    return 1;
}

int get_function(int i, char **argv, flags_t *data)
{
    int j = 0;
    char flag;
    int counter = 0;

    if (argv[i][0] == '-') {
        flag = argv[i][1];
        j = top_option(flag);
        if (j == -1)
            return 0;
        counter = s1[j].pf(i, argv, data);
        i += counter;
    }
    return i;
}

int show_tag_top(int argc, char **argv, flags_t *data)
{
    for (int i = 1; i < argc; i++) {
        if (!show_tag_verif(i, argv))
            return 1;
        else
            i = get_function(i, argv, data);
        if (argv[i][0] != '-')
            continue;
    }
    return 0;
}

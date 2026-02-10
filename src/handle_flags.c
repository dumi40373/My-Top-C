/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** handle_flag_n
*/

#include "../include/my.h"
#include "../include/top.h"

int handle_n(int i, char **argv, flags_t *data)
{
    int frames_arg = 0;

    if (!argv[i + 1])
        return 84;
    frames_arg = my_getnbr(argv[i + 1]);
    data->is_n = 1;
    data->max_frames = frames_arg;
    return 0;
}

int handle_u(int i, char **argv, flags_t *data)
{
    if (!argv[i + 1])
        return 84;
    data->is_u = 1;
    data->username = strdup(argv[i + 1]);
    return 0;
}

int handle_d(int i, char **argv, flags_t *data)
{
    if (!argv[i + 1])
        return 84;
    data->delay = atof(argv[i + 1]);
    return 0;
}

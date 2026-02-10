/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** Per-process scheduler-related values
*/

#include <time.h>
#include "../include/my.h"
#include "../include/top.h"

int return_prio(char *pid)
{
    char path[50] = "/proc/";
    char **stat;
    int prio;

    my_strcat(path, pid);
    my_strcat(path, "/stat");
    stat = read_stat(path);
    if (!stat)
        return -1;
    prio = string_to_int(stat[17]);
    free_all(stat);
    return prio;
}

int nice_val(char *pid)
{
    char path[50] = "/proc/";
    char **stat;
    int ni;

    my_strcat(path, pid);
    my_strcat(path, "/stat");
    stat = read_stat(path);
    if (!stat)
        return -1;
    ni = my_getnbr(stat[18]);
    free_all(stat);
    return ni;
}

char return_status(char *pid)
{
    char path[50] = "/proc/";
    char **stat;
    char status;

    my_strcat(path, pid);
    my_strcat(path, "/stat");
    stat = read_stat(path);
    if (!stat)
        return -1;
    status = stat[2][0];
    free_all(stat);
    return status;
}

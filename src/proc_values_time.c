/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** Per-process time-related values
*/

#include <time.h>
#include "../include/my.h"
#include "../include/top.h"

long utime_val(char *pid)
{
    char path[50] = "/proc/";
    char **stat;
    long utime;

    my_strcat(path, pid);
    my_strcat(path, "/stat");
    stat = read_stat(path);
    if (!stat)
        return -1;
    utime = string_to_int(stat[13]);
    free_all(stat);
    return utime;
}

long stime_val(char *pid)
{
    char path[50] = "/proc/";
    char **stat;
    long stime;

    my_strcat(path, pid);
    my_strcat(path, "/stat");
    stat = read_stat(path);
    if (!stat)
        return -1;
    stime = string_to_int(stat[14]);
    free_all(stat);
    return stime;
}

long ret_total_time(char *pid)
{
    long utime = utime_val(pid);
    long stime = stime_val(pid);
    long ticks_per_sec = sysconf(_SC_CLK_TCK);
    long total_ticks = utime + stime;

    return (total_ticks * 100) / ticks_per_sec;
}

/*
** EPITECH PROJECT, 2026
** calc
** File description:
** calc
*/

#include "../include/top.h"
#include "../include/my.h"

double calc_proc_ticks(double utime, double stime)
{
    return utime + stime;
}

double delta_prock_ticks(double new_ticks, double old_ticks)
{
    return new_ticks - old_ticks;
}

double cpu_time_sec(double proc_ticks)
{
    return proc_ticks / sysconf(_SC_CLK_TCK);
}

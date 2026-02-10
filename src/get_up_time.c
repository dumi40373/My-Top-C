/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** get up time
*/

#include "../include/my.h"
#include "../include/top.h"

int get_up_time(header_info_t *info)
{
    FILE *file = fopen("/proc/uptime", "r");
    long long total_sec = 0;
    int days = 0;
    int hours = 0;
    int mins = 0;
    int rem = 0;

    fscanf(file, "%lld", &total_sec);
    days = total_sec / 86400;
    rem = total_sec % 86400;
    hours = rem / 3600;
    rem = rem % 3600;
    mins = rem / 60;
    info->up_sec = total_sec;
    info->up_min = mins;
    info->up_hours = hours;
    info->up_days = days;
    fclose(file);
    return 0;
}

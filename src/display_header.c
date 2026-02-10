/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** Header display functions
*/

#include "../include/my.h"
#include "../include/top.h"

int print_up_time(header_info_t *info)
{
    if (info->up_sec < 3600) {
        printw("up %d min,", info->up_min);
        return 0;
    }
    if (info->up_sec < 86400) {
        printw("up %d:%02d,", info->up_hours, info->up_min);
        return 0;
    }
    if (info->up_sec < 172800) {
        printw("up %d day, %d:%02d,", info->up_days, info->up_hours,
            info->up_min);
        return 0;
    }
    printw("up %d days, %d:%02d,", info->up_days, info->up_hours,
        info->up_min);
    return 0;
}

void put_header(header_info_t *info)
{
    double loadavg[3];

    my_get_time_of_day(info);
    get_up_time(info);
    get_users_nb(info);
    my_getloadavg(loadavg, 3);
    get_total_proc(info);
    printw("top - %02d:%02d:%02d ", info->hour, info->min, info->sec);
    print_up_time(info);
    printw(" %d user, load average: %.2f, %.2f, %.2f\n", info->nb_users,
        loadavg[0], loadavg[1], loadavg[2]);
    printw("Tasks: %d total, %d running, %d sleeping, "
        "%d stopped, %d zombie\n", info->total_proc.counter,
        info->total_proc.running, info->total_proc.sleeping,
        info->total_proc.stopped, info->total_proc.zombie);
}

void put_mem_header(header_info_t *info)
{
    put_mem_info(info);
    put_swap_info(info);
    printw("MiB Mem : %.1f total, %.1f free, %.1f used, %.1f buff/cache\n",
        info->memory.total, info->memory.free, info->memory.used,
        info->memory.buff_cache);
    printw("MiB Swap: %.1f total, %.1f free, %.1f used. %.1f avail Mem\n",
        info->swap.total, info->swap.free, info->swap.used,
        info->swap.avail_mem);
}

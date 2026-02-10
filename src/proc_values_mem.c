/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** Per-process memory-related values
*/

#include <time.h>
#include "../include/my.h"
#include "../include/top.h"

double virt_val(char *pid)
{
    char path[50] = "/proc/";
    char **stat;
    double ni;

    my_strcat(path, pid);
    my_strcat(path, "/statm");
    stat = read_stat(path);
    if (!stat)
        return -1;
    ni = strtod(stat[0], NULL);
    free_all(stat);
    return ni * 4;
}

long res_val(char *pid)
{
    char path[50] = "/proc/";
    char **stat;
    long res;

    my_strcat(path, pid);
    my_strcat(path, "/statm");
    stat = read_stat(path);
    if (!stat)
        return -1;
    res = string_to_int(stat[1]);
    free_all(stat);
    return res * 4;
}

long shr_val(char *pid)
{
    char path[50] = "/proc/";
    char **stat;
    long shr;

    my_strcat(path, pid);
    my_strcat(path, "/statm");
    stat = read_stat(path);
    if (!stat)
        return -1;
    shr = string_to_int(stat[2]);
    free_all(stat);
    return shr * (4096 / 1024);
}

double ret_mem(long res)
{
    double mem_tot = (read_mem_arg("MemTotal") * 1024.0) * 1024.0;

    return ((double)res / mem_tot) * 100.0;
}

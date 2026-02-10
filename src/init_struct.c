/*
** EPITECH PROJECT, 2026
** bs
** File description:
** bs
*/

#include <time.h>
#include "../include/my.h"
#include "../include/top.h"

void init_proc_node(proc_t *new, struct dirent *dirp, struct timespec *ts)
{
    new->pid = string_to_int(dirp->d_name);
    new->pr = return_prio(dirp->d_name);
    new->ni = nice_val(dirp->d_name);
    new->virt = virt_val(dirp->d_name);
    new->res = res_val(dirp->d_name);
    new->shr = shr_val(dirp->d_name);
    new->mem = ret_mem(new->res * 1024);
    new->s = return_status(dirp->d_name);
    new->cpu = 0.0;
    new->proc_ticks = calc_proc_ticks(utime_val(dirp->d_name),
        stime_val(dirp->d_name));
    new->time_sec = cpu_time_sec(new->proc_ticks);
    new->cpu_timesec = ts->tv_sec + (ts->tv_nsec / 1000000000.0);
    new->time_plous = ret_total_time(dirp->d_name);
    new->cmd = return_cmd_name(dirp->d_name);
    new->next = NULL;
}

void create_node(struct dirent *dirp, proc_t **process)
{
    proc_t *new = malloc(sizeof(proc_t));
    struct timespec ts;

    if (!new)
        return;
    new->pid = string_to_int(dirp->d_name);
    new->usr = user_process(dirp->d_name);
    if (!new->usr) {
        free(new);
        return;
    }
    clock_gettime(CLOCK_MONOTONIC, &ts);
    init_proc_node(new, dirp, &ts);
    new->next = *process;
    *process = new;
}

int detect_process(char *path, char *target)
{
    size_t len = my_strlen(path) + my_strlen(target) + 1;
    char *str = malloc(len);
    DIR *dir = NULL;

    if (!str)
        return 0;
    my_strcpy(str, path);
    my_strcat(str, target);
    dir = opendir(str);
    if (dir) {
        closedir(dir);
        free(str);
        return 1;
    }
    free(str);
    return 0;
}

void init_struct(proc_t **process)
{
    DIR *dp;
    char *path = "/proc/";

    dp = opendir(path);
    if (!dp)
        return;
    *process = NULL;
    for (struct dirent *dirp = readdir(dp); dirp; dirp = readdir(dp))
        if (detect_process(path, dirp->d_name))
            create_node(dirp, process);
    closedir(dp);
    return;
}

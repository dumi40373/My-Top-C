/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** get_header_mem
*/

#include "../include/my.h"
#include "../include/top.h"

char *read_mem_line(char *word)
{
    FILE *file = fopen("/proc/meminfo", "r");
    char line[256];
    char *res;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, word, strlen(word)) == 0) {
            res = strdup(line);
            fclose(file);
            return res;
        }
    }
    fclose(file);
    return NULL;
}

double read_mem_arg(char *line_name)
{
    char *line;
    char *arg;
    int a = 0;
    int number = 0;

    line = read_mem_line(line_name);
    arg = malloc(sizeof(char) * my_strlen(line));
    for (int i = 0; line[i]; i++)
        if (my_isnumeric(line[i])) {
            arg[a] = line[i];
            a++;
        }
    arg[a] = '\0';
    number = my_getnbr(arg);
    free(line);
    free(arg);
    return (double)number / 1024.0;
}

static void get_mem_buff_cache(mem_t *inf)
{
    double buff = read_mem_arg("Buffers:");
    double cache = read_mem_arg("Cached:");
    double sreclaim = read_mem_arg("SReclaimable:");

    inf->buff_cache = buff + cache + sreclaim;
}

static void read_mem_used(mem_t *inf)
{
    double shmem = read_mem_arg("Shmem:");
    double sunreclaim = read_mem_arg("SUnreclaim:");

    inf->used = inf->total - inf->free - inf->buff_cache + (sunreclaim + shmem);
}

void put_mem_info(header_info_t *info)
{
    mem_t inf = {0.0, 0.0, 0.0, 0.0};

    inf.total = read_mem_arg("MemTotal:");
    inf.free = read_mem_arg("MemFree:");
    get_mem_buff_cache(&inf);
    read_mem_used(&inf);
    info->memory.total = inf.total;
    info->memory.free = inf.free;
    info->memory.used = inf.used;
    info->memory.buff_cache = inf.buff_cache;
}

void put_swap_info(header_info_t *info)
{
    swap_t inf = {0.0, 0.0, 0.0, 0.0};

    inf.total = read_mem_arg("SwapTotal:");
    inf.free = read_mem_arg("SwapFree:");
    inf.used = inf.total - inf.free;
    inf.avail_mem = read_mem_arg("MemAvailable:");
    info->swap.total = inf.total;
    info->swap.free = inf.free;
    info->swap.used = inf.used;
    info->swap.avail_mem = inf.avail_mem;
}

/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** total_proc
*/

#include "../include/my.h"
#include "../include/top.h"

char parse_proc_stat(char *dir_name)
{
    char *file_path = strdup("/proc/");
    char buffer[1024];
    FILE *file;
    int index;
    char res;

    my_strcat(file_path, dir_name);
    my_strcat(file_path, "/stat");
    file = fopen(file_path, "r");
    fgets(buffer, sizeof(buffer), file);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ')')
            index = i;
    }
    while (!my_isalpha(buffer[index]))
        index++;
    res = buffer[index];
    free(file_path);
    fclose(file);
    return res;
}

void increment_stat(proc_stat_t *stat, char *dir_name)
{
    char value = parse_proc_stat(dir_name);

    stat->counter++;
    if (value == 'R')
        stat->running++;
    if (value == 'S' || value == 'D' || value == 'I')
        stat->sleeping++;
    if (value == 'T')
        stat->stopped++;
    if (value == 'Z')
        stat->zombie++;
}

void get_total_proc(header_info_t *info)
{
    DIR *dir;
    struct dirent *entry;
    int counter;
    proc_stat_t stat = {0, 0, 0, 0, 0};

    dir = opendir("/proc");
    if (dir == NULL)
        return;
    entry = readdir(dir);
    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if (entry->d_name[0] != '.' && my_str_isnumeric(entry->d_name)) {
            increment_stat(&stat, entry->d_name);
        }
    }
    closedir(dir);
    info->total_proc.counter = stat.counter;
    info->total_proc.running = stat.running;
    info->total_proc.sleeping = stat.sleeping;
    info->total_proc.stopped = stat.stopped;
    info->total_proc.zombie = stat.zombie;
}

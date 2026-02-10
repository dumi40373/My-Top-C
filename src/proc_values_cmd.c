/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** Per-process command name helpers
*/

#include <time.h>
#include "../include/my.h"
#include "../include/top.h"

static char *return_name(char *str)
{
    int z = 0;
    char *new_str = malloc(sizeof(char) * (my_strlen(str)) - 1);

    for (int i = 1; str[i + 1] != '\0'; i++){
        new_str[z] = str[i];
        z++;
    }
    new_str[z] = '\0';
    return new_str;
}

char *return_cmd_name(char *pid)
{
    char path[50] = "/proc/";
    char **stat;
    char *name;

    my_strcat(path, pid);
    my_strcat(path, "/stat");
    stat = read_stat(path);
    if (!stat)
        return NULL;
    name = return_name(stat[1]);
    free_all(stat);
    return name;
}

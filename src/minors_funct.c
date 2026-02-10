/*
** EPITECH PROJECT, 2026
** bs
** File description:
** bs
*/

#include "../include/my.h"
#include "../include/top.h"

long delta_proc_time(long utime, long stime,
    long utime2, long stime2)
{
    return ((utime2 + stime2) - (utime + stime));
}

void free_all(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

void put_in_center(double nb[], int nelem)
{
    char str[50];
    int max_y;
    int max_x;

    clear();
    getmaxyx(stdscr, max_y, max_x);
    move(max_y / 2, max_x / 2);
    for (int i = 0; i < nelem; i++){
        snprintf(str, 50, "%f", nb[i]);
        addstr(str);
        if (i + 1 != nelem)
            addstr(" ");
        refresh();
    }
}

char **read_stat(const char *path)
{
    char *buf = malloc(sizeof(char) * 200);
    char **str;
    int fd = open(path, O_RDONLY);

    if (fd < 0)
        return NULL;
    buf[199] = '\0';
    read(fd, buf, 199);
    str = my_str_to_word_array_delim(buf, ' ');
    close(fd);
    free(buf);
    return str;
}

char **read_file(const char *path)
{
    struct stat filestat;
    char *buf;
    char **str;
    int fd = open(path, O_RDONLY);

    stat(path, &filestat);
    buf = malloc(sizeof(char) * (filestat.st_size + 1));
    buf[filestat.st_size] = '\0';
    read(fd, buf, filestat.st_size);
    str = my_str_to_word_array_delim(buf, '\n');
    close(fd);
    free(buf);
    return str;
}

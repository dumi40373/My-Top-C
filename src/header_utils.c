/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** get_time_of_day
*/

#include "../include/my.h"
#include "../include/top.h"

void my_get_time_of_day(header_info_t *info)
{
    time_t timestamp = time(NULL);
    struct tm *ti = localtime(&timestamp);

    info->hour = ti->tm_hour;
    info->min = ti->tm_min;
    info->sec = ti->tm_sec;
}

int is_seat(struct utmp *n)
{
    return (strncmp(n->ut_line, "seat", 4) == 0);
}

int get_users_nb(header_info_t *info)
{
    struct utmp n;
    FILE *file = fopen("/run/utmp", "r");
    int counter = 0;

    if (file == NULL)
        return 84;
    while (fread(&n, sizeof(struct utmp), 1, file) == 1) {
        if (n.ut_type == USER_PROCESS && !is_seat(&n))
            counter++;
    }
    fclose(file);
    info->nb_users = counter;
    return 0;
}

int my_getloadavg(double loadavg[], int nelem)
{
    FILE *file = fopen("/proc/loadavg", "r");

    for (int i = 0; i < nelem; i++)
        fscanf(file, "%lf", &loadavg[i]);
    return 0;
}

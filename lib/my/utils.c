/*
** EPITECH PROJECT, 2025
** utils
** File description:
** Miscellaneous utility functions
*/

#include <stdlib.h>
#include "my.h"

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

static int max_lencmpt(char *s1, char *s2)
{
    if (my_strlen(s1) > my_strlen(s2))
        return my_strlen(s1);
    else
        return my_strlen(s2);
}

char **my_put_in_alphabet(char **argv)
{
    int len = 0;
    char *tmp;
    int max_len;
    int swap = 0;

    for (; argv[len] != NULL; len++);
    for (int i = 0; i < len && argv[i + 1] != NULL; i++){
        max_len = max_lencmpt(argv[i], argv[i + 1]);
        if (my_strncmp2(argv[i], argv[i + 1], max_len) > 0){
            tmp = argv[i];
            argv[i] = argv[i + 1];
            argv[i + 1] = tmp;
            swap = 1;
        }
    }
    if (swap == 1)
        my_put_in_alphabet(argv);
    return argv;
}

static const int days_in_month[12] = {
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
};
static const int days_in_month_leap[12] = {
    31, 29, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
};
static int check_century_leap(double tmp)
{
    if ((tmp / 100) - (int)(tmp / 100) == 0) {
        if ((tmp / 400) - (int)(tmp / 400) == 0)
            return 1;
        else
            return 0;
    }
    return 1;
}

static int bissextile_detector(int years)
{
    double tmp = years;

    if ((tmp / 4) - (int)(tmp / 4) == 0) {
        return check_century_leap(tmp);
    }
    return 0;
}

static int second_left_in_day(int nbr)
{
    return (int)(nbr % 86400);
}

static int calculate_month(long int *nbr_day, int years)
{
    int mounth = 0;

    if (bissextile_detector(years) == 1) {
        while (*nbr_day >= days_in_month_leap[mounth]) {
            *nbr_day -= days_in_month_leap[mounth];
            mounth += 1;
        }
    } else {
        while (*nbr_day >= days_in_month[mounth]) {
            *nbr_day -= days_in_month[mounth];
            mounth += 1;
        }
    }
    return mounth;
}

static char *format_day_alignment(char *date, long int nbr_day)
{
    if (my_nbrlen(nbr_day + 1) < 2) {
        date = my_strcat(date, " ");
    }
    return date;
}

static char *format_date(int mounth, long int nbr_day, int hours, int minutes)
{
    char *date = malloc(sizeof(char) * 51);
    const char *months[12] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    date[0] = '\0';
    date = my_strcat(date, months[mounth]);
    date = my_strcat(date, "  ");
    date = format_day_alignment(date, nbr_day);
    date = my_strcat(date, int_to_string(nbr_day + 1));
    date = my_strcat(date, " ");
    date = my_strcat(date, int_to_string(hours + 1));
    date = my_strcat(date, ":");
    if (minutes < 10) {
        date = my_strcat(date, "0");
    }
    date = my_strcat(date, int_to_string(minutes));
    date[my_strlen(date)] = '\0';
    return date;
}

char *my_ctime(double nbr)
{
    char *date;
    long int nbr_day = nbr / 86400;
    int seconds = second_left_in_day(nbr);
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int years = 1970;
    int mounth = 0;
    int days_in_current_year = 0;

    while (1) {
        days_in_current_year = (bissextile_detector(years) == 1) ? 366 : 365;
        if (nbr_day < days_in_current_year)
            break;
        nbr_day -= days_in_current_year;
        years++;
    }
    mounth = calculate_month(&nbr_day, years);
    date = format_date(mounth, nbr_day, hours, minutes);
    return date;
}

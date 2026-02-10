/*
** EPITECH PROJECT, 2025
** conversion
** File description:
** Type conversion functions
*/

#include <stdlib.h>
#include "my.h"

char int_to_char(int nbr)
{
    return (char)('0' + nbr);
}

int char_to_int(char c)
{
    return (int)(c - '0');
}

char *int_to_string(int nbr)
{
    int negative = (nbr < 0);
    int len = my_nbrlen(nbr);
    char *str = malloc(len + negative + 1);

    str[len + negative] = '\0';
    if (nbr < 0)
        nbr = -nbr;
    for (int i = len + negative - 1; i >= 0; i--) {
        str[i] = '0' + (nbr % 10);
        nbr /= 10;
    }
    if (negative)
        str[0] = '-';
    return str;
}

int my_getnbr(char *str)
{
    int neg = 1;
    int nb = 0;
    int i = 0;

    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-') {
            neg = neg * -1;
        }
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
        } else {
            return (nb * neg);
        }
    }
    return (nb * neg);
}

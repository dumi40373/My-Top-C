/*
** EPITECH PROJECT, 2025
** check
** File description:
** Character and value checking functions
*/

#include <unistd.h>
#include <stdio.h>

static void my_putchar2(char c)
{
    write(1, &c, 1);
}

int my_isneg(int n)
{
    if (n >= 0)
        my_putchar2('P');
    else
        my_putchar2('N');
    return (0);
}

int my_isnumeric(char nbr)
{
    if (nbr >= '0' && nbr <= '9'){
        return 1;
    } else {
        return 0;
    }
}

int my_str_isnumeric(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

int my_isalpha(char arg)
{
    if (arg >= 'a' && arg <= 'z'){
        return 1;
    }
    if (arg >= 'A' && arg <= 'Z'){
        return 1;
    }
    return 0;
}

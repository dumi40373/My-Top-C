/*
** EPITECH PROJECT, 2025
** output
** File description:
** Output functions for terminal display
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        my_putchar(str[i]);
    }
    return (0);
}

int my_put_nbr(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar((nb % 10) + '0');
    return 0;
}

int my_put_unsigned_nbr(unsigned int nb)
{
    if (nb >= 10) {
        my_put_unsigned_nbr(nb / 10);
    }
    my_putchar((nb % 10) + '0');
    return 0;
}

static float negverif(float nb)
{
    if (nb < 0.0f){
        nb = -nb;
        my_putchar('-');
    }
    return nb;
}

static int digit_verif(int digit)
{
    if (digit < 0)
        digit = 0;
    if (digit > 9)
        digit = 9;
    my_putchar('0' + digit);
    return digit;
}

void my_putfloat(double nb)
{
    int precision = 6;
    double frac = (nb - (int)nb) + 1e-6f;
    int digit = 0;
    int cmpt = frac_cmpt(nb + 1);

    nb = negverif(nb);
    my_put_nbr((int)nb);
    my_putchar('.');
    if (frac < 0.0f)
        frac = -frac;
    for (int i = 0; i < precision; ++i) {
        if (i <= cmpt){
            frac *= 10.0f;
            digit = (int)(frac);
            digit = digit_verif(digit);
            frac -= (double)digit;
            continue;
        }
        my_putchar('0');
    }
}

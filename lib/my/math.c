/*
** EPITECH PROJECT, 2025
** math
** File description:
** Mathematical functions
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    return (nb * my_compute_power_rec(nb, p - 1));
}

static int my_compute_power_it(int nb, int p)
{
    int power = nb;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    for (int i = 1; i < p; i++){
        power = power * nb;
    }
    return power;
}

int my_compute_square_root(int nb)
{
    int x = 1;

    if (nb <= 0)
        return (0);
    if (nb == 1)
        return (1);
    for (int i = 1; x < nb; i++){
        x = my_compute_power_it(i, 2);
        if (x > nb){
            return (0);
            break;
        }
        if (x == nb)
            return i;
    }
    return (0);
}

int my_is_prime(int nb)
{
    return 0;
}

int my_pow(int nbr, int expo)
{
    int result = nbr * nbr;

    if (expo == 1)
        return nbr;
    if (expo == 0)
        return 1;
    for (int i = 2; i < expo; i++){
        result = result * nbr;
    }
    return result;
}

int my_nbrlen(long int nbr)
{
    long int cmpt = 0;

    if (nbr == 0)
        return 1;
    if (nbr < 0)
        nbr = -nbr;
    while (nbr != 0) {
        nbr = nbr / 10;
        cmpt++;
    }
    return cmpt;
}

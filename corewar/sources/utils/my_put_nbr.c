/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** write a number
*/

#include "corewar.h"

void my_put_nbr(int nb)
{
    int pow = 1;
    int nbcpy = nb;
    int lon = 0;
    char result;

    while (nbcpy > 9) {
        pow = pow * 10;
        nbcpy = nbcpy / 10;
        lon = lon + 1;
    }
    while (lon > 0) {
        result = (nb / pow) + 48;
        write(1, &result, 1);
        nb = nb % pow;
        pow = pow / 10;
        lon = lon - 1;
    }
    result = nb + '0';
    write(1, &result, 1);
}

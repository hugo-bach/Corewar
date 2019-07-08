/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** my_atoi
*/

#include "asm.h"

int my_atoi(char *str)
{
    int i = 0;
    int mult = 1;
    int nb = 0;

    if (str[i] == 45) {
        mult = -1;
        i++;
    } else if (str[i] == 43)
        i++;
    while (str[i] >= 48 && str[i] <= 57 && str[i])
        nb = nb * 10 + (str[i++] - 48);
    return (nb*mult);
}

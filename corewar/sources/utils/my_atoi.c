/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** my_atoi
*/

#include "corewar.h"

int my_atoi(char *str)
{
    int i = 0;
    int factor = 1;
    int nb = 0;

    for (; str[i] != '\0' && str[i] != '\n';) {
        if (str[i] < '0' || str[i] > '9')
            return -1;
        nb = nb * 10 + (str[i++] - '0');
        if (nb < 0)
            write_error("Overflow.");
    }
    return (nb * factor);
}
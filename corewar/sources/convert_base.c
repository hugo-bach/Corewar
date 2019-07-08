/*
** EPITECH PROJECT, 2018
** convert_base.c
** File description:
** function convert_base of project corewar
*/

#include "corewar.h"

static char *zero_fill(int place, int *nb)
{
    char *list = "0123456789ABCDEF";
    char *result = malloc(sizeof(char) * (place + 1));

    result[0] = '0';
    for (int i = 1; i <= place; i++)
        result[i] = list[nb[(place - 1) - i]];
    result[place] = '\0';
    return result;
}

int base_to_int(char *str, int base)
{
    int pow = 1;
    int result = 0;
    int len = my_strlen(str);
    int val = 0;
    char c;

    for (int i = len - 1; i >= 0; i--) {
        c = str[i];
        val = (c >= '0' && c <= '9') ? c - 48 : c - 55;
        result += val * pow;
        pow *= base;
    }
    return result;
}

static char *write_base(int place, int *nb)
{
    char *list = "0123456789ABCDEF";
    char *result = malloc(sizeof(char) * (place + 1));

    for (int i = 1; i <= place; i++)
        result[i - 1] = list[nb[place - i]];
    result[place] = '\0';
    return result;
}

char *int_to_base(int decimal, int base)
{
    int nb[16] = {0};
    int quotient = decimal;
    int place = 0;
    int value = 0;

    while (quotient != 0) {
        value = quotient;
        nb[place] = value % base;
        quotient = (value - nb[place]) / base;
        place++;
    }
    if (place == 0)
        return my_strdup("00\0");
    if (place % 2 != 0)
        return zero_fill(place + 1, nb);
    return write_base(place, nb);
}

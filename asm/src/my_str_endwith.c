/*
** EPITECH PROJECT, 2018
** my_str_endwith.c
** File description:
** my_str_endwith function of the corewar
*/

#include "asm.h"

int my_str_endwith(char *str, char *end)
{
    int valid = 0;
    int j = my_strlen(str) - 1;

    if (my_strlen(end) > my_strlen(str))
        return 0;
    for (int i = my_strlen(end) - 1; i >= 0; i--)
        if (str[j] == end[i]) {
            j--;
            valid++;
        }
    if (valid == my_strlen(end))
        return 1;
    return 0;
}

/*
** EPITECH PROJECT, 2018
** get_value_intr.c
** File description:
** get value intr
*/

#include "asm.h"

int get_value_instr(char *str)
{
    if (str[0] > 47 && str[0] < 58)
        return (my_atoi(str));
    if (str[0] == 'r' && str[1] != '-')
        return (my_atoi(str += 1));
    if (str[0] == DIRECT_CHAR && str[1] == LABEL_CHAR)
        return (-2);
    if (str[0] == DIRECT_CHAR)
        return (my_atoi(str += 1));
    if (str[0] == LABEL_CHAR)
        return (-2);
    if (str[0] == '-')
        return (my_atoi(str));
    write_error("Value instruction not found");
    return (84);
}

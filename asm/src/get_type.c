/*
** EPITECH PROJECT, 2018
** get_type
** File description:
** get_type
*/

#include "asm.h"
#include "op.h"

int *get_type(char *str)
{
    if (check_label(str) == 1) {
        for (; str[0] != LABEL_CHAR; str++);
        str++;
        for (; str[0] && str[0] == ' '; str++);
        return (get_params_nbr(get_params_type(str)));
    } else
        return (get_params_nbr(get_params_type(str)));
}

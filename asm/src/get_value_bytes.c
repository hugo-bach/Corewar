/*
** EPITECH PROJECT, 2018
** get_value_bytes
** File description:
** get_value_bytes
*/

#include "asm.h"
#include "op.h"

static int get_value_bytes_next(char *str, int end_by_i)
{
    if (str[0] == DIRECT_CHAR)
        return (get_value_direct_char(str, end_by_i));
    if (str[0] == LABEL_CHAR)
        return (get_value_label(str));
    if (str[0] == '-')
        return (IND_SIZE);
    write_error("Value bytes not found");
    return (84);
}

int get_value_bytes(char *str, int end_by_i)
{
    if (str[0] > 47 && str[0] < 58)
        return (get_value_number(str));
    if (str[0] == 'r')
        return (get_value_registre(str));
    if (str[0] == DIRECT_CHAR && str[1] == LABEL_CHAR)
        return (get_value_offset(str, end_by_i));
    return (get_value_bytes_next(str, end_by_i));
}

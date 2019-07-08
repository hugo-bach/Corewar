/*
** EPITECH PROJECT, 2018
** value_bytes_tools
** File description:
** value_bytes_tools
*/

#include "asm.h"
#include "op.h"

int get_value_registre(char *str)
{
    int value = my_atoi(str += 1);

    for (int i = 1; str[i] != '\0'; i++)
        if (!(str[i] > 47 && str[i] < 58))
            write_error("Registre problem");
    if (value > REG_NUMBER)
        write_error("Registre Number problem");
    return (T_REG);
}

int get_value_number(char *str)
{
    for (int i = 1; str[i] != '\0'; i++)
        if (!(str[i] > 47 && str[i] < 58) && str[i] != ' ')
            write_error("Indirect number problem");
    return (IND_SIZE);
}

int get_value_offset(char *str, int end_by_i)
{
    if (is_in_labels(str += 2) == 0)
        write_error("Offset problem");
    for (int i = 2; str[i] != '\0'; i++)
        if (is_a_label_chars(str[i]) == 0)
            write_error("Offset problem");
    if (end_by_i == 1)
        return (IND_SIZE);
    return (DIR_SIZE);
}

int get_value_direct_char(char *str, int end_by_i)
{
    for (int i = 1; str[i] != '\0'; i++)
        if ((str[i] < 48 || str[i] > 57) && str[i] != '-')
            write_error("Direct number problem");
    if (end_by_i == 1)
        return (IND_SIZE);
    return (DIR_SIZE);
}

int get_value_label(char *str)
{
    if (is_in_labels(str += 1) == 0)
        write_error("Offset problem");
    return (IND_SIZE);
}

/*
** EPITECH PROJECT, 2018
** skip_tools
** File description:
** skip_tools
*/

#include "asm.h"

char *skip_label(char *str)
{
    if (check_label(str) == 1) {
        for (; str[0] != LABEL_CHAR; str++);
        str++;
    }
    return (str);
}

char *skip_space(char *str)
{
    for (; str[0] == ' '; str++);
    for (; str[0] != ' '; str++);
    for (; str[0] == ' '; str++);
    return (str);
}

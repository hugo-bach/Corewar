/*
** EPITECH PROJECT, 2018
** it_end_by_i
** File description:
** it_end_by_i
*/

#include "corewar.h"

int is_special(char *str)
{
    int i = 0;

    if (str[0] == ' ')
        for (; str[i] && str[i] == ' '; i++);
    if (str[i] == 'z' && str[i + 1] == 'j' && str[i + 2] == 'm' &&
        str[i + 3] == 'p')
        return (2);
    if (str[i] == 'f' && str[i + 1] == 'o' && str[i + 2] == 'r' &&
        str[i + 3] == 'k')
        return (2);
    if (str[i] == 'l' && str[i + 1] == 'f' && str[i + 2] == 'o' &&
        str[i + 3] == 'r' && str[i + 4] == 'k')
        return (2);
    for (; str[i] && str[i + 1] != '\0'; i++);
    if (str[i] == 'i')
        return (1);
    return (0);
}

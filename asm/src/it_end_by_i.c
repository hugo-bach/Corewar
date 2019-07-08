/*
** EPITECH PROJECT, 2018
** it_end_by_i
** File description:
** it_end_by_i
*/

#include "asm.h"

int it_end_by_i(char *str)
{
    int i = 0;
    char *instruction[4] = {"zjmp", "fork", "lfork", NULL};

    for (int j = 0; instruction[j]; j++)
        if (instruction_is_present(str, instruction[j]) == 1)
            return (1);
    for (; str[i] && str[i] == ' '; i++);
    for (; str[i] && str[i + 1] != ' '; i++);
    if (str[i] == 'i')
        return (1);
    return (0);
}

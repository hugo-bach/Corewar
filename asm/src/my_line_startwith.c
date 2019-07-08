/*
** EPITECH PROJECT, 2018
** my_arg_startwith.c
** File description:
** function my_arg_startwith of project asm
*/

#include "asm.h"

int my_line_startwith(char *arg, char *start)
{
    int len_start = my_strlen(start);
    int len_arg = my_strlen(arg);
    int i = 0;

    if (arg == NULL)
        return 0;
    if (len_start >= len_arg)
        return 0;
    while (start[i] == arg[i] && (start[i] != '\0' && arg[i] != '\0'))
        i++;
    if (i == len_start)
        return 1;
    return 0;
}
/*
** EPITECH PROJECT, 2018
** name
** File description:
** strlen function
*/

#include "asm.h"

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    for (; str[i]; i++);
    return (i);
}

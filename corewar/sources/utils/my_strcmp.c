/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_strcmp
*/

#include "corewar.h"

int my_strcmp(char *str, char *src)
{
    if (my_strlen(str) != my_strlen(src))
        return (0);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != src[i])
            return (0);
    return (1);
}
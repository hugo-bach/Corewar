/*
** EPITECH PROJECT, 2018
** name
** File description:
** strdup function
*/

#include "asm.h"

char *my_strdup(char *str)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    if (result == NULL)
        return (NULL);
    for (; str[i]; i++)
        result[i] = str[i];
    result[i] = '\0';
    return (result);
}

/*
** EPITECH PROJECT, 2018
** name_core.c
** File description:
** fct who return a name with .core
*/

#include "asm.h"

char *name_core(char *name)
{
    char *result = NULL;

    name[my_strlen(name) - 1] = '\0';
    result = my_strcat(name, "cor");
    return (result);
}

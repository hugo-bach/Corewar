/*
** EPITECH PROJECT, 2018
** singleton_label.c
** File description:
** singleton label
*/

#include "asm.h"

char **my_macro_label(char **str)
{
    static char **label = NULL;

    if (str != NULL)
        label = create_label(str);
    return (label);
}

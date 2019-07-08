/*
** EPITECH PROJECT, 2018
** endswith.c
** File description:
** fct endswith who check the end of the string
*/

#include "asm.h"

int endswith(char *str, char *end)
{
    int word1 = my_strlen(str);
    int word2 = my_strlen(end);

    if (word1 <= word2)
        return (-1);
    for (int i = word1 - word2, j = 0; end[j]; i++, j++)
        if (str[i] != end[j])
            return (-1);
    return (1);
}

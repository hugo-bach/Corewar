/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** fct who concat two string
*/

#include "asm.h"

char *my_strcat(char *str1, char *str2)
{
    int nb = my_strlen(str1) + my_strlen(str2) + 1;
    char *result = malloc(sizeof(char) * nb);

    for (nb = 0; str1[nb]; nb++)
        result[nb] = str1[nb];
    for (int i = 0; str2[i]; i++, nb++)
        result[nb] = str2[i];
    result[nb] = '\0';
    return (result);
}

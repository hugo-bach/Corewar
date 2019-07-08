/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function of the corewar
*/

#include "corewar.h"

int my_strlen(char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    return i;
}
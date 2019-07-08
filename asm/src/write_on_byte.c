/*
** EPITECH PROJECT, 2018
** write_on_byte.c
** File description:
** fct who write on byte
*/

#include "asm.h"

void write_byte(int *tab)
{
    for (int i = 0; tab[i] != -1; i++)
        if (tab[i] == -2)
            tab[i] = 0;
}

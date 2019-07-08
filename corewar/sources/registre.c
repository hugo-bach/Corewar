/*
** EPITECH PROJECT, 2018
** registre.c
** File description:
** registre function of the corewar
*/

#include "corewar.h"

static unsigned int *my_calloc_uint(int size)
{
    unsigned int *res = malloc(sizeof(unsigned int) * size);

    for (int i = 0; i < size; i++)
        res[i] = 0;
    return (res);
}

unsigned int *set_registre(int nb)
{
    unsigned int *registre = my_calloc_uint(sizeof(int) * (REG_NUMBER+1));

    for (int i = 0; i < REG_NUMBER; i++)
        registre[i] = 0;
    registre[1] = nb;
    return registre;
}
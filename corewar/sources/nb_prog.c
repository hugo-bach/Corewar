/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function of the corewar
*/

#include "corewar.h"

int nb_prog(char **av)
{
    int nb = 0;

    for (int i = 0; av[i] != NULL; i++)
        nb = (my_str_endwith(av[i], ".cor") == 1) ? nb + 1: nb;
    return nb;
}
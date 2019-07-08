/*
** EPITECH PROJECT, 2018
** pc_sorting.c
** File description:
** pc_sorting function of the corewar
*/

#include "corewar.h"

static void sorter(prog_t **prog, int j)
{
    prog_t *tmp = NULL;

    if (prog[j]->pc < prog[j + 1]->pc) {
        tmp = prog[j];
        prog[j] = prog[j + 1];
        prog[j + 1] = tmp;
    }
    return;
}

void prog_sort(prog_t **prog)
{
    for (int i = nb_on_start(0); i < nb_of_programs(0); i++)
        for (int j = nb_on_start(0); j < nb_of_programs(0) - 1; j++)
            sorter(prog, j);
    return;
}
/*
** EPITECH PROJECT, 2018
** calc_prog_size.c
** File description:
** fct who calc the prog size of the prog
*/

#include "asm.h"

int size_instruct(instr_t *list)
{
    int nb = 0;

    if (list->instr != -1)
        nb++;
    for (int i = 0; list->type[i] != -1; nb++, i++);
    for (int i = 0; list->params[i] != -1; nb++, i++);
    return (nb);
}

void calc_prog(instr_t **list, header_t *test)
{
    int nb = 0;

    for (int i = 0; list[i]; i++)
        nb += size_instruct(list[i]);
    test->prog_size = nb;
}

/*
** EPITECH PROJECT, 2018
** name
** File description:
** transform values function
*/

#include "corewar.h"

void transform_values(int *values, int *memory, prog_t *prog, int nb)
{
    (void) memory;

    for (int i = 0; prog[nb].instruction->params[i] != '\0'; i++) {
        if (prog[nb].instruction->params[i] == 'r')
            values[i] = prog[nb].registre[values[i]];
    }
}

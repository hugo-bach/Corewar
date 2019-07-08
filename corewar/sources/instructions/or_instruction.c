/*
** EPITECH PROJECT, 2018
** name
** File description:
** or instruction
*/

#include "corewar.h"

static void launch_or(prog_t **prog, int i, int *values)
{
    int nb_a = 0;
    int nb_b = 0;

    if (prog[i]->instruction->params[0] == 'r')
        nb_a = prog[i]->registre[values[0]];
    else
        nb_a = values[0];
    if (prog[i]->instruction->params[1] == 'r')
        nb_a = prog[i]->registre[values[1]];
    else
        nb_a = values[1];
    prog[i]->registre[values[2]] = (nb_a | nb_b);
    free(values);
}

void or_instruction(__attribute__((unused)) int *memory, prog_t **prog, int i)
{
    int *values;

    values = get_params_value(prog[i]->instruction->inst,
    prog[i]->instruction->params);
    if (!(values[0] >= 1 && values[0] <= 16) ||
    !(values[1] >= 1 && values[1] <= 16)) {
        prog[i]->carry_flag = 1;
        free(values);
        return;
    }
    launch_or(prog, i, values);
}

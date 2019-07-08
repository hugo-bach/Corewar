/*
** EPITECH PROJECT, 2018
** name
** File description:
** and instruction
*/

#include "corewar.h"

static int launch_and(prog_t **prog, int i, int *values)
{
    unsigned int nb_a = 0;
    unsigned int nb_b = 0;

    nb_a = (prog[i]->instruction->params[0] == 'r') ?
    (int) prog[i]->registre[values[0]] : values[0];
    nb_b = (prog[i]->instruction->params[1] == 'r') ?
    (int) prog[i]->registre[values[1]] : values[1];
    if (!(values[1] >= 1 && values[1] <= 16) ||
    !(values[2] >= 1 && values[2] <= 16)) {
        free(values);
        return (-1);
    }
    prog[i]->registre[values[2]] = (nb_a & nb_b);
    prog[i]->carry_flag = 1;
    free(values);
    return (0);
}

void and_instruction(__attribute__((unused)) int *memory, prog_t **prog, int i)
{
    int *values;

    values = get_params_value(prog[i]->instruction->inst,
    prog[i]->instruction->params);
    if (!(values[0] >= 1 && values[0] <= 16) ||
    !(values[1] >= 1 && values[1] <= 16)) {
        free(values);
        prog[i]->carry_flag = 1;
        return;
    }
    if (launch_and(prog, i, values) == -1) {
        prog[i]->carry_flag = 1;
        return;
    }
}

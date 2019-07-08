/*
** EPITECH PROJECT, 2018
** name
** File description:
** add_instruction
*/

#include "corewar.h"

static int add_error(prog_t **prog, int i, int *values)
{
    if (my_strlen(prog[i]->instruction->params) != 3) {
        free(values);
        prog[i]->carry_flag = 1;
        return (-1);
    }
    if (prog[i]->instruction->params[0] == 0 ||
    prog[i]->instruction->params[1] == 0 ||
    prog[i]->instruction->params[1] == 0) {
        free(values);
        prog[i]->carry_flag = 1;
        return (-1);
    }
    if (!(values[0] >= 1 && values[0] <= 16) ||
    !(values[1] >= 1 && values[1] <= 16) ||
    !(values[2] >= 1 && values[2] <= 16)) {
        free(values);
        prog[i]->carry_flag = 1;
        return (-1);
    }
    return (0);
}

void add_instruction(__attribute__((unused)) int *memory, prog_t **prog, int i)
{
    int *values;
    int sum = 0;

    values = get_params_value(prog[i]->instruction->inst,
    prog[i]->instruction->params);
    if (add_error(prog, i, values) == -1)
        return;
    sum = prog[i]->registre[values[0]] + prog[i]->registre[values[1]];
    prog[i]->registre[values[2]] = sum;
    prog[i]->carry_flag = 1;
    free(values);
}

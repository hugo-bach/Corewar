/*
** EPITECH PROJECT, 2018
** name
** File description:
** sub instrcution
*/

#include "corewar.h"

void sub_instruction(__attribute__((unused)) int *memory, prog_t **prog, int i)
{
    int *values;
    int sub = 0;

    values = get_params_value(prog[i]->instruction->inst,
    prog[i]->instruction->params);
    if (values[0] < 1 || values[0] > 16 || values[1] < 1 || values[1] > 16 ||
    values[2] < 1 || values[2] > 16) {
        prog[i]->carry_flag = 1;
        free(values);
        return;
    }
    sub = prog[i]->registre[values[0]] - prog[i]->registre[values[1]];
    prog[i]->registre[values[2]] = sub;
    prog[i]->carry_flag = 1;
    free(values);
}

/*
** EPITECH PROJECT, 2018
** name
** File description:
** ld instruction
*/

#include "corewar.h"

void lld_instruction(int *memory, prog_t **prog, int i)
{
    int *values;

    values = get_params_value(prog[i]->instruction->inst,
    prog[i]->instruction->params);
    if (my_strlen(prog[i]->instruction->params) != 2) {
        free(values);
        prog[i]->carry_flag = 1;
        return;
    }
    if (!(values[1] >= 1 && values[1] <= 16)) {
        free(values);
        prog[i]->carry_flag = 1;
        return;
    }
    prog[i]->registre[values[1]] = get_mem_special_value(memory,
    prog[i]->pc + values[0], 4);
    prog[i]->carry_flag = 1;
    free(values);
}

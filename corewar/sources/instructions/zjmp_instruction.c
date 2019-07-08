/*
** EPITECH PROJECT, 2018
** name
** File description:
** zjmp instruction
*/

#include "corewar.h"

void zjmp_instruction(__attribute__((unused)) int *memory, prog_t **prog, int i)
{
    int *values;

    values = get_params_value(prog[i]->instruction->inst,
    prog[i]->instruction->params);
    if ((prog[i]->pc + (values[0] % IDX_MOD)) < 0) {
        prog[i]->pc = (MEM_SIZE + (prog[i]->pc + (values[0] % IDX_MOD)))
        % MEM_SIZE;
    }
    else
        prog[i]->pc = ((prog[i]->pc + (values[0] % IDX_MOD))) % MEM_SIZE;
    prog[i]->carry_flag = 0;
    free(values);
}

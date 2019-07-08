/*
** EPITECH PROJECT, 2018
** name
** File description:
** 
*/

#include "corewar.h"

static void launch_st(int *memory, prog_t **prog, int i, int *values)
{
    if (prog[i]->registre[values[0]] == 0)
        prog[i]->registre[values[0]] = 0;
    if (prog[i]->pc + (values[1] % IDX_MOD) < 0)
        load_memvalue(memory , MEM_SIZE + (prog[i]->pc + (values[1] % IDX_MOD)),
        (int) prog[i]->registre[values[0]], prog[i]->number);
    else
        load_memvalue(memory , (prog[i]->pc + (values[1] % IDX_MOD)) % MEM_SIZE,
        (int) prog[i]->registre[values[0]], prog[i]->number);
    prog[i]->carry_flag = 1;
}

static int st_error(prog_t **prog, int i, int *values)
{
    if (!(values[0] >= 1 && values[0] <= 16)) {
        prog[i]->carry_flag = 1;
        free(values);
        return (-1);
    }
    if (prog[i]->instruction->params[1] == 0) {
        prog[i]->carry_flag = 1;
        free(values);
        return (-1);
    }
    return (0);
}

void st_instruction(int *memory, prog_t **prog, int i)
{
    int *values;

    values = get_params_value(prog[i]->instruction->inst,
    prog[i]->instruction->params);
    if (st_error(prog, i, values) == -1)
        return;
    if (prog[i]->instruction->params[1] == 'r') {
        if (!(values[1] >= 1 && values[1] <= 16)) {
            prog[i]->carry_flag = 1;
            free(values);
            return;
        }
        values[1] = prog[i]->registre[values[1]];
    }
    launch_st(memory, prog, i, values);
    free(values);
}

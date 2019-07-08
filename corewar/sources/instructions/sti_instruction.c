/*
** EPITECH PROJECT, 2018
** name
** File description:
** sti instruction
*/

#include "corewar.h"

static int sti_error(prog_t **prog, int i, int *values)
{
    if (prog[i]->instruction->params[1] == 'r') {
        if (!(values[1] >= 1 && values[1] <= 16)) {
            prog[i]->carry_flag = 1;
            return (-1);
        }
        values[1] = prog[i]->registre[values[1]];
    }
    if (prog[i]->instruction->params[2] == 'r') {
        if (!(values[2] >= 1 && values[2] <= 16)) {
            prog[i]->carry_flag = 1;
            return (-1);
        }
        values[2] = prog[i]->registre[values[2]];
    }
    if (!(values[0] >= 1 && values[0] <= 16)) {
        prog[i]->carry_flag = 1;
        return (-1);
    }
    return (0);
}

static void launch_sti(int *memory, prog_t **prog, int i, int *values)
{
    if (sti_error(prog, i, values) == -1) {
        prog[i]->carry_flag = 1;
        free(values);
        return;
    }
    if (prog[i]->pc + (values[1] + values[2]) % IDX_MOD < 0)
        load_memvalue(memory , MEM_SIZE + (prog[i]->pc +
        (values[1] + values[2]) % IDX_MOD) % MEM_SIZE,
        (int) prog[i]->registre[values[0]], prog[i]->number);
    else
        load_memvalue(memory , (prog[i]->pc + (values[1] + values[2])
        % IDX_MOD) % MEM_SIZE, (int) prog[i]->registre[values[0]],
        prog[i]->number);
    free(values);
}

void sti_instruction(int *memory, prog_t **prog, int i)
{
    int *values;
    char *params = prog[i]->instruction->params;
    int size = 0;

    values = get_params_value(prog[i]->instruction->inst,
    prog[i]->instruction->params);
    for (; values[size] != -1; size ++);
    if (size != 3) {
        prog[i]->carry_flag = 1;
        free(values);
        return;
    }
    if (params[1] == 0 || params[2] == 0 ||params[2] == 0) {
        prog[i]->carry_flag = 1;
        free(values);
        return;
    }
    launch_sti(memory, prog, i, values);
    prog[i]->carry_flag = 1;
}

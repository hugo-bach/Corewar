/*
** EPITECH PROJECT, 2018
** name
** File description:
** launch instruction f
*/

#include "corewar.h"

static prog_t *fork_dup(prog_t *model)
{
    prog_t *copy;
    copy = malloc(sizeof(prog_t));
    copy->name = model->name;
    copy->prog_name = my_strdup(model->prog_name);
    copy->comment = my_strdup(model->comment);
    copy->header = int_array_cpy(model->header);
    copy->core = int_array_cpy(model->core);
    copy->prog_size = model->prog_size;
    copy->number = model->number;
    copy->pc = model->pc;
    copy->live = model->live;
    copy->registre = registre_dup(model->registre);
    copy->dead = false;
    copy->address = model->address;
    copy->carry_flag = model->carry_flag;
    copy->instruction = malloc(sizeof(instruction_t));
    return copy;
}

void write_fork(prog_t *prog, int *memory)
{
    int count = 0;

    for (int j = prog->address; prog->core[count] != -1; j++) {
        if (j >= MEM_SIZE)
            j = j % MEM_SIZE;
        memory[j] = prog->core[count];
        count++;
    }
    return;
}

prog_t **struct_append(prog_t **prog, prog_t *new)
{
    prog_t **new_list;
    int i = 0;
    int new_nb = nb_of_programs(0);

    new_list = malloc(sizeof(prog_t *) * (nb_of_programs(0) + 2));
    for (i = 0; i < nb_of_programs(0); i++)
        new_list[i] = prog[i];
    new_list[i] = new;
    free(prog);
    new_nb = nb_of_programs(new_nb + 1);
    return new_list;
}

prog_t **fork_instruction(int *memory, prog_t **prog, int i)
{
    int *values;
    prog_t *new_prog;
    (void)memory;

    values = get_params_value(prog[i]->instruction->inst,
    prog[i]->instruction->params);
    new_prog = fork_dup(prog[i]);
    free(new_prog->instruction);
    if ((prog[i]->pc + (values[0] % IDX_MOD)) < 0)
        new_prog->address = (MEM_SIZE + (prog[i]->pc + (values[0] % IDX_MOD))
        % MEM_SIZE);
    else
        new_prog->address = ((prog[i]->pc + (values[0] % IDX_MOD)) % MEM_SIZE);
    new_prog->pc = (new_prog->address + 3) % MEM_SIZE;
    new_prog->instruction = NULL;
    prog = struct_append(prog, new_prog);
    free(values);
    return prog;
}

prog_t **lfork_instruction(int *memory, prog_t **prog, int i)
{
    int *values;
    prog_t *new_prog;
    (void)memory;

    values = get_params_value(prog[i]->instruction->inst,
    prog[i]->instruction->params);
    new_prog = fork_dup(prog[i]);
    free(new_prog->instruction);
    if ((prog[i]->pc + (values[0] % IDX_MOD)) < 0)
        new_prog->address = (MEM_SIZE + (prog[i]->pc + (values[0]))
        % MEM_SIZE);
    else
        new_prog->address = ((prog[i]->pc + (values[0])) % MEM_SIZE);
    new_prog->pc = (new_prog->address + 3) % MEM_SIZE;
    new_prog->instruction = NULL;
    prog = struct_append(prog, new_prog);
    free(values);
    return prog;
}

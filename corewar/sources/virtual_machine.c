/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function of the corewar
*/

#include "corewar.h"

static void update_inst(instruction_t *inst, int cursor, int *mem)
{
    for (int i = 0; inst->inst[i] != -1; i++)
        inst->inst[i] = mem[cursor + i];
}

prog_t **do_instruction(int *memory, prog_t **prog, int i, int *live_count)
{
    if (prog[i]->instruction == NULL)
        prog[i]->instruction = create_instruction(memory, prog[i]->pc);
    if (prog[i]->instruction->nb_cycle == prog[i]->instruction->cycle) {
        *live_count = (prog[i]->instruction->inst[0] == 1) ?
        *live_count + 1 : *live_count;
        update_inst(prog[i]->instruction, prog[i]->pc, memory);
        prog = launch_instruction(memory, prog, i);
        prog[i]->pc = (prog[i]->pc + prog[i]->instruction->size) % MEM_SIZE;
        free_instruction(prog[i]);
        prog[i]->instruction = create_instruction(memory, prog[i]->pc);
    }
    if (prog[i]->instruction->inst[0] == -1) {
        prog[i]->pc = (prog[i]->pc + 1) % MEM_SIZE;
        free_instruction(prog[i]);
        prog[i]->instruction = create_instruction(memory, prog[i]->pc);
        return prog;
    }
    prog[i]->instruction->nb_cycle += 1;
    return prog;
}

prog_t **load_instruction(int *memory, prog_t **prog, int *count)
{
    prog_sort(prog);
    for (int i = 0; i < nb_of_programs(0); i++)
        if (prog[i]->dead != true)
            prog = do_instruction(memory, prog, i, count);
    return prog;
}

prog_t **virtual_machine(prog_t **prog_list, int *memory, int dump)
{
    int to_die = CYCLE_TO_DIE;
    int cycle = 0;
    int live_count = 0;
    bool win = false;

    struct_sorter(prog_list);
    while (win == false) {
        prog_list = load_instruction(memory, prog_list, &live_count);
        launch_dump(cycle, dump, memory);
        if (to_die < CYCLE_DELTA)
            win = forced_win(prog_list, cycle);
        else if (cycle % to_die == 0 && cycle != 0)
            win = reset_live(prog_list, cycle);
        if (live_count > NBR_LIVE && live_count != 0) {
            to_die = to_die - CYCLE_DELTA;
            live_count = 0;
        }
        display_ncurse(prog_list, memory, cycle, live_count, to_die);
        cycle++;
    }
    return prog_list;
}

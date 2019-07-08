/*
** EPITECH PROJECT, 2018
** name
** File description:
** launch instruction f
*/

#include "corewar.h"

static prog_t **launch_other(int *memory, prog_t **prog, int i)
{
    if (prog[i]->instruction->inst[0] == 13)
        lld_instruction(memory, prog, i);
    if (prog[i]->instruction->inst[0] == 4)
        add_instruction(memory, prog, i);
    if (prog[i]->instruction->inst[0] == 5)
        sub_instruction(memory, prog, i);
    if (prog[i]->instruction->inst[0] == 6)
        and_instruction(memory, prog, i);
    if (prog[i]->instruction->inst[0] == 7)
        or_instruction(memory, prog, i);
    if (prog[i]->instruction->inst[0] == 8)
        xor_instruction(memory, prog, i);
    if (prog[i]->instruction->inst[0] == 12)
        prog = fork_instruction(memory, prog, i);
    if (prog[i]->instruction->inst[0] == 14)
        prog = lfork_instruction(memory, prog, i);
    return prog;
}

prog_t **launch_instruction(int *memory, prog_t **prog, int i)
{
    if (prog[i]->instruction->inst[0] == 1)
        live_instruction(memory, prog, i);
    if (prog[i]->instruction->inst[0] == 2)
        ld_instruction(memory, prog, i);
    if (prog[i]->instruction->inst[0] == 11)
        sti_instruction(memory, prog, i);
    if (prog[i]->instruction->inst[0] == 9 && prog[i]->carry_flag == 1)
        zjmp_instruction(memory, prog, i);
    if (prog[i]->instruction->inst[0] == 3)
        st_instruction(memory, prog, i);
    if (prog[i]->instruction->inst[0] == 10)
        ldi_instruction(memory, prog, i);
    if (prog[i]->instruction->inst[0] == 13)
        lldi_instruction(memory, prog, i);
    if (prog[i]->instruction->inst[0] == 15)
        aff_instruction(memory, prog, i);
    prog = launch_other(memory, prog, i);
    return prog;
}

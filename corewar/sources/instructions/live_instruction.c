/*
** EPITECH PROJECT, 2018
** name
** File description:
** live instruction
*/

#include "corewar.h"

void live_instruction(int *memory, prog_t **prog, int i)
{
    for (int j = 0; j < nb_of_programs(0); j++) {
        if (prog[j]->number == get_memvalue(memory, prog[i]->pc + 1)) {
            prog[j]->live = get_memvalue(memory, prog[i]->pc + 1);
            last_alive(prog[j]->live);
        }
    }
    prog[i]->carry_flag = 1;
}

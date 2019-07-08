/*
** EPITECH PROJECT, 2018
** free_mem.c
** File description:
** free memory
*/

#include "corewar.h"

void free_instruction(prog_t *prog)
{
    if (prog->instruction != NULL) {
        if (prog->instruction->inst != NULL)
            free(prog->instruction->inst);
        if (prog->instruction->params != NULL)
            free(prog->instruction->params);
        free(prog->instruction);
    }
}

void free_struct(prog_t *prog)
{
    free(prog->prog_name);
    free(prog->comment);
    free(prog->header);
    free(prog->core);
    free(prog->registre);
    free_instruction(prog);
}

void free_all(prog_t **prog_list)
{
    for (int i = 0; i < nb_of_programs(0); i++) {
        free_struct(prog_list[i]);
        free(prog_list[i]);
    }
    free(prog_list);
    free(prog_nbr());
}

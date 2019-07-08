/*
** EPITECH PROJECT, 2018
** name
** File description:
** aff instruction
*/

#include "corewar.h"

void aff_instruction(__attribute__((unused)) int *memory, prog_t **prog, int i)
{
    int *values = NULL;
    int character = 0;

    return;
    values = get_params_value(prog[i]->instruction->inst,
    prog[i]->instruction->params);
    if (!(values[0] >= 1 && values[0] <= 16)) {
        free(values);
        prog[i]->carry_flag = 1;
        return;
    }
    character = prog[i]->registre[values[0]] % 256;
    if (character >= '!' && character <= '~') {
        write(1, "'", 1);
        write(1, &character, 1);
        write(1, "'\n", 2);
    } else
        write(1, "aff: can't print :(\n", 20);
    prog[i]->carry_flag = 1;
    free(values);
}

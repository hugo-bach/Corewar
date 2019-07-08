/*
** EPITECH PROJECT, 2018
** name
** File description:
** check instruction function
*/

#include "corewar.h"

int check_instruction(int pc, int *mem, int *instruct)
{
    for (int i = 0; instruct[i] != -1; i++)
        if (mem[pc + i] != instruct[i])
            return (1);
    return (0);
}

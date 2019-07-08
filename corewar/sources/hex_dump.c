/*
** EPITECH PROJECT, 2018
** hex_dump.c
** File description:
** hex_dump function of the corewar
*/

#include "corewar.h"

char ***hex_dump(int *memory)
{
    int count = 0;
    char ***dump = malloc(sizeof(char ***) * (MEM_SIZE/32));

    for (int i = 0; i < MEM_SIZE/32; i++) {
        dump[i] = malloc(sizeof(char *) * 32);
        for (int j = 0; j < 32; j++) {
            dump[i][j] = int_to_base(memory[count], 16);
            count++;
        }
    }
    return dump;
}

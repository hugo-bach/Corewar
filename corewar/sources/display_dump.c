/*
** EPITECH PROJECT, 2018
** display_dump.c
** File description:
** display_dump function of the corewar
*/

#include "corewar.h"

static void display_line(char ***dump, int i)
{
    for (int j = 0; j < 32; j++) {
        if (my_strcmp(dump[i][j], "00") != 1) {
            write(1, "\033[91m", 5);
            my_putstr(dump[i][j]);
            write(1, "\033[0m", 4);
        }
        else
            my_putstr(dump[i][j]);
        (j == 31) ? (void)0 : my_putstr(" ");
    }
}

static void display_dump(char ***dump)
{
    for (int i = 0; i < MEM_SIZE/32; i++) {
        my_putstr("0x");
        my_putstr(int_to_base(i+1, 16));
        my_putstr("\t");
        display_line(dump, i);
        my_putstr("\n");
    }
}

void launch_dump(int cycle, int dump, int *memory)
{
    if (cycle == dump && dump != 0) {
        display_dump(hex_dump(memory));
        exit(0);
    }
    return;
}
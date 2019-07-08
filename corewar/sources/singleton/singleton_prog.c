/*
** EPITECH PROJECT, 2018
** singleton_prog.c
** File description:
** singleton fct who write the prog number of each instruction
*/

#include "corewar.h"

int nb_on_start(int nb)
{
    static int nb_on_start;

    if (nb != 0)
        nb_on_start = nb;
    return nb_on_start;
}

int nb_of_programs(int nb)
{
    static int nb_of_prog;

    if (nb != 0)
        nb_of_prog = nb;
    return nb_of_prog;
}

int last_alive(int alive)
{
    static int last = 0;

    if (alive != -1)
        last = alive;
    return last;
}

int my_macro_fd(char *str)
{
    static int fd;

    if (str != NULL)
        fd = open(str, O_RDWR);
    if (fd == -1)
        write_error("impossible de lire le fichier.");
    return (fd);
}

int *prog_nbr(void)
{
    static int start = 0;
    static int *prog;

    if (start == 0) {
        prog = malloc(sizeof(int) * (MEM_SIZE + 1));
        start++;
        for (int i = 0; i != MEM_SIZE; i++)
            prog[i] = 0;
        prog[MEM_SIZE] = -1;
    }
    return (prog);
}

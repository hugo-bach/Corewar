/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function of the corewar
*/

#include "corewar.h"

void set_memory_to_null(int *memory)
{
    int i = 0;

    for (i = 0; i < MEM_SIZE; i++)
        memory[i] = 0;
    memory[i] = -1;
    return;
}

void write_core(prog_t **prog, int index, int *memory)
{
    int count = 0;
    int *prog_nb = prog_nbr();

    if (prog[index]->prog_size > 1024)
        write_error("prog size can't exceed 1024 bytes.");
    for (int j = prog[index]->address; prog[index]->core[count] != -1; j++) {
        if (j >= MEM_SIZE)
            j = j % MEM_SIZE;
        if (memory[j] != 0)
            write_error("a program try to overwrite an other.");
        memory[j] = prog[index]->core[count];
        prog_nb[j] = prog[index]->number;
        count++;
    }
    return;
}

int main(int __attribute__((unused)) ac, char *av[])
{
    int memory[MEM_SIZE + 1];
    prog_t **prog_tab = malloc(sizeof(prog_t *) * (nb_prog(av) + 2));
    int dump = find_dump(av);

    nb_of_programs(nb_prog(av));
    nb_on_start(nb_prog(av));
    fill_params(prog_tab, nb_prog(av), av);
    set_memory_to_null(memory);
    for (int i = 0; i < nb_prog(av); i++)
        write_core(prog_tab, i, memory);
    prog_tab = virtual_machine(prog_tab, memory, dump);
    free_all(prog_tab);
    endwin();
    return 0;
}

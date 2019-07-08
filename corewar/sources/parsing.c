/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** parsing function of the corewar
*/

#include "corewar.h"

void arg_checking(char **av)
{
    for (int i = 0; av[i] != NULL; i++) {
        (my_strcmp(av[i], "-h") == 1) ? display_help(0) : (void)0;
        if (av[i+1] == NULL &&
        (my_strcmp(av[i], "-a") == 1 || my_strcmp(av[i], "-n") == 1))
            write_error("Invalid parameters.");
    }
    if (nb_prog(av) == 0)
        write_error("There is no valid Champion.");
    return;
}

void check_number_values(int *numbers)
{
    for (int i = 0; i < nb_of_programs(0); i++)
        for (int j = i + 1; j < nb_of_programs(0); j++)
            (numbers[i] == numbers[j]) ?
            write_error("Champion must have different prog number.") : (void)0;
    return;
}

void module_address(int *address, int nb)
{
    for (int i = 0; i < nb; i++)
        if (address[i] > MEM_SIZE)
            address[i] = address[i] % MEM_SIZE;
    return;
}

void fill_structure(prog_t **prog_list, int i, char **av)
{
    prog_list[i]->name = name_finder(av);
    prog_list[i]->header = get_header(my_macro_fd(prog_list[i]->name));
    prog_list[i]->prog_size = 0;
    prog_list[i]->core = get_prog(my_macro_fd(NULL), prog_list[i]->header,
    &prog_list[i]->prog_size);
    prog_list[i]->prog_name = get_prog_name(prog_list[i]->header);
    prog_list[i]->comment = get_prog_comment(prog_list[i]->header);
    prog_list[i]->registre = set_registre(prog_list[i]->number);
    prog_list[i]->pc = prog_list[i]->address;
    prog_list[i]->carry_flag = 0;
    prog_list[i]->dead = false;
    prog_list[i]->live = 0;
    prog_list[i]->instruction = NULL;
    return;
}

void fill_params(prog_t **prog_list, int nb, char **av)
{
    int number[nb];
    int address[nb];

    arg_checking(av);
    fill_address(address, nb);
    find_values(number, av, "-n");
    find_values(address, av, "-a");
    fill_number(number, nb);
    check_number_values(number);
    module_address(address, nb);
    for (int i = 0; i < nb; i++) {
        prog_list[i] = malloc(sizeof(prog_t));
        prog_list[i]->number = number[i];
        prog_list[i]->address = address[i];
        fill_structure(prog_list, i, av);
    }
}

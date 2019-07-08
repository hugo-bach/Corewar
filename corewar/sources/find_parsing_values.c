/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** parsing function of the corewar
*/

#include "corewar.h"

void fill_address(int *address, int nb)
{
    int factor = 0;

    for (int i = 0; i < nb; i++) {
        address[i] = (MEM_SIZE/nb) * factor;
        factor++;
    }
    return;
}

void fill_number(int *numbers, int nb)
{
    int count = 1;

    for (int i = 0; i < nb; i++) {
        if (numbers[i] == -1) {
            count_checker(nb, &count, numbers);
            numbers[i] = count;
        }
    }
}

int get_value(char **av, int index, char *flag)
{
    for (int i = index; i != 0 && my_str_endwith(av[i], ".cor") != 1; i--)
        if (my_strcmp(av[i], flag) == 1) {
            (my_atoi(av[i+1]) == -1) ? display_help(84) : (void)0;
            return my_atoi(av[i+1]);
        }
    return -1;
}

void find_values(int *number, char **av, char *flag)
{
    int index = 0;
    int value = 0;

    for (int i = 0; av[i] != NULL; i++) {
        if (my_str_endwith(av[i], ".cor")) {
            value = get_value(av, i-1, flag);
            (my_strcmp(flag, "-n") == 1 || (value != -1 &&
            my_strcmp(flag, "-a"))) ? number[index] = value : 0;
            index++;
        }
    }
    return;
}
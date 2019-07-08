/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** parsing function of the corewar
*/

#include "corewar.h"

void count_checker(int nb, int *count, int *numbers)
{
    while (number_already_used(nb, *count, numbers) == 1)
        (*count) += 1;
}

char *name_finder(char **av)
{
    static int index = 0;
    int count = 0;
    char *value = NULL;

    for (int i = 0; av[i] != NULL; i++) {
        if (my_str_endwith(av[i], ".cor") == 1) {
            value = (count == index) ? av[i] : NULL;
            count++;
        }
        if (value != NULL) {
            index++;
            break;
        }
    }
    return value;
}

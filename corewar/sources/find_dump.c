/*
** EPITECH PROJECT, 2018
** find_dump.c
** File description:
** find_dump function of the corewar
*/

#include "corewar.h"

static void check_params(char **av)
{
    char *list[5] = {"-dump", "-h", "-a", "-n", NULL};
    int flag = 0;

    for (int i = 1; av[i] != NULL; i++) {
        for (int j = 0; list[j] != NULL; j++)
            flag = (my_strcmp(av[i], list[j]) == 1) ? 1 : flag;
        if (flag == 0 && my_str_endwith(av[i], ".cor") == 1)
            flag = 1;
        if (flag == 0 && my_atoi(av[i]) != -1)
            flag = 1;
        if (flag == 0)
            write_error("invalid parameters.");
        flag = 0;
    }
}

int find_dump(char **av)
{
    int dump = 0;

    check_params(av);
    for (int i = 0; av[i] != NULL; i++) {
        if (my_strcmp(av[i], "-dump") == 1)
            dump = (av[i+1] != NULL) ? my_atoi(av[i+1]) : -1;
        if (dump < 0)
            write_error("invalid value for dump.");
    }
    return dump;
}
/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function of the corewar
*/

#include "corewar.h"

int number_already_used(int nb, int check, int *numbers)
{
    for (int i = 0; i < nb; i++)
        if (numbers[i] == check)
            return 1;
    return 0;
}
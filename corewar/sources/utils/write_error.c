/*
** EPITECH PROJECT, 2018
** write_error.c
** File description:
** fct who print a msg error on stderr and exit 84
*/

#include "corewar.h"

void write_error(char *str)
{
    write(2, "Error : ", 8);
    write(2, str, my_strlen(str));
    write(2, "\n", 1);
    exit(84);
}

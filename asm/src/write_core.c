/*
** EPITECH PROJECT, 2018
** write_core.c
** File description:
** fct who write a int in the file .core
*/

#include "asm.h"

void write_core(int *list)
{
    int fd = my_macro_fd(NULL);

    for (int i = 0; list[i] != -1; i++)
        write(fd, &list[i], 1);
}

void write_core_int(int list)
{
    int fd = my_macro_fd(NULL);

    write(fd, &list, 1);
}

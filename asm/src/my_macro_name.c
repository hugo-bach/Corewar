/*
** EPITECH PROJECT, 2018
** my_macro_name.c
** File description:
** fct who save the first arg of the prog asm
*/

#include "asm.h"

int my_macro_fd(char *str)
{
    static int fd = 0;

    if (str != NULL)
        fd = open(name_core(str), O_CREAT | O_APPEND | O_TRUNC | O_RDWR, 0666);
    if (fd == -1)
        write_error("Impossible de creer un fichier");
    return (fd);
}

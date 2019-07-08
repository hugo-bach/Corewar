/*
** EPITECH PROJECT, 2018
** name
** File description:
** get magic nbr in int *
*/

#include "asm.h"

char *get_parts(char *str, int begin, int end)
{
    char *result = malloc(sizeof(char) * ((end - begin) + 1));
    int count = 0;

    for (int i = begin; i < end; i++)
        result[count++] = str[i];
    result[count] = '\0';
    return (result);
}

int *get_magic_nbr(void)
{
    int magic = COREWAR_EXEC_MAGIC;
    char *magic_str = int_to_base(magic, 16);
    int *result = malloc(sizeof(int) * (my_strlen(magic_str) / 2 + 1));
    int pos = 0;
    int i = 0;

    for (; i < my_strlen(magic_str) / 2; i++, pos += 2)
        result[i] = base_to_int(get_parts(magic_str, pos, pos + 2), 16);
    result[i] = -1;
    return (result);
}

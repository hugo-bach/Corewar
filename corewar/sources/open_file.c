/*
** EPITECH PROJECT, 2018
** name
** File description:
** open file function
*/

#include "corewar.h"

int *get_header(int fd)
{
    int size = PROG_NAME_LENGTH + COMMENT_LENGTH + 8 + 8 + 1;
    char buffer[size];
    int *result = malloc(sizeof(int) * size);

    buffer[0] = 'a';
    read(fd, buffer, size - 1);
    if (buffer[0] == 'a')
        write_error("Invalid .cor file !\n");
    for (int i = 0; i < size - 1; i++)
        if ((int)buffer[i] < 0)
            result[i] = 256 + (int)buffer[i];
        else
            result[i] = (int)buffer[i];
    result[size - 1] = -1;
    return (result);
}

static int power(int nb, int pow)
{
    int result = nb;

    if (pow == 0)
        return (1);
    for (int i = 0; i < pow - 1; i++)
        result *= nb;
    return (result);
}

int *get_prog(int fd, int *header, int *prog_size)
{
    int cursor = 4 + PROG_NAME_LENGTH + 4;
    char *buffer;
    int *result;

    for (int i = 0; i < 4; i++)
        *prog_size = *prog_size + (header[cursor + i] *
        power(256, 4 - (i + 1)));
    buffer = malloc(sizeof(char) * (*prog_size + 1));
    result = malloc(sizeof(int) * (*prog_size + 1));
    read(fd, buffer, *prog_size);
    for (int i = 0; i < *prog_size; i++)
        if ((int)buffer[i] < 0)
            result[i] = 256 + (int)buffer[i];
        else
            result[i] = (int)buffer[i];
    free(buffer);
    result[*prog_size] = -1;
    return (result);
}

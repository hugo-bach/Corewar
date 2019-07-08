/*
** EPITECH PROJECT, 2018
** name.c
** File description:
** function name of project asm
*/

#include "asm.h"
#include "op.h"

int *string_encoder(char *name, int size)
{
    int *values = malloc(sizeof(int) * (size + 1));
    int i = 0;

    for (; name[i] != '\0'; i++)
        values[i] = (int)name[i];
    for (; i < size; i++)
        values[i] = 0;
    values[size] = -1;
    return values;
}

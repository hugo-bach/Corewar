/*
** EPITECH PROJECT, 2018
** name
** File description:
** get value of parameters
*/

#include "corewar.h"

static int get_params_size(char param, int status)
{
    int res = 0;

    switch (param) {
        case 'r':
            return (1);
            break;
        case 'd':
            res = (status == 1) ? 2 : 4;
            return (res);
            break;
        case 'i':
            return (2);
            break;
        default:
            break;
    }
    return (0);
}

static unsigned int power(int nb, int pow)
{
    unsigned result = nb;

    if (pow == 0)
        return (1);
    for (int i = 0; i < pow - 1; i++)
        result *= nb;
    return (result);
}

int get_mem_special_value(int *instruct, int cursor, int size)
{
    unsigned int res = 0;

    for (int i = 0; i < size; i++) {
        if (instruct[cursor + i] == -1)
            break;
        res = res + (instruct[cursor + i] * power(256, size - (i + 1)));
    }
    if (res > ((power(256, size) - 1) / 2))
        res -= (power(256, size));
    return (res);
}

static int get_special_value(int *instruct)
{
    int res = 0;
    int size = 0;

    for (; instruct[size] != -1; size++);
    res = get_mem_special_value(instruct, 1, 2) - size;
    return (res);
}

int *get_params_value(int *instruction, char *params)
{
    int *result = malloc(sizeof(int) * (my_strlen(params) + 1));
    int cursor = 2;
    char *name = get_instruction_name(instruction[0]);
    int size = 0;

    for (int i = 0; i < my_strlen(params) + 1; i++)
        result[i] = -1;
    cursor = (my_strcmp(name, "live")) ? 1 : cursor;
    if (my_strcmp(name, "zjmp") == 1 || my_strcmp(name, "fork") == 1 ||
        my_strcmp(name, "lfork") == 1)
        result[0] = get_special_value(instruction);
    for (int i = 0; params[i] != '\0'; i++, cursor += size) {
        size = get_params_size(params[i], is_special(name));
        size = (my_strcmp(name, "live") == 1) ? 4 : size;
        result[i] = get_mem_special_value(instruction, cursor, size);
    }
    return (result);
}

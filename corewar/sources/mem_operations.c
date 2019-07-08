/*
** EPITECH PROJECT, 2018
** name
** File description:
** get_memvalue function -> get value on REG_SIZE bytes in memory
*/

#include "corewar.h"

static unsigned int power(int nb, int pow)
{
    unsigned int res = nb;

    if (pow == 0)
        return (1);
    for (int i = 0; i < pow - 1; i++)
        res *= nb;
    return (res);
}

int get_memvalue(int *mem, int cursor)
{
    int res = 0;

    if (cursor < 0)
        cursor = MEM_SIZE + cursor;
    for (int i = 0; i < REG_SIZE; i++)
        res = res + (power(256, REG_SIZE - (i + 1)) * mem[(cursor + i) %
        MEM_SIZE]);
    return (res);
}

void load_memvalue(int *mem, int cursor, int value, int number)
{
    int *prog_nb = prog_nbr();
    unsigned long int test = 0;

    if (cursor < 0)
        cursor = MEM_SIZE + cursor;
    if (value < 0)
        test = 4294967295 + (value + 1);
    else
        test = value;
    for (int i = 0; i < REG_SIZE; i++) {
        mem[(cursor + (REG_SIZE - (i + 1))) % MEM_SIZE] =
        (test / power(256, i) % 256);
        prog_nb[(cursor + REG_SIZE - (i + 1)) % MEM_SIZE] = number;
    }
}

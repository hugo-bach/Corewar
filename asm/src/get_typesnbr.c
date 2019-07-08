/*
** EPITECH PROJECT, 2018
** name
** File description:
** get type by number in the struct
*/

#include "asm.h"

void write_types(char *result, int *pos, int nb)
{
    switch (nb) {
        case 0:
            result[*pos] = 'i';
            break;
        case 1:
            result[*pos] = 'd';
            break;
        case 2:
            result[*pos] = 'r';
            break;
        default:
            write_error("ASM Internal Error (get_typesnbr)");
            break;
    }
    *pos = *pos + 1;
}

char *get_typesnbr(int nb)
{
    char *result = malloc(sizeof(char) * MAX_ARGS_NUMBER);
    int count = 0;
    int pos = 0;

    for (int i = 0; i < MAX_ARGS_NUMBER; i++)
        result[i] = '\0';
    for (int i = T_IND; count < 3; i /= 2, count++)
        if (nb >= i) {
            write_types(result, &pos, count);
            nb %= i;
        }
    return (result);
}

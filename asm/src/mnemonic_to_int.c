/*
** EPITECH PROJECT, 2018
** mnemonic_to_int
** File description:
** mnemonic_to_int
*/

#include "asm.h"
#include "op.h"

int mnemonic_to_int(char *str)
{
    for (int i = 0; op_tab[i].code != 0; i++)
        if (my_strcmp(str, op_tab[i].mnemonique) == 1)
            return (op_tab[i].code);
    write_error("Mnemonic not found");
    return (0);
}

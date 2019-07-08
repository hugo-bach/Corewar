/*
** EPITECH PROJECT, 2018
** my_word_is_present
** File description:
** my_word_is_present
*/

#include "asm.h"
#include "op.h"

int get_nb_inst(char **file)
{
    int count = 0;
    int value = 0;

    for (int i = 2; file[i] != NULL; i++)
        for (int j = 0; op_tab[j].code != 0; j++) {
            value = instruction_is_present(file[i], op_tab[j].mnemonique);
            count = (value == 1) ? count + 1 : count;
        }
    return (count);
}

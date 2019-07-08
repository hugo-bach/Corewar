/*
** EPITECH PROJECT, 2018
** instruction_invalid.c
** File description:
** fct who check if the instruction is invalid
*/

#include "asm.h"

void instruction_invalid(char *str)
{
    int error = 0;
    int nb = 0;

    if (my_word_is_present(str, NAME_CMD_STRING) == 1 ||
        my_word_is_present(str, COMMENT_CMD_STRING) == 1)
        return;
    if (check_label(str) == 1) {
        for (; str[nb] && str[nb] != ':'; nb++);
        if (my_strlen(str) > nb + 1)
            error++;
    }
    for (nb = 0; op_tab[nb].code != 0; nb++)
        if (my_word_is_present(str, op_tab[nb].mnemonique) == 1 ||
        str[0] == '\n') {
            error++;
            break;
        }
    if (error != 1 && error != 2)
        write_error("Instruction invalid");
}

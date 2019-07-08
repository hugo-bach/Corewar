/*
** EPITECH PROJECT, 2018
** instruction
** File description:
** instruction
*/

#include "asm.h"

instr_t **init_struct_instr(instr_t **list, char **file)
{
    int size = get_nb_inst(file);

    list = malloc(sizeof(instr_t *) * (size + 1));
    for (int i = 0; i != size; i++) {
        list[i] = malloc(sizeof(instr_t) * 1);
        list[i]->instr = -1;
    }
    list[size] = NULL;
    return (list);
}

static void fill_instr(instr_t **list, char *file, header_t *header)
{
    static int index;

    for (int j = 0; op_tab[j].code != 0; j++)
        if (instruction_is_present(file, op_tab[j].mnemonique) == 1 &&
        my_word_is_present(file, NAME_CMD_STRING) != 1 &&
        my_word_is_present(file, COMMENT_CMD_STRING) != 1) {
            list[index]->instr = mnemonic_to_int(op_tab[j].mnemonique);
            list[index]->type = get_type(file);
            list[index]->params = get_params(file, header);
            index++;
            return;
        }
}

instr_t **fill_struct_instr(instr_t **list, char **file, header_t *header)
{
    for (int i = 0; file[i] != NULL; i++)
        fill_instr(list, file[i], header);
    return (list);
}

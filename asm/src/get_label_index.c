/*
** EPITECH PROJECT, 2018
** get_label_index.c
** File description:
** fct who get the label index
*/

#include "asm.h"

static int is_offset(instr_t *list)
{
    for (int i = 0; list->params[i] != -1; i++)
        if (list->params[i] == -2)
            return (1);
    return (0);
}

static int check_pos(int index, int pos)
{
    int nb = index - pos;

    if (nb < 0)
        return (1);
    else
        return (0);
}

void write_offset(int index, int pos, instr_t *list)
{
    int nb = check_pos(index, pos);
    int cursor = 0;

    for (; list->params[cursor] != -2; cursor++);
    for (; list->params[cursor] != -1 && list->params[cursor] == -2; cursor++);
    cursor--;
    if (nb == 0) {
        set_instruction(list->params, cursor, (index - pos) + 2, 2);
        write_byte(list->params);
    } else {
        set_instruction(list->params,
            cursor - 1, 257 - ((pos - index) / 257), 1);
        set_instruction(list->params, cursor, 257 - (pos - index - 1), 1);
    }
}

void set_offset(char **file, instr_t **list, int *label_index)
{
    int nb = 0;
    int index = 0;

    for (int i = 2, j = 0; file[i]; i++)
        if (file[i][my_strlen(file[i]) - 2] != LABEL_CHAR) {
            (is_offset(list[j]) == 1) ?
                index = index_offset(file[i], label_index),
                write_offset(index, nb, list[j]) : (void) 0;
            nb += size_instruct(list[j++]);
        }
}

void get_label_index(char **file, instr_t **list)
{
    int nb = 0;
    int *label_index = malloc(sizeof(int) *
    (my_strlen_array(my_macro_label(NULL)) + 1));

    for (int i = 2, j = 0, k = 0; file[i]; i++) {
        if (check_label(file[i]) == 1)
            label_index[k++] = nb;
        if (file[i][my_strlen(file[i]) - 2] != LABEL_CHAR)
            nb += size_instruct(list[j++]);
    }
    label_index[my_strlen_array(my_macro_label(NULL))] = -1;
    set_offset(file, list, label_index);
}

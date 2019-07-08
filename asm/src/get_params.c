/*
** EPITECH PROJECT, 2018
** get_params
** File description:
** get_params
*/

#include "asm.h"

void set_instruction(int *tab, int cursor, int value, int bytes)
{
    if (value == -2) {
        for (int i = 0; i != bytes; i++)
            tab[cursor - i] = -2;
        return;
    }
    tab[cursor] += value;
    for (int j = cursor; j != cursor - bytes; j--)
        while (tab[j] >= 256) {
            tab[j] -= 256;
            (tab[j - 1] == -2) ? tab[j - 1] = 0 : 0;
            tab[j - 1]++;
        }
}

void set_instruction_neg(int *tab, int cursor, int value, int bytes)
{
    int nb = 0;

    value--;
    for (int i = cursor, j = 0; j != bytes; j++, i--)
        tab[i] = 255;
    for (; value >= 256; nb++)
        value -= 256;
    tab[cursor - 1] -= nb;
    tab[cursor] -= value;
}

static int check_new_value_neg(char *str, int value_intr)
{
    if (value_intr >= 0)
        return (value_intr);
    if (value_intr == -2 && str[0] == DIRECT_CHAR && str[1] == LABEL_CHAR)
        return (value_intr);
    if (value_intr == -2 && str[0] == LABEL_CHAR)
        return (value_intr);
    value_intr = -1 * value_intr;
    return (value_intr);
}

static int *get_tab_of_int(char **params, int size, int end_by_i)
{
    int *tab = malloc(sizeof(int) * (size + 1));
    int cursor = 0;
    int value_intr = 0;
    int value_bytes = 0;
    int temp = 0;

    for (int i = 0; i != size + 1; tab[i] = 0, i++);
    tab[size] = -1;
    for (int i = 0; params[i] != NULL; i++, cursor++) {
        value_intr = get_value_instr(params[i]);
        temp = value_intr;
        value_intr = check_new_value_neg(params[i], value_intr);
        value_bytes = get_value_bytes(params[i], end_by_i);
        cursor += (value_bytes - 1);
        if (temp != value_intr)
            set_instruction_neg(tab, cursor, value_intr, value_bytes);
        else
            set_instruction(tab, cursor, value_intr, value_bytes);
    }
    return (tab);
}

int *get_params(char *str, header_t *header)
{
    int value = 0;
    int end_by_i = 0;
    char tmp[3] = {SEPARATOR_CHAR, '\n', '\0'};
    char **params = NULL;

    str = skip_label(str);
    end_by_i = it_end_by_i(str);
    str = skip_space(str);
    params = my_str_to_tab(str, tmp);
    for (int i = 0; params[i] != NULL; i++)
        if (my_word_is_present(params[i], NAME_CMD_STRING) != 1 &&
        my_word_is_present(params[i], COMMENT_CMD_STRING) != 1) {
            for (; params[i][0] == ' '; params[i]++);
            value += get_value_bytes(params[i], end_by_i);
        }
    header->prog_size += value;
    return (get_tab_of_int(params, value, end_by_i));
}

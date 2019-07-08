/*
** EPITECH PROJECT, 2018
** name
** File description:
** get intruction number function
*/

#include "corewar.h"

char *get_instruction_name(int nb)
{
    for (int i = 0; op_tab[i].mnemonique != 0; i++)
        if (op_tab[i].code == nb)
            return (op_tab[i].mnemonique);
    return (NULL);
}

int get_value_type(char c_a, char c_b, int special)
{
    if (c_a == '0') {
        if (c_b == '1')
            return (1);
        else
            return (0);
    } else {
        if (c_b == '0' && special != 1)
            return (4);
        else
            return (2);
    }
    return (0);
}

char get_char_type(char c_a, char c_b)
{
    if (c_a == '0') {
        if (c_b == '1')
            return ('r');
        else
            return ('\0');
    } else {
        if (c_b == '0')
            return ('d');
        else
            return ('i');
    }
    return ('\0');
}

static int fill_params_type(char *type, char *name, char *params, int res)
{
    for (int i = 0, j = 0; type[j + 2] && i < MAX_ARGS_NUMBER - 1;
    i++, j += 2) {
        if (type[j + 1] != '\0') {
            res += get_value_type(type[j], type[j + 1], is_special(name));
            params[i] = get_char_type(type[j], type[j + 1]);
        }
    }
    return (res);
}

int get_instruction_size(int *mem, int pc, char *params)
{
    int desc = mem[(pc % MEM_SIZE) + 1];
    int res = 2;
    char *type = int_to_base(desc, 2);
    char *name = get_instruction_name(mem[pc]);

    if (my_strcmp(name, "live")) {
        free(type);
        return (5);
    }
    if (is_special(name) == 2) {
        free(type);
        return (3);
    }
    res = fill_params_type(type, name, params, res);
    params[MAX_ARGS_NUMBER] = '\0';
    free(type);
    return (res);
}

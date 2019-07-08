/*
** EPITECH PROJECT, 2018
** name
** File description:
** check params function
*/

#include "asm.h"

void check_params(char *name, char *result)
{
    int nb_param = 0;
    int i = 0;
    int test = 0;
    char *params = NULL;

    for (; op_tab[i].mnemonique != 0; i++)
        if (my_strcmp(op_tab[i].mnemonique, name) == 1) {
            nb_param = op_tab[i].nbr_args;
            break;
        }
    if (my_strlen(result) != nb_param)
        write_error("Error: ASM - too many arguments");
    for (int j = 0; result[j] != '\0'; j++) {
        params = get_typesnbr(op_tab[i].type[j]);
        for (int k = 0; params[k]; k++)
            (params[k] == result[j]) ? test = 1 : 0;
        (test != 1) ? write_error("Error: ASM - bad arguments") : (void) 0;
        test = 0;
    }
}

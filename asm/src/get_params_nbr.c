/*
** EPITECH PROJECT, 2018
** name
** File description:
** get params nbr
*/

#include "asm.h"

void fill_first_str(char *types, char *result_str)
{
    int pos = 0;

    for (int i = 0; types[i] != '\0'; i++, pos += 2) {
        if (types[i] == 'r') {
            result_str[pos] = '0';
            result_str[pos + 1] = '1';
        } else if (types[i] == 'd') {
            result_str[pos] = '1';
            result_str[pos + 1] = '0';
        } else {
            result_str[pos] = '1';
            result_str[pos + 1] = '1';
        }
    }
    result_str[pos] = '\0';
}

int *change_binary_to_list(char *str)
{
    int *result = malloc(sizeof(int) * ((my_strlen(str) / 8) + 1));
    char *buffer = NULL;
    int counter = 0;
    int counter1 = 0;

    for (int i = 0; str[i] != '\0'; i += 8, counter1++) {
        buffer = malloc(sizeof(char) * 9);
        for (int j = i; j < i + 8; j++)
            buffer[counter++] = str[j];
        buffer[counter] = '\0';
        counter = 0;
        result[counter1] = base_to_int(buffer, 2);
    }
    result[counter1] = -1;
    return (result);
}

static int *get_empty_list(void)
{
    int *result = malloc(sizeof(int));

    result[0] = -1;
    return (result);
}

int *get_params_nbr(char *types)
{
    char *result_str;
    char *full_result = NULL;
    int i = 0;
    int nb = 0;

    if (types == NULL)
        return (get_empty_list());
    nb = my_strlen(types);
    result_str = malloc(sizeof(char) * (nb * 2 + 1));
    fill_first_str(types, result_str);
    full_result = malloc(sizeof(char) * (nb * 2 + (8 - ((nb * 2) % 8)) + 1));
    for (i = 0; result_str[i]; i++)
        full_result[i] = result_str[i];
    for (; i < ((nb * 2) + (8 - ((nb * 2) % 8))); i++)
        full_result[i] = '0';
    full_result[i] = '\0';
    for (i = my_strlen(full_result) - 1; full_result[i] == '0'; i--);
    if ((i + 1) % 8 == 0)
        full_result[i + 1] = '\0';
    return (change_binary_to_list(full_result));
}

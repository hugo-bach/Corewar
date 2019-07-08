/*
** EPITECH PROJECT, 2018
** label_tools
** File description:
** label_tools
*/

#include "asm.h"

int index_offset(char *file, int *label_index)
{
    char **label = my_macro_label(NULL);
    char lb[2] = {LABEL_CHAR, '\0'};
    int i = 0;

    for (; label[i]; i++)
        if (check_word(file, my_strcat(lb, label[i])) == 1)
            return (label_index[i]);
    return (0);
}

int is_a_label_chars(char c)
{
    for (int i = 0; LABEL_CHARS[i] != '\0'; i++)
        if (LABEL_CHARS[i] == c)
            return (1);
    return (0);
}

int check_label(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == LABEL_CHAR && is_a_label_chars(str[i-1]) == 1)
            return (1);
    return (0);
}

int is_in_labels(char *str)
{
    char **labels = my_macro_label(NULL);

    if (labels == NULL)
        return (0);
    for (int i = 0; labels[i] != NULL; i++)
        if (my_strcmp(labels[i], str) == 1)
            return (1);
    return (0);
}

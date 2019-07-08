/*
** EPITECH PROJECT, 2018
** my_macro_label.c
** File description:
** fct who save a char **of label
*/

#include "asm.h"

static int count_label(char *str)
{
    for (int j = 0; str[j]; j++) {
        if (j != 0 && str[j] == LABEL_CHAR &&
            is_a_label_chars(str[j - 1]) == 0 &&
            str[j - 1] != DIRECT_CHAR && str[j - 1] != SEPARATOR_CHAR
            && str[j - 1] != ' ')
            write_error("Invalid label");
        if (j != 0 && str[j] == LABEL_CHAR &&
            is_a_label_chars(str[j - 1]) != 0)
            return (1);
    }
    return (0);
}

static int nb_label(char **str)
{
    int nb = 1;

    for (int i = 0; str[i]; i++) {
        instruction_invalid(str[i]);
        nb += count_label(str[i]);
    }
    return (nb);
}

static char *set_label(char *str, int j)
{
    char *result = malloc(sizeof(char) * (j + 1));

    for (int i = 0; i != j; i++) {
        if (is_a_label_chars(str[i]) == 0)
            write_error("Invalid char for the label");
        result[i] = str[i];
    }
    result[j] = '\0';
    return (result);
}

static void multiple_definition(char *label1, char *label2)
{
    if (my_strcmp(label1, label2) == 1)
        write_error("Multiple definition");
}

char **create_label(char **str)
{
    int size = nb_label(str);
    char **label = malloc(sizeof(char *) * size);
    int nb = 0;

    if (size == 1) {
        free(label);
        return (NULL);
    }
    for (int i = 0; str[i]; i++)
        for (int j = 0; str[i][j]; j++)
            (j != 0 && str[i][j] == LABEL_CHAR &&
                is_a_label_chars(str[i][j - 1]) != 0) ?
                label[nb++] = set_label(str[i], j) : 0;
    label[nb] = NULL;
    if (size <= 2)
        return (label);
    for (int j = 0; label[j + 1]; j++)
        for (int i = j + 1; label[i]; i++)
            multiple_definition(label[j], label[i]);
    return (label);
}

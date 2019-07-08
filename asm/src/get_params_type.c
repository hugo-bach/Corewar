/*
** EPITECH PROJECT, 2018
** name
** File description:
** get parameters type
*/

#include "asm.h"

static int count_words(char *str)
{
    int result = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == SEPARATOR_CHAR)
            result++;
    return (result + 1);
}

static char *my_reallocchar(char *str, char c)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = 0;

    for (; str[i] != '\0'; i++)
        result[i] = str[i];
    result[i++] = c;
    result[i] = '\0';
    return (result);
}

char get_char_by_param(char *param)
{
    if (param[0] == 'r')
        return ('r');
    else if (param[0] == '%')
        return ('d');
    else
        return ('i');
}

char *init_line(char *instruct_line, int *i)
{
    char *name = malloc(sizeof(char));

    name[0] = '\0';
    for (; instruct_line[*i] != ' '; *i = *i + 1)
        name = my_reallocchar(name, instruct_line[*i]);
    *i += 1;
    return (name);
}

char *get_params_type(char *instruct_line)
{
    int i = 0;
    int k = 0;
    char *buffer;
    char *result = malloc(sizeof(char) * (count_words(instruct_line) + 1));
    char *name = init_line(instruct_line, &i);

    for (int j = 0; j < count_words(instruct_line); j++, i++) {
        buffer = malloc(sizeof(char));
        buffer[0] = '\0';
        for (; instruct_line[i] && instruct_line[i] == ' '; i++);
        for (; instruct_line[i] && instruct_line[i] != SEPARATOR_CHAR; i++)
            buffer = my_reallocchar(buffer, instruct_line[i]);
        result[k++] = get_char_by_param(buffer);
    }
    result[k] = '\0';
    check_params(name, result);
    if (my_strcmp(name, "zjmp") == 1 || my_strcmp(name, "live") == 1 ||
        my_strcmp(name, "fork") == 1 || my_strcmp(name, "lfork") == 1)
        return (NULL);
    return (result);
}

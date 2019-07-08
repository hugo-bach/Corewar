/*
** EPITECH PROJECT, 2018
** name
** File description:
** delete_comment function
*/

#include "asm.h"

int my_contains_only(char *str, char *chars)
{
    int counter = 0;

    for (int i = 0; str[i]; i++)
        for (int j = 0; chars[j]; j++)
            counter = (str[i] = chars[j]) ? counter + 1 : counter;
    if (counter == my_strlen(str))
        return (0);
    return (1);
}

int get_nbrline(char **tab)
{
    int count = 0;

    for (int i = 0; tab[i] != NULL; i++)
        if (my_strlen(tab[i]) >= 1 || my_contains_only(tab[i], " #\n\t") == 1)
            count++;
    return (count);
}

char *delete_comment_into_line(char *line)
{
    int i = 0;
    int new_stop = my_strlen(line) - 1;
    int new_start = 0;

    for (; line[i] != '\0' && line[i] != COMMENT_CHAR; i++);
    if (line[i] == COMMENT_CHAR)
        line[i] = '\0';
    if (my_strlen(line) > 1) {
        new_stop = my_strlen(line) - 2;
        for (; new_stop > 0 && line[new_stop] == ' '; new_stop--);
        if (line[new_stop] != '\n') {
            line[new_stop + 1] = '\n';
            line[new_stop + 2] = '\0';
        } else
            line[new_stop + 1] = '\0';
    }
    for (; line[new_start] == ' '; new_start++);
    return (line + new_start);
}

char **clean_tab(char **tab)
{
    char **result;
    int count = 0;
    int k = 0;
    int i = 0;

    for (i = 0; tab[i]; i++)
        if (my_strlen(tab[i]) > 1)
            count++;
    result = malloc(sizeof(char *) * (count + 1));
    for (i = 0; tab[i]; i++)
        if (my_strlen(tab[i]) > 1)
            result[k++] = tab[i];
    result[k] = NULL;
    return (result);
}

char **delete_comment(char **tab)
{
    char **new_tab = malloc(sizeof(char *) * (get_nbrline(tab) + 1));
    int i = 0;
    int j = 0;
    int k = 0;

    for (; tab[i] != NULL; i++)
        if (my_strlen(tab[i]) >= 1 || my_contains_only(tab[i], " #\n\t") == 1)
            new_tab[k++] = tab[i];
    new_tab[get_nbrline(tab)] = NULL;
    for (i = 0; new_tab[i]; i++)
        for (j = 0; new_tab[i][j] != '\0'; j++)
            (new_tab[i][j] == '\t') ? new_tab[i][j] = ' ' : 0;
    for (i = 0; new_tab[i]; i++)
        new_tab[i] = delete_comment_into_line(new_tab[i]);
    new_tab = clean_tab(new_tab);
    return (new_tab);
}

/*
** EPITECH PROJECT, 2018
** my_str_to_tab
** File description:
** my_str_to_tab
*/

#include "asm.h"

int my_char_is_present(char *str, char c)
{
    for (int i = 0; i <= my_strlen(str); i++)
        if (str[i] == c)
            return (1);
    return (0);
}

char **start_to_write(char *str, char **tab, char *char_to_skip)
{
    int flg = 0;
    int y = 0;
    int x = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = i; my_char_is_present(char_to_skip, str[j])
        == 0; j++, y++) {
            tab[x][y] = str[j];
            flg = 1;
        }
        i += y;
        if (str[i] == '\0')
            i--;
        if (flg == 1)
            tab[x++][y] = '\0';
        y = 0;
        flg = 0;
    }
    return (tab);
}

int get_nb_words(char *str, char *char_to_skip)
{
    int x = 0;
    int nb_words = 0;
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = i; my_char_is_present(char_to_skip, str[j])
            == 0; j++, len++)
            x = 1;
        i += len;
        if (str[i] == '\0')
            i--;
        if (x == 1)
            nb_words++;
        x = 0;
        len = 0;
    }
    return (nb_words);
}

void get_size_words(char *str, int *tab_len, char *char_to_skip)
{
    int x = 0;
    int len = 0;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = i; my_char_is_present(char_to_skip, str[j])
            == 0; j++, len++)
            x = 1;
        i += len;
        if (str[i] == '\0')
            i--;
        if (x == 1) {
            tab_len[j] = len;
            j++;
        }
        x = 0;
        len = 0;
    }
    tab_len[j] = -1;
}

char **my_str_to_tab(char *str, char *char_to_skip)
{
    int tab_len[get_nb_words(str, char_to_skip) + 1];
    char **tab;
    int len = 0;
    int i = 0;

    get_size_words(str, tab_len, char_to_skip);
    for (; tab_len[len] != -1; len++);
    tab = malloc(sizeof(char *) * (len + 1));
    for (; i < len; i++)
        tab[i] = malloc(sizeof(char) * (tab_len[i] + 1));
    tab[i] = NULL;
    tab = start_to_write(str, tab, char_to_skip);
    return (tab);
}
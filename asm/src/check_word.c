/*
** EPITECH PROJECT, 2018
** check_word.c
** File description:
** check word
*/

#include "asm.h"

int check_word(char *str, char *word)
{
    int count = my_strlen(word);
    int nb = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == word[nb])
            nb++;
        else
            nb = 0;
        if (nb == count && (str[i + 1] == SEPARATOR_CHAR ||
            str[i + 1] == ' ' || str[i + 1] == '\n' || str[i + 1] == '\0'))
            return (1);
    }
    return (0);
}

/*
** EPITECH PROJECT, 2018
** my_word_is_present
** File description:
** my_word_is_present
*/

#include "asm.h"

int my_word_is_present(char *str, char *word)
{
    int len_word = my_strlen(word);
    int curs = 0;
    int result = 0;

    for (int k = 0; str[k] != '\0'; k++) {
        curs = 0;
        while (str[k] == word[curs] && result != 1) {
            k++;
            curs++;
            result = (curs == len_word && (str[k] == ' ')) ? 1 : 0;
        }
    }
    return result;
}

int instruction_is_present(char *str, char *word)
{
    int nb = 0;
    char *temp = my_strdup(str);

    if (check_label(temp) == 1)
        temp = skip_label(str);
    for (; temp[0] && temp[0] == ' '; temp++);
    if (my_strlen(temp) < my_strlen(word))
        return (0);
    for (int i = 0; word[i]; i++) {
        if (word[i] == temp[nb])
            nb++;
        else
            nb = 0;
        if (nb == my_strlen(word) && temp[nb] == ' ')
            return (1);
    }
    return (0);
}

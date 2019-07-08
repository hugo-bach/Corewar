/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** parsing function of the corewar
*/

#include "corewar.h"

char *get_prog_comment(int *header)
{
    int i;
    int index = 0;
    char *comment;

    for (i = PROG_NAME_LENGTH + 12; header[i] != 0; i++);
    comment = malloc(sizeof(char) * (i+1));
    for (int j = PROG_NAME_LENGTH + 12; header[j] != 0; j++) {
        comment[index] = header[j];
        index++;
    }
    comment[index] = '\0';
    return comment;
}

char *get_prog_name(int *header)
{
    int i;
    int index = 0;
    char *prog_name;

    for (i = 4; header[i] != 0; i++);
    prog_name = malloc(sizeof(char) * (i+1));
    for (int j = 4; header[j] != 0; j++) {
        prog_name[index] = header[j];
        index++;
    }
    prog_name[index] = '\0';
    return prog_name;
}
/*
** EPITECH PROJECT, 2018
** header_parsing.c
** File description:
** function header_parsing of project asm
*/

#include "asm.h"

static void valid_string(char *line, int size)
{
    int i = 0;
    int count_quote = 0;

    for (; line[i] != '\0'; i++)
        if (line[i] == '"')
            count_quote++;
    if (i > size)
        write_error("to long name or comment.");
    if (count_quote != 2)
        write_error("invalid name or comment.");
    if (my_str_endwith(line, "\"\n") != 1)
        write_error("invalid line content.");
    return;
}

static char *string_grab(char *line, int size)
{
    int i = 0;
    int j = 0;
    char *dest = NULL;

    valid_string(line, size);
    dest = malloc(sizeof(char) * (size + 1));
    for (; line[i] != '"'; i++);
    i++;
    for (; line[i] != '"'; j++, i++)
        dest[j] = line[i];
    dest[j] = '\0';
    return dest;
}

void header_parsing(header_t *header, char **lines)
{
    int name = 0;
    int comment = 0;

    for (int i = 0; lines[i] != NULL; i++) {
        if (my_line_startwith(lines[i], NAME_CMD_STRING) == 1) {
            (i == 0) ? (void)0 : write_error("name must be on first line.");
            header->prog_name = string_grab(lines[i], PROG_NAME_LENGTH);
            name = 1;
        }
        if (my_line_startwith(lines[i], COMMENT_CMD_STRING) == 1) {
            (i == 1) ? (void)0 : write_error("comment have to follow name.");
            header->comment = string_grab(lines[i], COMMENT_LENGTH);
            comment = 1;
        }
    }
    if (name == 0 || comment == 0)
        write_error("missing name or comment.");
    return;
}

/*
** EPITECH PROJECT, 2018
** name
** File description:
** open file and print the result in char **
*/

#include "asm.h"

char **my_realloc(char **ptr, int new_size, char *new_element)
{
    char **result = malloc(sizeof(char *) * (new_size + 1));
    int i = 0;

    if (result == NULL)
        return (NULL);
    if (ptr != NULL)
        for (; ptr[i]; i++)
            result[i] = ptr[i];
    result[i] = my_strdup(new_element);
    result[i + 1] = NULL;
    return (result);
}

char **open_file(char *file)
{
    FILE *fd = fopen(file, "r");
    char *buffer = NULL;
    char **result = NULL;
    size_t size = 0;
    int i = 1;

    if (fd == NULL || endswith(file, ".s") != 1)
        write_error("Erreur fichier introuvable, ou type incorrect");
    for (; getline(&buffer, &size, fd) != -1; i++)
        result = my_realloc(result, i, buffer);
    if (result == NULL)
        write_error("Error: ASM - empty file");
    fclose(fd);
    free(buffer);
    return (result);
}

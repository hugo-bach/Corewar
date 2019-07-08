/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function of the corewar
*/

#include "corewar.h"

unsigned int *registre_dup(unsigned int *model)
{
    unsigned int *new = malloc(sizeof(unsigned int) * (REG_NUMBER + 1));

    for (int i = 0; i < REG_NUMBER + 1; i++)
        new[i] = model[i];
    return new;
}

int *int_array_cpy(int *model)
{
    int size = 0;
    int i = 0;
    int *new;

    for (size = 0; model[size] != -1; size++);
    new = malloc(sizeof(int) * (size+1));
    for (; model[i] != -1; i++)
        new[i] = model[i];
    new[i] = -1;
    return new;
}

prog_t *struct_dup(prog_t *model)
{
    prog_t *copy;
    copy = malloc(sizeof(prog_t));
    copy->name = model->name;
    copy->prog_name = my_strdup(model->prog_name);
    copy->comment = my_strdup(model->comment);
    copy->header = int_array_cpy(model->header);
    copy->core = int_array_cpy(model->core);
    copy->prog_size = model->prog_size;
    copy->number = model->number;
    copy->pc = model->pc;
    copy->live = model->live;
    copy->registre = registre_dup(model->registre);
    copy->dead = model->dead;
    copy->address = model->address;
    copy->carry_flag = 0;
    copy->instruction = NULL;

    return copy;
}

void swap_elem(prog_t **array, int i, int j)
{
    prog_t *swap;

    if (array[i]->number < array[j]->number) {
        swap = array[i];
        array[i] = array[j];
        array[j] = swap;
    }
    return;
}

void struct_sorter(prog_t **array)
{
    for (int i = 0; i < nb_of_programs(0); i++)
        for (int j = 0; j < nb_of_programs(0); j++)
            swap_elem(array, i, j);
    return;
}

/*
** EPITECH PROJECT, 2018
** create_instruction.c
** File description:
** fct who create a struct and fill with the instruction
*/

#include "corewar.h"

static int *get_instruction(int *prog, int pc, int size)
{
    int *instruction = malloc(sizeof(int) * (size + 1));
    int i = 0;

    for (int j = pc; i != size; i++, j++)
        instruction[i] = prog[j % MEM_SIZE];
    instruction[i] = -1;
    return (instruction);
}

static void error_struct(instruction_t *instruct)
{
    instruct->size = -1;
    instruct->cycle = - 1;
    instruct->inst = malloc(sizeof(int) * 1);
    instruct->inst[0] = -1;
    instruct->nb_cycle = -2;
    instruct->params = NULL;
}

static char *my_calloc(int size)
{
    char *result = malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++)
        result[i] = '\0';
    return (result);
}

instruction_t *create_instruction(int *memory, int pc)
{
    instruction_t *inst = malloc(sizeof(instruction_t));
    int count_cycle = 0;

    for (int i = 0; op_tab[i].nbr_cycles != 0; i++) {
        (pc < 0) ? pc = MEM_SIZE + pc : 0;
        if (op_tab[i].code == memory[pc]) {
            count_cycle = op_tab[i].nbr_cycles;
            break;
        }
    }
    if (count_cycle == 0) {
        error_struct(inst);
        return (inst);
    }
    inst->params = my_calloc(MAX_ARGS_NUMBER + 2);
    inst->size = get_instruction_size(memory, pc, inst->params);
    inst->cycle = count_cycle;
    inst->inst = get_instruction(memory, pc, inst->size);
    inst->nb_cycle = 0;
    return (inst);
}

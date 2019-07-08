/*
** EPITECH PROJECT, 2018
** instruction.h
** File description:
** header of instruction
*/

#ifndef INSTRUCTION_H

typedef struct instruction_s
{
    int size;
    int cycle;
    int *inst;
    int nb_cycle;
    char *params;
} instruction_t;

typedef struct prog_s
{
    char *name;
    char *prog_name;
    char *comment;
    int address;
    int number;
    int *header;
    int *core;
    int prog_size;
    unsigned int *registre;
    int pc;
    int carry_flag;
    int live;
    bool dead;
    instruction_t *instruction;
} prog_t;

void fill_params(prog_t **, int , char **);
prog_t **virtual_machine(prog_t **, int *, int);
instruction_t *create_instruction(int *, int);
int get_instruction_size(int *, int, char *);
int check_instruction(int, int *, int *);
char *get_instruction_name(int);
bool forced_win(prog_t **, int);
bool reset_live(prog_t **, int);
void display_winner(prog_t **);
void struct_sorter(prog_t **);
prog_t *struct_dup(prog_t *);
prog_t **launch_instruction(int *, prog_t **, int);
void display_ncurse(prog_t **, int *, int ,int, int);
void free_all(prog_t **);
void prog_sort(prog_t **);
void free_instruction(prog_t *);
void free_struct(prog_t *);
void swap_elem(prog_t **, int, int);
void ld_instruction(int *, prog_t **, int);
void ldi_instruction(int *, prog_t **, int);
void st_instruction(int *, prog_t **, int);
void sti_instruction(int *, prog_t **, int);
void live_instruction(int *, prog_t **, int);
void zjmp_instruction(int *, prog_t **, int);
void lld_instruction(int *, prog_t **, int);
void lldi_instruction(int *, prog_t **, int);
void add_instruction(int *, prog_t **, int);
void sub_instruction(int *, prog_t **, int);
void and_instruction(int *, prog_t **, int);
void or_instruction(int *, prog_t **, int);
void xor_instruction(int *, prog_t **, int);
void aff_instruction(int *, prog_t **, int);
prog_t **fork_instruction(int *, prog_t **, int);
prog_t **lfork_instruction(int *, prog_t **, int);
void display_ncurse_win(prog_t *, prog_t **, int);

#endif /*INSTRUCTION_H*/

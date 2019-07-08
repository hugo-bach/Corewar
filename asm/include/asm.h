/*
** EPITECH PROJECT, 2018
** asm.h
** File description:
** header of the project asm
*/

#ifndef ASM_H
#define ASM_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "op.h"

typedef struct instr_s {
    int instr;
    int *type;
    int *params;
} instr_t;

typedef struct asm_core {
    int *exec_magic;
    int *name;
    int *comment;
    int *prog;
} asm_core_t;

int my_strlen(char *);
char *my_strdup(char *);
char **open_file(char *);
char **delete_comment(char **);
int base_to_int(char *, int);
char *int_to_base(int, int);
int *string_encoder(char *, int);
void write_core(int *);
int my_macro_fd(char *);
char *my_strcat(char *, char *);
char *name_core(char *);
int my_strcmp(char *, char *);
int my_line_startwith(char *, char *);
int mnemonic_to_int(char *);
void header_parsing(header_t *, char **);
int my_word_is_present(char *, char *);
int get_nb_inst(char **);
int *get_params_nbr(char *);
char *get_params_type(char *);
char **my_macro_label(char **);
void write_error(char *);
int is_a_label_chars(char);
int endswith(char *, char *);
char **my_str_to_tab(char *, char *);
int my_atoi(char *);
int *get_params(char *, header_t *);
int *get_type(char *);
instr_t **init_struct_instr(instr_t **, char **);
instr_t **fill_struct_instr(instr_t **, char **, header_t *);
int check_label(char *);
int it_end_by_i(char *);
int is_a_label_chars(char);
int is_in_labels(char *);
int get_value_registre(char *);
int get_value_number(char *);
int get_value_offset(char *, int);
int get_value_direct_char(char *, int);
int get_value_bytes(char *, int);
int get_value_label(char *);
char *get_typesnbr(int);
void instruction_invalid(char *);
char *get_typesnbr(int);
void check_params(char *, char *);
int *get_magic_nbr(void);
int my_str_endwith(char *, char *);
void calc_prog(instr_t **, header_t *);
int my_strlen_array(char **);
void write_core_int(int);
void get_label_index(char **, instr_t **);
int my_strlen_array(char **);
int size_instruct(instr_t *);
void set_instruction(int *, int, int, int);
int check_word(char *, char *);
void write_byte(int *);
int instruction_is_present(char *, char *);
char *skip_label(char *);
char *skip_space(char *);
int index_offset(char *, int *);
int get_value_instr(char *);
char **create_label(char **);

#endif

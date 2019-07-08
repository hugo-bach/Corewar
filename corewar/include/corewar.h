/*
** EPITECH PROJECT, 2018
** corewar.h
** File description:
** header of the project corewar
*/

#ifndef COREWAR_H

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>
#include <ncurses.h>
#include <string.h>

#include "instruction.h"
#include "singleton.h"
#include "utils.h"
#include "op.h"

#define DELAY 800

typedef struct params_s
{
    char *flag;
    int index;
} params_t;

int nb_prog(char **);
int number_already_used(int, int, int *);
int find_dump(char **);
char *int_to_base(int, int);
char ***hex_dump(int *);
int *get_header(int);
int *get_prog(int, int*, int*);
char *name_finder(char **);
void count_checker(int, int *, int *);
void display_help(int);
int is_special(char *);
int get_memvalue(int *, int);
void load_memvalue(int *, int, int, int);
int get_mem_special_value(int *, int, int);
int *get_params_value(int *, char *);
char *get_prog_comment(int *);
char *get_prog_name(int *);
void fill_address(int *, int);
void fill_number(int *, int);
int get_value(char **, int, char *);
void find_values(int *, char **, char *);
unsigned int *registre_dup(unsigned int *);
unsigned int *set_registre(int);
void launch_dump(int, int, int *);

#endif

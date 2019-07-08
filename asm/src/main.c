/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** function main of project asm
*/

#include "asm.h"

static void write_result(instr_t **list, char **file,
                        header_t header, asm_core_t core)
{
    int h[2] = {0, -1};
    int size[5] = {0, 0, 0, 0, -1};

    write_core(h);
    write_core(core.exec_magic);
    write_core(core.name);
    calc_prog(list, &header);
    set_instruction(size, 3, header.prog_size, 4);
    write_core(size);
    write_core(core.comment);
    if (my_strlen_array(file) == 2)
        return;
    get_label_index(file, list);
    for (int i = 0; list[i]; i++) {
        write_core_int(list[i]->instr);
        write_core(list[i]->type);
        write_core(list[i]->params);
    }
}

int main(int ac, char **av)
{
    char **file = NULL;
    header_t header = {0, NULL, 0, NULL};
    asm_core_t core = {NULL, NULL, NULL, NULL};
    instr_t **list = NULL;

    if (ac != 2)
        return (84);
    file = open_file(av[1]);
    file = delete_comment(file);
    header_parsing(&header, file);
    core.exec_magic = get_magic_nbr();
    core.name = string_encoder(header.prog_name, PROG_NAME_LENGTH + 4);
    core.comment = string_encoder(header.comment, COMMENT_LENGTH + 4);
    my_macro_label(file);
    list = init_struct_instr(list, file);
    list = fill_struct_instr(list, file, &header);
    my_macro_fd(av[1]);
    write_result(list, file, header, core);
    return (0);
}

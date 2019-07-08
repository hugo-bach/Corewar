/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** parsing function of the corewar
*/

#include "corewar.h"

void display_help(int type)
{
    my_putstr("USAGE\n");
    my_putstr("\t./corewar [-dump nbr_cycle] ");
    my_putstr("[[-n prog_number] [-a load_address] prog_name] ...\n");
    my_putstr("DESCRIPTION\n\t-dump nbr_cycle");
    my_putstr("\tdumps the memory after the nbr_cycle execution");
    my_putstr("if the round isn’t\n\t\talready over) with ");
    my_putstr("the following format: 32");
    my_putstr("bytes/line in\n\t\thexadecimal (A0BCDEFE1DD3...)\n\t");
    my_putstr("-n prog_number\tsets the next program’s number. ");
    my_putstr("By default, the first free number\n");
    my_putstr("\t\tin the parameter order\n\t");
    my_putstr("-a load_address\tsets the next program’s ");
    my_putstr("loading address. When no address is\n");
    my_putstr("\t\tspecified, optimize the addresses so that ");
    my_putstr("the processes are as far\n");
    my_putstr("\t\taway from each other as possible.");
    my_putstr(" The addresses are MEM_SIZE modulo\n");
    exit(type);
}
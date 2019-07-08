/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function of the corewar
*/

#include "corewar.h"

static void win_text(prog_t *win, prog_t **list, int cycle)
{
    display_ncurse_win(win, list, cycle);
    endwin();
    exit(0);
}

bool forced_win(prog_t **prog_list, int cycle)
{
    int last = last_alive(-1);

    for (int i = 0; i < nb_of_programs(0); i++) {
        if (prog_list[i]->dead == false && prog_list[i]->number == last) {
            win_text(prog_list[i], prog_list, cycle);
            break;
        }
    }
    return true;
}

bool check_other(int *i, int alive, prog_t **prog_list)
{
    while (*i < nb_of_programs(0)) {
        if (prog_list[*i]->dead != true && prog_list[*i]->number != alive) {
            return false;
        }
        (*i)++;
    }
    return true;
}

static bool check_win(prog_t **prog_list, int cycle)
{
    int alive = 0;
    int breaker = 0;
    int index = 0;

    for (int i = 0; i < nb_of_programs(0) && breaker != 1; i++) {
        if (prog_list[i]->dead == false) {
            alive = prog_list[i]->number;
            index = i;
            i++;
            breaker = (check_other(&i, alive, prog_list) == false) ? 1 : 0;
        }
    }
    if (breaker == 1)
        return false;
    win_text(prog_list[index], prog_list, cycle);
    return true;
}

bool reset_live(prog_t **prog_list, int cycle)
{
    bool win = false;

    for (int j = 0; j < nb_of_programs(0) && win != true; j++) {
        if (prog_list[j]->live != prog_list[j]->number)
            prog_list[j]->dead = true;
        else if (prog_list[j]->live == prog_list[j]->number)
            prog_list[j]->live = 0;
        win = check_win(prog_list, cycle);
    }
    return win;
}

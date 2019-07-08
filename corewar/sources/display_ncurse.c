/*
** EPITECH PROJECT, 2018
** display_ncurse.c
** File description:
** fct who display the memory in ncurse
*/

#include "corewar.h"

static void init_ncurse(void)
{
    initscr();
    timeout(TRUE);
    keypad(stdscr, TRUE);
    noecho();
    if (has_colors() == FALSE)
        (1) ? endwin(), write_error("Terminal doesn't support color") : (void)0;
    start_color();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    curs_set(FALSE);
}

static int *color_nb(prog_t **instr)
{
    int nb = nb_of_programs(0);
    int *color_nb = calloc(sizeof(int), (nb + 1));

    for (int i = 0; i != nb; i++)
        color_nb[i] = instr[i]->number;
    color_nb[nb] = -1;
    return (color_nb);
}

static char **name_prog(prog_t **instr)
{
    int nb = nb_of_programs(0);
    char **result = calloc(sizeof(char *), (nb + 1));

    for (int i = 0; i != nb; i++)
        result[i] = strdup(instr[i]->prog_name);
    return (result);
}

char **open_ascii(void)
{
    FILE *fd = fopen("ascii_name.txt", "r");
    char **def = calloc(sizeof(char *), 2);
    char *temp = NULL;
    size_t len = 0;
    int nb = 0;
    char **ascii = NULL;

    def[0] = strdup("Erreur impossible d'ouvrir le fichier");
    if (fd == NULL)
        return (def);
    for (; getline(&temp, &len, fd) != -1; nb++);
    fclose(fd);
    fd = fopen("ascii_name.txt", "r");
    ascii = calloc(sizeof(char *), (nb + 1));
    for (int i = 0; getline(&temp, &len, fd) != -1; i++)
        ascii[i] = strdup(temp);
    (temp != NULL) ? free(temp) : (void) 0;
    fclose(fd);
    return (ascii);
}

void display_ncurse_win(prog_t *instr, prog_t **list, int cycle)
{
    char *color_name[7] = {"RED", "GREEN", "BLUE", "YELLOW", "MAGENTA", "CYAN", NULL};
    int *color = color = color_nb(list);
    WINDOW *win = NULL;
    int *prog_nb = prog_nbr();
    char *arg[3] = {"./ascii_art.py", instr->prog_name, NULL};
    pid_t test = fork();
    int len = 0;
    if (test == 0)
        execvp(arg[0], arg);
    else
        waitpid(test, &len, F_OK);
    char **ascii = open_ascii();

    for (int i = 25; i != 0; i--) {
        win = subwin(stdscr, LINES - 45, COLS - 45, i, 25);
        clear();
        box(win, ACS_VLINE, ACS_HLINE);
        mvwprintw(win, 2, 50, " __       __  __                                                __ ");
        mvwprintw(win, 3, 50, "/  |  _  /  |/  |                                              /  |");
        mvwprintw(win, 4, 50, "$$ | / \\ $$ |$$/  _______   _______    ______    ______        $$ |");
        mvwprintw(win, 5, 50, "$$ |/$  \\$$ |/  |/       \\ /       \\  /      \\  /      \\       $$ |");
        mvwprintw(win, 6, 50, "$$ /$$$  $$ |$$ |$$$$$$$  |$$$$$$$  |/$$$$$$  |/$$$$$$  |      $$ |");
        mvwprintw(win, 7, 50, "$$ $$/$$ $$ |$$ |$$ |  $$ |$$ |  $$ |$$    $$ |$$ |  $$/       $$/ ");
        mvwprintw(win, 8, 50, "$$$$/  $$$$ |$$ |$$ |  $$ |$$ |  $$ |$$$$$$$$/ $$ |             __ ");
        mvwprintw(win, 9, 50, "$$$/    $$$ |$$ |$$ |  $$ |$$ |  $$ |$$       |$$ |            /  |");
        mvwprintw(win, 10, 50, "$$/      $$/ $$/ $$/   $$/ $$/   $$/  $$$$$$$/ $$/             $$/ ");
        refresh();
        usleep(15000);
    }
    for (len = 0; color_name[len]; len++)
        if (color[len] == instr->number) {
            attron(COLOR_PAIR(len + 1));
            break;
        }
    for (int i = 0; ascii[i]; i++)
        mvwprintw(stdscr, 18 + i, 80, "%s", ascii[i]);
    attroff(COLOR_PAIR(len + 1));
    mvwprintw(stdscr, 24, 160, "Cycle total : %d", cycle);
    mvwprintw(stdscr, 27, 90, "I say : \"%s\"", instr->comment);
    for (int i = 0, pos = 20, nb  = 0, j = 0; i != nb_on_start(0); i++, pos += 20 + 20) {
        WINDOW *t = newwin(25, 30, 30, pos);
        box(t, ACS_VLINE, ACS_HLINE);
        mvwprintw(t, 1, (30 - strlen(list[i]->prog_name)) / 2, "/%s\\", list[i]->prog_name);
        for (nb = 0, j = 0; prog_nb[j] != -1; j++)
            if (prog_nb[j] == list[i]->number)
                nb++;
        mvwprintw(t, 3, 1, "Size at the end : %d", nb);
        mvwprintw(t, 4, 1, "Live : %s", (list[i]->dead == true) ? "No" : "Yes");
        if (instr->number == list[i]->number)
            mvwprintw(t, 6, 10, "WINNER !");
        wrefresh(t);
    }
    refresh();
    sleep(15);
    endwin();
}

void display_ncurse(prog_t **instr, int *memory, int cycle, int nb_live, int to_die)
{
    static int k = 0;
    static int time = DELAY;
    static char **name;
    static int *color;
    int x = 0;
    int y = 1;
    int p = 0;
    int key = getch();
    int *prog_nb = prog_nbr();
    char *color_name[7] = {"RED", "GREEN", "BLUE", "YELLOW", "MAGENTA", "CYAN", NULL};
    WINDOW *win = subwin(stdscr, LINES, 55, 0, 155);
    WINDOW *border1 = subwin(stdscr, 1, 55, 6, 155);

    (k == 0) ? init_ncurse(), name = name_prog(instr), color = color_nb(instr),
    k++ : 0;
    if (key == KEY_LEFT && time > 0)
        time -= 100;
    if (key == KEY_RIGHT)
        time += 100;
    if (key == ' ')
        for (int temp = 0; key == ' ' && temp != ' '; temp = getch());
    if (key == 'd')
        time = (time == 100000) ? 800 : 100000;
    erase();
    box(win, ACS_VLINE, ACS_HLINE);
    box(border1, ACS_VLINE, ACS_HLINE);
    mvwprintw(win, 1, 5, "____  ___________   ______  _  _______ _______");
    mvwprintw(win, 2, 3, "_/ ___\\/  _ \\_  __ \\_/ __ \\ \\/ \\/ /\\__  \\_  __  \\");
    mvwprintw(win, 3, 3, "\\  \\__(  <_> )  | \\/\\  ___/\\     /  / __ \\|  | \\/");
    mvwprintw(win, 4, 3, " \\___  >____/|__|    \\___  >\\/\\_/  (____  /__|   ");
    mvwprintw(win, 5, 3, "     \\/                  \\/              \\/       ");
    mvwprintw(win, 8, 2, "Nb de cycle : [%d]", cycle);
    mvwprintw(win, 11, 2, "Live count :  [%d]", nb_live);
    mvwprintw(win, 12, 2, "Cycle to die : %d", to_die);
    mvwprintw(win, 13, 2, "Delay : %d ms", time);
    for (int j = 0, pos = 15; name[j]; j++, pos += 8) {
        mvwprintw(win, pos, 1, "=====================================================");
        mvwprintw(win, pos, 20, " Player %d ", instr[j]->number);
        mvwprintw(win, pos + 1, 2, "Name : %s", name[j]);
        mvwprintw(win, pos + 2, 2, (instr[j]->dead != true) ? "Live : Yes" : "Live No");
        mvwprintw(win, pos + 3, 2, "Size of the prog : %d", instr[j]->prog_size);
        for (int l = 0; color[l] != -1; l++)
            if (color[l] == instr[j]->number)
                mvwprintw(win, pos + 4, 2, "Color : %s", color_name[l]);
    }
    for (int i = 0; i != (3 * 1024); i++, x += 3) {
        if (x >= 156)
            (1) ? x = 0, y++ : 0;
        for (int j = 0; j != nb_of_programs(0); j++)
            if (instr[j]->pc == i && instr[j]->dead == false) {
                attron(A_STANDOUT | A_BOLD);
                break;
            }
        for (p = 0; color[p] != -1; p++)
            if (color[p] == prog_nb[i])
                attron(COLOR_PAIR(p + 1));
        mvwprintw(stdscr, y, x, "%02x", memory[i]);
        attroff(A_STANDOUT | A_BOLD | COLOR_PAIR(p + 1));
    }
    refresh();
    usleep(time);
}

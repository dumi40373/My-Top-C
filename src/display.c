/*
** EPITECH PROJECT, 2026
** bs
** File description:
** Process display functions for my_top
*/

#include "../include/my.h"
#include "../include/top.h"

void free_node(proc_t *process)
{
    proc_t *tmp;

    if (!process)
        return;
    while (process) {
        tmp = process;
        process = process->next;
        free(tmp);
    }
}

void get_full_bar(void)
{
    int max_y;
    int max_x;

    getmaxyx(stdscr, max_y, max_x);
    for (int i = 77; i <= max_x; i++)
        addch(' ');
}

void put_top_bar(void)
{
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    attron(COLOR_PAIR(1) | A_BOLD);
    mvprintw(6, 0, "%4s %9s %3s %3s %7s %7s %7s  %1s %5s %5s %10s %s",
        "PID", "USR", "PR", "NI", "VIRT", "RES", "SHR",
        "S", "%CPU", "%MEM", "TIME+", "COMMAND");
    get_full_bar();
    addch('\n');
    attroff(COLOR_PAIR(1) | A_BOLD);
}

int is_usr_verif(proc_t *process, flags_t *data)
{
    if (data->is_u) {
        if (!my_strcmp(data->username, process->usr))
            return 1;
    }
    return 0;
}

void put_node(proc_t *process, flags_t *data)
{
    for (int row = 7; process; process = process->next) {
        if (is_usr_verif(process, data))
            continue;
        mvprintw(row, 0,
            "%4d %9.9s %3d %3d %7s %7ld %7ld  %c %5.1f %5.1f %10s %s\n",
            process->pid, process->usr, process->pr, process->ni,
            format_memory(process->virt), process->res, process->shr,
            process->s, process->cpu, process->mem,
            format_time(process->time_plous), process->cmd);
        row++;
    }
}

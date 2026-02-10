/*
** EPITECH PROJECT, 2026
** bs
** File description:
** bs
*/

#include "../include/my.h"
#include "../include/top.h"

void calc_cpu(proc_t *new_proc, proc_t *old_proc)
{
    double delta_proc_ticks_val = delta_prock_ticks(new_proc->proc_ticks,
        old_proc->proc_ticks);
    double delta_wall = new_proc->cpu_timesec - old_proc->cpu_timesec;

    if (delta_wall > 0)
        new_proc->cpu = ((delta_proc_ticks_val / sysconf(_SC_CLK_TCK)) /
            delta_wall) * 100.0;
    else
        new_proc->cpu = 0.0;
}

void calc_process_cpu(proc_t *process, proc_t *old_process)
{
    proc_t *old_process_start = old_process;

    if (!process || !old_process)
        return;
    process->cpu = 0.0;
    while (old_process) {
        if (process->pid == old_process->pid) {
            calc_cpu(process, old_process);
            break;
        }
        old_process = old_process->next;
    }
    calc_process_cpu(process->next, old_process_start);
}

cpu_t header_loop(header_info_t *info, cpu_t *prev, cpu_t *cur,
    int first)
{
    cpu_t delta;

    put_header(info);
    put_cpu_header(prev, cur, &delta, first);
    put_mem_header(info);
    return delta;
}

static void initialize_ncurses(void)
{
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    use_default_colors();
    start_color();
}

static void handle_proc_disp(proc_t *process, flags_t *data)
{
    put_top_bar();
    put_node(process, data);
}

static int frames_verif(flags_t *data, int frames_count)
{
    if (data->is_n)
        if (frames_count == data->max_frames)
            return 1;
    return 0;
}

void main_loop(proc_t *process, header_info_t *info, flags_t *data)
{
    main_loop_t main = initialize_main();

    initialize_ncurses();
    for (int ch = 0; ch != 'q'; ch = getch()) {
        clear();
        header_loop(info, &main.prev, &main.cur, main.first);
        if (main.first)
            main.first = 0;
        init_struct(&process);
        calc_process_cpu(process, main.prev_proc);
        handle_proc_disp(process, data);
        free_node(main.prev_proc);
        main.prev_proc = process;
        main.frames_count++;
        if (frames_verif(data, main.frames_count))
            break;
        sleep(data->delay);
    }
    free_node(main.prev_proc);
    endwin();
}

int main(int argc, char **argv)
{
    proc_t *process = NULL;
    header_info_t info;
    flags_t data;

    data = initialize_flags();
    if (show_tag_top(argc, argv, &data))
        return 84;
    main_loop(process, &info, &data);
    return 0;
}

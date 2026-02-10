/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** get_header_cpu
*/

#include "../include/my.h"
#include "../include/top.h"

int read_cpu_inf(cpu_t *inf)
{
    FILE *file = fopen("/proc/stat", "r");
    char buffer[1024];

    fgets(buffer, sizeof(buffer), file);
    fclose(file);
    sscanf(buffer, "cpu  %llu %llu %llu %llu %llu %llu %llu %llu",
        &inf->user, &inf->nice, &inf->system, &inf->idle,
        &inf->iowait, &inf->irq, &inf->softirq, &inf->steal);
    inf->total = 0;
    return 0;
}

void compute_delta(cpu_t *delta, cpu_t *prev, cpu_t *cur)
{
    delta->user = cur->user - prev->user;
    delta->nice = cur->nice - prev->nice;
    delta->system = cur->system - prev->system;
    delta->idle = cur->idle - prev->idle;
    delta->iowait = cur->iowait - prev->iowait;
    delta->irq = cur->irq - prev->irq;
    delta->softirq = cur->softirq - prev->softirq;
    delta->steal = cur->steal - prev->steal;
}

void compute_total(cpu_t *delta)
{
    delta->total = delta->user + delta->idle + delta->iowait +
        delta->irq + delta->nice + delta->softirq + delta->steal +
        delta->system;
}

void put_percentage(cpu_t *delta)
{
    if (delta->total == 0)
        return;
    printw("%%Cpu(s): ");
    printw("%.1f us ", 100.0 * (double)delta->user / (double)delta->total);
    printw("%.1f sy ", 100.0 * (double)delta->system / (double)delta->total);
    printw("%.1f ni ", 100.0 * (double)delta->nice / (double)delta->total);
    printw("%.1f id ", 100.0 * (double)delta->idle / (double)delta->total);
    printw("%.1f wa ", 100.0 * (double)delta->iowait / (double)delta->total);
    printw("%.1f hi ", 100.0 * (double)delta->irq / (double)delta->total);
    printw("%.1f si ", 100.0 * (double)delta->softirq / (double)delta->total);
    printw("%.1f st\n", 100.0 * (double)delta->steal / (double)delta->total);
}

void put_cpu_header(cpu_t *prev, cpu_t *cur, cpu_t *delta, int first)
{
    read_cpu_inf(cur);
    if (first) {
        compute_total(cur);
        put_percentage(cur);
        *prev = *cur;
    } else {
        compute_delta(delta, prev, cur);
        compute_total(delta);
        put_percentage(delta);
        *prev = *cur;
    }
}

/*
** EPITECH PROJECT, 2025
** my_top
** File description:
** top.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Window/Window.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <math.h>
#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <sys/utsname.h>
#include <utmp.h>
#include <string.h>

#ifndef MY_TOP_H
    #define MY_TOP_H
    #define WIDHT 1920
    #define HEIGHT 1080

typedef struct proc_s {
    int pid;
    char *usr;
    int pr;
    int ni;
    double virt;
    double utime;
    double stime;
    double proc_ticks;
    double time_sec;
    double cpu_timesec;
    double cpu;
    long res;
    long shr;
    double mem;
    char s;
    char *cmd;
    long time_plous;
    struct proc_s *prev;
    struct proc_s *next;
} proc_t;
typedef struct flags_s {
    int is_u;
    char *username;
    double delay;
    int is_n;
    long max_frames;
    long frames_count;
} flags_t;
typedef struct proc_stat_s {
    int counter;
    int running;
    int sleeping;
    int stopped;
    int zombie;
} proc_stat_t;
typedef struct cpu_s {
    unsigned long long user, nice, system, idle,
    iowait, irq, softirq, steal, total;
} cpu_t;
typedef struct mem_s {
    double total, free, used, buff_cache;
} mem_t;
typedef struct swap_s {
    double total, free, used, avail_mem;
} swap_t;
typedef struct header_info_s {
    int hour;
    int min;
    int sec;
    long long up_sec;
    int up_min;
    int up_hours;
    int up_days;
    int nb_users;
    double *loadavg;
    proc_stat_t total_proc;
    mem_t memory;
    swap_t swap;
} header_info_t;
typedef struct main_loop_s {
    proc_t *prev_proc;
    cpu_t prev;
    cpu_t cur;
    int first;
    int frames_count;
} main_loop_t;
int handle_d(int i, char **argv, flags_t *data);
int handle_u(int i, char **argv, flags_t *data);
int handle_n(int i, char **argv, flags_t *data);
void free_all(char **tab);
flags_t initialize_flags(void);
proc_stat_t initialize_procstat(void);
void my_get_time_of_day(header_info_t *info);
int get_up_time(header_info_t *info);
void init_struct(proc_t **process);
int get_users_nb(header_info_t *info);
char *user_return(char *uid);
char *user_process(char *pid);
char **read_file(const char *path);
char **read_stat(const char *path);
void get_total_proc(header_info_t *info);
double read_mem_arg(char *line_name);
char *read_mem_line(char *word);
void free_node(proc_t *process);
void get_full_bar(void);
void put_top_bar(void);
void put_node(proc_t *process, flags_t *data);
int return_prio(char *pid);
int nice_val(char *pid);
double virt_val(char *pid);
long res_val(char *pid);
long shr_val(char *pid);
long utime_val(char *pid);
long stime_val(char *pid);
long ret_total_time(char *pid);
char return_status(char *pid);
char *return_cmd_name(char *pid);
double ret_mem(long res);
double calc_proc_ticks(double utime, double stime);
double delta_prock_ticks(double new_ticks, double old_ticks);
double cpu_time_sec(double proc_ticks);
void calc_cpu(proc_t *new_proc, proc_t *old_proc);
void calc_process_cpu(proc_t *process, proc_t *old_process);
int print_up_time(header_info_t *info);
void put_header(header_info_t *info);
int my_getloadavg(double loadavg[], int nelem);
void put_cpu_header(cpu_t *prev, cpu_t *cur, cpu_t *delta, int first);
void put_mem_info(header_info_t *info);
void put_mem_header(header_info_t *info);
void put_swap_info(header_info_t *info);
char *format_memory(double bytes);
char *format_time(long centiseconds);
int show_tag_top(int argc, char **argv, flags_t *data);
int handle_n(int i, char **argv, flags_t *data);
int handle_u(int i, char **argv, flags_t *data);
int handle_d(int i, char **argv, flags_t *data);
flags_t initialize_flags(void);
main_loop_t initialize_main(void);
#endif

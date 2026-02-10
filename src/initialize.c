/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** initialize
*/

#include "../include/my.h"
#include "../include/top.h"

flags_t initialize_flags(void)
{
    flags_t data = {
        .delay = 3.0,
        .frames_count = 0,
        .max_frames = 0,
        .username = NULL,
        .is_u = 0,
        .is_n = 0
    };

    return data;
}

main_loop_t initialize_main(void)
{
    main_loop_t data = {
        .first = 1,
        .frames_count = 0,
        .prev_proc = NULL
    };

    return data;
}

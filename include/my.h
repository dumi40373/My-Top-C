/*
** EPITECH PROJECT, 2025
** my.h_2
** File description:
** my.h_2
*/

#include <stdarg.h>
#include <ncurses.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>

#ifndef MY_H
    #define MY_H
struct arg_list {
    double nbr;
    char str[4];
    int expo;
};
struct float_list {
    char neg;
    long int entier;
    long int frac;
};
void my_putchar(char c);
long string_to_int(char *str);
int my_isneg(int nb);
int my_put_nbr(long int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char *str);
int my_compute_power_it(int nb, int p);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp2(char const *s1, char const *s2, int n);
int my_isnumeric(char nbr);
char *my_strcat(char *dest, char const *src);
char int_to_char(int nbr);
char *int_to_string(int nbr);
int my_nbrlen(long int nbr);
int my_pow(int nbr, int expo);
void my_putfloat(double nb);
int frac_cmpt(double nb);
void my_put_scientist(double nbr);
void my_put_scientist_upper(double nbr);
void my_printf(const char *str, ...);
char *decimal_to_hexa(int nb);
char decimal_to_hexa_char(int nb);
void handle_hexa(va_list ap);
void handle_nothing(va_list ap);
void handle_percent(va_list ap);
void handle_scientist_upper(va_list ap);
void handle_scientist(va_list ap);
void handle_float(va_list ap);
void handle_int(va_list ap);
void handle_str(va_list ap);
void handle_char(va_list ap);
void handle_pointer(va_list ap);
void my_putaddress(void *ptr);
void handle_unsigned(va_list ap);
void handle_shortest(va_list ap);
int my_put_unsigned_nbr(unsigned int nb);
struct arg_list my_return_scientist(double nbr);
struct float_list my_return_float(double nb);
long int zero_killer(int nb);
void my_shortest(double nb);
char *move_dot(double nb);
int find_exponent_int(double nb);
char *find_exponent_str(double nb);
char *find_mantissa(double nb);
char *float_to_hexa(char *binary);
void flag_a(double nb);
void handle_float_to_hexa(va_list ap);
char *decimal_to_hexa_upper(int nb);
void handle_hexa_upper(va_list ap);
int nb_to_left(const char *str, va_list arg);
int show_tag(const char *str, va_list args, int i);
int my_isalpha(char arg);
char **my_str_to_word_array(char const *str);
int my_str_in_ascii(char *str);
char *my_strncpy_nbr(char const *src, int n);
char *my_ctime(double nbr);
char **my_put_in_alphabet(char **argv);
char **my_str_to_word_array_delim(char const *str, char delim);
char int_to_char(int nbr);
int char_to_int(char c);
int my_str_isnumeric(char *str);

#endif

##
## EPITECH PROJECT, 2025
## day12
## File description:
## day12
##

CC		=	epiclang
CFLAGS		=	-g
CPPFLAGS	=	-Iinclude
LDFLAGS	=	-lncurses

NAME	=	my_top
SRC	=	src/main.c	\
		src/init_struct.c	\
		src/minors_funct.c	\
		src/user_process.c	\
		src/get_header_mem.c	\
		src/display.c \
		src/display_header.c \
		src/format.c \
		src/proc_values_sched.c \
		src/proc_values_mem.c \
		src/proc_values_time.c \
		src/proc_values_cmd.c \
		src/calc.c \
		src/header_utils.c	\
		src/get_up_time.c	\
		src/total_proc.c	\
		src/get_header_cpu.c	\
		src/show_tag_top.c	\
		src/handle_flags.c	\
		src/initialize.c	\

OBJ	=	$(SRC:src/%.c=%.o)

all: library $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(OBJ) lib/my/libmy.a $(LDFLAGS) $(CFLAGS)

$(OBJ): %.o: src/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

library:
	$(MAKE) -C lib/my all

clean:
	rm -f $(OBJ)
	$(MAKE) -C lib/my clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C lib/my fclean

re: fclean all

.PHONY: all clean fclean re library
##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

SRC	=	output.c	\
		string_len_cmp.c	\
		string_copy.c	\
		string_manip.c	\
		string_utils.c	\
		conversion.c	\
		math.c	\
		check.c	\
		utils.c	\
		my_printf.c	\
		hexadecimal_convert.c	\
		hexadecimal_convert_char.c	\
		hexadecimal_convert_upper.c	\
		handle_char.c	\
		handle_str.c	\
		handle_int.c	\
		handle_float.c	\
		handle_scientist.c	\
		handle_scientist_upper.c	\
		handle_percent.c	\
		handle_hexa.c	\
		handle_hexa_upper.c	\
		handle_nothing.c	\
		handle_pointer.c	\
		handle_unsigned.c	\
		handle_shortest.c	\
		handle_float_to_hexa.c	\
		my_find_pointer_address.c	\
		my_put_scientist.c	\
		my_put_scientist_upper.c	\
		my_retscientist.c	\
		my_retfloat.c	\
		zero_killer.c	\
		my_shortest.c	\
		float_to_binary.c	\
		float_to_hexa.c	\
		flag_a.c	\
		frac_cmpt.c	\
	nb_to_left.c	\
	show_tag.c	\
	my_str_to_word_array.c	\
	my_str_to_word_array_delim.c	\
	multiple_word_cmpt.c	\

OBJ	=	$(SRC:.c=.o)

all: exe

exe: $(OBJ)
	ar rc libmy.a $(OBJ)
	cp my.h ../../include/

$(OBJ): $(SRC)
	epiclang -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libmy.a

re: fclean all
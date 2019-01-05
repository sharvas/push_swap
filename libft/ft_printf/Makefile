# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 14:34:39 by dfinnis           #+#    #+#              #
#    Updated: 2018/12/08 14:34:43 by dfinnis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
		initialize.c \
		parse_flags_width.c \
		parse_precision.c \
		parse_length.c \
		parse_type.c \
		read_numbers.c \
		read_floats.c \
		read_others.c \
		build_precision.c \
		build_width.c \
		build_prefix.c \
		build_float.c \
		error_protection.c \
		binary.c

LIBO = ../ft_isdigit.o \
		../ft_itoa_base.o \
		../ft_itoa_intmax.o \
		../ft_itoa_unsigned.o \
		../ft_putchar.o \
		../ft_putstr.o \
		../ft_strchr.o \
		../ft_strdup.o \
		../ft_strndup.o \
		../ft_strjoin.o \
		../ft_strlen.o \
		../ft_strcat.o \
		../ft_strcpy.o \
		../ft_strnew.o \
		../ft_bzero.o \
		../ft_memset.o \
		../ft_strjoinfree.o \
		../ft_strjoinfree_s1.o \
		../ft_strjoinfree_s2.o

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

HEADER = -I ../

INC = ft_printf.h

LIB = -L ../ -lft

all: lib $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) $(LIBO)
	@ranlib $(NAME)

$(OBJ): $(SRCS)
	@gcc -c $(FLAGS) $(SRCS) -I $(INC)

lib: 
	@make -C ../ all

libfclean:
	@make -C ../ fclean

libclean:
	@make -C ../ clean

clean: libclean
	@/bin/rm -f $(OBJ)

fclean: clean libfclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re

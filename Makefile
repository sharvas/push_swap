# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/05 14:18:51 by dfinnis           #+#    #+#              #
#    Updated: 2019/01/06 13:37:33 by svaskeli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
NAME = $(PUSH_SWAP) $(CHECKER)

FLAGS = -Wall -Werror -Wextra

PS_SRCS_DIR = srcs/push_swap/
CH_SRCS_DIR = srcs/checker/
SH_SRCS_DIR = srcs/shared/
SRCS_DIRS = $(PS_SRCS_DIR) $(CH_SRCS_DIR) $(SH_SRCS_DIR)

OBJS_DIR = objs/
SRCS_DIR = srcs/

LIBFT = libft
LIBFT_A = $(LIBFT)/libft.a

PS_SRCS = push_swap.c ps_functions.c ps_find_refs.c ps_sort_pb.c \
	ps_sort_pa.c ps_sort_small.c

CH_SRCS = checker.c checker_functions.c visualizer.c visualizer_colour.c

SH_SRCS = stack.c stack_overflow.c do_push_swap.c do_rotate.c do_comb.c \
	error.c error_null.c

PS_OBJS = $(PS_SRCS:%.c=%.o)
CH_OBJS = $(CH_SRCS:%.c=%.o)
SH_OBJS = $(SH_SRCS:%.c=%.o)
OBJS = $(PS_OBJS) $(CH_OBJS) $(SH_OBJS)

PS_SRCS_PATH = $(PS_SRCS:%=$(PS_SRCS_DIR)%)
CH_SRCS_PATH = $(CH_SRCS:%=$(CH_SRCS_DIR)%)
SH_SRCS_PATH = $(SH_SRCS:%=$(SH_SRCS_DIR)%)
SRCS_PATH = $(PS_SRCS_PATH) $(CH_SRCS_PATH) $(SH_SRCS_PATH)

PS_OBJS_PATH = $(addprefix $(OBJS_DIR), $(PS_OBJS))
CH_OBJS_PATH = $(addprefix $(OBJS_DIR), $(CH_OBJS))
SH_OBJS_PATH = $(addprefix $(OBJS_DIR), $(SH_OBJS))
OBJS_PATH = $(PS_OBJS_PATH) $(CH_OBJS_PATH) $(SH_OBJS_PATH)

GREEN = "\033[0;32m"
DEFAULT = "\033[0m"

all: $(NAME)

norm:
	norminette -R CheckForbiddenSourceHeader $(INC) $(SRCS_DIR)

$(NAME): $(LIBFT_A) $(OBJS_DIR)
	@echo "Compiling:" $(GREEN) $(NAME) $(DEFAULT)
	gcc $(FLAGS) $(PS_OBJS_PATH) $(SH_OBJS_PATH) $(LIBFT_A) -o $(PUSH_SWAP) -I $(LIBFT)
	gcc $(FLAGS) $(CH_OBJS_PATH) $(SH_OBJS_PATH) $(LIBFT_A) -o $(CHECKER) -I $(LIBFT)

$(LIBFT_A):
	@echo "Compiling:" $(GREEN) Libft $(DEFAULT)
	@make -C $(LIBFT)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	gcc $(FLAGS) -c $(SRCS_PATH)
	@mv $(OBJS) $(OBJS_DIR)

clean:
	@make -C $(LIBFT)/ clean
	@rm -rf $(OBJS_DIR)

fclean:
	@make -C $(LIBFT)/ fclean
	@rm -rf $(OBJS_DIR) $(NAME)

re: fclean all

.PHONY: all norm clean fclean re

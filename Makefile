# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/05 14:18:51 by dfinnis           #+#    #+#              #
#    Updated: 2019/01/05 17:39:24 by svaskeli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
NAME = $(PUSH_SWAP) $(CHECKER)

FLAGS = -Wall -Werror -Wextra

PS_SRC_DIR = srcs/push_swap/
CH_SRC_DIR = srcs/checker/
SH_SRC_DIR = srcs/shared/
SRC_DIR = $(PS_SRC_DIR) $(CH_SRC_DIR) $(SH_SRC_DIR)

OBJS_DIR = objs/
SRCS_DIR = srcs/

INC = includes/
#INCLUDE_DIRS =	-I $(INC)

LIBFT = libft
LIBFT_A = $(LIBFT)/libft.a

PS_SRC = push_swap.c ps_functions.c ps_find_refs.c ps_algo.c \
	ps_sort_small.c ps_pushback.c

CH_SRC = checker.c checker_functions.c visualizer.c visualizer_colour.c

SH_SRC = stack.c stack_overflow.c do_push_swap.c do_rotate.c do_comb.c \
	error.c error_null.c

PS_OBJ = $(PS_SRC:%.c=%.o)
CH_OBJ = $(CH_SRC:%.c=%.o)
SH_OBJ = $(SH_SRC:%.c=%.o)
OBJ = $(PS_OBJ) $(CH_OBJ) $(SH_OBJ)

PS_SRC_PATH = $(PS_SRC:%=$(PS_SRC_DIR)%)
CH_SRC_PATH = $(CH_SRC:%=$(CH_SRC_DIR)%)
SH_SRC_PATH = $(SH_SRC:%=$(SH_SRC_DIR)%)
SRC_PATH = $(PS_SRC_PATH) $(CH_SRC_PATH) $(SH_SRC_PATH)

PS_OBJ_PATH = $(addprefix $(OBJ_DIR), $(PS_OBJ))
CH_OBJ_PATH = $(addprefix $(OBJ_DIR), $(CH_OBJ))
SH_OBJ_PATH = $(addprefix $(OBJ_DIR), $(SH_OBJ))
OBJ_PATH = $(PS_OBJ_PATH) $(CH_OBJ_PATH) $(SH_OBJ_PATH)

GREEN = "\033[0;32m"
DEFAULT = "\033[0m"

all: $(NAME)

norm:
	@norminette $(INC) $(SRCS_DIR)

$(LIBFT_A):
	@echo "Libft:" $(GREEN) Compiling Libft $(DEFAULT)
	@make -C $(LIBFT)

$(COMP):
	@gcc $(FLAGS) -c $(SRC_PATH) -o $(OBJS_DIR)

$(NAME): $(LIBFT_A) $(OBJS_DIR) $(OBJ_PATH) $(COMP)
	@echo "Push_swap:" $(GREEN) $(NAME) $(DEFAULT)
	gcc $(FLAGS) $(PS_OBJ_PATH) $(SH_OBJ_PATH) $(LIBFT_A) -o $(PUSH_SWAP) -I $(LIBFT)
	gcc $(FLAGS) $(CH_OBJ_PATH) $(SH_OBJ_PATH) $(LIBFT_A) -o $(CHECKER) -I $(LIBFT)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "Push_swap:" $(GREEN) $< $(DEFAULT)
	@gcc $(FLAGS) -c $< -o $@ -I $(LIBFT)

clean:
	@make -C $(LIBFT)/ clean
	@rm -rf $(OBJS_DIR)

fclean:
	@make -C $(LIBFT)/ fclean
	@rm -rf $(OBJS_DIR) $(NAME)

re: fclean all

.PHONY: all norm clean fclean re

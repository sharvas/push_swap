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

PUSH_SWAP =		push_swap
CHECKER =		checker
INC =			includes/
NAME =			$(PUSH_SWAP) $(CHECKER)

FLAGS =			-Wall -Werror -Wextra
COMP =			gcc $(FLAGS) -I $(INC) -I libft/ -I libft/libft -c -o

LIBFT_A = 		libft.a

PS_SRC_DIR =	srcs/push_swap/
C_SRC_DIR =		srcs/checker/
S_SRC_DIR =		srcs/shared/
LIBFT =			libft/

PS_SRC =		push_swap.c \
				ps_functions.c \
				ps_find_refs.c \
				ps_algo.c \
				ps_sort_small.c \
				ps_pushback.c \

C_SRC =			checker.c \
				checker_functions.c \
				visualizer.c \
				visualizer_colour.c

S_SRC =			stack.c \
				stack_overflow.c \
				do_push_swap.c \
				do_rotate.c \
				do_comb.c \
				error.c \
				error_null.c

PS_OBJ =		$(PS_SRC:%.c=%.o)
C_OBJ =			$(C_SRC:%.c=%.o)
S_OBJ =			$(S_SRC:%.c=%.o)
OBJ =			$(PS_OBJ) $(C_OBJ) $(S_OBJ)

PS_SRC_PATH =	$(PS_SRC:%=$(PS_SRC_DIR)%)
C_SRC_PATH =	$(C_SRC:%=$(C_SRC_DIR)%)
S_SRC_PATH =	$(S_SRC:%=$(S_SRC_DIR)%)
SRC_PATH =		$(PS_SRC_PATH) $(C_SRC_PATH) $(S_SRC_PATH)

PS_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(PS_OBJ))
C_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(C_OBJ))
S_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(S_OBJ))
OBJ_PATH =		$(PS_OBJ_PATH) $(C_OBJ_PATH) $(S_OBJ_PATH)


all:			do_libft $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

$(NAME):		$(OBJ_PATH)
				gcc $(FLAGS) $(PS_OBJ_PATH) $(S_OBJ_PATH) libft.a -o push_swap \
					-I $(INC) -I libft/
				gcc $(FLAGS) $(C_OBJ_PATH) $(S_OBJ_PATH) libft.a -o checker \
					-I $(INC) -I libft/

#$(obj/123/%.o): $(src/123/%.c)
#	gcc $< 


#$(PS_OBJ_PATH):	$(PS_SRC_PATH)
#				@$(MAKE) $(PS_OBJ)
#$(C_OBJ_PATH):	$(C_SRC_PATH)
#				@$(MAKE) $(C_OBJ)
#$(S_OBJ_PATH):	$(S_SRC_PATH)
#				@$(MAKE) $(S_OBJ)

$(PS_OBJ):		$(LIBFT_A)
				@$(COMP) $(OBJ_DIR)$@ $(PS_SRC_DIR)$(@:%.o=%.c)
$(C_OBJ):		$(LIBFT_A)
				@$(COMP) $(OBJ_DIR)$@ $(C_SRC_DIR)$(@:%.o=%.c)
$(S_OBJ):		$(LIBFT_A)
				@$(COMP) $(OBJ_DIR)$@ $(S_SRC_DIR)$(@:%.o=%.c)

do_libft:
				make -C $(LIBFT)
				cp $(LIBFT)/$(LIBFT_A) .

clean:
				/bin/rm -rf $(OBJ_DIR) $(LIBFT_A)
				make -C $(LIBFT) clean

fclean: clean
				/bin/rm -f $(NAME) $(LIBFT_A)
				make -C $(LIBFT) fclean

re: 			fclean all

.PHONY:			all clean fclean re


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:03:15 by svaskeli          #+#    #+#             */
/*   Updated: 2019/03/03 17:03:17 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_stack
{
	int				n;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_all
{
	struct s_stack	*a;
	struct s_stack	*b;
	struct s_stack	*cpy;
	char			**array;
	int				len;
	int				min;
	int				max;
	int				a_third;
	int				b_third;
	int				a_seven;
	int				b_seven;
	int				c_seven;
	int				d_seven;
	int				e_seven;
	int				f_seven;
	int				write_instructions;
	char			*instructions;
	int				v;
	int				c;
	int				t;
	char			*f;
	int				fd;
}					t_all;

typedef struct		s_flags
{
	int				a;
	int				b;
	int				row;
}					t_flags;

/*
**		push_swap.c
*/
void				ft_push_swap_usage(void);
void				ft_push_swap(char **av);
int					main(int ac, char **av);

/*
**		ps_functions.c
*/
void				ft_read_args_ps(t_all *all, char **argv);
int					ft_is_verbose(char *instructions);
void				ft_condense_verbose(t_all *all);
void				ft_find_replace(t_all *all, char *find, char *replace);
void				ft_putfile(t_all *all);

/*
**		ps_find_refs.c
*/
void				ft_find_refs(t_all *all);
int					ft_find_ref(t_stack *cpy, int count);
t_stack				*ft_dublicate_list(t_all *all);
t_stack				*add_link(t_stack *cpy, int n, t_all *all);
void				ft_simple_sort(t_stack *cpy);

/*
**		ps_sort_pb.c
*/
int					ft_sort_module(t_all *all, int size, int start, int end);
void				ft_sort_100(t_all *all);
void				ft_sort_big(t_all *all);
void				ft_sort_algo_switch(t_all *all);

/*
**		ps_sort_pa.c
*/
void				ft_rotate_direction(t_all *all, int num, int direction);
int					ft_up_down(t_all *all, int num);
int					ft_min_max(t_all *all, int max, int min);
void				ft_pushback(t_all *all, int min_max);
void				ft_pa_sort(t_all *all);

/*
**		ps_sort_small.c
*/
void				ft_sort_3(t_all *all, char stack);
void				ft_sort_4(t_all *all);
void				ft_rotate_small(t_all *all, int min);
void				ft_sort_5(t_all *all);
void				ft_sort_small(t_all *all);

/*
**		checker.c
*/
void				ft_checker_usage(void);
void				ft_checker(char **argv);
int					main(int argc, char **argv);

/*
**		checker_functions.c
*/
void				ft_read_args_checker(t_all *all, char **argv);
void				ft_open_file(t_all *all, char **argv, int i);
void				ft_read_do(char *line, t_all *all);
t_all				*ft_do_ops(t_all *all);
void				ft_ko_ok(t_all *all);

/*
**		stack.c
*/
void				ft_fill_a(t_all *all, char **argv, int i);
void				ft_fill_error(t_all *all, char *str);
void				ft_add_end(t_all *all, int n);
void				ft_add_top(t_all *all, char stack, int n);
void				ft_del_top(t_all *all, char stack);

/*
**		stack_overflow.c
*/
t_all				*ft_initialize(t_all *all);
int					ft_find_len(t_all *all, char stack);
int					ft_find_min(t_all *all, char stack);
int					ft_find_max(t_all *all, char stack);
int					ft_is_sorted(t_all *all, char stack);

/*
**		do_push_swap.c
*/
void				ft_pa(t_all *all);
void				ft_pb(t_all *all);
void				ft_sa(t_all *all);
void				ft_sb(t_all *all);

/*
**		do_rotate.c
*/
void				ft_ra(t_all *all);
void				ft_rb(t_all *all);
void				ft_rra(t_all *all);
void				ft_rrb(t_all *all);

/*
**		do_comb.c
*/
void				ft_ss(t_all *all);
void				ft_rr(t_all *all);
void				ft_rrr(t_all *all);

/*
**		error.c
*/
void				ft_ps_error(t_all *all);
int					ft_atoi_error(char *str, t_all *all);
int					ft_is_duplicate(t_all *all, intmax_t n);
void				ft_free_stack(t_stack *stack);
void				ft_free_all(t_all *all);

/*
**		error_null.c
*/
char				*ft_ps_strdup_empty(t_all *all);
char				*ft_strjoinfree_s1_ps(t_all *all, char *s2);

/*
**		visualizer.c
*/
int					ft_is_bonus(char *str);
t_flags				ft_initialize_flags(t_flags *flags);
void				ft_print_row(t_stack *s_a, t_stack *s_b, t_flags *flags);
void				ft_debug_v(t_all *all, char *str);

/*
**		visualizer_colour.c
*/
void				ft_print_row_ca(t_stack *s_a, t_stack *s_b, t_flags *flags);
void				ft_print_row_cb(t_stack *s_a, t_stack *s_b, t_flags *flags);
void				ft_print_row_cab(t_stack *s_a, t_stack *s_b,
					t_flags *flags);
void				ft_debug_c_print(t_stack *s_a, t_stack *s_b, t_flags flags,
					char *str);
void				ft_debug_c(t_all *all, char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:04:33 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/30 18:48:10 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "unistd.h"
# include "stdio.h" // rm, just for testing

typedef struct		s_stack
{
	int				n;
	struct s_stack	*next;
	struct s_stack	*prev;
//	int				top;
}					t_stack;

typedef struct		s_all
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				v;
	int				c;
	int				min;
	int				qu;
	int				median;
	int				three_qu;
	int				max;
	int				len;
	int				display;
}					t_all;

typedef struct		s_flags
{
	int				a;
	int				b;
	int				row;
}					t_flags;

/*
**		checker.c
*/
void	ft_read_do(char *line, t_all *all);
t_all	*ft_do_ops(t_all *all);
void	ft_checker(char **argv);
int		main(int argc, char **argv);

/*
**		push_swap_v2.c 
*/// correct to no v2
void	ft_setmax_b(t_all *all, int if_rotate);
int		ft_isleft(t_all *all, char c);

int		ft_find_min(t_all *all, char stack);
int		ft_find_max(t_all *all, char stack);

void	ft_rotate_direction(t_all *all, int max);
void	ft_pa_sort(t_all *all);
void	ft_sort_v2(t_all *all);
void	ft_sort_algo_switch(t_all *all);
void	ft_push_swap(char **av);

/*
**		sort.c
*/
int		ft_find_len(t_all *all, char c);
void	ft_simple_sort(t_stack *cpy);
void	ft_find_ref(t_all *all);
void	ft_ko_ok(t_all *all);
int		ft_is_sorted(t_all *all, char c);

/*
**		solve_small.c
*/
void	ft_sort_3(t_all *all);
void	ft_sort_4(t_all *all);
void	ft_sort_5(t_all *all);
void	ft_sort_small(t_all *all);

/*
**		do_push_swap.c
*/
void	ft_sa(t_all *all);
void	ft_sb(t_all *all);
void	ft_pa(t_all *all);
void	ft_pb(t_all *all);

/*
**		do_rotate.c
*/
void	ft_ra(t_all *all);
void	ft_rb(t_all *all);
void	ft_rra(t_all *all);
void	ft_rrb(t_all *all);

/*
**		do_comb.c
*/
void	ft_ss(t_all *all);
void	ft_rr(t_all *all);
void	ft_rrr(t_all *all);

/*
**		error.c
*/
void	ft_error(/*t_all *all*/);
int		ft_atoi_error(char *str);
int 	ft_is_duplicate(t_all *all, intmax_t n);

/*
**		stack.c
*/
t_all	*ft_initialize(t_all *all);
void	ft_fill_error(t_all *all, char *str);
void	ft_fill_a(t_all *all, char **argv);
void	ft_add_end(t_all *all, int n);
void	ft_add_top(t_all *all, char stack, int n);
void	ft_del_top(t_all *all, char stack);

/*
**		bonus.c
*/
int		ft_is_bonus(char *str);
void	ft_push_swap_usage(void);
void	ft_checker_usage(void);

/*
**		bonus_c.c
*/
void	ft_print_row_ca(t_stack *s_a, t_stack *s_b, t_flags *flags);
void	ft_print_row_cb(t_stack *s_a, t_stack *s_b, t_flags *flags);
void	ft_print_row_cab(t_stack *s_a, t_stack *s_b, t_flags *flags);
void	ft_debug_c_print(t_stack *s_a, t_stack *s_b, t_flags flags, char *str);
void	ft_debug_c(t_all *all, char *str);

/*
**		bonus_v.c
*/
t_flags	ft_initialize_flags(t_flags *flags);
void	ft_print_row(t_stack *s_a, t_stack *s_b, t_flags *flags);
void	ft_debug_v(t_all *all, char *str);

#endif

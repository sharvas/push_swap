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

/*
**		checker.c
*/
t_all	*ft_do_ops(t_all *all);
void	ft_checker(char **argv);
int		main(int argc, char **argv);

/*
**		sort.c
*/
int		ft_find_len(t_all *all, char c);
void	ft_simple_sort(t_stack *cpy);
void	ft_find_ref(t_all *all);
void	ft_ko_ok(t_all *all);
int		ft_is_sorted(t_all *all);

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
void	ft_print_row(t_stack *stack_a, t_stack *stack_b, int flag_a, int flag_b);
void	ft_debug_v(t_all *all, char *str);
void	ft_debug_c(t_all *all, char *str);
void	ft_push_swap_usage(void);
void	ft_checker_usage(void);
int		ft_is_bonus(char *str);

#endif

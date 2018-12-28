/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:04:33 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/22 15:04:35 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "unistd.h"
# include "stdio.h" // rm, just fpr testing

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
	int				v;
	long long 		mean;
	int				min;
	int				max;
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
void	ft_find_mean(t_all *all);

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
void	ft_fill_a(t_all *all, char **argv);

void	ft_add_end(t_all *all, int n);
void	ft_add_top(t_all *all, char stack, int n);
void	ft_del_top(t_all *all, char stack);

void	ft_ko_ok(t_all *all);
int		ft_is_sorted(t_all *all);

/*
**		bonus.c
*/
void	ft_debug_v(t_all *all);

#endif

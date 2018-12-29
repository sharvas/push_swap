/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 09:41:50 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/29 10:28:57 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_all *all)
{
	ft_sa(all);
	ft_sb(all);
	ft_putstr("ss\n");
}

void	ft_rr(t_all *all)
{
	ft_ra(all);
	ft_rb(all);
	ft_putstr("rr\n");
}

void	ft_rrr(t_all *all)
{
	ft_rra(all);
	ft_rrb(all);
	ft_putstr("rrr\n");
}

void	ft_sa(t_all *all)
{
	int	tmp;

	if (all->a && all->a->next != all->a)
	{
		tmp = all->a->n;
		all->a->n = all->a->next->n;
		all->a->next->n = tmp;
	}
	ft_putstr("sa\n");
}

void	ft_sb(t_all *all)
{
	int	tmp;

	if (all->b && all->b->next != all->b)
	{
		tmp = all->b->n;
		all->b->n = all->b->next->n;
		all->b->next->n = tmp;
	}
	ft_putstr("sb\n");
}

void	ft_pa(t_all *all)
{
	if (all->b)
	{
		ft_add_top(all, 'a', all->b->n);
		ft_del_top(all, 'b');
	}
	ft_putstr("pa\n");
}

void	ft_pb(t_all *all)
{
	if (all->a)
	{
		ft_add_top(all, 'b', all->a->n);
		ft_del_top(all, 'a');
	}
	ft_putstr("pb\n");
}

void	ft_ra(t_all *all)
{
	if (all->a)
		all->a = all->a->next;
	ft_putstr("ra\n");
}

void	ft_rb(t_all *all)
{
	if (all->b)
		all->b = all->b->next;
	ft_putstr("rb\n");
}

void	ft_rra(t_all *all)
{
	if (all->a)
		all->a = all->a->prev;
	ft_putstr("rra\n");
}

void	ft_rrb(t_all *all)
{
	if (all->b)
		all->b = all->b->prev;
	ft_putstr("rrb\n");
}

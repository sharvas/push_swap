/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:37:52 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/26 15:37:53 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_all *all)
{
	int	tmp;

	if (all->a && all->a->next != all->a)
	{
		tmp = all->a->n;
		all->a->n = all->a->next->n;
		all->a->next->n = tmp;
	}
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
}

void	ft_pa(t_all *all)
{
	if (all->b)
	{
		ft_add_top(all, 'a', all->b->n);
		ft_del_top(all, 'b');
	}
}

void	ft_pb(t_all *all)
{
	if (all->a)
	{
		ft_add_top(all, 'b', all->a->n);
		ft_del_top(all, 'a');
	}
}

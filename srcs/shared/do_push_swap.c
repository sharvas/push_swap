/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:10:22 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/07 10:10:23 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_pa(t_all *all)
{
	if (all->b)
	{
		ft_add_top(all, 'a', all->b->n);
		ft_del_top(all, 'b');
	}
	if (all->write_instructions)
		all->instructions = ft_strjoinfree_s1_ps(all, "pa\n");
}

void	ft_pb(t_all *all)
{
	if (all->a)
	{
		ft_add_top(all, 'b', all->a->n);
		ft_del_top(all, 'a');
	}
	if (all->write_instructions)
		all->instructions = ft_strjoinfree_s1_ps(all, "pb\n");
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
	if (all->write_instructions)
		all->instructions = ft_strjoinfree_s1_ps(all, "sa\n");
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
	if (all->write_instructions)
		all->instructions = ft_strjoinfree_s1_ps(all, "sb\n");
}

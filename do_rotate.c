/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:37:15 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/26 15:37:16 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_all *all)
{
	if (all->a)
		all->a = all->a->next;
	if (all->display)
		ft_putstr("ra\n");
}

void	ft_rb(t_all *all)
{
	if (all->b)
		all->b = all->b->next;
	if (all->display)
		ft_putstr("rb\n");
}

void	ft_rra(t_all *all)
{
	if (all->a)
		all->a = all->a->prev;
	if (all->display)
		ft_putstr("rra\n");
}

void	ft_rrb(t_all *all)
{
	if (all->b)
		all->b = all->b->prev;
	if (all->display)
		ft_putstr("rrb\n");
}

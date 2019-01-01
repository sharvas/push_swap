/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:37:15 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/01 16:20:10 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_all *all)
{
	t_stack *last;
	t_stack	*tmp;

	last = all->a;
	while (last->next != NULL)
		last = last->next;
	if (all->a)
	{
		tmp = all->a->next;
		tmp->next = all->a->next->next;
		tmp->prev = NULL;
		last->next = all->a;
		all->a->prev = last;
		all->a->next = NULL;
		all->a = tmp;
	}
	if (all->display)
		ft_putstr("ra\n");
}

void	ft_rb(t_all *all)
{
	t_stack *last;
	t_stack	*tmp;

	last = all->b;
	while (last->next != NULL)
		last = last->next;
	if (all->b)
	{
		tmp = all->b->next;
		tmp->next = all->b->next->next;
		tmp->prev = NULL;
		last->next = all->b;
		all->b->prev = last;
		all->b->next = NULL;
		all->b = tmp;
	}
	if (all->display)
		ft_putstr("rb\n");
}

void	ft_rra(t_all *all)
{
	t_stack *last;

	last = all->a;
	while (last->next != NULL)
		last = last->next;
	if (all->a)
	{
		all->a->prev = last;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = all->a;
		all->a = last;
	}
	if (all->display)
		ft_putstr("rra\n");
}

void	ft_rrb(t_all *all)
{
	t_stack *last;

	last = all->b;
	while (last->next != NULL)
		last = last->next;
	if (all->b)
	{
		all->b->prev = last;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = all->b;
		all->b = last;
	}
	if (all->display)
		ft_putstr("rrb\n");
}

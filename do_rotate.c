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

# include "push_swap.h"

void	ft_ra(t_all *all)
{
	if (all->a)
		all->a = all->a->next;
}

void	ft_rb(t_all *all)
{
	if (all->b)
		all->b = all->b->next;
}

void	ft_rra(t_all *all)
{
	if (all->a)
	all->a = all->a->prev;
}

void	ft_rrb(t_all *all)
{
	if (all->b)
		all->b = all->b->prev;
}

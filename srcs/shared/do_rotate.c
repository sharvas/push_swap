/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:35:53 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/06 17:35:55 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_ra(t_all *all)
{
	if (all->a)
		all->a = all->a->next;
	if (all->write_instructions)
		all->instructions = ft_strjoinfree_s1_ps(all, "ra\n");
}

void	ft_rb(t_all *all)
{
	if (all->b)
		all->b = all->b->next;
	if (all->write_instructions)
		all->instructions = ft_strjoinfree_s1_ps(all, "rb\n");
}

void	ft_rra(t_all *all)
{
	if (all->a)
		all->a = all->a->prev;
	if (all->write_instructions)
		all->instructions = ft_strjoinfree_s1_ps(all, "rra\n");
}

void	ft_rrb(t_all *all)
{
	if (all->b)
		all->b = all->b->prev;
	if (all->write_instructions)
		all->instructions = ft_strjoinfree_s1_ps(all, "rrb\n");
}

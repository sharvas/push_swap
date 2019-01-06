/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:37:15 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/05 15:29:17 by svaskeli         ###   ########.fr       */
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

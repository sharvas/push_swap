/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_comb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:10:15 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/07 10:10:18 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_ss(t_all *all)
{
	int	write;

	write = 0;
	if (all->write_instructions)
	{
		all->instructions = ft_strjoinfree_s1_ps(all, "ss\n");
		write = 1;
		all->write_instructions = 0;
	}
	ft_sa(all);
	ft_sb(all);
	if (write)
		all->write_instructions = 1;
}

void	ft_rr(t_all *all)
{
	int	write;

	write = 0;
	if (all->write_instructions)
	{
		all->instructions = ft_strjoinfree_s1_ps(all, "rr\n");
		write = 1;
		all->write_instructions = 0;
	}
	ft_ra(all);
	ft_rb(all);
	if (write)
		all->write_instructions = 1;
}

void	ft_rrr(t_all *all)
{
	int	write;

	write = 0;
	if (all->write_instructions)
	{
		all->instructions = ft_strjoinfree_s1_ps(all, "rrr\n");
		write = 1;
		all->write_instructions = 0;
	}
	ft_rra(all);
	ft_rrb(all);
	if (write)
		all->write_instructions = 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_comb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:05:08 by svaskeli          #+#    #+#             */
/*   Updated: 2019/03/03 17:05:10 by svaskeli         ###   ########.fr       */
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

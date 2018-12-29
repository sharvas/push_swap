/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_comb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:39:00 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/26 15:39:01 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_all *all)
{
	int	check;

	check = 0;
	if (all->display)
	{
		ft_putstr("ss\n");
		check = 1;
		all->display = 0;

	}
	ft_sa(all);
	ft_sb(all);
	if (check)
		all->display = 1;
}

void	ft_rr(t_all *all)
{
	int	check;

	check = 0;
	if (all->display)
	{
		ft_putstr("rr\n");
		check = 1;
		all->display = 0;
	}
	ft_ra(all);
	ft_rb(all);
	if (check)
		all->display = 1;
}

void	ft_rrr(t_all *all)
{
	int	check;

	check = 0;
	if (all->display)
	{
		ft_putstr("rrr\n");
		check = 1;
		all->display = 0;
	}
	ft_rra(all);
	ft_rrb(all);
	if (check)
		all->display = 1;
}

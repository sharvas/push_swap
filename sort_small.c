/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 16:51:04 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/01 16:51:06 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_all *all)
{
	int	min;
	int	max;

	min = ft_find_min(all, 'a');
	max = ft_find_max(all, 'a');	
	if (all->a->n == min)
	{
		ft_sa(all);
		ft_ra(all);
	}
	else if (all->a->n == max)
	{
		ft_ra(all);
		if (!ft_is_sorted(all, 'a'))
			ft_sa(all);
	}
	else
	{
		if (all->a->next->n == max)
			ft_rra(all);
		else
			ft_sa(all);
	}
}

void	ft_sort_4(t_all *all)
{
	while (all->a->n != all->min)
		ft_ra(all);
	ft_pb(all);
	ft_sort_3(all);
	ft_pa(all);
}

void	ft_sort_5(t_all *all)
{
	while (ft_find_len(all, 'b') < 2)
	{
		if (all->a->n < all->median)
			ft_pb(all);
		else
			ft_ra(all);
	}
	ft_sort_3(all);
	ft_pa(all);
	ft_pa(all);
	if (!ft_is_sorted(all, 'a'))
		ft_sa(all);
}

void	ft_sort_small(t_all *all)
{
	if (ft_find_len(all, 'a') == 2)
		ft_sa(all);
	else if (ft_find_len(all, 'a') == 3)
		ft_sort_3(all);
	else if (ft_find_len(all, 'a') == 4)
		ft_sort_4(all);
	else if (ft_find_len(all, 'a') == 5)
		ft_sort_5(all);
}

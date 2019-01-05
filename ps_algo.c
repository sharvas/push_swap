/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 11:30:38 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/05 11:30:39 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sort_module(t_all *all, int size, int start, int end)
{
	int		size_b;
	int		next_size;

	if (size < all->len / 2)
	{
		while (all->a->n > end)
			ft_rra(all);
		while (all->a->n <= end)
			ft_rra(all);
		size++;
	}
	else
		while (all->a->n > end)
			ft_ra(all);
	while (size--)
	{
		if (all->a->n > start && all->a->n <= end)
			ft_pb(all);
		else
			ft_ra(all);
	}
	size_b = ft_find_len(all, 'b');
	next_size = size_b;
	while (size_b--)
		ft_pa_sort(all);
	return (next_size);
}

void	ft_sort_100(t_all *all)
{
	int		size_a;
	int		tmp;

	size_a = ft_find_len(all, 'a');
	tmp = ft_sort_module(all, size_a, all->two_thirds, all->max);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->one_third, all->two_thirds);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->min, all->one_third);
	while (all->a->n != all->min)
		ft_rra(all);
}

void	ft_sort_big(t_all *all)
{
	int		size_a;
	int		tmp;

	size_a = ft_find_len(all, 'a');
	tmp = ft_sort_module(all, size_a, all->six_sevenths, all->max);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->five_sevenths, all->six_sevenths);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->four_sevenths, all->five_sevenths);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->three_sevenths, all->four_sevenths);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->two_sevenths, all->three_sevenths);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->one_seventh, all->two_sevenths);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->min, all->one_seventh);
	while (all->a->n != all->min)
		ft_rra(all);
}

void	ft_sort_algo_switch(t_all *all)
{
	if (ft_is_sorted(all, 'a'))
		return ;
	else if (ft_find_len(all, 'a') <= 5)
		ft_sort_small(all);
	else if (ft_find_len(all, 'a') > 101)
		ft_sort_big(all);
	else
		ft_sort_100(all);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 11:39:51 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/06 11:39:53 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
		all->a->n > start && all->a->n <= end ? ft_pb(all) : ft_ra(all);
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
	tmp = ft_sort_module(all, size_a, all->b_third, all->max);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->a_third, all->b_third);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->min, all->a_third);
	while (all->a->n != all->min)
		ft_rra(all);
}

void	ft_sort_big(t_all *all)
{
	int		size_a;
	int		tmp;

	size_a = ft_find_len(all, 'a');
	tmp = ft_sort_module(all, size_a, all->f_seven, all->max);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->e_seven, all->f_seven);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->d_seven, all->e_seven);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->c_seven, all->d_seven);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->b_seven, all->c_seven);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->a_seven, all->b_seven);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->min, all->a_seven);
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

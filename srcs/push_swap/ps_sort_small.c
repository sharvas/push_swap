/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:06:48 by svaskeli          #+#    #+#             */
/*   Updated: 2019/03/03 17:06:50 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_all *all, char stack)
{
	int	min;
	int	max;

	min = (stack == 'a') ? ft_find_min(all, 'a') : ft_find_min(all, 'b');
	max = (stack == 'a') ? ft_find_max(all, 'a') : ft_find_max(all, 'b');
	if (ft_is_sorted(all, 'a'))
		return ;
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
	ft_sort_3(all, 'a');
	ft_pa(all);
}

void	ft_rotate_small(t_all *all, int min)
{
	t_stack	*tmp;
	int		count;

	tmp = all->a;
	count = 0;
	while (tmp->n != min)
	{
		tmp = tmp->next;
		count++;
	}
	if (count < 3)
		while (count--)
			ft_ra(all);
	else
	{
		count = ft_find_len(all, 'a') - count;
		while (count--)
			ft_rra(all);
	}
	ft_pb(all);
}

void	ft_sort_5(t_all *all)
{
	int min;

	while (ft_find_len(all, 'b') < 2)
	{
		min = ft_find_min(all, 'a');
		ft_rotate_small(all, min);
	}
	ft_sort_3(all, 'a');
	ft_pa(all);
	ft_pa(all);
}

void	ft_sort_small(t_all *all)
{
	if (ft_find_len(all, 'a') == 2)
		ft_sa(all);
	else if (ft_find_len(all, 'a') == 3)
		ft_sort_3(all, 'a');
	else if (ft_find_len(all, 'a') == 4)
		ft_sort_4(all);
	else if (ft_find_len(all, 'a') == 5)
		ft_sort_5(all);
}

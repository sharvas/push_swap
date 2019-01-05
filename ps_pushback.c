/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pushback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 11:29:52 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/05 11:29:54 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_direction(t_all *all, int num, int direction)
{
	if (direction > 0)
		while (all->b->n != num)
			ft_rb(all);
	else
		while (all->b->n != num)
			ft_rrb(all);
}

int		ft_up_down(t_all *all, int num)
{
	t_stack	*tmp;
	int		count;
	int		len;

	count = 0;
	tmp = all->b;
	while (tmp->n != num)
	{
		count++;
		tmp = tmp->next;
	}
	if (count <= ((len = ft_find_len(all, 'b')) / 2))
		return (count);
	else
		return ((len - count) * -1);
}

int		ft_min_max(t_all *all, int max, int min)
{
	int		count_max;
	int		count_min;
	int		max_direction;
	int		min_direction;

	max_direction = 1;
	min_direction = 1;
	if ((count_max = ft_up_down(all, max)) < 0)
	{
		count_max = -count_max;
		max_direction = -1;
	}
	if ((count_min = ft_up_down(all, min)) < 0)
	{
		count_min = -count_min;
		min_direction = -1;
	}
	if (count_max > (count_min + 1))
	{
		ft_rotate_direction(all, min, min_direction);
		return (-1);
	}
	else
		ft_rotate_direction(all, max, max_direction);
	return (1);
}

void	ft_pushback(t_all *all, int min_max)
{
	if (min_max > 0)
		ft_pa(all);
	else
	{
		ft_pa(all);
		ft_ra(all);
	}
}

void	ft_pa_sort(t_all *all)
{
	int	max;
	int	min;
	int	min_max;

	max = ft_find_max(all, 'b');
	min = ft_find_min(all, 'b');
	min_max = ft_min_max(all, max, min);
	ft_pushback(all, min_max);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 09:12:37 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/31 14:06:59 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_setmax_b(t_all *all)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = all->b;
	max = all->b;
	while (tmp && tmp->next != all->b)
	{
		if (tmp->n < tmp->next->n)
			max = tmp->next;
		tmp = tmp->next;
	}
	while (all->b != max)
		ft_rb(all);
}

void	ft_sort_less(t_all *all)
{
	t_stack	*tmp_b;
	int		count_b;
	int		size_a;
	int		size_b;

	size_a = ft_find_len(all, 'a');
	while (size_a--)
	{
		if (all->a->n <= all->median)
		{
			size_b = (all->b) ? ft_find_len(all, 'b') : 0;
			count_b = 0;
			tmp_b = all->b;
			while (tmp_b && size_b > 1 && count_b < size_b && all->a->n < tmp_b->n)
			{
				count_b++;
				tmp_b = tmp_b->next;
			}
			if (tmp_b != all->b || count_b > 1)
			{
				while (count_b--)
					ft_rb(all);
			}
			ft_pb(all);
			ft_setmax_b(all);
		}
		else
			ft_ra(all);
	}
	size_b = ft_find_len(all, 'b');
	while (size_b--)
		ft_pa(all);
}

void	ft_sort_more(t_all *all)
{
	t_stack	*tmp_b;
	int		count_b;
	int		size_b;
	int		size_a;

	size_a = ft_find_len(all, 'a');
	while (size_a--)
	{
		if (all->a->n > all->median)
		{
			size_b = (all->b) ? ft_find_len(all, 'b') : 0;
			count_b = 0;
			tmp_b = all->b;
			while (tmp_b && size_b > 1 && count_b < size_b && all->a->n < tmp_b->n)
			{
				count_b++;
				tmp_b = tmp_b->next;
			}
			if (tmp_b != all->b || count_b > 1)
			{
				while (count_b--)
					ft_rb(all);
			}
			ft_pb(all);
			ft_setmax_b(all);
		}
		else
			ft_ra(all);
	}
	size_b = ft_find_len(all, 'b');
	while (size_b--)
		ft_pa(all);
}

void	ft_sort(t_all *all)
{
	ft_sort_more(all);
	ft_sort_less(all);
}

void	ft_push_swap(char **av)
{
	t_all	*all;

	all = NULL;
	all = ft_initialize(all);
	all->display = 1;
	ft_fill_a(all, av);
	ft_find_ref(all);
	ft_sort(all);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		ft_push_swap_usage();
	ft_push_swap(av);
	return (0);
}

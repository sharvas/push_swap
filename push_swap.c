/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 09:12:37 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/30 18:53:24 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_less(t_all *all)
{
	t_stack	*tmp_b;
	int		count_b;
	int		count_a;
	int		size_a;
	int		size_b;

	count_a = 0;
	size_a = ft_find_len(all, 'a');
	while (count_a++ < size_a)
	{
		if (all->a->n <= all->median)
		{
			if (all->b)
				size_b = ft_find_len(all, 'b');
			else
				size_b = 0;
			count_b = 0;
			tmp_b = all->b;
			while (all->b && size_b > 1 && count_b < size_b && all->a->n < tmp_b->n)
			{
				count_b++;
				tmp_b = tmp_b->next;
			}
			if (count_b <= size_b)
			{
				while (count_b--)
					ft_rb(all);
			}
			ft_pb(all);
		}
		else
			ft_ra(all);
	}
	while (all->b->n != all->median)
		ft_rb(all);
	size_b = ft_find_len(all, 'b');
	while (size_b--)
		ft_pa(all);
}

void	ft_sort_more(t_all *all)
{
	t_stack	*tmp_b;
	int		count_b;
	int		count_a;
	int		size_b;
	int		size_a;

	count_a = 0;
	size_a = ft_find_len(all, 'a');
	while (count_a++ < size_a)
	{
		if (all->a->n > all->median)
		{
			if (all->b)
				size_b = ft_find_len(all, 'b');
			else
				size_b = 0;
			count_b = 0;
			tmp_b = all->b;
			while (all->b && size_b > 1 && count_b < size_b && all->a->n < tmp_b->n)
			{
				count_b++;
				tmp_b = tmp_b->next;
			}
			if (count_b <= size_b)
			{
				while (count_b--)
					ft_rb(all);
			}
			ft_pb(all);
		}
		else
			ft_ra(all);
	}
	while (all->b->n != all->max)
		ft_rb(all);
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

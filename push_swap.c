/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 09:12:37 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/29 20:16:53 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_less(t_all *all)
{
	t_stack	*tmp;
	int		count_b;
	int		size_b;

	size_b = 0;
	while (all->a)
	{
		if (all->a->n < all->median)
		{
			ft_pb(all);
			size_b++;
			tmp = all->b;
			count_b = -1;
			while (tmp->n >= all->b->n && (count_b < size_b - 1))
			{
				count_b++;
				tmp = tmp->next;
			}
			if (count_b > 0)
			{
				while (count_b >= 0)
				{
					ft_sb(all);
					ft_rb(all);
					count_b--;
				}
			}
		}
		else
			ft_ra(all);
	}
	while (all->a->prev)
		all->a = all->a->prev;
	while (size_b)
	{
		ft_pa(all);
		size_b--;
	}
}

void	ft_sort_more(t_all *all)
{
	t_stack	*tmp;
	int		count_b;
	int		size_b;

	size_b = 0;
	while (all->a)
	{
		if (all->a->n >= all->median)
		{
			ft_pb(all);
			size_b++;
			tmp = all->b;
			count_b = -1;
//				printf("tmp: %i ir all: %i\n", tmp->n, all->b->n);
			printf("%i\n", all->a->n);
			while (tmp && tmp->n <= all->b->n && (count_b < size_b - 1))
			{
				count_b++;
				tmp = tmp->next;
			}
//			printf("size: %i ir count_b: %i\n", size_b, count_b);
			if (count_b > 0)
			{
				while (count_b >= 0)
				{
					ft_sb(all);
					ft_rb(all);
					count_b--;
				}
			}
		}
		else
			ft_ra(all);
	}
	while (all->a->prev)
		all->a = all->a->prev;
	while (size_b)
	{
		ft_pa(all);
		size_b--;
	}
}

void	ft_sort(t_all *all)
{
	t_stack	*top;

//	if (!ft_is_sorted(all))
//	{
		ft_sort_more(all);
//		if (!ft_is_sorted(all))
			ft_sort_less(all);
//	}
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

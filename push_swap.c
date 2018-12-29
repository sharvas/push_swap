/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 09:12:37 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/29 11:36:35 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_less(t_all *all, t_stack *tmp_a, int count_a)
{
	t_stack	*tmp_b;
	int		count_b;
	int		size_b;

	size_b = 0;
	while (count_a < all->len - 1)
	{
		if (all->a->n < all->median)
		{
			ft_pb(all);
			size_b++;
			tmp_b = all->b;
			count_b = 0;
			while (count_b < size_b)
			{
				if (tmp_b->n > all->b->n)
				{
					while (count_b)
					{
						ft_sb(all);
						ft_rb(all);
						count_b--;
					}
					break ;
				}
				count_b++;
				tmp_b = tmp_b->next;
			}
		}
		else
			ft_ra(all);
		count_a++;
	}
	while (size_b)
	{
		ft_pa(all);
		size_b--;
	}
}

void	ft_sort_more(t_all *all, t_stack *tmp_a, int count_a)
{
	t_stack	*tmp_b;
	int		count_b;
	int		size_b;

	size_b = 0;
	while (count_a < all->len - 1)
	{
		if (all->a->n >= all->median)
		{
			ft_pb(all);
			size_b++;
			tmp_b = all->b;
			count_b = 0;
			while (count_b < size_b)
			{
				if (tmp_b->n > all->b->n)
				{
					while (count_b)
					{
						ft_sb(all);
						ft_rb(all);
						count_b--;
					}
					break ;
				}
				count_b++;
				tmp_b = tmp_b->next;
			}
		}
		else
			ft_ra(all);
		count_a++;
	}
	while (size_b)
	{
		ft_pa(all);
		size_b--;
	}
}

void	ft_sort(t_all *all)
{
	t_stack *tmp_a;
	int		count_a;

	count_a = 0;
	tmp_a = all->a;
	if (!ft_is_sorted(all))
	{
		ft_sort_more(all, tmp_a, count_a);
		if (!ft_is_sorted(all))
			ft_sort_less(all, tmp_a, count_a);
	}
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
	if (ac > 1)
		ft_push_swap(av);
	return (0);
}

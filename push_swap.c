/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 09:12:37 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/29 10:45:37 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_less(t_all *all, t_stack *tmp_a, int size_a)
{
	t_stack	*tmp_b;
	int		count;
	int		size_b;

	size_b = 0;
	while (size_a)
	{
		tmp_a = all->a;
		if (tmp_a->n < all->median)
		{
			ft_pb(all);
			size_b++;
			tmp_b = all->b;
			count = 0;
			while (count < size_b)
			{
				if (tmp_b->n < all->b->n)
				{
					while (count)
					{
						ft_sb(all);
						ft_rb(all);
						count--;
					}
					break ;
				}
				count++;
				tmp_b = tmp_b->next;
			}
		}
		else
			ft_ra(all);
		size_a--;
	}
	while (size_b)
	{
		ft_pa(all);
		size_b--;
	}
}

void	ft_sort_more(t_all *all, t_stack *tmp_a, int size_a)
{
	t_stack	*tmp_b;
	int		count;
	int		size_b;

	size_b = 0;
	while (size_a)
	{
		tmp_a = all->a;
		if (tmp_a->n >= all->median)
		{
			ft_pb(all);
			size_b++;
			tmp_b = all->b;
			count = 0;
			while (count < size_b)
			{
				if (tmp_b->n < all->b->n)
				{
					while (count)
					{
						ft_sb(all);
						ft_rb(all);
						count--;
					}
					break ;
				}
				count++;
				tmp_b = tmp_b->next;
			}
		}
		else
			ft_ra(all);
		size_a--;
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
	int		size_a;

	tmp_a = all->a;
	size_a = all->len;
	ft_sort_less(all, tmp_a, size_a);
	ft_sort_more(all, tmp_a, size_a);
}

void	ft_push_swap(char **av)
{
	t_all	*all;

	all = NULL;
	all = ft_initialize(all);
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

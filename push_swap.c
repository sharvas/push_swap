/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 09:12:37 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/28 15:53:08 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_sort_less(all, tmp_a, size_a, instructions)
{
	t_stack	*tmp_b;
	int		count;
	int		size_b;

	size_b = 0;
	while (size_a)
	{
		if (tmp_a->n < all->mean)
		{
			ft_pb(all);
			size_b++;
			tmp_b = all->b;
			count = 0;
			while (count < size_b)
			{
				if (tmp_b->n < all->b)
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
		tmp_a = tmp_a->next;
		size_a--;
	}
	while (size_b)
	{
		ft_pa(all);
		size_b--;
	}
	return (instructions);
}

char	*ft_sort_less(all, tmp_a, size_a, instructions)
{
	t_stack	*tmp_b;
	int		count;
	int		size_b;

	size_b = 0;
	while (size_a)
	{
		if (tmp_a->n >= all->mean)
		{
			ft_pb(all);
			size_b++;
			tmp_b = all->b;
			count = 0;
			while (count < size_b)
			{
				if (tmp_b->n < all->b)
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
		tmp_a = tmp_a->next;
		size_a--;
	}
	while (size_b)
	{
		ft_pa(all);
		size_b--;
	}
	return (instructions)
}

char	*ft_sort(t_all *all, char *instructions)
{
	t_stack *tmp_a;
	int		size_a;

	tmp_a = all->a;
	size_a = all->len;
	instructions = ft_sort_less(all, tmp_a, size_a, instructions);
	instructions = ft_sort_more(all, tmp_a, size_a, instructions);
}

void	ft_push_swap(char **av)
{
	t_all	*all;
	char	*instructions;

	all = NULL;
	instructions = NULL;
	all = ft_initialize(all);
	ft_fill_a(all, av);
	ft_find_ref(all);
	instructions = ft_sort(all, instructions);
	ft_putstr_fd(instructions, 0);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		ft_push_swap(av);
	return (0);
}

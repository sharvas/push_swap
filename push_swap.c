/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 09:12:37 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/28 15:21:08 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_sort(t_all *all, char *instructions)
{
	t_stack *tmp_a;
	t_stack *tmp_b;
	int		counter;

	tmp_a = all->a;
	while (tmp->a != top_a->prev)
	{
		if (tmp_a->n < all->mean)
		{
			ft_pb(all);
			top_b = all->b;
			counter = 0;
			while (all->b != top_b->prev)
			{
				if (top_b->n < all->b)
				{
					all->b = top_b;
					while (counter)
					{
						ft_sb(all);
						all->b = all->b->next;
						counter--;
					}
					break ;
				}
				counter++;
				all->b = all->b->next;
			}
		}
		all->a = all->a->next;
	}
	all
	while ()
}

void	ft_push_swap(char **av)
{
	t_all	*all;
	char	*instructions;

	all = NULL;
	instructions = NULL;
	all = ft_initialize(all);
	ft_fill_a(all, av);
//	ft_find_min_max(all);
	instructions = ft_sort(all, instructions);
	ft_putstr_fd(instructions, 0);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		ft_push_swap(av);
	return (0);
}

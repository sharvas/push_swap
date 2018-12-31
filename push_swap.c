/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 09:12:37 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/31 16:53:46 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_setmax_b(t_all *all, int if_rotate)
{
	t_stack	*tmp;
	t_stack	*max;
	int		count_rb;
	int		count_rrb;

	tmp = all->b;
	max = all->b;
	count_rb = 0;
	count_rrb = 0;
	while (tmp && tmp->next != all->b)
	{
		if (tmp->n < tmp->next->n)
			max = tmp->next;
		tmp = tmp->next;
	}
	tmp = all->b;
	while (tmp && tmp != max)
	{
		tmp = tmp->next;
		count_rb++;
	}
	tmp = all->b;
	while (tmp && tmp != max)
	{
		tmp = tmp->prev;
		count_rrb++;
	}
	if (count_rb < count_rrb)
	{
		while (if_rotate && all->b != max)
			ft_rb(all);
	}
	else
	{
		while (if_rotate && all->b != max)
			ft_rrb(all);
	}
}

int		ft_isleft(t_all *all, char c)
{
	t_stack *tmp;

	tmp = all->a;
	if (c == '-')
	{
		while (tmp && tmp->next != all->a)
		{
			if (tmp->n <= all->median)
				return (1);
			tmp = tmp->next;
		}
	}
	else if (c == '+')
	{
		while (tmp && tmp->next != all->a)
		{
			if (tmp->n > all->median)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}

void	ft_sort_less(t_all *all)
{
	t_stack	*tmp_b;
	int		count_b;
	int		size_a;
	int		size_b;
	int		if_rotate;

	size_a = ft_find_len(all, 'a');
	while (size_a--)
	{
		if_rotate = 1;
		if (all->a->n <= all->median)
		{
			size_b = (all->b) ? ft_find_len(all, 'b') : 0;
			if (all->a && all->b && all->b->prev && all->a->n > all->b->n && all->a->n < all->b->prev->n)
				if_rotate = 0;
			ft_setmax_b(all, if_rotate);
			count_b = 0;
			tmp_b = all->b;
			while (tmp_b && size_b > 1 && count_b < size_b && all->a->n < tmp_b->n/* && !ft_is_sorted(all, 'b')*/)
			{
				count_b++;
				tmp_b = tmp_b->next;
			}
			if (tmp_b != all->b || count_b > 1)
			{
				while (count_b-- && if_rotate)
					ft_rb(all); //check if rb or rrb
			}
			ft_pb(all);
		}
		else if (ft_isleft(all, '-'))
			ft_ra(all);
	}
	ft_setmax_b(all, 1);
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
	int		if_rotate;

	size_a = ft_find_len(all, 'a');
	while (size_a--)
	{
		if_rotate = 1;
		if (all->a->n > all->median)
		{
			size_b = (all->b) ? ft_find_len(all, 'b') : 0;
			if (all->a && all->b && all->b->prev && all->a->n > all->b->n && all->a->n < all->b->prev->n)
				if_rotate = 0;
			ft_setmax_b(all, if_rotate);
			count_b = 0;
			tmp_b = all->b;
			while (tmp_b && size_b > 1 && count_b < size_b && all->a->n < tmp_b->n/* && !ft_is_sorted(all, 'b')*/)
			{
				count_b++;
				tmp_b = tmp_b->next;
			}
			if (tmp_b != all->b || count_b > 1)
			{
				while (count_b-- && if_rotate)
					ft_rb(all); //check if rb or rrb
			}
			ft_pb(all);
		}
		else if (ft_isleft(all, '+'))
			ft_ra(all);
	}
	ft_setmax_b(all, 1);
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

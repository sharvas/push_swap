/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 10:20:18 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/29 22:00:54 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_len(t_all *all, char c)
{
	t_stack		*tmp;
	int			len;

	len = 1;
	tmp = (c == 'a') ? all->a : all->b;
	while (tmp->next)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	ft_simple_sort(t_stack *cpy)
{
	t_stack		*top;
	int			swap;

	top = cpy;
	while (cpy->next)
	{
		if (cpy->n < cpy->next->n)
			cpy = cpy->next;
		else
		{
			swap = cpy->n;
			cpy->n = cpy->next->n;
			cpy->next->n = swap;
			cpy = top;
		}
	}
	cpy = top;
}

t_stack	*add_link(t_stack *cpy, int n)
{
	t_stack	*tmp;

	if (cpy)
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
		tmp->prev = cpy;
		tmp->next = NULL;
		cpy->next = tmp;
		tmp->n = n;
		cpy = tmp;
	}
	else
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
		tmp->prev = NULL;
		tmp->next = NULL;
		tmp->n = n;
		cpy = tmp;
	}
	return (cpy);
}

t_stack	*ft_dublicate_list(t_all *all)
{
	t_stack		*cpy;
	t_stack		*tmp;

	tmp = all->a;
	cpy = NULL;
	while (tmp)
	{
		cpy = add_link(cpy, tmp->n);
		tmp = tmp->next;
	}
	while (cpy->prev)
		cpy = cpy->prev;
	return (cpy);
}

void	ft_find_ref(t_all *all)
{
	t_stack		*cpy;
	int			count;

	all->len = ft_find_len(all, 'a');
	cpy = ft_dublicate_list(all);
	ft_simple_sort(cpy);
	all->min = cpy->n;
	count = (all->len / 2);
	while (count--)
		cpy = cpy->next;
	all->median = cpy->n;
	count = (all->len / 2);
	while (++count < all->len)
		cpy = cpy->next;
	all->max = cpy->n;
	free(cpy);
}

void	ft_ko_ok(t_all *all)
{
	if (ft_is_sorted(all))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int		ft_is_sorted(t_all *all)
{
	t_stack	*tmp;

	if (!all->a || all->b)
		return (0);
	tmp = all->a;
	while (tmp->next != NULL)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// void	ft_find_min_max(t_all *all)
// {
// 	t_stack		*tmp;

// 	tmp = all->a;
// 	all->min = tmp->n;
// 	all->max = tmp->n;
// 	tmp = tmp->next;
// 	while (tmp->next != all->a->next)
// 	{
// 		if (tmp->n < all->min)
// 			all->min = tmp->n;
// 		if (tmp->n > all->max)
// 			all->max = tmp->n;
// 		tmp = tmp->next;
// 	}
// }


// void	ft_find_min_max(t_all *all)
// {
// 	t_stack		*tmp;

// 	tmp = all->a;
// 	all->min = tmp->n;
// 	all->max = tmp->n;
// 	tmp = tmp->next;
// 	while (tmp->next != all->a->next)
// 	{
// 		if (tmp->n < all->min)
// 			all->min = tmp->n;
// 		if (tmp->n > all->max)
// 			all->max = tmp->n;
// 		tmp = tmp->next;
// 	}
// }

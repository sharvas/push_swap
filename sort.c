/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 10:20:18 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/03 19:48:31 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_len(t_all *all, char c)
{
	t_stack		*tmp;
	t_stack		*top;
	int			len;

	len = 1;
	tmp = (c == 'a') ? all->a : all->b;
	top = tmp;
	while (tmp && tmp->next != top)
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
	while (cpy && cpy->next)
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
	while (tmp != all->a->prev)
	{
		cpy = add_link(cpy, tmp->n);
		tmp = tmp->next;
	}
	cpy = add_link(cpy, tmp->n);
	tmp = tmp->next;
	while (cpy->prev)
		cpy = cpy->prev;
	return (cpy);
}

void	ft_find_sevenths(t_all *all)
{
	t_stack		*top;
	t_stack		*cpy;
	int			count;

	all->len = ft_find_len(all, 'a');
	cpy = ft_dublicate_list(all);
	ft_simple_sort(cpy);
	top = cpy;
	count = (all->len / 7);
	all->min = cpy->n;
	while (count--)
		cpy = cpy->next;
	all->one_seventh = cpy->n;
	cpy = top;
	count = ((all->len / 7) * 2);
	while (count--)
		cpy = cpy->next;
	all->two_sevenths = cpy->n;
	cpy = top;
	count = ((all->len / 7) * 3);
	while (count--)
		cpy = cpy->next;
	all->three_sevenths = cpy->n;
	cpy = top;
	count = ((all->len / 7) * 4);
	while (count--)
		cpy = cpy->next;
	all->four_sevenths = cpy->n;
	cpy = top;
	count = ((all->len / 7) * 5);
	while (count--)
		cpy = cpy->next;
	all->five_sevenths = cpy->n;
	cpy = top;
	count = ((all->len / 7) * 6);
	while (count--)
		cpy = cpy->next;
	all->six_sevenths = cpy->n;
	while (cpy->prev)
		cpy = cpy->prev;
	free(cpy);
}

void	ft_find_thirds(t_all *all)
{
	t_stack		*top;
	t_stack		*cpy;
	int			count;

	all->len = ft_find_len(all, 'a');
	cpy = ft_dublicate_list(all);
	ft_simple_sort(cpy);
	top = cpy;
	count = (all->len / 3);
	all->min = cpy->n;
	while (count--)
		cpy = cpy->next;
	all->one_third = cpy->n;
	cpy = top;
	count = (all->len / 2);
	while (count--)
		cpy = cpy->next;
	all->median = cpy->n;
	cpy = top;
	count = ((all->len / 3) * 2);
	while (count--)
		cpy = cpy->next;
	all->two_thirds = cpy->n;
	while (cpy->next)
		cpy = cpy->next;
	all->max = cpy->n;
	while (cpy->prev)
		cpy = cpy->prev;
	free(cpy);
}

void	ft_find_ref(t_all *all)
{
	ft_find_thirds(all);
	ft_find_sevenths(all);
	t_stack		*top;
	t_stack		*cpy;
	int			count;

	all->len = ft_find_len(all, 'a');
	cpy = ft_dublicate_list(all);
	ft_simple_sort(cpy);
	top = cpy;
	count = (all->len / 4);
	all->min = cpy->n;
	while (count--)
		cpy = cpy->next;
	all->qu = cpy->n;
	cpy = top;
	count = (all->len / 2);
	while (count--)
		cpy = cpy->next;
	all->median = cpy->n;
	cpy = top;
	count = ((all->len / 2) + (all->len / 4));
	while (count--)
		cpy = cpy->next;
	all->three_qu = cpy->n;
	while (cpy->next)
		cpy = cpy->next;
	all->max = cpy->n;
	while (cpy->prev)
		cpy = cpy->prev;
	free(cpy);
}

void	ft_ko_ok(t_all *all)
{
	if (ft_is_sorted(all, 'a') && !all->b)
		ft_putstr("\x1B[32mOK\x1B[0m\n");
	else
		ft_putstr("\x1B[31mKO\x1B[0m\n");
}

int		ft_is_sorted(t_all *all, char c)
{
	t_stack	*tmp;
	t_stack	*top;

	tmp = (c == 'a') ? all->a : all->b;
	top = tmp;
	while (tmp->next != top)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

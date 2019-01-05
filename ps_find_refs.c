/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_refs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 11:58:47 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/05 11:58:48 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_refs(t_all *all)
{
	t_stack		*cpy;

	all->len = ft_find_len(all, 'a');
	cpy = ft_dublicate_list(all);
	ft_simple_sort(cpy);
	all->min = cpy->n;
	all->one_third = ft_find_ref(cpy, (all->len / 3));
	all->two_thirds = ft_find_ref(cpy, ((all->len / 3) * 2));
	all->one_seventh = ft_find_ref(cpy, (all->len / 7));
	all->two_sevenths = ft_find_ref(cpy, ((all->len / 7) * 2));
	all->three_sevenths = ft_find_ref(cpy, ((all->len / 7) * 3));
	all->four_sevenths = ft_find_ref(cpy, ((all->len / 7) * 4));
	all->five_sevenths = ft_find_ref(cpy, ((all->len / 7) * 5));
	all->six_sevenths = ft_find_ref(cpy, ((all->len / 7) * 6));
	while (cpy->next)
		cpy = cpy->next;
	all->max = cpy->n;
	while (cpy->prev)
		cpy = cpy->prev;
	ft_free_stack(cpy);
}

int		ft_find_ref(t_stack *cpy, int count)
{
	int		n;
	t_stack *top;

	top = cpy;
	while (count--)
		cpy = cpy->next;
	n = cpy->n;
	cpy = top;
	return (n);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_refs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 11:58:47 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/05 15:40:21 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_find_refs(t_all *all)
{
	all->len = ft_find_len(all, 'a');
	all->cpy = ft_dublicate_list(all);
	ft_simple_sort(all->cpy);
	all->min = all->cpy->n;
	all->a_third = ft_find_ref(all->cpy, (all->len / 3));
	all->b_third = ft_find_ref(all->cpy, ((all->len / 3) * 2));
	all->a_seven = ft_find_ref(all->cpy, (all->len / 7));
	all->b_seven = ft_find_ref(all->cpy, ((all->len / 7) * 2));
	all->c_seven = ft_find_ref(all->cpy, ((all->len / 7) * 3));
	all->d_seven = ft_find_ref(all->cpy, ((all->len / 7) * 4));
	all->e_seven = ft_find_ref(all->cpy, ((all->len / 7) * 5));
	all->f_seven = ft_find_ref(all->cpy, ((all->len / 7) * 6));
	while (all->cpy->next)
		all->cpy = all->cpy->next;
	all->max = all->cpy->n;
	while (all->cpy->prev)
		all->cpy = all->cpy->prev;
	if (all->cpy)
		ft_free_stack(all->cpy);
	all->cpy = NULL;
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
		cpy = add_link(cpy, tmp->n, all);
		tmp = tmp->next;
	}
	cpy = add_link(cpy, tmp->n, all);
	tmp = tmp->next;
	while (cpy->prev)
		cpy = cpy->prev;
	return (cpy);
}

t_stack	*add_link(t_stack *cpy, int n, t_all *all)
{
	t_stack	*tmp;

	if (cpy)
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			ft_ps_error(all);
		tmp->prev = cpy;
		tmp->next = NULL;
		cpy->next = tmp;
		tmp->n = n;
		cpy = tmp;
	}
	else
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			ft_ps_error(all);
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

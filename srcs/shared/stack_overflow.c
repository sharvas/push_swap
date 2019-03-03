/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:06:07 by svaskeli          #+#    #+#             */
/*   Updated: 2019/03/03 17:06:09 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_all	*ft_initialize(t_all *all)
{
	if (!(all = (t_all *)malloc(sizeof(t_all))))
		ft_ps_error(all);
	all->a = NULL;
	all->b = NULL;
	all->cpy = NULL;
	all->array = NULL;
	all->len = 0;
	all->min = 0;
	all->max = 0;
	all->a_third = 0;
	all->b_third = 0;
	all->a_seven = 0;
	all->b_seven = 0;
	all->c_seven = 0;
	all->d_seven = 0;
	all->e_seven = 0;
	all->f_seven = 0;
	all->write_instructions = 0;
	all->instructions = ft_ps_strdup_empty(all);
	all->v = 0;
	all->c = 0;
	all->t = 0;
	all->f = 0;
	all->fd = 0;
	return (all);
}

int		ft_find_len(t_all *all, char stack)
{
	t_stack	*tmp;
	t_stack	*top;
	int		len;

	len = 1;
	tmp = (stack == 'a') ? all->a : all->b;
	top = tmp;
	while (tmp && tmp->next != top)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int		ft_find_min(t_all *all, char stack)
{
	t_stack	*tmp;
	int		min;
	int		len;

	tmp = (stack == 'a') ? all->a : all->b;
	len = ft_find_len(all, stack);
	min = tmp->n;
	while (len--)
	{
		tmp = tmp->next;
		if (tmp->n < min)
			min = tmp->n;
	}
	return (min);
}

int		ft_find_max(t_all *all, char stack)
{
	t_stack	*tmp;
	int		max;
	int		len;

	tmp = (stack == 'a') ? all->a : all->b;
	len = ft_find_len(all, stack);
	max = tmp->n;
	while (len--)
	{
		tmp = tmp->next;
		if (tmp->n > max)
			max = tmp->n;
	}
	return (max);
}

int		ft_is_sorted(t_all *all, char stack)
{
	t_stack	*tmp;
	t_stack	*top;

	if (!all || !all->a)
		return (0);
	tmp = (stack == 'a') ? all->a : all->b;
	top = tmp;
	while (tmp && tmp->next != top)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 13:19:49 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/01 16:18:20 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*ft_initialize(t_all *all)
{
	if (!(all = (t_all *)malloc(sizeof(t_all))))
		exit(1);
	all->a = NULL;
	all->b = NULL;
	all->v = 0;
	all->min = 0;
	all->median = 0;
	all->max = 0;
	all->len = 0;
	all->display = 0;
	return (all);
}

void	ft_fill_a(t_all *all, char **argv)
{
	int		i;
	int		j;
	int		n;
	char	**array;

	i = 1;
	j = 0;
	n = 0;
	array = NULL;
	if (ft_strcmp(argv[i], "-v") == 0)
	{
		all->v = 1;
		i++;
	}
	if (ft_strchr(argv[i], ' '))// buggy
	{
		array = ft_split_whitespaces(argv[i]);
		while (array[j])
		{
			n = ft_atoi_error(array[j]);
			if (ft_is_duplicate(all, n))
				ft_error(all);
			ft_add_end(all, n);
			j++;
		}
	}
	else
	{
		while (argv[i])
		{
			n = ft_atoi_error(argv[i]);
			if (ft_is_duplicate(all, n))
				ft_error(all);
			ft_add_end(all, n);
			i++;
		}
	}
	while (all->a->prev)
		all->a = all->a->prev;
}

void	ft_add_end(t_all *all, int n)
{
	t_stack	**top;
	t_stack	*tmp;

	top = &all->a;
	while (*top && (*top)->next)
		*top = (*top)->next;
	if (*top)
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
		tmp->prev = *top;
		tmp->next = NULL;
		(*top)->next = tmp;
		tmp->n = n;
	}
	else
	{
		if (!(*top = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
		(*top)->next = NULL;
		(*top)->prev = NULL;
		(*top)->n = n;
	}
}

void	ft_add_top(t_all *all, char stack, int n)
{
	t_stack	**top;
	t_stack	*tmp;

	top = (stack == 'a') ? &all->a : &all->b;
	if (*top)
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
		tmp->next = *top;
		tmp->prev = NULL;
		(*top)->prev = tmp;
		tmp->n = n;
		*top = tmp;
	}
	else
	{
		if (!(*top = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
		(*top)->next = NULL;
		(*top)->prev = NULL;
		(*top)->n = n;
	}
}

void	ft_del_top(t_all *all, char stack)
{
	t_stack	*top;
	t_stack	**tmp;

	tmp = (stack == 'a') ? &all->a : &all->b;
	if (*tmp)
		top = (*tmp)->next;
	if (*tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
	if (stack == 'a')
		all->a = top;
	else
		all->b = top;
}

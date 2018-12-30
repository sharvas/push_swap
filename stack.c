/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 13:19:49 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/30 18:50:34 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*ft_initialize(t_all *all)
{
	if (!(all = (t_all *)malloc(sizeof(t_all))))
		ft_error();
	all->a = NULL;
	all->b = NULL;
	all->v = 0;
	all->c = 0;
	all->min = 0;
	all->qu = 0;
	all->median = 0;
	all->three_qu = 0;
	all->max = 0;
	all->len = 0;
	all->display = 0;
	return (all);
}

void	ft_fill_error(t_all *all, char *str)
{
	int	n;

	n = ft_atoi_error(str);
	if (ft_is_duplicate(all, n))
		ft_error(all);
	ft_add_end(all, n);
}

void	ft_fill_a(t_all *all, char **argv)
{
	int		i;
	int		j;
	char	**array;

	i = 1;
	j = 0;
	array = NULL;
	while (ft_is_bonus(argv[i]))
	{
		if (ft_strcmp(argv[i], "-v") == 0)
		{
			all->v = 1;
			i++;
		}
		if (ft_strcmp(argv[i], "-c") == 0)
		{
			all->c = 1;
			i++;
		}
		if (ft_strcmp(argv[i], "-f") == 0)
		{
			i++;
//			open fd
		}
	}
	if (ft_strchr(argv[i], ' '))
	{
		array = ft_split_whitespaces(argv[i]);
		while (array[j])
			ft_fill_error(all, array[j++]);
	}
	else
	{
		while (argv[i])
			ft_fill_error(all, argv[i++]);
	}
}

void	ft_add_end(t_all *all, int n)
{
	t_stack	**top;
	t_stack	*tmp;

	top = &all->a;
	if (*top)
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
		tmp->next = *top;
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->n = n;
//		tmp->top = 1;
//		(*top)->top = 0;
	}
	else
	{
		if (!(*top = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->n = n;
//		(*top)->top = 1;
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
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->n = n;
		*top = (*top)->prev;
//		tmp->top = 1;
//		(*top)->top = 0;
	}
	else
	{
		if (!(*top = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->n = n;
//		(*top)->top = 1;
	}
}

void	ft_del_top(t_all *all, char stack)
{
	t_stack	**top;
	t_stack	*tmp;

	top = (stack == 'a') ? &all->a : &all->b;
	if (*top)
	{
		if ((*top)->next == *top)
		{
			free(*top);
			*top = NULL;
		}
		else
		{
			tmp = *top;
			*top = (*top)->next;
			tmp->prev->next = *top;
			(*top)->prev = tmp->prev;
			free(tmp);
//			(*top)->top = 1;
		}
	}
}

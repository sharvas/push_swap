/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 13:19:49 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/02 18:00:38 by svaskeli         ###   ########.fr       */
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
			if (!argv[i])
				ft_checker_usage();
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
	}
	else
	{
		if (!(*top = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
		(*top)->next = *top;
		(*top)->prev = *top;
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
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->n = n;
		*top = (*top)->prev;
	}
	else
	{
		if (!(*top = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->n = n;
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
		}
	}
}

int	ft_find_min(t_all *all, char stack)
{
	t_stack		*tmp;
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

int	ft_find_max(t_all *all, char stack)
{
	t_stack		*tmp;
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

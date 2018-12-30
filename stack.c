/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 13:19:49 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/29 21:34:22 by svaskeli         ###   ########.fr       */
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
//	all->qu = 0;
	all->median = 0;
//	all->three_qu = 0;
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
		ft_putstr("here\n");
		array = ft_split_whitespaces(argv[i]);
		ft_putstr("here2\n");
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
//	t_stack	/***/*top;
	t_stack	*tmp;

//	top = /*&*/all->a;
	if (/**top*/all->a)
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
//		tmp->next = *top;
		tmp->prev = all->a;//(*top)->prev;
		tmp->next = NULL;
		all->a->next = tmp;
//		(*top)->prev = tmp;
//		tmp->prev->next = tmp;
		tmp->n = n;
		all->a = tmp;
	}
	else
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
//		(*top)->next = *top;
//		(*top)->prev = *top;
//		(*top)->n = n;
		tmp->prev = NULL;
		tmp->next = NULL;
		tmp->n = n;
		all->a = tmp;
	}
}

void	ft_add_top(t_all *all, char stack, int n)
{
	t_stack	/***/*top;
	t_stack	*tmp;

	top = (stack == 'a') ? /*&*/all->a : /*&*/all->b;
	if (/***/top)
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
		tmp->next = /***/top;
		tmp->prev = NULL;//(*top)->prev;
		top->prev = tmp;
//		(*top)->prev = tmp;
//		tmp->prev->next = tmp;
		tmp->n = n;
//		*top = (*top)->prev;
		top = tmp;
	}
	else
	{
		if (!(/***/top = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
		top->next = NULL;
		top->prev = NULL;
		top->n = n;
//		(*top)->next = *top;
//		(*top)->prev = *top;
//		(*top)->n = n;
	}
//	if (stack == 'a')
//		all->a = top;
//	else
//		all->b = top;
}

void	ft_del_top(t_all *all, char stack)
{
	t_stack	/***/*top;
	t_stack	*tmp;

	top = (stack == 'a') ? /*&*/all->a : /*&*/all->b;
	tmp = top->next;
	if (/***/top)
	{
//		if (/*(*top)->next == *top*/top->next == NULL)
//		{
			free(/***/top);
			/***/top = NULL;
//		}
//		else
//		{
//			printf("-?-\n");
//			tmp = /***/top;
//			/***/top->prev->next = NULL; //(*top)->next;
//			top->next->prev = tmp->prev;
//			tmp->prev->next = *top;
//			(*top)->prev = tmp->prev;
//			free(tmp);
//			tmp = NULL;
//		}
	}
//	if (stack == 'a')
//		all->a = top;
//	else
//		all->b = top;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:05:49 by svaskeli          #+#    #+#             */
/*   Updated: 2019/03/03 17:05:51 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_fill_a(t_all *all, char **argv, int i)
{
	int	j;

	while (argv[i])
	{
		j = 0;
		if (ft_strchr(argv[i], ' '))
		{
			if (!(all->array = ft_split_whitespaces(argv[i])))
				ft_ps_error(all);
			while (all->array[j])
				ft_fill_error(all, all->array[j++]);
			if (all->array)
				ft_2d_char_free(all->array);
			all->array = NULL;
		}
		else
			ft_fill_error(all, argv[i]);
		i++;
	}
}

void	ft_fill_error(t_all *all, char *str)
{
	int	n;

	n = ft_atoi_error(str, all);
	if (ft_is_duplicate(all, n))
		ft_ps_error(all);
	ft_add_end(all, n);
}

void	ft_add_end(t_all *all, int n)
{
	t_stack	**top;
	t_stack	*tmp;

	top = &all->a;
	if (*top)
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			ft_ps_error(all);
		tmp->next = *top;
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->n = n;
	}
	else
	{
		if (!(*top = (t_stack *)malloc(sizeof(t_stack))))
			ft_ps_error(all);
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
			ft_ps_error(all);
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
			ft_ps_error(all);
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

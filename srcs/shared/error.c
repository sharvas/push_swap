/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:05:29 by svaskeli          #+#    #+#             */
/*   Updated: 2019/03/03 17:05:31 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_error(t_all *all)
{
	ft_putstr("Error\n");
	ft_free_all(all);
	exit(1);
}

int		ft_is_duplicate(t_all *all, intmax_t n)
{
	t_stack	*ref;

	ref = all->a;
	if (ref == NULL)
		return (0);
	if (n == ref->n)
		return (1);
	ref = ref->next;
	while (ref != all->a)
	{
		if (n == ref->n)
			return (1);
		ref = ref->next;
	}
	return (0);
}

int		ft_atoi_error(char *str, t_all *all)
{
	long	a;
	int		i;
	int		n;

	a = 0;
	i = 0;
	n = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		str++;
	}
	while (*str == '0' && *(str + 1) == '0')
		str++;
	if (str[i] < '0' || str[i] > '9')
		ft_ps_error(all);
	while (str[i] >= '0' && str[i] <= '9' && i < 11)
		a = (a * 10) + (str[i++] - '0');
	a *= n;
	if (str[i] || a > 2147483647 || a < -2147483648)
		ft_ps_error(all);
	return (a);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack *tmp;
	t_stack	*end;

	if (stack)
		end = stack->prev;
	else
		end = stack;
	while (stack && stack != end)
	{
		tmp = stack->next;
		if (stack)
			free(stack);
		stack = tmp;
	}
	if (end)
		free(end);
	stack = NULL;
	end = NULL;
	tmp = NULL;
}

void	ft_free_all(t_all *all)
{
	if (all)
	{
		ft_free_stack(all->a);
		ft_free_stack(all->b);
		ft_free_stack(all->cpy);
		if (all->instructions)
			free(all->instructions);
		all->instructions = NULL;
		if (all->array)
			ft_2d_char_free(all->array);
		all->array = NULL;
		if (all)
			free(all);
		all = NULL;
	}
}

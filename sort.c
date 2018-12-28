/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 10:20:18 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/28 10:20:19 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_find_mean(t_all *all)
{
	t_stack		*tmp;
	long long	total;
	int			len;

	total = 0;
	len = 0;
	tmp = all->a;
	while (tmp->next != all->a)
	{
		total += tmp->n;
		len++;
		tmp = tmp->next;
	}
	total += tmp->n;
	len++;
	all->mean = (total / len);
}

void	ft_find_min_max(t_all *all)
{
	t_stack		*tmp;

	tmp = all->a;
	all->min = tmp->n;
	all->max = tmp->n;
	tmp = tmp->next;
	while (tmp->next != all->a->next)
	{
		if (tmp->n < all->min)
			all->min = tmp->n;
		if (tmp->n > all->max)
			all->max = tmp->n;
		tmp = tmp->next;
	}
}

void	ft_ko_ok(t_all *all)
{
	if (ft_is_sorted(all))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int		ft_is_sorted(t_all *all)
{
	t_stack	*tmp;

	if (!all->a || all->b)
		return (0);
	tmp = all->a;
	while (tmp->next != all->a)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
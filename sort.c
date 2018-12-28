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

int		ft_find_len(t_all *all)
{
	t_stack		*tmp;
	int			len;

	len = 1;
	tmp = all->a;
	while (tmp->next != all->a)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

t_all	*ft_simple_sort(t_all *all)
{
	t_stack		*tmp;
	int			swap;

	tmp = all->a;
	swap = 0;
	while (tmp->next != all->a)
	{
		if (tmp->n < tmp->next->n)
			tmp = tmp->next;
		else
		{
			swap = tmp->n;
			tmp->n = tmp->next->n;
			tmp->next->n = swap;
			tmp = all->a;
		}
	}
	return (all);
}

void	ft_find_ref(t_all *all)
{
	t_stack		*tmp;
	t_all		*cpy;
	int			count;

	all->len = ft_find_len(all);
	cpy = ft_simple_sort(all);
	tmp = cpy->a;
	count = (ft_find_len(all) / 4);
	all->min = tmp->n;
	while (count--)
		tmp = tmp->next;
	all->qu = tmp->n;
	tmp = cpy->a;
	count = (ft_find_len(all) / 2);
	while (count--)
		tmp = tmp->next;
	all->median = tmp->n;
	tmp = cpy->a;
	count = ((ft_find_len(all) / 2) + (ft_find_len(all) / 4));
	while (count--)
		tmp = tmp->next;
	all->three_qu = tmp->n;
	while (tmp->next != all->a)
		tmp = tmp->next;
	all->max = tmp->n;
	printf("min: %d, qu: %d, median: %d, three_qu: %d, max: %d, len: %d\n", all->min, all->qu, all->median, all->three_qu, all->max, all->len);
	//free_cpy??//
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

// void	ft_find_min_max(t_all *all)
// {
// 	t_stack		*tmp;

// 	tmp = all->a;
// 	all->min = tmp->n;
// 	all->max = tmp->n;
// 	tmp = tmp->next;
// 	while (tmp->next != all->a->next)
// 	{
// 		if (tmp->n < all->min)
// 			all->min = tmp->n;
// 		if (tmp->n > all->max)
// 			all->max = tmp->n;
// 		tmp = tmp->next;
// 	}
// }


// void	ft_find_min_max(t_all *all)
// {
// 	t_stack		*tmp;

// 	tmp = all->a;
// 	all->min = tmp->n;
// 	all->max = tmp->n;
// 	tmp = tmp->next;
// 	while (tmp->next != all->a->next)
// 	{
// 		if (tmp->n < all->min)
// 			all->min = tmp->n;
// 		if (tmp->n > all->max)
// 			all->max = tmp->n;
// 		tmp = tmp->next;
// 	}
// }

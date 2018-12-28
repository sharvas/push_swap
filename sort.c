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
	printf("meana: %lld\n", all->mean);//
	while (tmp->next != all->a)
	{
		total += tmp->n;
		len++;
		printf("total: %lld, len: %d\n", total, len);//
		tmp = tmp->next;
	}
	total += tmp->n;
	len++;
	printf("total: %lld, len: %d\n", total, len);
	all->mean = (total / len);
	printf("mean: %lld\n", all->mean);//
}

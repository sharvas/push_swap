/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 10:20:18 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/29 22:00:54 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_len(t_all *all, char c)
{
	t_stack		*tmp;
	//	t_stack		*top;
	int			len;

	len = 1;
	tmp = (c == 'a') ? all->a : all->b;
	//	top = tmp;
	while (tmp->next/* != top*/)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

/*t_all*/void	ft_simple_sort(t_stack *cpy)
{
	t_stack		*top;
	int			swap;
	//	int			count;

	top = cpy;
	//	printf("%i\n", cpy->next->n);
	//	count = 0;
	while (/*count < all->len*/cpy->next)
	{
		if (cpy->n < cpy->next->n)
			cpy = cpy->next;
		else
		{
			swap = cpy->n;
			cpy->n = cpy->next->n;
			cpy->next->n = swap;
			cpy = top;
			//			count = 0;
		}
		//		count++;
	}
	//	return (all);
}

void	add_stuff(t_stack **list, int n)
{
	t_stack	*tmp;
	t_stack	*copy;

	copy = *list;
	if (copy)
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
		tmp->prev = copy;
		tmp->next = NULL;
		copy->next = tmp;
		tmp->n = n;
		copy = tmp;
	}
	else
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(/*all*/);
		tmp->prev = NULL;
		tmp->next = NULL;
		tmp->n = n;
		copy = tmp;
	}
}

t_stack	*ft_dublicate_list(t_all *all)
{
	t_stack		**copy;
//	t_stack		*all;
	t_stack		*tmp;

	tmp = all->a;
	*copy = NULL;
	while (tmp)
	{
		add_stuff(copy, tmp->n);
		printf("%i\n", *copy->n);
		tmp = tmp->next;
	}
	tmp = *copy;
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
//	if (!(copy = (t_stack *)malloc(sizeof(t_stack))))
//		ft_error(/*all and copy*/);
/*	copy->n = tmp->n;
	copy->next = NULL;
	copy->prev = NULL;
	tmp = tmp->next;

	while (tmp)
	{
		if (!(all = (t_stack *)malloc(sizeof(t_stack))))
*///			ft_error(/*all and copy*/);
/*		all->n = tmp->n;
		all->prev = copy;

		copy->n = tmp->n;
		//	printf("%i\n", copy->n);
		//		copy->next = tmp->next;
		//		copy->prev = tmp->prev;
		copy = copy->next;
		tmp = tmp->next;
	}
	//	tmp = NULL;
	//	while (tmp->prev)
	//		tmp = tmp->prev;
	return (top);*/
}

void	ft_find_ref(t_all *all)
{
	//	t_stack		*tmp;
	t_stack		*cpy;
	int			count;

	all->len = ft_find_len(all, 'a');
	cpy = ft_dublicate_list(all);
	printf("%i\n", all->len);
	/*cpy = */ft_simple_sort(cpy);
	//	tmp = cpy->a;
	//	count = (all->len / 4);
	all->min = cpy->n;
	//	while (count--)
	//		cpy = cpy->next;
	//	all->qu = cpy->n;
	//	tmp = cpy->a;
	count = (all->len / 2);
	while (count--)
		cpy = cpy->next;
	all->median = cpy->n;
	//	tmp = cpy->a;
	//	count = ((all->len / 2) + (all->len / 4));
	//	while (count--)
	//		cpy = cpy->next;
	//	all->three_qu = cpy->n;
	//	all->median = 5;
	count = 0;
	while (count++ < all->len)
		cpy = cpy->next;
	all->max = cpy->n;
	//	printf("min: %d, qu: %d, median: %d, three_qu: %d, max: %d, len: %d\n", 
	//	all->min, all->qu, all->median, all->three_qu, all->max, all->len);//
	free(cpy);
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
	while (tmp->next != /*all->a*/NULL)
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

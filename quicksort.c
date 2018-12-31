/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:58:32 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/31 19:40:24 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_all *all)
{
	t_stack *tmp;

	tmp = all->a;
	while (tmp)
	{
		printf("%i ", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

void	swap(int *a, int *b, t_all *all)
{
//	int t;
	t_stack *tmp;
	t_stack *mem_a;
	t_stack	*mem_b;
	int		count_a;
	int		count_b;
	int		i;

	count_a = 0;
	count_b = 0;
	i = 0;
	tmp = all->a;
	while (tmp)
	{
		if (tmp->n == *a)
			mem_a = tmp;
		if (tmp->n == *b)
			mem_b = tmp;
		tmp = tmp->next;
	}
	while (i++ < all->len && all->a != mem_a)
	{
		ft_ra(all);
		count_a++;
	}
	ft_pb(all);
	while (i++ < all->len - 1 && all->a != mem_b)
	{
		ft_ra(all);
		count_b++;
	}
	ft_pb(all);
	ft_sb(all);
	ft_pa(all);
	while (count_b--)
		ft_rra(all);
	ft_pa(all);
	while (count_a--)
		ft_rra(all);
//	ft_print_list(all);
//	exit(1);
//	t = *a;
//	*a = *b;
//	*b = t;
}

t_stack	*partition(t_stack *head, t_stack *last, t_all *all)
{ 
	// set pivot as h element
	int x;

	// similar to i = l-1 for array implementation 
	t_stack *i;
	t_stack	*j;
//	t_stack *top;

	i = head->prev;
	j = head;
	x = last->n;
//	top = all->a;
	// Similar to "for (int j = l; j <= h- 1; j++)"
	while (j != last)
	{
		if (j->n <= x)
		{
			// Similar to i++ for array
			i = (i == NULL) ? head : i->next;
			swap(&(i->n), &(j->n), all);
		}
		j = j->next;
	} 
	i = (i == NULL) ? head : i->next; // Similar to i++
	swap(&(i->n), &(last->n), all);
	return i;
}

void _quickSort(t_stack *head, t_stack *last, t_all *all)
{
	t_stack	*p;

	if (last != NULL && head != last && head != last->next)
	{
		p = partition(head, last, all);
		_quickSort(head, p->prev, all);
		_quickSort(p->next, last, all);
	}
}

void	quickSort(t_all *all)
{
	t_stack *last;
	t_stack	*head;
	t_stack	*tmp;

	head = all->a;
	tmp = all->a;
	// Find last node 
	while (tmp && tmp->next)
		tmp = tmp->next;
	last = tmp;
	// Call the recursive QuickSort 
//	ft_print_list(all);
	_quickSort(head, last, all);
//	ft_print_list(all);
} 

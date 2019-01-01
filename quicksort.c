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
	int		count_a;
	int		count_b;
	int		i;
	int		first_a;

	count_a = 0;
	count_b = 0;
	i = 0;
	first_a = 0;
	while (i++ < all->len && (all->a->n != *a || all->a->n != *b))
	{
		ft_ra(all);
		count_a++;
		count_b = (all->a->n == *a) ? 0 : count_a;
		count_a = (all->a->n == *a) ? count_a : 0;
		first_a = (all->a->n == *a) ? 1 : 0;
	}
	ft_pb(all);
	while (i++ < all->len - 1 && (all->a->n != *b || all->a->n != *a))
	{
		ft_ra(all);
		count_b++;
		count_a = (all->a->n == *b) ? 0 : count_b;
		count_a = (all->a->n == *a) ? count_a : 0;
		first_a = (all->a->n == *a) ? 1 : 0;
	}
	ft_pb(all);
	ft_sb(all);
	ft_pa(all);
	while (count_b--)
		ft_rra(all);
	ft_pa(all);
	while (count_a--)
		ft_rra(all);
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

	i = head->prev;
	j = head;
	x = last->n;
	// Similar to "for (int j = l; j <= h- 1; j++)"
	printf("	a\n");
	while (j && j != last)
	{
		if (j->n <= x)
		{
			// Similar to i++ for array
			i = (i == NULL) ? head : i->next;
			swap(&(i->n), &(j->n), all);
		}
		j = j->next;
		printf("	b\n");
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
	while (tmp->n != all->median)//(tmp && tmp->next)
		tmp = tmp->next;
	last = tmp;
	// Call the recursive QuickSort 
	ft_print_list(all);
	_quickSort(head, last, all);
	ft_print_list(all);
} 

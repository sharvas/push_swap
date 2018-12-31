/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:58:32 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/31 10:41:46 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap (int* a, int* b)
{
	int t = *a;

	*a = *b;
	*b = t;
}

t_stack	*partition(t_stack *head, t_stack *last)
{ 
	// set pivot as h element
	int x  = last->n;

	// similar to i = l-1 for array implementation 
	t_stack *i = head->prev;
	t_stack	*j = head;

	// Similar to "for (int j = l; j <= h- 1; j++)"
	while (j != last)
	{
		if (j->n <= x)
		{
			// Similar to i++ for array
			i = (i == NULL) ? head : i->next;
			swap(&(i->n), &(j->n));
		}
		j = j->next;
	} 
	i = (i == NULL) ? head : i->next; // Similar to i++
	swap(&(i->n), &(last->n));
	return i;
}

void _quickSort(t_stack *head, t_stack *last)
{
	t_stack	*p;

	if (head != NULL && head != last && head != last->next)
	{
		p = partition(head, last);
		_quickSort(head, p->prev);
		_quickSort(p->next, head);
	}
}

void	quickSort(t_all *all)
{
	// Find last node 
	t_stack *last;
	t_stack	*head;

	last = all->a->prev;
	head = all->a;
	// Call the recursive QuickSort 
	_quickSort(head, last);
} 

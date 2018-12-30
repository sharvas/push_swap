/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:58:32 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/30 19:18:11 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Node* partition(Node *l, Node *h) 
{ 
	// set pivot as h element 
	int x  = h->data; 

	// similar to i = l-1 for array implementation 
	Node *i = l->prev; 

	// Similar to "for (int j = l; j <= h- 1; j++)" 
	for (Node *j = l; j != h; j = j->next) 
	{ 
		if (j->data <= x) 
		{ 
			// Similar to i++ for array 
			i = (i == NULL)? l : i->next; 

			swap(&(i->data), &(j->data)); 
		} 
	} 
	i = (i == NULL)? l : i->next; // Similar to i++ 
	swap(&(i->data), &(h->data)); 
	return i; 
} 

void _quickSort(t_all *all) 
{ 
	if (h != NULL && l != h && l != h->next) 
	{ 
		struct Node *p = partition(l, h); 
		_quickSort(l, p->prev); 
		_quickSort(p->next, h); 
	} 
}

void	quickSort(t_all *all)
{
	// Find last node 
//	struct Node *h = lastNode(head); 

	// Call the recursive QuickSort 
	_quickSort(all);
} 

void	ft_quicksort(t_all *all)
{

}

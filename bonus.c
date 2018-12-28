/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:35:18 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/27 17:35:20 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_debug_v(t_all *all)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		flag_a;
	int		flag_b;	

	flag_a = 0;
	flag_b = 0;	
	stack_a = all->a;
	stack_b = all->b;
	printf(" %-11s| %s\n", "a", "b");
	while ((stack_a && stack_a->next != all->a) || (stack_b && stack_b->next != all->b))
	{
		if (stack_a && stack_b && !flag_a && !flag_b)
			printf("%- 12d|%- 12d\n", stack_a->n, stack_b->n);
		else if (stack_a && stack_a->next != all->a)
			printf("%- 12d|%12s\n", stack_a->n, "");
		else if (stack_b && stack_b->next != all->b)
			printf("%12s|%- 12d\n", "", stack_b->n);
		if (stack_a && stack_a->next != all->a)
			stack_a = stack_a->next;
		else
			flag_a = 1;
		if (stack_b && stack_b->next != all->b)
			stack_b = stack_b->next;
		else
			flag_b = 1;
	}
	if (stack_a && stack_b && !flag_a && !flag_b)
	 	printf("%- 12d|%- 12d\n", stack_a->n, stack_b->n);
	else if (stack_a && !flag_a)
		printf("%- 12d|%12s\n", stack_a->n, "");
	else if (stack_b && !flag_b)
		printf("%12s|%- 12d\n", "", stack_b->n);
}//convert printf to ft_printf

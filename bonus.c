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

void	ft_print_row(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	if (stack_a && stack_b && !flags->a && !flags->b)
		printf("%- 12d|%- 12d\n", stack_a->n, stack_b->n);
	else if (stack_a && !flags->a)
		printf("%- 12d|%12s\n", stack_a->n, "");
	else if (stack_b && !flags->b)
		printf("%12s|%- 12d\n", "", stack_b->n);
}

void	ft_print_row_ca(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	if (stack_a && stack_b && !flags->a && !flags->b)
		printf("\x1B[35m%- 12d\x1B[0m|%- 12d\n", stack_a->n, stack_b->n);
	else if (stack_a && !flags->a)
		printf("\x1B[35m%- 12d\x1B[0m|%12s\n", stack_a->n, "");
	else if (stack_b && !flags->b)
		printf("%12s|%- 12d\n", "", stack_b->n);
}

void	ft_print_row_cb(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	if (stack_a && stack_b && !flags->a && !flags->b)
		printf("%- 12d|\x1B[35m%- 12d\x1B[0m\n", stack_a->n, stack_b->n);
	else if (stack_a && !flags->a)
		printf("%- 12d|%12s\n", stack_a->n, "");
	else if (stack_b && !flags->b)
		printf("%12s|\x1B[35m%- 12d\x1B[0m\n", "", stack_b->n);
}

void	ft_print_row_cab(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	if (stack_a && stack_b && !flags->a && !flags->b)
		printf("\x1B[35m%- 12d|%- 12d\x1B[0m\n", stack_a->n, stack_b->n);
	else if (stack_a && !flags->a)
		printf("\x1B[35m%- 12d|%12s\x1B[0m\n", stack_a->n, "");
	else if (stack_b && !flags->b)
		printf("\x1B[35m%12s|%- 12d\x1B[0m\n", "", stack_b->n);
}

t_flags	ft_initialize_flags(t_flags *flags)
{
	flags->a = 0;
	flags->b = 0;
	flags->row = 0;
	return (*flags);
}

void	ft_debug_v(t_all *all, char *str)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_flags	flags;

	flags = ft_initialize_flags(&flags);
	stack_a = all->a;
	stack_b = all->b;
	printf("%s\n %-11s| %s\n", str, "a", "b");
	while ((stack_a && stack_a->next != all->a) || (stack_b && stack_b->next != all->b))
	{
		ft_print_row(stack_a, stack_b, &flags);
		if (stack_a && stack_a->next != all->a)
			stack_a = stack_a->next;
		else
			flags.a = 1;
		if (stack_b && stack_b->next != all->b)
			stack_b = stack_b->next;
		else
			flags.b = 1;
	}
	ft_print_row(stack_a, stack_b, &flags);
	printf("\n");
}//convert printf to ft_printf

void	ft_debug_c_print(t_stack *stack_a, t_stack *stack_b, t_flags flags, char *str)
{
	if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rra") == 0 || (ft_strcmp(str, "pa") == 0 && !flags.row) || (ft_strcmp(str, "sa") == 0 && flags.row < 2))
		ft_print_row_ca(stack_a, stack_b, &flags);
	else if (ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rrb") == 0 || (ft_strcmp(str, "pb") == 0 && !flags.row) ||  (ft_strcmp(str, "sb") == 0 && flags.row < 2))
		ft_print_row_cb(stack_a, stack_b, &flags);
	else if (ft_strcmp(str, "ss") == 0 && flags.row < 2)
		ft_print_row_cab(stack_a, stack_b, &flags);
	else
		ft_print_row(stack_a, stack_b, &flags);
}

void	ft_debug_c(t_all *all, char *str)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_flags	flags;

	flags = ft_initialize_flags(&flags);
	stack_a = all->a;
	stack_b = all->b;
	printf("\x1B[35m%s\x1B[0m\n %-11s| %s\n", str, "a", "b");
	if ((ft_strcmp(str, "rrr") == 0) || (ft_strcmp(str, "rr") == 0))
		printf("\x1B[35m");
	while ((stack_a && stack_a->next != all->a) || (stack_b && stack_b->next != all->b))
	{
		ft_debug_c_print(stack_a, stack_b, flags, str);
		if (stack_a && stack_a->next != all->a)
			stack_a = stack_a->next;
		else
			flags.a = 1;
		if (stack_b && stack_b->next != all->b)
			stack_b = stack_b->next;
		else
			flags.b = 1;
		flags.row++;
	}
	ft_debug_c_print(stack_a, stack_b, flags, str);
	printf("\x1B[0m\n");
}//convert printf to ft_printf

void	ft_push_swap_usage(void)
{
	ft_putstr("usage:	./push_swap [-f] n1 [n2...]\n");
	ft_putstr("n1, n2 etc.: numbers between -2147483648 and 2147483647\n");
	exit(1);
}

void	ft_checker_usage(void)
{
	ft_putstr("usage:	./checker [-v] [-c] [-f] n1 [n2...]\n");
	ft_putstr("n1, n2 etc.: numbers between -2147483648 and 2147483647\n");
	exit(1);
}

int		ft_is_bonus(char *str)
{
	if (!str)
		return (0);
	return (ft_strcmp(str, "-v") == 0) || (ft_strcmp(str, "-c") == 0) ||
	(ft_strcmp(str, "-f") == 0);
}

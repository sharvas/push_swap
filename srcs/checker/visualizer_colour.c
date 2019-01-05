/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_colour.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 10:55:40 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/05 15:27:05 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_print_row_ca(t_stack *s_a, t_stack *s_b, t_flags *flags)
{
	if (s_a && s_b && !flags->a && !flags->b)
		printf("\x1B[35m%- 12d\x1B[0m|%- 12d\n", s_a->n, s_b->n);
	else if (s_a && !flags->a)
		printf("\x1B[35m%- 12d\x1B[0m|%12s\n", s_a->n, "");
	else if (s_b && !flags->b)
		printf("%12s|%- 12d\n", "", s_b->n);
}

void	ft_print_row_cb(t_stack *s_a, t_stack *s_b, t_flags *flags)
{
	if (s_a && s_b && !flags->a && !flags->b)
		printf("%- 12d|\x1B[35m%- 12d\x1B[0m\n", s_a->n, s_b->n);
	else if (s_a && !flags->a)
		printf("%- 12d|%12s\n", s_a->n, "");
	else if (s_b && !flags->b)
		printf("%12s|\x1B[35m%- 12d\x1B[0m\n", "", s_b->n);
}

void	ft_print_row_cab(t_stack *s_a, t_stack *s_b, t_flags *flags)
{
	if (s_a && s_b && !flags->a && !flags->b)
		printf("\x1B[35m%- 12d|%- 12d\x1B[0m\n", s_a->n, s_b->n);
	else if (s_a && !flags->a)
		printf("\x1B[35m%- 12d|%12s\x1B[0m\n", s_a->n, "");
	else if (s_b && !flags->b)
		printf("\x1B[35m%12s|%- 12d\x1B[0m\n", "", s_b->n);
}

void	ft_debug_c_print(t_stack *s_a, t_stack *s_b, t_flags flags, char *str)
{
	if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rra") == 0 ||
		(ft_strcmp(str, "pa") == 0 && !flags.row) ||
		(ft_strcmp(str, "sa") == 0 && flags.row < 2))
		ft_print_row_ca(s_a, s_b, &flags);
	else if (ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rrb") == 0 ||
		(ft_strcmp(str, "pb") == 0 && !flags.row) ||
		(ft_strcmp(str, "sb") == 0 && flags.row < 2))
		ft_print_row_cb(s_a, s_b, &flags);
	else if (ft_strcmp(str, "ss") == 0 && flags.row < 2)
		ft_print_row_cab(s_a, s_b, &flags);
	else
		ft_print_row(s_a, s_b, &flags);
}

void	ft_debug_c(t_all *all, char *str)
{
	t_stack	*s_a;
	t_stack	*s_b;
	t_flags	flags;

	flags = ft_initialize_flags(&flags);
	s_a = all->a;
	s_b = all->b;
	usleep(120000);//variable?
	printf("\E[H\E[2J\n\x1B[35m%s\x1B[0m\n %-11s| %s\n", str, "a", "b");
	if ((ft_strcmp(str, "rrr") == 0) || (ft_strcmp(str, "rr") == 0))
		printf("\x1B[35m");
	while ((s_a && s_a->next != all->a) || (s_b && s_b->next != all->b))
	{
		ft_debug_c_print(s_a, s_b, flags, str);
		if (s_a && s_a->next != all->a)
			s_a = s_a->next;
		else
			flags.a = 1;
		if (s_b && s_b->next != all->b)
			s_b = s_b->next;
		else
			flags.b = 1;
		flags.row++;
	}
	ft_debug_c_print(s_a, s_b, flags, str);
}//convert printf to ft_printf

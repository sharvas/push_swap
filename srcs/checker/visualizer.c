/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 10:55:33 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/05 15:26:47 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		ft_is_bonus(char *str)
{
	if (!str)
		return (0);
	return (ft_strcmp(str, "-v") == 0) || (ft_strcmp(str, "-c") == 0) ||
	(ft_strcmp(str, "-t") == 0) || (ft_strcmp(str, "-f") == 0);
}

t_flags	ft_initialize_flags(t_flags *flags)
{
	flags->a = 0;
	flags->b = 0;
	flags->row = 0;
	return (*flags);
}

void	ft_print_row(t_stack *s_a, t_stack *s_b, t_flags *flags)
{
	if (s_a && s_b && !flags->a && !flags->b)
		printf("%- 12d|%- 12d\n", s_a->n, s_b->n);
	else if (s_a && !flags->a)
		printf("%- 12d|%12s\n", s_a->n, "");
	else if (s_b && !flags->b)
		printf("%12s|%- 12d\n", "", s_b->n);
}

void	ft_debug_v(t_all *all, char *str)
{
	t_stack	*s_a;
	t_stack	*s_b;
	t_flags	flags;

	flags = ft_initialize_flags(&flags);
	s_a = all->a;
	s_b = all->b;
	if (all->t)
		usleep(120000);
	printf("\E[H\E[2J\n%s\n %-11s| %s\n", str, "a", "b");
	while ((s_a && s_a->next != all->a) || (s_b && s_b->next != all->b))
	{
		ft_print_row(s_a, s_b, &flags);
		if (s_a && s_a->next != all->a)
			s_a = s_a->next;
		else
			flags.a = 1;
		if (s_b && s_b->next != all->b)
			s_b = s_b->next;
		else
			flags.b = 1;
	}
	ft_print_row(s_a, s_b, &flags);
}

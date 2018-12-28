/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 09:12:37 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/28 14:28:57 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_sort(t_all *all, char *instructions)
{
	instruct

}

void	ft_push_swap(char **av)
{
	t_all	*all;
	char	*instructions;

	all = NULL;
	instructions = NULL;
	all = ft_initialize(all);
	ft_fill_a(all, av);
//	ft_find_min_max(all);
	instructions = ft_sort(all, instructions);
	ft_putstr_fd(instructions, 0);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		ft_push_swap(av);
	return (0);
}

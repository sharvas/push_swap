/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 13:04:09 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/05 13:04:10 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_usage(void)
{
	ft_putstr("usage:	./push_swap [-f] n1 [n2...]\n");
	ft_putstr("n1, n2 etc.: numbers between -2147483648 and 2147483647\n");
	ft_putstr("-f file_name writes instructions to file_name\n");
	exit(1);
}

void	ft_push_swap(char **av)
{
	t_all	*all;

	all = NULL;
	all = ft_initialize(all);
	all->write_instructions = 1;
	ft_read_args_ps(all, av);
	ft_find_refs(all);
	ft_sort_algo_switch(all);
	ft_condense_verbose(all);
	if (!all->f)
		ft_putstr(all->instructions);
	else
		ft_putfile(all);
	ft_free_all(all);
}

int		main(int ac, char **av)
{
	if (ac == 1 || ((ac == 2 || ac == 3) && (ft_strcmp(av[1], "-f") == 0)))
		ft_push_swap_usage();
	ft_push_swap(av);
	return (0);
}

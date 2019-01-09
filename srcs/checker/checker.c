/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:09:50 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/09 11:17:10 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_checker_usage(void)
{
	ft_putstr("usage:	./checker [-v] [-c] [-f] n1 [n2...]\n");
	ft_putstr("n1, n2 etc.: numbers between -2147483648 and 2147483647\n");
	ft_putstr("-v visualizer, -c colour last operation, -t slow visualizer\n");
	ft_putstr("-f file_name reads instructions from file_name\n");
	exit(1);
}

void	ft_checker(char **argv)
{
	t_all	*all;

	all = NULL;
	all = ft_initialize(all);
	ft_read_args_checker(all, argv);
	all = ft_do_ops(all);
	ft_ko_ok(all);
	close(all->fd);
	ft_free_all(all);
}

int		main(int argc, char **argv)
{
	if (argc == 1 ||
		(argc == 2 && ft_is_bonus(argv[1])) ||
		(argc == 3 && ft_is_bonus(argv[1]) && ft_is_bonus(argv[2])) ||
		(argc == 4 && ft_is_bonus(argv[1]) && ft_is_bonus(argv[2]) &&
		ft_is_bonus(argv[3])) ||
		(argc == 5 && ft_is_bonus(argv[1]) && ft_is_bonus(argv[2]) &&
		ft_is_bonus(argv[3]) && ft_is_bonus(argv[4])))
		ft_checker_usage();
	ft_checker(argv);
	return (0);
}

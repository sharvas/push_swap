/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:28:18 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/04 18:09:48 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker(char **argv)
{
	t_all	*all;

	all = NULL;
	all = ft_initialize(all);
	ft_read_args_checker(all, argv);
	all = ft_do_ops(all);
	ft_ko_ok(all);
	ft_free_all(all);
	close(all->fd);
}

int		main(int argc, char **argv)
{
	if (argc == 1 ||
		(argc == 2 && ft_is_bonus(argv[1])) ||
		(argc == 3 && ft_is_bonus(argv[1]) && ft_is_bonus(argv[2])) ||
		(argc == 4 && ft_is_bonus(argv[1]) && ft_is_bonus(argv[2]) &&
		ft_is_bonus(argv[3])))
		ft_checker_usage();
	ft_checker(argv);
	return (0);
}

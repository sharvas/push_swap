/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:28:18 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/26 15:28:20 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_read_do(char *line, t_all *all)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(all);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(all);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(all);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(all);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(all);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(all);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(all);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(all);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(all);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(all);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(all);
	else
		ft_error(/*all*/);
}

t_all	*ft_do_ops(t_all *all)
{
	char	*line;
	int		count;

	line = NULL;
	count = 0;
	if (all->v)
	{
		printf("\E[H\E[2J");
		ft_debug_v(all, "initial state:");
	}
	while ((get_next_line(0, &line)) == 1)
	{
		ft_read_do(line, all);
		count++;
		if (all->v)
			ft_debug_v(all, line);
		free(line);
		line = NULL;
	}
	if (all->v)
		printf("instructions count: %d\n\n", count);
	return (all);
}

void	ft_checker(char **argv)
{
	t_all	*all;

	all = NULL;
	all = ft_initialize(all);
	ft_fill_a(all, argv);
	all = ft_do_ops(all);
	ft_ko_ok(all);
//	ft_free_all(all);
}

int		main(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && (ft_strcmp(argv[1], "-v") == 0)))
		ft_checker_usage();
	ft_checker(argv);
	return (0);
}

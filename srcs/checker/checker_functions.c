/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:09:55 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/09 13:44:27 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_read_args_checker(t_all *all, char **argv)
{
	int		i;

	i = 1;
	while (ft_is_bonus(argv[i]))
	{
		if (ft_strcmp(argv[i], "-v") == 0)
			all->v = 1;
		else if (ft_strcmp(argv[i], "-c") == 0)
			all->c = 1;
		else if (ft_strcmp(argv[i], "-t") == 0)
			all->t = 1;
		else if (ft_strcmp(argv[i], "-f") == 0)
		{
			i++;
			if (!argv[i])
				ft_checker_usage();
			all->f = argv[i];
			ft_open_file(all, argv, i);
		}
		i++;
	}
	ft_fill_a(all, argv, i);
}

void	ft_open_file(t_all *all, char **argv, int i)
{
	if ((all->fd = open(all->f, O_RDONLY)) < 0)
		ft_ps_error(all);
	i++;
	if (!argv[i])
		ft_checker_usage();
}

t_all	*ft_do_ops(t_all *all)
{
	char	*line;
	int		count;
	int		g;

	line = NULL;
	count = 0;
	if (all->v || all->c)
		ft_debug_v(all, "initial state:");
	while ((g = get_next_line(all->fd, &line)) == 1)
	{
		ft_read_do(line, all);
		count++;
		if (all->c)
			ft_debug_c(all, line);
		else if (all->v)
			ft_debug_v(all, line);
		ft_freestr(line);
	}
	ft_freestr(line);
	if (g == -1)
		ft_ps_error(all);
	if (all->v || all->c)
		ft_printf("\n\x1B[0minstruction count: %d\n\n", count);
	return (all);
}

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
		ft_ps_error(all);
}

void	ft_ko_ok(t_all *all)
{
	if (ft_is_sorted(all, 'a') && !all->b)
		ft_putstr("\x1B[32mOK\x1B[0m\n");
	else
		ft_putstr("\x1B[31mKO\x1B[0m\n");
}

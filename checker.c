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

# include "push_swap.h"

// t_all	*ft_do_ops(t_all *all)
// {
// 	char	*line;

// 	line = NULL;
// 	printf("here\n");
// 	while((get_next_line(0, &line)) == 1)
// 	{
// 		printf("line: %s\n", line);
// 		free(line);
// 		line = NULL;
// 	}
// 	printf("B\n");
// 	return (all);
// }

void	ft_checker(char **argv)
{
	t_all	*all;

	all = NULL;
	all = ft_initialize(all);
	ft_fill_a(all, argv);
//	all = ft_do_ops(all);
	ft_ko_ok(all);
//	ft_free_all(all);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		ft_checker(argv);
	return (0);
}

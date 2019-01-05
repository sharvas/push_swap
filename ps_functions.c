/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 11:43:46 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/05 11:43:47 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_read_args_ps(t_all *all, char **argv)
{
	int		i;

	i = 1;
	if (ft_strcmp(argv[i], "-f") == 0)
	{
		i++;
		all->f = argv[i++];
	}
	ft_fill_a(all, argv, i);
}

void	ft_condense_verbose(t_all *all)
{
	ft_find_replace(all, "\nra\nrra\n", "\n");
	ft_find_replace(all, "rra\nra\n", "");
	ft_find_replace(all, "\nrb\nrrb\n", "\n");
	ft_find_replace(all, "rrb\nrb\n", "");
	ft_find_replace(all, "pb\npa\n", "");
	ft_find_replace(all, "pa\npb\n", "");
	ft_find_replace(all, "sa\nsa\n", "");
	ft_find_replace(all, "sb\nsb\n", "");
	ft_find_replace(all, "\nra\nrb\n", "\nrr\n");
	ft_find_replace(all, "\nrb\nra\n", "\nrr\n");
	ft_find_replace(all, "rra\nrrb\n", "rrr\n");
	ft_find_replace(all, "rrb\nrra\n", "rrr\n");
	ft_find_replace(all, "sa\nsb\n", "ss\n");
	ft_find_replace(all, "sb\nsa\n", "ss\n");
	ft_find_replace(all, "\nrr\nrrr\n", "\n");
	ft_find_replace(all, "rrr\nrr\n", "");
}

void	ft_find_replace(t_all *all, char *find, char *replace)
{
	char	*str;
	char	*verbose;
	char	*tmp;
	int		n;

	str = all->instructions;
	while ((verbose = ft_strstr(str, find)))
	{
		tmp = str;
//		str_all = str;
		n = 0;

		while(tmp != verbose)
		{
			tmp++;
			n++;
		}
		tmp = str;
		if (!(str = (char*)malloc(sizeof(char*) * (n + ft_strlen(replace) + ft_strlen(tmp + n + ft_strlen(find))))))
			ft_error(/*all*/);
		str = ft_strncpy(str, tmp, n);
		str = ft_strcat(str, replace);
		str = ft_strcat(str, tmp + n + ft_strlen(find));
//		free(tmp); >> need to free, but crashes with cases of 100 random

//		str = ft_strndup(str, n);// need to free str
//		str = ft_strjoinfree_s1(str, replace);
//		str = ft_strjoinfree_s1(str, str_all + n + ft_strlen(find));//need to free s2
	}
	all->instructions = str;
}

void	ft_putfile(t_all *all)
{
	int	fd;

	if ((fd = open(all->f, O_RDWR | O_CREAT | O_EXCL, 0666)) < 0)
		ft_error();//usage??
	if ((write(fd, all->instructions, ft_strlen(all->instructions))) < 0)
		ft_error();//usage??
	close(fd);
}

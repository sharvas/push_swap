/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condense_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 13:19:39 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/05 14:08:32 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_replace(t_all *all, char *find, char *replace)
{
	char	*str;
	char	*verbose;
	char	*tmp;
	int		n;

	int i = 1;
	str = all->instructions;
	tmp = NULL;
	while ((verbose = ft_strstr(str, find)))
	{
		tmp = str;
		n = 0;

		while(tmp++ != verbose)
			n++;
		tmp = str;
		if (!(str = ft_strnew((n + ft_strlen(replace) + ft_strlen(tmp + n + ft_strlen(find))))))
			ft_error(/*all*/);
		str = ft_strncpy(str, tmp, n);
		str = ft_strcat(str, replace);
		str = ft_strcat(str, tmp + n + ft_strlen(find));
		if (tmp)
			free(tmp);
		tmp = NULL;
		verbose = NULL;
	}
	all->instructions = str;
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

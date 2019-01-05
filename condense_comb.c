/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condense_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 13:19:39 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/04 18:18:21 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

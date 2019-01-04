/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condense_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 13:19:39 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/03 13:19:40 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_condense_str(t_all *all, char *find, char *replace)
{
	char	*str;
	char	*str_all;
	int		n;
	char	*verbose;
	char	*tmp;

	str = all->instructions;
	while ((verbose = ft_strstr(str, find)))
	{
		tmp = str;
		str_all = str;
		n = 0;

		while(tmp != verbose)
		{
			tmp++;
			n++;
		}
		str = ft_strndup(str, n);//free
		str = ft_strjoinfree_s1(str, replace);
		str = ft_strjoinfree_s1(str, str_all + n + ft_strlen(find));
	}
	all->instructions = str;
}

void	ft_condense_comb(t_all *all)
{
	ft_condense_str(all, "\nrra\nra\n", "\n");
	ft_condense_str(all, "\nra\nrra\n", "\n");
	ft_condense_str(all, "\nrb\nrrb\n", "\n");
	ft_condense_str(all, "\nrrb\nrb\n", "\n");
	ft_condense_str(all, "\npb\npa\n", "\n");
	ft_condense_str(all, "\npa\npb\n", "\n");
	ft_condense_str(all, "\nsa\nsa\n", "\n");
	ft_condense_str(all, "\nsb\nsb\n", "\n");
	ft_condense_str(all, "\nra\nrb\n", "\nrr\n");
	ft_condense_str(all, "\nrb\nra\n", "\nrr\n");
	ft_condense_str(all, "\nrra\nrrb\n", "\nrrr\n");
	ft_condense_str(all, "\nrrb\nrra\n", "\nrrr\n");
	ft_condense_str(all, "\nsa\nsb\n", "\nss\n");
	ft_condense_str(all, "\nsb\nsa\n", "\nss\n");
	ft_condense_str(all, "\nrr\nrrr\n", "\n");
	ft_condense_str(all, "\nrrr\nrr\n", "\n");
}

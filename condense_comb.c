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

void	ft_condense_rr(t_all *all)
{
	char	*str;
	char	*str_all;
	int		n;
	char	*verbose;
	char	*tmp;

	str = all->instructions;
	while ((verbose = ft_strstr(str, "ra\nrb\n")) ||
		(verbose = ft_strstr(str, "rb\nra\n")))
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
		str = ft_strjoinfree_s1(str, "rr\n");
		str = ft_strjoinfree_s1(str, str_all + n + 6);
	}
	all->instructions = str;
}

void	ft_condense_rrr(t_all *all)
{
	char	*str;
	char	*str_all;
	int		n;
	char	*verbose;
	char	*tmp;

	str = all->instructions;
	while ((verbose = ft_strstr(str, "rra\nrrb\n")) ||
		(verbose = ft_strstr(str, "rrb\nrra\n")))
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
		str = ft_strjoinfree_s1(str, "rrr\n");
		str = ft_strjoinfree_s1(str, str_all + n + 8);
	}
	all->instructions = str;
}

void	ft_condense_ss(t_all *all)
{
	char	*str;
	char	*str_all;
	int		n;
	char	*verbose;
	char	*tmp;

	str = all->instructions;
	while ((verbose = ft_strstr(str, "sa\nsb\n")) ||
		(verbose = ft_strstr(str, "sb\nsa\n")))
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
		str = ft_strjoinfree_s1(str, "ss\n");
		str = ft_strjoinfree_s1(str, str_all + n + 6);
	}
	all->instructions = str;
}

void	ft_condense_comb(t_all *all)
{
	ft_condense_rr(all);
	ft_condense_rrr(all);
	ft_condense_ss(all);
}

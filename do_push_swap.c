/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:37:52 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/26 15:37:53 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_sa(t_all *all)
{
	int	tmp;

	tmp = a->n;
	a->n = a->next->n;
	a->next->n = tmp;
}

void	ft_sb(t_all *all)
{
	int	tmp;

	tmp = b->n;
	b->n = b->next->n;
	b->next->n = tmp;
}


void	ft_pa(t_all *all)
{
	
}

void	ft_pb(t_all *all)
{
	
}

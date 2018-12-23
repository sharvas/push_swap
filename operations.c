/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 17:08:02 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/22 17:08:04 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <push_swap.h>

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

void	ft_ss(t_all *all)
{
	ft_sa();
	ft_sb();
}

void	ft_pa(t_all *all)
{
	
}

void	ft_pb(t_all *all)
{
	
}

void	ft_ra(t_all *all)
{
	all->a = all->a->next;
}

void	ft_rb(t_all *all)
{
	all->b = all->b->next;
}

void	ft_rr(t_all *all)
{
	ft_ra();
	ft_rb();
}

void	ft_rra(t_all *all)
{
	all->a = all->a->prev;
}

void	ft_rrb(t_all *all)
{
	all->b = all->b->prev;
}

void	ft_rrr(t_all *all)
{
	ft_rra();
	ft_rrb();
}

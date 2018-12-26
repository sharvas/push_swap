/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 17:04:24 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/22 17:04:27 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_error(/*t_all *all*/)
{
	ft_putstr("Error\n");
//	ft_free_all(all);//
	exit (1);
}

int		ft_is_error(char *argv, intmax_t n)
{
	int		i;

	i = -1;
	if (n > 2147483647 || n < -2147483648)
		return (1);
	while (argv[++i])
	{
		if ((!ft_isdigit(argv[i]) && argv[i] != '-'))
			return (1);
	}
	return (0);
}

int 	ft_is_duplicate(t_all *all, intmax_t n)
{
	t_stack	*ref;

	ref = all->a;
	if (ref == NULL)
		return (0);
	if (n == ref->n)
		return (1);
	ref = ref->next;
	while (ref != all->a)
	{
		if (n == ref->n)
			return (1);
		ref = ref->next;
	}
	return (0);
}

// void	ft_free_stack(t_stack *stack)
// {
// 	while ()
// 	{

// 	}
// }

// void	ft_free_all()
// {
// 	ft_free_stack(a);
// 	ft_free_stack(b);

// }

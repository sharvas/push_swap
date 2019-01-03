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

#include "push_swap.h"

void	ft_error(/*t_all *all*/)
{
	ft_putstr("Error\n");
//	ft_free_all(all);//
	exit(1);
}

int		ft_is_duplicate(t_all *all, intmax_t n)
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

int		ft_atoi_error(char *str)
{
	long	a;
	int		i;
	int		n;

	a = 0;
	i = 0;
	n = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		ft_error();
	while (str[i] >= '0' && str[i] <= '9' && i < 11)
		a = (a * 10) + (str[i++] - '0');
	a *= n;
	if (str[i] || a > 2147483647 || a < -2147483648)
		ft_error();
	return (a);
}

char		*ft_strdup_empty(void)
{
	char	*str;

	str = NULL;
	if (!(str = ft_strdup("")))
		ft_error();
	return (str);
}

char		*ft_strjoinfree_s1_error(char *s1, char *s2)
{
	char	*str;

	str = NULL;
	if (!(str = ft_strjoinfree_s1(s1, s2)))
		ft_error();//need to free string
	return (str);
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

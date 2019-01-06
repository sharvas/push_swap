/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_null.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 12:54:29 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/05 15:29:34 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char		*ft_ps_strdup_empty(t_all *all)
{
	char	*str;

	str = NULL;
	if (!(str = ft_strdup("")))
		ft_ps_error(all);
	return (str);
}

char		*ft_strjoinfree_s1_ps(t_all *all, char *s2)
{
	char	*str;

	str = NULL;
	if (!(str = ft_strjoinfree_s1(all->instructions, s2)))
		ft_ps_error(all);
	return (str);
}
